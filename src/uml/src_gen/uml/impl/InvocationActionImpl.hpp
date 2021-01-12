//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_INVOCATIONACTIONINVOCATIONACTIONIMPL_HPP
#define UML_INVOCATIONACTIONINVOCATIONACTIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../InvocationAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class InvocationActionImpl : virtual public ActionImpl, virtual public InvocationAction 
	{
		public: 
			InvocationActionImpl(const InvocationActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			InvocationActionImpl& operator=(InvocationActionImpl const&) = delete;

		protected:
			friend class umlFactoryImpl;
			InvocationActionImpl();
			virtual std::shared_ptr<InvocationAction> getThisInvocationActionPtr() const;
			virtual void setThisInvocationActionPtr(std::weak_ptr<InvocationAction> thisInvocationActionPtr);

			//Additional constructors for the containments back reference
			InvocationActionImpl(std::weak_ptr<uml::Activity > par_activity);


			//Additional constructors for the containments back reference
			InvocationActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode);


			//Additional constructors for the containments back reference
			InvocationActionImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			InvocationActionImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~InvocationActionImpl();
			
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
			The InputPins that provide the argument values passed in the invocation request.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::InputPin, uml::InputPin>> getArgument() const ;
			
			
			/*!
			For CallOperationActions, SendSignalActions, and SendObjectActions, an optional Port of the target object through which the invocation request is sent.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::Port > getOnPort() const ;
			
			/*!
			For CallOperationActions, SendSignalActions, and SendObjectActions, an optional Port of the target object through which the invocation request is sent.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setOnPort(std::shared_ptr<uml::Port> _onPort) ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;/*!
			The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> getInput() const ;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element > getOwner() const ;/*!
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
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<InvocationAction> m_thisInvocationActionPtr;
	};
}
#endif /* end of include guard: UML_INVOCATIONACTIONINVOCATIONACTIONIMPL_HPP */
