#include "uml/impl/AddStructuralFeatureValueActionImpl.hpp"

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
#include "uml/Namespace.hpp"
#include "uml/OutputPin.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuralFeature.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/WriteStructuralFeatureAction.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
AddStructuralFeatureValueActionImpl::AddStructuralFeatureValueActionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

AddStructuralFeatureValueActionImpl::~AddStructuralFeatureValueActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete AddStructuralFeatureValueAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
AddStructuralFeatureValueActionImpl::AddStructuralFeatureValueActionImpl(std::weak_ptr<uml::Activity> par_activity)
:AddStructuralFeatureValueActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
AddStructuralFeatureValueActionImpl::AddStructuralFeatureValueActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:AddStructuralFeatureValueActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
AddStructuralFeatureValueActionImpl::AddStructuralFeatureValueActionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:AddStructuralFeatureValueActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
AddStructuralFeatureValueActionImpl::AddStructuralFeatureValueActionImpl(std::weak_ptr<uml::Element> par_owner)
:AddStructuralFeatureValueActionImpl()
{
	m_owner = par_owner;
}

AddStructuralFeatureValueActionImpl::AddStructuralFeatureValueActionImpl(const AddStructuralFeatureValueActionImpl & obj): AddStructuralFeatureValueActionImpl()
{
	*this = obj;
}

AddStructuralFeatureValueActionImpl& AddStructuralFeatureValueActionImpl::operator=(const AddStructuralFeatureValueActionImpl & obj)
{
	//call overloaded =Operator for each base class
	WriteStructuralFeatureActionImpl::operator=(obj);
	AddStructuralFeatureValueAction::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy AddStructuralFeatureValueAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isReplaceAll = obj.getIsReplaceAll();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'insertAt'
	if(obj.getInsertAt()!=nullptr)
	{
		m_insertAt = std::dynamic_pointer_cast<uml::InputPin>(obj.getInsertAt()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> AddStructuralFeatureValueActionImpl::copy() const
{
	std::shared_ptr<AddStructuralFeatureValueActionImpl> element(new AddStructuralFeatureValueActionImpl());
	*element =(*this);
	element->setThisAddStructuralFeatureValueActionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> AddStructuralFeatureValueActionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getAddStructuralFeatureValueAction_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isReplaceAll
*/
bool AddStructuralFeatureValueActionImpl::getIsReplaceAll() const 
{
	return m_isReplaceAll;
}
void AddStructuralFeatureValueActionImpl::setIsReplaceAll(bool _isReplaceAll)
{
	m_isReplaceAll = _isReplaceAll;
	
} 


//*********************************
// Operations
//*********************************
bool AddStructuralFeatureValueActionImpl::insertAt_pin(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool AddStructuralFeatureValueActionImpl::required_value(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference insertAt
*/
std::shared_ptr<uml::InputPin> AddStructuralFeatureValueActionImpl::getInsertAt() const
{
    return m_insertAt;
}
void AddStructuralFeatureValueActionImpl::setInsertAt(std::shared_ptr<uml::InputPin> _insertAt)
{
    m_insertAt = _insertAt;
	
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> AddStructuralFeatureValueActionImpl::getInGroup() const
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

std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> AddStructuralFeatureValueActionImpl::getInput() const
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

std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> AddStructuralFeatureValueActionImpl::getOutput() const
{
	if(m_output == nullptr)
	{
		/*SubsetUnion*/
		m_output.reset(new SubsetUnion<uml::OutputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_output - SubsetUnion<uml::OutputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOutput()->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_output - SubsetUnion<uml::OutputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_output;
}

std::shared_ptr<Union<uml::Element>> AddStructuralFeatureValueActionImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> AddStructuralFeatureValueActionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> AddStructuralFeatureValueActionImpl::getRedefinedElement() const
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




std::shared_ptr<AddStructuralFeatureValueAction> AddStructuralFeatureValueActionImpl::getThisAddStructuralFeatureValueActionPtr() const
{
	return m_thisAddStructuralFeatureValueActionPtr.lock();
}
void AddStructuralFeatureValueActionImpl::setThisAddStructuralFeatureValueActionPtr(std::weak_ptr<AddStructuralFeatureValueAction> thisAddStructuralFeatureValueActionPtr)
{
	m_thisAddStructuralFeatureValueActionPtr = thisAddStructuralFeatureValueActionPtr;
	setThisWriteStructuralFeatureActionPtr(thisAddStructuralFeatureValueActionPtr);
}
std::shared_ptr<ecore::EObject> AddStructuralFeatureValueActionImpl::eContainer() const
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
Any AddStructuralFeatureValueActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ADDSTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_INSERTAT:
			{
				std::shared_ptr<ecore::EObject> returnValue=getInsertAt();
				return eAny(returnValue); //1531
			}
		case uml::umlPackage::ADDSTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_ISREPLACEALL:
			return eAny(getIsReplaceAll()); //1532
	}
	return WriteStructuralFeatureActionImpl::eGet(featureID, resolve, coreType);
}
bool AddStructuralFeatureValueActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::ADDSTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_INSERTAT:
			return getInsertAt() != nullptr; //1531
		case uml::umlPackage::ADDSTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_ISREPLACEALL:
			return getIsReplaceAll() != false; //1532
	}
	return WriteStructuralFeatureActionImpl::internalEIsSet(featureID);
}
bool AddStructuralFeatureValueActionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ADDSTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_INSERTAT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::InputPin> _insertAt = std::dynamic_pointer_cast<uml::InputPin>(_temp);
			setInsertAt(_insertAt); //1531
			return true;
		}
		case uml::umlPackage::ADDSTRUCTURALFEATUREVALUEACTION_ATTRIBUTE_ISREPLACEALL:
		{
			// BOOST CAST
			bool _isReplaceAll = newValue->get<bool>();
			setIsReplaceAll(_isReplaceAll); //1532
			return true;
		}
	}

	return WriteStructuralFeatureActionImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any AddStructuralFeatureValueActionImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 1609
		case umlPackage::ADDSTRUCTURALFEATUREVALUEACTION_OPERATION_INSERTAT_PIN_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->insertAt_pin(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 1608
		case umlPackage::ADDSTRUCTURALFEATUREVALUEACTION_OPERATION_REQUIRED_VALUE_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->required_value(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = WriteStructuralFeatureActionImpl::eInvoke(operationID, arguments);
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
void AddStructuralFeatureValueActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void AddStructuralFeatureValueActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isReplaceAll");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsReplaceAll(value);
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

	WriteStructuralFeatureActionImpl::loadAttributes(loadHandler, attr_list);
}

void AddStructuralFeatureValueActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("insertAt") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			loadHandler->handleChild(this->getInsertAt()); 

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
	WriteStructuralFeatureActionImpl::loadNode(nodeName, loadHandler);
}

void AddStructuralFeatureValueActionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	WriteStructuralFeatureActionImpl::resolveReferences(featureID, references);
}

void AddStructuralFeatureValueActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	WriteStructuralFeatureActionImpl::saveContent(saveHandler);
	
	StructuralFeatureActionImpl::saveContent(saveHandler);
	
	ActionImpl::saveContent(saveHandler);
	
	ExecutableNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
	
	
}

void AddStructuralFeatureValueActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'insertAt'
		std::shared_ptr<uml::InputPin> insertAt = this->getInsertAt();
		if (insertAt != nullptr)
		{
			saveHandler->addReference(insertAt, "insertAt", insertAt->eClass() != package->getInputPin_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getAddStructuralFeatureValueAction_Attribute_isReplaceAll()) )
		{
			saveHandler->addAttribute("isReplaceAll", this->getIsReplaceAll());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

