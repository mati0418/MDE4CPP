//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_DEPLOYMENTTARGETDEPLOYMENTTARGETIMPL_HPP
#define UML_DEPLOYMENTTARGETDEPLOYMENTTARGETIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "uml/uml.hpp" 

// model includes
#include "../DeploymentTarget.hpp"

#include "uml/impl/NamedElementImpl.hpp"

//*********************************
namespace uml 
{
	class UML_API DeploymentTargetImpl : virtual public NamedElementImpl, virtual public DeploymentTarget 
	{
		public: 
			DeploymentTargetImpl(const DeploymentTargetImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			DeploymentTargetImpl& operator=(DeploymentTargetImpl const&); 

		protected:
			friend class umlFactoryImpl;
			DeploymentTargetImpl();
			virtual std::shared_ptr<DeploymentTarget> getThisDeploymentTargetPtr() const;
			virtual void setThisDeploymentTargetPtr(std::weak_ptr<DeploymentTarget> thisDeploymentTargetPtr);

			//Additional constructors for the containments back reference
			DeploymentTargetImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			DeploymentTargetImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~DeploymentTargetImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			Derivation for DeploymentTarget::/deployedElement
			result = (deployment.deployedArtifact->select(oclIsKindOf(Artifact))->collect(oclAsType(Artifact).manifestation)->collect(utilizedElement)->asSet())
			<p>From package UML::Deployments.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::PackageableElement> > getDeployedElements() ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The set of elements that are manifested in an Artifact that is involved in Deployment to a DeploymentTarget.
			<p>From package UML::Deployments.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::PackageableElement>> getDeployedElement() const ;
			
			/*!
			The set of Deployments for a DeploymentTarget.
			<p>From package UML::Deployments.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Deployment, uml::Element>> getDeployment() const ;
			
			
			
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

		private:
			std::weak_ptr<DeploymentTarget> m_thisDeploymentTargetPtr;
	};
}
#endif /* end of include guard: UML_DEPLOYMENTTARGETDEPLOYMENTTARGETIMPL_HPP */
