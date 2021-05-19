//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXTENSIONPOINTEXTENSIONPOINTIMPL_HPP
#define UML_EXTENSIONPOINTEXTENSIONPOINTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../ExtensionPoint.hpp"

#include "uml/impl/RedefinableElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API ExtensionPointImpl : virtual public RedefinableElementImpl, virtual public ExtensionPoint 
	{
		public: 
			ExtensionPointImpl(const ExtensionPointImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ExtensionPointImpl& operator=(ExtensionPointImpl const&); 

		protected:
			friend class umlFactoryImpl;
			ExtensionPointImpl();
			virtual std::shared_ptr<ExtensionPoint> getThisExtensionPointPtr() const;
			virtual void setThisExtensionPointPtr(std::weak_ptr<ExtensionPoint> thisExtensionPointPtr);

			//Additional constructors for the containments back reference
			ExtensionPointImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			ExtensionPointImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			ExtensionPointImpl(std::weak_ptr<uml::UseCase> par_useCase);

		public:
			//destructor
			virtual ~ExtensionPointImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			An ExtensionPoint must have a name.
			name->notEmpty ()
			*/
			 
			virtual bool must_have_name(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The UseCase that owns this ExtensionPoint.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual std::weak_ptr<uml::UseCase> getUseCase() const ;
			/*!
			The UseCase that owns this ExtensionPoint.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual void setUseCase(std::weak_ptr<uml::UseCase>) ;
			
			
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

		private:
			std::weak_ptr<ExtensionPoint> m_thisExtensionPointPtr;
	};
}
#endif /* end of include guard: UML_EXTENSIONPOINTEXTENSIONPOINTIMPL_HPP */
