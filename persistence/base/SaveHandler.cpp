/*
 * SaveHandler.cpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#include "persistence/base/SaveHandler.hpp"

#include <string>
#include <sstream> // used for addReferences()

#include "boost/algorithm/string.hpp" // used for string splitting
#include "ecore/EObject.hpp"
#include "persistence/base/HandlerHelper.hpp"

using namespace persistence::base;

SaveHandler::SaveHandler()
{
	m_rootObject = nullptr;
	m_isXSIMode = true;
	m_savedObjects.reset(new Bag<ecore::EObject>());
}

SaveHandler::~SaveHandler()
{
}

/**/
std::string SaveHandler::getPrefix()
{
	return m_rootPrefix;
}

void SaveHandler::setRootObject(std::shared_ptr<ecore::EObject> object)
{
	if (m_rootObject == nullptr)
	{
		m_rootObject = object;
	}
}

void SaveHandler::addAttribute(const std::string &name, bool value)
{
	addAttribute(name, (value ? (std::string) "true" : (std::string) "false"));
}

void SaveHandler::addReference(const std::string &name, std::shared_ptr<ecore::EObject> object)
{
	if (object)
	{
		std::string ref = "";
		auto iter = m_refToObject_map.find(object);
		if (iter != m_refToObject_map.end())
		{
			ref = iter->second;
		}
		else
		{
			ref = persistence::base::HandlerHelper::extractReference(object, m_rootObject, m_rootPrefix);
		}

		if (!m_isXSIMode && name == "type")
		{
			unsigned index = ref.find(" ");
			if (index != std::string::npos)
			{
				std::string href = ref.substr(index+1, name.size()-index-1);
				std::string xmitype = ref.substr(0, index);
				addTypeReference(href, xmitype);
			}
			else
			{
				addAttribute(name, ref);
			}
		}
		else
		{
			addAttribute(name, ref);
		}
	}
}

std::string SaveHandler::extractType(std::shared_ptr<ecore::EObject> obj) const
{
	return persistence::base::HandlerHelper::extractType(obj, m_rootPrefix);
}


void SaveHandler::addReference(const std::shared_ptr<ecore::EObject> object, const std::string &tagName, const bool typeRequired)
{
	if (object == nullptr)
	{
		return;
	}


	if (m_savedObjects->find(object) != -1)
	{
		return;
	}

	m_savedObjects->push_back(object);

	// 1. Create and add Node-Element to model-tree
	createAndAddElement(tagName);

	if (!m_isXSIMode)
	{
		auto iter = m_refToObject_map.find(object);
		if (iter != m_refToObject_map.end())
		{
			addAttribute("xmi:id", iter->second);
		}
		else
		{
			std::cout << "id not found for tag name '" << tagName << "'" << std::endl;
		}
	}

	if(typeRequired)
	{
		// 1.x Set Attribute "xsi:type" to the specific Class-Type
		if (m_isXSIMode)
		{
			addAttribute("xsi:type", extractType(object));
		}
		else
		{
			addAttribute("xmi:type", extractType(object));
		}
	}

	// 2. Recursive call of save()
	object->save(m_thisPtr);

	// 3. Tell saveHandler for stepping to previous level
	release();
}

void SaveHandler::setThisPtr(std::shared_ptr<SaveHandler> thisPtr)
{
	m_thisPtr = thisPtr;
}

void SaveHandler::setIsXSIMode(bool value)
{
	m_isXSIMode = value;
}

void SaveHandler::setTypesMap(std::map<std::string, std::shared_ptr<ecore::EObject>> typesMap)
{
	std::map<std::string, std::shared_ptr<ecore::EObject>>::iterator iter = typesMap.begin();
	std::map<std::string, std::shared_ptr<ecore::EObject>>::iterator end = typesMap.end();
	while (iter != end)
	{
		m_refToObject_map.insert(std::pair<std::shared_ptr<ecore::EObject>, std::string>(iter->second, iter->first));
		iter++;
	}
}
