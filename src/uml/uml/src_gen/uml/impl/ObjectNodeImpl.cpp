
#include "uml/impl/ObjectNodeImpl.hpp"

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
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"


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
#include "uml/Behavior.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/Namespace.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/State.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/Type.hpp"
#include "uml/TypedElement.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ObjectNodeImpl::ObjectNodeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ObjectNodeImpl::~ObjectNodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ObjectNode "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ObjectNodeImpl::ObjectNodeImpl(std::weak_ptr<uml::Activity> par_activity)
:ObjectNodeImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
ObjectNodeImpl::ObjectNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:ObjectNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
ObjectNodeImpl::ObjectNodeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ObjectNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ObjectNodeImpl::ObjectNodeImpl(std::weak_ptr<uml::Element> par_owner)
:ObjectNodeImpl()
{
	m_owner = par_owner;
}

ObjectNodeImpl::ObjectNodeImpl(const ObjectNodeImpl & obj): ObjectNodeImpl()
{
	*this = obj;
}

ObjectNodeImpl& ObjectNodeImpl::operator=(const ObjectNodeImpl & obj)
{
	//call overloaded =Operator for each base class
	ActivityNodeImpl::operator=(obj);
	TypedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ObjectNode 
	 * which is generated by the compiler (as ObjectNode is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ObjectNode::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ObjectNode "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isControlType = obj.getIsControlType();
	m_ordering = obj.getOrdering();

	//copy references with no containment (soft copy)
	m_inState  = obj.getInState();
	m_selection  = obj.getSelection();
	//Clone references with containment (deep copy)
	//clone reference 'upperBound'
	if(obj.getUpperBound()!=nullptr)
	{
		m_upperBound = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getUpperBound()->copy());
	}
	
	return *this;
}

