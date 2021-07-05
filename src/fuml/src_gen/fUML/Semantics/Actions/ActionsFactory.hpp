//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONSFACTORY_HPP
#define FUML_SEMANTICS_ACTIONSFACTORY_HPP

#include <map>
#include <memory>

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/EFactory.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"

namespace fUML::Semantics::Activities 
{
	class ActivityNodeActivationGroup;
}



namespace fUML::Semantics::Actions 
{
	class FUML_API ActionsFactory : virtual public ecore::EFactory 
	{
		private:    
			ActionsFactory(ActionsFactory const&) = delete;
			ActionsFactory& operator=(ActionsFactory const&) = delete;
		protected:
			ActionsFactory(){}
		
			//Singleton Instance and Getter
			private:
				static std::shared_ptr<ActionsFactory> instance;
			public:
				static std::shared_ptr<ActionsFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			virtual std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivation> createAcceptCallActionActivation(const int metaElementID = ActionsPackage::ACCEPTCALLACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivation> createAcceptCallActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::ACCEPTCALLACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivations> createAcceptCallActionActivations(const int metaElementID = ActionsPackage::ACCEPTCALLACTIONACTIVATIONS_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> createAcceptEventActionActivation(const int metaElementID = ActionsPackage::ACCEPTEVENTACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> createAcceptEventActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::ACCEPTEVENTACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepter> createAcceptEventActionEventAccepter(const int metaElementID = ActionsPackage::ACCEPTEVENTACTIONEVENTACCEPTER_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation> createAddStructuralFeatureValueActionActivation(const int metaElementID = ActionsPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation> createAddStructuralFeatureValueActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation> createCallBehaviorActionActivation(const int metaElementID = ActionsPackage::CALLBEHAVIORACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation> createCallBehaviorActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::CALLBEHAVIORACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation> createCallOperationActionActivation(const int metaElementID = ActionsPackage::CALLOPERATIONACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation> createCallOperationActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::CALLOPERATIONACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ClauseActivation> createClauseActivation(const int metaElementID = ActionsPackage::CLAUSEACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ClearAssociationActionActivation> createClearAssociationActionActivation(const int metaElementID = ActionsPackage::CLEARASSOCIATIONACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ClearAssociationActionActivation> createClearAssociationActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::CLEARASSOCIATIONACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation> createClearStructuralFeatureActionActivation(const int metaElementID = ActionsPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation> createClearStructuralFeatureActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation> createConditionalNodeActivation(const int metaElementID = ActionsPackage::CONDITIONALNODEACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation> createConditionalNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::CONDITIONALNODEACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::CreateLinkActionActivation> createCreateLinkActionActivation(const int metaElementID = ActionsPackage::CREATELINKACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::CreateLinkActionActivation> createCreateLinkActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::CREATELINKACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation> createCreateObjectActionActivation(const int metaElementID = ActionsPackage::CREATEOBJECTACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation> createCreateObjectActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::CREATEOBJECTACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivation> createDestroyLinkActionActivation(const int metaElementID = ActionsPackage::DESTROYLINKACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivation> createDestroyLinkActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::DESTROYLINKACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation> createDestroyObjectActionActivation(const int metaElementID = ActionsPackage::DESTROYOBJECTACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation> createDestroyObjectActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::DESTROYOBJECTACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> createInputPinActivation(const int metaElementID = ActionsPackage::INPUTPINACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> createInputPinActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::INPUTPINACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivation> createLoopNodeActivation(const int metaElementID = ActionsPackage::LOOPNODEACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivation> createLoopNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::LOOPNODEACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> createOutputPinActivation(const int metaElementID = ActionsPackage::OUTPUTPINACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> createOutputPinActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::OUTPUTPINACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadExtentActionActivation> createReadExtentActionActivation(const int metaElementID = ActionsPackage::READEXTENTACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadExtentActionActivation> createReadExtentActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::READEXTENTACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation> createReadIsClassifiedObjectActionActivation(const int metaElementID = ActionsPackage::READISCLASSIFIEDOBJECTACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation> createReadIsClassifiedObjectActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::READISCLASSIFIEDOBJECTACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadLinkActionActivation> createReadLinkActionActivation(const int metaElementID = ActionsPackage::READLINKACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadLinkActionActivation> createReadLinkActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::READLINKACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> createReadSelfActionActivation(const int metaElementID = ActionsPackage::READSELFACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> createReadSelfActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::READSELFACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation> createReadStructuralFeatureActionActivation(const int metaElementID = ActionsPackage::READSTRUCTURALFEATUREACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation> createReadStructuralFeatureActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::READSTRUCTURALFEATUREACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ReclassifyObjectActionActivation> createReclassifyObjectActionActivation(const int metaElementID = ActionsPackage::RECLASSIFYOBJECTACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReclassifyObjectActionActivation> createReclassifyObjectActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::RECLASSIFYOBJECTACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ReduceActionActivation> createReduceActionActivation(const int metaElementID = ActionsPackage::REDUCEACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReduceActionActivation> createReduceActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::REDUCEACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation> createRemoveStructuralFeatureValueActivation(const int metaElementID = ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation> createRemoveStructuralFeatureValueActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ReplyActionActivation> createReplyActionActivation(const int metaElementID = ActionsPackage::REPLYACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReplyActionActivation> createReplyActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::REPLYACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ReturnInformation> createReturnInformation(const int metaElementID = ActionsPackage::RETURNINFORMATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::SendSignalActionActivation> createSendSignalActionActivation(const int metaElementID = ActionsPackage::SENDSIGNALACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::SendSignalActionActivation> createSendSignalActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::SENDSIGNALACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::StartClassifierBehaviorActionActivation> createStartClassifierBehaviorActionActivation(const int metaElementID = ActionsPackage::STARTCLASSIFIERBEHAVIORACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::StartClassifierBehaviorActionActivation> createStartClassifierBehaviorActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::STARTCLASSIFIERBEHAVIORACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::StartObjectBehaviorActionActivation> createStartObjectBehaviorActionActivation(const int metaElementID = ActionsPackage::STARTOBJECTBEHAVIORACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::StartObjectBehaviorActionActivation> createStartObjectBehaviorActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::STARTOBJECTBEHAVIORACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> createStructuredActivityNodeActivation(const int metaElementID = ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> createStructuredActivityNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::TestIdentityActionActivation> createTestIdentityActionActivation(const int metaElementID = ActionsPackage::TESTIDENTITYACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::TestIdentityActionActivation> createTestIdentityActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::TESTIDENTITYACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation> createValueSpecificationActionActivation(const int metaElementID = ActionsPackage::VALUESPECIFICATIONACTIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation> createValueSpecificationActionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActionsPackage::VALUESPECIFICATIONACTIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Actions::Values> createValues(const int metaElementID = ActionsPackage::VALUES_CLASS) const = 0;
			
			
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONSFACTORY_HPP */
