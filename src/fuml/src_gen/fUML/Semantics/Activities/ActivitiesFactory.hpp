//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIESFACTORY_HPP
#define FUML_SEMANTICS_ACTIVITIESFACTORY_HPP
// namespace macro header include
#include "fUML/fUML.hpp"

#include <map>
#include <memory>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"

namespace fUML::Semantics::Actions
{
	class CallActionActivation;
	class StructuredActivityNodeActivation;
}
namespace fUML::Semantics::CommonBehavior
{
	class ParameterValue;
}
namespace fUML::Semantics::Loci
{
	class Locus;
}
namespace fUML::Semantics::SimpleClassifiers
{
	class FeatureValue;
}



namespace fUML::Semantics::Activities 
{
	class FUML_API ActivitiesFactory : virtual public ecore::EFactory 
	{
		private:    
			ActivitiesFactory(ActivitiesFactory const&) = delete;
			ActivitiesFactory& operator=(ActivitiesFactory const&) = delete;
		protected:
			ActivitiesFactory(){}
		
			//Singleton Instance and Getter
			private:
				static std::shared_ptr<ActivitiesFactory> instance;
			public:
				static std::shared_ptr<ActivitiesFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> createActivityEdgeInstance(const int metaElementID = ActivitiesPackage::ACTIVITYEDGEINSTANCE_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> createActivityEdgeInstance_as_edgeInstances_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActivitiesPackage::ACTIVITYEDGEINSTANCE_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> createActivityExecution(const int metaElementID = ActivitiesPackage::ACTIVITYEXECUTION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> createActivityExecution_as_callExecutions_in_CallActionActivation(std::shared_ptr<fUML::Semantics::Actions::CallActionActivation> par_CallActionActivation, const int metaElementID = ActivitiesPackage::ACTIVITYEXECUTION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> createActivityExecution_as_decisionInputExecution_in_DecisionNodeActivation(std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivation> par_DecisionNodeActivation, const int metaElementID = ActivitiesPackage::ACTIVITYEXECUTION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> createActivityExecution_as_extensionalValues_in_Locus(std::shared_ptr<fUML::Semantics::Loci::Locus> par_Locus, const int metaElementID = ActivitiesPackage::ACTIVITYEXECUTION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> createActivityExecution_as_value_in_ObjectToken(std::shared_ptr<fUML::Semantics::Activities::ObjectToken> par_ObjectToken, const int metaElementID = ActivitiesPackage::ACTIVITYEXECUTION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> createActivityExecution_as_values_in_FeatureValue(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> par_FeatureValue, const int metaElementID = ActivitiesPackage::ACTIVITYEXECUTION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> createActivityExecution_as_values_in_ParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> par_ParameterValue, const int metaElementID = ActivitiesPackage::ACTIVITYEXECUTION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityFinalNodeActivation> createActivityFinalNodeActivation(const int metaElementID = ActivitiesPackage::ACTIVITYFINALNODEACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityFinalNodeActivation> createActivityFinalNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActivitiesPackage::ACTIVITYFINALNODEACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> createActivityNodeActivationGroup(const int metaElementID = ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> createActivityNodeActivationGroup_as_activationGroup_in_StructuredActivityNodeActivation(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> par_StructuredActivityNodeActivation, const int metaElementID = ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> createActivityNodeActivationGroup_as_activationGroup_in_ActivityExecution(std::weak_ptr<fUML::Semantics::Activities::ActivityExecution> par_ActivityExecution, const int metaElementID = ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivation> createActivityParameterNodeActivation(const int metaElementID = ActivitiesPackage::ACTIVITYPARAMETERNODEACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivation> createActivityParameterNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActivitiesPackage::ACTIVITYPARAMETERNODEACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::CentralBufferNodeActivation> createCentralBufferNodeActivation(const int metaElementID = ActivitiesPackage::CENTRALBUFFERNODEACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Activities::CentralBufferNodeActivation> createCentralBufferNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActivitiesPackage::CENTRALBUFFERNODEACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ClassifierBehaviorExecutionActivity> createClassifierBehaviorExecutionActivity(const int metaElementID = ActivitiesPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1> createClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1(const int metaElementID = ActivitiesPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY_OWNEDBEHAVIORACTIVITY1_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ControlToken> createControlToken(const int metaElementID = ActivitiesPackage::CONTROLTOKEN_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Activities::ControlToken> createControlToken_as_heldTokens_in_ActivityNodeActivation(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> par_ActivityNodeActivation, const int metaElementID = ActivitiesPackage::CONTROLTOKEN_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::DataStoreNodeActivation> createDataStoreNodeActivation(const int metaElementID = ActivitiesPackage::DATASTORENODEACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Activities::DataStoreNodeActivation> createDataStoreNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActivitiesPackage::DATASTORENODEACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivation> createDecisionNodeActivation(const int metaElementID = ActivitiesPackage::DECISIONNODEACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivation> createDecisionNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActivitiesPackage::DECISIONNODEACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup> createExpansionActivationGroup(const int metaElementID = ActivitiesPackage::EXPANSIONACTIVATIONGROUP_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup> createExpansionActivationGroup_as_activationGroup_in_StructuredActivityNodeActivation(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> par_StructuredActivityNodeActivation, const int metaElementID = ActivitiesPackage::EXPANSIONACTIVATIONGROUP_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup> createExpansionActivationGroup_as_activationGroup_in_ActivityExecution(std::weak_ptr<fUML::Semantics::Activities::ActivityExecution> par_ActivityExecution, const int metaElementID = ActivitiesPackage::EXPANSIONACTIVATIONGROUP_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> createExpansionNodeActivation(const int metaElementID = ActivitiesPackage::EXPANSIONNODEACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> createExpansionNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActivitiesPackage::EXPANSIONNODEACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation> createExpansionRegionActivation(const int metaElementID = ActivitiesPackage::EXPANSIONREGIONACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation> createExpansionRegionActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActivitiesPackage::EXPANSIONREGIONACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::FlowFinalNodeActivation> createFlowFinalNodeActivation(const int metaElementID = ActivitiesPackage::FLOWFINALNODEACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Activities::FlowFinalNodeActivation> createFlowFinalNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActivitiesPackage::FLOWFINALNODEACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ForkNodeActivation> createForkNodeActivation(const int metaElementID = ActivitiesPackage::FORKNODEACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Activities::ForkNodeActivation> createForkNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActivitiesPackage::FORKNODEACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ForkedToken> createForkedToken(const int metaElementID = ActivitiesPackage::FORKEDTOKEN_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Activities::ForkedToken> createForkedToken_as_heldTokens_in_ActivityNodeActivation(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> par_ActivityNodeActivation, const int metaElementID = ActivitiesPackage::FORKEDTOKEN_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::InitialNodeActivation> createInitialNodeActivation(const int metaElementID = ActivitiesPackage::INITIALNODEACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Activities::InitialNodeActivation> createInitialNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActivitiesPackage::INITIALNODEACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::JoinNodeActivation> createJoinNodeActivation(const int metaElementID = ActivitiesPackage::JOINNODEACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Activities::JoinNodeActivation> createJoinNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActivitiesPackage::JOINNODEACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::MergeNodeActivation> createMergeNodeActivation(const int metaElementID = ActivitiesPackage::MERGENODEACTIVATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Activities::MergeNodeActivation> createMergeNodeActivation_as_nodeActivations_in_ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_ActivityNodeActivationGroup, const int metaElementID = ActivitiesPackage::MERGENODEACTIVATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ObjectToken> createObjectToken(const int metaElementID = ActivitiesPackage::OBJECTTOKEN_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<fUML::Semantics::Activities::ObjectToken> createObjectToken_as_heldTokens_in_ActivityNodeActivation(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation> par_ActivityNodeActivation, const int metaElementID = ActivitiesPackage::OBJECTTOKEN_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::Offer> createOffer(const int metaElementID = ActivitiesPackage::OFFER_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::TokenSet> createTokenSet(const int metaElementID = ActivitiesPackage::TOKENSET_CLASS) const = 0;
			
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIESFACTORY_HPP */
