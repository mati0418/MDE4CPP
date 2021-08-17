#include "uml/impl/ExpansionRegionImpl.hpp"

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
#include "uml/ElementImport.hpp"
#include "uml/ExceptionHandler.hpp"
#include "uml/ExpansionNode.hpp"
#include "uml/InputPin.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/OutputPin.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/Variable.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExpansionRegionImpl::ExpansionRegionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ExpansionRegionImpl::~ExpansionRegionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExpansionRegion "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ExpansionRegionImpl::ExpansionRegionImpl(std::weak_ptr<uml::Activity> par_Activity, const int reference_id)
:ExpansionRegionImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::ACTIVITYNODE_ATTRIBUTE_ACTIVITY:
		m_activity = par_Activity;
		m_owner = par_Activity;
		 return;
	case uml::umlPackage::ACTIVITYGROUP_ATTRIBUTE_INACTIVITY:
		m_inActivity = par_Activity;
		m_owner = par_Activity;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}


//Additional constructor for the containments back reference
ExpansionRegionImpl::ExpansionRegionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:ExpansionRegionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
ExpansionRegionImpl::ExpansionRegionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ExpansionRegionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ExpansionRegionImpl::ExpansionRegionImpl(std::weak_ptr<uml::Element> par_owner)
:ExpansionRegionImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ExpansionRegionImpl::ExpansionRegionImpl(std::weak_ptr<uml::ActivityGroup> par_superGroup)
:ExpansionRegionImpl()
{
	m_superGroup = par_superGroup;
	m_owner = par_superGroup;
}

ExpansionRegionImpl::ExpansionRegionImpl(const ExpansionRegionImpl & obj): ExpansionRegionImpl()
{
	*this = obj;
}

