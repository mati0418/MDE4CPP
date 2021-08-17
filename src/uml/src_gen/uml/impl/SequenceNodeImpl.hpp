//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_SEQUENCENODESEQUENCENODEIMPL_HPP
#define UML_SEQUENCENODESEQUENCENODEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../SequenceNode.hpp"

#include "uml/impl/StructuredActivityNodeImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API SequenceNodeImpl : virtual public StructuredActivityNodeImpl, virtual public SequenceNode 
	{
		public: 
			SequenceNodeImpl(const SequenceNodeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			SequenceNodeImpl& operator=(SequenceNodeImpl const&); 

		protected:
			friend class umlFactoryImpl;
			SequenceNodeImpl();
			virtual std::shared_ptr<SequenceNode> getThisSequenceNodePtr() const;
			virtual void setThisSequenceNodePtr(std::weak_ptr<SequenceNode> thisSequenceNodePtr);

			//Additional constructors for the containments back reference
			SequenceNodeImpl(std::weak_ptr<uml::Activity> par_Activity, const int reference_id);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			SequenceNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			SequenceNodeImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			SequenceNodeImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			SequenceNodeImpl(std::weak_ptr<uml::ActivityGroup> par_superGroup);

		public:
			//destructor
			virtual ~SequenceNodeImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The ordered set of ExecutableNodes to be sequenced.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::ExecutableNode>> getExecutableNode() const ;
			
			
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			ActivityEdges immediately contained in the ActivityGroup.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityEdge>> getContainedEdge() const ;/*!
			ActivityNodes immediately contained in the ActivityGroup.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityNode>> getContainedNode() const ;/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;/*!
			The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> getInput() const ;/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const ;/*!
			The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> getOutput() const ;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> getOwnedMember() const ;/*!
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
			std::weak_ptr<SequenceNode> m_thisSequenceNodePtr;
	};
}
#endif /* end of include guard: UML_SEQUENCENODESEQUENCENODEIMPL_HPP */
