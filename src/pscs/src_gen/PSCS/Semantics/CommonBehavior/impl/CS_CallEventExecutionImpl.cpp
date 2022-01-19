
#include "PSCS/Semantics/CommonBehavior/impl/CS_CallEventExecutionImpl.hpp"

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
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"

//Includes from codegen annotation
#include "PSCS/Semantics/CommonBehavior/CS_EventOccurrence.hpp"
#include "fUML/fUMLFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersFactory.hpp"
#include "uml/Behavior.hpp"
#include "PSCS/Semantics/StructuredClassifiers/CS_InteractionPoint.hpp"
#include "fUML/Semantics/CommonBehavior/CallEventExecution.hpp"
#include "uml/Classifier.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "fUML/Semantics/SimpleClassifiers/FeatureValue.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
#include "fUML/Semantics/CommonBehavior/ObjectActivation.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/Values/Value.hpp"
//Factories and Package includes
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSCS::Semantics::CommonBehavior;

//*********************************
// Constructor / Destructor
//*********************************
CS_CallEventExecutionImpl::CS_CallEventExecutionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CS_CallEventExecutionImpl::~CS_CallEventExecutionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_CallEventExecution "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CS_CallEventExecutionImpl::CS_CallEventExecutionImpl(const CS_CallEventExecutionImpl & obj): CS_CallEventExecutionImpl()
{
	*this = obj;
}

CS_CallEventExecutionImpl& CS_CallEventExecutionImpl::operator=(const CS_CallEventExecutionImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::CommonBehavior::CallEventExecutionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CS_CallEventExecution 
	 * which is generated by the compiler (as CS_CallEventExecution is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CS_CallEventExecution::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_CallEventExecution "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_interactionPoint  = obj.getInteractionPoint();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CS_CallEventExecutionImpl::copy() const
{
	std::shared_ptr<CS_CallEventExecutionImpl> element(new CS_CallEventExecutionImpl());
	*element =(*this);
	element->setThisCS_CallEventExecutionPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> CS_CallEventExecutionImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new call event execution that is a copy of this execution
// with no referenced interaction point.

std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_CallEventExecution> newValue = std::dynamic_pointer_cast<PSCS::Semantics::CommonBehavior::CS_CallEventExecution>(fUML::Semantics::CommonBehavior::CallEventExecutionImpl::_copy());
newValue->setInteractionPoint(nullptr);
return newValue;
	//end of body
}

std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> CS_CallEventExecutionImpl::createEventOccurrence()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// Wrap the created event occurrence within a CS_EventOccurrence which
	// references the behavior port on which the call was dispatched.
	std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_EventOccurrence> wrappingEventOccurrence = PSCS::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createCS_EventOccurrence();
	wrappingEventOccurrence->setInteractionPoint(this->getInteractionPoint());
	wrappingEventOccurrence->setWrappedEventOccurrence(fUML::Semantics::CommonBehavior::CallEventExecutionImpl::createEventOccurrence());
	return wrappingEventOccurrence;
	//end of body
}

std::shared_ptr<fUML::Semantics::Values::Value> CS_CallEventExecutionImpl::new_()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new call event execution.

return PSCS::Semantics::CommonBehavior::CommonBehaviorFactory::eInstance()->createCS_CallEventExecution();
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference interactionPoint */
std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> CS_CallEventExecutionImpl::getInteractionPoint() const
{
    return m_interactionPoint;
}
void CS_CallEventExecutionImpl::setInteractionPoint(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> _interactionPoint)
{
    m_interactionPoint = _interactionPoint;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> CS_CallEventExecutionImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void CS_CallEventExecutionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get PSCSFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void CS_CallEventExecutionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("interactionPoint");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("interactionPoint")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::CommonBehavior::CallEventExecutionImpl::loadAttributes(loadHandler, attr_list);
}

void CS_CallEventExecutionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::CommonBehavior::CallEventExecutionImpl::loadNode(nodeName, loadHandler);
}

void CS_CallEventExecutionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::CS_CALLEVENTEXECUTION_ATTRIBUTE_INTERACTIONPOINT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> _interactionPoint = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>( references.front() );
				setInteractionPoint(_interactionPoint);
			}
			
			return;
		}
	}
	fUML::Semantics::CommonBehavior::CallEventExecutionImpl::resolveReferences(featureID, references);
}

