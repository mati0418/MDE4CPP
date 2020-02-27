//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_SIMPLECLASSIFIERS_STRUCTUREDVALUE_HPP
#define FUML_SEMANTICS_SIMPLECLASSIFIERS_STRUCTUREDVALUE_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T> class Bag; 



//*********************************
// generated Includes

#include <map>

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
	class FUMLFactory;
}

//Forward Declaration for used types
namespace fUML::Semantics::SimpleClassifiers 
{
	class FeatureValue;
}

namespace uml 
{
	class StructuralFeature;
}

namespace fUML::Semantics::Values 
{
	class Value;
}

namespace uml 
{
	class ValueSpecification;
}

// base class includes
#include "fUML/Semantics/Values/Value.hpp"

// enum includes


//*********************************
namespace fUML::Semantics::SimpleClassifiers 
{
	/*!
	 */
	class StructuredValue:virtual public fUML::Semantics::Values::Value
	{
		public:
 			StructuredValue(const StructuredValue &) {}
			StructuredValue& operator=(StructuredValue const&) = delete;

		protected:
			StructuredValue(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~StructuredValue() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void assignFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature,std::shared_ptr<Bag<fUML::Semantics::Values::Value> >  values,int position) = 0;
			
			/*!
			 */ 
			virtual void createFeatureValues() = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value> > getValues(std::shared_ptr<uml::StructuralFeature>  feature,std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue> >  featureValues) = 0;
			
			/*!
			 */ 
			virtual void removeValue(std::shared_ptr<uml::StructuralFeature>  feature,std::shared_ptr<fUML::Semantics::Values::Value>  value) = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature) = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue> > retrieveFeatureValues() = 0;
			
			/*!
			 */ 
			virtual void setFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature,std::shared_ptr<Bag<fUML::Semantics::Values::Value> >  values,int position) = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<uml::ValueSpecification> specify() = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
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
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: FUML_SEMANTICS_SIMPLECLASSIFIERS_STRUCTUREDVALUE_HPP */
