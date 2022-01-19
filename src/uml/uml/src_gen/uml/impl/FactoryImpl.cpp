
#include "uml/impl/FactoryImpl.hpp"

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
#include "uml/umlFactory.hpp"
#include "uml/Class.hpp"
#include "uml/Comment.hpp"
#include "uml/Element.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
FactoryImpl::FactoryImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

FactoryImpl::~FactoryImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Factory "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
FactoryImpl::FactoryImpl(std::weak_ptr<uml::Element> par_owner)
:FactoryImpl()
{
	m_owner = par_owner;
}

FactoryImpl::FactoryImpl(const FactoryImpl & obj): FactoryImpl()
{
	*this = obj;
}

FactoryImpl& FactoryImpl::operator=(const FactoryImpl & obj)
{
	//call overloaded =Operator for each base class
	ElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Factory 
	 * which is generated by the compiler (as Factory is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Factory::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Factory "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> FactoryImpl::copy() const
{
	std::shared_ptr<FactoryImpl> element(new FactoryImpl());
	*element =(*this);
	element->setThisFactoryPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Element> FactoryImpl::create(std::shared_ptr<uml::Class> metaClass)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> FactoryImpl::getOwnedElement() const
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

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> FactoryImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void FactoryImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void FactoryImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ElementImpl::loadAttributes(loadHandler, attr_list);
}

void FactoryImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ElementImpl::loadNode(nodeName, loadHandler);
}

void FactoryImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ElementImpl::resolveReferences(featureID, references);
}

void FactoryImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void FactoryImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> FactoryImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getFactory_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any FactoryImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}

bool FactoryImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return ElementImpl::internalEIsSet(featureID);
}

bool FactoryImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any FactoryImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// uml::Factory::create(uml::Class) : uml::Element: 486892436
		case umlPackage::FACTORY_OPERATION_CREATE_CLASS:
		{
			//Retrieve input parameter 'metaClass'
			//parameter 0
			std::shared_ptr<uml::Class> incoming_param_metaClass;
			std::list<Any>::const_iterator incoming_param_metaClass_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_metaClass = (*incoming_param_metaClass_arguments_citer)->get<std::shared_ptr<uml::Class> >();
			result = eAny(this->create(incoming_param_metaClass), uml::umlPackage::ELEMENT_CLASS,false);
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

std::shared_ptr<uml::Factory> FactoryImpl::getThisFactoryPtr() const
{
	return m_thisFactoryPtr.lock();
}
void FactoryImpl::setThisFactoryPtr(std::weak_ptr<uml::Factory> thisFactoryPtr)
{
	m_thisFactoryPtr = thisFactoryPtr;
	setThisElementPtr(thisFactoryPtr);
}