ExpansionRegionImpl& ExpansionRegionImpl::operator=(const ExpansionRegionImpl & obj)
{
	//call overloaded =Operator for each base class
	StructuredActivityNodeImpl::operator=(obj);
	ExpansionRegion::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExpansionRegion "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_mode = obj.getMode();

	//copy references with no containment (soft copy)
	m_inputElement  = obj.getInputElement();
	m_outputElement  = obj.getOutputElement();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ExpansionRegionImpl::copy() const
{
	std::shared_ptr<ExpansionRegionImpl> element(new ExpansionRegionImpl());
	*element =(*this);
	element->setThisExpansionRegionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ExpansionRegionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getExpansionRegion_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute mode
*/
uml::ExpansionKind ExpansionRegionImpl::getMode() const 
{
	return m_mode;
}
void ExpansionRegionImpl::setMode(uml::ExpansionKind _mode)
{
	m_mode = _mode;
	
} 


//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
/*
Getter & Setter for reference inputElement
*/
std::shared_ptr<Bag<uml::ExpansionNode>> ExpansionRegionImpl::getInputElement() const
{
	if(m_inputElement == nullptr)
	{
		m_inputElement.reset(new Bag<uml::ExpansionNode>());
		
		
	}
    return m_inputElement;
}



/*
Getter & Setter for reference outputElement
*/
std::shared_ptr<Bag<uml::ExpansionNode>> ExpansionRegionImpl::getOutputElement() const
{
	if(m_outputElement == nullptr)
	{
		m_outputElement.reset(new Bag<uml::ExpansionNode>());
		
		
	}
    return m_outputElement;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityEdge>> ExpansionRegionImpl::getContainedEdge() const
{
	if(m_containedEdge == nullptr)
	{
		/*Union*/
		m_containedEdge.reset(new Union<uml::ActivityEdge>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_containedEdge - Union<uml::ActivityEdge>()" << std::endl;
		#endif
		
		
	}
	return m_containedEdge;
}

std::shared_ptr<Union<uml::ActivityNode>> ExpansionRegionImpl::getContainedNode() const
{
	if(m_containedNode == nullptr)
	{
		/*Union*/
		m_containedNode.reset(new Union<uml::ActivityNode>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_containedNode - Union<uml::ActivityNode>()" << std::endl;
		#endif
		
		
	}
	return m_containedNode;
}

std::shared_ptr<Union<uml::ActivityGroup>> ExpansionRegionImpl::getInGroup() const
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

std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> ExpansionRegionImpl::getInput() const
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

std::shared_ptr<Union<uml::NamedElement>> ExpansionRegionImpl::getMember() const
{
	if(m_member == nullptr)
	{
		/*Union*/
		m_member.reset(new Union<uml::NamedElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_member - Union<uml::NamedElement>()" << std::endl;
		#endif
		
		
	}
	return m_member;
}

std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> ExpansionRegionImpl::getOutput() const
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

std::shared_ptr<Union<uml::Element>> ExpansionRegionImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> ExpansionRegionImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOwnedMember()->initSubsetUnion(getOwnedElement(), getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement >(getOwnedElement(), getMember())" << std::endl;
		#endif
		
	}
	return m_ownedMember;
}

std::weak_ptr<uml::Element> ExpansionRegionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ExpansionRegionImpl::getRedefinedElement() const
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




std::shared_ptr<ExpansionRegion> ExpansionRegionImpl::getThisExpansionRegionPtr() const
{
	return m_thisExpansionRegionPtr.lock();
}
void ExpansionRegionImpl::setThisExpansionRegionPtr(std::weak_ptr<ExpansionRegion> thisExpansionRegionPtr)
{
	m_thisExpansionRegionPtr = thisExpansionRegionPtr;
	setThisStructuredActivityNodePtr(thisExpansionRegionPtr);
}
std::shared_ptr<ecore::EObject> ExpansionRegionImpl::eContainer() const
{
	if(auto wp = m_activity.lock())
	{
		return wp;
	}
	if(auto wp = m_inActivity.lock())
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

	if(auto wp = m_superGroup.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ExpansionRegionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXPANSIONREGION_ATTRIBUTE_INPUTELEMENT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ExpansionNode>::iterator iter = getInputElement()->begin();
			Bag<uml::ExpansionNode>::iterator end = getInputElement()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //9446			
		}
		case uml::umlPackage::EXPANSIONREGION_ATTRIBUTE_MODE:
			return eAny(getMode()); //9444
		case uml::umlPackage::EXPANSIONREGION_ATTRIBUTE_OUTPUTELEMENT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ExpansionNode>::iterator iter = getOutputElement()->begin();
			Bag<uml::ExpansionNode>::iterator end = getOutputElement()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //9445			
		}
	}
	return StructuredActivityNodeImpl::eGet(featureID, resolve, coreType);
}
bool ExpansionRegionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXPANSIONREGION_ATTRIBUTE_INPUTELEMENT:
			return getInputElement() != nullptr; //9446
		case uml::umlPackage::EXPANSIONREGION_ATTRIBUTE_MODE:
			return m_mode != ExpansionKind::ITERATIVE;; //9444
		case uml::umlPackage::EXPANSIONREGION_ATTRIBUTE_OUTPUTELEMENT:
			return getOutputElement() != nullptr; //9445
	}
	return StructuredActivityNodeImpl::internalEIsSet(featureID);
}
bool ExpansionRegionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::EXPANSIONREGION_ATTRIBUTE_INPUTELEMENT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ExpansionNode>> inputElementList(new Bag<uml::ExpansionNode>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				inputElementList->add(std::dynamic_pointer_cast<uml::ExpansionNode>(*iter));
				iter++;
			}
			
			Bag<uml::ExpansionNode>::iterator iterInputElement = getInputElement()->begin();
			Bag<uml::ExpansionNode>::iterator endInputElement = getInputElement()->end();
			while (iterInputElement != endInputElement)
			{
				if (inputElementList->find(*iterInputElement) == -1)
				{
					getInputElement()->erase(*iterInputElement);
				}
				iterInputElement++;
			}
 
			iterInputElement = inputElementList->begin();
			endInputElement = inputElementList->end();
			while (iterInputElement != endInputElement)
			{
				if (getInputElement()->find(*iterInputElement) == -1)
				{
					getInputElement()->add(*iterInputElement);
				}
				iterInputElement++;			
			}
			return true;
		}
		case uml::umlPackage::EXPANSIONREGION_ATTRIBUTE_MODE:
		{
			// BOOST CAST
			uml::ExpansionKind _mode = newValue->get<uml::ExpansionKind>();
			setMode(_mode); //9444
			return true;
		}
		case uml::umlPackage::EXPANSIONREGION_ATTRIBUTE_OUTPUTELEMENT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ExpansionNode>> outputElementList(new Bag<uml::ExpansionNode>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				outputElementList->add(std::dynamic_pointer_cast<uml::ExpansionNode>(*iter));
				iter++;
			}
			
			Bag<uml::ExpansionNode>::iterator iterOutputElement = getOutputElement()->begin();
			Bag<uml::ExpansionNode>::iterator endOutputElement = getOutputElement()->end();
			while (iterOutputElement != endOutputElement)
			{
				if (outputElementList->find(*iterOutputElement) == -1)
				{
					getOutputElement()->erase(*iterOutputElement);
				}
				iterOutputElement++;
			}
 
			iterOutputElement = outputElementList->begin();
			endOutputElement = outputElementList->end();
			while (iterOutputElement != endOutputElement)
			{
				if (getOutputElement()->find(*iterOutputElement) == -1)
				{
					getOutputElement()->add(*iterOutputElement);
				}
				iterOutputElement++;			
			}
			return true;
		}
	}

	return StructuredActivityNodeImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ExpansionRegionImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = StructuredActivityNodeImpl::eInvoke(operationID, arguments);
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
void ExpansionRegionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ExpansionRegionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("mode");
		if ( iter != attr_list.end() )
		{
			uml::ExpansionKind value = ExpansionKind::ITERATIVE;
			std::string literal = iter->second;
			if (literal == "parallel")
			{
				value = ExpansionKind::PARALLEL;
			}
			else if (literal == "iterative")
			{
				value = ExpansionKind::ITERATIVE;
			}
			else if (literal == "stream")
			{
				value = ExpansionKind::STREAM;
			}
			this->setMode(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("inputElement");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("inputElement")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("outputElement");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("outputElement")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	StructuredActivityNodeImpl::loadAttributes(loadHandler, attr_list);
}

void ExpansionRegionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	StructuredActivityNodeImpl::loadNode(nodeName, loadHandler);
}

void ExpansionRegionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::EXPANSIONREGION_ATTRIBUTE_INPUTELEMENT:
		{
			std::shared_ptr<Bag<uml::ExpansionNode>> _inputElement = getInputElement();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ExpansionNode>  _r = std::dynamic_pointer_cast<uml::ExpansionNode>(ref);
				if (_r != nullptr)
				{
					_inputElement->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::EXPANSIONREGION_ATTRIBUTE_OUTPUTELEMENT:
		{
			std::shared_ptr<Bag<uml::ExpansionNode>> _outputElement = getOutputElement();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ExpansionNode>  _r = std::dynamic_pointer_cast<uml::ExpansionNode>(ref);
				if (_r != nullptr)
				{
					_outputElement->push_back(_r);
				}
			}
			return;
		}
	}
	StructuredActivityNodeImpl::resolveReferences(featureID, references);
}

void ExpansionRegionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	StructuredActivityNodeImpl::saveContent(saveHandler);
	
	ActionImpl::saveContent(saveHandler);
	ActivityGroupImpl::saveContent(saveHandler);
	NamespaceImpl::saveContent(saveHandler);
	
	ExecutableNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
	
	
}

void ExpansionRegionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getExpansionRegion_Attribute_mode()) )
		{
			uml::ExpansionKind value = this->getMode();
			std::string literal = "";
			if (value == ExpansionKind::PARALLEL)
			{
				literal = "parallel";
			}
			else if (value == ExpansionKind::ITERATIVE)
			{
				literal = "iterative";
			}
			else if (value == ExpansionKind::STREAM)
			{
				literal = "stream";
			}
			saveHandler->addAttribute("mode", literal);
		}
	// Add references
		saveHandler->addReferences<uml::ExpansionNode>("inputElement", this->getInputElement());
		saveHandler->addReferences<uml::ExpansionNode>("outputElement", this->getOutputElement());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

