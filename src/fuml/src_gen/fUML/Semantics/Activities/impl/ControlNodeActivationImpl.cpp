#include "fUML/Semantics/Activities/impl/ControlNodeActivationImpl.hpp"

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
 #include "uml/ActivityNode.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Activities/ActivitiesFactory.hpp"


#include "fUML/Semantics/Activities/ActivityEdgeInstance.hpp"
#include "uml/ActivityNode.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivation.hpp"
#include "fUML/Semantics/Activities/ActivityNodeActivationGroup.hpp"
#include "fUML/Semantics/Activities/Token.hpp"

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/Activities/ActivitiesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace fUML::Semantics::Activities;

//*********************************
// Constructor / Destructor
//*********************************
ControlNodeActivationImpl::ControlNodeActivationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ControlNodeActivationImpl::~ControlNodeActivationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ControlNodeActivation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ControlNodeActivationImpl::ControlNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group)
:ControlNodeActivationImpl()
{
	m_group = par_group;
}

ControlNodeActivationImpl::ControlNodeActivationImpl(const ControlNodeActivationImpl & obj): ControlNodeActivationImpl()
{
	*this = obj;
}

ControlNodeActivationImpl& ControlNodeActivationImpl::operator=(const ControlNodeActivationImpl & obj)
{
	//call overloaded =Operator for each base class
	ActivityNodeActivationImpl::operator=(obj);
	ControlNodeActivation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ControlNodeActivation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ControlNodeActivationImpl::copy() const
{
	std::shared_ptr<ControlNodeActivationImpl> element(new ControlNodeActivationImpl());
	*element =(*this);
	element->setThisControlNodeActivationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ControlNodeActivationImpl::eStaticClass() const
{
	return fUML::Semantics::Activities::ActivitiesPackage::eInstance()->getControlNodeActivation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
void ControlNodeActivationImpl::fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    if (this->getNode() != nullptr) {
        DEBUG_MESSAGE(std::cout<<"[fire] Control node " << this->getNode()->getName() << "..."<<std::endl;)
    }

    this->sendOffers(incomingTokens);
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<ControlNodeActivation> ControlNodeActivationImpl::getThisControlNodeActivationPtr() const
{
	return m_thisControlNodeActivationPtr.lock();
}
void ControlNodeActivationImpl::setThisControlNodeActivationPtr(std::weak_ptr<ControlNodeActivation> thisControlNodeActivationPtr)
{
	m_thisControlNodeActivationPtr = thisControlNodeActivationPtr;
	setThisActivityNodeActivationPtr(thisControlNodeActivationPtr);
}
std::shared_ptr<ecore::EObject> ControlNodeActivationImpl::eContainer() const
{
	if(auto wp = m_group.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ControlNodeActivationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ActivityNodeActivationImpl::eGet(featureID, resolve, coreType);
}
bool ControlNodeActivationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ActivityNodeActivationImpl::internalEIsSet(featureID);
}
bool ControlNodeActivationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ActivityNodeActivationImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ControlNodeActivationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 3133
		case ActivitiesPackage::CONTROLNODEACTIVATION_OPERATION_FIRE_TOKEN:
		{
			//Retrieve input parameter 'incomingTokens'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incoming_param_incomingTokens;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_incomingTokens_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_incomingTokens = (*incoming_param_incomingTokens_arguments_citer)->get()->get<std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> >();
			this->fire(incoming_param_incomingTokens);
			break;
		}

		default:
		{
			// call superTypes
			result = ActivityNodeActivationImpl::eInvoke(operationID, arguments);
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
void ControlNodeActivationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ControlNodeActivationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ActivityNodeActivationImpl::loadAttributes(loadHandler, attr_list);
}

void ControlNodeActivationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ActivityNodeActivationImpl::loadNode(nodeName, loadHandler);
}

void ControlNodeActivationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ActivityNodeActivationImpl::resolveReferences(featureID, references);
}

void ControlNodeActivationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActivityNodeActivationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void ControlNodeActivationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::Activities::ActivitiesPackage> package = fUML::Semantics::Activities::ActivitiesPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

