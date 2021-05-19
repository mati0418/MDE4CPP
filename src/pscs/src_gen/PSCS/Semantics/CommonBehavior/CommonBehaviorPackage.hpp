//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_COMMONBEHAVIORPACKAGE_HPP
#define PSCS_SEMANTICS_COMMONBEHAVIORPACKAGE_HPP

// namespace macro header include
#include "pscs/pscs.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EAnnotation;
	class EAttribute;
	class EClass;
	class EDataType;
	class EGenericType;
	class EOperation;
	class EParameter;
	class EReference;
	class EStringToStringMapEntry;
}

namespace PSCS::Semantics::CommonBehavior 
{
	class CS_CallEventExecution;
	class CS_EventOccurrence;
}
 
namespace PSCS::Semantics::CommonBehavior 
{
	/*!
	The Metamodel Package for the CommonBehavior metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class PSCS_API CommonBehaviorPackage : virtual public ecore::EPackage 
	{
		private:    
			CommonBehaviorPackage(CommonBehaviorPackage const&) = delete;
			CommonBehaviorPackage& operator=(CommonBehaviorPackage const&) = delete;

		protected:
			CommonBehaviorPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class CS_CallEventExecution
			//Class and Feature IDs 
			static const unsigned long CS_CALLEVENTEXECUTION_CLASS = 329007207;
			static const unsigned int CS_CALLEVENTEXECUTION_CLASS_FEATURE_COUNT = 9;
			static const unsigned int CS_CALLEVENTEXECUTION_CLASS_OPERATION_COUNT = 59;
			
			static const int CS_CALLEVENTEXECUTION_ATTRIBUTE_INTERACTIONPOINT = 408;
			
			static const int CS_CALLEVENTEXECUTION_OPERATION__COPY = 467;
			static const int CS_CALLEVENTEXECUTION_OPERATION_CREATEEVENTOCCURRENCE = 465;
			static const int CS_CALLEVENTEXECUTION_OPERATION_NEW_ = 466;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_CallEventExecution_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getCS_CallEventExecution_Attribute_interactionPoint() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getCS_CallEventExecution_Operation__copy() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_CallEventExecution_Operation_createEventOccurrence() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_CallEventExecution_Operation_new_() const = 0;
			
			// End Class CS_CallEventExecution


			// Begin Class CS_EventOccurrence
			//Class and Feature IDs 
			static const unsigned long CS_EVENTOCCURRENCE_CLASS = 619124533;
			static const unsigned int CS_EVENTOCCURRENCE_CLASS_FEATURE_COUNT = 5;
			static const unsigned int CS_EVENTOCCURRENCE_CLASS_OPERATION_COUNT = 10;
			static const int CS_EVENTOCCURRENCE_ATTRIBUTE_PROPAGATIONINWARD = 1303;
			
			static const int CS_EVENTOCCURRENCE_ATTRIBUTE_INTERACTIONPOINT = 1301;
			static const int CS_EVENTOCCURRENCE_ATTRIBUTE_ONPORT = 1304;
			static const int CS_EVENTOCCURRENCE_ATTRIBUTE_WRAPPEDEVENTOCCURRENCE = 1302;
			
			static const int CS_EVENTOCCURRENCE_OPERATION_DOSEND = 1312;
			static const int CS_EVENTOCCURRENCE_OPERATION_GETPARAMETERVALUES = 1310;
			static const int CS_EVENTOCCURRENCE_OPERATION_MATCH_TRIGGER = 1311;
			static const int CS_EVENTOCCURRENCE_OPERATION_SENDINTO_CS_REFERENCE_PORT = 1313;
			static const int CS_EVENTOCCURRENCE_OPERATION_SENDOUTTO_CS_REFERENCE_PORT = 1314;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCS_EventOccurrence_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getCS_EventOccurrence_Attribute_propagationInward() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getCS_EventOccurrence_Attribute_interactionPoint() const = 0;
			virtual std::shared_ptr<ecore::EReference> getCS_EventOccurrence_Attribute_onPort() const = 0;
			virtual std::shared_ptr<ecore::EReference> getCS_EventOccurrence_Attribute_wrappedEventOccurrence() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getCS_EventOccurrence_Operation_doSend() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_EventOccurrence_Operation_getParameterValues() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_EventOccurrence_Operation_match_Trigger() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_EventOccurrence_Operation_sendInTo_CS_Reference_Port() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getCS_EventOccurrence_Operation_sendOutTo_CS_Reference_Port() const = 0;
			
			// End Class CS_EventOccurrence

			
			

			

			//Singleton Instance and Getter
			private:
				static std::shared_ptr<CommonBehaviorPackage> instance;
			public:
				static std::shared_ptr<CommonBehaviorPackage> eInstance();
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_COMMONBEHAVIORPACKAGE_HPP */
