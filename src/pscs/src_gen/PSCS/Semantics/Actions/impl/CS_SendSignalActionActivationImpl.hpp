//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_ACTIONS_CS_SENDSIGNALACTIONACTIVATIONCS_SENDSIGNALACTIONACTIVATIONIMPL_HPP
#define PSCS_SEMANTICS_ACTIONS_CS_SENDSIGNALACTIONACTIVATIONCS_SENDSIGNALACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "pscs/pscs.hpp" 

// model includes
#include "../CS_SendSignalActionActivation.hpp"

#include "PSCS/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/SendSignalActionActivationImpl.hpp"

//*********************************
namespace PSCS::Semantics::Actions 
{
	class PSCS_API CS_SendSignalActionActivationImpl : virtual public fUML::Semantics::Actions::SendSignalActionActivationImpl, virtual public CS_SendSignalActionActivation 
	{
		public: 
			CS_SendSignalActionActivationImpl(const CS_SendSignalActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CS_SendSignalActionActivationImpl& operator=(CS_SendSignalActionActivationImpl const&); 

		protected:
			friend class PSCS::Semantics::Actions::ActionsFactoryImpl;
			CS_SendSignalActionActivationImpl();
			virtual std::shared_ptr<CS_SendSignalActionActivation> getThisCS_SendSignalActionActivationPtr() const;
			virtual void setThisCS_SendSignalActionActivationPtr(std::weak_ptr<CS_SendSignalActionActivation> thisCS_SendSignalActionActivationPtr);

			//Additional constructors for the containments back reference
			CS_SendSignalActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~CS_SendSignalActionActivationImpl();
			
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
			std::weak_ptr<CS_SendSignalActionActivation> m_thisCS_SendSignalActionActivationPtr;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_ACTIONS_CS_SENDSIGNALACTIONACTIVATIONCS_SENDSIGNALACTIONACTIVATIONIMPL_HPP */