void CS_CallEventExecutionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::CommonBehavior::CallEventExecutionImpl::saveContent(saveHandler);
	
	fUML::Semantics::CommonBehavior::ExecutionImpl::saveContent(saveHandler);
	
	fUML::Semantics::StructuredClassifiers::ObjectImpl::saveContent(saveHandler);
	
	fUML::Semantics::StructuredClassifiers::ExtensionalValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::CompoundValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::SimpleClassifiers::StructuredValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CS_CallEventExecutionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::Semantics::CommonBehavior::CommonBehaviorPackage> package = PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getInteractionPoint(), "interactionPoint", getInteractionPoint()->eClass() != PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getCS_InteractionPoint_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> CS_CallEventExecutionImpl::eStaticClass() const
{
	return PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getCS_CallEventExecution_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any CS_CallEventExecutionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::CS_CALLEVENTEXECUTION_ATTRIBUTE_INTERACTIONPOINT:
			return eAny(getInteractionPoint(),PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::CS_INTERACTIONPOINT_CLASS,false); //48
	}
	return fUML::Semantics::CommonBehavior::CallEventExecutionImpl::eGet(featureID, resolve, coreType);
}

bool CS_CallEventExecutionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::CS_CALLEVENTEXECUTION_ATTRIBUTE_INTERACTIONPOINT:
			return getInteractionPoint() != nullptr; //48
	}
	return fUML::Semantics::CommonBehavior::CallEventExecutionImpl::internalEIsSet(featureID);
}

bool CS_CallEventExecutionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case PSCS::Semantics::CommonBehavior::CommonBehaviorPackage::CS_CALLEVENTEXECUTION_ATTRIBUTE_INTERACTIONPOINT:
		{
			// CAST Any to PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> _interactionPoint = std::dynamic_pointer_cast<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>(_temp);
			setInteractionPoint(_interactionPoint); //48
			return true;
		}
	}

	return fUML::Semantics::CommonBehavior::CallEventExecutionImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any CS_CallEventExecutionImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// PSCS::Semantics::CommonBehavior::CS_CallEventExecution::_copy() : fUML::Semantics::Values::Value: 900135867
		case CommonBehaviorPackage::CS_CALLEVENTEXECUTION_OPERATION__COPY:
		{
			result = eAny(this->_copy(), fUML::Semantics::Values::ValuesPackage::VALUE_CLASS,false);
			break;
		}
		// PSCS::Semantics::CommonBehavior::CS_CallEventExecution::createEventOccurrence() : fUML::Semantics::CommonBehavior::EventOccurrence: 801253865
		case CommonBehaviorPackage::CS_CALLEVENTEXECUTION_OPERATION_CREATEEVENTOCCURRENCE:
		{
			result = eAny(this->createEventOccurrence(), fUML::Semantics::CommonBehavior::CommonBehaviorPackage::EVENTOCCURRENCE_CLASS,false);
			break;
		}
		// PSCS::Semantics::CommonBehavior::CS_CallEventExecution::new_() : fUML::Semantics::Values::Value: 161317237
		case CommonBehaviorPackage::CS_CALLEVENTEXECUTION_OPERATION_NEW_:
		{
			result = eAny(this->new_(), fUML::Semantics::Values::ValuesPackage::VALUE_CLASS,false);
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::CommonBehavior::CallEventExecutionImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSCS::Semantics::CommonBehavior::CS_CallEventExecution> CS_CallEventExecutionImpl::getThisCS_CallEventExecutionPtr() const
{
	return m_thisCS_CallEventExecutionPtr.lock();
}
void CS_CallEventExecutionImpl::setThisCS_CallEventExecutionPtr(std::weak_ptr<PSCS::Semantics::CommonBehavior::CS_CallEventExecution> thisCS_CallEventExecutionPtr)
{
	m_thisCS_CallEventExecutionPtr = thisCS_CallEventExecutionPtr;
	setThisCallEventExecutionPtr(thisCS_CallEventExecutionPtr);
}


