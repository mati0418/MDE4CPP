//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_CREATEOBJECTACTIONACTIVATION_HPP
#define FUML_SEMANTICS_ACTIONS_CREATEOBJECTACTIONACTIVATION_HPP


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
namespace uml 
{
	class Action;
	class ActivityNode;
	class CreateObjectAction;
}

// namespace macro header include
#include "fuml/fuml.hpp"

// base class includes
#include "fUML/Semantics/Actions/ActionActivation.hpp"

// enum includes



//*********************************
namespace fUML::Semantics::Actions 
{
	
	class FUML_API CreateObjectActionActivation: virtual public ActionActivation
	{
		public:
 			CreateObjectActionActivation(const CreateObjectActionActivation &) {}

		protected:
			CreateObjectActionActivation(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CreateObjectActionActivation() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual void doAction() = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<uml::CreateObjectAction> getCreateObjectAction() const = 0;
			
			virtual void setCreateObjectAction(std::shared_ptr<uml::CreateObjectAction>) = 0;
			/*Additional Setter for 'ActionActivation::action' redefined by reference 'createObjectAction'*/
			
			virtual void setAction(std::shared_ptr<uml::Action>) = 0;/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'createObjectAction'*/
			
			virtual void setNode(std::shared_ptr<uml::ActivityNode>) = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			std::shared_ptr<uml::CreateObjectAction> m_createObjectAction;

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
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_CREATEOBJECTACTIONACTIVATION_HPP */
