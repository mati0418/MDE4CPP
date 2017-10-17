//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CONNECTIONPOINTREFERENCECONNECTIONPOINTREFERENCEIMPL_HPP
#define UML_CONNECTIONPOINTREFERENCECONNECTIONPOINTREFERENCEIMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//*********************************
// generated Includes

//Model includes
#include "../ConnectionPointReference.hpp"

#include "impl/VertexImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace uml 
{
	class ConnectionPointReferenceImpl :virtual public VertexImpl, virtual public ConnectionPointReference 
	{
		public: 
			ConnectionPointReferenceImpl(const ConnectionPointReferenceImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ConnectionPointReferenceImpl& operator=(ConnectionPointReferenceImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			ConnectionPointReferenceImpl();

			//Additional constructors for the containments back reference
			ConnectionPointReferenceImpl(std::weak_ptr<uml::Region > par_container);


			//Additional constructors for the containments back reference
			ConnectionPointReferenceImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			ConnectionPointReferenceImpl(std::weak_ptr<uml::Element > par_owner);


			//Additional constructors for the containments back reference
			ConnectionPointReferenceImpl(std::weak_ptr<uml::State > par_state);




		public:
			//destructor
			virtual ~ConnectionPointReferenceImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 The entry Pseudostates must be Pseudostates with kind entryPoint.
			entry->forAll(kind = PseudostateKind::entryPoint) */ 
			virtual bool entry_pseudostates(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			/*!
			 The exit Pseudostates must be Pseudostates with kind exitPoint.
			exit->forAll(kind = PseudostateKind::exitPoint) */ 
			virtual bool exit_pseudostates(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The entryPoint Pseudostates corresponding to this connection point.
			<p>From package UML::StateMachines.</p> */
			virtual std::shared_ptr< Bag<uml::Pseudostate> > getEntry() const ;
			
			/*!
			 The exitPoints kind Pseudostates corresponding to this connection point.
			<p>From package UML::StateMachines.</p> */
			virtual std::shared_ptr< Bag<uml::Pseudostate> > getExit() const ;
			
			/*!
			 The State in which the ConnectionPointReference is defined.
			<p>From package UML::StateMachines.</p> */
			virtual std::weak_ptr<uml::State > getState() const ;
			
			/*!
			 The State in which the ConnectionPointReference is defined.
			<p>From package UML::StateMachines.</p> */
			virtual void setState(std::shared_ptr<uml::State> _state_state) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Namespace > getNamespace() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element> > getOwnedElement() const ;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
	};
}
#endif /* end of include guard: UML_CONNECTIONPOINTREFERENCECONNECTIONPOINTREFERENCEIMPL_HPP */