//*********************************
// Operations
//*********************************
bool ObjectNodeImpl::input_output_parameter(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectNodeImpl::object_flow_edges(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ObjectNodeImpl::selection_behavior(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isControlType */
bool ObjectNodeImpl::getIsControlType() const 
{
	return m_isControlType;
}
void ObjectNodeImpl::setIsControlType(bool _isControlType)
{
	m_isControlType = _isControlType;
	
}

/* Getter & Setter for attribute ordering */
uml::ObjectNodeOrderingKind ObjectNodeImpl::getOrdering() const 
{
	return m_ordering;
}
void ObjectNodeImpl::setOrdering(uml::ObjectNodeOrderingKind _ordering)
{
	m_ordering = _ordering;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference inState */
std::shared_ptr<Bag<uml::State>> ObjectNodeImpl::getInState() const
{
	if(m_inState == nullptr)
	{
		m_inState.reset(new Bag<uml::State>());
		
		
	}
    return m_inState;
}

/* Getter & Setter for reference selection */
std::shared_ptr<uml::Behavior> ObjectNodeImpl::getSelection() const
{
    return m_selection;
}
void ObjectNodeImpl::setSelection(std::shared_ptr<uml::Behavior> _selection)
{
    m_selection = _selection;
	
}

/* Getter & Setter for reference upperBound */
std::shared_ptr<uml::ValueSpecification> ObjectNodeImpl::getUpperBound() const
{
    return m_upperBound;
}
void ObjectNodeImpl::setUpperBound(std::shared_ptr<uml::ValueSpecification> _upperBound)
{
    m_upperBound = _upperBound;
	
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> ObjectNodeImpl::getInGroup() const
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

std::shared_ptr<Union<uml::Element>> ObjectNodeImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ObjectNodeImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ObjectNodeImpl::getRedefinedElement() const
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

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ObjectNodeImpl::eContainer() const
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
// Persistence Functions
//*********************************
void ObjectNodeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ObjectNodeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isControlType");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsControlType(value);
		}

		iter = attr_list.find("ordering");
		if ( iter != attr_list.end() )
		{
			uml::ObjectNodeOrderingKind value = uml::ObjectNodeOrderingKind::FIFO;
			std::string literal = iter->second;
						if (literal == "unordered")
			{
				value = uml::ObjectNodeOrderingKind::UNORDERED;
			}
			else 			if (literal == "ordered")
			{
				value = uml::ObjectNodeOrderingKind::ORDERED;
			}
			else 			if (literal == "LIFO")
			{
				value = uml::ObjectNodeOrderingKind::LIFO;
			}
			else 			if (literal == "FIFO")
			{
				value = uml::ObjectNodeOrderingKind::FIFO;
			}
			this->setOrdering(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("inState");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("inState")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("selection");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("selection")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ActivityNodeImpl::loadAttributes(loadHandler, attr_list);
	TypedElementImpl::loadAttributes(loadHandler, attr_list);
}

void ObjectNodeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("upperBound") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getUpperBound()); 

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
	ActivityNodeImpl::loadNode(nodeName, loadHandler);
	TypedElementImpl::loadNode(nodeName, loadHandler);
}

void ObjectNodeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::OBJECTNODE_ATTRIBUTE_INSTATE:
		{
			std::shared_ptr<Bag<uml::State>> _inState = getInState();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::State>  _r = std::dynamic_pointer_cast<uml::State>(ref);
				if (_r != nullptr)
				{
					_inState->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::OBJECTNODE_ATTRIBUTE_SELECTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Behavior> _selection = std::dynamic_pointer_cast<uml::Behavior>( references.front() );
				setSelection(_selection);
			}
			
			return;
		}
	}
	ActivityNodeImpl::resolveReferences(featureID, references);
	TypedElementImpl::resolveReferences(featureID, references);
}

void ObjectNodeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActivityNodeImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ObjectNodeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'upperBound'
		std::shared_ptr<uml::ValueSpecification> upperBound = this->getUpperBound();
		if (upperBound != nullptr)
		{
			saveHandler->addReference(upperBound, "upperBound", upperBound->eClass() != package->getValueSpecification_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getObjectNode_Attribute_isControlType()) )
		{
			saveHandler->addAttribute("isControlType", this->getIsControlType());
		}

		if ( this->eIsSet(package->getObjectNode_Attribute_ordering()) )
		{
			uml::ObjectNodeOrderingKind value = this->getOrdering();
			std::string literal = "";
			if (value == uml::ObjectNodeOrderingKind::UNORDERED)
			{
				literal = "unordered";
			}
			else if (value == uml::ObjectNodeOrderingKind::ORDERED)
			{
				literal = "ordered";
			}
			else if (value == uml::ObjectNodeOrderingKind::LIFO)
			{
				literal = "LIFO";
			}
			else if (value == uml::ObjectNodeOrderingKind::FIFO)
			{
				literal = "FIFO";
			}
			saveHandler->addAttribute("ordering", literal);
		}
	// Add references
		saveHandler->addReferences<uml::State>("inState", this->getInState());
		saveHandler->addReference(this->getSelection(), "selection", getSelection()->eClass() != uml::umlPackage::eInstance()->getBehavior_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ObjectNodeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getObjectNode_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ObjectNodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::OBJECTNODE_ATTRIBUTE_INSTATE:
		{
			return eAnyBag(getInState(),uml::umlPackage::STATE_CLASS); //16021
		}
		case uml::umlPackage::OBJECTNODE_ATTRIBUTE_ISCONTROLTYPE:
			return eAny(getIsControlType(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //16022
		case uml::umlPackage::OBJECTNODE_ATTRIBUTE_ORDERING:
			return eAny(getOrdering(),uml::umlPackage::OBJECTNODEORDERINGKIND_CLASS,false); //16023
		case uml::umlPackage::OBJECTNODE_ATTRIBUTE_SELECTION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getSelection();
			return eAny(returnValue,uml::umlPackage::BEHAVIOR_CLASS,false); //16024
		}
		case uml::umlPackage::OBJECTNODE_ATTRIBUTE_UPPERBOUND:
		{
			std::shared_ptr<ecore::EObject> returnValue=getUpperBound();
			return eAny(returnValue,uml::umlPackage::VALUESPECIFICATION_CLASS,false); //16025
		}
	}
	Any result;
	result = ActivityNodeImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = TypedElementImpl::eGet(featureID, resolve, coreType);
	return result;
}

bool ObjectNodeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::OBJECTNODE_ATTRIBUTE_INSTATE:
			return getInState() != nullptr; //16021
		case uml::umlPackage::OBJECTNODE_ATTRIBUTE_ISCONTROLTYPE:
			return getIsControlType() != false; //16022
		case uml::umlPackage::OBJECTNODE_ATTRIBUTE_ORDERING:
			return m_ordering != uml::ObjectNodeOrderingKind::FIFO;; //16023
		case uml::umlPackage::OBJECTNODE_ATTRIBUTE_SELECTION:
			return getSelection() != nullptr; //16024
		case uml::umlPackage::OBJECTNODE_ATTRIBUTE_UPPERBOUND:
			return getUpperBound() != nullptr; //16025
	}
	bool result = false;
	result = ActivityNodeImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = TypedElementImpl::internalEIsSet(featureID);
	return result;
}

