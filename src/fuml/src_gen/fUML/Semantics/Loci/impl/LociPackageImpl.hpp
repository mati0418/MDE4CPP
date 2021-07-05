//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_LOCIPACKAGEIMPL_HPP
#define FUML_SEMANTICS_LOCIPACKAGEIMPL_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/ecorePackage.hpp"
#include "ecore/impl/EPackageImpl.hpp"

#include "fUML/Semantics/Loci/LociPackage.hpp" 


namespace fUML::Semantics::Loci 
{
	class ChoiceStrategy;
	class ExecutionFactory;
	class Executor;
	class FirstChoiceStrategy;
	class Locus;
	class SemanticStrategy;
	class SemanticVisitor;}

namespace ecore
{
	class ecoreFactory;
}

namespace fUML::Semantics::Loci
{
	class FUML_API LociPackageImpl : public ecore::EPackageImpl ,virtual public LociPackage
	{
		private:    
			LociPackageImpl(LociPackageImpl const&) = delete;
			LociPackageImpl& operator=(LociPackageImpl const&) = delete;

		protected:
			LociPackageImpl();

		public:
			virtual ~LociPackageImpl();

			// Begin Class ChoiceStrategy
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getChoiceStrategy_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getChoiceStrategy_Operation_choose_EInt() const ;
			virtual std::shared_ptr<ecore::EOperation> getChoiceStrategy_Operation_getName() const ;
			
			// End Class ChoiceStrategy

			// Begin Class ExecutionFactory
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getExecutionFactory_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getExecutionFactory_Attribute_builtInTypes() const ;
			virtual std::shared_ptr<ecore::EReference> getExecutionFactory_Attribute_locus() const ;
			virtual std::shared_ptr<ecore::EReference> getExecutionFactory_Attribute_primitiveBehaviorPrototypes() const ;
			virtual std::shared_ptr<ecore::EReference> getExecutionFactory_Attribute_strategies() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_addBuiltInType_PrimitiveType() const ;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution() const ;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_assignStrategy_SemanticStrategy() const ;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_createEvaluation_ValueSpecification() const ;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_createExecution_Behavior_Object() const ;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_getBuiltInType_EString() const ;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_getStrategy_EString() const ;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_getStrategyIndex_EString() const ;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_instantiateOpaqueBehaviorExecution_OpaqueBehavior() const ;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_instantiateOpaqueBehaviorExecution_Behavior() const ;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_instantiateVisitor_Element() const ;
			
			// End Class ExecutionFactory

			// Begin Class Executor
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getExecutor_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getExecutor_Attribute_locus() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getExecutor_Operation_evaluate_ValueSpecification() const ;
			virtual std::shared_ptr<ecore::EOperation> getExecutor_Operation_execute_Behavior_ParameterValue() const ;
			virtual std::shared_ptr<ecore::EOperation> getExecutor_Operation_start_Class_ParameterValue() const ;
			
			// End Class Executor

			// Begin Class FirstChoiceStrategy
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getFirstChoiceStrategy_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getFirstChoiceStrategy_Operation_choose_EInt() const ;
			
			// End Class FirstChoiceStrategy

			// Begin Class Locus
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getLocus_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getLocus_Attribute_executor() const ;
			virtual std::shared_ptr<ecore::EReference> getLocus_Attribute_extensionalValues() const ;
			virtual std::shared_ptr<ecore::EReference> getLocus_Attribute_factory() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getLocus_Operation_add_ExtensionalValue() const ;
			virtual std::shared_ptr<ecore::EOperation> getLocus_Operation_assignExecutor_Executor() const ;
			virtual std::shared_ptr<ecore::EOperation> getLocus_Operation_assignFactory_ExecutionFactory() const ;
			virtual std::shared_ptr<ecore::EOperation> getLocus_Operation_conforms_Classifier_Classifier() const ;
			virtual std::shared_ptr<ecore::EOperation> getLocus_Operation_instantiate_Class() const ;
			virtual std::shared_ptr<ecore::EOperation> getLocus_Operation_remove_ExtensionalValue() const ;
			virtual std::shared_ptr<ecore::EOperation> getLocus_Operation_retrieveExtent_Classifier() const ;
			
			// End Class Locus

			// Begin Class SemanticStrategy
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getSemanticStrategy_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getSemanticStrategy_Operation_getName() const ;
			
			// End Class SemanticStrategy

			// Begin Class SemanticVisitor
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getSemanticVisitor_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getSemanticVisitor_Operation__beginIsolation() const ;
			virtual std::shared_ptr<ecore::EOperation> getSemanticVisitor_Operation__endIsolation() const ;
			
			// End Class SemanticVisitor

			
			// SubPackages Getters
			

