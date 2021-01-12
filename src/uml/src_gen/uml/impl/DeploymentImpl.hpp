//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_DEPLOYMENTDEPLOYMENTIMPL_HPP
#define UML_DEPLOYMENTDEPLOYMENTIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../Deployment.hpp"

#include "uml/impl/DependencyImpl.hpp"

//*********************************
namespace uml 
{
	class DeploymentImpl : virtual public DependencyImpl, virtual public Deployment 
	{
		public: 
			DeploymentImpl(const DeploymentImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			DeploymentImpl& operator=(DeploymentImpl const&) = delete;

		protected:
			friend class umlFactoryImpl;
			DeploymentImpl();
			virtual std::shared_ptr<Deployment> getThisDeploymentPtr() const;
			virtual void setThisDeploymentPtr(std::weak_ptr<Deployment> thisDeploymentPtr);

			//Additional constructors for the containments back reference
			DeploymentImpl(std::weak_ptr<uml::DeploymentTarget > par_location);


			//Additional constructors for the containments back reference
			DeploymentImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			DeploymentImpl(std::weak_ptr<uml::Element > par_owner);


			//Additional constructors for the containments back reference
			DeploymentImpl(std::weak_ptr<uml::Package > par_owningPackage);


			//Additional constructors for the containments back reference
			DeploymentImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter);




		public:
			//destructor
			virtual ~DeploymentImpl();
			
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
			The specification of properties that parameterize the deployment and execution of one or more Artifacts.
			<p>From package UML::Deployments.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::DeploymentSpecification, uml::Element>> getConfiguration() const ;
			
			
			/*!
			The Artifacts that are deployed onto a Node. This association specializes the supplier association.
			<p>From package UML::Deployments.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::DeployedArtifact, uml::NamedElement /*Subset does not reference a union*/>> getDeployedArtifact() const ;
			
			
			/*!
			The DeployedTarget which is the target of a Deployment.
			<p>From package UML::Deployments.</p>
			*/
			
			virtual std::weak_ptr<uml::DeploymentTarget > getLocation() const ;
			
			/*!
			The DeployedTarget which is the target of a Deployment.
			<p>From package UML::Deployments.</p>
			*/
			
			virtual void setLocation(std::shared_ptr<uml::DeploymentTarget> _location) ;
			
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace > getNamespace() const ;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element > getOwner() const ;/*!
			Specifies the elements related by the Relationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getRelatedElement() const ;/*!
			Specifies the source Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getSource() const ;/*!
			Specifies the target Element(s) of the DirectedRelationship.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> getTarget() const ; 
			 
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
			std::weak_ptr<Deployment> m_thisDeploymentPtr;
	};
}
#endif /* end of include guard: UML_DEPLOYMENTDEPLOYMENTIMPL_HPP */
