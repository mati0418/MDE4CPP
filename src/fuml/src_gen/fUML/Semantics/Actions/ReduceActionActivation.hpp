//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_REDUCEACTIONACTIVATION_HPP
#define FUML_SEMANTICS_ACTIONS_REDUCEACTIONACTIVATION_HPP


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
namespace fUML::Semantics::Actions 
{
	class InputPinActivation;
	class OutputPinActivation;
	class PinActivation;
}
namespace fUML::Semantics::Activities 
{
	class ActivityEdgeInstance;
	class ActivityNodeActivationGroup;
	class Token;
}
namespace fUML::Semantics::CommonBehavior 
{
	class Execution;
}
namespace uml 
{
	class Action;
	class ActivityNode;
}

// namespace macro header include
#include "fUML/fUML.hpp"

// base class includes
#include "fUML/Semantics/Actions/ActionActivation.hpp"

// enum includes



//*********************************
namespace fUML::Semantics::Actions 
{
	
	class FUML_API ReduceActionActivation: virtual public ActionActivation
	{
		public:
 			ReduceActionActivation(const ReduceActionActivation &) {}

		protected:
			ReduceActionActivation(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ReduceActionActivation() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> getCurrentExecution() const = 0;
			
			virtual void setCurrentExecution(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution>) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> m_currentExecution;

		public:
			//*********************************
			// Union Getter
			//*********************************
			
			virtual std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> getPinActivation() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_REDUCEACTIONACTIVATION_HPP */
