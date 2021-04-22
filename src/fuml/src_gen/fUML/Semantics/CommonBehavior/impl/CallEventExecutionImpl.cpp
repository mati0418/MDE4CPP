#include "fUML/Semantics/CommonBehavior/impl/CallEventExecutionImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <cassert>
#include <iostream>
#include <sstream>

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation
#include "fUML/Semantics/CommonBehavior/CallEventOccurrence.hpp"
#include "fUML/Semantics/CommonBehavior/CallEventBehavior.hpp"
#include "fUML/FUMLFactory.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "uml/ParameterDirectionKind.hpp"
#include "uml/Parameter.hpp"
#include "uml/Behavior.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Behavior.hpp"
#include "uml/Classifier.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"
#include "uml/Operation.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/Values/Value.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************
CallEventExecutionImpl::CallEventExecutionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CallEventExecutionImpl::~CallEventExecutionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CallEventExecution "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CallEventExecutionImpl::CallEventExecutionImpl(const CallEventExecutionImpl & obj): CallEventExecutionImpl()
{
	*this = obj;
}

CallEventExecutionImpl& CallEventExecutionImpl::operator=(const CallEventExecutionImpl & obj)
{
	//call overloaded =Operator for each base class
	ExecutionImpl::operator=(obj);
	CallEventExecution::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CallEventExecution "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_callerSuspended = obj.getCallerSuspended();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CallEventExecutionImpl::copy() const
{
	std::shared_ptr<CallEventExecutionImpl> element(new CallEventExecutionImpl());
	*element =(*this);
	element->setThisCallEventExecutionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CallEventExecutionImpl::eStaticClass() const
{
	return fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getCallEventExecution_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute callerSuspended
*/
bool CallEventExecutionImpl::getCallerSuspended() const 
{
	return m_callerSuspended;
}
void CallEventExecutionImpl::setCallerSuspended(bool _callerSuspended)
{
	m_callerSuspended = _callerSuspended;
} 


//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> CallEventExecutionImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new call event execution that is a copy of this execution, with the
// caller initially not suspended.

std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecution> newValue = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::CallEventExecution>(fUML::Semantics::CommonBehavior::ExecutionImpl::_copy());
newValue->setCallerSuspended(false);
return newValue;
	//end of body
}

std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> CallEventExecutionImpl::createEventOccurrence()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventOccurrence> eventOccurrence = fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createCallEventOccurrence();
	eventOccurrence->setExecution(getThisCallEventExecutionPtr());
	return eventOccurrence;
	//end of body
}

void CallEventExecutionImpl::execute()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Make the call on the target object (which is the context of this execution)
// and suspend the caller until the call is completed.
// Note: The callerSuspended flag needs to be set before the call is made,
// in case the call is immediately handled and returned, even before the
// suspend loop is started.

this->setCallerSuspended(true);
this->makeCall();
this->suspendCaller();
	//end of body
}

std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > CallEventExecutionImpl::getInputParameterValues()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Return input parameter values for this execution.

std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> parameterValues(new Bag<fUML::Semantics::CommonBehavior::ParameterValue>());
for(unsigned int i = 0; i < this->getParameterValues()->size(); i++)
{
	std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> parameterValue = this->getParameterValues()->at(i);
	if((parameterValue->getParameter()->getDirection() == uml::ParameterDirectionKind::IN) || (parameterValue->getParameter()->getDirection() == uml::ParameterDirectionKind::INOUT))
	{
		parameterValues->add(parameterValue);
	}
}

return parameterValues;
	//end of body
}

std::shared_ptr<uml::Operation> CallEventExecutionImpl::getOperation()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Return the operation being called by this call event execution.
return (std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::CallEventBehavior>(this->getBehavior()))->getOperation();
	//end of body
}

bool CallEventExecutionImpl::isCallerSuspended()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		_beginIsolation();
	bool isSuspended = m_callerSuspended;
	_endIsolation();

	return isSuspended;
	//end of body
}

void CallEventExecutionImpl::makeCall()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Make the call on the target object (which is the context of this execution)
// by sending a call event occurrence. (Note that the call will never be
// completed if the target is not an active object, since then the object
// would then have no event pool in which the event occurrence could be placed.)

	std::shared_ptr<fUML::Semantics::StructuredClassifiers::Reference> reference = fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactory::eInstance()->createReference();
	reference->setReferent(this->getContext());
	this->createEventOccurrence()->sendTo(reference);
	//end of body
}

std::shared_ptr<fUML::Semantics::Values::Value> CallEventExecutionImpl::new_()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return fUML::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createCallEventExecution();
	//end of body
}

void CallEventExecutionImpl::releaseCaller()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	setCallerSuspended(false);
	//end of body
}

void CallEventExecutionImpl::setOutputParameterValues(std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> parameterValues)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Set the output parameter values for this execution.

std::shared_ptr<Bag<uml::Parameter>> parameters = this->getBehavior()->getOwnedParameter();
unsigned int i = 1;
unsigned int j = 1;

while(i <= parameters->size())
{
	std::shared_ptr<uml::Parameter> parameter = parameters->at(i-1);
	if((parameter->getDirection() == uml::ParameterDirectionKind::INOUT) || (parameter->getDirection() == uml::ParameterDirectionKind::OUT) || (parameter->getDirection() == uml::ParameterDirectionKind::RETURN))
	{
		std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> parameterValue = getParameterValues()->at(j-1);
		parameterValue->setParameter(parameter);
		this->setParameterValue(parameterValue);
		j += 1;
	}
	i += 1;
}
	//end of body
}

