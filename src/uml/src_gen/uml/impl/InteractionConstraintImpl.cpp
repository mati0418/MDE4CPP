#include "uml/impl/InteractionConstraintImpl.hpp"

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


#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InteractionConstraintImpl::InteractionConstraintImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

InteractionConstraintImpl::~InteractionConstraintImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InteractionConstraint "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
InteractionConstraintImpl::InteractionConstraintImpl(std::weak_ptr<uml::Namespace> par_Namespace, const int reference_id)
:InteractionConstraintImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::CONSTRAINT_ATTRIBUTE_CONTEXT:
		m_context = par_Namespace;
		m_namespace = par_Namespace;
		 return;
	case uml::umlPackage::NAMEDELEMENT_ATTRIBUTE_NAMESPACE:
		m_namespace = par_Namespace;
		m_owner = par_Namespace;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}


//Additional constructor for the containments back reference
InteractionConstraintImpl::InteractionConstraintImpl(std::weak_ptr<uml::Element> par_owner)
:InteractionConstraintImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
InteractionConstraintImpl::InteractionConstraintImpl(std::weak_ptr<uml::Package> par_owningPackage)
:InteractionConstraintImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
InteractionConstraintImpl::InteractionConstraintImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:InteractionConstraintImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

InteractionConstraintImpl::InteractionConstraintImpl(const InteractionConstraintImpl & obj): InteractionConstraintImpl()
{
	*this = obj;
}

InteractionConstraintImpl& InteractionConstraintImpl::operator=(const InteractionConstraintImpl & obj)
{
	//call overloaded =Operator for each base class
	ConstraintImpl::operator=(obj);
	InteractionConstraint::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InteractionConstraint "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	if(obj.getMaxint()!=nullptr)
	{
		m_maxint = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getMaxint()->copy());
	}
	if(obj.getMinint()!=nullptr)
	{
		m_minint = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getMinint()->copy());
	}
	
	
	return *this;
}

std::shared_ptr<ecore::EObject> InteractionConstraintImpl::copy() const
{
	std::shared_ptr<InteractionConstraintImpl> element(new InteractionConstraintImpl());
	*element =(*this);
	element->setThisInteractionConstraintPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> InteractionConstraintImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getInteractionConstraint_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool InteractionConstraintImpl::dynamic_variables(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionConstraintImpl::global_data(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionConstraintImpl::maxint_greater_equal_minint(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionConstraintImpl::maxint_positive(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionConstraintImpl::minint_maxint(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InteractionConstraintImpl::minint_non_negative(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference maxint
*/
std::shared_ptr<uml::ValueSpecification> InteractionConstraintImpl::getMaxint() const
{

    return m_maxint;
}
void InteractionConstraintImpl::setMaxint(std::shared_ptr<uml::ValueSpecification> _maxint)
{
    m_maxint = _maxint;
	
	
}


/*
Getter & Setter for reference minint
*/
std::shared_ptr<uml::ValueSpecification> InteractionConstraintImpl::getMinint() const
{

    return m_minint;
}
void InteractionConstraintImpl::setMinint(std::shared_ptr<uml::ValueSpecification> _minint)
{
    m_minint = _minint;
	
	
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> InteractionConstraintImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> InteractionConstraintImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> InteractionConstraintImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<InteractionConstraint> InteractionConstraintImpl::getThisInteractionConstraintPtr() const
{
	return m_thisInteractionConstraintPtr.lock();
}
void InteractionConstraintImpl::setThisInteractionConstraintPtr(std::weak_ptr<InteractionConstraint> thisInteractionConstraintPtr)
{
	m_thisInteractionConstraintPtr = thisInteractionConstraintPtr;
	setThisConstraintPtr(thisInteractionConstraintPtr);
}
std::shared_ptr<ecore::EObject> InteractionConstraintImpl::eContainer() const
{
	if(auto wp = m_context.lock())
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

	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any InteractionConstraintImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::INTERACTIONCONSTRAINT_ATTRIBUTE_MAXINT:
			{
				std::shared_ptr<ecore::EObject> returnValue=getMaxint();
				return eAny(returnValue); //12015
			}
		case uml::umlPackage::INTERACTIONCONSTRAINT_ATTRIBUTE_MININT:
			{
				std::shared_ptr<ecore::EObject> returnValue=getMinint();
				return eAny(returnValue); //12016
			}
	}
	return ConstraintImpl::eGet(featureID, resolve, coreType);
}
bool InteractionConstraintImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::INTERACTIONCONSTRAINT_ATTRIBUTE_MAXINT:
			return getMaxint() != nullptr; //12015
		case uml::umlPackage::INTERACTIONCONSTRAINT_ATTRIBUTE_MININT:
			return getMinint() != nullptr; //12016
	}
	return ConstraintImpl::internalEIsSet(featureID);
}
bool InteractionConstraintImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::INTERACTIONCONSTRAINT_ATTRIBUTE_MAXINT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _maxint = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setMaxint(_maxint); //12015
			return true;
		}
		case uml::umlPackage::INTERACTIONCONSTRAINT_ATTRIBUTE_MININT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _minint = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setMinint(_minint); //12016
			return true;
		}
	}

	return ConstraintImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any InteractionConstraintImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 12082
		case umlPackage::INTERACTIONCONSTRAINT_OPERATION_DYNAMIC_VARIABLES_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->dynamic_variables(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 12083
		case umlPackage::INTERACTIONCONSTRAINT_OPERATION_GLOBAL_DATA_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->global_data(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 12084
		case umlPackage::INTERACTIONCONSTRAINT_OPERATION_MAXINT_GREATER_EQUAL_MININT_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->maxint_greater_equal_minint(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 12081
		case umlPackage::INTERACTIONCONSTRAINT_OPERATION_MAXINT_POSITIVE_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->maxint_positive(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 12079
		case umlPackage::INTERACTIONCONSTRAINT_OPERATION_MININT_MAXINT_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->minint_maxint(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 12080
		case umlPackage::INTERACTIONCONSTRAINT_OPERATION_MININT_NON_NEGATIVE_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->minint_non_negative(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = ConstraintImpl::eInvoke(operationID, arguments);
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
void InteractionConstraintImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InteractionConstraintImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ConstraintImpl::loadAttributes(loadHandler, attr_list);
}

void InteractionConstraintImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("maxint") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getMaxint()); 

			return; 
		}

		if ( nodeName.compare("minint") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getMinint()); 

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
	ConstraintImpl::loadNode(nodeName, loadHandler);
}

void InteractionConstraintImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ConstraintImpl::resolveReferences(featureID, references);
}

void InteractionConstraintImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ConstraintImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void InteractionConstraintImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'maxint'
		std::shared_ptr<uml::ValueSpecification> maxint = this->getMaxint();
		if (maxint != nullptr)
		{
			saveHandler->addReference(maxint, "maxint", maxint->eClass() != package->getValueSpecification_Class());
		}

		// Save 'minint'
		std::shared_ptr<uml::ValueSpecification> minint = this->getMinint();
		if (minint != nullptr)
		{
			saveHandler->addReference(minint, "minint", minint->eClass() != package->getValueSpecification_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

