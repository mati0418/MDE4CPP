
#include "fUML/Semantics/Actions/impl/AcceptEventActionActivationImpl.hpp"

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

#include "abstractDataTypes/Subset.hpp"


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "uml/umlFactory.hpp"

#include "fUML/Semantics/Actions/AcceptEventActionEventAccepter.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Actions/ActionActivation.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
AcceptEventActionActivationImpl::AcceptEventActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

AcceptEventActionActivationImpl::~AcceptEventActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete AcceptEventActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
AcceptEventActionActivationImpl::AcceptEventActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:AcceptEventActionActivationImpl()
{
	m_group = par_group;
}

AcceptEventActionActivationImpl::AcceptEventActionActivationImpl(const AcceptEventActionActivationImpl & obj): AcceptEventActionActivationImpl()
{
	*this = obj;
}

AcceptEventActionActivationImpl& AcceptEventActionActivationImpl::operator=(const AcceptEventActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of AcceptEventActionActivation 
	 * which is generated by the compiler (as AcceptEventActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//AcceptEventActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy AcceptEventActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_waiting = obj.isWaiting();

	//copy references with no containment (soft copy)
	m_eventAccepter  = obj.getEventAccepter();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> AcceptEventActionActivationImpl::copy() const
{
	std::shared_ptr<AcceptEventActionActivationImpl> element(new AcceptEventActionActivationImpl());
	*element =(*this);
	element->setThisAcceptEventActionActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void AcceptEventActionActivationImpl::accept(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void AcceptEventActionActivationImpl::doAction()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void AcceptEventActionActivationImpl::fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void AcceptEventActionActivationImpl::initialize(std::shared_ptr<uml::ActivityNode> node,std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> group)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool AcceptEventActionActivationImpl::isReady()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool AcceptEventActionActivationImpl::match(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void AcceptEventActionActivationImpl::run()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void AcceptEventActionActivationImpl::terminate()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute waiting */
bool AcceptEventActionActivationImpl::isWaiting() const 
{
	return m_waiting;
}
void AcceptEventActionActivationImpl::setWaiting(bool _waiting)
{
	m_waiting = _waiting;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference eventAccepter */
std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepter> AcceptEventActionActivationImpl::getEventAccepter() const
{
    return m_eventAccepter;
}
void AcceptEventActionActivationImpl::setEventAccepter(std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepter> _eventAccepter)
{
    m_eventAccepter = _eventAccepter;
	
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> AcceptEventActionActivationImpl::getPinActivation() const
{
	if(m_pinActivation == nullptr)
	{
		/*Union*/
		m_pinActivation.reset(new Union<fUML::Semantics::Actions::PinActivation>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_pinActivation - Union<fUML::Semantics::Actions::PinActivation>()" << std::endl;
		#endif
		
		
	}
	return m_pinActivation;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> AcceptEventActionActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void AcceptEventActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void AcceptEventActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("waiting");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setWaiting(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("eventAccepter");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("eventAccepter")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void AcceptEventActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ActionActivationImpl::loadNode(nodeName, loadHandler);
}

void AcceptEventActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONACTIVATION_ATTRIBUTE_EVENTACCEPTER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepter> _eventAccepter = std::dynamic_pointer_cast<fUML::Semantics::Actions::AcceptEventActionEventAccepter>( references.front() );
				setEventAccepter(_eventAccepter);
			}
			
			return;
		}
	}
	ActionActivationImpl::resolveReferences(featureID, references);
}

void AcceptEventActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void AcceptEventActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Actions::ActionsPackage> package = fUML::Semantics::Actions::ActionsPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getAcceptEventActionActivation_Attribute_waiting()) )
		{
			saveHandler->addAttribute("waiting", this->isWaiting());
		}
	// Add references
		saveHandler->addReference(this->getEventAccepter(), "eventAccepter", getEventAccepter()->eClass() != fUML::Semantics::Actions::ActionsPackage::eInstance()->getAcceptEventActionEventAccepter_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}


std::shared_ptr<ecore::EClass> AcceptEventActionActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Actions::ActionsPackage::eInstance()->getAcceptEventActionActivation_Class();
}


//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any AcceptEventActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONACTIVATION_ATTRIBUTE_EVENTACCEPTER:
			{
				std::shared_ptr<ecore::EObject> returnValue=getEventAccepter();
				return eAny(returnValue); //311
			}
		case fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONACTIVATION_ATTRIBUTE_WAITING:
			return eAny(isWaiting()); //312
	}
	return ActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool AcceptEventActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONACTIVATION_ATTRIBUTE_EVENTACCEPTER:
			return getEventAccepter() != nullptr; //311
		case fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONACTIVATION_ATTRIBUTE_WAITING:
			return isWaiting() != false; //312
	}
	return ActionActivationImpl::internalEIsSet(featureID);
}

