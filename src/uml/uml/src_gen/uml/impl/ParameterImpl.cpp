
#include "uml/impl/ParameterImpl.hpp"

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
#include "uml/Behavior.hpp"
#include "uml/Comment.hpp"
#include "uml/ConnectableElement.hpp"
#include "uml/ConnectorEnd.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/MultiplicityElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Operation.hpp"
#include "uml/ParameterSet.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/Type.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ParameterImpl::ParameterImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ParameterImpl::~ParameterImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Parameter "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ParameterImpl::ParameterImpl(std::weak_ptr<uml::Behavior> par_behavior)
:ParameterImpl()
{
	m_behavior = par_behavior;
	m_namespace = par_behavior;
}

//Additional constructor for the containments back reference
ParameterImpl::ParameterImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ParameterImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ParameterImpl::ParameterImpl(std::weak_ptr<uml::Operation> par_operation)
:ParameterImpl()
{
	m_operation = par_operation;
	m_namespace = par_operation;
}

//Additional constructor for the containments back reference
ParameterImpl::ParameterImpl(std::weak_ptr<uml::Element> par_owner)
:ParameterImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ParameterImpl::ParameterImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:ParameterImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

ParameterImpl::ParameterImpl(const ParameterImpl & obj): ParameterImpl()
{
	*this = obj;
}

