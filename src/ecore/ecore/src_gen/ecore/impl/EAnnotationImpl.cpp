#include "ecore/impl/EAnnotationImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>

#include "abstractDataTypes/Subset.hpp"


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ecore/ecoreFactory.hpp"


#include "ecore/EAnnotation.hpp"
#include "ecore/EModelElement.hpp"
#include "ecore/EObject.hpp"

//Factories an Package includes
#include "ecore/ecorePackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EAnnotationImpl::EAnnotationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EAnnotationImpl::~EAnnotationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EAnnotation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EAnnotationImpl::EAnnotationImpl(std::weak_ptr<ecore::EObject> par_eContainer)
:EAnnotationImpl()
{
	m_eContainer = par_eContainer;
}

//Additional constructor for the containments back reference
EAnnotationImpl::EAnnotationImpl(std::weak_ptr<ecore::EModelElement> par_eModelElement)
:EAnnotationImpl()
{
	m_eModelElement = par_eModelElement;
}

EAnnotationImpl::EAnnotationImpl(const EAnnotationImpl & obj): EAnnotationImpl()
{
	*this = obj;
}

EAnnotationImpl& EAnnotationImpl::operator=(const EAnnotationImpl & obj)
{
	//call overloaded =Operator for each base class
	EModelElementImpl::operator=(obj);
	EAnnotation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EAnnotation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	std::shared_ptr<std::map < std::string, std::string>> detailsContainer = getDetails();
	for(const auto pair_details : *obj.getDetails())
	{
		detailsContainer->insert(std::make_pair(pair_details.first, pair_details.second));
	}
	m_source = obj.getSource();

	//copy references with no containment (soft copy)
	m_eModelElement  = obj.getEModelElement();
	std::shared_ptr<Bag<ecore::EObject>> _references = obj.getReferences();
	m_references.reset(new Bag<ecore::EObject>(*(obj.getReferences().get())));
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<ecore::EObject, ecore::EObject>> contentsContainer = getContents();
	if(nullptr != contentsContainer )
	{
		int size = contentsContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _contents=(*contentsContainer)[i];
			if(nullptr != _contents)
			{
				contentsContainer->push_back(std::dynamic_pointer_cast<ecore::EObject>(_contents->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container contents."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr contents."<< std::endl;)
	}
	/*Subset*/
	m_contents->initSubset(getEContens());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_contents - Subset<ecore::EObject, ecore::EObject >(getEContens())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> EAnnotationImpl::copy() const
{
	std::shared_ptr<EAnnotationImpl> element(new EAnnotationImpl());
	*element =(*this);
	element->setThisEAnnotationPtr(element);
	return element;
}

std::shared_ptr<EClass> EAnnotationImpl::eStaticClass() const
{
	return ecore::ecorePackage::eInstance()->getEAnnotation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute details
*/
std::shared_ptr<std::map < std::string, std::string>> EAnnotationImpl::getDetails() const 
{
	return m_details;
}
void EAnnotationImpl::setDetails(std::shared_ptr<std::map < std::string, std::string>> _details)
{
	m_details = _details;
	
} 


/*
Getter & Setter for attribute source
*/
std::string EAnnotationImpl::getSource() const 
{
	return m_source;
}
void EAnnotationImpl::setSource(std::string _source)
{
	m_source = _source;
	
} 


//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
/*
Getter & Setter for reference contents
*/
std::shared_ptr<Subset<ecore::EObject, ecore::EObject>> EAnnotationImpl::getContents() const
{
	if(m_contents == nullptr)
	{
		/*Subset*/
		m_contents.reset(new Subset<ecore::EObject, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_contents - Subset<ecore::EObject, ecore::EObject >()" << std::endl;
		#endif
		
		/*Subset*/
		m_contents->initSubset(getEContens());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_contents - Subset<ecore::EObject, ecore::EObject >(getEContens())" << std::endl;
		#endif
		
	}

    return m_contents;
}



/*
Getter & Setter for reference eModelElement
*/
std::weak_ptr<ecore::EModelElement> EAnnotationImpl::getEModelElement() const
{

    return m_eModelElement;
}
void EAnnotationImpl::setEModelElement(std::weak_ptr<ecore::EModelElement> _eModelElement)
{
    m_eModelElement = _eModelElement;
	
}


/*
Getter & Setter for reference references
*/
std::shared_ptr<Bag<ecore::EObject>> EAnnotationImpl::getReferences() const
{
	if(m_references == nullptr)
	{
		m_references.reset(new Bag<ecore::EObject>());
		
		
	}

    return m_references;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EAnnotationImpl::getEContens() const
{
	if(m_eContens == nullptr)
	{
		/*Union*/
		m_eContens.reset(new Union<ecore::EObject>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_eContens - Union<ecore::EObject>()" << std::endl;
		#endif
		
		
	}
	return m_eContens;
}




std::shared_ptr<EAnnotation> EAnnotationImpl::getThisEAnnotationPtr() const
{
	return m_thisEAnnotationPtr.lock();
}
void EAnnotationImpl::setThisEAnnotationPtr(std::weak_ptr<EAnnotation> thisEAnnotationPtr)
{
	m_thisEAnnotationPtr = thisEAnnotationPtr;
	setThisEModelElementPtr(thisEAnnotationPtr);
}
std::shared_ptr<ecore::EObject> EAnnotationImpl::eContainer() const
{
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}

	if(auto wp = m_eModelElement.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any EAnnotationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_CONTENTS:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::EObject>::iterator iter = getContents()->begin();
			Bag<ecore::EObject>::iterator end = getContents()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //16			
		}
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_DETAILS:
			return eAny(getDetails()); //18
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_EMODELELEMENT:
			{
				std::shared_ptr<ecore::EObject> returnValue=getEModelElement().lock();
				return eAny(returnValue); //15
			}
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_REFERENCES:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ecore::EObject>::iterator iter = getReferences()->begin();
			Bag<ecore::EObject>::iterator end = getReferences()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //17			
		}
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_SOURCE:
			return eAny(getSource()); //14
	}
	return EModelElementImpl::eGet(featureID, resolve, coreType);
}
bool EAnnotationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_CONTENTS:
			return getContents() != nullptr; //16
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_DETAILS:
			return getDetails() != nullptr; //18
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_EMODELELEMENT:
			return getEModelElement().lock() != nullptr; //15
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_REFERENCES:
			return getReferences() != nullptr; //17
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_SOURCE:
			return getSource() != ""; //14
	}
	return EModelElementImpl::internalEIsSet(featureID);
}
bool EAnnotationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_CONTENTS:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ecore::EObject>> contentsList(new Bag<ecore::EObject>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				contentsList->add(std::dynamic_pointer_cast<ecore::EObject>(*iter));
				iter++;
			}
			
			Bag<ecore::EObject>::iterator iterContents = getContents()->begin();
			Bag<ecore::EObject>::iterator endContents = getContents()->end();
			while (iterContents != endContents)
			{
				if (contentsList->find(*iterContents) == -1)
				{
					getContents()->erase(*iterContents);
				}
				iterContents++;
			}
 
			iterContents = contentsList->begin();
			endContents = contentsList->end();
			while (iterContents != endContents)
			{
				if (getContents()->find(*iterContents) == -1)
				{
					getContents()->add(*iterContents);
				}
				iterContents++;			
			}
			return true;
		}
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_DETAILS:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<std::map < std::string, std::string>> _details = std::dynamic_pointer_cast<std::map < std::string, std::string>>(_temp);
			setDetails(_details); //18			
			return true;
		}
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_EMODELELEMENT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ecore::EModelElement> _eModelElement = std::dynamic_pointer_cast<ecore::EModelElement>(_temp);
			setEModelElement(_eModelElement); //15
			return true;
		}
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_REFERENCES:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ecore::EObject>> referencesList(new Bag<ecore::EObject>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				referencesList->add(std::dynamic_pointer_cast<ecore::EObject>(*iter));
				iter++;
			}
			
			Bag<ecore::EObject>::iterator iterReferences = getReferences()->begin();
			Bag<ecore::EObject>::iterator endReferences = getReferences()->end();
			while (iterReferences != endReferences)
			{
				if (referencesList->find(*iterReferences) == -1)
				{
					getReferences()->erase(*iterReferences);
				}
				iterReferences++;
			}
 
			iterReferences = referencesList->begin();
			endReferences = referencesList->end();
			while (iterReferences != endReferences)
			{
				if (getReferences()->find(*iterReferences) == -1)
				{
					getReferences()->add(*iterReferences);
				}
				iterReferences++;			
			}
			return true;
		}
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_SOURCE:
		{
			// BOOST CAST
			std::string _source = newValue->get<std::string>();
			setSource(_source); //14
			return true;
		}
	}

	return EModelElementImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any EAnnotationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = EModelElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