bool AcceptEventActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONACTIVATION_ATTRIBUTE_EVENTACCEPTER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionEventAccepter> _eventAccepter = std::dynamic_pointer_cast<fUML::Semantics::Actions::AcceptEventActionEventAccepter>(_temp);
			setEventAccepter(_eventAccepter); //311
			return true;
		}
		case fUML::Semantics::Actions::ActionsPackage::ACCEPTEVENTACTIONACTIVATION_ATTRIBUTE_WAITING:
		{
			// BOOST CAST
			bool _waiting = newValue->get<bool>();
			setWaiting(_waiting); //312
			return true;
		}
	}

	return ActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any AcceptEventActionActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 908096905
		case ActionsPackage::ACCEPTEVENTACTIONACTIVATION_OPERATION_ACCEPT_EVENTOCCURRENCE:
		{
			//Retrieve input parameter 'eventOccurrence'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> incoming_param_eventOccurrence;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_eventOccurrence_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_eventOccurrence = (*incoming_param_eventOccurrence_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> >();
			this->accept(incoming_param_eventOccurrence);
			break;
		}
		
		// 2139307330
		case ActionsPackage::ACCEPTEVENTACTIONACTIVATION_OPERATION_DOACTION:
		{
			this->doAction();
			break;
		}
		
		// 1477585117
		case ActionsPackage::ACCEPTEVENTACTIONACTIVATION_OPERATION_FIRE_TOKEN:
		{
			//Retrieve input parameter 'incomingTokens'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incoming_param_incomingTokens;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_incomingTokens_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_incomingTokens = (*incoming_param_incomingTokens_arguments_citer)->get()->get<std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> >();
			this->fire(incoming_param_incomingTokens);
			break;
		}
		
		// 640030514
		case ActionsPackage::ACCEPTEVENTACTIONACTIVATION_OPERATION_INITIALIZE_ACTIVITYNODE_ACTIVITYNODEACTIVATIONGROUP:
		{
			//Retrieve input parameter 'node'
			//parameter 0
			std::shared_ptr<uml::ActivityNode> incoming_param_node;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_node_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_node = (*incoming_param_node_arguments_citer)->get()->get<std::shared_ptr<uml::ActivityNode> >();
			//Retrieve input parameter 'group'
			//parameter 1
			std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> incoming_param_group;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_group_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_group = (*incoming_param_group_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> >();
			this->initialize(incoming_param_node,incoming_param_group);
			break;
		}
		
		// 1247902812
		case ActionsPackage::ACCEPTEVENTACTIONACTIVATION_OPERATION_ISREADY:
		{
			result = eAny(this->isReady());
			break;
		}
		
		// 1530016891
		case ActionsPackage::ACCEPTEVENTACTIONACTIVATION_OPERATION_MATCH_EVENTOCCURRENCE:
		{
			//Retrieve input parameter 'eventOccurrence'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> incoming_param_eventOccurrence;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_eventOccurrence_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_eventOccurrence = (*incoming_param_eventOccurrence_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> >();
			result = eAny(this->match(incoming_param_eventOccurrence));
			break;
		}
		
		// 1056616233
		case ActionsPackage::ACCEPTEVENTACTIONACTIVATION_OPERATION_RUN:
		{
			this->run();
			break;
		}
		
		// 1685607188
		case ActionsPackage::ACCEPTEVENTACTIONACTIVATION_OPERATION_TERMINATE:
		{
			this->terminate();
			break;
		}

		default:
		{
			// call superTypes
			result = ActionActivationImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}


std::shared_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> AcceptEventActionActivationImpl::getThisAcceptEventActionActivationPtr() const
{
	return m_thisAcceptEventActionActivationPtr.lock();
}
void AcceptEventActionActivationImpl::setThisAcceptEventActionActivationPtr(std::weak_ptr<fUML::Semantics::Actions::AcceptEventActionActivation> thisAcceptEventActionActivationPtr)
{
	m_thisAcceptEventActionActivationPtr = thisAcceptEventActionActivationPtr;
	setThisActionActivationPtr(thisAcceptEventActionActivationPtr);
}
