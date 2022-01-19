
#include "fUML/Semantics/SimpleClassifiers/impl/PrimitiveValueImpl.hpp"

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
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"

//Includes from codegen annotation
#include "fUML/fUMLFactory.hpp"
#include "uml/umlFactory.hpp"
#include "uml/PrimitiveType.hpp"
#include "uml/Classifier.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Classifier.hpp"
#include "uml/PrimitiveType.hpp"
#include "fUML/Semantics/Values/Value.hpp"
//Factories and Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace fUML::Semantics::SimpleClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
PrimitiveValueImpl::PrimitiveValueImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

PrimitiveValueImpl::~PrimitiveValueImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PrimitiveValue "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


PrimitiveValueImpl::PrimitiveValueImpl(const PrimitiveValueImpl & obj): PrimitiveValueImpl()
{
	*this = obj;
}

PrimitiveValueImpl& PrimitiveValueImpl::operator=(const PrimitiveValueImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Values::ValueImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of PrimitiveValue 
	 * which is generated by the compiler (as PrimitiveValue is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//PrimitiveValue::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PrimitiveValue "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_type  = obj.getType();
	//Clone references with containment (deep copy)
	return *this;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> PrimitiveValueImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new value that is equal to this primitive value.

std::shared_ptr<fUML::Semantics::SimpleClassifiers::PrimitiveValue> newValue =
	std::dynamic_pointer_cast<fUML::Semantics::SimpleClassifiers::PrimitiveValue>(fUML::Semantics::Values::ValueImpl::_copy());
newValue->setType(this->getType());
return newValue;
	//end of body
}

std::shared_ptr<Bag<uml::Classifier> > PrimitiveValueImpl::getTypes()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::Classifier> > types(new Bag<uml::Classifier>());
	std::shared_ptr<uml::PrimitiveType> type = this->getType();
	if (type != nullptr)
	{
		types->push_back(std::dynamic_pointer_cast<uml::Classifier>(type));
	}
    return types;
	//end of body
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference type */
std::shared_ptr<uml::PrimitiveType> PrimitiveValueImpl::getType() const
{
    return m_type;
}
void PrimitiveValueImpl::setType(std::shared_ptr<uml::PrimitiveType> _type)
{
    m_type = _type;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> PrimitiveValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void PrimitiveValueImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get fUMLFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void PrimitiveValueImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("type");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("type")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	fUML::Semantics::Values::ValueImpl::loadAttributes(loadHandler, attr_list);
}

void PrimitiveValueImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Values::ValueImpl::loadNode(nodeName, loadHandler);
}

void PrimitiveValueImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::PRIMITIVEVALUE_ATTRIBUTE_TYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::PrimitiveType> _type = std::dynamic_pointer_cast<uml::PrimitiveType>( references.front() );
				setType(_type);
			}
			
			return;
		}
	}
	fUML::Semantics::Values::ValueImpl::resolveReferences(featureID, references);
}

void PrimitiveValueImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Values::ValueImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void PrimitiveValueImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage> package = fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getType(), "type", getType()->eClass() != uml::umlPackage::eInstance()->getPrimitiveType_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> PrimitiveValueImpl::eStaticClass() const
{
	return fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getPrimitiveValue_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any PrimitiveValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::PRIMITIVEVALUE_ATTRIBUTE_TYPE:
			return eAny(getType(),uml::umlPackage::PRIMITIVETYPE_CLASS,false); //890
	}
	return fUML::Semantics::Values::ValueImpl::eGet(featureID, resolve, coreType);
}

bool PrimitiveValueImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::PRIMITIVEVALUE_ATTRIBUTE_TYPE:
			return getType() != nullptr; //890
	}
	return fUML::Semantics::Values::ValueImpl::internalEIsSet(featureID);
}

bool PrimitiveValueImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::PRIMITIVEVALUE_ATTRIBUTE_TYPE:
		{
			// CAST Any to uml::PrimitiveType
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::PrimitiveType> _type = std::dynamic_pointer_cast<uml::PrimitiveType>(_temp);
			setType(_type); //890
			return true;
		}
	}

	return fUML::Semantics::Values::ValueImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any PrimitiveValueImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// fUML::Semantics::SimpleClassifiers::PrimitiveValue::_copy() : fUML::Semantics::Values::Value: 1483946573
		case SimpleClassifiersPackage::PRIMITIVEVALUE_OPERATION__COPY:
		{
			result = eAny(this->_copy(), fUML::Semantics::Values::ValuesPackage::VALUE_CLASS,false);
			break;
		}
		// fUML::Semantics::SimpleClassifiers::PrimitiveValue::getTypes() : uml::Classifier[*]: 1603549944
		case SimpleClassifiersPackage::PRIMITIVEVALUE_OPERATION_GETTYPES:
		{
			std::shared_ptr<Bag<uml::Classifier> > resultList = this->getTypes();
			return eAny(resultList,uml::umlPackage::CLASSIFIER_CLASS,true);
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Values::ValueImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<fUML::Semantics::SimpleClassifiers::PrimitiveValue> PrimitiveValueImpl::getThisPrimitiveValuePtr() const
{
	return m_thisPrimitiveValuePtr.lock();
}
void PrimitiveValueImpl::setThisPrimitiveValuePtr(std::weak_ptr<fUML::Semantics::SimpleClassifiers::PrimitiveValue> thisPrimitiveValuePtr)
{
	m_thisPrimitiveValuePtr = thisPrimitiveValuePtr;
	setThisValuePtr(thisPrimitiveValuePtr);
}


