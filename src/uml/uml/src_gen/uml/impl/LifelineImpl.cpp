
#include "uml/impl/LifelineImpl.hpp"

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
#include <stdexcept>


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
#include "uml/Comment.hpp"
#include "uml/ConnectableElement.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Interaction.hpp"
#include "uml/InteractionFragment.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/PartDecomposition.hpp"
#include "uml/StringExpression.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
LifelineImpl::LifelineImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

LifelineImpl::~LifelineImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Lifeline "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
LifelineImpl::LifelineImpl(std::weak_ptr<uml::Interaction> par_interaction)
:LifelineImpl()
{
	m_interaction = par_interaction;
	m_namespace = par_interaction;
}

//Additional constructor for the containments back reference
LifelineImpl::LifelineImpl(std::weak_ptr<uml::Namespace> par_namespace)
:LifelineImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
LifelineImpl::LifelineImpl(std::weak_ptr<uml::Element> par_owner)
:LifelineImpl()
{
	m_owner = par_owner;
}

LifelineImpl::LifelineImpl(const LifelineImpl & obj): LifelineImpl()
{
	*this = obj;
}

LifelineImpl& LifelineImpl::operator=(const LifelineImpl & obj)
{
	//call overloaded =Operator for each base class
	NamedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Lifeline 
	 * which is generated by the compiler (as Lifeline is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Lifeline::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Lifeline "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_coveredBy  = obj.getCoveredBy();
	m_decomposedAs  = obj.getDecomposedAs();
	m_interaction  = obj.getInteraction();
	m_represents  = obj.getRepresents();
	//Clone references with containment (deep copy)
	//clone reference 'selector'
	if(obj.getSelector()!=nullptr)
	{
		m_selector = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getSelector()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> LifelineImpl::copy() const
{
	std::shared_ptr<LifelineImpl> element(new LifelineImpl());
	*element =(*this);
	element->setThisLifelinePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool LifelineImpl::interaction_uses_share_lifeline(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool LifelineImpl::same_classifier(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool LifelineImpl::selector_int_or_string(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool LifelineImpl::selector_specified(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference coveredBy */
std::shared_ptr<Bag<uml::InteractionFragment>> LifelineImpl::getCoveredBy() const
{
	if(m_coveredBy == nullptr)
	{
		m_coveredBy.reset(new Bag<uml::InteractionFragment>());
		
		
	}
    return m_coveredBy;
}

/* Getter & Setter for reference decomposedAs */
std::shared_ptr<uml::PartDecomposition> LifelineImpl::getDecomposedAs() const
{
    return m_decomposedAs;
}
void LifelineImpl::setDecomposedAs(std::shared_ptr<uml::PartDecomposition> _decomposedAs)
{
    m_decomposedAs = _decomposedAs;
	
}

/* Getter & Setter for reference interaction */
std::weak_ptr<uml::Interaction> LifelineImpl::getInteraction() const
{
    return m_interaction;
}
void LifelineImpl::setInteraction(std::weak_ptr<uml::Interaction> _interaction)
{
    m_interaction = _interaction;
	
}

/* Getter & Setter for reference represents */
std::shared_ptr<uml::ConnectableElement> LifelineImpl::getRepresents() const
{
    return m_represents;
}
void LifelineImpl::setRepresents(std::shared_ptr<uml::ConnectableElement> _represents)
{
    m_represents = _represents;
	
}

/* Getter & Setter for reference selector */
std::shared_ptr<uml::ValueSpecification> LifelineImpl::getSelector() const
{
    return m_selector;
}
void LifelineImpl::setSelector(std::shared_ptr<uml::ValueSpecification> _selector)
{
    m_selector = _selector;
	
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> LifelineImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> LifelineImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> LifelineImpl::getOwner() const
{
	return m_owner;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> LifelineImpl::eContainer() const
{
	if(auto wp = m_interaction.lock())
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
void LifelineImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LifelineImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("coveredBy");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("coveredBy")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("decomposedAs");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("decomposedAs")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("represents");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("represents")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void LifelineImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("selector") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getSelector()); 

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
	NamedElementImpl::loadNode(nodeName, loadHandler);
}

void LifelineImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::LIFELINE_ATTRIBUTE_COVEREDBY:
		{
			std::shared_ptr<Bag<uml::InteractionFragment>> _coveredBy = getCoveredBy();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::InteractionFragment>  _r = std::dynamic_pointer_cast<uml::InteractionFragment>(ref);
				if (_r != nullptr)
				{
					_coveredBy->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::LIFELINE_ATTRIBUTE_DECOMPOSEDAS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::PartDecomposition> _decomposedAs = std::dynamic_pointer_cast<uml::PartDecomposition>( references.front() );
				setDecomposedAs(_decomposedAs);
			}
			
			return;
		}

		case uml::umlPackage::LIFELINE_ATTRIBUTE_INTERACTION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Interaction> _interaction = std::dynamic_pointer_cast<uml::Interaction>( references.front() );
				setInteraction(_interaction);
			}
			
			return;
		}

		case uml::umlPackage::LIFELINE_ATTRIBUTE_REPRESENTS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ConnectableElement> _represents = std::dynamic_pointer_cast<uml::ConnectableElement>( references.front() );
				setRepresents(_represents);
			}
			
			return;
		}
	}
	NamedElementImpl::resolveReferences(featureID, references);
}

void LifelineImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void LifelineImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'selector'
		std::shared_ptr<uml::ValueSpecification> selector = this->getSelector();
		if (selector != nullptr)
		{
			saveHandler->addReference(selector, "selector", selector->eClass() != package->getValueSpecification_Class());
		}
	// Add references
		saveHandler->addReferences<uml::InteractionFragment>("coveredBy", this->getCoveredBy());
		saveHandler->addReference(this->getDecomposedAs(), "decomposedAs", getDecomposedAs()->eClass() != uml::umlPackage::eInstance()->getPartDecomposition_Class()); 
		saveHandler->addReference(this->getRepresents(), "represents", getRepresents()->eClass() != uml::umlPackage::eInstance()->getConnectableElement_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> LifelineImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getLifeline_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any LifelineImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::LIFELINE_ATTRIBUTE_COVEREDBY:
			return eAnyBag(getCoveredBy(),uml::umlPackage::INTERACTIONFRAGMENT_CLASS); //13213
		case uml::umlPackage::LIFELINE_ATTRIBUTE_DECOMPOSEDAS:
			return eAny(getDecomposedAs(),uml::umlPackage::PARTDECOMPOSITION_CLASS,false); //1329
		case uml::umlPackage::LIFELINE_ATTRIBUTE_INTERACTION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getInteraction().lock();
			return eAny(returnValue,uml::umlPackage::INTERACTION_CLASS,false); //13210
		}
		case uml::umlPackage::LIFELINE_ATTRIBUTE_REPRESENTS:
			return eAny(getRepresents(),uml::umlPackage::CONNECTABLEELEMENT_CLASS,false); //13211
		case uml::umlPackage::LIFELINE_ATTRIBUTE_SELECTOR:
			return eAny(getSelector(),uml::umlPackage::VALUESPECIFICATION_CLASS,false); //13212
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}

bool LifelineImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::LIFELINE_ATTRIBUTE_COVEREDBY:
			return getCoveredBy() != nullptr; //13213
		case uml::umlPackage::LIFELINE_ATTRIBUTE_DECOMPOSEDAS:
			return getDecomposedAs() != nullptr; //1329
		case uml::umlPackage::LIFELINE_ATTRIBUTE_INTERACTION:
			return getInteraction().lock() != nullptr; //13210
		case uml::umlPackage::LIFELINE_ATTRIBUTE_REPRESENTS:
			return getRepresents() != nullptr; //13211
		case uml::umlPackage::LIFELINE_ATTRIBUTE_SELECTOR:
			return getSelector() != nullptr; //13212
	}
	return NamedElementImpl::internalEIsSet(featureID);
}

