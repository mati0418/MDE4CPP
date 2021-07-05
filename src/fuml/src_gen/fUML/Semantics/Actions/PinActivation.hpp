//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_PINACTIVATION_HPP
#define FUML_SEMANTICS_ACTIONS_PINACTIVATION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 


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
	class ActionActivation;
}
namespace fUML::Semantics::Activities 
{
	class ActivityEdgeInstance;
	class ActivityNodeActivationGroup;
	class Token;
}
namespace uml 
{
	class ActivityNode;
	class Pin;
}

// namespace macro header include
#include "fUML/fUML.hpp"

// base class includes
#include "fUML/Semantics/Activities/ObjectNodeActivation.hpp"

// enum includes



//*********************************
namespace fUML::Semantics::Actions 
{
	
	class FUML_API PinActivation: virtual public fUML::Semantics::Activities::ObjectNodeActivation
	{
		public:
 			PinActivation(const PinActivation &) {}

		protected:
			PinActivation(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~PinActivation() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual void fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens) = 0; 
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > takeOfferedTokens() = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::weak_ptr<fUML::Semantics::Actions::ActionActivation> getActionActivation() const = 0;
			
			virtual void setActionActivation(std::weak_ptr<fUML::Semantics::Actions::ActionActivation>) = 0;
			
			virtual std::shared_ptr<uml::Pin> getPin() const = 0;
			
			virtual void setPin(std::shared_ptr<uml::Pin>) = 0;
			/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'pin'*/
			
			virtual void setNode(std::shared_ptr<uml::ActivityNode>) = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			std::weak_ptr<fUML::Semantics::Actions::ActionActivation> m_actionActivation;
			std::shared_ptr<uml::Pin> m_pin;

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
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_PINACTIVATION_HPP */
