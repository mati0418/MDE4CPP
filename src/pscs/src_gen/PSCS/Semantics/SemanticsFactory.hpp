//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICSFACTORY_HPP
#define PSCS_SEMANTICSFACTORY_HPP

#include <map>
#include <memory>

#include "ecore/EFactory.hpp"
#include "PSCS/Semantics/SemanticsPackage.hpp"

namespace PSCS::Semantics::Actions 
{
	class CS_AcceptCallActionActivation;
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

namespace fUML::Semantics::Activities 
{
	class ActivityNodeActivationGroup;
}

namespace PSCS::Semantics::Classification 
{
	class CS_InstanceValueEvaluation;
}

namespace PSCS::Semantics::CommonBehavior 
{
	class CS_CallEventExecution;
	class CS_EventOccurrence;
}

namespace PSCS::Semantics::Loci 
{
	class CS_ExecutionFactory;
	class CS_Executor;
	class CS_Locus;
}

namespace fUML::Semantics::Loci 
{
	class Locus;
}

namespace fUML::Semantics::Loci 
{
	class Locus;
}

namespace PSCS::Semantics::StructuredClassifiers 
{
	class CS_DefaultRequestPropagationStrategy;
	class CS_DispatchOperationOfInterfaceStrategy;
	class CS_InteractionPoint;
	class CS_Link;
	class CS_NameBased_StructuralFeatureOfInterfaceAccessStrategy;
	class CS_Object;
	class CS_Reference;
	class CS_RequestPropagationStrategy;
	class CS_StructuralFeatureOfInterfaceAccessStrategy;
}

namespace PSCS::Semantics::Values 
{
	class CS_OpaqueExpressionEvaluation;
}



namespace PSCS::Semantics 
{
	class SemanticsFactory : virtual public ecore::EFactory 
	{
		private:    
			SemanticsFactory(SemanticsFactory const&) = delete;
			SemanticsFactory& operator=(SemanticsFactory const&) = delete;
		protected:
			SemanticsFactory(){}
		
			//Singleton Instance and Getter
			private:
				static std::shared_ptr<SemanticsFactory> instance;
			public:
				static std::shared_ptr<SemanticsFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			
	};
}
#endif /* end of include guard: PSCS_SEMANTICSFACTORY_HPP */
