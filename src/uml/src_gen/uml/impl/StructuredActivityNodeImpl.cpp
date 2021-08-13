#include "uml/impl/StructuredActivityNodeImpl.hpp"

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


#include "uml/Action.hpp"
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
StructuredActivityNodeImpl::StructuredActivityNodeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

StructuredActivityNodeImpl::~StructuredActivityNodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete StructuredActivityNode "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
StructuredActivityNodeImpl::StructuredActivityNodeImpl(std::weak_ptr<uml::Activity> par_Activity, const int reference_id)
:StructuredActivityNodeImpl()
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
StructuredActivityNodeImpl::StructuredActivityNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:StructuredActivityNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
StructuredActivityNodeImpl::StructuredActivityNodeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:StructuredActivityNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
StructuredActivityNodeImpl::StructuredActivityNodeImpl(std::weak_ptr<uml::Element> par_owner)
:StructuredActivityNodeImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
StructuredActivityNodeImpl::StructuredActivityNodeImpl(std::weak_ptr<uml::ActivityGroup> par_superGroup)
:StructuredActivityNodeImpl()
{
	m_superGroup = par_superGroup;
	m_owner = par_superGroup;
}

StructuredActivityNodeImpl::StructuredActivityNodeImpl(const StructuredActivityNodeImpl & obj): StructuredActivityNodeImpl()
{
	*this = obj;
}

