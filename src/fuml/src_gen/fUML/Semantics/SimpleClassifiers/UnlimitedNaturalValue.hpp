//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_SIMPLECLASSIFIERS_UNLIMITEDNATURALVALUE_HPP
#define FUML_SEMANTICS_SIMPLECLASSIFIERS_UNLIMITEDNATURALVALUE_HPP


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

namespace fUML
{
	class fUMLFactory;
}

//Forward Declaration for used types 
namespace uml 
{
	class PrimitiveType;
	class ValueSpecification;
}

// namespace macro header include
#include "fUML/fUML.hpp"

// base class includes
#include "fUML/Semantics/SimpleClassifiers/PrimitiveValue.hpp"

// enum includes



//*********************************
namespace fUML::Semantics::SimpleClassifiers 
{
	
	class FUML_API UnlimitedNaturalValue: virtual public PrimitiveValue
	{
		public:
 			UnlimitedNaturalValue(const UnlimitedNaturalValue &) {}

		protected:
			UnlimitedNaturalValue(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~UnlimitedNaturalValue() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> _copy() = 0; 
			virtual bool equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue) = 0; 
			virtual std::shared_ptr<uml::ValueSpecification> specify() = 0; 
			virtual std::string toString() = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			 
			virtual int getValue() const = 0;
			 
			virtual void setValue (int _value)= 0;
			
			//*********************************
			// Reference
			//*********************************
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			int m_value = 0;
			
			
			//*********************************
			// Reference Members
			//*********************************
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: FUML_SEMANTICS_SIMPLECLASSIFIERS_UNLIMITEDNATURALVALUE_HPP */
