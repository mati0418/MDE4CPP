//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONSFACTORY_HPP
#define FUML_SEMANTICS_ACTIONSFACTORY_HPP
// namespace macro header include
#include "fUML/fUML.hpp"

#include <map>
#include <memory>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EFactory.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"

namespace fUML::Semantics::Activities
{
	class ActivityNodeActivationGroup;
	class ObjectToken;
}
namespace fUML::Semantics::CommonBehavior
{
	class ParameterValue;
}
namespace fUML::Semantics::SimpleClassifiers
{
	class FeatureValue;
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
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivation> createAcceptCallActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::ACCEPTCALLACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::AcceptCallActionActivations> createAcceptCallActionActivations(const int metaElementID = ActionsPackage::ACCEPTCALLACTIONACTIVATIONS_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> createAcceptEventActionActivation(const int metaElementID = ActionsPackage::ACCEPTEVENTACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> createAcceptEventActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::ACCEPTEVENTACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepter> createAcceptEventActionEventAccepter(const int metaElementID = ActionsPackage::ACCEPTEVENTACTIONEVENTACCEPTER_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation> createAddStructuralFeatureValueActionActivation(const int metaElementID = ActionsPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::AddStructuralFeatureValueActionActivation> createAddStructuralFeatureValueActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::ADDSTRUCTURALFEATUREVALUEACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation> createCallBehaviorActionActivation(const int metaElementID = ActionsPackage::CALLBEHAVIORACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::CallBehaviorActionActivation> createCallBehaviorActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::CALLBEHAVIORACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation> createCallOperationActionActivation(const int metaElementID = ActionsPackage::CALLOPERATIONACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::CallOperationActionActivation> createCallOperationActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::CALLOPERATIONACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::ClauseActivation> createClauseActivation(const int metaElementID = ActionsPackage::CLAUSEACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::ClauseActivation> createClauseActivation_as_clauseActivations_in_ConditionalNodeActivation(std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation> par_ConditionalNodeActivation, const int metaElementID = ActionsPackage::CLAUSEACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::ClearAssociationActionActivation> createClearAssociationActionActivation(const int metaElementID = ActionsPackage::CLEARASSOCIATIONACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::ClearAssociationActionActivation> createClearAssociationActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::CLEARASSOCIATIONACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation> createClearStructuralFeatureActionActivation(const int metaElementID = ActionsPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::ClearStructuralFeatureActionActivation> createClearStructuralFeatureActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::CLEARSTRUCTURALFEATUREACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation> createConditionalNodeActivation(const int metaElementID = ActionsPackage::CONDITIONALNODEACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::ConditionalNodeActivation> createConditionalNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::CONDITIONALNODEACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::CreateLinkActionActivation> createCreateLinkActionActivation(const int metaElementID = ActionsPackage::CREATELINKACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::CreateLinkActionActivation> createCreateLinkActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::CREATELINKACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation> createCreateObjectActionActivation(const int metaElementID = ActionsPackage::CREATEOBJECTACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::CreateObjectActionActivation> createCreateObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::CREATEOBJECTACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivation> createDestroyLinkActionActivation(const int metaElementID = ActionsPackage::DESTROYLINKACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::DestroyLinkActionActivation> createDestroyLinkActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::DESTROYLINKACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation> createDestroyObjectActionActivation(const int metaElementID = ActionsPackage::DESTROYOBJECTACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::DestroyObjectActionActivation> createDestroyObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::DESTROYOBJECTACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> createInputPinActivation(const int metaElementID = ActionsPackage::INPUTPINACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> createInputPinActivation_as_inputPinActivation_in_ActionActivation(std::shared_ptr<fUML::Semantics::Actions::ActionActivation> par_ActionActivation, const int metaElementID = ActionsPackage::INPUTPINACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::InputPinActivation> createInputPinActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::INPUTPINACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivation> createLoopNodeActivation(const int metaElementID = ActionsPackage::LOOPNODEACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivation> createLoopNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::LOOPNODEACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> createOutputPinActivation(const int metaElementID = ActionsPackage::OUTPUTPINACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> createOutputPinActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::OUTPUTPINACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::OutputPinActivation> createOutputPinActivation_as_outputPinActivation_in_ActionActivation(std::shared_ptr<fUML::Semantics::Actions::ActionActivation> par_ActionActivation, const int metaElementID = ActionsPackage::OUTPUTPINACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadExtentActionActivation> createReadExtentActionActivation(const int metaElementID = ActionsPackage::READEXTENTACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadExtentActionActivation> createReadExtentActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::READEXTENTACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation> createReadIsClassifiedObjectActionActivation(const int metaElementID = ActionsPackage::READISCLASSIFIEDOBJECTACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadIsClassifiedObjectActionActivation> createReadIsClassifiedObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::READISCLASSIFIEDOBJECTACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadLinkActionActivation> createReadLinkActionActivation(const int metaElementID = ActionsPackage::READLINKACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadLinkActionActivation> createReadLinkActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::READLINKACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> createReadSelfActionActivation(const int metaElementID = ActionsPackage::READSELFACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadSelfActionActivation> createReadSelfActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::READSELFACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation> createReadStructuralFeatureActionActivation(const int metaElementID = ActionsPackage::READSTRUCTURALFEATUREACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReadStructuralFeatureActionActivation> createReadStructuralFeatureActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::READSTRUCTURALFEATUREACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::ReclassifyObjectActionActivation> createReclassifyObjectActionActivation(const int metaElementID = ActionsPackage::RECLASSIFYOBJECTACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReclassifyObjectActionActivation> createReclassifyObjectActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::RECLASSIFYOBJECTACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::ReduceActionActivation> createReduceActionActivation(const int metaElementID = ActionsPackage::REDUCEACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReduceActionActivation> createReduceActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::REDUCEACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation> createRemoveStructuralFeatureValueActivation(const int metaElementID = ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::RemoveStructuralFeatureValueActivation> createRemoveStructuralFeatureValueActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::REMOVESTRUCTURALFEATUREVALUEACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::ReplyActionActivation> createReplyActionActivation(const int metaElementID = ActionsPackage::REPLYACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReplyActionActivation> createReplyActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::REPLYACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::ReturnInformation> createReturnInformation(const int metaElementID = ActionsPackage::RETURNINFORMATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::ReturnInformation> createReturnInformation_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID = ActionsPackage::RETURNINFORMATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::ReturnInformation> createReturnInformation_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID = ActionsPackage::RETURNINFORMATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::ReturnInformation> createReturnInformation_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID = ActionsPackage::RETURNINFORMATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::SendSignalActionActivation> createSendSignalActionActivation(const int metaElementID = ActionsPackage::SENDSIGNALACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::SendSignalActionActivation> createSendSignalActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::SENDSIGNALACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::StartClassifierBehaviorActionActivation> createStartClassifierBehaviorActionActivation(const int metaElementID = ActionsPackage::STARTCLASSIFIERBEHAVIORACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::StartClassifierBehaviorActionActivation> createStartClassifierBehaviorActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::STARTCLASSIFIERBEHAVIORACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::StartObjectBehaviorActionActivation> createStartObjectBehaviorActionActivation(const int metaElementID = ActionsPackage::STARTOBJECTBEHAVIORACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::StartObjectBehaviorActionActivation> createStartObjectBehaviorActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::STARTOBJECTBEHAVIORACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> createStructuredActivityNodeActivation(const int metaElementID = ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> createStructuredActivityNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::STRUCTUREDACTIVITYNODEACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::TestIdentityActionActivation> createTestIdentityActionActivation(const int metaElementID = ActionsPackage::TESTIDENTITYACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::TestIdentityActionActivation> createTestIdentityActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::TESTIDENTITYACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation> createValueSpecificationActionActivation(const int metaElementID = ActionsPackage::VALUESPECIFICATIONACTIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::ValueSpecificationActionActivation> createValueSpecificationActionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActionsPackage::VALUESPECIFICATIONACTIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Actions::Values> createValues(const int metaElementID = ActionsPackage::VALUES_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Actions::Values> createValues_as_bodyOutputLists_in_LoopNodeActivation(std::shared_ptr<fUML::Semantics::Actions::LoopNodeActivation> par_LoopNodeActivation, const int metaElementID = ActionsPackage::VALUES_CLASS) const = 0;
			
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONSFACTORY_HPP */