		private:
			std::shared_ptr<ecore::EClass> m_choiceStrategy_Class = nullptr;std::shared_ptr<ecore::EClass> m_executionFactory_Class = nullptr;std::shared_ptr<ecore::EClass> m_executor_Class = nullptr;std::shared_ptr<ecore::EClass> m_firstChoiceStrategy_Class = nullptr;std::shared_ptr<ecore::EClass> m_locus_Class = nullptr;std::shared_ptr<ecore::EClass> m_semanticStrategy_Class = nullptr;std::shared_ptr<ecore::EClass> m_semanticVisitor_Class = nullptr;
			
			
			std::shared_ptr<ecore::EReference> m_executionFactory_Attribute_builtInTypes = nullptr;std::shared_ptr<ecore::EReference> m_locus_Attribute_executor = nullptr;std::shared_ptr<ecore::EReference> m_locus_Attribute_extensionalValues = nullptr;std::shared_ptr<ecore::EReference> m_locus_Attribute_factory = nullptr;std::shared_ptr<ecore::EReference> m_executionFactory_Attribute_locus = nullptr;std::shared_ptr<ecore::EReference> m_executor_Attribute_locus = nullptr;std::shared_ptr<ecore::EReference> m_executionFactory_Attribute_primitiveBehaviorPrototypes = nullptr;std::shared_ptr<ecore::EReference> m_executionFactory_Attribute_strategies = nullptr;
			std::shared_ptr<ecore::EOperation> m_semanticVisitor_Operation__beginIsolation = nullptr;std::shared_ptr<ecore::EOperation> m_semanticVisitor_Operation__endIsolation = nullptr;std::shared_ptr<ecore::EOperation> m_locus_Operation_add_ExtensionalValue = nullptr;std::shared_ptr<ecore::EOperation> m_executionFactory_Operation_addBuiltInType_PrimitiveType = nullptr;std::shared_ptr<ecore::EOperation> m_executionFactory_Operation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution = nullptr;std::shared_ptr<ecore::EOperation> m_locus_Operation_assignExecutor_Executor = nullptr;std::shared_ptr<ecore::EOperation> m_locus_Operation_assignFactory_ExecutionFactory = nullptr;std::shared_ptr<ecore::EOperation> m_executionFactory_Operation_assignStrategy_SemanticStrategy = nullptr;std::shared_ptr<ecore::EOperation> m_choiceStrategy_Operation_choose_EInt = nullptr;std::shared_ptr<ecore::EOperation> m_firstChoiceStrategy_Operation_choose_EInt = nullptr;std::shared_ptr<ecore::EOperation> m_locus_Operation_conforms_Classifier_Classifier = nullptr;std::shared_ptr<ecore::EOperation> m_executionFactory_Operation_createEvaluation_ValueSpecification = nullptr;std::shared_ptr<ecore::EOperation> m_executionFactory_Operation_createExecution_Behavior_Object = nullptr;std::shared_ptr<ecore::EOperation> m_executor_Operation_evaluate_ValueSpecification = nullptr;std::shared_ptr<ecore::EOperation> m_executor_Operation_execute_Behavior_ParameterValue = nullptr;std::shared_ptr<ecore::EOperation> m_executionFactory_Operation_getBuiltInType_EString = nullptr;std::shared_ptr<ecore::EOperation> m_choiceStrategy_Operation_getName = nullptr;std::shared_ptr<ecore::EOperation> m_semanticStrategy_Operation_getName = nullptr;std::shared_ptr<ecore::EOperation> m_executionFactory_Operation_getStrategy_EString = nullptr;std::shared_ptr<ecore::EOperation> m_executionFactory_Operation_getStrategyIndex_EString = nullptr;std::shared_ptr<ecore::EOperation> m_locus_Operation_instantiate_Class = nullptr;std::shared_ptr<ecore::EOperation> m_executionFactory_Operation_instantiateOpaqueBehaviorExecution_OpaqueBehavior = nullptr;std::shared_ptr<ecore::EOperation> m_executionFactory_Operation_instantiateOpaqueBehaviorExecution_Behavior = nullptr;std::shared_ptr<ecore::EOperation> m_executionFactory_Operation_instantiateVisitor_Element = nullptr;std::shared_ptr<ecore::EOperation> m_locus_Operation_remove_ExtensionalValue = nullptr;std::shared_ptr<ecore::EOperation> m_locus_Operation_retrieveExtent_Classifier = nullptr;std::shared_ptr<ecore::EOperation> m_executor_Operation_start_Class_ParameterValue = nullptr;

			friend class LociPackage;

			static bool isInited;
			static LociPackage* create();
			bool isInitialized = false;
 			bool isCreated = false;

			virtual void init(std::shared_ptr<ecore::EPackage> package);

		public:
			void createPackageContents(std::shared_ptr<ecore::EPackage> package);
			void initializePackageContents();

		private:
			void createChoiceStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createExecutionFactoryContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createExecutorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createFirstChoiceStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createLocusContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createSemanticStrategyContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createSemanticVisitorContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);

			void initializeChoiceStrategyContent();
			void initializeExecutionFactoryContent();
			void initializeExecutorContent();
			void initializeFirstChoiceStrategyContent();
			void initializeLocusContent();
			void initializeSemanticStrategyContent();
			void initializeSemanticVisitorContent();
			void initializePackageEDataTypes();



	};
}
#endif /* end of include guard: FUML_SEMANTICS_LOCIPACKAGEIMPL_HPP */