StructuredActivityNodeImpl& StructuredActivityNodeImpl::operator=(const StructuredActivityNodeImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionImpl::operator=(obj);
	NamespaceImpl::operator=(obj);
	ActivityGroupImpl::operator=(obj);
	StructuredActivityNode::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy StructuredActivityNode "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_mustIsolate = obj.getMustIsolate();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::ActivityEdge, uml::ActivityEdge,uml::Element>> edgeContainer = getEdge();
	if(nullptr != edgeContainer )
	{
		int size = edgeContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _edge=(*edgeContainer)[i];
			if(nullptr != _edge)
			{
				edgeContainer->push_back(std::dynamic_pointer_cast<uml::ActivityEdge>(_edge->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container edge."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr edge."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode,uml::Element>> nodeContainer = getNode();
	if(nullptr != nodeContainer )
	{
		int size = nodeContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _node=(*nodeContainer)[i];
			if(nullptr != _node)
			{
				nodeContainer->push_back(std::dynamic_pointer_cast<uml::ActivityNode>(_node->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container node."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr node."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> structuredNodeInputContainer = getStructuredNodeInput();
	if(nullptr != structuredNodeInputContainer )
	{
		int size = structuredNodeInputContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _structuredNodeInput=(*structuredNodeInputContainer)[i];
			if(nullptr != _structuredNodeInput)
			{
				structuredNodeInputContainer->push_back(std::dynamic_pointer_cast<uml::InputPin>(_structuredNodeInput->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container structuredNodeInput."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr structuredNodeInput."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> structuredNodeOutputContainer = getStructuredNodeOutput();
	if(nullptr != structuredNodeOutputContainer )
	{
		int size = structuredNodeOutputContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _structuredNodeOutput=(*structuredNodeOutputContainer)[i];
			if(nullptr != _structuredNodeOutput)
			{
				structuredNodeOutputContainer->push_back(std::dynamic_pointer_cast<uml::OutputPin>(_structuredNodeOutput->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container structuredNodeOutput."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr structuredNodeOutput."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Variable, uml::NamedElement>> variableContainer = getVariable();
	if(nullptr != variableContainer )
	{
		int size = variableContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _variable=(*variableContainer)[i];
			if(nullptr != _variable)
			{
				variableContainer->push_back(std::dynamic_pointer_cast<uml::Variable>(_variable->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container variable."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr variable."<< std::endl;)
	}
	/*Subset*/
	m_edge->initSubset(getContainedEdge(),getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge,uml::Element >(getContainedEdge(),getOwnedElement())" << std::endl;
	#endif
	
	/*Subset*/
	m_node->initSubset(getContainedNode(),getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode,uml::Element >(getContainedNode(),getOwnedElement())" << std::endl;
	#endif
	
	/*Subset*/
	m_structuredNodeInput->initSubset(getInput());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_structuredNodeInput - Subset<uml::InputPin, uml::InputPin >(getInput())" << std::endl;
	#endif
	
	/*Subset*/
	m_structuredNodeOutput->initSubset(getOutput());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_structuredNodeOutput - Subset<uml::OutputPin, uml::OutputPin >(getOutput())" << std::endl;
	#endif
	
	/*Subset*/
	m_variable->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_variable - Subset<uml::Variable, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> StructuredActivityNodeImpl::copy() const
{
	std::shared_ptr<StructuredActivityNodeImpl> element(new StructuredActivityNodeImpl());
	*element =(*this);
	element->setThisStructuredActivityNodePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> StructuredActivityNodeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getStructuredActivityNode_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute mustIsolate
*/
bool StructuredActivityNodeImpl::getMustIsolate() const 
{
	return m_mustIsolate;
}
void StructuredActivityNodeImpl::setMustIsolate(bool _mustIsolate)
{
	m_mustIsolate = _mustIsolate;
	
} 


//*********************************
// Operations
//*********************************
bool StructuredActivityNodeImpl::edges(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StructuredActivityNodeImpl::input_pin_edges(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool StructuredActivityNodeImpl::output_pin_edges(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::ActivityNode> > StructuredActivityNodeImpl::sourceNodes()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::ActivityNode> > StructuredActivityNodeImpl::targetNodes()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference edge
*/
std::shared_ptr<Subset<uml::ActivityEdge, uml::ActivityEdge,uml::Element>> StructuredActivityNodeImpl::getEdge() const
{
	if(m_edge == nullptr)
	{
		/*Subset*/
		m_edge.reset(new Subset<uml::ActivityEdge, uml::ActivityEdge,uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge,uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_edge->initSubset(getContainedEdge(),getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_edge - Subset<uml::ActivityEdge, uml::ActivityEdge,uml::Element >(getContainedEdge(),getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_edge;
}



/*
Getter & Setter for reference node
*/
std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode,uml::Element>> StructuredActivityNodeImpl::getNode() const
{
	if(m_node == nullptr)
	{
		/*Subset*/
		m_node.reset(new Subset<uml::ActivityNode, uml::ActivityNode,uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode,uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_node->initSubset(getContainedNode(),getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode,uml::Element >(getContainedNode(),getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_node;
}



/*
Getter & Setter for reference structuredNodeInput
*/
std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> StructuredActivityNodeImpl::getStructuredNodeInput() const
{
	if(m_structuredNodeInput == nullptr)
	{
		/*Subset*/
		m_structuredNodeInput.reset(new Subset<uml::InputPin, uml::InputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_structuredNodeInput - Subset<uml::InputPin, uml::InputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		m_structuredNodeInput->initSubset(getInput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_structuredNodeInput - Subset<uml::InputPin, uml::InputPin >(getInput())" << std::endl;
		#endif
		
	}

    return m_structuredNodeInput;
}



/*
Getter & Setter for reference structuredNodeOutput
*/
std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> StructuredActivityNodeImpl::getStructuredNodeOutput() const
{
	if(m_structuredNodeOutput == nullptr)
	{
		/*Subset*/
		m_structuredNodeOutput.reset(new Subset<uml::OutputPin, uml::OutputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_structuredNodeOutput - Subset<uml::OutputPin, uml::OutputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		m_structuredNodeOutput->initSubset(getOutput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_structuredNodeOutput - Subset<uml::OutputPin, uml::OutputPin >(getOutput())" << std::endl;
		#endif
		
	}

    return m_structuredNodeOutput;
}



/*
Getter & Setter for reference variable
*/
std::shared_ptr<Subset<uml::Variable, uml::NamedElement>> StructuredActivityNodeImpl::getVariable() const
{
	if(m_variable == nullptr)
	{
		/*Subset*/
		m_variable.reset(new Subset<uml::Variable, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_variable - Subset<uml::Variable, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_variable->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_variable - Subset<uml::Variable, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_variable;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityEdge>> StructuredActivityNodeImpl::getContainedEdge() const
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

std::shared_ptr<Union<uml::ActivityNode>> StructuredActivityNodeImpl::getContainedNode() const
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

std::shared_ptr<Union<uml::ActivityGroup>> StructuredActivityNodeImpl::getInGroup() const
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

std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> StructuredActivityNodeImpl::getInput() const
{
	if(m_input == nullptr)
	{
		/*SubsetUnion*/
		m_input.reset(new SubsetUnion<uml::InputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_input->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_input;
}

std::shared_ptr<Union<uml::NamedElement>> StructuredActivityNodeImpl::getMember() const
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

std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> StructuredActivityNodeImpl::getOutput() const
{
	if(m_output == nullptr)
	{
		/*SubsetUnion*/
		m_output.reset(new SubsetUnion<uml::OutputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_output - SubsetUnion<uml::OutputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_output->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_output - SubsetUnion<uml::OutputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_output;
}

std::shared_ptr<Union<uml::Element>> StructuredActivityNodeImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> StructuredActivityNodeImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_ownedMember->initSubsetUnion(getOwnedElement(),getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >(getOwnedElement(),getMember())" << std::endl;
		#endif
		
	}
	return m_ownedMember;
}

std::weak_ptr<uml::Element> StructuredActivityNodeImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> StructuredActivityNodeImpl::getRedefinedElement() const
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




std::shared_ptr<StructuredActivityNode> StructuredActivityNodeImpl::getThisStructuredActivityNodePtr() const
{
	return m_thisStructuredActivityNodePtr.lock();
}
void StructuredActivityNodeImpl::setThisStructuredActivityNodePtr(std::weak_ptr<StructuredActivityNode> thisStructuredActivityNodePtr)
{
	m_thisStructuredActivityNodePtr = thisStructuredActivityNodePtr;
	setThisActionPtr(thisStructuredActivityNodePtr);
	setThisActivityGroupPtr(thisStructuredActivityNodePtr);
	setThisNamespacePtr(thisStructuredActivityNodePtr);
}
std::shared_ptr<ecore::EObject> StructuredActivityNodeImpl::eContainer() const
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
Any StructuredActivityNodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_EDGE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityEdge>::iterator iter = getEdge()->begin();
			Bag<uml::ActivityEdge>::iterator end = getEdge()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22738			
		}
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_MUSTISOLATE:
			return eAny(getMustIsolate()); //22739
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_NODE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityNode>::iterator iter = getNode()->begin();
			Bag<uml::ActivityNode>::iterator end = getNode()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22743			
		}
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEINPUT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::InputPin>::iterator iter = getStructuredNodeInput()->begin();
			Bag<uml::InputPin>::iterator end = getStructuredNodeInput()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22740			
		}
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEOUTPUT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::OutputPin>::iterator iter = getStructuredNodeOutput()->begin();
			Bag<uml::OutputPin>::iterator end = getStructuredNodeOutput()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22741			
		}
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_VARIABLE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Variable>::iterator iter = getVariable()->begin();
			Bag<uml::Variable>::iterator end = getVariable()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //22742			
		}
	}
	Any result;
	result = ActionImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = ActivityGroupImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = NamespaceImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool StructuredActivityNodeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_EDGE:
			return getEdge() != nullptr; //22738
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_MUSTISOLATE:
			return getMustIsolate() != false; //22739
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_NODE:
			return getNode() != nullptr; //22743
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEINPUT:
			return getStructuredNodeInput() != nullptr; //22740
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEOUTPUT:
			return getStructuredNodeOutput() != nullptr; //22741
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_VARIABLE:
			return getVariable() != nullptr; //22742
	}
	bool result = false;
	result = ActionImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = ActivityGroupImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = NamespaceImpl::internalEIsSet(featureID);
	return result;
}
bool StructuredActivityNodeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_EDGE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityEdge>> edgeList(new Bag<uml::ActivityEdge>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				edgeList->add(std::dynamic_pointer_cast<uml::ActivityEdge>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityEdge>::iterator iterEdge = getEdge()->begin();
			Bag<uml::ActivityEdge>::iterator endEdge = getEdge()->end();
			while (iterEdge != endEdge)
			{
				if (edgeList->find(*iterEdge) == -1)
				{
					getEdge()->erase(*iterEdge);
				}
				iterEdge++;
			}
 
			iterEdge = edgeList->begin();
			endEdge = edgeList->end();
			while (iterEdge != endEdge)
			{
				if (getEdge()->find(*iterEdge) == -1)
				{
					getEdge()->add(*iterEdge);
				}
				iterEdge++;			
			}
			return true;
		}
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_MUSTISOLATE:
		{
			// BOOST CAST
			bool _mustIsolate = newValue->get<bool>();
			setMustIsolate(_mustIsolate); //22739
			return true;
		}
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_NODE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityNode>> nodeList(new Bag<uml::ActivityNode>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				nodeList->add(std::dynamic_pointer_cast<uml::ActivityNode>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityNode>::iterator iterNode = getNode()->begin();
			Bag<uml::ActivityNode>::iterator endNode = getNode()->end();
			while (iterNode != endNode)
			{
				if (nodeList->find(*iterNode) == -1)
				{
					getNode()->erase(*iterNode);
				}
				iterNode++;
			}
 
			iterNode = nodeList->begin();
			endNode = nodeList->end();
			while (iterNode != endNode)
			{
				if (getNode()->find(*iterNode) == -1)
				{
					getNode()->add(*iterNode);
				}
				iterNode++;			
			}
			return true;
		}
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEINPUT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::InputPin>> structuredNodeInputList(new Bag<uml::InputPin>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				structuredNodeInputList->add(std::dynamic_pointer_cast<uml::InputPin>(*iter));
				iter++;
			}
			
			Bag<uml::InputPin>::iterator iterStructuredNodeInput = getStructuredNodeInput()->begin();
			Bag<uml::InputPin>::iterator endStructuredNodeInput = getStructuredNodeInput()->end();
			while (iterStructuredNodeInput != endStructuredNodeInput)
			{
				if (structuredNodeInputList->find(*iterStructuredNodeInput) == -1)
				{
					getStructuredNodeInput()->erase(*iterStructuredNodeInput);
				}
				iterStructuredNodeInput++;
			}
 
			iterStructuredNodeInput = structuredNodeInputList->begin();
			endStructuredNodeInput = structuredNodeInputList->end();
			while (iterStructuredNodeInput != endStructuredNodeInput)
			{
				if (getStructuredNodeInput()->find(*iterStructuredNodeInput) == -1)
				{
					getStructuredNodeInput()->add(*iterStructuredNodeInput);
				}
				iterStructuredNodeInput++;			
			}
			return true;
		}
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_STRUCTUREDNODEOUTPUT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::OutputPin>> structuredNodeOutputList(new Bag<uml::OutputPin>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				structuredNodeOutputList->add(std::dynamic_pointer_cast<uml::OutputPin>(*iter));
				iter++;
			}
			
			Bag<uml::OutputPin>::iterator iterStructuredNodeOutput = getStructuredNodeOutput()->begin();
			Bag<uml::OutputPin>::iterator endStructuredNodeOutput = getStructuredNodeOutput()->end();
			while (iterStructuredNodeOutput != endStructuredNodeOutput)
			{
				if (structuredNodeOutputList->find(*iterStructuredNodeOutput) == -1)
				{
					getStructuredNodeOutput()->erase(*iterStructuredNodeOutput);
				}
				iterStructuredNodeOutput++;
			}
 
			iterStructuredNodeOutput = structuredNodeOutputList->begin();
			endStructuredNodeOutput = structuredNodeOutputList->end();
			while (iterStructuredNodeOutput != endStructuredNodeOutput)
			{
				if (getStructuredNodeOutput()->find(*iterStructuredNodeOutput) == -1)
				{
					getStructuredNodeOutput()->add(*iterStructuredNodeOutput);
				}
				iterStructuredNodeOutput++;			
			}
			return true;
		}
		case uml::umlPackage::STRUCTUREDACTIVITYNODE_ATTRIBUTE_VARIABLE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Variable>> variableList(new Bag<uml::Variable>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				variableList->add(std::dynamic_pointer_cast<uml::Variable>(*iter));
				iter++;
			}
			
			Bag<uml::Variable>::iterator iterVariable = getVariable()->begin();
			Bag<uml::Variable>::iterator endVariable = getVariable()->end();
			while (iterVariable != endVariable)
			{
				if (variableList->find(*iterVariable) == -1)
				{
					getVariable()->erase(*iterVariable);
				}
				iterVariable++;
			}
 
			iterVariable = variableList->begin();
			endVariable = variableList->end();
			while (iterVariable != endVariable)
			{
				if (getVariable()->find(*iterVariable) == -1)
				{
					getVariable()->add(*iterVariable);
				}
				iterVariable++;			
			}
			return true;
		}
	}

	bool result = false;
	result = ActionImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = ActivityGroupImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = NamespaceImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Behavioral Feature
//*********************************
Any StructuredActivityNodeImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 22827
		case umlPackage::STRUCTUREDACTIVITYNODE_OPERATION_EDGES_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->edges(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 22828
		case umlPackage::STRUCTUREDACTIVITYNODE_OPERATION_INPUT_PIN_EDGES_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->input_pin_edges(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 22826
		case umlPackage::STRUCTUREDACTIVITYNODE_OPERATION_OUTPUT_PIN_EDGES_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->output_pin_edges(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 22829
		case umlPackage::STRUCTUREDACTIVITYNODE_OPERATION_SOURCENODES:
		{
			result = eAny(this->sourceNodes());
			break;
		}
		
		// 22830
		case umlPackage::STRUCTUREDACTIVITYNODE_OPERATION_TARGETNODES:
		{
			result = eAny(this->targetNodes());
			break;
		}

		default:
		{
			// call superTypes
			result = ActivityGroupImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = NamespaceImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = ActionImpl::eInvoke(operationID, arguments);
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
void StructuredActivityNodeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void StructuredActivityNodeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("mustIsolate");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setMustIsolate(value);
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

	ActionImpl::loadAttributes(loadHandler, attr_list);
	ActivityGroupImpl::loadAttributes(loadHandler, attr_list);
	NamespaceImpl::loadAttributes(loadHandler, attr_list);
}

void StructuredActivityNodeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("edge") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::ActivityEdge>(this->getEdge());  

			return; 
		}

		if ( nodeName.compare("node") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::ActivityNode>(this->getNode());  

			return; 
		}

		if ( nodeName.compare("structuredNodeInput") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			loadHandler->handleChildContainer<uml::InputPin>(this->getStructuredNodeInput());  

			return; 
		}

		if ( nodeName.compare("structuredNodeOutput") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "OutputPin";
			}
			loadHandler->handleChildContainer<uml::OutputPin>(this->getStructuredNodeOutput());  

			return; 
		}

		if ( nodeName.compare("variable") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Variable";
			}
			loadHandler->handleChildContainer<uml::Variable>(this->getVariable());  

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
	ActionImpl::loadNode(nodeName, loadHandler);
	ActivityGroupImpl::loadNode(nodeName, loadHandler);
	NamespaceImpl::loadNode(nodeName, loadHandler);
}

void StructuredActivityNodeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ActionImpl::resolveReferences(featureID, references);
	ActivityGroupImpl::resolveReferences(featureID, references);
	NamespaceImpl::resolveReferences(featureID, references);
}

void StructuredActivityNodeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

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

void StructuredActivityNodeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'edge'
		for (std::shared_ptr<uml::ActivityEdge> edge : *this->getEdge()) 
		{
			saveHandler->addReference(edge, "edge", edge->eClass() != package->getActivityEdge_Class());
		}

		// Save 'node'
		for (std::shared_ptr<uml::ActivityNode> node : *this->getNode()) 
		{
			saveHandler->addReference(node, "node", node->eClass() != package->getActivityNode_Class());
		}

		// Save 'structuredNodeInput'
		for (std::shared_ptr<uml::InputPin> structuredNodeInput : *this->getStructuredNodeInput()) 
		{
			saveHandler->addReference(structuredNodeInput, "structuredNodeInput", structuredNodeInput->eClass() != package->getInputPin_Class());
		}

		// Save 'structuredNodeOutput'
		for (std::shared_ptr<uml::OutputPin> structuredNodeOutput : *this->getStructuredNodeOutput()) 
		{
			saveHandler->addReference(structuredNodeOutput, "structuredNodeOutput", structuredNodeOutput->eClass() != package->getOutputPin_Class());
		}

		// Save 'variable'
		for (std::shared_ptr<uml::Variable> variable : *this->getVariable()) 
		{
			saveHandler->addReference(variable, "variable", variable->eClass() != package->getVariable_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getStructuredActivityNode_Attribute_mustIsolate()) )
		{
			saveHandler->addAttribute("mustIsolate", this->getMustIsolate());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

