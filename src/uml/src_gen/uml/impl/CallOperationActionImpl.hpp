//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CALLOPERATIONACTIONCALLOPERATIONACTIONIMPL_HPP
#define UML_CALLOPERATIONACTIONCALLOPERATIONACTIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../CallOperationAction.hpp"

#include "uml/impl/CallActionImpl.hpp"

//*********************************
namespace uml 
{
	class CallOperationActionImpl : virtual public CallActionImpl, virtual public CallOperationAction 
	{
		public: 
			CallOperationActionImpl(const CallOperationActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			CallOperationActionImpl& operator=(CallOperationActionImpl const&) = delete;

		protected:
			friend class umlFactoryImpl;
			CallOperationActionImpl();
			virtual std::shared_ptr<CallOperationAction> getThisCallOperationActionPtr() const;
			virtual void setThisCallOperationActionPtr(std::weak_ptr<CallOperationAction> thisCallOperationActionPtr);

			//Additional constructors for the containments back reference
			CallOperationActionImpl(std::weak_ptr<uml::Activity > par_activity);


			//Additional constructors for the containments back reference
			CallOperationActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode);


			//Additional constructors for the containments back reference
			CallOperationActionImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			CallOperationActionImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~CallOperationActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			If onPort has no value, the operation must be an owned or inherited feature of the type of the target InputPin, otherwise the Port given by onPort must be an owned or inherited feature of the type of the target InputPin, and the Port must have a required or provided Interface with the operation as an owned or inherited feature.
			if onPort=null then  target.type.oclAsType(Classifier).allFeatures()->includes(operation)
			else target.type.oclAsType(Classifier).allFeatures()->includes(onPort) and onPort.provided->union(onPort.required).allFeatures()->includes(operation)
			endif
			*/
			 
			virtual bool type_target_pin(Any diagnostics,std::map <   Any, Any >  context) ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The Operation being invoked.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::Operation > getOperation() const ;
			
			/*!
			The Operation being invoked.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setOperation(std::shared_ptr<uml::Operation> _operation) ;
			
			/*!
			The InputPin that provides the target object to which the Operation call request is sent.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin > getTarget() const ;
			
			/*!
			The InputPin that provides the target object to which the Operation call request is sent.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setTarget(std::shared_ptr<uml::InputPin> _target) ;
			
							
			
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
			The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> getOutput() const ;/*!
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
			std::weak_ptr<CallOperationAction> m_thisCallOperationActionPtr;
	};
}
#endif /* end of include guard: UML_CALLOPERATIONACTIONCALLOPERATIONACTIONIMPL_HPP */
