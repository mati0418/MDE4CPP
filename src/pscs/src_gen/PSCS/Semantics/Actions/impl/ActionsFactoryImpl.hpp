//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_ACTIONSFACTORYIMPL_HPP
#define PSCS_SEMANTICS_ACTIONSFACTORYIMPL_HPP

// namespace macro header include
#include "pscs/pscs.hpp"

#include "ecore/impl/EFactoryImpl.hpp"

#include "PSCS/Semantics/Actions/ActionsFactory.hpp"

namespace Actions 
{	class CS_AcceptCallActionActivation;
	class CS_AcceptEventActionActivation;
	class CS_AddStructuralFeatureValueActionActivation;
	class CS_CallOperationActionActivation;
	class CS_ClearStructuralFeatureActionActivation;
	class CS_ConstructStrategy;
	class CS_CreateLinkActionActivation;
	class CS_CreateObjectActionActivation;
	class CS_DefaultConstructStrategy;
	class CS_ReadExtentActionActivation;
	class CS_ReadSelfActionActivation;
	class CS_RemoveStructuralFeatureValueActionActivation;
	class CS_SendSignalActionActivation;
}

namespace PSCS::Semantics::Actions 
{
	class PSCS_API ActionsFactoryImpl : virtual public ecore::EFactoryImpl , virtual public ActionsFactory 
	{
		private:    
			ActionsFactoryImpl(ActionsFactoryImpl const&) = delete;
			ActionsFactoryImpl& operator=(ActionsFactoryImpl const&) = delete;

		protected:
			friend class ActionsFactory;
			// Constructor
			ActionsFactoryImpl();

		public:
			virtual ~ActionsFactoryImpl();
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const;

			//Creator functions
			 virtual std::shared_ptr<PSCS::Semantics::Actions::CS_AcceptCallActionActivation> createCS_AcceptCallActionActivation(const int metaElementID = ActionsPackage::CS_ACCEPTCALLACTIONACTIVATION_CLASS) const ;
			 //Add containing object
			 virtual std::shared_ptr<PSCS::Semantics::Actions::CS_AcceptCallActionActivation> createCS_AcceptCallActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::CS_ACCEPTCALLACTIONACTIVATION_CLASS) const ;
			 
			 virtual std::shared_ptr<PSCS::Semantics::Actions::CS_AcceptEventActionActivation> createCS_AcceptEventActionActivation(const int metaElementID = ActionsPackage::CS_ACCEPTEVENTACTIONACTIVATION_CLASS) const ;
			 //Add containing object
			 virtual std::shared_ptr<PSCS::Semantics::Actions::CS_AcceptEventActionActivation> createCS_AcceptEventActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::CS_ACCEPTEVENTACTIONACTIVATION_CLASS) const ;
			 
			 virtual std::shared_ptr<PSCS::Semantics::Actions::CS_AddStructuralFeatureValueActionActivation> createCS_AddStructuralFeatureValueActionActivation(const int metaElementID = ActionsPackage::CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS) const ;
			 //Add containing object
			 virtual std::shared_ptr<PSCS::Semantics::Actions::CS_AddStructuralFeatureValueActionActivation> createCS_AddStructuralFeatureValueActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::CS_ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS) const ;
			 
			 virtual std::shared_ptr<PSCS::Semantics::Actions::CS_CallOperationActionActivation> createCS_CallOperationActionActivation(const int metaElementID = ActionsPackage::CS_CALLOPERATIONACTIONACTIVATION_CLASS) const ;
			 //Add containing object
			 virtual std::shared_ptr<PSCS::Semantics::Actions::CS_CallOperationActionActivation> createCS_CallOperationActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::CS_CALLOPERATIONACTIONACTIVATION_CLASS) const ;
			 
			 virtual std::shared_ptr<PSCS::Semantics::Actions::CS_ClearStructuralFeatureActionActivation> createCS_ClearStructuralFeatureActionActivation(const int metaElementID = ActionsPackage::CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS) const ;
			 //Add containing object
			 virtual std::shared_ptr<PSCS::Semantics::Actions::CS_ClearStructuralFeatureActionActivation> createCS_ClearStructuralFeatureActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::CS_CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS) const ;
			 
			 virtual std::shared_ptr<PSCS::Semantics::Actions::CS_CreateLinkActionActivation> createCS_CreateLinkActionActivation(const int metaElementID = ActionsPackage::CS_CREATELINKACTIONACTIVATION_CLASS) const ;
			 //Add containing object
			 virtual std::shared_ptr<PSCS::Semantics::Actions::CS_CreateLinkActionActivation> createCS_CreateLinkActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::CS_CREATELINKACTIONACTIVATION_CLASS) const ;
			 
			 virtual std::shared_ptr<PSCS::Semantics::Actions::CS_CreateObjectActionActivation> createCS_CreateObjectActionActivation(const int metaElementID = ActionsPackage::CS_CREATEOBJECTACTIONACTIVATION_CLASS) const ;
			 //Add containing object
			 virtual std::shared_ptr<PSCS::Semantics::Actions::CS_CreateObjectActionActivation> createCS_CreateObjectActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::CS_CREATEOBJECTACTIONACTIVATION_CLASS) const ;
			 
			 virtual std::shared_ptr<PSCS::Semantics::Actions::CS_DefaultConstructStrategy> createCS_DefaultConstructStrategy(const int metaElementID = ActionsPackage::CS_DEFAULTCONSTRUCTSTRATEGY_CLASS) const ;
			 
			 virtual std::shared_ptr<PSCS::Semantics::Actions::CS_ReadExtentActionActivation> createCS_ReadExtentActionActivation(const int metaElementID = ActionsPackage::CS_READEXTENTACTIONACTIVATION_CLASS) const ;
			 //Add containing object
			 virtual std::shared_ptr<PSCS::Semantics::Actions::CS_ReadExtentActionActivation> createCS_ReadExtentActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::CS_READEXTENTACTIONACTIVATION_CLASS) const ;
			 
			 virtual std::shared_ptr<PSCS::Semantics::Actions::CS_ReadSelfActionActivation> createCS_ReadSelfActionActivation(const int metaElementID = ActionsPackage::CS_READSELFACTIONACTIVATION_CLASS) const ;
			 //Add containing object
			 virtual std::shared_ptr<PSCS::Semantics::Actions::CS_ReadSelfActionActivation> createCS_ReadSelfActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::CS_READSELFACTIONACTIVATION_CLASS) const ;
			 
			 virtual std::shared_ptr<PSCS::Semantics::Actions::CS_RemoveStructuralFeatureValueActionActivation> createCS_RemoveStructuralFeatureValueActionActivation(const int metaElementID = ActionsPackage::CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS) const ;
			 //Add containing object
			 virtual std::shared_ptr<PSCS::Semantics::Actions::CS_RemoveStructuralFeatureValueActionActivation> createCS_RemoveStructuralFeatureValueActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::CS_REMOVESTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS) const ;
			 
			 virtual std::shared_ptr<PSCS::Semantics::Actions::CS_SendSignalActionActivation> createCS_SendSignalActionActivation(const int metaElementID = ActionsPackage::CS_SENDSIGNALACTIONACTIVATION_CLASS) const ;
			 //Add containing object
			 virtual std::shared_ptr<PSCS::Semantics::Actions::CS_SendSignalActionActivation> createCS_SendSignalActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::CS_SENDSIGNALACTIONACTIVATION_CLASS) const ;
			 
			 

		private:
			static ActionsFactory* create();
            std::map<std::string,int> m_idMap;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_ACTIONSFACTORYIMPL_HPP */
