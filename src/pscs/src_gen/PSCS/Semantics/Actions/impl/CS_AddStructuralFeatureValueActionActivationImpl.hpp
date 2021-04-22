//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_ACTIONS_CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATIONCS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATIONIMPL_HPP
#define PSCS_SEMANTICS_ACTIONS_CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATIONCS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../CS_AddStructuralFeatureValueActionActivation.hpp"

#include "PSCS/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/AddStructuralFeatureValueActionActivationImpl.hpp"

//*********************************
namespace PSCS::Semantics::Actions 
{
	class CS_AddStructuralFeatureValueActionActivationImpl : virtual public fUML::Semantics::Actions::AddStructuralFeatureValueActionActivationImpl, virtual public CS_AddStructuralFeatureValueActionActivation 
	{
		public: 
			CS_AddStructuralFeatureValueActionActivationImpl(const CS_AddStructuralFeatureValueActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CS_AddStructuralFeatureValueActionActivationImpl& operator=(CS_AddStructuralFeatureValueActionActivationImpl const&); 

		protected:
			friend class PSCS::Semantics::Actions::ActionsFactoryImpl;
			CS_AddStructuralFeatureValueActionActivationImpl();
			virtual std::shared_ptr<CS_AddStructuralFeatureValueActionActivation> getThisCS_AddStructuralFeatureValueActionActivationPtr() const;
			virtual void setThisCS_AddStructuralFeatureValueActionActivationPtr(std::weak_ptr<CS_AddStructuralFeatureValueActionActivation> thisCS_AddStructuralFeatureValueActionActivationPtr);

			//Additional constructors for the containments back reference
			CS_AddStructuralFeatureValueActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~CS_AddStructuralFeatureValueActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual void doAction() ; 
			virtual void doActionDefault() ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			
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
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<CS_AddStructuralFeatureValueActionActivation> m_thisCS_AddStructuralFeatureValueActionActivationPtr;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_ACTIONS_CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATIONCS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATIONIMPL_HPP */
