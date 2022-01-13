
#include "ecore/impl/EOperationImpl.hpp"

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
#include "ecore/EOperation.hpp"
#include "ecore/EParameter.hpp"
#include "ecore/ETypeParameter.hpp"
#include "ecore/ETypedElement.hpp"
//Factories and Package includes
#include "ecore/ecorePackage.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EOperationImpl::EOperationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EOperationImpl::~EOperationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EOperation "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EOperationImpl::EOperationImpl(std::weak_ptr<ecore::EObject> par_eContainer)
:EOperationImpl()
{
	m_eContainer = par_eContainer;
}

//Additional constructor for the containments back reference
EOperationImpl::EOperationImpl(std::weak_ptr<ecore::EClass> par_eContainingClass)
:EOperationImpl()
{
	m_eContainingClass = par_eContainingClass;
}

EOperationImpl::EOperationImpl(const EOperationImpl & obj): EOperationImpl()
{
	*this = obj;
}

EOperationImpl& EOperationImpl::operator=(const EOperationImpl & obj)
{
	//call overloaded =Operator for each base class
	ETypedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EOperation 
	 * which is generated by the compiler (as EOperation is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EOperation::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EOperation "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_operationID = obj.getOperationID();

	//copy references with no containment (soft copy)
	m_eContainingClass  = obj.getEContainingClass();
	m_eExceptions  = obj.getEExceptions();
	//Clone references with containment (deep copy)
	//clone reference 'eGenericExceptions'
	std::shared_ptr<Bag<ecore::EGenericType>> eGenericExceptionsList = obj.getEGenericExceptions();
	if(eGenericExceptionsList)
	{
		m_eGenericExceptions.reset(new Bag<ecore::EGenericType>());
		
		
		for(const std::shared_ptr<ecore::EGenericType> eGenericExceptionsindexElem: *eGenericExceptionsList) 
		{
			std::shared_ptr<ecore::EGenericType> temp = std::dynamic_pointer_cast<ecore::EGenericType>((eGenericExceptionsindexElem)->copy());
			m_eGenericExceptions->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr eGenericExceptions."<< std::endl;)
	}

	//clone reference 'eParameters'
	std::shared_ptr<Subset<ecore::EParameter, ecore::EObject>> eParametersList = obj.getEParameters();
	if(eParametersList)
	{
		/*Subset*/
		m_eParameters.reset(new Subset<ecore::EParameter, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eParameters - Subset<ecore::EParameter, ecore::EObject >()" << std::endl;
		#endif
		
		/*Subset*/
		getEParameters()->initSubset(getEContentUnion());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eParameters - Subset<ecore::EParameter, ecore::EObject >(getEContentUnion())" << std::endl;
		#endif
		
		for(const std::shared_ptr<ecore::EParameter> eParametersindexElem: *eParametersList) 
		{
			std::shared_ptr<ecore::EParameter> temp = std::dynamic_pointer_cast<ecore::EParameter>((eParametersindexElem)->copy());
			m_eParameters->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr eParameters."<< std::endl;)
	}

	//clone reference 'eTypeParameters'
	std::shared_ptr<Bag<ecore::ETypeParameter>> eTypeParametersList = obj.getETypeParameters();
	if(eTypeParametersList)
	{
		m_eTypeParameters.reset(new Bag<ecore::ETypeParameter>());
		
		
		for(const std::shared_ptr<ecore::ETypeParameter> eTypeParametersindexElem: *eTypeParametersList) 
		{
			std::shared_ptr<ecore::ETypeParameter> temp = std::dynamic_pointer_cast<ecore::ETypeParameter>((eTypeParametersindexElem)->copy());
			m_eTypeParameters->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr eTypeParameters."<< std::endl;)
	}
	
	/*Subset*/
	getEParameters()->initSubset(getEContentUnion());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_eParameters - Subset<ecore::EParameter, ecore::EObject >(getEContentUnion())" << std::endl;
	#endif
	
	
	return *this;
}

std::shared_ptr<ecore::EObject> EOperationImpl::copy() const
{
	std::shared_ptr<EOperationImpl> element(new EOperationImpl());
	*element =(*this);
	element->setThisEOperationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************


bool EOperationImpl::isOverrideOf(std::shared_ptr<ecore::EOperation> someOperation) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<ecore::EClass > containingClass = someOperation->getEContainingClass().lock();
	if(nullptr == containingClass)
	{
		std::cerr << __PRETTY_FUNCTION__ << " containing class not set." << std::endl;
		return false;
	}

	std::shared_ptr<ecore::EClass > thisContainingClass = getEContainingClass().lock();
	if(nullptr == thisContainingClass)
	{
		std::cerr << __PRETTY_FUNCTION__ << " thisContainingClass not set." << std::endl;
		return false;
	}

	if (containingClass->isSuperTypeOf(thisContainingClass) && (someOperation->getName()==getName()))
    {
        std::shared_ptr< Bag<ecore::EParameter> > parameters = getEParameters();
        std::shared_ptr< Bag<ecore::EParameter> > otherParameters = someOperation->getEParameters();
        if (parameters->size() == otherParameters->size())
        {
            for (Bag<EParameter> ::iterator i = parameters->begin(), j = otherParameters->begin(); i != parameters->end(); ++i,++j )
        	{
            	std::shared_ptr<EParameter> parameter = *i;
            	std::shared_ptr<EParameter> otherParameter = *j;
                if (parameter->getEType().get() != otherParameter->getEType().get())
          		{
                    return false;
        		}
        	}
            return true;
		}
	}
    return false;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute operationID */
int EOperationImpl::getOperationID() const 
{
	return m_operationID;
}
void EOperationImpl::setOperationID(int _operationID)
{
	m_operationID = _operationID;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference eContainingClass */
std::weak_ptr<ecore::EClass> EOperationImpl::getEContainingClass() const
{
    return m_eContainingClass;
}

/* Getter & Setter for reference eExceptions */
std::shared_ptr<Bag<ecore::EClassifier>> EOperationImpl::getEExceptions() const
{
	if(m_eExceptions == nullptr)
	{
		m_eExceptions.reset(new Bag<ecore::EClassifier>());
		
		
	}
    return m_eExceptions;
}

/* Getter & Setter for reference eGenericExceptions */
std::shared_ptr<Bag<ecore::EGenericType>> EOperationImpl::getEGenericExceptions() const
{
	if(m_eGenericExceptions == nullptr)
	{
		m_eGenericExceptions.reset(new Bag<ecore::EGenericType>());
		
		
	}
    return m_eGenericExceptions;
}

/* Getter & Setter for reference eParameters */
std::shared_ptr<Subset<ecore::EParameter, ecore::EObject>> EOperationImpl::getEParameters() const
{
	if(m_eParameters == nullptr)
	{
		/*Subset*/
		m_eParameters.reset(new Subset<ecore::EParameter, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eParameters - Subset<ecore::EParameter, ecore::EObject >()" << std::endl;
		#endif
		
		/*Subset*/
		getEParameters()->initSubset(getEContentUnion());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eParameters - Subset<ecore::EParameter, ecore::EObject >(getEContentUnion())" << std::endl;
		#endif
		
	}
    return m_eParameters;
}

/* Getter & Setter for reference eTypeParameters */
std::shared_ptr<Bag<ecore::ETypeParameter>> EOperationImpl::getETypeParameters() const
{
	if(m_eTypeParameters == nullptr)
	{
		m_eTypeParameters.reset(new Bag<ecore::ETypeParameter>());
		
		
	}
    return m_eTypeParameters;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EOperationImpl::getEContentUnion() const
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
std::shared_ptr<ecore::EObject> EOperationImpl::eContainer() const
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
void EOperationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EOperationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("operationID");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'int'
			int value;
			std::istringstream(iter->second) >> value;
			this->setOperationID(value);
		}
		std::shared_ptr<EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("eExceptions");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("eExceptions")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void EOperationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("eGenericExceptions") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EGenericType";
			}
			loadHandler->handleChildContainer<ecore::EGenericType>(this->getEGenericExceptions());  

			return; 
		}

		if ( nodeName.compare("eParameters") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EParameter";
			}
			loadHandler->handleChildContainer<ecore::EParameter>(this->getEParameters());  

			return; 
		}

		if ( nodeName.compare("eTypeParameters") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ETypeParameter";
			}
			loadHandler->handleChildContainer<ecore::ETypeParameter>(this->getETypeParameters());  

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
	ETypedElementImpl::loadNode(nodeName, loadHandler);
}

void EOperationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_EEXCEPTIONS:
		{
			std::shared_ptr<Bag<ecore::EClassifier>> _eExceptions = getEExceptions();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<ecore::EClassifier>  _r = std::dynamic_pointer_cast<ecore::EClassifier>(ref);
				if (_r != nullptr)
				{
					_eExceptions->push_back(_r);
				}
			}
			return;
		}
	}
	ETypedElementImpl::resolveReferences(featureID, references);
}

void EOperationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ETypedElementImpl::saveContent(saveHandler);
	
	ENamedElementImpl::saveContent(saveHandler);
	
	EModelElementImpl::saveContent(saveHandler);
	
	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void EOperationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::ecorePackage> package = ecore::ecorePackage::eInstance();
		// Save 'eParameters'
		for (std::shared_ptr<ecore::EParameter> eParameters : *this->getEParameters()) 
		{
			saveHandler->addReference(eParameters, "eParameters", eParameters->eClass() != package->getEParameter_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getEOperation_Attribute_operationID()) )
		{
			saveHandler->addAttribute("operationID", this->getOperationID());
		}
	// Add references
		saveHandler->addReferences<ecore::EClassifier>("eExceptions", this->getEExceptions());
		//
		// Add new tags (from references)
		//
		std::shared_ptr<EClass> metaClass = this->eClass();
		// Save 'eGenericExceptions'

		saveHandler->addReferences<ecore::EGenericType>("eGenericExceptions", this->getEGenericExceptions());

		// Save 'eTypeParameters'

		saveHandler->addReferences<ecore::ETypeParameter>("eTypeParameters", this->getETypeParameters());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<EClass> EOperationImpl::eStaticClass() const
{
	return ecore::ecorePackage::eInstance()->getEOperation_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any EOperationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_ECONTAININGCLASS:
		{
			std::shared_ptr<ecore::EObject> returnValue=getEContainingClass().lock();
			return eAny(returnValue,ecore::ecorePackage::ECLASS_CLASS,false); //4214
		}
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_EEXCEPTIONS:
			return eAnyBag(getEExceptions(),ecore::ecorePackage::ECLASSIFIER_CLASS); //4217
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_EGENERICEXCEPTIONS:
			return eAnyBag(getEGenericExceptions(),ecore::ecorePackage::EGENERICTYPE_CLASS); //4218
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_EPARAMETERS:
			return eAnyBag(getEParameters(),ecore::ecorePackage::EPARAMETER_CLASS); //4216
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_ETYPEPARAMETERS:
			return eAnyBag(getETypeParameters(),ecore::ecorePackage::ETYPEPARAMETER_CLASS); //4215
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_OPERATIONID:
			return eAny(getOperationID(),ecore::ecorePackage::EINT_CLASS,false); //4213
	}
	return ETypedElementImpl::eGet(featureID, resolve, coreType);
}

