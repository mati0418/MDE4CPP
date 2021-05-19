//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_CREATEOBJECTACTIONACTIVATIONCREATEOBJECTACTIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_CREATEOBJECTACTIONACTIVATIONCREATEOBJECTACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fuml/fuml.hpp" 

// model includes
#include "../CreateObjectActionActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API CreateObjectActionActivationImpl : virtual public ActionActivationImpl, virtual public CreateObjectActionActivation 
	{
		public: 
			CreateObjectActionActivationImpl(const CreateObjectActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CreateObjectActionActivationImpl& operator=(CreateObjectActionActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			CreateObjectActionActivationImpl();
			virtual std::shared_ptr<CreateObjectActionActivation> getThisCreateObjectActionActivationPtr() const;
			virtual void setThisCreateObjectActionActivationPtr(std::weak_ptr<CreateObjectActionActivation> thisCreateObjectActionActivationPtr);

			//Additional constructors for the containments back reference
			CreateObjectActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~CreateObjectActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual void doAction() ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<uml::CreateObjectAction> getCreateObjectAction() const ;
			
			virtual void setCreateObjectAction(std::shared_ptr<uml::CreateObjectAction>) ;
			/*Additional Setter for 'ActionActivation::action' redefined by reference 'createObjectAction'*/
			
			virtual void setAction(std::shared_ptr<uml::Action>) ;/*Additional Setter for 'ActivityNodeActivation::node' redefined by reference 'createObjectAction'*/
			
			virtual void setNode(std::shared_ptr<uml::ActivityNode>) ;
			
			//*********************************
			// Union Getter
			//*********************************
			
			virtual std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> getPinActivation() const ; 
			 
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
			std::weak_ptr<CreateObjectActionActivation> m_thisCreateObjectActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_CREATEOBJECTACTIONACTIVATIONCREATEOBJECTACTIONACTIVATIONIMPL_HPP */
