
#include "fUML/Semantics/StructuredClassifiers/impl/RedefinitionBasedDispatchStrategyImpl.hpp"

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
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"

//Includes from codegen annotation
#include "abstractDataTypes/Subset.hpp"
#include "uml/umlPackage.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Class.hpp"
#include "uml/Operation.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/Behavior.hpp"
#include "fUML/Semantics/StructuredClassifiers/DispatchStrategy.hpp"
#include "fUML/Semantics/StructuredClassifiers/Object.hpp"
#include "uml/Operation.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::StructuredClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
RedefinitionBasedDispatchStrategyImpl::RedefinitionBasedDispatchStrategyImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

RedefinitionBasedDispatchStrategyImpl::~RedefinitionBasedDispatchStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete RedefinitionBasedDispatchStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


RedefinitionBasedDispatchStrategyImpl::RedefinitionBasedDispatchStrategyImpl(const RedefinitionBasedDispatchStrategyImpl & obj): RedefinitionBasedDispatchStrategyImpl()
{
	*this = obj;
}

RedefinitionBasedDispatchStrategyImpl& RedefinitionBasedDispatchStrategyImpl::operator=(const RedefinitionBasedDispatchStrategyImpl & obj)
{
	//call overloaded =Operator for each base class
	DispatchStrategyImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of RedefinitionBasedDispatchStrategy 
	 * which is generated by the compiler (as RedefinitionBasedDispatchStrategy is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//RedefinitionBasedDispatchStrategy::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy RedefinitionBasedDispatchStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> RedefinitionBasedDispatchStrategyImpl::copy() const
{
	std::shared_ptr<RedefinitionBasedDispatchStrategyImpl> element(new RedefinitionBasedDispatchStrategyImpl());
	*element =(*this);
	element->setThisRedefinitionBasedDispatchStrategyPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool RedefinitionBasedDispatchStrategyImpl::operationsMatch(std::shared_ptr<uml::Operation> ownedOperation,std::shared_ptr<uml::Operation> baseOperation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		bool matches = false;
	if(ownedOperation->matches(baseOperation))
	{
		matches = true;
	}
	else
    {
		unsigned int i = 0;
		while(!matches && i < ownedOperation->getRedefinedOperation()->size())
        {
			matches = this->operationsMatch(ownedOperation->getRedefinedOperation()->at(i), baseOperation);
			i = i + 1;
        }
    }
	return matches;
	//end of body
}

std::shared_ptr<uml::Behavior> RedefinitionBasedDispatchStrategyImpl::retrieveMethod(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> object,std::shared_ptr<uml::Operation> operation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<uml::Behavior> method = DispatchStrategyImpl::retrieveMethod(object, operation);
	unsigned int i = 0;
	while(method == nullptr && (i < object->getTypes()->size()))
	{
		std::shared_ptr<uml::Classifier> type = object->getTypes()->at(i);
		/*
		MDE4CPP specific implementation:
		Normalley. only classes would be taken into account. 
		In MDE4CPP object classes for interfaces also exist. Those are typed by interfaces as well.
		Because of that, interfaces are also taken into account here.
		*/
		unsigned long metaElementID = type->eClass()->getMetaElementID();
		if(metaElementID == uml::umlPackage::CLASS_CLASS || metaElementID == uml::umlPackage::INTERFACE_CLASS)
		{
		std::shared_ptr<Bag<uml::Operation> > memberOperations = type->getAllOperations();
		unsigned int j = 0;
		while(method == nullptr && (j < memberOperations->size()))
		{
			std::shared_ptr<uml::Operation> memberOperation = memberOperations->at(j);
			if(memberOperation != nullptr)
			{	
				if(this->operationsMatch(memberOperation, operation))
				{
					method = memberOperation->getMethod()->at(0);
				}
			}
			j = j + 1;
		}
		}
		i = i + 1;
	}

	return method;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> RedefinitionBasedDispatchStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void RedefinitionBasedDispatchStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void RedefinitionBasedDispatchStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	DispatchStrategyImpl::loadAttributes(loadHandler, attr_list);
}

void RedefinitionBasedDispatchStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	DispatchStrategyImpl::loadNode(nodeName, loadHandler);
}

void RedefinitionBasedDispatchStrategyImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	DispatchStrategyImpl::resolveReferences(featureID, references);
}

void RedefinitionBasedDispatchStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DispatchStrategyImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticStrategyImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void RedefinitionBasedDispatchStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

std::shared_ptr<ecore::EClass> RedefinitionBasedDispatchStrategyImpl::eStaticClass() const
{
	return fUML::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getRedefinitionBasedDispatchStrategy_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any RedefinitionBasedDispatchStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return DispatchStrategyImpl::eGet(featureID, resolve, coreType);
}

bool RedefinitionBasedDispatchStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return DispatchStrategyImpl::internalEIsSet(featureID);
}

bool RedefinitionBasedDispatchStrategyImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return DispatchStrategyImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any RedefinitionBasedDispatchStrategyImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategy::operationsMatch(uml::Operation, uml::Operation) : bool: 1256965492
		case StructuredClassifiersPackage::REDEFINITIONBASEDDISPATCHSTRATEGY_OPERATION_OPERATIONSMATCH_OPERATION_OPERATION:
		{
			//Retrieve input parameter 'ownedOperation'
			//parameter 0
			std::shared_ptr<uml::Operation> incoming_param_ownedOperation;
			std::list<Any>::const_iterator incoming_param_ownedOperation_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_ownedOperation = (*incoming_param_ownedOperation_arguments_citer)->get<std::shared_ptr<uml::Operation> >();
			//Retrieve input parameter 'baseOperation'
			//parameter 1
			std::shared_ptr<uml::Operation> incoming_param_baseOperation;
			std::list<Any>::const_iterator incoming_param_baseOperation_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_baseOperation = (*incoming_param_baseOperation_arguments_citer)->get<std::shared_ptr<uml::Operation> >();
			result = eAny(this->operationsMatch(incoming_param_ownedOperation,incoming_param_baseOperation),0,false);
			break;
		}
		// fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategy::retrieveMethod(fUML::Semantics::StructuredClassifiers::Object, uml::Operation) : uml::Behavior: 2137388834
		case StructuredClassifiersPackage::REDEFINITIONBASEDDISPATCHSTRATEGY_OPERATION_RETRIEVEMETHOD_OBJECT_OPERATION:
		{
			//Retrieve input parameter 'object'
			//parameter 0
			std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> incoming_param_object;
			std::list<Any>::const_iterator incoming_param_object_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_object = (*incoming_param_object_arguments_citer)->get<std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> >();
			//Retrieve input parameter 'operation'
			//parameter 1
			std::shared_ptr<uml::Operation> incoming_param_operation;
			std::list<Any>::const_iterator incoming_param_operation_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_operation = (*incoming_param_operation_arguments_citer)->get<std::shared_ptr<uml::Operation> >();
			result = eAny(this->retrieveMethod(incoming_param_object,incoming_param_operation), uml::umlPackage::BEHAVIOR_CLASS,false);
			break;
		}

		default:
		{
			// call superTypes
			result = DispatchStrategyImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategy> RedefinitionBasedDispatchStrategyImpl::getThisRedefinitionBasedDispatchStrategyPtr() const
{
	return m_thisRedefinitionBasedDispatchStrategyPtr.lock();
}
void RedefinitionBasedDispatchStrategyImpl::setThisRedefinitionBasedDispatchStrategyPtr(std::weak_ptr<fUML::Semantics::StructuredClassifiers::RedefinitionBasedDispatchStrategy> thisRedefinitionBasedDispatchStrategyPtr)
{
	m_thisRedefinitionBasedDispatchStrategyPtr = thisRedefinitionBasedDispatchStrategyPtr;
	setThisDispatchStrategyPtr(thisRedefinitionBasedDispatchStrategyPtr);
}


