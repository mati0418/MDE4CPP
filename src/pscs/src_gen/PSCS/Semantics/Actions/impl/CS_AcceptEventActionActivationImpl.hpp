//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_ACTIONS_CS_ACCEPTEVENTACTIONACTIVATIONCS_ACCEPTEVENTACTIONACTIVATIONIMPL_HPP
#define PSCS_SEMANTICS_ACTIONS_CS_ACCEPTEVENTACTIONACTIVATIONCS_ACCEPTEVENTACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../CS_AcceptEventActionActivation.hpp"

#include "PSCS/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/AcceptEventActionActivationImpl.hpp"

//*********************************
namespace PSCS::Semantics::Actions 
{
	class CS_AcceptEventActionActivationImpl : virtual public fUML::Semantics::Actions::AcceptEventActionActivationImpl, virtual public CS_AcceptEventActionActivation 
	{
		public: 
			CS_AcceptEventActionActivationImpl(const CS_AcceptEventActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CS_AcceptEventActionActivationImpl& operator=(CS_AcceptEventActionActivationImpl const&); 

		protected:
			friend class PSCS::Semantics::Actions::ActionsFactoryImpl;
			CS_AcceptEventActionActivationImpl();
			virtual std::shared_ptr<CS_AcceptEventActionActivation> getThisCS_AcceptEventActionActivationPtr() const;
			virtual void setThisCS_AcceptEventActionActivationPtr(std::weak_ptr<CS_AcceptEventActionActivation> thisCS_AcceptEventActionActivationPtr);

			//Additional constructors for the containments back reference
			CS_AcceptEventActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~CS_AcceptEventActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual void accept(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence) ;
			
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
			std::weak_ptr<CS_AcceptEventActionActivation> m_thisCS_AcceptEventActionActivationPtr;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_ACTIONS_CS_ACCEPTEVENTACTIONACTIVATIONCS_ACCEPTEVENTACTIONACTIVATIONIMPL_HPP */
