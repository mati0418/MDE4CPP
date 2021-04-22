//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_FINALSTATEFINALSTATEIMPL_HPP
#define UML_FINALSTATEFINALSTATEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../FinalState.hpp"

#include "uml/impl/StateImpl.hpp"

//*********************************
namespace uml 
{
	class FinalStateImpl : virtual public StateImpl, virtual public FinalState 
	{
		public: 
			FinalStateImpl(const FinalStateImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			FinalStateImpl& operator=(FinalStateImpl const&); 

		protected:
			friend class umlFactoryImpl;
			FinalStateImpl();
			virtual std::shared_ptr<FinalState> getThisFinalStatePtr() const;
			virtual void setThisFinalStatePtr(std::weak_ptr<FinalState> thisFinalStatePtr);

			//Additional constructors for the containments back reference
			FinalStateImpl(std::weak_ptr<uml::Region> par_container);
			//Additional constructors for the containments back reference
			FinalStateImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			FinalStateImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~FinalStateImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			A FinalState cannot reference a submachine.
			submachine->isEmpty()
			*/
			 
			virtual bool cannot_reference_submachine(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			A FinalState has no entry Behavior.
			entry->isEmpty()
			*/
			 
			virtual bool no_entry_behavior(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			A FinalState has no exit Behavior.
			exit->isEmpty()
			*/
			 
			virtual bool no_exit_behavior(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			A FinalState cannot have any outgoing Transitions.
			outgoing->size() = 0
			*/
			 
			virtual bool no_outgoing_transitions(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			A FinalState cannot have Regions.
			region->size() = 0
			*/
			 
			virtual bool no_regions(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			A FinalState has no state (doActivity) Behavior.
			doActivity->isEmpty()
			*/
			 
			virtual bool no_state_behavior(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const ;/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const ;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> getOwnedMember() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
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
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<FinalState> m_thisFinalStatePtr;
	};
}
#endif /* end of include guard: UML_FINALSTATEFINALSTATEIMPL_HPP */
