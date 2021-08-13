//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_COMMONBEHAVIORFACTORY_HPP
#define PSCS_SEMANTICS_COMMONBEHAVIORFACTORY_HPP
// namespace macro header include
#include "PSCS/PSCS.hpp"

#include <map>
#include <memory>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EFactory.hpp"
#include "PSCS/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"




namespace PSCS::Semantics::CommonBehavior 
{
	class PSCS_API CommonBehaviorFactory : virtual public ecore::EFactory 
	{
		private:    
			CommonBehaviorFactory(CommonBehaviorFactory const&) = delete;
			CommonBehaviorFactory& operator=(CommonBehaviorFactory const&) = delete;
		protected:
			CommonBehaviorFactory(){}
		
			//Singleton Instance and Getter
			private:
				static std::shared_ptr<CommonBehaviorFactory> instance;
			public:
				static std::shared_ptr<CommonBehaviorFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			virtual std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_CallEventExecution> createCS_CallEventExecution(const int metaElementID = CommonBehaviorPackage::CS_CALLEVENTEXECUTION_CLASS) const = 0;
			virtual std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_EventOccurrence> createCS_EventOccurrence(const int metaElementID = CommonBehaviorPackage::CS_EVENTOCCURRENCE_CLASS) const = 0;
			
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_COMMONBEHAVIORFACTORY_HPP */
