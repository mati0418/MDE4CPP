#include "ocl/Expressions/impl/CollectionItemImpl.hpp"

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

#include "abstractDataTypes/Bag.hpp"


#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ecore/ecoreFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"


#include "ocl/Expressions/CollectionLiteralPart.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ocl/Expressions/OclExpression.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "ecore/ecorePackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Expressions;

//*********************************
// Constructor / Destructor
//*********************************
CollectionItemImpl::CollectionItemImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CollectionItemImpl::~CollectionItemImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CollectionItem "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CollectionItemImpl::CollectionItemImpl(const CollectionItemImpl & obj): CollectionItemImpl()
{
	*this = obj;
}

CollectionItemImpl& CollectionItemImpl::operator=(const CollectionItemImpl & obj)
{
	//call overloaded =Operator for each base class
	CollectionLiteralPartImpl::operator=(obj);
	CollectionItem::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CollectionItem "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	if(obj.getItem()!=nullptr)
	{
		m_item = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(obj.getItem()->copy());
	}
	
	return *this;
}

std::shared_ptr<ecore::EObject> CollectionItemImpl::copy() const
{
	std::shared_ptr<CollectionItemImpl> element(new CollectionItemImpl());
	*element =(*this);
	element->setThisCollectionItemPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CollectionItemImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getCollectionItem_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
/*
Getter & Setter for reference item
*/
std::shared_ptr<ocl::Expressions::OclExpression> CollectionItemImpl::getItem() const
{
//assert(m_item);
    return m_item;
}
void CollectionItemImpl::setItem(std::shared_ptr<ocl::Expressions::OclExpression> _item)
{
    m_item = _item;
	
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<CollectionItem> CollectionItemImpl::getThisCollectionItemPtr() const
{
	return m_thisCollectionItemPtr.lock();
}
void CollectionItemImpl::setThisCollectionItemPtr(std::weak_ptr<CollectionItem> thisCollectionItemPtr)
{
	m_thisCollectionItemPtr = thisCollectionItemPtr;
	setThisCollectionLiteralPartPtr(thisCollectionItemPtr);
}
std::shared_ptr<ecore::EObject> CollectionItemImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CollectionItemImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:
			{
				std::shared_ptr<ecore::EObject> returnValue=getItem();
				return eAny(returnValue); //1110
			}
	}
	return CollectionLiteralPartImpl::eGet(featureID, resolve, coreType);
}
bool CollectionItemImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:
			return getItem() != nullptr; //1110
	}
	return CollectionLiteralPartImpl::internalEIsSet(featureID);
}
bool CollectionItemImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::COLLECTIONITEM_ATTRIBUTE_ITEM:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::OclExpression> _item = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(_temp);
			setItem(_item); //1110
			return true;
		}
	}

	return CollectionLiteralPartImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any CollectionItemImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = CollectionLiteralPartImpl::eInvoke(operationID, arguments);
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
void CollectionItemImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get oclFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void CollectionItemImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	CollectionLiteralPartImpl::loadAttributes(loadHandler, attr_list);
}

void CollectionItemImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("item") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getItem()); 

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
	CollectionLiteralPartImpl::loadNode(nodeName, loadHandler);
}

void CollectionItemImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	CollectionLiteralPartImpl::resolveReferences(featureID, references);
}

void CollectionItemImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CollectionLiteralPartImpl::saveContent(saveHandler);
	
	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void CollectionItemImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'item'

		saveHandler->addReference(this->getItem(), "item", getItem()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Class());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

