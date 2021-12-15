
#include "uml/impl/InterruptibleActivityRegionImpl.hpp"

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
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Namespace.hpp"
#include "uml/StringExpression.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

InterruptibleActivityRegionImpl::~InterruptibleActivityRegionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InterruptibleActivityRegion "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl(std::weak_ptr<uml::Activity> par_inActivity)
:InterruptibleActivityRegionImpl()
{
	m_inActivity = par_inActivity;
	m_owner = par_inActivity;
}

//Additional constructor for the containments back reference
InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:InterruptibleActivityRegionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl(std::weak_ptr<uml::Element> par_owner)
:InterruptibleActivityRegionImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl(std::weak_ptr<uml::ActivityGroup> par_superGroup)
:InterruptibleActivityRegionImpl()
{
	m_superGroup = par_superGroup;
	m_owner = par_superGroup;
}

InterruptibleActivityRegionImpl::InterruptibleActivityRegionImpl(const InterruptibleActivityRegionImpl & obj): InterruptibleActivityRegionImpl()
{
	*this = obj;
}

InterruptibleActivityRegionImpl& InterruptibleActivityRegionImpl::operator=(const InterruptibleActivityRegionImpl & obj)
{
	//call overloaded =Operator for each base class
	ActivityGroupImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of InterruptibleActivityRegion 
	 * which is generated by the compiler (as InterruptibleActivityRegion is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//InterruptibleActivityRegion::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InterruptibleActivityRegion "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_interruptingEdge  = obj.getInterruptingEdge();
	//Clone references with containment (deep copy)
	//clone reference 'node'
	std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode>> nodeList = obj.getNode();
	if(nodeList)
	{
		/*Subset*/
		m_node.reset(new Subset<uml::ActivityNode, uml::ActivityNode >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode >()" << std::endl;
		#endif
		
		/*Subset*/
		getNode()->initSubset(getContainedNode());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode >(getContainedNode())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ActivityNode> nodeindexElem: *nodeList) 
		{
			std::shared_ptr<uml::ActivityNode> temp = std::dynamic_pointer_cast<uml::ActivityNode>((nodeindexElem)->copy());
			m_node->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr node."<< std::endl;)
	}
	return *this;
}

std::shared_ptr<ecore::EObject> InterruptibleActivityRegionImpl::copy() const
{
	std::shared_ptr<InterruptibleActivityRegionImpl> element(new InterruptibleActivityRegionImpl());
	*element =(*this);
	element->setThisInterruptibleActivityRegionPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool InterruptibleActivityRegionImpl::interrupting_edges(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference interruptingEdge */
std::shared_ptr<Bag<uml::ActivityEdge>> InterruptibleActivityRegionImpl::getInterruptingEdge() const
{
	if(m_interruptingEdge == nullptr)
	{
		m_interruptingEdge.reset(new Bag<uml::ActivityEdge>());
		
		
	}
    return m_interruptingEdge;
}

/* Getter & Setter for reference node */
std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode>> InterruptibleActivityRegionImpl::getNode() const
{
	if(m_node == nullptr)
	{
		/*Subset*/
		m_node.reset(new Subset<uml::ActivityNode, uml::ActivityNode >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode >()" << std::endl;
		#endif
		
		/*Subset*/
		getNode()->initSubset(getContainedNode());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_node - Subset<uml::ActivityNode, uml::ActivityNode >(getContainedNode())" << std::endl;
		#endif
		
	}
    return m_node;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityNode>> InterruptibleActivityRegionImpl::getContainedNode() const
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

std::shared_ptr<Union<uml::Element>> InterruptibleActivityRegionImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> InterruptibleActivityRegionImpl::getOwner() const
{
	return m_owner;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> InterruptibleActivityRegionImpl::eContainer() const
{
	if(auto wp = m_inActivity.lock())
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
// Persistence Functions
//*********************************
void InterruptibleActivityRegionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InterruptibleActivityRegionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("interruptingEdge");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("interruptingEdge")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("node");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("node")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ActivityGroupImpl::loadAttributes(loadHandler, attr_list);
}

void InterruptibleActivityRegionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ActivityGroupImpl::loadNode(nodeName, loadHandler);
}

void InterruptibleActivityRegionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::INTERRUPTIBLEACTIVITYREGION_ATTRIBUTE_INTERRUPTINGEDGE:
		{
			std::shared_ptr<Bag<uml::ActivityEdge>> _interruptingEdge = getInterruptingEdge();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ActivityEdge>  _r = std::dynamic_pointer_cast<uml::ActivityEdge>(ref);
				if (_r != nullptr)
				{
					_interruptingEdge->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::INTERRUPTIBLEACTIVITYREGION_ATTRIBUTE_NODE:
		{
			std::shared_ptr<Subset<uml::ActivityNode, uml::ActivityNode>> _node = getNode();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ActivityNode>  _r = std::dynamic_pointer_cast<uml::ActivityNode>(ref);
				if (_r != nullptr)
				{
					_node->push_back(_r);
				}
			}
			return;
		}
	}
	ActivityGroupImpl::resolveReferences(featureID, references);
}

void InterruptibleActivityRegionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActivityGroupImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void InterruptibleActivityRegionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReferences<uml::ActivityEdge>("interruptingEdge", this->getInterruptingEdge());
		saveHandler->addReferences<uml::ActivityNode>("node", this->getNode());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> InterruptibleActivityRegionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getInterruptibleActivityRegion_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any InterruptibleActivityRegionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::INTERRUPTIBLEACTIVITYREGION_ATTRIBUTE_INTERRUPTINGEDGE:
		{
			return eAnyBag(getInterruptingEdge(),uml::umlPackage::ACTIVITYEDGE_CLASS); //12714
		}
		case uml::umlPackage::INTERRUPTIBLEACTIVITYREGION_ATTRIBUTE_NODE:
		{
			return eAnyBag(getNode(),uml::umlPackage::ACTIVITYNODE_CLASS); //12715
		}
	}
	return ActivityGroupImpl::eGet(featureID, resolve, coreType);
}

bool InterruptibleActivityRegionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::INTERRUPTIBLEACTIVITYREGION_ATTRIBUTE_INTERRUPTINGEDGE:
			return getInterruptingEdge() != nullptr; //12714
		case uml::umlPackage::INTERRUPTIBLEACTIVITYREGION_ATTRIBUTE_NODE:
			return getNode() != nullptr; //12715
	}
	return ActivityGroupImpl::internalEIsSet(featureID);
}

bool InterruptibleActivityRegionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::INTERRUPTIBLEACTIVITYREGION_ATTRIBUTE_INTERRUPTINGEDGE:
		{
			// CAST Any to Bag<uml::ActivityEdge>
			if((newValue->isContainer()) && (uml::umlPackage::ACTIVITYEDGE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::ActivityEdge>> interruptingEdgeList= newValue->get<std::shared_ptr<Bag<uml::ActivityEdge>>>();
					std::shared_ptr<Bag<uml::ActivityEdge>> _interruptingEdge=getInterruptingEdge();
					for(const std::shared_ptr<uml::ActivityEdge> indexInterruptingEdge: *_interruptingEdge)
					{
						if (interruptingEdgeList->find(indexInterruptingEdge) == -1)
						{
							_interruptingEdge->erase(indexInterruptingEdge);
						}
					}

					for(const std::shared_ptr<uml::ActivityEdge> indexInterruptingEdge: *interruptingEdgeList)
					{
						if (_interruptingEdge->find(indexInterruptingEdge) == -1)
						{
							_interruptingEdge->add(indexInterruptingEdge);
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
		case uml::umlPackage::INTERRUPTIBLEACTIVITYREGION_ATTRIBUTE_NODE:
		{
			// CAST Any to Bag<uml::ActivityNode>
			if((newValue->isContainer()) && (uml::umlPackage::ACTIVITYNODE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::ActivityNode>> nodeList= newValue->get<std::shared_ptr<Bag<uml::ActivityNode>>>();
					std::shared_ptr<Bag<uml::ActivityNode>> _node=getNode();
					for(const std::shared_ptr<uml::ActivityNode> indexNode: *_node)
					{
						if (nodeList->find(indexNode) == -1)
						{
							_node->erase(indexNode);
						}
					}

					for(const std::shared_ptr<uml::ActivityNode> indexNode: *nodeList)
					{
						if (_node->find(indexNode) == -1)
						{
							_node->add(indexNode);
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
	}

	return ActivityGroupImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any InterruptibleActivityRegionImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// uml::InterruptibleActivityRegion::interrupting_edges(Any, std::map) : bool: 1423062569
		case umlPackage::INTERRUPTIBLEACTIVITYREGION_OPERATION_INTERRUPTING_EDGES_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->interrupting_edges(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = ActivityGroupImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::InterruptibleActivityRegion> InterruptibleActivityRegionImpl::getThisInterruptibleActivityRegionPtr() const
{
	return m_thisInterruptibleActivityRegionPtr.lock();
}
void InterruptibleActivityRegionImpl::setThisInterruptibleActivityRegionPtr(std::weak_ptr<uml::InterruptibleActivityRegion> thisInterruptibleActivityRegionPtr)
{
	m_thisInterruptibleActivityRegionPtr = thisInterruptibleActivityRegionPtr;
	setThisActivityGroupPtr(thisInterruptibleActivityRegionPtr);
}

