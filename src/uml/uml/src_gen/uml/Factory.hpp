//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_FACTORY_HPP
#define UML_FACTORY_HPP


#include <memory>
#include <string>
// forward declarations


//*********************************
// generated Includes
#include <map> // used for Persistence
#include <vector> // used for Persistence
namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace uml
{
	class umlFactory;
}

//Forward Declaration for used types 
namespace uml 
{
	class Class;
	class Comment;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Element.hpp"




//*********************************
namespace uml 
{
	/*!
	An Element may be created from a Factory. A Factory is an instance of the MOF Factory class. A Factory creates
	instances of the types in a Package.
	
	<span style="background-color:#FF8000">This Element was merged from mof::Reflection package.</span>
	*/
	
	class UML_API Factory: virtual public Element
	{
		public:
 			Factory(const Factory &) {}

		protected:
			Factory(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Factory() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			Creates an element that is an instance of the metaClass. Object::metaClass == metaClass and metaClass.isInstance(object)
			== true.
			All properties of the element are considered unset. The values are the same as if object.unset(property) was invoked for
			every property.
			*/
			 
			virtual std::shared_ptr<uml::Element> create(std::shared_ptr<uml::Class> metaClass) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************

			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
	};
}
#endif /* end of include guard: UML_FACTORY_HPP */