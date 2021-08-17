#include "uml/impl/OperationImpl.hpp"

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


#include "uml/Behavior.hpp"
#include "uml/BehavioralFeature.hpp"
#include "uml/Class.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/DataType.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Interface.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Operation.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Parameter.hpp"
#include "uml/ParameterSet.hpp"
#include "uml/ParameterableElement.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/TemplateableElement.hpp"
#include "uml/Type.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
OperationImpl::OperationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

OperationImpl::~OperationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Operation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
OperationImpl::OperationImpl(std::weak_ptr<uml::Class> par_class)
:OperationImpl()
{
	m_class = par_class;
	m_namespace = par_class;
}

//Additional constructor for the containments back reference
OperationImpl::OperationImpl(std::weak_ptr<uml::DataType> par_datatype)
:OperationImpl()
{
	m_datatype = par_datatype;
	m_namespace = par_datatype;
}

//Additional constructor for the containments back reference
OperationImpl::OperationImpl(std::weak_ptr<uml::Interface> par_interface)
:OperationImpl()
{
	m_interface = par_interface;
	m_namespace = par_interface;
}

//Additional constructor for the containments back reference
OperationImpl::OperationImpl(std::weak_ptr<uml::Namespace> par_namespace)
:OperationImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
OperationImpl::OperationImpl(std::weak_ptr<uml::Element> par_owner)
:OperationImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
OperationImpl::OperationImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:OperationImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

OperationImpl::OperationImpl(const OperationImpl & obj): OperationImpl()
{
	*this = obj;
}

