
#include "ecore/impl/EEnumImpl.hpp"

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
#include "ecore/EDataType.hpp"
#include "ecore/EEnumLiteral.hpp"
#include "ecore/EObject.hpp"
#include "ecore/EPackage.hpp"
#include "ecore/ETypeParameter.hpp"
//Factories and Package includes
#include "ecore/ecorePackage.hpp"

using namespace ecore;

//*********************************
// Constructor / Destructor
//*********************************
EEnumImpl::EEnumImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

EEnumImpl::~EEnumImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EEnum "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
EEnumImpl::EEnumImpl(std::weak_ptr<ecore::EObject> par_eContainer)
:EEnumImpl()
{
	m_eContainer = par_eContainer;
}

//Additional constructor for the containments back reference
EEnumImpl::EEnumImpl(std::weak_ptr<ecore::EPackage> par_ePackage)
:EEnumImpl()
{
	m_ePackage = par_ePackage;
}

EEnumImpl::EEnumImpl(const EEnumImpl & obj): EEnumImpl()
{
	*this = obj;
}

EEnumImpl& EEnumImpl::operator=(const EEnumImpl & obj)
{
	//call overloaded =Operator for each base class
	EDataTypeImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of EEnum 
	 * which is generated by the compiler (as EEnum is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//EEnum::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EEnum "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'eLiterals'
	std::shared_ptr<Subset<ecore::EEnumLiteral, ecore::EObject>> eLiteralsList = obj.getELiterals();
	if(eLiteralsList)
	{
		/*Subset*/
		m_eLiterals.reset(new Subset<ecore::EEnumLiteral, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eLiterals - Subset<ecore::EEnumLiteral, ecore::EObject >()" << std::endl;
		#endif
		
		/*Subset*/
		getELiterals()->initSubset(getEContentUnion());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eLiterals - Subset<ecore::EEnumLiteral, ecore::EObject >(getEContentUnion())" << std::endl;
		#endif
		
		for(const std::shared_ptr<ecore::EEnumLiteral> eLiteralsindexElem: *eLiteralsList) 
		{
			std::shared_ptr<ecore::EEnumLiteral> temp = std::dynamic_pointer_cast<ecore::EEnumLiteral>((eLiteralsindexElem)->copy());
			m_eLiterals->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr eLiterals."<< std::endl;)
	}
	/*Subset*/
	getELiterals()->initSubset(getEContentUnion());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_eLiterals - Subset<ecore::EEnumLiteral, ecore::EObject >(getEContentUnion())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> EEnumImpl::copy() const
{
	std::shared_ptr<EEnumImpl> element(new EEnumImpl());
	*element =(*this);
	element->setThisEEnumPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<ecore::EEnumLiteral> EEnumImpl::getEEnumLiteral(std::string name) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    for (std::shared_ptr<EEnumLiteral> e : *getELiterals())
    {
        if(e->getName()==name)
        {
            return e;
        }
    }
    return std::shared_ptr<ecore::EEnumLiteral>();
	//end of body
}

std::shared_ptr<ecore::EEnumLiteral> EEnumImpl::getEEnumLiteral(int value) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    for (std::shared_ptr<EEnumLiteral> e : *getELiterals())
    {
        if(e->getValue()==value)
        {
            return e;
        }
    }
    return std::shared_ptr<ecore::EEnumLiteral>();

	//end of body
}

std::shared_ptr<ecore::EEnumLiteral> EEnumImpl::getEEnumLiteralByLiteral(std::string literal) const
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    for (std::shared_ptr<EEnumLiteral> e : *getELiterals())
    {
        if(e->getLiteral()==literal)
        {
            return e;
        }
    }
    return std::shared_ptr<ecore::EEnumLiteral>  ();
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference eLiterals */
std::shared_ptr<Subset<ecore::EEnumLiteral, ecore::EObject>> EEnumImpl::getELiterals() const
{
	if(m_eLiterals == nullptr)
	{
		/*Subset*/
		m_eLiterals.reset(new Subset<ecore::EEnumLiteral, ecore::EObject >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_eLiterals - Subset<ecore::EEnumLiteral, ecore::EObject >()" << std::endl;
		#endif
		
		/*Subset*/
		getELiterals()->initSubset(getEContentUnion());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_eLiterals - Subset<ecore::EEnumLiteral, ecore::EObject >(getEContentUnion())" << std::endl;
		#endif
		
	}
    return m_eLiterals;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<ecore::EObject>> EEnumImpl::getEContentUnion() const
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
std::shared_ptr<ecore::EObject> EEnumImpl::eContainer() const
{
	if(auto wp = m_eContainer.lock())
	{
		return wp;
	}

	if(auto wp = m_ePackage.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void EEnumImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void EEnumImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	EDataTypeImpl::loadAttributes(loadHandler, attr_list);
}

void EEnumImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("eLiterals") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "EEnumLiteral";
			}
			loadHandler->handleChildContainer<ecore::EEnumLiteral>(this->getELiterals());  

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
	EDataTypeImpl::loadNode(nodeName, loadHandler);
}

void EEnumImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references)
{
	EDataTypeImpl::resolveReferences(featureID, references);
}

void EEnumImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	EDataTypeImpl::saveContent(saveHandler);
	
	EClassifierImpl::saveContent(saveHandler);
	
	ENamedElementImpl::saveContent(saveHandler);
	
	EModelElementImpl::saveContent(saveHandler);
	
	EObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void EEnumImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ecore::ecorePackage> package = ecore::ecorePackage::eInstance();
		// Save 'eLiterals'
		for (std::shared_ptr<ecore::EEnumLiteral> eLiterals : *this->getELiterals()) 
		{
			saveHandler->addReference(eLiterals, "eLiterals", eLiterals->eClass() != package->getEEnumLiteral_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<EClass> EEnumImpl::eStaticClass() const
{
	return ecore::ecorePackage::eInstance()->getEEnum_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any EEnumImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EENUM_ATTRIBUTE_ELITERALS:
			return eAnyBag(getELiterals(),ecore::ecorePackage::EENUMLITERAL_CLASS); //2112
	}
	return EDataTypeImpl::eGet(featureID, resolve, coreType);
}

bool EEnumImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ecore::ecorePackage::EENUM_ATTRIBUTE_ELITERALS:
			return getELiterals() != nullptr; //2112
	}
	return EDataTypeImpl::internalEIsSet(featureID);
}

bool EEnumImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ecore::ecorePackage::EENUM_ATTRIBUTE_ELITERALS:
		{
			// CAST Any to Bag<ecore::EEnumLiteral>
			if((newValue->isContainer()) && (ecore::ecorePackage::EENUMLITERAL_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<ecore::EEnumLiteral>> eLiteralsList= newValue->get<std::shared_ptr<Bag<ecore::EEnumLiteral>>>();
					std::shared_ptr<Bag<ecore::EEnumLiteral>> _eLiterals=getELiterals();
					for(const std::shared_ptr<ecore::EEnumLiteral> indexELiterals: *_eLiterals)
					{
						if (eLiteralsList->find(indexELiterals) == -1)
						{
							_eLiterals->erase(indexELiterals);
						}
					}

					for(const std::shared_ptr<ecore::EEnumLiteral> indexELiterals: *eLiteralsList)
					{
						if (_eLiterals->find(indexELiterals) == -1)
						{
							_eLiterals->add(indexELiterals);
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

	return EDataTypeImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any EEnumImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// ecore::EEnum::getEEnumLiteral(std::string) : ecore::EEnumLiteral {const}: 1917703622
		case ecorePackage::EENUM_OPERATION_GETEENUMLITERAL_ESTRING:
		{
			//Retrieve input parameter 'name'
			//parameter 0
			std::string incoming_param_name;
			std::list<Any>::const_iterator incoming_param_name_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_name = (*incoming_param_name_arguments_citer)->get<std::string >();
			result = eAny(this->getEEnumLiteral(incoming_param_name), ecore::ecorePackage::EENUMLITERAL_CLASS,false);
			break;
		}
		// ecore::EEnum::getEEnumLiteral(int) : ecore::EEnumLiteral {const}: 1070395435
		case ecorePackage::EENUM_OPERATION_GETEENUMLITERAL_EINT:
		{
			//Retrieve input parameter 'value'
			//parameter 0
			int incoming_param_value;
			std::list<Any>::const_iterator incoming_param_value_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_value = (*incoming_param_value_arguments_citer)->get<int >();
			result = eAny(this->getEEnumLiteral(incoming_param_value), ecore::ecorePackage::EENUMLITERAL_CLASS,false);
			break;
		}
		// ecore::EEnum::getEEnumLiteralByLiteral(std::string) : ecore::EEnumLiteral {const}: 582537382
		case ecorePackage::EENUM_OPERATION_GETEENUMLITERALBYLITERAL_ESTRING:
		{
			//Retrieve input parameter 'literal'
			//parameter 0
			std::string incoming_param_literal;
			std::list<Any>::const_iterator incoming_param_literal_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_literal = (*incoming_param_literal_arguments_citer)->get<std::string >();
			result = eAny(this->getEEnumLiteralByLiteral(incoming_param_literal), ecore::ecorePackage::EENUMLITERAL_CLASS,false);
			break;
		}

		default:
		{
			// call superTypes
			result = EDataTypeImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ecore::EEnum> EEnumImpl::getThisEEnumPtr() const
{
	return m_thisEEnumPtr.lock();
}
void EEnumImpl::setThisEEnumPtr(std::weak_ptr<ecore::EEnum> thisEEnumPtr)
{
	m_thisEEnumPtr = thisEEnumPtr;
	setThisEDataTypePtr(thisEEnumPtr);
}


