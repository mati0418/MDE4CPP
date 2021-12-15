//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PSEUDOSTATEPSEUDOSTATEIMPL_HPP
#define UML_PSEUDOSTATEPSEUDOSTATEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../Pseudostate.hpp"

#include "uml/impl/VertexImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API PseudostateImpl : virtual public VertexImpl, virtual public Pseudostate 
	{
		public: 
			PseudostateImpl(const PseudostateImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			PseudostateImpl& operator=(PseudostateImpl const&); 

		protected:
			friend class umlFactoryImpl;
			PseudostateImpl();
			virtual std::shared_ptr<uml::Pseudostate> getThisPseudostatePtr() const;
			virtual void setThisPseudostatePtr(std::weak_ptr<uml::Pseudostate> thisPseudostatePtr);

			//Additional constructors for the containments back reference
			PseudostateImpl(std::weak_ptr<uml::Region> par_container);
			//Additional constructors for the containments back reference
			PseudostateImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			PseudostateImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			PseudostateImpl(std::weak_ptr<uml::State> par_state);
			//Additional constructors for the containments back reference
			PseudostateImpl(std::weak_ptr<uml::StateMachine> par_stateMachine);

		public:
			//destructor
			virtual ~PseudostateImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			In a complete statemachine, a choice Vertex must have at least one incoming and one outgoing Transition.
			(kind = PseudostateKind::choice) implies (incoming->size() >= 1 and outgoing->size() >= 1)
			*/
			 
			virtual bool choice_vertex(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			In a complete StateMachine, a fork Vertex must have at least two outgoing Transitions and exactly one incoming Transition.
			(kind = PseudostateKind::fork) implies (incoming->size() = 1 and outgoing->size() >= 2)
			*/
			 
			virtual bool fork_vertex(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			History Vertices can have at most one outgoing Transition.
			((kind = PseudostateKind::deepHistory) or (kind = PseudostateKind::shallowHistory)) implies (outgoing->size() <= 1)
			*/
			 
			virtual bool history_vertices(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			An initial Vertex can have at most one outgoing Transition.
			(kind = PseudostateKind::initial) implies (outgoing->size() <= 1)
			*/
			 
			virtual bool initial_vertex(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			In a complete StateMachine, a join Vertex must have at least two incoming Transitions and exactly one outgoing Transition.
			(kind = PseudostateKind::join) implies (outgoing->size() = 1 and incoming->size() >= 2)
			*/
			 
			virtual bool join_vertex(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			In a complete StateMachine, a junction Vertex must have at least one incoming and one outgoing Transition.
			(kind = PseudostateKind::junction) implies (incoming->size() >= 1 and outgoing->size() >= 1)
			*/
			 
			virtual bool junction_vertex(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			The outgoing Transition from an initial vertex may have a behavior, but not a trigger or a guard.
			(kind = PseudostateKind::initial) implies (outgoing.guard = null and outgoing.trigger->isEmpty())
			*/
			 
			virtual bool outgoing_from_initial(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			All Transitions incoming a join Vertex must originate in different Regions of an orthogonal State.
			(kind = PseudostateKind::join) implies
			
			-- for any pair of incoming transitions there exists an orthogonal state which contains the source vetices of these transitions 
			-- such that these source vertices belong to different regions of that orthogonal state 
			
			incoming->forAll(t1:Transition, t2:Transition | let contState:State = containingStateMachine().LCAState(t1.source, t2.source) in
				((contState <> null) and (contState.region
					->exists(r1:Region, r2: Region | (r1 <> r2) and t1.source.isContainedInRegion(r1) and t2.source.isContainedInRegion(r2)))))
			*/
			 
			virtual bool transitions_incoming(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			/*!
			All transitions outgoing a fork vertex must target states in different regions of an orthogonal state.
			(kind = PseudostateKind::fork) implies
			
			-- for any pair of outgoing transitions there exists an orthogonal state which contains the targets of these transitions 
			-- such that these targets belong to different regions of that orthogonal state 
			
			outgoing->forAll(t1:Transition, t2:Transition | let contState:State = containingStateMachine().LCAState(t1.target, t2.target) in
				((contState <> null) and (contState.region
					->exists(r1:Region, r2: Region | (r1 <> r2) and t1.target.isContainedInRegion(r1) and t2.target.isContainedInRegion(r2)))))
			*/
			 
			virtual bool transitions_outgoing(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attribute Getters & Setters
			//*********************************
			/*!
			Determines the precise type of the Pseudostate and can be one of: entryPoint, exitPoint, initial, deepHistory, shallowHistory, join, fork, junction, terminate or choice.
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual uml::PseudostateKind getKind() const ;
			/*!
			Determines the precise type of the Pseudostate and can be one of: entryPoint, exitPoint, initial, deepHistory, shallowHistory, join, fork, junction, terminate or choice.
			<p>From package UML::StateMachines.</p>
			*/
			 
			virtual void setKind (uml::PseudostateKind _kind);
			
			//*********************************
			// Reference Getters & Setters
			//*********************************
			/*!
			The State that owns this Pseudostate and in which it appears.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::weak_ptr<uml::State> getState() const ;
			/*!
			The State that owns this Pseudostate and in which it appears.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setState(std::weak_ptr<uml::State>) ;
			/*!
			The StateMachine in which this Pseudostate is defined. This only applies to Pseudostates of the kind entryPoint or exitPoint.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual std::weak_ptr<uml::StateMachine> getStateMachine() const ;
			/*!
			The StateMachine in which this Pseudostate is defined. This only applies to Pseudostates of the kind entryPoint or exitPoint.
			<p>From package UML::StateMachines.</p>
			*/
			
			virtual void setStateMachine(std::weak_ptr<uml::StateMachine>) ;
			
			//*********************************
			// Union Reference Getters
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const ;
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;
			/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;
			
			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;

			//*********************************
			// EStructuralFeature Get/Set/IsSet
			//*********************************
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual bool internalEIsSet(int featureID) const ;

			//*********************************
			// EOperation Invoke
			//*********************************
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments) ;

		private:
			std::weak_ptr<uml::Pseudostate> m_thisPseudostatePtr;
	};
}
#endif /* end of include guard: UML_PSEUDOSTATEPSEUDOSTATEIMPL_HPP */