OperationImpl& OperationImpl::operator=(const OperationImpl & obj)
{
	//call overloaded =Operator for each base class
	BehavioralFeatureImpl::operator=(obj);
	ParameterableElementImpl::operator=(obj);
	TemplateableElementImpl::operator=(obj);
	Operation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Operation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isOrdered = obj.getIsOrdered();
	m_isQuery = obj.getIsQuery();
	m_isUnique = obj.getIsUnique();
	m_lower = obj.getLower();
	m_upper = obj.getUpper();

	//copy references with no containment (soft copy)
	m_class  = obj.getClass();
	m_datatype  = obj.getDatatype();
	m_interface  = obj.getInterface();
	m_type  = obj.getType();
	//Clone references with containment (deep copy)
	//clone reference 'bodyCondition'
	if(obj.getBodyCondition()!=nullptr)
	{
		m_bodyCondition = std::dynamic_pointer_cast<uml::Constraint>(obj.getBodyCondition()->copy());
	}

	//clone reference 'postcondition'
	std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>> postconditionList = obj.getPostcondition();
	if(postconditionList)
	{
		Bag<uml::Constraint>::iterator postconditionIter = postconditionList->begin();
		Bag<uml::Constraint>::iterator postconditionEnd = postconditionList->end();
		while (postconditionIter != postconditionEnd) 
		{
			std::shared_ptr<uml::Constraint> temp = std::dynamic_pointer_cast<uml::Constraint>((*postconditionIter)->copy());
			getPostcondition()->push_back(temp);
			postconditionIter++;
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr postcondition."<< std::endl;)
	}

	//clone reference 'precondition'
	std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>> preconditionList = obj.getPrecondition();
	if(preconditionList)
	{
		Bag<uml::Constraint>::iterator preconditionIter = preconditionList->begin();
		Bag<uml::Constraint>::iterator preconditionEnd = preconditionList->end();
		while (preconditionIter != preconditionEnd) 
		{
			std::shared_ptr<uml::Constraint> temp = std::dynamic_pointer_cast<uml::Constraint>((*preconditionIter)->copy());
			getPrecondition()->push_back(temp);
			preconditionIter++;
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr precondition."<< std::endl;)
	}

	//clone reference 'redefinedOperation'
	std::shared_ptr<Subset<uml::Operation, uml::RedefinableElement>> redefinedOperationList = obj.getRedefinedOperation();
	if(redefinedOperationList)
	{
		Bag<uml::Operation>::iterator redefinedOperationIter = redefinedOperationList->begin();
		Bag<uml::Operation>::iterator redefinedOperationEnd = redefinedOperationList->end();
		while (redefinedOperationIter != redefinedOperationEnd) 
		{
			std::shared_ptr<uml::Operation> temp = std::dynamic_pointer_cast<uml::Operation>((*redefinedOperationIter)->copy());
			getRedefinedOperation()->push_back(temp);
			redefinedOperationIter++;
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr redefinedOperation."<< std::endl;)
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> OperationImpl::copy() const
{
	std::shared_ptr<OperationImpl> element(new OperationImpl());
	*element =(*this);
	element->setThisOperationPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> OperationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getOperation_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isOrdered
*/
bool OperationImpl::getIsOrdered() const 
{
	return m_isOrdered;
}



/*
Getter & Setter for attribute isQuery
*/
bool OperationImpl::getIsQuery() const 
{
	return m_isQuery;
}
void OperationImpl::setIsQuery(bool _isQuery)
{
	m_isQuery = _isQuery;
	
} 


/*
Getter & Setter for attribute isUnique
*/
bool OperationImpl::getIsUnique() const 
{
	return m_isUnique;
}



/*
Getter & Setter for attribute lower
*/
int OperationImpl::getLower() const 
{
	return m_lower;
}



/*
Getter & Setter for attribute upper
*/
int OperationImpl::getUpper() const 
{
	return m_upper;
}



//*********************************
// Operations
//*********************************
bool OperationImpl::at_most_one_return(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

int OperationImpl::getLower()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Parameter> OperationImpl::getReturnResult()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return this->returnResult();
	//end of body
}



int OperationImpl::getUpper()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OperationImpl::isOrdered()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OperationImpl::isUnique()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool OperationImpl::matches(std::shared_ptr<uml::Operation> comparedOperation)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	//Checks whether two uml::Operations share the same name and input parameter types (= share same signature)

bool equals = false;

if(this->getName() != comparedOperation->getName()) {return equals;}

std::shared_ptr<Bag<uml::Parameter>> thisParameters = this->getOwnedParameter();
std::shared_ptr<Bag<uml::Parameter>> otherParameters = comparedOperation->getOwnedParameter();

if(thisParameters->size() != otherParameters->size()) {return equals;}

for(unsigned int i = 0; i < thisParameters->size(); i++)
{
	if(thisParameters->at(i)->getType() != otherParameters->at(i)->getType()) {return equals;}
}

equals = true;
return equals;

	//end of body
}

bool OperationImpl::only_body_for_query(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Parameter> OperationImpl::returnResult()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::Parameter>> ownedParameters = this->getOwnedParameter();
	std::shared_ptr<uml::Parameter> returnResult;

	for(std::shared_ptr<uml::Parameter> p : *ownedParameters)
	{
		if(p->getDirection() == uml::ParameterDirectionKind::RETURN)
		{
				returnResult=p;
				break;
		}
	}
	
	return returnResult;
	//end of body
}

void OperationImpl::setIsOrdered(bool newIsOrdered)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	m_isOrdered = newIsOrdered;
	//end of body
}

void OperationImpl::setIsUnique(bool newIsUnique)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	m_isUnique = newIsUnique;
	//end of body
}

void OperationImpl::setLower(int newLower)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	m_lower = newLower;
	//end of body
}

void OperationImpl::setType(std::shared_ptr<uml::Type> newType)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	m_type = newType;
	//end of body
}

void OperationImpl::setUpper(int newUpper)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	m_upper = newUpper;
	//end of body
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference bodyCondition
*/
std::shared_ptr<uml::Constraint> OperationImpl::getBodyCondition() const
{
    return m_bodyCondition;
}
void OperationImpl::setBodyCondition(std::shared_ptr<uml::Constraint> _bodyCondition)
{
    m_bodyCondition = _bodyCondition;
	
}


/*
Getter & Setter for reference class
*/
std::weak_ptr<uml::Class> OperationImpl::getClass() const
{
    return m_class;
}
void OperationImpl::setClass(std::weak_ptr<uml::Class> _class)
{
    m_class = _class;
	
}


/*
Getter & Setter for reference datatype
*/
std::weak_ptr<uml::DataType> OperationImpl::getDatatype() const
{
    return m_datatype;
}
void OperationImpl::setDatatype(std::weak_ptr<uml::DataType> _datatype)
{
    m_datatype = _datatype;
	
}


/*
Getter & Setter for reference interface
*/
std::weak_ptr<uml::Interface> OperationImpl::getInterface() const
{
    return m_interface;
}
void OperationImpl::setInterface(std::weak_ptr<uml::Interface> _interface)
{
    m_interface = _interface;
	
}


/*
Getter & Setter for reference ownedParameter
*/
std::shared_ptr<Bag<uml::Parameter>> OperationImpl::getProperty_OwnedParameter() const
{
	//Getter call of redefined container reference BehavioralFeature::ownedParameter 
	return uml::BehavioralFeatureImpl::getOwnedParameter();
}



/*
Getter & Setter for reference postcondition
*/
std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>> OperationImpl::getPostcondition() const
{
	if(m_postcondition == nullptr)
	{
		/*Subset*/
		m_postcondition.reset(new Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_postcondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getPostcondition()->initSubset(getOwnedRule());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_postcondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >(getOwnedRule())" << std::endl;
		#endif
		
	}
    return m_postcondition;
}



/*
Getter & Setter for reference precondition
*/
std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>> OperationImpl::getPrecondition() const
{
	if(m_precondition == nullptr)
	{
		/*Subset*/
		m_precondition.reset(new Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_precondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		getPrecondition()->initSubset(getOwnedRule());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_precondition - Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ >(getOwnedRule())" << std::endl;
		#endif
		
	}
    return m_precondition;
}



/*
Getter & Setter for reference redefinedOperation
*/
std::shared_ptr<Subset<uml::Operation, uml::RedefinableElement>> OperationImpl::getRedefinedOperation() const
{
	if(m_redefinedOperation == nullptr)
	{
		/*Subset*/
		m_redefinedOperation.reset(new Subset<uml::Operation, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_redefinedOperation - Subset<uml::Operation, uml::RedefinableElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getRedefinedOperation()->initSubset(getRedefinedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_redefinedOperation - Subset<uml::Operation, uml::RedefinableElement >(getRedefinedElement())" << std::endl;
		#endif
		
	}
    return m_redefinedOperation;
}



/*
Getter & Setter for reference type
*/
std::shared_ptr<uml::Type> OperationImpl::getType() const
{
    return m_type;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Classifier>> OperationImpl::getFeaturingClassifier() const
{
	if(m_featuringClassifier == nullptr)
	{
		/*Union*/
		m_featuringClassifier.reset(new Union<uml::Classifier>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_featuringClassifier - Union<uml::Classifier>()" << std::endl;
		#endif
		
		
	}
	return m_featuringClassifier;
}

std::shared_ptr<Union<uml::NamedElement>> OperationImpl::getMember() const
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

std::weak_ptr<uml::Namespace> OperationImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> OperationImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> OperationImpl::getOwnedMember() const
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

std::weak_ptr<uml::Element> OperationImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> OperationImpl::getRedefinedElement() const
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

std::shared_ptr<Union<uml::Classifier>> OperationImpl::getRedefinitionContext() const
{
	if(m_redefinitionContext == nullptr)
	{
		/*Union*/
		m_redefinitionContext.reset(new Union<uml::Classifier>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinitionContext - Union<uml::Classifier>()" << std::endl;
		#endif
		
		
	}
	return m_redefinitionContext;
}




std::shared_ptr<Operation> OperationImpl::getThisOperationPtr() const
{
	return m_thisOperationPtr.lock();
}
void OperationImpl::setThisOperationPtr(std::weak_ptr<Operation> thisOperationPtr)
{
	m_thisOperationPtr = thisOperationPtr;
	setThisBehavioralFeaturePtr(thisOperationPtr);
	setThisParameterableElementPtr(thisOperationPtr);
	setThisTemplateableElementPtr(thisOperationPtr);
}
std::shared_ptr<ecore::EObject> OperationImpl::eContainer() const
{
	if(auto wp = m_class.lock())
	{
		return wp;
	}

	if(auto wp = m_datatype.lock())
	{
		return wp;
	}

	if(auto wp = m_interface.lock())
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

	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any OperationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::OPERATION_ATTRIBUTE_BODYCONDITION:
			{
				std::shared_ptr<ecore::EObject> returnValue=getBodyCondition();
				return eAny(returnValue); //16730
			}
		case uml::umlPackage::OPERATION_ATTRIBUTE_CLASS:
			{
				std::shared_ptr<ecore::EObject> returnValue=getClass().lock();
				return eAny(returnValue); //16731
			}
		case uml::umlPackage::OPERATION_ATTRIBUTE_DATATYPE:
			{
				std::shared_ptr<ecore::EObject> returnValue=getDatatype().lock();
				return eAny(returnValue); //16732
			}
		case uml::umlPackage::OPERATION_ATTRIBUTE_INTERFACE:
			{
				std::shared_ptr<ecore::EObject> returnValue=getInterface().lock();
				return eAny(returnValue); //16733
			}
		case uml::umlPackage::OPERATION_ATTRIBUTE_ISORDERED:
			return eAny(getIsOrdered()); //16734
		case uml::umlPackage::OPERATION_ATTRIBUTE_ISQUERY:
			return eAny(getIsQuery()); //16735
		case uml::umlPackage::OPERATION_ATTRIBUTE_ISUNIQUE:
			return eAny(getIsUnique()); //16736
		case uml::umlPackage::OPERATION_ATTRIBUTE_LOWER:
			return eAny(getLower()); //16737
		case uml::umlPackage::OPERATION_ATTRIBUTE_OWNEDPARAMETER:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Parameter>::iterator iter = getProperty_OwnedParameter()->begin();
			Bag<uml::Parameter>::iterator end = getProperty_OwnedParameter()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //16743			
		}
		case uml::umlPackage::OPERATION_ATTRIBUTE_POSTCONDITION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Constraint>::iterator iter = getPostcondition()->begin();
			Bag<uml::Constraint>::iterator end = getPostcondition()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //16738			
		}
		case uml::umlPackage::OPERATION_ATTRIBUTE_PRECONDITION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Constraint>::iterator iter = getPrecondition()->begin();
			Bag<uml::Constraint>::iterator end = getPrecondition()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //16739			
		}
		case uml::umlPackage::OPERATION_ATTRIBUTE_REDEFINEDOPERATION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Operation>::iterator iter = getRedefinedOperation()->begin();
			Bag<uml::Operation>::iterator end = getRedefinedOperation()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //16740			
		}
		case uml::umlPackage::OPERATION_ATTRIBUTE_TYPE:
			{
				std::shared_ptr<ecore::EObject> returnValue=getType();
				return eAny(returnValue); //16741
			}
		case uml::umlPackage::OPERATION_ATTRIBUTE_UPPER:
			return eAny(getUpper()); //16742
	}
	Any result;
	result = BehavioralFeatureImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = ParameterableElementImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = TemplateableElementImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool OperationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::OPERATION_ATTRIBUTE_BODYCONDITION:
			return getBodyCondition() != nullptr; //16730
		case uml::umlPackage::OPERATION_ATTRIBUTE_CLASS:
			return getClass().lock() != nullptr; //16731
		case uml::umlPackage::OPERATION_ATTRIBUTE_DATATYPE:
			return getDatatype().lock() != nullptr; //16732
		case uml::umlPackage::OPERATION_ATTRIBUTE_INTERFACE:
			return getInterface().lock() != nullptr; //16733
		case uml::umlPackage::OPERATION_ATTRIBUTE_ISORDERED:
			return getIsOrdered() != false; //16734
		case uml::umlPackage::OPERATION_ATTRIBUTE_ISQUERY:
			return getIsQuery() != false; //16735
		case uml::umlPackage::OPERATION_ATTRIBUTE_ISUNIQUE:
			return getIsUnique() != true; //16736
		case uml::umlPackage::OPERATION_ATTRIBUTE_LOWER:
			return getLower() != 1; //16737
		case uml::umlPackage::OPERATION_ATTRIBUTE_OWNEDPARAMETER:
			return getProperty_OwnedParameter() != nullptr; //16743
		case uml::umlPackage::OPERATION_ATTRIBUTE_POSTCONDITION:
			return getPostcondition() != nullptr; //16738
		case uml::umlPackage::OPERATION_ATTRIBUTE_PRECONDITION:
			return getPrecondition() != nullptr; //16739
		case uml::umlPackage::OPERATION_ATTRIBUTE_REDEFINEDOPERATION:
			return getRedefinedOperation() != nullptr; //16740
		case uml::umlPackage::OPERATION_ATTRIBUTE_TYPE:
			return getType() != nullptr; //16741
		case uml::umlPackage::OPERATION_ATTRIBUTE_UPPER:
			return getUpper() != 1; //16742
	}
	bool result = false;
	result = BehavioralFeatureImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = ParameterableElementImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = TemplateableElementImpl::internalEIsSet(featureID);
	return result;
}
bool OperationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::OPERATION_ATTRIBUTE_BODYCONDITION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Constraint> _bodyCondition = std::dynamic_pointer_cast<uml::Constraint>(_temp);
			setBodyCondition(_bodyCondition); //16730
			return true;
		}
		case uml::umlPackage::OPERATION_ATTRIBUTE_CLASS:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Class> _class = std::dynamic_pointer_cast<uml::Class>(_temp);
			setClass(_class); //16731
			return true;
		}
		case uml::umlPackage::OPERATION_ATTRIBUTE_DATATYPE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::DataType> _datatype = std::dynamic_pointer_cast<uml::DataType>(_temp);
			setDatatype(_datatype); //16732
			return true;
		}
		case uml::umlPackage::OPERATION_ATTRIBUTE_INTERFACE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Interface> _interface = std::dynamic_pointer_cast<uml::Interface>(_temp);
			setInterface(_interface); //16733
			return true;
		}
		case uml::umlPackage::OPERATION_ATTRIBUTE_ISQUERY:
		{
			// BOOST CAST
			bool _isQuery = newValue->get<bool>();
			setIsQuery(_isQuery); //16735
			return true;
		}
		case uml::umlPackage::OPERATION_ATTRIBUTE_OWNEDPARAMETER:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Parameter>> ownedParameterList(new Bag<uml::Parameter>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedParameterList->add(std::dynamic_pointer_cast<uml::Parameter>(*iter));
				iter++;
			}
			
			Bag<uml::Parameter>::iterator iterOwnedParameter = getProperty_OwnedParameter()->begin();
			Bag<uml::Parameter>::iterator endOwnedParameter = getProperty_OwnedParameter()->end();
			while (iterOwnedParameter != endOwnedParameter)
			{
				if (ownedParameterList->find(*iterOwnedParameter) == -1)
				{
					getProperty_OwnedParameter()->erase(*iterOwnedParameter);
				}
				iterOwnedParameter++;
			}
 
			iterOwnedParameter = ownedParameterList->begin();
			endOwnedParameter = ownedParameterList->end();
			while (iterOwnedParameter != endOwnedParameter)
			{
				if (getProperty_OwnedParameter()->find(*iterOwnedParameter) == -1)
				{
					getProperty_OwnedParameter()->add(*iterOwnedParameter);
				}
				iterOwnedParameter++;			
			}
			return true;
		}
		case uml::umlPackage::OPERATION_ATTRIBUTE_POSTCONDITION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Constraint>> postconditionList(new Bag<uml::Constraint>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				postconditionList->add(std::dynamic_pointer_cast<uml::Constraint>(*iter));
				iter++;
			}
			
			Bag<uml::Constraint>::iterator iterPostcondition = getPostcondition()->begin();
			Bag<uml::Constraint>::iterator endPostcondition = getPostcondition()->end();
			while (iterPostcondition != endPostcondition)
			{
				if (postconditionList->find(*iterPostcondition) == -1)
				{
					getPostcondition()->erase(*iterPostcondition);
				}
				iterPostcondition++;
			}
 
			iterPostcondition = postconditionList->begin();
			endPostcondition = postconditionList->end();
			while (iterPostcondition != endPostcondition)
			{
				if (getPostcondition()->find(*iterPostcondition) == -1)
				{
					getPostcondition()->add(*iterPostcondition);
				}
				iterPostcondition++;			
			}
			return true;
		}
		case uml::umlPackage::OPERATION_ATTRIBUTE_PRECONDITION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Constraint>> preconditionList(new Bag<uml::Constraint>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				preconditionList->add(std::dynamic_pointer_cast<uml::Constraint>(*iter));
				iter++;
			}
			
			Bag<uml::Constraint>::iterator iterPrecondition = getPrecondition()->begin();
			Bag<uml::Constraint>::iterator endPrecondition = getPrecondition()->end();
			while (iterPrecondition != endPrecondition)
			{
				if (preconditionList->find(*iterPrecondition) == -1)
				{
					getPrecondition()->erase(*iterPrecondition);
				}
				iterPrecondition++;
			}
 
			iterPrecondition = preconditionList->begin();
			endPrecondition = preconditionList->end();
			while (iterPrecondition != endPrecondition)
			{
				if (getPrecondition()->find(*iterPrecondition) == -1)
				{
					getPrecondition()->add(*iterPrecondition);
				}
				iterPrecondition++;			
			}
			return true;
		}
		case uml::umlPackage::OPERATION_ATTRIBUTE_REDEFINEDOPERATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Operation>> redefinedOperationList(new Bag<uml::Operation>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				redefinedOperationList->add(std::dynamic_pointer_cast<uml::Operation>(*iter));
				iter++;
			}
			
			Bag<uml::Operation>::iterator iterRedefinedOperation = getRedefinedOperation()->begin();
			Bag<uml::Operation>::iterator endRedefinedOperation = getRedefinedOperation()->end();
			while (iterRedefinedOperation != endRedefinedOperation)
			{
				if (redefinedOperationList->find(*iterRedefinedOperation) == -1)
				{
					getRedefinedOperation()->erase(*iterRedefinedOperation);
				}
				iterRedefinedOperation++;
			}
 
			iterRedefinedOperation = redefinedOperationList->begin();
			endRedefinedOperation = redefinedOperationList->end();
			while (iterRedefinedOperation != endRedefinedOperation)
			{
				if (getRedefinedOperation()->find(*iterRedefinedOperation) == -1)
				{
					getRedefinedOperation()->add(*iterRedefinedOperation);
				}
				iterRedefinedOperation++;			
			}
			return true;
		}
	}

	bool result = false;
	result = BehavioralFeatureImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = ParameterableElementImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = TemplateableElementImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Behavioral Feature