void CallEventExecutionImpl::suspendCaller()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	while(isCallerSuspended())
	{
		wait_();
	}
	//end of body
}

void CallEventExecutionImpl::wait_()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Wait for an indeterminate amount of time to allow other concurrent
// executions to proceed

// [There is no further formal specification for this operation.].
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<CallEventExecution> CallEventExecutionImpl::getThisCallEventExecutionPtr() const
{
	return m_thisCallEventExecutionPtr.lock();
}
void CallEventExecutionImpl::setThisCallEventExecutionPtr(std::weak_ptr<CallEventExecution> thisCallEventExecutionPtr)
{
	m_thisCallEventExecutionPtr = thisCallEventExecutionPtr;
	setThisExecutionPtr(thisCallEventExecutionPtr);
}
std::shared_ptr<ecore::EObject> CallEventExecutionImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CallEventExecutionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTEXECUTION_ATTRIBUTE_CALLERSUSPENDED:
			return eAny(getCallerSuspended()); //177
	}
	return ExecutionImpl::eGet(featureID, resolve, coreType);
}
bool CallEventExecutionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTEXECUTION_ATTRIBUTE_CALLERSUSPENDED:
			return getCallerSuspended() != false; //177
	}
	return ExecutionImpl::internalEIsSet(featureID);
}
bool CallEventExecutionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::CommonBehavior::CommonBehaviorPackage::CALLEVENTEXECUTION_ATTRIBUTE_CALLERSUSPENDED:
		{
			// BOOST CAST
			bool _callerSuspended = newValue->get<bool>();
			setCallerSuspended(_callerSuspended); //177
			return true;
		}
	}

	return ExecutionImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any CallEventExecutionImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 1752
		case CommonBehaviorPackage::CALLEVENTEXECUTION_OPERATION__COPY:
		{
			result = eAny(this->_copy());
			break;
		}
		
		// 1753
		case CommonBehaviorPackage::CALLEVENTEXECUTION_OPERATION_CREATEEVENTOCCURRENCE:
		{
			result = eAny(this->createEventOccurrence());
			break;
		}
		
		// 1754
		case CommonBehaviorPackage::CALLEVENTEXECUTION_OPERATION_EXECUTE:
		{
			this->execute();
			break;
		}
		
		// 1755
		case CommonBehaviorPackage::CALLEVENTEXECUTION_OPERATION_GETINPUTPARAMETERVALUES:
		{
			result = eAny(this->getInputParameterValues());
			break;
		}
		
		// 1756
		case CommonBehaviorPackage::CALLEVENTEXECUTION_OPERATION_GETOPERATION:
		{
			result = eAny(this->getOperation());
			break;
		}
		
		// 1757
		case CommonBehaviorPackage::CALLEVENTEXECUTION_OPERATION_ISCALLERSUSPENDED:
		{
			result = eAny(this->isCallerSuspended());
			break;
		}
		
		// 1758
		case CommonBehaviorPackage::CALLEVENTEXECUTION_OPERATION_MAKECALL:
		{
			this->makeCall();
			break;
		}
		
		// 1759
		case CommonBehaviorPackage::CALLEVENTEXECUTION_OPERATION_NEW_:
		{
			result = eAny(this->new_());
			break;
		}
		
		// 1760
		case CommonBehaviorPackage::CALLEVENTEXECUTION_OPERATION_RELEASECALLER:
		{
			this->releaseCaller();
			break;
		}
		
		// 1761
		case CommonBehaviorPackage::CALLEVENTEXECUTION_OPERATION_SETOUTPUTPARAMETERVALUES_PARAMETERVALUE:
		{
			//Retrieve input parameter 'parameterValues'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> incoming_param_parameterValues;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_parameterValues_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_parameterValues = (*incoming_param_parameterValues_arguments_citer)->get()->get<std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> >();
			this->setOutputParameterValues(incoming_param_parameterValues);
			break;
		}
		
		// 1762
		case CommonBehaviorPackage::CALLEVENTEXECUTION_OPERATION_SUSPENDCALLER:
		{
			this->suspendCaller();
			break;
		}
		
		// 1763
		case CommonBehaviorPackage::CALLEVENTEXECUTION_OPERATION_WAIT_:
		{
			this->wait_();
			break;
		}

		default:
		{
			// call superTypes
			result = ExecutionImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

//*********************************
// Persistence Functions
//*********************************
void CallEventExecutionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void CallEventExecutionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("callerSuspended");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setCallerSuspended(value);
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	ExecutionImpl::loadAttributes(loadHandler, attr_list);
}

void CallEventExecutionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ExecutionImpl::loadNode(nodeName, loadHandler);
}

void CallEventExecutionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ExecutionImpl::resolveReferences(featureID, references);
}

void CallEventExecutionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ExecutionImpl::saveContent(saveHandler);
	
	fUML::Semantics::StructuredClassifiers::ObjectImpl::saveContent(saveHandler);
	
	fUML::Semantics::StructuredClassifiers::ExtensionalValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::CompoundValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::StructuredValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
}

void CallEventExecutionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::CommonBehavior::CommonBehaviorPackage> package = fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getCallEventExecution_Attribute_callerSuspended()) )
		{
			saveHandler->addAttribute("callerSuspended", this->getCallerSuspended());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

