//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_HPP
#define PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_HPP

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

namespace PSCS
{
	class PSCSFactory;
}

//Forward Declaration for used types
namespace PSCS::Semantics::StructuredClassifiers 
{
	class CS_Object;
}

namespace fUML::Semantics::SimpleClassifiers 
{
	class FeatureValue;
}

namespace fUML::Semantics::Loci 
{
	class SemanticStrategy;
}

namespace uml 
{
	class StructuralFeature;
}

namespace fUML::Semantics::Values 
{
	class Value;
}

// base class includes
#include "fUML/Semantics/Loci/SemanticStrategy.hpp"

// enum includes


//*********************************
namespace PSCS::Semantics::StructuredClassifiers 
{
	/*!
	 */
	class CS_StructuralFeatureOfInterfaceAccessStrategy:virtual public fUML::Semantics::Loci::SemanticStrategy
	{
		public:
 			CS_StructuralFeatureOfInterfaceAccessStrategy(const CS_StructuralFeatureOfInterfaceAccessStrategy &) {}
			CS_StructuralFeatureOfInterfaceAccessStrategy& operator=(CS_StructuralFeatureOfInterfaceAccessStrategy const&) = delete;

		protected:
			CS_StructuralFeatureOfInterfaceAccessStrategy(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CS_StructuralFeatureOfInterfaceAccessStrategy() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::string getName() = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> read(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object>  cs_Object,std::shared_ptr<uml::StructuralFeature>  feature) = 0;
			
			/*!
			 */ 
			virtual void write(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object>  cs_Object,std::shared_ptr<uml::StructuralFeature>  feature,std::shared_ptr<Bag<fUML::Semantics::Values::Value> >  values,int position) = 0;
			
			
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
#endif /* end of include guard: PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_STRUCTURALFEATUREOFINTERFACEACCESSSTRATEGY_HPP */
