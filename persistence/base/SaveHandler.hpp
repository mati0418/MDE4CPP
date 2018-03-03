/*
 * SaveHandler.hpp
 *
 *  Created on: 29.05.2017
 *      Author: Alexander
 */

#ifndef PERSISTENCE_BASE_SAVEHANDLER_HPP
#define PERSISTENCE_BASE_SAVEHANDLER_HPP

#include "persistence/interface/XSaveHandler.hpp"

#include <string>

namespace ecore
{
	class EObject;
}

namespace persistence
{
	namespace base
	{
		class SaveHandler: public persistence::interface::XSaveHandler
		{
			public:
				SaveHandler();
				virtual ~SaveHandler();

				std::string getPrefix();
				void setRootObject(std::shared_ptr<ecore::EObject> object);

				std::string extractType(std::shared_ptr<ecore::EObject> obj) const;

				virtual bool createRootNode(const std::string& name, const std::string& ns_uri) = 0;
				virtual bool createRootNode(const std::string& prefix, const std::string& name, const std::string& ns_uri) = 0;

				virtual bool createAndAddElement(const std::string& name) = 0;

				void addAttribute(const std::string &name, bool value);
				virtual void addAttribute(const std::string &name, const std::string& value) = 0;

				void addReference(const std::string &name, std::shared_ptr<ecore::EObject> object);
				virtual void addReferences(const std::string &name, std::shared_ptr<ecore::EObject> object) = 0;

				virtual void release() = 0;

			protected:
				std::shared_ptr<ecore::EObject> m_rootObject;
				std::string m_rootPrefix;
		};
	} /* namespace base */
} /* namespace persistence */

#endif /* SaveHandler_HPP_ */
