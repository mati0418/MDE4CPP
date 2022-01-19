
#include "ecore/impl/EStructuralFeatureImpl.hpp"

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
#include "ecore/ecoreFactory.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/EObject.hpp"
#include "ecore/ETypedElement.hpp"
//Factories and Package includes
#include "ecore/ecorePackage.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EStructuralFeatureImpl::EStructuralFeatureImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EStructuralFeatureImpl::~EStructuralFeatureImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EStructuralFeature "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EStructuralFeatureImpl::EStructuralFeatureImpl(std::weak_ptr<ecore::EObject> par_eContainer)
:EStructuralFeatureImpl()
{
	m_eContainer = par_eContainer;
}

//Additional constructor for the containments back reference
EStructuralFeatureImpl::EStructuralFeatureImpl(std::weak_ptr<ecore::EClass> par_eContainingClass)
:EStructuralFeatureImpl()
{
	m_eContainingClass = par_eContainingClass;
}

EStructuralFeatureImpl::EStructuralFeatureImpl(const EStructuralFeatureImpl & obj): EStructuralFeatureImpl()
{
	*this = obj;
}

EStructuralFeatureImpl& EStructuralFeatureImpl::operator=(const EStructuralFeatureImpl & obj)
{
	//call overloaded =Operator for each base class
	ETypedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EStructuralFeature 
	 * which is generated by the compiler (as EStructuralFeature is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EStructuralFeature::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EStructuralFeature "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_changeable = obj.isChangeable();
	m_defaultValue = obj.getDefaultValue();
	m_defaultValueLiteral = obj.getDefaultValueLiteral();
	m_derived = obj.isDerived();
	m_featureID = obj.getFeatureID();
	m_transient = obj.isTransient();
	m_unsettable = obj.isUnsettable();
	m_volatile = obj.isVolatile();

	//copy references with no containment (soft copy)
	m_eContainingClass  = obj.getEContainingClass();
	//Clone references with containment (deep copy)
	return *this;
}

//*********************************
// Operations
//*********************************
void * EStructuralFeatureImpl::getContainerClass()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}



//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute changeable */
bool EStructuralFeatureImpl::isChangeable() const 
{
	return m_changeable;
}
void EStructuralFeatureImpl::setChangeable(bool _changeable)
{
	m_changeable = _changeable;
	
}

/* Getter & Setter for attribute defaultValue */
Any EStructuralFeatureImpl::getDefaultValue() const 
{
	return m_defaultValue;
}
void EStructuralFeatureImpl::setDefaultValue(Any _defaultValue)
{
	m_defaultValue = _defaultValue;
	
}

/* Getter & Setter for attribute defaultValueLiteral */
std::string EStructuralFeatureImpl::getDefaultValueLiteral() const 
{
	return m_defaultValueLiteral;
}
void EStructuralFeatureImpl::setDefaultValueLiteral(std::string _defaultValueLiteral)
{
	m_defaultValueLiteral = _defaultValueLiteral;
	
}

/* Getter & Setter for attribute derived */
bool EStructuralFeatureImpl::isDerived() const 
{
	return m_derived;
}
void EStructuralFeatureImpl::setDerived(bool _derived)
{
	m_derived = _derived;
	
}

/* Getter & Setter for attribute featureID */
int EStructuralFeatureImpl::getFeatureID() const 
{
	return m_featureID;
}
void EStructuralFeatureImpl::setFeatureID(int _featureID)
{
	m_featureID = _featureID;
	
}

/* Getter & Setter for attribute transient */
bool EStructuralFeatureImpl::isTransient() const 
{
	return m_transient;
}
void EStructuralFeatureImpl::setTransient(bool _transient)
{
	m_transient = _transient;
	
}

/* Getter & Setter for attribute unsettable */
bool EStructuralFeatureImpl::isUnsettable() const 
{
	return m_unsettable;
}
void EStructuralFeatureImpl::setUnsettable(bool _unsettable)
{
	m_unsettable = _unsettable;
	
}

/* Getter & Setter for attribute volatile */
bool EStructuralFeatureImpl::isVolatile() const 
{
	return m_volatile;
}
void EStructuralFeatureImpl::setVolatile(bool _volatile)
{
	m_volatile = _volatile;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference eContainingClass */
std::weak_ptr<ecore::EClass> EStructuralFeatureImpl::getEContainingClass() const
{
    return m_eContainingClass;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EStructuralFeatureImpl::getEContentUnion() const
{
	if(m_eContentUnion == nullptr)
	{
		/*Union*/
		m_eContentUnion.reset(new Union<ecore::EObject>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_eContentUnion - Union<ecore::EObject>()" << std::endl;
		#endif
		
		
	}
	return m_eContentUnion;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> EStructuralFeatureImpl::eContainer() const
{
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}

	if(auto wp = m_eContainingClass.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void EStructuralFeatureImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get ecoreFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void EStructuralFeatureImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("changeable");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setChangeable(value);
		}

		iter = attr_list.find("defaultValueLiteral");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setDefaultValueLiteral(value);
		}

		iter = attr_list.find("derived");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setDerived(value);
		}

		iter = attr_list.find("featureID");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'int'
			int value;
			std::istringstream(iter->second) >> value;
			this->setFeatureID(value);
		}

		iter = attr_list.find("transient");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setTransient(value);
		}

		iter = attr_list.find("unsettable");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setUnsettable(value);
		}

		iter = attr_list.find("volatile");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setVolatile(value);
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

	ETypedElementImpl::loadAttributes(loadHandler, attr_list);
}

void EStructuralFeatureImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ETypedElementImpl::loadNode(nodeName, loadHandler);
}

void EStructuralFeatureImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references)
{
	ETypedElementImpl::resolveReferences(featureID, references);
}

void EStructuralFeatureImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ETypedElementImpl::saveContent(saveHandler);
	
	ENamedElementImpl::saveContent(saveHandler);
	
	EModelElementImpl::saveContent(saveHandler);
	
	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void EStructuralFeatureImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::ecorePackage> package = ecore::ecorePackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getEStructuralFeature_Attribute_changeable()) )
		{
			saveHandler->addAttribute("changeable", this->isChangeable());
		}

		if ( this->eIsSet(package->getEStructuralFeature_Attribute_defaultValueLiteral()) )
		{
			saveHandler->addAttribute("defaultValueLiteral", this->getDefaultValueLiteral());
		}

		if ( this->eIsSet(package->getEStructuralFeature_Attribute_derived()) )
		{
			saveHandler->addAttribute("derived", this->isDerived());
		}

		if ( this->eIsSet(package->getEStructuralFeature_Attribute_featureID()) )
		{
			saveHandler->addAttribute("featureID", this->getFeatureID());
		}

		if ( this->eIsSet(package->getEStructuralFeature_Attribute_transient()) )
		{
			saveHandler->addAttribute("transient", this->isTransient());
		}

		if ( this->eIsSet(package->getEStructuralFeature_Attribute_unsettable()) )
		{
			saveHandler->addAttribute("unsettable", this->isUnsettable());
		}

		if ( this->eIsSet(package->getEStructuralFeature_Attribute_volatile()) )
		{
			saveHandler->addAttribute("volatile", this->isVolatile());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<EClass> EStructuralFeatureImpl::eStaticClass() const
{
	return ecore::ecorePackage::eInstance()->getEStructuralFeature_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any EStructuralFeatureImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_CHANGEABLE:
			return eAny(isChangeable(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //5313
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_DEFAULTVALUE:
			return eAny(getDefaultValue(),ecore::ecorePackage::EJAVAOBJECT_CLASS,false); //5317
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_DEFAULTVALUELITERAL:
			return eAny(getDefaultValueLiteral(),ecore::ecorePackage::ESTRING_CLASS,false); //5316
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_DERIVED:
			return eAny(isDerived(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //5319
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_ECONTAININGCLASS:
		{
			std::shared_ptr<ecore::EObject> returnValue=getEContainingClass().lock();
			return eAny(returnValue,ecore::ecorePackage::ECLASS_CLASS,false); //5321
		}
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_FEATUREID:
			return eAny(getFeatureID(),ecore::ecorePackage::EINT_CLASS,false); //5320
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_TRANSIENT:
			return eAny(isTransient(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //5315
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_UNSETTABLE:
			return eAny(isUnsettable(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //5318
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_VOLATILE:
			return eAny(isVolatile(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //5314
	}
	return ETypedElementImpl::eGet(featureID, resolve, coreType);
}

bool EStructuralFeatureImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_CHANGEABLE:
			return isChangeable() != true; //5313
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_DEFAULTVALUE:
			return getDefaultValue() != nullptr; //5317
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_DEFAULTVALUELITERAL:
			return getDefaultValueLiteral() != ""; //5316
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_DERIVED:
			return isDerived() != false; //5319
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_ECONTAININGCLASS:
			return getEContainingClass().lock() != nullptr; //5321
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_FEATUREID:
			return getFeatureID() != -1; //5320
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_TRANSIENT:
			return isTransient() != false; //5315
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_UNSETTABLE:
			return isUnsettable() != false; //5318
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_VOLATILE:
			return isVolatile() != false; //5314
	}
	return ETypedElementImpl::internalEIsSet(featureID);
}

bool EStructuralFeatureImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_CHANGEABLE:
		{
			// CAST Any to bool
			bool _changeable = newValue->get<bool>();
			setChangeable(_changeable); //5313
			return true;
		}
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_DEFAULTVALUE:
		{
			// CAST Any to Any
			Any _defaultValue = newValue->get<Any>();
			setDefaultValue(_defaultValue); //5317
			return true;
		}
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_DEFAULTVALUELITERAL:
		{
			// CAST Any to std::string
			std::string _defaultValueLiteral = newValue->get<std::string>();
			setDefaultValueLiteral(_defaultValueLiteral); //5316
			return true;
		}
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_DERIVED:
		{
			// CAST Any to bool
			bool _derived = newValue->get<bool>();
			setDerived(_derived); //5319
			return true;
		}
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_TRANSIENT:
		{
			// CAST Any to bool
			bool _transient = newValue->get<bool>();
			setTransient(_transient); //5315
			return true;
		}
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_UNSETTABLE:
		{
			// CAST Any to bool
			bool _unsettable = newValue->get<bool>();
			setUnsettable(_unsettable); //5318
			return true;
		}
		case ecore::ecorePackage::ESTRUCTURALFEATURE_ATTRIBUTE_VOLATILE:
		{
			// CAST Any to bool
			bool _volatile = newValue->get<bool>();
			setVolatile(_volatile); //5314
			return true;
		}
	}

	return ETypedElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any EStructuralFeatureImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// ecore::EStructuralFeature::getContainerClass() : void *: 172675706
		case ecorePackage::ESTRUCTURALFEATURE_OPERATION_GETCONTAINERCLASS:
		{
			result = eAny(this->getContainerClass(),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = ETypedElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ecore::EStructuralFeature> EStructuralFeatureImpl::getThisEStructuralFeaturePtr() const
{
	return m_thisEStructuralFeaturePtr.lock();
}
void EStructuralFeatureImpl::setThisEStructuralFeaturePtr(std::weak_ptr<ecore::EStructuralFeature> thisEStructuralFeaturePtr)
{
	m_thisEStructuralFeaturePtr = thisEStructuralFeaturePtr;
	setThisETypedElementPtr(thisEStructuralFeaturePtr);
}


