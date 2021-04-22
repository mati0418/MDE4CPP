//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXECUTABLENODEEXECUTABLENODEIMPL_HPP
#define UML_EXECUTABLENODEEXECUTABLENODEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ExecutableNode.hpp"

#include "uml/impl/ActivityNodeImpl.hpp"

//*********************************
namespace uml 
{
	class ExecutableNodeImpl : virtual public ActivityNodeImpl, virtual public ExecutableNode 
	{
		public: 
			ExecutableNodeImpl(const ExecutableNodeImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ExecutableNodeImpl& operator=(ExecutableNodeImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ExecutableNodeImpl();
			virtual std::shared_ptr<ExecutableNode> getThisExecutableNodePtr() const;
			virtual void setThisExecutableNodePtr(std::weak_ptr<ExecutableNode> thisExecutableNodePtr);

			//Additional constructors for the containments back reference
			ExecutableNodeImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			ExecutableNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			ExecutableNodeImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ExecutableNodeImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~ExecutableNodeImpl();
			
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
			A set of ExceptionHandlers that are examined if an exception propagates out of the ExceptionNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ExceptionHandler, uml::Element>> getHandler() const ;
			
			
			
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
			std::weak_ptr<ExecutableNode> m_thisExecutableNodePtr;
	};
}
#endif /* end of include guard: UML_EXECUTABLENODEEXECUTABLENODEIMPL_HPP */
