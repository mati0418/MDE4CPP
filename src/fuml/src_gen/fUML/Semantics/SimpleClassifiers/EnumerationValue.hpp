//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_SIMPLECLASSIFIERS_ENUMERATIONVALUE_HPP
#define FUML_SEMANTICS_SIMPLECLASSIFIERS_ENUMERATIONVALUE_HPP


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
	class Classifier;
	class Enumeration;
	class EnumerationLiteral;
	class ValueSpecification;
}

// namespace macro header include
#include "fuml/fuml.hpp"

// base class includes
#include "fUML/Semantics/Values/Value.hpp"

// enum includes



//*********************************
namespace fUML::Semantics::SimpleClassifiers 
{
	
	class FUML_API EnumerationValue: virtual public fUML::Semantics::Values::Value
	{
		public:
 			EnumerationValue(const EnumerationValue &) {}

		protected:
			EnumerationValue(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EnumerationValue() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> _copy() = 0; 
			virtual bool equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue) = 0; 
			virtual std::shared_ptr<Bag<uml::Classifier> > getTypes() = 0; 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> new_() = 0; 
			virtual std::shared_ptr<uml::ValueSpecification> specify() = 0; 
			virtual std::string toString() = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<uml::EnumerationLiteral> getLiteral() const = 0;
			
			virtual void setLiteral(std::shared_ptr<uml::EnumerationLiteral>) = 0;
			
			virtual std::shared_ptr<uml::Enumeration> getType() const = 0;
			
			virtual void setType(std::shared_ptr<uml::Enumeration>) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			std::shared_ptr<uml::EnumerationLiteral> m_literal;
			std::shared_ptr<uml::Enumeration> m_type;

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
#endif /* end of include guard: FUML_SEMANTICS_SIMPLECLASSIFIERS_ENUMERATIONVALUE_HPP */