//*********************************
Any OperationImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 16826
		case umlPackage::OPERATION_OPERATION_AT_MOST_ONE_RETURN_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->at_most_one_return(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 16836
		case umlPackage::OPERATION_OPERATION_GETLOWER:
		{
			result = eAny(this->getLower());
			break;
		}
		
		// 16828
		case umlPackage::OPERATION_OPERATION_GETRETURNRESULT:
		{
			result = eAny(this->getReturnResult());
			break;
		}
		
		// 16838
		case umlPackage::OPERATION_OPERATION_GETTYPE:
		{
			result = eAny(this->getType());
			break;
		}
		
		// 16839
		case umlPackage::OPERATION_OPERATION_GETUPPER:
		{
			result = eAny(this->getUpper());
			break;
		}
		
		// 16834
		case umlPackage::OPERATION_OPERATION_ISORDERED:
		{
			result = eAny(this->isOrdered());
			break;
		}
		
		// 16835
		case umlPackage::OPERATION_OPERATION_ISUNIQUE:
		{
			result = eAny(this->isUnique());
			break;
		}
		
		// 16840
		case umlPackage::OPERATION_OPERATION_MATCHES_OPERATION:
		{
			//Retrieve input parameter 'comparedOperation'
			//parameter 0
			std::shared_ptr<uml::Operation> incoming_param_comparedOperation;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_comparedOperation_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_comparedOperation = (*incoming_param_comparedOperation_arguments_citer)->get()->get<std::shared_ptr<uml::Operation> >();
			result = eAny(this->matches(incoming_param_comparedOperation));
			break;
		}
		
		// 16827
		case umlPackage::OPERATION_OPERATION_ONLY_BODY_FOR_QUERY_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->only_body_for_query(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 16837
		case umlPackage::OPERATION_OPERATION_RETURNRESULT:
		{
			result = eAny(this->returnResult());
			break;
		}
		
		// 16829
		case umlPackage::OPERATION_OPERATION_SETISORDERED_BOOLEAN:
		{
			//Retrieve input parameter 'newIsOrdered'
			//parameter 0
			bool incoming_param_newIsOrdered;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_newIsOrdered_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_newIsOrdered = (*incoming_param_newIsOrdered_arguments_citer)->get()->get<bool >();
			this->setIsOrdered(incoming_param_newIsOrdered);
			break;
		}
		
		// 16830
		case umlPackage::OPERATION_OPERATION_SETISUNIQUE_BOOLEAN:
		{
			//Retrieve input parameter 'newIsUnique'
			//parameter 0
			bool incoming_param_newIsUnique;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_newIsUnique_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_newIsUnique = (*incoming_param_newIsUnique_arguments_citer)->get()->get<bool >();
			this->setIsUnique(incoming_param_newIsUnique);
			break;
		}
		
		// 16831
		case umlPackage::OPERATION_OPERATION_SETLOWER_INTEGER:
		{
			//Retrieve input parameter 'newLower'
			//parameter 0
			int incoming_param_newLower;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_newLower_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_newLower = (*incoming_param_newLower_arguments_citer)->get()->get<int >();
			this->setLower(incoming_param_newLower);
			break;
		}
		
		// 16832
		case umlPackage::OPERATION_OPERATION_SETTYPE_TYPE:
		{
			//Retrieve input parameter 'newType'
			//parameter 0
			std::shared_ptr<uml::Type> incoming_param_newType;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_newType_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_newType = (*incoming_param_newType_arguments_citer)->get()->get<std::shared_ptr<uml::Type> >();
			this->setType(incoming_param_newType);
			break;
		}
		
		// 16833
		case umlPackage::OPERATION_OPERATION_SETUPPER_UNLIMITEDNATURAL:
		{
			//Retrieve input parameter 'newUpper'
			//parameter 0
			int incoming_param_newUpper;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_newUpper_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_newUpper = (*incoming_param_newUpper_arguments_citer)->get()->get<int >();
			this->setUpper(incoming_param_newUpper);
			break;
		}

		default:
		{
			// call superTypes
			result = TemplateableElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = ParameterableElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = BehavioralFeatureImpl::eInvoke(operationID, arguments);
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
void OperationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OperationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isQuery");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsQuery(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("bodyCondition");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("bodyCondition")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("postcondition");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("postcondition")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("precondition");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("precondition")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("redefinedOperation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("redefinedOperation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	BehavioralFeatureImpl::loadAttributes(loadHandler, attr_list);
	ParameterableElementImpl::loadAttributes(loadHandler, attr_list);
	TemplateableElementImpl::loadAttributes(loadHandler, attr_list);
}

void OperationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("ownedParameter") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Parameter";
			}
			loadHandler->handleChildContainer<uml::Parameter>(this->getProperty_OwnedParameter());  

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
	BehavioralFeatureImpl::loadNode(nodeName, loadHandler);
	ParameterableElementImpl::loadNode(nodeName, loadHandler);
	TemplateableElementImpl::loadNode(nodeName, loadHandler);
}

void OperationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::OPERATION_ATTRIBUTE_BODYCONDITION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Constraint> _bodyCondition = std::dynamic_pointer_cast<uml::Constraint>( references.front() );
				setBodyCondition(_bodyCondition);
			}
			
			return;
		}

		case uml::umlPackage::OPERATION_ATTRIBUTE_CLASS:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Class> _class = std::dynamic_pointer_cast<uml::Class>( references.front() );
				setClass(_class);
			}
			
			return;
		}

		case uml::umlPackage::OPERATION_ATTRIBUTE_DATATYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::DataType> _datatype = std::dynamic_pointer_cast<uml::DataType>( references.front() );
				setDatatype(_datatype);
			}
			
			return;
		}

		case uml::umlPackage::OPERATION_ATTRIBUTE_INTERFACE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Interface> _interface = std::dynamic_pointer_cast<uml::Interface>( references.front() );
				setInterface(_interface);
			}
			
			return;
		}

		case uml::umlPackage::OPERATION_ATTRIBUTE_POSTCONDITION:
		{
			std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>> _postcondition = getPostcondition();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Constraint>  _r = std::dynamic_pointer_cast<uml::Constraint>(ref);
				if (_r != nullptr)
				{
					_postcondition->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::OPERATION_ATTRIBUTE_PRECONDITION:
		{
			std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/>> _precondition = getPrecondition();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Constraint>  _r = std::dynamic_pointer_cast<uml::Constraint>(ref);
				if (_r != nullptr)
				{
					_precondition->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::OPERATION_ATTRIBUTE_REDEFINEDOPERATION:
		{
			std::shared_ptr<Subset<uml::Operation, uml::RedefinableElement>> _redefinedOperation = getRedefinedOperation();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Operation>  _r = std::dynamic_pointer_cast<uml::Operation>(ref);
				if (_r != nullptr)
				{
					_redefinedOperation->push_back(_r);
				}
			}
			return;
		}
	}
	BehavioralFeatureImpl::resolveReferences(featureID, references);
	ParameterableElementImpl::resolveReferences(featureID, references);
	TemplateableElementImpl::resolveReferences(featureID, references);
}

void OperationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	BehavioralFeatureImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	TemplateableElementImpl::saveContent(saveHandler);
	
	FeatureImpl::saveContent(saveHandler);
	NamespaceImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
	
}

void OperationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getOperation_Attribute_isQuery()) )
		{
			saveHandler->addAttribute("isQuery", this->getIsQuery());
		}
	// Add references
		saveHandler->addReference(this->getBodyCondition(), "bodyCondition", getBodyCondition()->eClass() != uml::umlPackage::eInstance()->getConstraint_Class()); 
		saveHandler->addReferences<uml::Constraint>("postcondition", this->getPostcondition());
		saveHandler->addReferences<uml::Constraint>("precondition", this->getPrecondition());
		saveHandler->addReferences<uml::Operation>("redefinedOperation", this->getRedefinedOperation());
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'ownedParameter'

		saveHandler->addReferences<uml::Parameter>("ownedParameter", this->getProperty_OwnedParameter());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

