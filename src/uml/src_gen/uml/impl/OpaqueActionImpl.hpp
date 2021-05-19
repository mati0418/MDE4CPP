//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_OPAQUEACTIONOPAQUEACTIONIMPL_HPP
#define UML_OPAQUEACTIONOPAQUEACTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../OpaqueAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API OpaqueActionImpl : virtual public ActionImpl, virtual public OpaqueAction 
	{
		public: 
			OpaqueActionImpl(const OpaqueActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			OpaqueActionImpl& operator=(OpaqueActionImpl const&); 

		protected:
			friend class umlFactoryImpl;
			OpaqueActionImpl();
			virtual std::shared_ptr<OpaqueAction> getThisOpaqueActionPtr() const;
			virtual void setThisOpaqueActionPtr(std::weak_ptr<OpaqueAction> thisOpaqueActionPtr);

			//Additional constructors for the containments back reference
			OpaqueActionImpl(std::weak_ptr<uml::Activity> par_activity);
			//Additional constructors for the containments back reference
			OpaqueActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode);
			//Additional constructors for the containments back reference
			OpaqueActionImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			OpaqueActionImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~OpaqueActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			If the language attribute is not empty, then the size of the body and language lists must be the same.
			language->notEmpty() implies (_'body'->size() = language->size())
			*/
			 
			virtual bool language_body_size(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			Provides a textual specification of the functionality of the Action, in one or more languages other than UML.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual std::shared_ptr<Bag<std::string>> getBody() const ;
			
			/*!
			If provided, a specification of the language used for each of the body Strings.
			<p>From package UML::Actions.</p>
			*/
			 
			virtual std::shared_ptr<Bag<std::string>> getLanguage() const ;
			
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The InputPins providing inputs to the OpaqueAction.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> getInputValue() const ;
			
			/*!
			The OutputPins on which the OpaqueAction provides outputs.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> getOutputValue() const ;
			
			
			
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

		private:
			std::weak_ptr<OpaqueAction> m_thisOpaqueActionPtr;
	};
}
#endif /* end of include guard: UML_OPAQUEACTIONOPAQUEACTIONIMPL_HPP */
