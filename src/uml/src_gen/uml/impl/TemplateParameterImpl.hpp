//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TEMPLATEPARAMETERTEMPLATEPARAMETERIMPL_HPP
#define UML_TEMPLATEPARAMETERTEMPLATEPARAMETERIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../TemplateParameter.hpp"

#include "uml/impl/ElementImpl.hpp"

//*********************************
namespace uml 
{
	class TemplateParameterImpl : virtual public ElementImpl, virtual public TemplateParameter 
	{
		public: 
			TemplateParameterImpl(const TemplateParameterImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			TemplateParameterImpl& operator=(TemplateParameterImpl const&); 

		protected:
			friend class umlFactoryImpl;
			TemplateParameterImpl();
			virtual std::shared_ptr<TemplateParameter> getThisTemplateParameterPtr() const;
			virtual void setThisTemplateParameterPtr(std::weak_ptr<TemplateParameter> thisTemplateParameterPtr);

			//Additional constructors for the containments back reference
			TemplateParameterImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			TemplateParameterImpl(std::weak_ptr<uml::TemplateSignature> par_signature);

		public:
			//destructor
			virtual ~TemplateParameterImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The default must be compatible with the formal TemplateParameter.
			default <> null implies default.isCompatibleWith(parameteredElement)
			*/
			 
			virtual bool must_be_compatible(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The ParameterableElement that is the default for this formal TemplateParameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::ParameterableElement> getDefault() const ;
			/*!
			The ParameterableElement that is the default for this formal TemplateParameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setDefault(std::shared_ptr<uml::ParameterableElement>) ;
			/*!
			The ParameterableElement that is owned by this TemplateParameter for the purpose of providing a default.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::ParameterableElement> getOwnedDefault() const ;
			/*!
			The ParameterableElement that is owned by this TemplateParameter for the purpose of providing a default.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setOwnedDefault(std::shared_ptr<uml::ParameterableElement>) ;
			/*!
			The ParameterableElement that is owned by this TemplateParameter for the purpose of exposing it as the parameteredElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::ParameterableElement> getOwnedParameteredElement() const ;
			/*!
			The ParameterableElement that is owned by this TemplateParameter for the purpose of exposing it as the parameteredElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setOwnedParameteredElement(std::shared_ptr<uml::ParameterableElement>) ;
			/*!
			The ParameterableElement exposed by this TemplateParameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<uml::ParameterableElement> getParameteredElement() const ;
			/*!
			The ParameterableElement exposed by this TemplateParameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setParameteredElement(std::shared_ptr<uml::ParameterableElement>) ;
			/*!
			The TemplateSignature that owns this TemplateParameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::TemplateSignature> getSignature() const ;
			/*!
			The TemplateSignature that owns this TemplateParameter.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual void setSignature(std::weak_ptr<uml::TemplateSignature>) ;
			
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
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
			std::weak_ptr<TemplateParameter> m_thisTemplateParameterPtr;
	};
}
#endif /* end of include guard: UML_TEMPLATEPARAMETERTEMPLATEPARAMETERIMPL_HPP */
