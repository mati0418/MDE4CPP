
#include "fUML/Semantics/Actions/impl/ReturnInformationImpl.hpp"

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
#include "uml/Classifier.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/CommonBehavior/CommonBehaviorFactory.hpp"

#include "fUML/Semantics/CommonBehavior/CallEventOccurrence.hpp"
#include "uml/Classifier.hpp"
#include "uml/Operation.hpp"
#include "fUML/Semantics/CommonBehavior/ParameterValue.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
ReturnInformationImpl::ReturnInformationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ReturnInformationImpl::~ReturnInformationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ReturnInformation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ReturnInformationImpl::ReturnInformationImpl(const ReturnInformationImpl & obj): ReturnInformationImpl()
{
	*this = obj;
}

ReturnInformationImpl& ReturnInformationImpl::operator=(const ReturnInformationImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Values::ValueImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ReturnInformation 
	 * which is generated by the compiler (as ReturnInformation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ReturnInformation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ReturnInformation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_callEventOccurrence  = obj.getCallEventOccurrence();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ReturnInformationImpl::copy() const
{
	std::shared_ptr<ReturnInformationImpl> element(new ReturnInformationImpl());
	*element =(*this);
	element->setThisReturnInformationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> ReturnInformationImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new return information value that is a copy of this value, with
// the same call event occurrence.

std::shared_ptr<fUML::Semantics::Actions::ReturnInformation> newValue = fUML::Semantics::Actions::ActionsFactory::eInstance()->createReturnInformation();
newValue->setCallEventOccurrence(this->getCallEventOccurrence());
return newValue;
	//end of body
}

bool ReturnInformationImpl::equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// One return information value equals another if they are for the
// same call event occurrence.

bool isEqual = false;

if(std::dynamic_pointer_cast<fUML::Semantics::Actions::ReturnInformation>(otherValue) != nullptr)
{
	isEqual = (std::dynamic_pointer_cast<fUML::Semantics::Actions::ReturnInformation>(otherValue))->getCallEventOccurrence() == this->getCallEventOccurrence();
}

return isEqual;
	//end of body
}

std::shared_ptr<uml::Operation> ReturnInformationImpl::getOperation()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Return the operation associated with the call event occurrence of this
// return information.

return this->getCallEventOccurrence()->getOperation();
	//end of body
}

std::shared_ptr<Bag<uml::Classifier> > ReturnInformationImpl::getTypes()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Return information is untyped.

std::shared_ptr<Bag<uml::Classifier>> types(new Bag<uml::Classifier>);

return types;
	//end of body
}

std::shared_ptr<fUML::Semantics::Values::Value> ReturnInformationImpl::new_()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new return information value, with an empty call event occurrence.

return fUML::Semantics::Actions::ActionsFactory::eInstance()->createReturnInformation();
	//end of body
}

void ReturnInformationImpl::reply(std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> outputParameterValues)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Reply to the call by setting the output parameters and
	// releasing the caller.
	this->getCallEventOccurrence()->setOutputParameterValues(outputParameterValues);
	this->getCallEventOccurrence()->releaseCaller();
	//end of body
}

std::shared_ptr<uml::ValueSpecification> ReturnInformationImpl::specify()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Return information cannot be specified using a value specification.
	return nullptr;
	//end of body
}

std::string ReturnInformationImpl::toString()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Return a string representation of the return information.
	std::string s = "ReturnInformation";
	std::string name = this->getCallEventOccurrence()->getOperation()->getName();
	if(name != "")
	{
		s = s + "(" + name + ")";
	}
	return s;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference callEventOccurrence */
std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventOccurrence> ReturnInformationImpl::getCallEventOccurrence() const
{
    return m_callEventOccurrence;
}
void ReturnInformationImpl::setCallEventOccurrence(std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventOccurrence> _callEventOccurrence)
{
    m_callEventOccurrence = _callEventOccurrence;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ReturnInformationImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ReturnInformationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ReturnInformationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("callEventOccurrence");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("callEventOccurrence")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::Values::ValueImpl::loadAttributes(loadHandler, attr_list);
}

void ReturnInformationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Values::ValueImpl::loadNode(nodeName, loadHandler);
}

void ReturnInformationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::RETURNINFORMATION_ATTRIBUTE_CALLEVENTOCCURRENCE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventOccurrence> _callEventOccurrence = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::CallEventOccurrence>( references.front() );
				setCallEventOccurrence(_callEventOccurrence);
			}
			
			return;
		}
	}
	fUML::Semantics::Values::ValueImpl::resolveReferences(featureID, references);
}

void ReturnInformationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ReturnInformationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getCallEventOccurrence(), "callEventOccurrence", getCallEventOccurrence()->eClass() != fUML::Semantics::CommonBehavior::CommonBehaviorPackage::eInstance()->getCallEventOccurrence_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


std::shared_ptr<ecore::EClass> ReturnInformationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getReturnInformation_Class();
}


//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ReturnInformationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::RETURNINFORMATION_ATTRIBUTE_CALLEVENTOCCURRENCE:
			{
				std::shared_ptr<ecore::EObject> returnValue=getCallEventOccurrence();
				return eAny(returnValue); //1020
			}
	}
	return fUML::Semantics::Values::ValueImpl::eGet(featureID, resolve, coreType);
}

bool ReturnInformationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::RETURNINFORMATION_ATTRIBUTE_CALLEVENTOCCURRENCE:
			return getCallEventOccurrence() != nullptr; //1020
	}
	return fUML::Semantics::Values::ValueImpl::internalEIsSet(featureID);
}

bool ReturnInformationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::RETURNINFORMATION_ATTRIBUTE_CALLEVENTOCCURRENCE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventOccurrence> _callEventOccurrence = std::dynamic_pointer_cast<fUML::Semantics::CommonBehavior::CallEventOccurrence>(_temp);
			setCallEventOccurrence(_callEventOccurrence); //1020
			return true;
		}
	}

	return fUML::Semantics::Values::ValueImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ReturnInformationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 2045103425
		case ActionsPackage::RETURNINFORMATION_OPERATION__COPY:
		{
			result = eAny(this->_copy());
			break;
		}
		
		// 1074588088
		case ActionsPackage::RETURNINFORMATION_OPERATION_EQUALS_VALUE:
		{
			//Retrieve input parameter 'otherValue'
			//parameter 0
			std::shared_ptr<fUML::Semantics::Values::Value> incoming_param_otherValue;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_otherValue_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_otherValue = (*incoming_param_otherValue_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::Values::Value> >();
			result = eAny(this->equals(incoming_param_otherValue));
			break;
		}
		
		// 455013808
		case ActionsPackage::RETURNINFORMATION_OPERATION_GETOPERATION:
		{
			result = eAny(this->getOperation());
			break;
		}
		
		// 904744346
		case ActionsPackage::RETURNINFORMATION_OPERATION_GETTYPES:
		{
			result = eAny(this->getTypes());
			break;
		}
		
		// 1466582464
		case ActionsPackage::RETURNINFORMATION_OPERATION_NEW_:
		{
			result = eAny(this->new_());
			break;
		}
		
		// 1070285524
		case ActionsPackage::RETURNINFORMATION_OPERATION_REPLY_PARAMETERVALUE:
		{
			//Retrieve input parameter 'outputParameterValues'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> incoming_param_outputParameterValues;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_outputParameterValues_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_outputParameterValues = (*incoming_param_outputParameterValues_arguments_citer)->get()->get<std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> >();
			this->reply(incoming_param_outputParameterValues);
			break;
		}
		
		// 364086231
		case ActionsPackage::RETURNINFORMATION_OPERATION_SPECIFY:
		{
			result = eAny(this->specify());
			break;
		}
		
		// 352529642
		case ActionsPackage::RETURNINFORMATION_OPERATION_TOSTRING:
		{
			result = eAny(this->toString());
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Values::ValueImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}


std::shared_ptr<fUML::Semantics::Actions::ReturnInformation> ReturnInformationImpl::getThisReturnInformationPtr() const
{
	return m_thisReturnInformationPtr.lock();
}
void ReturnInformationImpl::setThisReturnInformationPtr(std::weak_ptr<fUML::Semantics::Actions::ReturnInformation> thisReturnInformationPtr)
{
	m_thisReturnInformationPtr = thisReturnInformationPtr;
	setThisValuePtr(thisReturnInformationPtr);
}
