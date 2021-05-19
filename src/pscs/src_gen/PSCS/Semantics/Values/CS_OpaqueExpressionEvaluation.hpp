//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_VALUES_CS_OPAQUEEXPRESSIONEVALUATION_HPP
#define PSCS_SEMANTICS_VALUES_CS_OPAQUEEXPRESSIONEVALUATION_HPP


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

namespace PSCS
{
	class PSCSFactory;
}

//Forward Declaration for used types 
namespace fUML::Semantics::Loci 
{
	class Locus;
}
namespace fUML::Semantics::Values 
{
	class Value;
}
namespace uml 
{
	class ValueSpecification;
}

// namespace macro header include
#include "pscs/pscs.hpp"

// base class includes
#include "fUML/Semantics/Values/Evaluation.hpp"

// enum includes



//*********************************
namespace PSCS::Semantics::Values 
{
	
	class PSCS_API CS_OpaqueExpressionEvaluation: virtual public fUML::Semantics::Values::Evaluation
	{
		public:
 			CS_OpaqueExpressionEvaluation(const CS_OpaqueExpressionEvaluation &) {}

		protected:
			CS_OpaqueExpressionEvaluation(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CS_OpaqueExpressionEvaluation() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> evaluate() = 0; 
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value> > executeExpressionBehavior() = 0;
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
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: PSCS_SEMANTICS_VALUES_CS_OPAQUEEXPRESSIONEVALUATION_HPP */