bool EOperationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_ECONTAININGCLASS:
			return getEContainingClass().lock() != nullptr; //4214
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_EEXCEPTIONS:
			return getEExceptions() != nullptr; //4217
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_EGENERICEXCEPTIONS:
			return getEGenericExceptions() != nullptr; //4218
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_EPARAMETERS:
			return getEParameters() != nullptr; //4216
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_ETYPEPARAMETERS:
			return getETypeParameters() != nullptr; //4215
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_OPERATIONID:
			return getOperationID() != -1; //4213
	}
	return ETypedElementImpl::internalEIsSet(featureID);
}

bool EOperationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_EEXCEPTIONS:
		{
			// CAST Any to Bag<ecore::EClassifier>
			if((newValue->isContainer()) && (ecore::ecorePackage::ECLASSIFIER_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<ecore::EClassifier>> eExceptionsList= newValue->get<std::shared_ptr<Bag<ecore::EClassifier>>>();
					std::shared_ptr<Bag<ecore::EClassifier>> _eExceptions=getEExceptions();
					for(const std::shared_ptr<ecore::EClassifier> indexEExceptions: *_eExceptions)
					{
						if (eExceptionsList->find(indexEExceptions) == -1)
						{
							_eExceptions->erase(indexEExceptions);
						}
					}

					for(const std::shared_ptr<ecore::EClassifier> indexEExceptions: *eExceptionsList)
					{
						if (_eExceptions->find(indexEExceptions) == -1)
						{
							_eExceptions->add(indexEExceptions);
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
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_EGENERICEXCEPTIONS:
		{
			// CAST Any to Bag<ecore::EGenericType>
			if((newValue->isContainer()) && (ecore::ecorePackage::EGENERICTYPE_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<ecore::EGenericType>> eGenericExceptionsList= newValue->get<std::shared_ptr<Bag<ecore::EGenericType>>>();
					std::shared_ptr<Bag<ecore::EGenericType>> _eGenericExceptions=getEGenericExceptions();
					for(const std::shared_ptr<ecore::EGenericType> indexEGenericExceptions: *_eGenericExceptions)
					{
						if (eGenericExceptionsList->find(indexEGenericExceptions) == -1)
						{
							_eGenericExceptions->erase(indexEGenericExceptions);
						}
					}

					for(const std::shared_ptr<ecore::EGenericType> indexEGenericExceptions: *eGenericExceptionsList)
					{
						if (_eGenericExceptions->find(indexEGenericExceptions) == -1)
						{
							_eGenericExceptions->add(indexEGenericExceptions);
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
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_EPARAMETERS:
		{
			// CAST Any to Bag<ecore::EParameter>
			if((newValue->isContainer()) && (ecore::ecorePackage::EPARAMETER_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<ecore::EParameter>> eParametersList= newValue->get<std::shared_ptr<Bag<ecore::EParameter>>>();
					std::shared_ptr<Bag<ecore::EParameter>> _eParameters=getEParameters();
					for(const std::shared_ptr<ecore::EParameter> indexEParameters: *_eParameters)
					{
						if (eParametersList->find(indexEParameters) == -1)
						{
							_eParameters->erase(indexEParameters);
						}
					}

					for(const std::shared_ptr<ecore::EParameter> indexEParameters: *eParametersList)
					{
						if (_eParameters->find(indexEParameters) == -1)
						{
							_eParameters->add(indexEParameters);
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
		case ecore::ecorePackage::EOPERATION_ATTRIBUTE_ETYPEPARAMETERS:
		{
			// CAST Any to Bag<ecore::ETypeParameter>
			if((newValue->isContainer()) && (ecore::ecorePackage::ETYPEPARAMETER_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<ecore::ETypeParameter>> eTypeParametersList= newValue->get<std::shared_ptr<Bag<ecore::ETypeParameter>>>();
					std::shared_ptr<Bag<ecore::ETypeParameter>> _eTypeParameters=getETypeParameters();
					for(const std::shared_ptr<ecore::ETypeParameter> indexETypeParameters: *_eTypeParameters)
					{
						if (eTypeParametersList->find(indexETypeParameters) == -1)
						{
							_eTypeParameters->erase(indexETypeParameters);
						}
					}

					for(const std::shared_ptr<ecore::ETypeParameter> indexETypeParameters: *eTypeParametersList)
					{
						if (_eTypeParameters->find(indexETypeParameters) == -1)
						{
							_eTypeParameters->add(indexETypeParameters);
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

	return ETypedElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any EOperationImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// ecore::EOperation::isOverrideOf(ecore::EOperation) : bool {const}: 861941010
		case ecorePackage::EOPERATION_OPERATION_ISOVERRIDEOF_EOPERATION:
		{
			//Retrieve input parameter 'someOperation'
			//parameter 0
			std::shared_ptr<ecore::EOperation> incoming_param_someOperation;
			std::list<Any>::const_iterator incoming_param_someOperation_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_someOperation = (*incoming_param_someOperation_arguments_citer)->get<std::shared_ptr<ecore::EOperation> >();
			result = eAny(this->isOverrideOf(incoming_param_someOperation),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = ETypedElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ecore::EOperation> EOperationImpl::getThisEOperationPtr() const
{
	return m_thisEOperationPtr.lock();
}
void EOperationImpl::setThisEOperationPtr(std::weak_ptr<ecore::EOperation> thisEOperationPtr)
{
	m_thisEOperationPtr = thisEOperationPtr;
	setThisETypedElementPtr(thisEOperationPtr);
}


