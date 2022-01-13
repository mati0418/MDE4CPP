//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_LOCIPACKAGE_HPP
#define FUML_SEMANTICS_LOCIPACKAGE_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EParameter;
	class EOperation;
	class EDataType;
	class EAnnotation;
	class EClass;
	class EReference;
	class EStringToStringMapEntry;
	class EGenericType;
}

namespace fUML::Semantics::Loci 
{
	class ChoiceStrategy;
	class ExecutionFactory;
	class Executor;
	class FirstChoiceStrategy;
	class Locus;
	class SemanticStrategy;
	class SemanticVisitor;
}
 
namespace fUML::Semantics::Loci 
{
	/*!
	The Metamodel Package for the Loci metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class FUML_API LociPackage : virtual public ecore::EPackage 
	{
		private:    
			LociPackage(LociPackage const&) = delete;
			LociPackage& operator=(LociPackage const&) = delete;

		protected:
			LociPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class ChoiceStrategy
			//Class and Feature IDs 
			static const long long CHOICESTRATEGY_CLASS = 645728985;
			static const unsigned int CHOICESTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int CHOICESTRATEGY_CLASS_OPERATION_COUNT = 3;
			
			
			static const int CHOICESTRATEGY_OPERATION_CHOOSE_EINT = 1273166866;
			static const int CHOICESTRATEGY_OPERATION_GETNAME = 1727304580;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getChoiceStrategy_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getChoiceStrategy_Operation_choose_EInt() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getChoiceStrategy_Operation_getName() const = 0;
			
			// End Class ChoiceStrategy


			// Begin Class ExecutionFactory
			//Class and Feature IDs 
			static const long long EXECUTIONFACTORY_CLASS = 102788675;
			static const unsigned int EXECUTIONFACTORY_CLASS_FEATURE_COUNT = 4;
			static const unsigned int EXECUTIONFACTORY_CLASS_OPERATION_COUNT = 10;
			
			static const long long EXECUTIONFACTORY_ATTRIBUTE_BUILTINTYPES = 1371486848;
			static const long long EXECUTIONFACTORY_ATTRIBUTE_LOCUS = 648263615;
			static const long long EXECUTIONFACTORY_ATTRIBUTE_PRIMITIVEBEHAVIORPROTOTYPES = 846327382;
			static const long long EXECUTIONFACTORY_ATTRIBUTE_STRATEGIES = 1614243054;
			
			static const int EXECUTIONFACTORY_OPERATION_ADDBUILTINTYPE_PRIMITIVETYPE = 856696871;
			static const int EXECUTIONFACTORY_OPERATION_ADDPRIMITIVEBEHAVIORPROTOTYPE_OPAQUEBEHAVIOREXECUTION = 1007202968;
			static const int EXECUTIONFACTORY_OPERATION_ASSIGNSTRATEGY_SEMANTICSTRATEGY = 1797723207;
			static const int EXECUTIONFACTORY_OPERATION_CREATEEVALUATION_VALUESPECIFICATION = 823281622;
			static const int EXECUTIONFACTORY_OPERATION_CREATEEXECUTION_BEHAVIOR_OBJECT = 490726063;
			static const int EXECUTIONFACTORY_OPERATION_GETBUILTINTYPE_ESTRING = 192630283;
			static const int EXECUTIONFACTORY_OPERATION_GETSTRATEGY_ESTRING = 1451856544;
			static const int EXECUTIONFACTORY_OPERATION_GETSTRATEGYINDEX_ESTRING = 461389125;
			static const int EXECUTIONFACTORY_OPERATION_INSTANTIATEOPAQUEBEHAVIOREXECUTION_BEHAVIOR = 859316560;
			static const int EXECUTIONFACTORY_OPERATION_INSTANTIATEVISITOR_ELEMENT = 1427156490;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getExecutionFactory_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getExecutionFactory_Attribute_builtInTypes() const = 0;
			virtual std::shared_ptr<ecore::EReference> getExecutionFactory_Attribute_locus() const = 0;
			virtual std::shared_ptr<ecore::EReference> getExecutionFactory_Attribute_primitiveBehaviorPrototypes() const = 0;
			virtual std::shared_ptr<ecore::EReference> getExecutionFactory_Attribute_strategies() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_addBuiltInType_PrimitiveType() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_addPrimitiveBehaviorPrototype_OpaqueBehaviorExecution() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_assignStrategy_SemanticStrategy() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_createEvaluation_ValueSpecification() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_createExecution_Behavior_Object() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_getBuiltInType_EString() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_getStrategy_EString() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_getStrategyIndex_EString() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_instantiateOpaqueBehaviorExecution_Behavior() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecutionFactory_Operation_instantiateVisitor_Element() const = 0;
			
			// End Class ExecutionFactory


			// Begin Class Executor
			//Class and Feature IDs 
			static const long long EXECUTOR_CLASS = 1690815834;
			static const unsigned int EXECUTOR_CLASS_FEATURE_COUNT = 1;
			static const unsigned int EXECUTOR_CLASS_OPERATION_COUNT = 3;
			
			static const long long EXECUTOR_ATTRIBUTE_LOCUS = 32912316;
			
			static const int EXECUTOR_OPERATION_EVALUATE_VALUESPECIFICATION = 1244975009;
			static const int EXECUTOR_OPERATION_EXECUTE_BEHAVIOR_PARAMETERVALUE = 531750117;
			static const int EXECUTOR_OPERATION_START_CLASS_PARAMETERVALUE = 204336979;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getExecutor_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getExecutor_Attribute_locus() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getExecutor_Operation_evaluate_ValueSpecification() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecutor_Operation_execute_Behavior_ParameterValue() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getExecutor_Operation_start_Class_ParameterValue() const = 0;
			
			// End Class Executor


			// Begin Class FirstChoiceStrategy
			//Class and Feature IDs 
			static const long long FIRSTCHOICESTRATEGY_CLASS = 1039516550;
			static const unsigned int FIRSTCHOICESTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int FIRSTCHOICESTRATEGY_CLASS_OPERATION_COUNT = 4;
			
			
			static const int FIRSTCHOICESTRATEGY_OPERATION_CHOOSE_EINT = 1148186745;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getFirstChoiceStrategy_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getFirstChoiceStrategy_Operation_choose_EInt() const = 0;
			
			// End Class FirstChoiceStrategy


			// Begin Class Locus
			//Class and Feature IDs 
			static const long long LOCUS_CLASS = 274444621;
			static const unsigned int LOCUS_CLASS_FEATURE_COUNT = 3;
			static const unsigned int LOCUS_CLASS_OPERATION_COUNT = 7;
			
			static const long long LOCUS_ATTRIBUTE_EXECUTOR = 1079111157;
			static const long long LOCUS_ATTRIBUTE_EXTENSIONALVALUES = 1315349633;
			static const long long LOCUS_ATTRIBUTE_FACTORY = 897667860;
			
			static const int LOCUS_OPERATION_ADD_EXTENSIONALVALUE = 433913546;
			static const int LOCUS_OPERATION_ASSIGNEXECUTOR_EXECUTOR = 1235487051;
			static const int LOCUS_OPERATION_ASSIGNFACTORY_EXECUTIONFACTORY = 361443955;
			static const int LOCUS_OPERATION_CONFORMS_CLASSIFIER_CLASSIFIER = 1626464999;
			static const int LOCUS_OPERATION_INSTANTIATE_CLASS = 1875707887;
			static const int LOCUS_OPERATION_REMOVE_EXTENSIONALVALUE = 32081076;
			static const int LOCUS_OPERATION_RETRIEVEEXTENT_CLASSIFIER = 673387949;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getLocus_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getLocus_Attribute_executor() const = 0;
			virtual std::shared_ptr<ecore::EReference> getLocus_Attribute_extensionalValues() const = 0;
			virtual std::shared_ptr<ecore::EReference> getLocus_Attribute_factory() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getLocus_Operation_add_ExtensionalValue() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getLocus_Operation_assignExecutor_Executor() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getLocus_Operation_assignFactory_ExecutionFactory() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getLocus_Operation_conforms_Classifier_Classifier() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getLocus_Operation_instantiate_Class() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getLocus_Operation_remove_ExtensionalValue() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getLocus_Operation_retrieveExtent_Classifier() const = 0;
			
			// End Class Locus


			// Begin Class SemanticStrategy
			//Class and Feature IDs 
			static const long long SEMANTICSTRATEGY_CLASS = 1874097743;
			static const unsigned int SEMANTICSTRATEGY_CLASS_FEATURE_COUNT = 0;
			static const unsigned int SEMANTICSTRATEGY_CLASS_OPERATION_COUNT = 1;
			
			
			static const int SEMANTICSTRATEGY_OPERATION_GETNAME = 1330583593;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getSemanticStrategy_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getSemanticStrategy_Operation_getName() const = 0;
			
			// End Class SemanticStrategy


			// Begin Class SemanticVisitor
			//Class and Feature IDs 
			static const long long SEMANTICVISITOR_CLASS = 768926104;
			static const unsigned int SEMANTICVISITOR_CLASS_FEATURE_COUNT = 0;
			static const unsigned int SEMANTICVISITOR_CLASS_OPERATION_COUNT = 2;
			
			
			static const int SEMANTICVISITOR_OPERATION__BEGINISOLATION = 1202559749;
			static const int SEMANTICVISITOR_OPERATION__ENDISOLATION = 1758854823;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getSemanticVisitor_Class() const = 0;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getSemanticVisitor_Operation__beginIsolation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getSemanticVisitor_Operation__endIsolation() const = 0;
			
			// End Class SemanticVisitor

			
			

			

			//Singleton Instance and Getter
			private:
				static std::shared_ptr<LociPackage> instance;
			public:
				static std::shared_ptr<LociPackage> eInstance();
	};
}
#endif /* end of include guard: FUML_SEMANTICS_LOCIPACKAGE_HPP */