ParameterImpl& ParameterImpl::operator=(const ParameterImpl & obj)
{
	//call overloaded =Operator for each base class
	ConnectableElementImpl::operator=(obj);
	MultiplicityElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Parameter 
	 * which is generated by the compiler (as Parameter is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Parameter::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Parameter "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_default = obj.getDefault();
	m_direction = obj.getDirection();
	m_effect = obj.getEffect();
	m_isException = obj.getIsException();
	m_isStream = obj.getIsStream();

	//copy references with no containment (soft copy)
	m_behavior  = obj.getBehavior();
	m_operation  = obj.getOperation();
	m_parameterSet  = obj.getParameterSet();
	//Clone references with containment (deep copy)
	//clone reference 'defaultValue'
	if(obj.getDefaultValue()!=nullptr)
	{
		m_defaultValue = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getDefaultValue()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> ParameterImpl::copy() const
{
	std::shared_ptr<ParameterImpl> element(new ParameterImpl());
	*element =(*this);
	element->setThisParameterPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool ParameterImpl::connector_end(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterImpl::in_and_out(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterImpl::isSetDefault()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterImpl::not_exception(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterImpl::object_effect(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterImpl::reentrant_behaviors(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ParameterImpl::setBooleanDefaultValue(bool value)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ParameterImpl::setIntegerDefaultValue(int value)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ParameterImpl::setNullDefaultValue()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ParameterImpl::setRealDefaultValue(double value)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ParameterImpl::setStringDefaultValue(std::string value)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ParameterImpl::setUnlimitedNaturalDefaultValue(int value)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ParameterImpl::stream_and_exception(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

void ParameterImpl::unsetDefault()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute default */
std::string ParameterImpl::getDefault() const 
{
	return m_default;
}
void ParameterImpl::setDefault(std::string _default)
{
	m_default = _default;
	
}

/* Getter & Setter for attribute direction */
uml::ParameterDirectionKind ParameterImpl::getDirection() const 
{
	return m_direction;
}
void ParameterImpl::setDirection(uml::ParameterDirectionKind _direction)
{
	m_direction = _direction;
	
}

/* Getter & Setter for attribute effect */
uml::ParameterEffectKind ParameterImpl::getEffect() const 
{
	return m_effect;
}
void ParameterImpl::setEffect(uml::ParameterEffectKind _effect)
{
	m_effect = _effect;
	
}

/* Getter & Setter for attribute isException */
bool ParameterImpl::getIsException() const 
{
	return m_isException;
}
void ParameterImpl::setIsException(bool _isException)
{
	m_isException = _isException;
	
}

/* Getter & Setter for attribute isStream */
bool ParameterImpl::getIsStream() const 
{
	return m_isStream;
}
void ParameterImpl::setIsStream(bool _isStream)
{
	m_isStream = _isStream;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference behavior */
std::weak_ptr<uml::Behavior> ParameterImpl::getBehavior() const
{
    return m_behavior;
}
void ParameterImpl::setBehavior(std::weak_ptr<uml::Behavior> _behavior)
{
    m_behavior = _behavior;
	
}

/* Getter & Setter for reference defaultValue */
std::shared_ptr<uml::ValueSpecification> ParameterImpl::getDefaultValue() const
{
    return m_defaultValue;
}
void ParameterImpl::setDefaultValue(std::shared_ptr<uml::ValueSpecification> _defaultValue)
{
    m_defaultValue = _defaultValue;
	
}

/* Getter & Setter for reference operation */
std::weak_ptr<uml::Operation> ParameterImpl::getOperation() const
{
    return m_operation;
}

/* Getter & Setter for reference parameterSet */
std::shared_ptr<Bag<uml::ParameterSet>> ParameterImpl::getParameterSet() const
{
	if(m_parameterSet == nullptr)
	{
		m_parameterSet.reset(new Bag<uml::ParameterSet>());
		
		
	}
    return m_parameterSet;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> ParameterImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ParameterImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ParameterImpl::getOwner() const
{
	return m_owner;
}



//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ParameterImpl::eContainer() const
{
	if(auto wp = m_behavior.lock())
	{
		return wp;
	}

	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_operation.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
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
// Persistence Functions
//*********************************
void ParameterImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ParameterImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("direction");
		if ( iter != attr_list.end() )
		{
			uml::ParameterDirectionKind value = uml::ParameterDirectionKind::IN;
			std::string literal = iter->second;
						if (literal == "in")
			{
				value = uml::ParameterDirectionKind::IN;
			}
			else 			if (literal == "inout")
			{
				value = uml::ParameterDirectionKind::INOUT;
			}
			else 			if (literal == "out")
			{
				value = uml::ParameterDirectionKind::OUT;
			}
			else 			if (literal == "return")
			{
				value = uml::ParameterDirectionKind::RETURN;
			}
			this->setDirection(value);
		}

		iter = attr_list.find("effect");
		if ( iter != attr_list.end() )
		{
			uml::ParameterEffectKind value = uml::ParameterEffectKind::CREATE;
			std::string literal = iter->second;
						if (literal == "create")
			{
				value = uml::ParameterEffectKind::CREATE;
			}
			else 			if (literal == "read")
			{
				value = uml::ParameterEffectKind::READ;
			}
			else 			if (literal == "update")
			{
				value = uml::ParameterEffectKind::UPDATE;
			}
			else 			if (literal == "delete")
			{
				value = uml::ParameterEffectKind::DELETE;
			}
			this->setEffect(value);
		}

		iter = attr_list.find("isException");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsException(value);
		}

		iter = attr_list.find("isStream");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsStream(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("parameterSet");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("parameterSet")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ConnectableElementImpl::loadAttributes(loadHandler, attr_list);
	MultiplicityElementImpl::loadAttributes(loadHandler, attr_list);
}

void ParameterImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("defaultValue") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getDefaultValue()); 

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
	ConnectableElementImpl::loadNode(nodeName, loadHandler);
	MultiplicityElementImpl::loadNode(nodeName, loadHandler);
}

void ParameterImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::PARAMETER_ATTRIBUTE_BEHAVIOR:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Behavior> _behavior = std::dynamic_pointer_cast<uml::Behavior>( references.front() );
				setBehavior(_behavior);
			}
			
			return;
		}

		case uml::umlPackage::PARAMETER_ATTRIBUTE_PARAMETERSET:
		{
			std::shared_ptr<Bag<uml::ParameterSet>> _parameterSet = getParameterSet();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ParameterSet>  _r = std::dynamic_pointer_cast<uml::ParameterSet>(ref);
				if (_r != nullptr)
				{
					_parameterSet->push_back(_r);
				}
			}
			return;
		}
	}
	ConnectableElementImpl::resolveReferences(featureID, references);
	MultiplicityElementImpl::resolveReferences(featureID, references);
}

void ParameterImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ConnectableElementImpl::saveContent(saveHandler);
	MultiplicityElementImpl::saveContent(saveHandler);
	
	ParameterableElementImpl::saveContent(saveHandler);
	TypedElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ParameterImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'defaultValue'
		std::shared_ptr<uml::ValueSpecification> defaultValue = this->getDefaultValue();
		if (defaultValue != nullptr)
		{
			saveHandler->addReference(defaultValue, "defaultValue", defaultValue->eClass() != package->getValueSpecification_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getParameter_Attribute_direction()) )
		{
			uml::ParameterDirectionKind value = this->getDirection();
			std::string literal = "";
			if (value == uml::ParameterDirectionKind::IN)
			{
				literal = "in";
			}
			else if (value == uml::ParameterDirectionKind::INOUT)
			{
				literal = "inout";
			}
			else if (value == uml::ParameterDirectionKind::OUT)
			{
				literal = "out";
			}
			else if (value == uml::ParameterDirectionKind::RETURN)
			{
				literal = "return";
			}
			saveHandler->addAttribute("direction", literal);
		}

		if ( this->eIsSet(package->getParameter_Attribute_effect()) )
		{
			uml::ParameterEffectKind value = this->getEffect();
			std::string literal = "";
			if (value == uml::ParameterEffectKind::CREATE)
			{
				literal = "create";
			}
			else if (value == uml::ParameterEffectKind::READ)
			{
				literal = "read";
			}
			else if (value == uml::ParameterEffectKind::UPDATE)
			{
				literal = "update";
			}
			else if (value == uml::ParameterEffectKind::DELETE)
			{
				literal = "delete";
			}
			saveHandler->addAttribute("effect", literal);
		}

		if ( this->eIsSet(package->getParameter_Attribute_isException()) )
		{
			saveHandler->addAttribute("isException", this->getIsException());
		}

		if ( this->eIsSet(package->getParameter_Attribute_isStream()) )
		{
			saveHandler->addAttribute("isStream", this->getIsStream());
		}
	// Add references
		saveHandler->addReferences<uml::ParameterSet>("parameterSet", this->getParameterSet());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ParameterImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getParameter_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ParameterImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::PARAMETER_ATTRIBUTE_BEHAVIOR:
		{
			std::shared_ptr<ecore::EObject> returnValue=getBehavior().lock();
			return eAny(returnValue,uml::umlPackage::BEHAVIOR_CLASS,false); //17427
		}
		case uml::umlPackage::PARAMETER_ATTRIBUTE_DEFAULT:
			return eAny(getDefault(),ecore::ecorePackage::ESTRING_CLASS,false); //17419
		case uml::umlPackage::PARAMETER_ATTRIBUTE_DEFAULTVALUE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getDefaultValue();
			return eAny(returnValue,uml::umlPackage::VALUESPECIFICATION_CLASS,false); //17420
		}
		case uml::umlPackage::PARAMETER_ATTRIBUTE_DIRECTION:
			return eAny(getDirection(),uml::umlPackage::PARAMETERDIRECTIONKIND_CLASS,false); //17421
		case uml::umlPackage::PARAMETER_ATTRIBUTE_EFFECT:
			return eAny(getEffect(),uml::umlPackage::PARAMETEREFFECTKIND_CLASS,false); //17422
		case uml::umlPackage::PARAMETER_ATTRIBUTE_ISEXCEPTION:
			return eAny(getIsException(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //17423
		case uml::umlPackage::PARAMETER_ATTRIBUTE_ISSTREAM:
			return eAny(getIsStream(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //17424
		case uml::umlPackage::PARAMETER_ATTRIBUTE_OPERATION:
		{
			std::shared_ptr<ecore::EObject> returnValue=getOperation().lock();
			return eAny(returnValue,uml::umlPackage::OPERATION_CLASS,false); //17425
		}
		case uml::umlPackage::PARAMETER_ATTRIBUTE_PARAMETERSET:
		{
			return eAnyBag(getParameterSet(),uml::umlPackage::PARAMETERSET_CLASS); //17426
		}
	}
	Any result;
	result = ConnectableElementImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = MultiplicityElementImpl::eGet(featureID, resolve, coreType);
	return result;
}

bool ParameterImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::PARAMETER_ATTRIBUTE_BEHAVIOR:
			return getBehavior().lock() != nullptr; //17427
		case uml::umlPackage::PARAMETER_ATTRIBUTE_DEFAULT:
			return getDefault() != ""; //17419
		case uml::umlPackage::PARAMETER_ATTRIBUTE_DEFAULTVALUE:
			return getDefaultValue() != nullptr; //17420
		case uml::umlPackage::PARAMETER_ATTRIBUTE_DIRECTION:
			return m_direction != uml::ParameterDirectionKind::IN;; //17421
		case uml::umlPackage::PARAMETER_ATTRIBUTE_EFFECT:
			return m_effect != uml::ParameterEffectKind::CREATE;; //17422
		case uml::umlPackage::PARAMETER_ATTRIBUTE_ISEXCEPTION:
			return getIsException() != false; //17423
		case uml::umlPackage::PARAMETER_ATTRIBUTE_ISSTREAM:
			return getIsStream() != false; //17424
		case uml::umlPackage::PARAMETER_ATTRIBUTE_OPERATION:
			return getOperation().lock() != nullptr; //17425
		case uml::umlPackage::PARAMETER_ATTRIBUTE_PARAMETERSET:
			return getParameterSet() != nullptr; //17426
	}
	bool result = false;
	result = ConnectableElementImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = MultiplicityElementImpl::internalEIsSet(featureID);
	return result;
}

bool ParameterImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::PARAMETER_ATTRIBUTE_BEHAVIOR:
		{
			// CAST Any to uml::Behavior
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Behavior> _behavior = std::dynamic_pointer_cast<uml::Behavior>(_temp);
			setBehavior(_behavior); //17427
			return true;
		}
		case uml::umlPackage::PARAMETER_ATTRIBUTE_DEFAULT:
		{
			// CAST Any to std::string
			std::string _default = newValue->get<std::string>();
			setDefault(_default); //17419
			return true;
		}
		case uml::umlPackage::PARAMETER_ATTRIBUTE_DEFAULTVALUE:
		{
			// CAST Any to uml::ValueSpecification
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ValueSpecification> _defaultValue = std::dynamic_pointer_cast<uml::ValueSpecification>(_temp);
			setDefaultValue(_defaultValue); //17420
			return true;
		}
		case uml::umlPackage::PARAMETER_ATTRIBUTE_DIRECTION:
		{
			// CAST Any to uml::ParameterDirectionKind
			uml::ParameterDirectionKind _direction = newValue->get<uml::ParameterDirectionKind>();
			setDirection(_direction); //17421
			return true;
		}
		case uml::umlPackage::PARAMETER_ATTRIBUTE_EFFECT:
		{
			// CAST Any to uml::ParameterEffectKind
			uml::ParameterEffectKind _effect = newValue->get<uml::ParameterEffectKind>();
			setEffect(_effect); //17422
			return true;
		}
		case uml::umlPackage::PARAMETER_ATTRIBUTE_ISEXCEPTION:
		{
			// CAST Any to bool
			bool _isException = newValue->get<bool>();
			setIsException(_isException); //17423
			return true;
		}
		case uml::umlPackage::PARAMETER_ATTRIBUTE_ISSTREAM:
		{
			// CAST Any to bool
			bool _isStream = newValue->get<bool>();
			setIsStream(_isStream); //17424
			return true;
		}
		case uml::umlPackage::PARAMETER_ATTRIBUTE_PARAMETERSET:
		{
			// CAST Any to Bag<uml::ParameterSet>
			if((newValue->isContainer()) && (uml::umlPackage::PARAMETERSET_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::ParameterSet>> parameterSetList= newValue->get<std::shared_ptr<Bag<uml::ParameterSet>>>();
					std::shared_ptr<Bag<uml::ParameterSet>> _parameterSet=getParameterSet();
					for(const std::shared_ptr<uml::ParameterSet> indexParameterSet: *_parameterSet)
					{
						if (parameterSetList->find(indexParameterSet) == -1)
						{
							_parameterSet->erase(indexParameterSet);
						}
					}

					for(const std::shared_ptr<uml::ParameterSet> indexParameterSet: *parameterSetList)
					{
						if (_parameterSet->find(indexParameterSet) == -1)
						{
							_parameterSet->add(indexParameterSet);
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

	bool result = false;
	result = ConnectableElementImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = MultiplicityElementImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// EOperation Invoke
//*********************************
Any ParameterImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// uml::Parameter::connector_end(Any, std::map) : bool: 740584078
		case umlPackage::PARAMETER_OPERATION_CONNECTOR_END_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->connector_end(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Parameter::in_and_out(Any, std::map) : bool: 136133503
		case umlPackage::PARAMETER_OPERATION_IN_AND_OUT_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->in_and_out(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Parameter::isSetDefault() : bool: 1999374675
		case umlPackage::PARAMETER_OPERATION_ISSETDEFAULT:
		{
			result = eAny(this->isSetDefault(),0,false);
			break;
		}
		// uml::Parameter::not_exception(Any, std::map) : bool: 964172832
		case umlPackage::PARAMETER_OPERATION_NOT_EXCEPTION_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->not_exception(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Parameter::object_effect(Any, std::map) : bool: 305756032
		case umlPackage::PARAMETER_OPERATION_OBJECT_EFFECT_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->object_effect(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Parameter::reentrant_behaviors(Any, std::map) : bool: 873949267
		case umlPackage::PARAMETER_OPERATION_REENTRANT_BEHAVIORS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->reentrant_behaviors(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Parameter::setBooleanDefaultValue(bool): 401053548
		case umlPackage::PARAMETER_OPERATION_SETBOOLEANDEFAULTVALUE_BOOLEAN:
		{
			//Retrieve input parameter 'value'
			//parameter 0
			bool incoming_param_value;
			std::list<Any>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_value = (*incoming_param_value_arguments_citer)->get<bool >();
			this->setBooleanDefaultValue(incoming_param_value);
		}
		// uml::Parameter::setIntegerDefaultValue(int): 1728800880
		case umlPackage::PARAMETER_OPERATION_SETINTEGERDEFAULTVALUE_INTEGER:
		{
			//Retrieve input parameter 'value'
			//parameter 0
			int incoming_param_value;
			std::list<Any>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_value = (*incoming_param_value_arguments_citer)->get<int >();
			this->setIntegerDefaultValue(incoming_param_value);
		}
		// uml::Parameter::setNullDefaultValue(): 687577499
		case umlPackage::PARAMETER_OPERATION_SETNULLDEFAULTVALUE:
		{
			this->setNullDefaultValue();
		}
		// uml::Parameter::setRealDefaultValue(double): 488751702
		case umlPackage::PARAMETER_OPERATION_SETREALDEFAULTVALUE_REAL:
		{
			//Retrieve input parameter 'value'
			//parameter 0
			double incoming_param_value;
			std::list<Any>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_value = (*incoming_param_value_arguments_citer)->get<double >();
			this->setRealDefaultValue(incoming_param_value);
		}
		// uml::Parameter::setStringDefaultValue(std::string): 1288613666
		case umlPackage::PARAMETER_OPERATION_SETSTRINGDEFAULTVALUE_STRING:
		{
			//Retrieve input parameter 'value'
			//parameter 0
			std::string incoming_param_value;
			std::list<Any>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_value = (*incoming_param_value_arguments_citer)->get<std::string >();
			this->setStringDefaultValue(incoming_param_value);
		}
		// uml::Parameter::setUnlimitedNaturalDefaultValue(int): 287411615
		case umlPackage::PARAMETER_OPERATION_SETUNLIMITEDNATURALDEFAULTVALUE_UNLIMITEDNATURAL:
		{
			//Retrieve input parameter 'value'
			//parameter 0
			int incoming_param_value;
			std::list<Any>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_value = (*incoming_param_value_arguments_citer)->get<int >();
			this->setUnlimitedNaturalDefaultValue(incoming_param_value);
		}
		// uml::Parameter::stream_and_exception(Any, std::map) : bool: 1728894546
		case umlPackage::PARAMETER_OPERATION_STREAM_AND_EXCEPTION_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->stream_and_exception(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Parameter::unsetDefault(): 314482012
		case umlPackage::PARAMETER_OPERATION_UNSETDEFAULT:
		{
			this->unsetDefault();
		}

		default:
		{
			// call superTypes
			result = MultiplicityElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = ConnectableElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Parameter> ParameterImpl::getThisParameterPtr() const
{
	return m_thisParameterPtr.lock();
}
void ParameterImpl::setThisParameterPtr(std::weak_ptr<uml::Parameter> thisParameterPtr)
{
	m_thisParameterPtr = thisParameterPtr;
	setThisConnectableElementPtr(thisParameterPtr);
	setThisMultiplicityElementPtr(thisParameterPtr);
}

