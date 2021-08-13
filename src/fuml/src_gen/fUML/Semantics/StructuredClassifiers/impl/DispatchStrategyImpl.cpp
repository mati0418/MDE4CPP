#include "fUML/Semantics/StructuredClassifiers/impl/DispatchStrategyImpl.hpp"

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



#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation
#include "abstractDataTypes/Bag.hpp"
#include "fUML/Semantics/Loci/ExecutionFactory.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence


#include "uml/Behavior.hpp"
#include "fUML/Semantics/CommonBehavior/Execution.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
#include "uml/Operation.hpp"
#include "fUML/Semantics/Loci/SemanticStrategy.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::StructuredClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
DispatchStrategyImpl::DispatchStrategyImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DispatchStrategyImpl::~DispatchStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DispatchStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


DispatchStrategyImpl::DispatchStrategyImpl(const DispatchStrategyImpl & obj): DispatchStrategyImpl()
{
	*this = obj;
}

DispatchStrategyImpl& DispatchStrategyImpl::operator=(const DispatchStrategyImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Loci::SemanticStrategyImpl::operator=(obj);
	DispatchStrategy::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DispatchStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> DispatchStrategyImpl::copy() const
{
	std::shared_ptr<DispatchStrategyImpl> element(new DispatchStrategyImpl());
	*element =(*this);
	element->setThisDispatchStrategyPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> DispatchStrategyImpl::eStaticClass() const
{
	return fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getDispatchStrategy_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> DispatchStrategyImpl::dispatch(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> object,std::shared_ptr<uml::Operation> operation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    return object->getLocus()->getFactory()->createExecution(this->retrieveMethod(object,operation),object);
	//end of body
}

std::string DispatchStrategyImpl::getName()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return "dispatch";
	//end of body
}

std::shared_ptr<uml::Behavior> DispatchStrategyImpl::retrieveMethod(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> object,std::shared_ptr<uml::Operation> operation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	if (operation->getMethod()->size() > 0)
	{
		return operation->getMethod()->front();
	}
	else
	{
		return nullptr;
	}
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<DispatchStrategy> DispatchStrategyImpl::getThisDispatchStrategyPtr() const
{
	return m_thisDispatchStrategyPtr.lock();
}
void DispatchStrategyImpl::setThisDispatchStrategyPtr(std::weak_ptr<DispatchStrategy> thisDispatchStrategyPtr)
{
	m_thisDispatchStrategyPtr = thisDispatchStrategyPtr;
	setThisSemanticStrategyPtr(thisDispatchStrategyPtr);
}
std::shared_ptr<ecore::EObject> DispatchStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any DispatchStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Loci::SemanticStrategyImpl::eGet(featureID, resolve, coreType);
}
bool DispatchStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Loci::SemanticStrategyImpl::internalEIsSet(featureID);
}
bool DispatchStrategyImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Loci::SemanticStrategyImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any DispatchStrategyImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 4001
		case StructuredClassifiersPackage::DISPATCHSTRATEGY_OPERATION_DISPATCH_OBJECT_OPERATION:
		{
			//Retrieve input parameter 'object'
			//parameter 0
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> incoming_param_object;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_object_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_object = (*incoming_param_object_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> >();
			//Retrieve input parameter 'operation'
			//parameter 1
			std::shared_ptr<uml::Operation> incoming_param_operation;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_operation_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_operation = (*incoming_param_operation_arguments_citer)->get()->get<std::shared_ptr<uml::Operation> >();
			result = eAny(this->dispatch(incoming_param_object,incoming_param_operation));
			break;
		}
		
		// 4003
		case StructuredClassifiersPackage::DISPATCHSTRATEGY_OPERATION_GETNAME:
		{
			result = eAny(this->getName());
			break;
		}
		
		// 4002
		case StructuredClassifiersPackage::DISPATCHSTRATEGY_OPERATION_RETRIEVEMETHOD_OBJECT_OPERATION:
		{
			//Retrieve input parameter 'object'
			//parameter 0
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> incoming_param_object;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_object_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_object = (*incoming_param_object_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> >();
			//Retrieve input parameter 'operation'
			//parameter 1
			std::shared_ptr<uml::Operation> incoming_param_operation;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_operation_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_operation = (*incoming_param_operation_arguments_citer)->get()->get<std::shared_ptr<uml::Operation> >();
			result = eAny(this->retrieveMethod(incoming_param_object,incoming_param_operation));
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Loci::SemanticStrategyImpl::eInvoke(operationID, arguments);
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
void DispatchStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DispatchStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Loci::SemanticStrategyImpl::loadAttributes(loadHandler, attr_list);
}

void DispatchStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Loci::SemanticStrategyImpl::loadNode(nodeName, loadHandler);
}

void DispatchStrategyImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Loci::SemanticStrategyImpl::resolveReferences(featureID, references);
}

void DispatchStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Loci::SemanticStrategyImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
}

void DispatchStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage> package = fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

