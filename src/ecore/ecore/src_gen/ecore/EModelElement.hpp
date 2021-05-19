//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EMODELELEMENT_HPP
#define ECORE_EMODELELEMENT_HPP


#include <memory>
#include <string>
// forward declarations
template<class T, class ... U> class Subset;


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

namespace ecore
{
	class ecoreFactory;
}

//Forward Declaration for used types 
namespace ecore 
{
	class EAnnotation;
}

// namespace macro header include
#include "ecore/ecore.hpp"

// base class includes
#include "ecore/EObject.hpp"

// enum includes



//*********************************
namespace ecore 
{
	
	class ECORE_API EModelElement: virtual public EObject
	{
		public:
 			EModelElement(const EModelElement &) {}

		protected:
			EModelElement(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EModelElement() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<ecore::EAnnotation> getEAnnotation(std::string source) = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<Subset<ecore::EAnnotation, ecore::EObject>> getEAnnotations() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			mutable std::shared_ptr<Subset<ecore::EAnnotation, ecore::EObject>> m_eAnnotations;

		public:
			//*********************************
			// Union Getter
			//*********************************
			
			virtual std::shared_ptr<Union<ecore::EObject>> getEContens() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: ECORE_EMODELELEMENT_HPP */
