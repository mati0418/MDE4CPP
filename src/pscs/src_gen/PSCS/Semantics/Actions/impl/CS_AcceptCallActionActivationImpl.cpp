
#include "PSCS/Semantics/Actions/impl/CS_AcceptCallActionActivationImpl.hpp"

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
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"

//Includes from codegen annotation
#include "PSCS/Semantics/CommonBehavior/CS_EventOccurrence.hpp"
#include "fUML/fUMLFactory.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Actions/ActionsFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Actions/AcceptCallActionActivation.hpp"
#include "fUML/Semantics/Actions/AcceptEventActionEventAccepter.hpp"
#include "uml/Action.hpp"
#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"
#include "fUML/Semantics/Actions/InputPinActivation.hpp"
#include "fUML/Semantics/Actions/OutputPinActivation.hpp"
#include "fUML/Semantics/Actions/PinActivation.hpp"
#include "fUML/Semantics/Activities/Token.hpp"
//Factories and Package includes
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "PSCS/PSCSPackage.hpp"
#include "fUML/Semantics/Actions/ActionsPackage.hpp"
#include "PSCS/Semantics/Actions/ActionsPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "fUML/Semantics/CommonBehavior/CommonBehaviorPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace PSCS::Semantics::Actions;

//*********************************
// Constructor / Destructor
//*********************************
CS_AcceptCallActionActivationImpl::CS_AcceptCallActionActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CS_AcceptCallActionActivationImpl::~CS_AcceptCallActionActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_AcceptCallActionActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
CS_AcceptCallActionActivationImpl::CS_AcceptCallActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:CS_AcceptCallActionActivationImpl()
{
	m_group = par_group;
}

CS_AcceptCallActionActivationImpl::CS_AcceptCallActionActivationImpl(const CS_AcceptCallActionActivationImpl & obj): CS_AcceptCallActionActivationImpl()
{
	*this = obj;
}

CS_AcceptCallActionActivationImpl& CS_AcceptCallActionActivationImpl::operator=(const CS_AcceptCallActionActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Actions::AcceptCallActionActivationImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of CS_AcceptCallActionActivation 
	 * which is generated by the compiler (as CS_AcceptCallActionActivation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//CS_AcceptCallActionActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_AcceptCallActionActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CS_AcceptCallActionActivationImpl::copy() const
{
	std::shared_ptr<CS_AcceptCallActionActivationImpl> element(new CS_AcceptCallActionActivationImpl());
	*element =(*this);
	element->setThisCS_AcceptCallActionActivationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
void CS_AcceptCallActionActivationImpl::accept(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		// If the accepted event occurrence is a CS_EventOccurrence then the wrapped
	// event occurrence is extracted. The acceptance process is the one define
	// by AcceptCallActionActivation defined in fUML.
	if(std::dynamic_pointer_cast<PSCS::Semantics::CommonBehavior::CS_EventOccurrence>(eventOccurrence) != nullptr) {
		fUML::Semantics::Actions::AcceptCallActionActivationImpl::accept((std::dynamic_pointer_cast<PSCS::Semantics::CommonBehavior::CS_EventOccurrence>(eventOccurrence))->getWrappedEventOccurrence());
	}
	else {
		fUML::Semantics::Actions::AcceptCallActionActivationImpl::accept(eventOccurrence);
	}
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
std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> CS_AcceptCallActionActivationImpl::getPinActivation() const
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
std::shared_ptr<ecore::EObject> CS_AcceptCallActionActivationImpl::eContainer() const
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
void CS_AcceptCallActionActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CS_AcceptCallActionActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	fUML::Semantics::Actions::AcceptCallActionActivationImpl::loadAttributes(loadHandler, attr_list);
}

void CS_AcceptCallActionActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Actions::AcceptCallActionActivationImpl::loadNode(nodeName, loadHandler);
}

void CS_AcceptCallActionActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	fUML::Semantics::Actions::AcceptCallActionActivationImpl::resolveReferences(featureID, references);
}

void CS_AcceptCallActionActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Actions::AcceptCallActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::AcceptEventActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Actions::ActionActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Activities::ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void CS_AcceptCallActionActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::Semantics::Actions::ActionsPackage> package = PSCS::Semantics::Actions::ActionsPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> CS_AcceptCallActionActivationImpl::eStaticClass() const
{
	return PSCS::Semantics::Actions::ActionsPackage::eInstance()->getCS_AcceptCallActionActivation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any CS_AcceptCallActionActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Actions::AcceptCallActionActivationImpl::eGet(featureID, resolve, coreType);
}

bool CS_AcceptCallActionActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return fUML::Semantics::Actions::AcceptCallActionActivationImpl::internalEIsSet(featureID);
}

bool CS_AcceptCallActionActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return fUML::Semantics::Actions::AcceptCallActionActivationImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any CS_AcceptCallActionActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// PSCS::Semantics::Actions::CS_AcceptCallActionActivation::accept(fUML::Semantics::CommonBehavior::EventOccurrence): 2027172968
		case ActionsPackage::CS_ACCEPTCALLACTIONACTIVATION_OPERATION_ACCEPT_EVENTOCCURRENCE:
		{
			//Retrieve input parameter 'eventOccurrence'
			//parameter 0
			std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> incoming_param_eventOccurrence;
			std::list<Any>::const_iterator incoming_param_eventOccurrence_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_eventOccurrence = (*incoming_param_eventOccurrence_arguments_citer)->get<std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> >();
			this->accept(incoming_param_eventOccurrence);
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Actions::AcceptCallActionActivationImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<PSCS::Semantics::Actions::CS_AcceptCallActionActivation> CS_AcceptCallActionActivationImpl::getThisCS_AcceptCallActionActivationPtr() const
{
	return m_thisCS_AcceptCallActionActivationPtr.lock();
}
void CS_AcceptCallActionActivationImpl::setThisCS_AcceptCallActionActivationPtr(std::weak_ptr<PSCS::Semantics::Actions::CS_AcceptCallActionActivation> thisCS_AcceptCallActionActivationPtr)
{
	m_thisCS_AcceptCallActionActivationPtr = thisCS_AcceptCallActionActivationPtr;
	setThisAcceptCallActionActivationPtr(thisCS_AcceptCallActionActivationPtr);
}


