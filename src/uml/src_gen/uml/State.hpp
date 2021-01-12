//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STATE_HPP
#define UML_STATE_HPP

#include <map>
#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T, class ... U> class Subset;


class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

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

namespace uml
{
	class umlFactory;
}

//Forward Declaration for used types
namespace uml 
{
	class Behavior;
}

namespace uml 
{
	class Classifier;
}

namespace uml 
{
	class Comment;
}

namespace uml 
{
	class ConnectionPointReference;
}

namespace uml 
{
	class Constraint;
}

namespace uml 
{
	class Dependency;
}

namespace uml 
{
	class Element;
}

namespace uml 
{
	class ElementImport;
}

namespace uml 
{
	class NamedElement;
}

namespace uml 
{
	class Namespace;
}

namespace uml 
{
	class PackageImport;
}

namespace uml 
{
	class PackageableElement;
}

namespace uml 
{
	class Pseudostate;
}

namespace uml 
{
	class RedefinableElement;
}

namespace uml 
{
	class Region;
}

namespace uml 
{
	class State;
}

namespace uml 
{
	class StateMachine;
}

namespace uml 
{
	class StringExpression;
}

namespace uml 
{
	class Transition;
}

namespace uml 
{
	class Trigger;
}

namespace uml 
{
	class Vertex;
}

// base class includes
#include "uml/Namespace.hpp"

#include "uml/RedefinableElement.hpp"

