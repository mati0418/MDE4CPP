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

//Factories an Package includes
#include "fUML/Semantics/SemanticsPackage.hpp"
#include "fUML/fUMLPackage.hpp"
#include "fUML/Semantics/SimpleClassifiers/SimpleClassifiersPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
	PrimitiveValue::operator=(obj);

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

std::shared_ptr<ecore::EObject> PrimitiveValueImpl::copy() const
{
	std::shared_ptr<PrimitiveValueImpl> element(new PrimitiveValueImpl());
	*element =(*this);
	element->setThisPrimitiveValuePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> PrimitiveValueImpl::eStaticClass() const
{
	return fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::eInstance()->getPrimitiveValue_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<fUML::Semantics::Values::Value> PrimitiveValueImpl::_copy()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	// Create a new value that is equal to this primitive value.

std::shared_ptr<fUML::Semantics::SimpleClassifiers::PrimitiveValue> newValue(new fUML::Semantics::SimpleClassifiers::PrimitiveValueImpl());
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
// References
//*********************************
/*
Getter & Setter for reference type
*/
std::shared_ptr<uml::PrimitiveType> PrimitiveValueImpl::getType() const
{
//assert(m_type);
    return m_type;
}
void PrimitiveValueImpl::setType(std::shared_ptr<uml::PrimitiveType> _type)
{
    m_type = _type;
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<PrimitiveValue> PrimitiveValueImpl::getThisPrimitiveValuePtr() const
{
	return m_thisPrimitiveValuePtr.lock();
}
void PrimitiveValueImpl::setThisPrimitiveValuePtr(std::weak_ptr<PrimitiveValue> thisPrimitiveValuePtr)
{
	m_thisPrimitiveValuePtr = thisPrimitiveValuePtr;
	setThisValuePtr(thisPrimitiveValuePtr);
}
std::shared_ptr<ecore::EObject> PrimitiveValueImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any PrimitiveValueImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case fUML::Semantics::SimpleClassifiers::SimpleClassifiersPackage::PRIMITIVEVALUE_ATTRIBUTE_TYPE:
			return eAny(getType()); //890
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
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::PrimitiveType> _type = std::dynamic_pointer_cast<uml::PrimitiveType>(_temp);
			setType(_type); //890
			return true;
		}
	}

	return fUML::Semantics::Values::ValueImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any PrimitiveValueImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 8912
		case SimpleClassifiersPackage::PRIMITIVEVALUE_OPERATION__COPY:
		{
			result = eAny(this->_copy());
			break;
		}
		
		// 8911
		case SimpleClassifiersPackage::PRIMITIVEVALUE_OPERATION_GETTYPES:
		{
			result = eAny(this->getTypes());
			break;
		}

		default:
		{
			// call superTypes
			result = fUML::Semantics::Values::ValueImpl::eInvoke(operationID, arguments);
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