//*********************************
// Persistence Functions
//*********************************
void EAnnotationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get ecoreFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void EAnnotationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("source");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setSource(value);
		}
		std::shared_ptr<EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("references");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("references")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	EModelElementImpl::loadAttributes(loadHandler, attr_list);
}

void EAnnotationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("contents") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EObject";
			}
			loadHandler->handleChildContainer<ecore::EObject>(this->getContents());  

			return; 
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}
	//load BasePackage Nodes
	EModelElementImpl::loadNode(nodeName, loadHandler);
}

void EAnnotationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_EMODELELEMENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ecore::EModelElement> _eModelElement = std::dynamic_pointer_cast<ecore::EModelElement>( references.front() );
				setEModelElement(_eModelElement);
			}
			
			return;
		}

		case ecore::ecorePackage::EANNOTATION_ATTRIBUTE_REFERENCES:
		{
			std::shared_ptr<Bag<ecore::EObject>> _references = getReferences();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ecore::EObject>  _r = std::dynamic_pointer_cast<ecore::EObject>(ref);
				if (_r != nullptr)
				{
					_references->push_back(_r);
				}
			}
			return;
		}
	}
	EModelElementImpl::resolveReferences(featureID, references);
}

void EAnnotationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EModelElementImpl::saveContent(saveHandler);
	
	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void EAnnotationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::ecorePackage> package = ecore::ecorePackage::eInstance();
		// Save 'contents'
		for (std::shared_ptr<ecore::EObject> contents : *this->getContents()) 
		{
			saveHandler->addReference(contents, "contents", contents->eClass() != package->getEObject_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getEAnnotation_Attribute_source()) )
		{
			saveHandler->addAttribute("source", this->getSource());
		}
	// Add references
		saveHandler->addReferences<ecore::EObject>("references", this->getReferences());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

