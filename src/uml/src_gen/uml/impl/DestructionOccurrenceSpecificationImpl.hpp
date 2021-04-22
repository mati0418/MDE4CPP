//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_DESTRUCTIONOCCURRENCESPECIFICATIONDESTRUCTIONOCCURRENCESPECIFICATIONIMPL_HPP
#define UML_DESTRUCTIONOCCURRENCESPECIFICATIONDESTRUCTIONOCCURRENCESPECIFICATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../DestructionOccurrenceSpecification.hpp"

#include "uml/impl/MessageOccurrenceSpecificationImpl.hpp"

//*********************************
namespace uml 
{
	class DestructionOccurrenceSpecificationImpl : virtual public MessageOccurrenceSpecificationImpl, virtual public DestructionOccurrenceSpecification 
	{
		public: 
			DestructionOccurrenceSpecificationImpl(const DestructionOccurrenceSpecificationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			DestructionOccurrenceSpecificationImpl& operator=(DestructionOccurrenceSpecificationImpl const&); 

		protected:
			friend class umlFactoryImpl;
			DestructionOccurrenceSpecificationImpl();
			virtual std::shared_ptr<DestructionOccurrenceSpecification> getThisDestructionOccurrenceSpecificationPtr() const;
			virtual void setThisDestructionOccurrenceSpecificationPtr(std::weak_ptr<DestructionOccurrenceSpecification> thisDestructionOccurrenceSpecificationPtr);

			//Additional constructors for the containments back reference
			DestructionOccurrenceSpecificationImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction);
			//Additional constructors for the containments back reference
			DestructionOccurrenceSpecificationImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand);
			//Additional constructors for the containments back reference
			DestructionOccurrenceSpecificationImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			DestructionOccurrenceSpecificationImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~DestructionOccurrenceSpecificationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			No other OccurrenceSpecifications on a given Lifeline in an InteractionOperand may appear below a DestructionOccurrenceSpecification.
			let o : InteractionOperand = enclosingOperand in o->notEmpty() and 
			let peerEvents : OrderedSet(OccurrenceSpecification) = covered.events->select(enclosingOperand = o)
			in peerEvents->last() = self
			*/
			 
			virtual bool no_occurrence_specifications_below(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
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
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const ;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ; 
			 
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
			std::weak_ptr<DestructionOccurrenceSpecification> m_thisDestructionOccurrenceSpecificationPtr;
	};
}
#endif /* end of include guard: UML_DESTRUCTIONOCCURRENCESPECIFICATIONDESTRUCTIONOCCURRENCESPECIFICATIONIMPL_HPP */
