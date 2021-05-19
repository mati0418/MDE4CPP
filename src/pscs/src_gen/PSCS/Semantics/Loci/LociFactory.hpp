//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_LOCIFACTORY_HPP
#define PSCS_SEMANTICS_LOCIFACTORY_HPP

#include <map>
#include <memory>

// namespace macro header include
#include "pscs/pscs.hpp"

#include "ecore/EFactory.hpp"
#include "PSCS/Semantics/Loci/LociPackage.hpp"

namespace fUML::Semantics::Loci 
{
	class Locus;
}



namespace PSCS::Semantics::Loci 
{
	class PSCS_API LociFactory : virtual public ecore::EFactory 
	{
		private:    
			LociFactory(LociFactory const&) = delete;
			LociFactory& operator=(LociFactory const&) = delete;
		protected:
			LociFactory(){}
		
			//Singleton Instance and Getter
			private:
				static std::shared_ptr<LociFactory> instance;
			public:
				static std::shared_ptr<LociFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			virtual std::shared_ptr<PSCS::Semantics::Loci::CS_ExecutionFactory> createCS_ExecutionFactory(const int metaElementID = LociPackage::CS_EXECUTIONFACTORY_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<PSCS::Semantics::Loci::CS_ExecutionFactory> createCS_ExecutionFactory_in_Locus(std::weak_ptr<fUML::Semantics::Loci::Locus> par_locus, const int metaElementID = LociPackage::CS_EXECUTIONFACTORY_CLASS) const = 0;
			
			virtual std::shared_ptr<PSCS::Semantics::Loci::CS_Executor> createCS_Executor(const int metaElementID = LociPackage::CS_EXECUTOR_CLASS) const = 0;
			//Add containing object
			virtual std::shared_ptr<PSCS::Semantics::Loci::CS_Executor> createCS_Executor_in_Locus(std::weak_ptr<fUML::Semantics::Loci::Locus> par_locus, const int metaElementID = LociPackage::CS_EXECUTOR_CLASS) const = 0;
			
			virtual std::shared_ptr<PSCS::Semantics::Loci::CS_Locus> createCS_Locus(const int metaElementID = LociPackage::CS_LOCUS_CLASS) const = 0;
			
			
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_LOCIFACTORY_HPP */