bool LifelineImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::LIFELINE_ATTRIBUTE_COVEREDBY:
		{
			// CAST Any to Bag<uml::InteractionFragment>
			if((newValue->isContainer()) && (uml::umlPackage::INTERACTIONFRAGMENT_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::InteractionFragment>> coveredByList= newValue->get<std::shared_ptr<Bag<uml::InteractionFragment>>>();
					std::shared_ptr<Bag<uml::InteractionFragment>> _coveredBy=getCoveredBy();
					for(const std::shared_ptr<uml::InteractionFragment> indexCoveredBy: *_coveredBy)
					{
						if (coveredByList->find(indexCoveredBy) == -1)
						{
							_coveredBy->erase(indexCoveredBy);
						}
					}

					for(const std::shared_ptr<uml::InteractionFragment> indexCoveredBy: *coveredByList)
					{
						if (_coveredBy->find(indexCoveredBy) == -1)
						{
							_coveredBy->add(indexCoveredBy);
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
		case uml::umlPackage::LIFELINE_ATTRIBUTE_DECOMPOSEDAS:
		{
			// CAST Any to uml::PartDecomposition
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::PartDecomposition> _decomposedAs = std::dynamic_pointer_cast<uml::PartDecomposition>(_temp);
			setDecomposedAs(_decomposedAs); //1329
			return true;
		}
		case uml::umlPackage::LIFELINE_ATTRIBUTE_INTERACTION:
		{
			// CAST Any to uml::Interaction
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Interaction> _interaction = std::dynamic_pointer_cast<uml::Interaction>(_temp);
			setInteraction(_interaction); //13210
			return true;
		}
		case uml::umlPackage::LIFELINE_ATTRIBUTE_REPRESENTS:
		{
			// CAST Any to uml::ConnectableElement
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ConnectableElement> _represents = std::dynamic_pointer_cast<uml::ConnectableElement>(_temp);
			setRepresents(_represents); //13211
			return true;
		}
		case uml::umlPackage::LIFELINE_ATTRIBUTE_SELECTOR:
		{
			// CAST Any to uml::ValueSpecification
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _selector = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setSelector(_selector); //13212
			return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any LifelineImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// uml::Lifeline::interaction_uses_share_lifeline(Any, std::map) : bool: 1328915244
		case umlPackage::LIFELINE_OPERATION_INTERACTION_USES_SHARE_LIFELINE_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->interaction_uses_share_lifeline(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Lifeline::same_classifier(Any, std::map) : bool: 520184878
		case umlPackage::LIFELINE_OPERATION_SAME_CLASSIFIER_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->same_classifier(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Lifeline::selector_int_or_string(Any, std::map) : bool: 1159498731
		case umlPackage::LIFELINE_OPERATION_SELECTOR_INT_OR_STRING_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->selector_int_or_string(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Lifeline::selector_specified(Any, std::map) : bool: 1628682169
		case umlPackage::LIFELINE_OPERATION_SELECTOR_SPECIFIED_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->selector_specified(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = NamedElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Lifeline> LifelineImpl::getThisLifelinePtr() const
{
	return m_thisLifelinePtr.lock();
}
void LifelineImpl::setThisLifelinePtr(std::weak_ptr<uml::Lifeline> thisLifelinePtr)
{
	m_thisLifelinePtr = thisLifelinePtr;
	setThisNamedElementPtr(thisLifelinePtr);
}


