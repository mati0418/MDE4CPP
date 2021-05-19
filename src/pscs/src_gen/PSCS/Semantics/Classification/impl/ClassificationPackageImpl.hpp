//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_CLASSIFICATIONPACKAGEIMPL_HPP
#define PSCS_SEMANTICS_CLASSIFICATIONPACKAGEIMPL_HPP

// namespace macro header include
#include "pscs/pscs.hpp"

#include "ecore/ecorePackage.hpp"
#include "ecore/impl/EPackageImpl.hpp"

#include "PSCS/Semantics/Classification/ClassificationPackage.hpp" 


namespace PSCS::Semantics::Classification 
{
	class CS_InstanceValueEvaluation;}

namespace ecore
{
	class ecoreFactory;
}

namespace PSCS::Semantics::Classification
{
	class PSCS_API ClassificationPackageImpl : public ecore::EPackageImpl ,virtual public ClassificationPackage
	{
		private:    
			ClassificationPackageImpl(ClassificationPackageImpl const&) = delete;
			ClassificationPackageImpl& operator=(ClassificationPackageImpl const&) = delete;

		protected:
			ClassificationPackageImpl();

		public:
			virtual ~ClassificationPackageImpl();

			// Begin Class CS_InstanceValueEvaluation
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_InstanceValueEvaluation_Class() const ;
			
			
			
			virtual std::shared_ptr<ecore::EOperation> getCS_InstanceValueEvaluation_Operation_evaluate() const ;
			
			// End Class CS_InstanceValueEvaluation

			
			// SubPackages Getters
			

		private:
			std::shared_ptr<ecore::EClass> m_cS_InstanceValueEvaluation_Class = nullptr;
			
			
			
			std::shared_ptr<ecore::EOperation> m_cS_InstanceValueEvaluation_Operation_evaluate = nullptr;

			friend class ClassificationPackage;

			static bool isInited;
			static ClassificationPackage* create();
			bool isInitialized = false;
 			bool isCreated = false;

			virtual void init(std::shared_ptr<ecore::EPackage> package);

		public:
			void createPackageContents(std::shared_ptr<ecore::EPackage> package);
			void initializePackageContents();

		private:
			void createCS_InstanceValueEvaluationContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);

			void initializeCS_InstanceValueEvaluationContent();
			void initializePackageEDataTypes();



	};
}
#endif /* end of include guard: PSCS_SEMANTICS_CLASSIFICATIONPACKAGEIMPL_HPP */
