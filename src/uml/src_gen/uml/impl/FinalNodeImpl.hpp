//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_FINALNODEFINALNODEIMPL_HPP
#define UML_FINALNODEFINALNODEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../FinalNode.hpp"

#include "uml/impl/ControlNodeImpl.hpp"

//*********************************
namespace uml 
{
	class FinalNodeImpl : virtual public ControlNodeImpl, virtual public FinalNode 
	{
		public: 
			FinalNodeImpl(const FinalNodeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			FinalNodeImpl& operator=(FinalNodeImpl const&); 

		protected:
			friend class umlFactoryImpl;
			FinalNodeImpl();
			virtual std::shared_ptr<FinalNode> getThisFinalNodePtr() const;
			virtual void setThisFinalNodePtr(std::weak_ptr<FinalNode> thisFinalNodePtr);

			//Additional constructors for the containments back reference
			FinalNodeImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			FinalNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			FinalNodeImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			FinalNodeImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~FinalNodeImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			A FinalNode has no outgoing ActivityEdges.
			outgoing->isEmpty()
			*/
			 
			virtual bool no_outgoing_edges(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
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
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
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
			std::weak_ptr<FinalNode> m_thisFinalNodePtr;
	};
}
#endif /* end of include guard: UML_FINALNODEFINALNODEIMPL_HPP */
