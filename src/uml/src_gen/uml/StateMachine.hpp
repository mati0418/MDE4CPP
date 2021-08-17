//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_STATEMACHINE_HPP
#define UML_STATEMACHINE_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
template<class T, class ... U> class Subset;

class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

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

namespace uml
{
	class umlFactory;
}

//Forward Declaration for used types 
namespace uml 
{
	class BehavioralFeature;
	class CollaborationUse;
	class Comment;
	class ConnectableElement;
	class Connector;
	class Constraint;
	class Dependency;
	class ElementImport;
	class Extension;
	class Feature;
	class Generalization;
	class GeneralizationSet;
	class InterfaceRealization;
	class Operation;
	class Package;
	class PackageImport;
	class Parameter;
	class ParameterSet;
	class Port;
	class Property;
	class Pseudostate;
	class Reception;
	class Region;
	class State;
	class StringExpression;
	class Substitution;
	class TemplateBinding;
	class TemplateParameter;
	class TemplateSignature;
	class UseCase;
	class Vertex;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Behavior.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	StateMachines can be used to express event-driven behaviors of parts of a system. Behavior is modeled as a traversal of a graph of Vertices interconnected by one or more joined Transition arcs that are triggered by the dispatching of successive Event occurrences. During this traversal, the StateMachine may execute a sequence of Behaviors associated with various elements of the StateMachine.
	<p>From package UML::StateMachines.</p>
	*/
	
	class UML_API StateMachine: virtual public Behavior
	{
		public:
 			StateMachine(const StateMachine &) {}

		protected:
			StateMachine(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~StateMachine() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The operation LCA(s1,s2) returns the Region that is the least common ancestor of Vertices s1 and s2, based on the StateMachine containment hierarchy.
			result = (if ancestor(s1, s2) then 
			    s2.container
			else
				if ancestor(s2, s1) then
				    s1.container 
				else 
				    LCA(s1.container.state, s2.container.state)
				endif
			endif)
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual std::shared_ptr<uml::Region> LCA(std::shared_ptr<uml::Vertex> s1,std::shared_ptr<uml::Vertex> s2) = 0;/*!
			This utility funciton is like the LCA, except that it returns the nearest composite State that contains both input Vertices.
			result = (if v2.oclIsTypeOf(State) and ancestor(v1, v2) then
				v2.oclAsType(State)
			else if v1.oclIsTypeOf(State) and ancestor(v2, v1) then
				v1.oclAsType(State)
			else if (v1.container.state->isEmpty() or v2.container.state->isEmpty()) then 
				null.oclAsType(State)
			else LCAState(v1.container.state, v2.container.state)
			endif endif endif)
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual std::shared_ptr<uml::State> LCAState(std::shared_ptr<uml::Vertex> v1,std::shared_ptr<uml::Vertex> v2) = 0;/*!
			The query ancestor(s1, s2) checks whether Vertex s2 is an ancestor of Vertex s1.
			result = (if (s2 = s1) then 
				true 
			else 
				if s1.container.stateMachine->notEmpty() then 
				    true
				else 
				    if s2.container.stateMachine->notEmpty() then 
				        false
				    else
				        ancestor(s1, s2.container.state)
				     endif
				 endif
			endif  )
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual bool ancestor(std::shared_ptr<uml::Vertex> s1,std::shared_ptr<uml::Vertex> s2) = 0;/*!
			The Classifier context of a StateMachine cannot be an Interface.
			_'context' <> null implies not _'context'.oclIsKindOf(Interface)
			*/
			 
			virtual bool classifier_context(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			The connection points of a StateMachine are Pseudostates of kind entry point or exit point.
			connectionPoint->forAll (kind = PseudostateKind::entryPoint or kind = PseudostateKind::exitPoint)
			*/
			 
			virtual bool connection_points(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			The context Classifier of the method StateMachine of a BehavioralFeature must be the Classifier that owns the BehavioralFeature.
			specification <> null implies ( _'context' <> null and specification.featuringClassifier->exists(c | c = _'context'))
			*/
			 
			virtual bool context_classifier(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			A StateMachine as the method for a BehavioralFeature cannot have entry/exit connection points.
			specification <> null implies connectionPoint->isEmpty()
			*/
			 
			virtual bool method(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The connection points defined for this StateMachine. They represent the interface of the StateMachine when used as part of submachine State
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Pseudostate, uml::NamedElement>> getConnectionPoint() const = 0;
			
			/*!
			The StateMachines of which this is an extension.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::StateMachine>> getExtendedStateMachine() const = 0;
			
			/*!
			The Regions owned directly by the StateMachine.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Region, uml::NamedElement>> getRegion() const = 0;
			
			/*!
			References the submachine(s) in case of a submachine State. Multiple machines are referenced in case of a concurrent State.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::State>> getSubmachineState() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The connection points defined for this StateMachine. They represent the interface of the StateMachine when used as part of submachine State
			<p>From package UML::StateMachines.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Pseudostate, uml::NamedElement>> m_connectionPoint;/*!
			The Regions owned directly by the StateMachine.
			<p>From package UML::StateMachines.</p>
			*/
			
			mutable std::shared_ptr<Subset<uml::Region, uml::NamedElement>> m_region;/*!
			References the submachine(s) in case of a submachine State. Multiple machines are referenced in case of a concurrent State.
			<p>From package UML::StateMachines.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::State>> m_submachineState;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			All of the Properties that are direct (i.e., not inherited or imported) attributes of the Classifier.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> getAttribute() const = 0;/*!
			Specifies each Feature directly defined in the classifier. Note that there may be members of the Classifier that are of the type Feature but are not included, e.g., inherited features.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> getFeature() const = 0;/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const = 0;/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const = 0;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> getOwnedMember() const = 0;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const = 0;/*!
			The contexts that this element may be redefined from.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Classifier>> getRedefinitionContext() const = 0;/*!
			The roles that instances may play in this StructuredClassifier.
			<p>From package UML::StructuredClassifiers.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement>> getRole() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_STATEMACHINE_HPP */
