//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIORFACTORYIMPL_HPP
#define FUML_SEMANTICS_COMMONBEHAVIORFACTORYIMPL_HPP

// namespace macro header include
#include "fuml/fuml.hpp"

#include "ecore/impl/EFactoryImpl.hpp"

#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"

namespace CommonBehavior 
{	class CallEventBehavior;
	class CallEventExecution;
	class CallEventOccurrence;
	class ClassifierBehaviorExecution;
	class ClassifierBehaviorInvocationEventAccepter;
	class EventAccepter;
	class EventDispatchLoop;
	class EventOccurrence;
	class Execution;
	class FIFOGetNextEventStrategy;
	class GetNextEventStrategy;
	class InvocationEventOccurrence;
	class ObjectActivation;
	class OpaqueBehaviorExecution;
	class ParameterValue;
	class SignalEventOccurrence;
}

namespace fUML::Semantics::CommonBehavior 
{
	class FUML_API CommonBehaviorFactoryImpl : virtual public ecore::EFactoryImpl , virtual public CommonBehaviorFactory 
	{
		private:    
			CommonBehaviorFactoryImpl(CommonBehaviorFactoryImpl const&) = delete;
			CommonBehaviorFactoryImpl& operator=(CommonBehaviorFactoryImpl const&) = delete;

		protected:
			friend class CommonBehaviorFactory;
			// Constructor
			CommonBehaviorFactoryImpl();

		public:
			virtual ~CommonBehaviorFactoryImpl();
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const;

			//Creator functions
			 virtual std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventBehavior> createCallEventBehavior(const int metaElementID = CommonBehaviorPackage::CALLEVENTBEHAVIOR_CLASS) const ;
			 
			 virtual std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecution> createCallEventExecution(const int metaElementID = CommonBehaviorPackage::CALLEVENTEXECUTION_CLASS) const ;
			 
			 virtual std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventOccurrence> createCallEventOccurrence(const int metaElementID = CommonBehaviorPackage::CALLEVENTOCCURRENCE_CLASS) const ;
			 
			 virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorExecution> createClassifierBehaviorExecution(const int metaElementID = CommonBehaviorPackage::CLASSIFIERBEHAVIOREXECUTION_CLASS) const ;
			 
			 virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ClassifierBehaviorInvocationEventAccepter> createClassifierBehaviorInvocationEventAccepter(const int metaElementID = CommonBehaviorPackage::CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_CLASS) const ;
			 
			 virtual std::shared_ptr<fUML::Semantics::CommonBehavior::EventDispatchLoop> createEventDispatchLoop(const int metaElementID = CommonBehaviorPackage::EVENTDISPATCHLOOP_CLASS) const ;
			 
			 virtual std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> createEventOccurrence(const int metaElementID = CommonBehaviorPackage::EVENTOCCURRENCE_CLASS) const ;
			 
			 virtual std::shared_ptr<fUML::Semantics::CommonBehavior::FIFOGetNextEventStrategy> createFIFOGetNextEventStrategy(const int metaElementID = CommonBehaviorPackage::FIFOGETNEXTEVENTSTRATEGY_CLASS) const ;
			 
			 virtual std::shared_ptr<fUML::Semantics::CommonBehavior::InvocationEventOccurrence> createInvocationEventOccurrence(const int metaElementID = CommonBehaviorPackage::INVOCATIONEVENTOCCURRENCE_CLASS) const ;
			 
			 virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> createObjectActivation(const int metaElementID = CommonBehaviorPackage::OBJECTACTIVATION_CLASS) const ;
			 
			 virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> createParameterValue(const int metaElementID = CommonBehaviorPackage::PARAMETERVALUE_CLASS) const ;
			 
			 virtual std::shared_ptr<fUML::Semantics::CommonBehavior::SignalEventOccurrence> createSignalEventOccurrence(const int metaElementID = CommonBehaviorPackage::SIGNALEVENTOCCURRENCE_CLASS) const ;
			 
			 

		private:
			static CommonBehaviorFactory* create();
            std::map<std::string,int> m_idMap;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIORFACTORYIMPL_HPP */
