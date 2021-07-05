//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIESFACTORY_HPP
#define FUML_SEMANTICS_ACTIVITIESFACTORY_HPP

#include <map>
#include <memory>

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/EFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"

namespace fUML::Semantics::Actions 
{
	class StructuredActivityNodeActivation;
}
namespace fUML::Semantics::Activities 
{
	class ActivityExecution;
	class ActivityNodeActivationGroup;
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
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> createActivityEdgeInstance_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActivitiesPackage::ACTIVITYEDGEINSTANCE_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> createActivityExecution(const int metaElementID = ActivitiesPackage::ACTIVITYEXECUTION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityFinalNodeActivation> createActivityFinalNodeActivation(const int metaElementID = ActivitiesPackage::ACTIVITYFINALNODEACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityFinalNodeActivation> createActivityFinalNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActivitiesPackage::ACTIVITYFINALNODEACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> createActivityNodeActivationGroup(const int metaElementID = ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> createActivityNodeActivationGroup_in_ActivityExecution(std::weak_ptr<fUML::Semantics::Activities::ActivityExecution> par_activityExecution, const int metaElementID = ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> createActivityNodeActivationGroup_in_ContainingNodeActivation(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> par_containingNodeActivation, const int metaElementID = ActivitiesPackage::ACTIVITYNODEACTIVATIONGROUP_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivation> createActivityParameterNodeActivation(const int metaElementID = ActivitiesPackage::ACTIVITYPARAMETERNODEACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityParameterNodeActivation> createActivityParameterNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActivitiesPackage::ACTIVITYPARAMETERNODEACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::CentralBufferNodeActivation> createCentralBufferNodeActivation(const int metaElementID = ActivitiesPackage::CENTRALBUFFERNODEACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::CentralBufferNodeActivation> createCentralBufferNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActivitiesPackage::CENTRALBUFFERNODEACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ClassifierBehaviorExecutionActivity> createClassifierBehaviorExecutionActivity(const int metaElementID = ActivitiesPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1> createClassifierBehaviorExecutionActivity_OwnedBehaviorActivity1(const int metaElementID = ActivitiesPackage::CLASSIFIERBEHAVIOREXECUTIONACTIVITY_OWNEDBEHAVIORACTIVITY1_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ControlToken> createControlToken(const int metaElementID = ActivitiesPackage::CONTROLTOKEN_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::DataStoreNodeActivation> createDataStoreNodeActivation(const int metaElementID = ActivitiesPackage::DATASTORENODEACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::DataStoreNodeActivation> createDataStoreNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActivitiesPackage::DATASTORENODEACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivation> createDecisionNodeActivation(const int metaElementID = ActivitiesPackage::DECISIONNODEACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::DecisionNodeActivation> createDecisionNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActivitiesPackage::DECISIONNODEACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup> createExpansionActivationGroup(const int metaElementID = ActivitiesPackage::EXPANSIONACTIVATIONGROUP_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup> createExpansionActivationGroup_in_ActivityExecution(std::weak_ptr<fUML::Semantics::Activities::ActivityExecution> par_activityExecution, const int metaElementID = ActivitiesPackage::EXPANSIONACTIVATIONGROUP_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionActivationGroup> createExpansionActivationGroup_in_ContainingNodeActivation(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> par_containingNodeActivation, const int metaElementID = ActivitiesPackage::EXPANSIONACTIVATIONGROUP_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> createExpansionNodeActivation(const int metaElementID = ActivitiesPackage::EXPANSIONNODEACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionNodeActivation> createExpansionNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActivitiesPackage::EXPANSIONNODEACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation> createExpansionRegionActivation(const int metaElementID = ActivitiesPackage::EXPANSIONREGIONACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::ExpansionRegionActivation> createExpansionRegionActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActivitiesPackage::EXPANSIONREGIONACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::FlowFinalNodeActivation> createFlowFinalNodeActivation(const int metaElementID = ActivitiesPackage::FLOWFINALNODEACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::FlowFinalNodeActivation> createFlowFinalNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActivitiesPackage::FLOWFINALNODEACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ForkNodeActivation> createForkNodeActivation(const int metaElementID = ActivitiesPackage::FORKNODEACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::ForkNodeActivation> createForkNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActivitiesPackage::FORKNODEACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ForkedToken> createForkedToken(const int metaElementID = ActivitiesPackage::FORKEDTOKEN_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::InitialNodeActivation> createInitialNodeActivation(const int metaElementID = ActivitiesPackage::INITIALNODEACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::InitialNodeActivation> createInitialNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActivitiesPackage::INITIALNODEACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::JoinNodeActivation> createJoinNodeActivation(const int metaElementID = ActivitiesPackage::JOINNODEACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::JoinNodeActivation> createJoinNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActivitiesPackage::JOINNODEACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::MergeNodeActivation> createMergeNodeActivation(const int metaElementID = ActivitiesPackage::MERGENODEACTIVATION_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<fUML::Semantics::Activities::MergeNodeActivation> createMergeNodeActivation_in_Group(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group, const int metaElementID = ActivitiesPackage::MERGENODEACTIVATION_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::ObjectToken> createObjectToken(const int metaElementID = ActivitiesPackage::OBJECTTOKEN_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::Offer> createOffer(const int metaElementID = ActivitiesPackage::OFFER_CLASS) const = 0;
			
			virtual std::shared_ptr<fUML::Semantics::Activities::TokenSet> createTokenSet(const int metaElementID = ActivitiesPackage::TOKENSET_CLASS) const = 0;
			
			
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIESFACTORY_HPP */