#include "uml/Vertex.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	A State models a situation during which some (usually implicit) invariant condition holds.
	<p>From package UML::StateMachines.</p>
	*/
	
	class State:virtual public Namespace,virtual public RedefinableElement,virtual public Vertex
	{
		public:
 			State(const State &) {}
			State& operator=(State const&) = delete;

		protected:
			State(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~State() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			Only composite States can have entry or exit Pseudostates defined.
			connectionPoint->notEmpty() implies isComposite
			*/
			 
			virtual bool composite_states(Any diagnostics,std::map <   Any, Any >  context) = 0;
			
			/*!
			The connection point references used as destinations/sources of Transitions associated with a submachine State must be defined as entry/exit points in the submachine StateMachine.
			self.isSubmachineState implies (self.connection->forAll (cp |
			  cp.entry->forAll (ps | ps.stateMachine = self.submachine) and
			  cp.exit->forAll (ps | ps.stateMachine = self.submachine)))
			*/
			 
			virtual bool destinations_or_sources_of_transitions(Any diagnostics,std::map <   Any, Any >  context) = 0;
			
			/*!
			Only entry or exit Pseudostates can serve as connection points.
			connectionPoint->forAll(kind = PseudostateKind::entryPoint or kind = PseudostateKind::exitPoint)
			*/
			 
			virtual bool entry_or_exit(Any diagnostics,std::map <   Any, Any >  context) = 0;
			
			/*!
			A composite State is a State with at least one Region.
			result = (region->notEmpty())
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual bool isComposite() = 0;
			
			/*!
			An orthogonal State is a composite state with at least 2 regions.
			result = (region->size () > 1)
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual bool isOrthogonal() = 0;
			
			/*!
			A simple State is a State without any regions.
			result = ((region->isEmpty()) and not isSubmachineState())
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual bool isSimple() = 0;
			
			/*!
			Only submachine State references another StateMachine.
			result = (submachine <> null)
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual bool isSubmachineState() = 0;
			
			/*!
			The redefinition context of a State is the nearest containing StateMachine.
			result = (let sm : StateMachine = containingStateMachine() in
			if sm._'context' = null or sm.general->notEmpty() then
			  sm
			else
			  sm._'context'
			endif)
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual std::shared_ptr<uml::Classifier> redefinitionContext() = 0;
			
			/*!
			A State is not allowed to have both a submachine and Regions.
			isComposite implies not isSubmachineState
			*/
			 
			virtual bool submachine_or_regions(Any diagnostics,std::map <   Any, Any >  context) = 0;
			
			/*!
			Only submachine States can have connection point references.
			isSubmachineState implies connection->notEmpty( )
			*/
			 
			virtual bool submachine_states(Any diagnostics,std::map <   Any, Any >  context) = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			A state with isComposite=true is said to be a composite State. A composite State is a State that contains at least one Region.
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual bool getIsComposite() const = 0;
			
			
			/*!
			A State with isOrthogonal=true is said to be an orthogonal composite State An orthogonal composite State contains two or more Regions.
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual bool getIsOrthogonal() const = 0;
			
			
			/*!
			A State with isSimple=true is said to be a simple State A simple State does not have any Regions and it does not refer to any submachine StateMachine.
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual bool getIsSimple() const = 0;
			
			
			/*!
			A State with isSubmachineState=true is said to be a submachine State Such a State refers to another StateMachine(submachine).
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual bool getIsSubmachineState() const = 0;
			
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The entry and exit connection points used in conjunction with this (submachine) State, i.e., as targets and sources, respectively, in the Region with the submachine State. A connection point reference references the corresponding definition of a connection point Pseudostate in the StateMachine referenced by the submachine State.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ConnectionPointReference, uml::NamedElement>> getConnection() const = 0;
			
			
			/*!
			The entry and exit Pseudostates of a composite State. These can only be entry or exit Pseudostates, and they must have different names. They can only be defined for composite States.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Pseudostate, uml::NamedElement>> getConnectionPoint() const = 0;
			
			
			/*!
			A list of Triggers that are candidates to be retained by the StateMachine if they trigger no Transitions out of the State (not consumed). A deferred Trigger is retained until the StateMachine reaches a State configuration where it is no longer deferred.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Trigger, uml::Element>> getDeferrableTrigger() const = 0;
			
			
			/*!
			An optional Behavior that is executed while being in the State. The execution starts when this State is entered, and ceases either by itself when done, or when the State is exited, whichever comes first.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::Behavior > getDoActivity() const = 0;
			
			/*!
			An optional Behavior that is executed while being in the State. The execution starts when this State is entered, and ceases either by itself when done, or when the State is exited, whichever comes first.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setDoActivity(std::shared_ptr<uml::Behavior> _doActivity) = 0;
			
			/*!
			An optional Behavior that is executed whenever this State is entered regardless of the Transition taken to reach the State. If defined, entry Behaviors are always executed to completion prior to any internal Behavior or Transitions performed within the State.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::Behavior > getEntry() const = 0;
			
			/*!
			An optional Behavior that is executed whenever this State is entered regardless of the Transition taken to reach the State. If defined, entry Behaviors are always executed to completion prior to any internal Behavior or Transitions performed within the State.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setEntry(std::shared_ptr<uml::Behavior> _entry) = 0;
			
			/*!
			An optional Behavior that is executed whenever this State is exited regardless of which Transition was taken out of the State. If defined, exit Behaviors are always executed to completion only after all internal and transition Behaviors have completed execution.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::Behavior > getExit() const = 0;
			
			/*!
			An optional Behavior that is executed whenever this State is exited regardless of which Transition was taken out of the State. If defined, exit Behaviors are always executed to completion only after all internal and transition Behaviors have completed execution.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setExit(std::shared_ptr<uml::Behavior> _exit) = 0;
			
			/*!
			The State of which this State is a redefinition.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::State > getRedefinedState() const = 0;
			
			/*!
			The State of which this State is a redefinition.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setRedefinedState(std::shared_ptr<uml::State> _redefinedState) = 0;
			
			/*!
			The Regions owned directly by the State.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Region, uml::NamedElement>> getRegion() const = 0;
			
			
			/*!
			Specifies conditions that are always true when this State is the current State. In ProtocolStateMachines state invariants are additional conditions to the preconditions of the outgoing Transitions, and to the postcondition of the incoming Transitions.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::Constraint > getStateInvariant() const = 0;
			
			/*!
			Specifies conditions that are always true when this State is the current State. In ProtocolStateMachines state invariants are additional conditions to the preconditions of the outgoing Transitions, and to the postcondition of the incoming Transitions.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setStateInvariant(std::shared_ptr<uml::Constraint> _stateInvariant) = 0;
			
			/*!
			The StateMachine that is to be inserted in place of the (submachine) State.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<uml::StateMachine > getSubmachine() const = 0;
			
			/*!
			The StateMachine that is to be inserted in place of the (submachine) State.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setSubmachine(std::shared_ptr<uml::StateMachine> _submachine) = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			A state with isComposite=true is said to be a composite State. A composite State is a State that contains at least one Region.
			<p>From package UML::StateMachines.</p>
			*/
			 
			bool m_isComposite = false;
			/*!
			A State with isOrthogonal=true is said to be an orthogonal composite State An orthogonal composite State contains two or more Regions.
			<p>From package UML::StateMachines.</p>
			*/
			 
			bool m_isOrthogonal = false;
			/*!
			A State with isSimple=true is said to be a simple State A simple State does not have any Regions and it does not refer to any submachine StateMachine.
			<p>From package UML::StateMachines.</p>
			*/
			 
			bool m_isSimple = true;
			/*!
			A State with isSubmachineState=true is said to be a submachine State Such a State refers to another StateMachine(submachine).
			<p>From package UML::StateMachines.</p>
			*/
			 
			bool m_isSubmachineState = false;
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The entry and exit connection points used in conjunction with this (submachine) State, i.e., as targets and sources, respectively, in the Region with the submachine State. A connection point reference references the corresponding definition of a connection point Pseudostate in the StateMachine referenced by the submachine State.
			<p>From package UML::StateMachines.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::ConnectionPointReference, uml::NamedElement>> m_connection;/*!
			The entry and exit Pseudostates of a composite State. These can only be entry or exit Pseudostates, and they must have different names. They can only be defined for composite States.
			<p>From package UML::StateMachines.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Pseudostate, uml::NamedElement>> m_connectionPoint;/*!
			A list of Triggers that are candidates to be retained by the StateMachine if they trigger no Transitions out of the State (not consumed). A deferred Trigger is retained until the StateMachine reaches a State configuration where it is no longer deferred.
			<p>From package UML::StateMachines.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Trigger, uml::Element>> m_deferrableTrigger;/*!
			An optional Behavior that is executed while being in the State. The execution starts when this State is entered, and ceases either by itself when done, or when the State is exited, whichever comes first.
			<p>From package UML::StateMachines.</p>
			*/
			
			std::shared_ptr<uml::Behavior > m_doActivity;/*!
			An optional Behavior that is executed whenever this State is entered regardless of the Transition taken to reach the State. If defined, entry Behaviors are always executed to completion prior to any internal Behavior or Transitions performed within the State.
			<p>From package UML::StateMachines.</p>
			*/
			
			std::shared_ptr<uml::Behavior > m_entry;/*!
			An optional Behavior that is executed whenever this State is exited regardless of which Transition was taken out of the State. If defined, exit Behaviors are always executed to completion only after all internal and transition Behaviors have completed execution.
			<p>From package UML::StateMachines.</p>
			*/
			
			std::shared_ptr<uml::Behavior > m_exit;/*!
			The State of which this State is a redefinition.
			<p>From package UML::StateMachines.</p>
			*/
			
			std::shared_ptr<uml::State > m_redefinedState;/*!
			The Regions owned directly by the State.
			<p>From package UML::StateMachines.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Region, uml::NamedElement>> m_region;/*!
			Specifies conditions that are always true when this State is the current State. In ProtocolStateMachines state invariants are additional conditions to the preconditions of the outgoing Transitions, and to the postcondition of the incoming Transitions.
			<p>From package UML::StateMachines.</p>
			*/
			
			std::shared_ptr<uml::Constraint > m_stateInvariant;/*!
			The StateMachine that is to be inserted in place of the (submachine) State.
			<p>From package UML::StateMachines.</p>
			*/
			
			std::shared_ptr<uml::StateMachine > m_submachine;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const = 0;/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace > getNamespace() const = 0;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> getOwnedMember() const = 0;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element > getOwner() const = 0;/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_STATE_HPP */
