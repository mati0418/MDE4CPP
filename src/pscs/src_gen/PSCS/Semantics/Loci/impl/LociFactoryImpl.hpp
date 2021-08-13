//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_LOCIFACTORYIMPL_HPP
#define PSCS_SEMANTICS_LOCIFACTORYIMPL_HPP

// namespace macro header include
#include "PSCS/PSCS.hpp"

#include "ecore/impl/EFactoryImpl.hpp"

#include "PSCS/Semantics/Loci/LociFactory.hpp"

namespace Loci 
{	class CS_ExecutionFactory;
	class CS_Executor;
	class CS_Locus;
}

namespace PSCS::Semantics::Loci 
{
	class PSCS_API LociFactoryImpl : virtual public ecore::EFactoryImpl , virtual public LociFactory 
	{
		private:    
			LociFactoryImpl(LociFactoryImpl const&) = delete;
			LociFactoryImpl& operator=(LociFactoryImpl const&) = delete;

		protected:
			friend class LociFactory;
			// Constructor
			LociFactoryImpl();

		public:
			virtual ~LociFactoryImpl();
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const;

			//Creator functions
			 virtual std::shared_ptr<PSCS::Semantics::Loci::CS_ExecutionFactory> createCS_ExecutionFactory(const int metaElementID = LociPackage::CS_EXECUTIONFACTORY_CLASS) const ;
			 virtual std::shared_ptr<PSCS::Semantics::Loci::CS_Executor> createCS_Executor(const int metaElementID = LociPackage::CS_EXECUTOR_CLASS) const ;
			 virtual std::shared_ptr<PSCS::Semantics::Loci::CS_Locus> createCS_Locus(const int metaElementID = LociPackage::CS_LOCUS_CLASS) const ;
			 

		private:
			static LociFactory* create();
            std::map<std::string,int> m_idMap;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_LOCIFACTORYIMPL_HPP */
