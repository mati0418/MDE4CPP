
#include "uml/impl/TemplateSignatureImpl.hpp"

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


#include "abstractDataTypes/Subset.hpp"


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
#include "uml/Element.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateableElement.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
TemplateSignatureImpl::TemplateSignatureImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

TemplateSignatureImpl::~TemplateSignatureImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete TemplateSignature "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
TemplateSignatureImpl::TemplateSignatureImpl(std::weak_ptr<uml::Element> par_owner)
:TemplateSignatureImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
TemplateSignatureImpl::TemplateSignatureImpl(std::weak_ptr<uml::TemplateableElement> par_template)
:TemplateSignatureImpl()
{
	m_template = par_template;
	m_owner = par_template;
}

TemplateSignatureImpl::TemplateSignatureImpl(const TemplateSignatureImpl & obj): TemplateSignatureImpl()
{
	*this = obj;
}

TemplateSignatureImpl& TemplateSignatureImpl::operator=(const TemplateSignatureImpl & obj)
{
	//call overloaded =Operator for each base class
	ElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of TemplateSignature 
	 * which is generated by the compiler (as TemplateSignature is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//TemplateSignature::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy TemplateSignature "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_parameter  = obj.getParameter();
	m_template  = obj.getTemplate();
	//Clone references with containment (deep copy)
	//clone reference 'ownedParameter'
	std::shared_ptr<Subset<uml::TemplateParameter, uml::Element, uml::TemplateParameter>> ownedParameterList = obj.getOwnedParameter();
	if(ownedParameterList)
	{
		/*Subset*/
		m_ownedParameter.reset(new Subset<uml::TemplateParameter, uml::Element, uml::TemplateParameter >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedParameter - Subset<uml::TemplateParameter, uml::Element, uml::TemplateParameter >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedParameter()->initSubset(getOwnedElement(), getParameter());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameter - Subset<uml::TemplateParameter, uml::Element, uml::TemplateParameter >(getOwnedElement(), getParameter())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::TemplateParameter> ownedParameterindexElem: *ownedParameterList) 
		{
			std::shared_ptr<uml::TemplateParameter> temp = std::dynamic_pointer_cast<uml::TemplateParameter>((ownedParameterindexElem)->copy());
			m_ownedParameter->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr ownedParameter."<< std::endl;)
	}
	/*Subset*/
	getOwnedParameter()->initSubset(getOwnedElement(), getParameter());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedParameter - Subset<uml::TemplateParameter, uml::Element, uml::TemplateParameter >(getOwnedElement(), getParameter())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> TemplateSignatureImpl::copy() const
{
	std::shared_ptr<TemplateSignatureImpl> element(new TemplateSignatureImpl());
	*element =(*this);
	element->setThisTemplateSignaturePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool TemplateSignatureImpl::own_elements(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool TemplateSignatureImpl::unique_parameters(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference ownedParameter */
std::shared_ptr<Subset<uml::TemplateParameter, uml::Element, uml::TemplateParameter>> TemplateSignatureImpl::getOwnedParameter() const
{
	if(m_ownedParameter == nullptr)
	{
		/*Subset*/
		m_ownedParameter.reset(new Subset<uml::TemplateParameter, uml::Element, uml::TemplateParameter >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedParameter - Subset<uml::TemplateParameter, uml::Element, uml::TemplateParameter >()" << std::endl;
		#endif
		
		/*Subset*/
		getOwnedParameter()->initSubset(getOwnedElement(), getParameter());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedParameter - Subset<uml::TemplateParameter, uml::Element, uml::TemplateParameter >(getOwnedElement(), getParameter())" << std::endl;
		#endif
		
	}
    return m_ownedParameter;
}

/* Getter & Setter for reference parameter */

/* Getter & Setter for reference template */
std::weak_ptr<uml::TemplateableElement> TemplateSignatureImpl::getTemplate() const
{
    return m_template;
}
void TemplateSignatureImpl::setTemplate(std::weak_ptr<uml::TemplateableElement> _template)
{
    m_template = _template;
	
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> TemplateSignatureImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> TemplateSignatureImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::TemplateParameter>> TemplateSignatureImpl::getParameter() const
{
	if(m_parameter == nullptr)
	{
		/*Union*/
		m_parameter.reset(new Union<uml::TemplateParameter>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_parameter - Union<uml::TemplateParameter>()" << std::endl;
		#endif
		
		
	}
	return m_parameter;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> TemplateSignatureImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_template.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void TemplateSignatureImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void TemplateSignatureImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("parameter");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("parameter")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ElementImpl::loadAttributes(loadHandler, attr_list);
}

void TemplateSignatureImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("ownedParameter") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "TemplateParameter";
			}
			loadHandler->handleChildContainer<uml::TemplateParameter>(this->getOwnedParameter());  

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
	ElementImpl::loadNode(nodeName, loadHandler);
}

void TemplateSignatureImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATESIGNATURE_ATTRIBUTE_PARAMETER:
		{
			std::shared_ptr<Union<uml::TemplateParameter>> _parameter = getParameter();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::TemplateParameter>  _r = std::dynamic_pointer_cast<uml::TemplateParameter>(ref);
				if (_r != nullptr)
				{
					_parameter->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::TEMPLATESIGNATURE_ATTRIBUTE_TEMPLATE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::TemplateableElement> _template = std::dynamic_pointer_cast<uml::TemplateableElement>( references.front() );
				setTemplate(_template);
			}
			
			return;
		}
	}
	ElementImpl::resolveReferences(featureID, references);
}

void TemplateSignatureImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void TemplateSignatureImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'ownedParameter'
		for (std::shared_ptr<uml::TemplateParameter> ownedParameter : *this->getOwnedParameter()) 
		{
			saveHandler->addReference(ownedParameter, "ownedParameter", ownedParameter->eClass() != package->getTemplateParameter_Class());
		}
	// Add references
		saveHandler->addReferences<uml::TemplateParameter>("parameter", this->getParameter());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> TemplateSignatureImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getTemplateSignature_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any TemplateSignatureImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATESIGNATURE_ATTRIBUTE_OWNEDPARAMETER:
			return eAnyBag(getOwnedParameter(),uml::umlPackage::TEMPLATEPARAMETER_CLASS); //2335
		case uml::umlPackage::TEMPLATESIGNATURE_ATTRIBUTE_PARAMETER:
			return eAnyBag(getParameter(),uml::umlPackage::TEMPLATEPARAMETER_CLASS); //2333
		case uml::umlPackage::TEMPLATESIGNATURE_ATTRIBUTE_TEMPLATE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getTemplate().lock();
			return eAny(returnValue,uml::umlPackage::TEMPLATEABLEELEMENT_CLASS,false); //2334
		}
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}

bool TemplateSignatureImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATESIGNATURE_ATTRIBUTE_OWNEDPARAMETER:
			return getOwnedParameter() != nullptr; //2335
		case uml::umlPackage::TEMPLATESIGNATURE_ATTRIBUTE_PARAMETER:
			return getParameter() != nullptr; //2333
		case uml::umlPackage::TEMPLATESIGNATURE_ATTRIBUTE_TEMPLATE:
			return getTemplate().lock() != nullptr; //2334
	}
	return ElementImpl::internalEIsSet(featureID);
}

bool TemplateSignatureImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::TEMPLATESIGNATURE_ATTRIBUTE_OWNEDPARAMETER:
		{
			// CAST Any to Bag<uml::TemplateParameter>
			if((newValue->isContainer()) && (uml::umlPackage::TEMPLATEPARAMETER_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::TemplateParameter>> ownedParameterList= newValue->get<std::shared_ptr<Bag<uml::TemplateParameter>>>();
					std::shared_ptr<Bag<uml::TemplateParameter>> _ownedParameter=getOwnedParameter();
					for(const std::shared_ptr<uml::TemplateParameter> indexOwnedParameter: *_ownedParameter)
					{
						if (ownedParameterList->find(indexOwnedParameter) == -1)
						{
							_ownedParameter->erase(indexOwnedParameter);
						}
					}

					for(const std::shared_ptr<uml::TemplateParameter> indexOwnedParameter: *ownedParameterList)
					{
						if (_ownedParameter->find(indexOwnedParameter) == -1)
						{
							_ownedParameter->add(indexOwnedParameter);
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
		case uml::umlPackage::TEMPLATESIGNATURE_ATTRIBUTE_PARAMETER:
		{
			// CAST Any to Bag<uml::TemplateParameter>
			if((newValue->isContainer()) && (uml::umlPackage::TEMPLATEPARAMETER_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::TemplateParameter>> parameterList= newValue->get<std::shared_ptr<Bag<uml::TemplateParameter>>>();
					std::shared_ptr<Bag<uml::TemplateParameter>> _parameter=getParameter();
					for(const std::shared_ptr<uml::TemplateParameter> indexParameter: *_parameter)
					{
						if (parameterList->find(indexParameter) == -1)
						{
							_parameter->erase(indexParameter);
						}
					}

					for(const std::shared_ptr<uml::TemplateParameter> indexParameter: *parameterList)
					{
						if (_parameter->find(indexParameter) == -1)
						{
							_parameter->add(indexParameter);
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
		case uml::umlPackage::TEMPLATESIGNATURE_ATTRIBUTE_TEMPLATE:
		{
			// CAST Any to uml::TemplateableElement
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::TemplateableElement> _template = std::dynamic_pointer_cast<uml::TemplateableElement>(_temp);
			setTemplate(_template); //2334
			return true;
		}
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any TemplateSignatureImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// uml::TemplateSignature::own_elements(Any, std::map) : bool: 545793563
		case umlPackage::TEMPLATESIGNATURE_OPERATION_OWN_ELEMENTS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->own_elements(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::TemplateSignature::unique_parameters(Any, std::map) : bool: 1841790268
		case umlPackage::TEMPLATESIGNATURE_OPERATION_UNIQUE_PARAMETERS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->unique_parameters(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = ElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::TemplateSignature> TemplateSignatureImpl::getThisTemplateSignaturePtr() const
{
	return m_thisTemplateSignaturePtr.lock();
}
void TemplateSignatureImpl::setThisTemplateSignaturePtr(std::weak_ptr<uml::TemplateSignature> thisTemplateSignaturePtr)
{
	m_thisTemplateSignaturePtr = thisTemplateSignaturePtr;
	setThisElementPtr(thisTemplateSignaturePtr);
}


