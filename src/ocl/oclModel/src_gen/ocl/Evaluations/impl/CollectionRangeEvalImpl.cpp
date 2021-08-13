#include "ocl/Evaluations/impl/CollectionRangeEvalImpl.hpp"

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

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Values/ValuesFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"


#include "ocl/Evaluations/CollectionLiteralPartEval.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Evaluations;

//*********************************
// Constructor / Destructor
//*********************************
CollectionRangeEvalImpl::CollectionRangeEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CollectionRangeEvalImpl::~CollectionRangeEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CollectionRangeEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CollectionRangeEvalImpl::CollectionRangeEvalImpl(const CollectionRangeEvalImpl & obj): CollectionRangeEvalImpl()
{
	*this = obj;
}

CollectionRangeEvalImpl& CollectionRangeEvalImpl::operator=(const CollectionRangeEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	CollectionLiteralPartEvalImpl::operator=(obj);
	CollectionRangeEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CollectionRangeEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_first  = obj.getFirst();
	m_last  = obj.getLast();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CollectionRangeEvalImpl::copy() const
{
	std::shared_ptr<CollectionRangeEvalImpl> element(new CollectionRangeEvalImpl());
	*element =(*this);
	element->setThisCollectionRangeEvalPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CollectionRangeEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getCollectionRangeEval_Class();
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
Getter & Setter for reference first
*/
std::shared_ptr<ocl::Evaluations::OclExpEval> CollectionRangeEvalImpl::getFirst() const
{
//assert(m_first);
    return m_first;
}
void CollectionRangeEvalImpl::setFirst(std::shared_ptr<ocl::Evaluations::OclExpEval> _first)
{
    m_first = _first;
	
}


/*
Getter & Setter for reference last
*/
std::shared_ptr<ocl::Evaluations::OclExpEval> CollectionRangeEvalImpl::getLast() const
{
//assert(m_last);
    return m_last;
}
void CollectionRangeEvalImpl::setLast(std::shared_ptr<ocl::Evaluations::OclExpEval> _last)
{
    m_last = _last;
	
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<CollectionRangeEval> CollectionRangeEvalImpl::getThisCollectionRangeEvalPtr() const
{
	return m_thisCollectionRangeEvalPtr.lock();
}
void CollectionRangeEvalImpl::setThisCollectionRangeEvalPtr(std::weak_ptr<CollectionRangeEval> thisCollectionRangeEvalPtr)
{
	m_thisCollectionRangeEvalPtr = thisCollectionRangeEvalPtr;
	setThisCollectionLiteralPartEvalPtr(thisCollectionRangeEvalPtr);
}
std::shared_ptr<ecore::EObject> CollectionRangeEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CollectionRangeEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::COLLECTIONRANGEEVAL_ATTRIBUTE_FIRST:
			{
				std::shared_ptr<ecore::EObject> returnValue=getFirst();
				return eAny(returnValue); //193
			}
		case ocl::Evaluations::EvaluationsPackage::COLLECTIONRANGEEVAL_ATTRIBUTE_LAST:
			{
				std::shared_ptr<ecore::EObject> returnValue=getLast();
				return eAny(returnValue); //194
			}
	}
	return CollectionLiteralPartEvalImpl::eGet(featureID, resolve, coreType);
}
bool CollectionRangeEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::COLLECTIONRANGEEVAL_ATTRIBUTE_FIRST:
			return getFirst() != nullptr; //193
		case ocl::Evaluations::EvaluationsPackage::COLLECTIONRANGEEVAL_ATTRIBUTE_LAST:
			return getLast() != nullptr; //194
	}
	return CollectionLiteralPartEvalImpl::internalEIsSet(featureID);
}
bool CollectionRangeEvalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::COLLECTIONRANGEEVAL_ATTRIBUTE_FIRST:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Evaluations::OclExpEval> _first = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(_temp);
			setFirst(_first); //193
			return true;
		}
		case ocl::Evaluations::EvaluationsPackage::COLLECTIONRANGEEVAL_ATTRIBUTE_LAST:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Evaluations::OclExpEval> _last = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>(_temp);
			setLast(_last); //194
			return true;
		}
	}

	return CollectionLiteralPartEvalImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any CollectionRangeEvalImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = CollectionLiteralPartEvalImpl::eInvoke(operationID, arguments);
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
void CollectionRangeEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CollectionRangeEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("first");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("first")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("last");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("last")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	CollectionLiteralPartEvalImpl::loadAttributes(loadHandler, attr_list);
}

void CollectionRangeEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	CollectionLiteralPartEvalImpl::loadNode(nodeName, loadHandler);
}

void CollectionRangeEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::COLLECTIONRANGEEVAL_ATTRIBUTE_FIRST:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::OclExpEval> _first = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>( references.front() );
				setFirst(_first);
			}
			
			return;
		}

		case ocl::Evaluations::EvaluationsPackage::COLLECTIONRANGEEVAL_ATTRIBUTE_LAST:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::OclExpEval> _last = std::dynamic_pointer_cast<ocl::Evaluations::OclExpEval>( references.front() );
				setLast(_last);
			}
			
			return;
		}
	}
	CollectionLiteralPartEvalImpl::resolveReferences(featureID, references);
}

void CollectionRangeEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CollectionLiteralPartEvalImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void CollectionRangeEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getFirst(), "first", getFirst()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Class()); 
		saveHandler->addReference(this->getLast(), "last", getLast()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