bool ObjectNodeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::OBJECTNODE_ATTRIBUTE_INSTATE:
		{
			// CAST Any to Bag<uml::State>
			if((newValue->isContainer()) && (uml::umlPackage::STATE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::State>> inStateList= newValue->get<std::shared_ptr<Bag<uml::State>>>();
					std::shared_ptr<Bag<uml::State>> _inState=getInState();
					for(const std::shared_ptr<uml::State> indexInState: *_inState)
					{
						if (inStateList->find(indexInState) == -1)
						{
							_inState->erase(indexInState);
						}
					}

					for(const std::shared_ptr<uml::State> indexInState: *inStateList)
					{
						if (_inState->find(indexInState) == -1)
						{
							_inState->add(indexInState);
						}
					}
				}
				catch(...)
				{
					DEBUG_MESSAGE(std::cout << "invalid Type to set of eAttributes."<< std::endl;)
					return false;
				}
			}
			else
			{
				return false;
			}
			return true;
		}
		case uml::umlPackage::OBJECTNODE_ATTRIBUTE_ISCONTROLTYPE:
		{
			// CAST Any to bool
			bool _isControlType = newValue->get<bool>();
			setIsControlType(_isControlType); //16022
			return true;
		}
		case uml::umlPackage::OBJECTNODE_ATTRIBUTE_ORDERING:
		{
			// CAST Any to uml::ObjectNodeOrderingKind
			uml::ObjectNodeOrderingKind _ordering = newValue->get<uml::ObjectNodeOrderingKind>();
			setOrdering(_ordering); //16023
			return true;
		}
		case uml::umlPackage::OBJECTNODE_ATTRIBUTE_SELECTION:
		{
			// CAST Any to uml::Behavior
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Behavior> _selection = std::dynamic_pointer_cast<uml::Behavior>(_temp);
			setSelection(_selection); //16024
			return true;
		}
		case uml::umlPackage::OBJECTNODE_ATTRIBUTE_UPPERBOUND:
		{
			// CAST Any to uml::ValueSpecification
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _upperBound = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setUpperBound(_upperBound); //16025
			return true;
		}
	}

	bool result = false;
	result = ActivityNodeImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = TypedElementImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// EOperation Invoke
//*********************************
Any ObjectNodeImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// uml::ObjectNode::input_output_parameter(Any, std::map) : bool: 1199944681
		case umlPackage::OBJECTNODE_OPERATION_INPUT_OUTPUT_PARAMETER_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->input_output_parameter(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::ObjectNode::object_flow_edges(Any, std::map) : bool: 987041183
		case umlPackage::OBJECTNODE_OPERATION_OBJECT_FLOW_EDGES_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->object_flow_edges(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::ObjectNode::selection_behavior(Any, std::map) : bool: 1576805400
		case umlPackage::OBJECTNODE_OPERATION_SELECTION_BEHAVIOR_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->selection_behavior(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = TypedElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = ActivityNodeImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::ObjectNode> ObjectNodeImpl::getThisObjectNodePtr() const
{
	return m_thisObjectNodePtr.lock();
}
void ObjectNodeImpl::setThisObjectNodePtr(std::weak_ptr<uml::ObjectNode> thisObjectNodePtr)
{
	m_thisObjectNodePtr = thisObjectNodePtr;
	setThisActivityNodePtr(thisObjectNodePtr);
	setThisTypedElementPtr(thisObjectNodePtr);
}

