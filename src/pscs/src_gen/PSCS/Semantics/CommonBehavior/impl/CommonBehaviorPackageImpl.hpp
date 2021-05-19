//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_COMMONBEHAVIORPACKAGEIMPL_HPP
#define PSCS_SEMANTICS_COMMONBEHAVIORPACKAGEIMPL_HPP

// namespace macro header include
#include "pscs/pscs.hpp"

#include "ecore/ecorePackage.hpp"
#include "ecore/impl/EPackageImpl.hpp"

#include "PSCS/Semantics/CommonBehavior/CommonBehaviorPackage.hpp" 


namespace PSCS::Semantics::CommonBehavior 
{
	class CS_CallEventExecution;
	class CS_EventOccurrence;}

namespace ecore
{
	class ecoreFactory;
}

namespace PSCS::Semantics::CommonBehavior
{
	class PSCS_API CommonBehaviorPackageImpl : public ecore::EPackageImpl ,virtual public CommonBehaviorPackage
	{
		private:    
			CommonBehaviorPackageImpl(CommonBehaviorPackageImpl const&) = delete;
			CommonBehaviorPackageImpl& operator=(CommonBehaviorPackageImpl const&) = delete;

		protected:
			CommonBehaviorPackageImpl();

		public:
			virtual ~CommonBehaviorPackageImpl();

			// Begin Class CS_CallEventExecution
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_CallEventExecution_Class() const ;
			
			
			virtual std::shared_ptr<ecore::EReference> getCS_CallEventExecution_Attribute_interactionPoint() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getCS_CallEventExecution_Operation__copy() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_CallEventExecution_Operation_createEventOccurrence() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_CallEventExecution_Operation_new_() const ;
			
			// End Class CS_CallEventExecution

			// Begin Class CS_EventOccurrence
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_EventOccurrence_Class() const ;
			
			virtual std::shared_ptr<ecore::EAttribute> getCS_EventOccurrence_Attribute_propagationInward() const ;
			
			virtual std::shared_ptr<ecore::EReference> getCS_EventOccurrence_Attribute_interactionPoint() const ;
			virtual std::shared_ptr<ecore::EReference> getCS_EventOccurrence_Attribute_onPort() const ;
			virtual std::shared_ptr<ecore::EReference> getCS_EventOccurrence_Attribute_wrappedEventOccurrence() const ;
			
			virtual std::shared_ptr<ecore::EOperation> getCS_EventOccurrence_Operation_doSend() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_EventOccurrence_Operation_getParameterValues() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_EventOccurrence_Operation_match_Trigger() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_EventOccurrence_Operation_sendInTo_CS_Reference_Port() const ;
			virtual std::shared_ptr<ecore::EOperation> getCS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port() const ;
			
			// End Class CS_EventOccurrence

			
			// SubPackages Getters
			

		private:
			std::shared_ptr<ecore::EClass> m_cS_CallEventExecution_Class = nullptr;std::shared_ptr<ecore::EClass> m_cS_EventOccurrence_Class = nullptr;
			
			std::shared_ptr<ecore::EAttribute> m_cS_EventOccurrence_Attribute_propagationInward = nullptr;
			std::shared_ptr<ecore::EReference> m_cS_CallEventExecution_Attribute_interactionPoint = nullptr;std::shared_ptr<ecore::EReference> m_cS_EventOccurrence_Attribute_interactionPoint = nullptr;std::shared_ptr<ecore::EReference> m_cS_EventOccurrence_Attribute_onPort = nullptr;std::shared_ptr<ecore::EReference> m_cS_EventOccurrence_Attribute_wrappedEventOccurrence = nullptr;
			std::shared_ptr<ecore::EOperation> m_cS_CallEventExecution_Operation__copy = nullptr;std::shared_ptr<ecore::EOperation> m_cS_CallEventExecution_Operation_createEventOccurrence = nullptr;std::shared_ptr<ecore::EOperation> m_cS_EventOccurrence_Operation_doSend = nullptr;std::shared_ptr<ecore::EOperation> m_cS_EventOccurrence_Operation_getParameterValues = nullptr;std::shared_ptr<ecore::EOperation> m_cS_EventOccurrence_Operation_match_Trigger = nullptr;std::shared_ptr<ecore::EOperation> m_cS_CallEventExecution_Operation_new_ = nullptr;std::shared_ptr<ecore::EOperation> m_cS_EventOccurrence_Operation_sendInTo_CS_Reference_Port = nullptr;std::shared_ptr<ecore::EOperation> m_cS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port = nullptr;

			friend class CommonBehaviorPackage;

			static bool isInited;
			static CommonBehaviorPackage* create();
			bool isInitialized = false;
 			bool isCreated = false;

			virtual void init(std::shared_ptr<ecore::EPackage> package);

		public:
			void createPackageContents(std::shared_ptr<ecore::EPackage> package);
			void initializePackageContents();

		private:
			void createCS_CallEventExecutionContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createCS_EventOccurrenceContent(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);
			void createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);

			void initializeCS_CallEventExecutionContent();
			void initializeCS_EventOccurrenceContent();
			void initializePackageEDataTypes();



	};
}
#endif /* end of include guard: PSCS_SEMANTICS_COMMONBEHAVIORPACKAGEIMPL_HPP */
