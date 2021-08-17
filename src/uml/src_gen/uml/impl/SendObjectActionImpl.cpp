#include "uml/impl/SendObjectActionImpl.hpp"

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


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"


#include "uml/Activity.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ExceptionHandler.hpp"
#include "uml/InputPin.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/InvocationAction.hpp"
#include "uml/Namespace.hpp"
#include "uml/OutputPin.hpp"
#include "uml/Port.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
SendObjectActionImpl::SendObjectActionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

SendObjectActionImpl::~SendObjectActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete SendObjectAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
SendObjectActionImpl::SendObjectActionImpl(std::weak_ptr<uml::Activity> par_activity)
:SendObjectActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
SendObjectActionImpl::SendObjectActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:SendObjectActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
SendObjectActionImpl::SendObjectActionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:SendObjectActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
SendObjectActionImpl::SendObjectActionImpl(std::weak_ptr<uml::Element> par_owner)
:SendObjectActionImpl()
{
	m_owner = par_owner;
}

SendObjectActionImpl::SendObjectActionImpl(const SendObjectActionImpl & obj): SendObjectActionImpl()
{
	*this = obj;
}

SendObjectActionImpl& SendObjectActionImpl::operator=(const SendObjectActionImpl & obj)
{
	//call overloaded =Operator for each base class
	InvocationActionImpl::operator=(obj);
	SendObjectAction::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy SendObjectAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'request'
	if(obj.getRequest()!=nullptr)
	{
		m_request = std::dynamic_pointer_cast<uml::InputPin>(obj.getRequest()->copy());
	}

	//clone reference 'target'
	if(obj.getTarget()!=nullptr)
	{
		m_target = std::dynamic_pointer_cast<uml::InputPin>(obj.getTarget()->copy());
	}
	
	
	return *this;
}

std::shared_ptr<ecore::EObject> SendObjectActionImpl::copy() const
{
	std::shared_ptr<SendObjectActionImpl> element(new SendObjectActionImpl());
	*element =(*this);
	element->setThisSendObjectActionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> SendObjectActionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getSendObjectAction_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool SendObjectActionImpl::type_target_pin(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference request
*/
std::shared_ptr<uml::InputPin> SendObjectActionImpl::getRequest() const
{
    return m_request;
}
void SendObjectActionImpl::setRequest(std::shared_ptr<uml::InputPin> _request)
{
    m_request = _request;
	
}


/*
Getter & Setter for reference target
*/
std::shared_ptr<uml::InputPin> SendObjectActionImpl::getTarget() const
{
    return m_target;
}
void SendObjectActionImpl::setTarget(std::shared_ptr<uml::InputPin> _target)
{
    m_target = _target;
	
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> SendObjectActionImpl::getInGroup() const
{
	if(m_inGroup == nullptr)
	{
		/*Union*/
		m_inGroup.reset(new Union<uml::ActivityGroup>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_inGroup - Union<uml::ActivityGroup>()" << std::endl;
		#endif
		
		
	}
	return m_inGroup;
}

std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> SendObjectActionImpl::getInput() const
{
	if(m_input == nullptr)
	{
		/*SubsetUnion*/
		m_input.reset(new SubsetUnion<uml::InputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getInput()->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_input;
}

std::shared_ptr<Union<uml::Element>> SendObjectActionImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::weak_ptr<uml::Element> SendObjectActionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> SendObjectActionImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}




std::shared_ptr<SendObjectAction> SendObjectActionImpl::getThisSendObjectActionPtr() const
{
	return m_thisSendObjectActionPtr.lock();
}
void SendObjectActionImpl::setThisSendObjectActionPtr(std::weak_ptr<SendObjectAction> thisSendObjectActionPtr)
{
	m_thisSendObjectActionPtr = thisSendObjectActionPtr;
	setThisInvocationActionPtr(thisSendObjectActionPtr);
}
std::shared_ptr<ecore::EObject> SendObjectActionImpl::eContainer() const
{
	if(auto wp = m_activity.lock())
	{
		return wp;
	}

	if(auto wp = m_inStructuredNode.lock())
	{
		return wp;
	}

	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any SendObjectActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::SENDOBJECTACTION_ATTRIBUTE_REQUEST:
			{
				std::shared_ptr<ecore::EObject> returnValue=getRequest();
				return eAny(returnValue); //21229
			}
		case uml::umlPackage::SENDOBJECTACTION_ATTRIBUTE_TARGET:
			{
				std::shared_ptr<ecore::EObject> returnValue=getTarget();
				return eAny(returnValue); //21230
			}
	}
	return InvocationActionImpl::eGet(featureID, resolve, coreType);
}
bool SendObjectActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::SENDOBJECTACTION_ATTRIBUTE_REQUEST:
			return getRequest() != nullptr; //21229
		case uml::umlPackage::SENDOBJECTACTION_ATTRIBUTE_TARGET:
			return getTarget() != nullptr; //21230
	}
	return InvocationActionImpl::internalEIsSet(featureID);
}
bool SendObjectActionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::SENDOBJECTACTION_ATTRIBUTE_REQUEST:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::InputPin> _request = std::dynamic_pointer_cast<uml::InputPin>(_temp);
			setRequest(_request); //21229
			return true;
		}
		case uml::umlPackage::SENDOBJECTACTION_ATTRIBUTE_TARGET:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::InputPin> _target = std::dynamic_pointer_cast<uml::InputPin>(_temp);
			setTarget(_target); //21230
			return true;
		}
	}

	return InvocationActionImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any SendObjectActionImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 21297
		case umlPackage::SENDOBJECTACTION_OPERATION_TYPE_TARGET_PIN_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->type_target_pin(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = InvocationActionImpl::eInvoke(operationID, arguments);
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
void SendObjectActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get umlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void SendObjectActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	InvocationActionImpl::loadAttributes(loadHandler, attr_list);
}

void SendObjectActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("request") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			loadHandler->handleChild(this->getRequest()); 

			return; 
		}

		if ( nodeName.compare("target") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			loadHandler->handleChild(this->getTarget()); 

			return; 
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
	//load BasePackage Nodes
	InvocationActionImpl::loadNode(nodeName, loadHandler);
}

void SendObjectActionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	InvocationActionImpl::resolveReferences(featureID, references);
}

void SendObjectActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	InvocationActionImpl::saveContent(saveHandler);
	
	ActionImpl::saveContent(saveHandler);
	
	ExecutableNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
	
}

void SendObjectActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'request'
		std::shared_ptr<uml::InputPin> request = this->getRequest();
		if (request != nullptr)
		{
			saveHandler->addReference(request, "request", request->eClass() != package->getInputPin_Class());
		}

		// Save 'target'
		std::shared_ptr<uml::InputPin> target = this->getTarget();
		if (target != nullptr)
		{
			saveHandler->addReference(target, "target", target->eClass() != package->getInputPin_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

