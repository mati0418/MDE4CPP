
#include "uml/impl/DependencyImpl.hpp"

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
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/DirectedRelationship.hpp"
#include "uml/Element.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DependencyImpl::DependencyImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DependencyImpl::~DependencyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Dependency "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
DependencyImpl::DependencyImpl(std::weak_ptr<uml::Namespace> par_namespace)
:DependencyImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
DependencyImpl::DependencyImpl(std::weak_ptr<uml::Element> par_owner)
:DependencyImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
DependencyImpl::DependencyImpl(std::weak_ptr<uml::Package> par_owningPackage)
:DependencyImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
DependencyImpl::DependencyImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:DependencyImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

DependencyImpl::DependencyImpl(const DependencyImpl & obj): DependencyImpl()
{
	*this = obj;
}

DependencyImpl& DependencyImpl::operator=(const DependencyImpl & obj)
{
	//call overloaded =Operator for each base class
	PackageableElementImpl::operator=(obj);
	DirectedRelationshipImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Dependency 
	 * which is generated by the compiler (as Dependency is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Dependency::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Dependency "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'client'
	std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element>> clientList = obj.getClient();
	if(clientList)
	{
		/*SubsetUnion*/
		m_client.reset(new SubsetUnion<uml::NamedElement, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_client - SubsetUnion<uml::NamedElement, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getClient()->initSubsetUnion(getSource());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_client - SubsetUnion<uml::NamedElement, uml::Element >(getSource())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::NamedElement> clientindexElem: *clientList) 
		{
			std::shared_ptr<uml::NamedElement> temp = std::dynamic_pointer_cast<uml::NamedElement>((clientindexElem)->copy());
			m_client->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr client."<< std::endl;)
	}

	//clone reference 'supplier'
	std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element>> supplierList = obj.getSupplier();
	if(supplierList)
	{
		/*SubsetUnion*/
		m_supplier.reset(new SubsetUnion<uml::NamedElement, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_supplier - SubsetUnion<uml::NamedElement, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getSupplier()->initSubsetUnion(getTarget());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_supplier - SubsetUnion<uml::NamedElement, uml::Element >(getTarget())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::NamedElement> supplierindexElem: *supplierList) 
		{
			std::shared_ptr<uml::NamedElement> temp = std::dynamic_pointer_cast<uml::NamedElement>((supplierindexElem)->copy());
			m_supplier->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr supplier."<< std::endl;)
	}
	return *this;
}

std::shared_ptr<ecore::EObject> DependencyImpl::copy() const
{
	std::shared_ptr<DependencyImpl> element(new DependencyImpl());
	*element =(*this);
	element->setThisDependencyPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference client */
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element>> DependencyImpl::getClient() const
{
	if(m_client == nullptr)
	{
		/*SubsetUnion*/
		m_client.reset(new SubsetUnion<uml::NamedElement, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_client - SubsetUnion<uml::NamedElement, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getClient()->initSubsetUnion(getSource());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_client - SubsetUnion<uml::NamedElement, uml::Element >(getSource())" << std::endl;
		#endif
		
	}
    return m_client;
}

/* Getter & Setter for reference supplier */
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element>> DependencyImpl::getSupplier() const
{
	if(m_supplier == nullptr)
	{
		/*SubsetUnion*/
		m_supplier.reset(new SubsetUnion<uml::NamedElement, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_supplier - SubsetUnion<uml::NamedElement, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getSupplier()->initSubsetUnion(getTarget());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_supplier - SubsetUnion<uml::NamedElement, uml::Element >(getTarget())" << std::endl;
		#endif
		
	}
    return m_supplier;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> DependencyImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> DependencyImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> DependencyImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::Element>> DependencyImpl::getRelatedElement() const
{
	if(m_relatedElement == nullptr)
	{
		/*Union*/
		m_relatedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_relatedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_relatedElement;
}

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> DependencyImpl::getSource() const
{
	if(m_source == nullptr)
	{
		/*SubsetUnion*/
		m_source.reset(new SubsetUnion<uml::Element, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_source - SubsetUnion<uml::Element, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getSource()->initSubsetUnion(getRelatedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_source - SubsetUnion<uml::Element, uml::Element >(getRelatedElement())" << std::endl;
		#endif
		
	}
	return m_source;
}

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> DependencyImpl::getTarget() const
{
	if(m_target == nullptr)
	{
		/*SubsetUnion*/
		m_target.reset(new SubsetUnion<uml::Element, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_target - SubsetUnion<uml::Element, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getTarget()->initSubsetUnion(getRelatedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_target - SubsetUnion<uml::Element, uml::Element >(getRelatedElement())" << std::endl;
		#endif
		
	}
	return m_target;
}



//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> DependencyImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_owningPackage.lock())
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
void DependencyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DependencyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("client");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("client")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("supplier");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("supplier")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	DirectedRelationshipImpl::loadAttributes(loadHandler, attr_list);
	PackageableElementImpl::loadAttributes(loadHandler, attr_list);
}

void DependencyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	DirectedRelationshipImpl::loadNode(nodeName, loadHandler);
	PackageableElementImpl::loadNode(nodeName, loadHandler);
}

void DependencyImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::DEPENDENCY_ATTRIBUTE_CLIENT:
		{
			std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element>> _client = getClient();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::NamedElement>  _r = std::dynamic_pointer_cast<uml::NamedElement>(ref);
				if (_r != nullptr)
				{
					_client->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::DEPENDENCY_ATTRIBUTE_SUPPLIER:
		{
			std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element>> _supplier = getSupplier();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::NamedElement>  _r = std::dynamic_pointer_cast<uml::NamedElement>(ref);
				if (_r != nullptr)
				{
					_supplier->push_back(_r);
				}
			}
			return;
		}
	}
	DirectedRelationshipImpl::resolveReferences(featureID, references);
	PackageableElementImpl::resolveReferences(featureID, references);
}

void DependencyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DirectedRelationshipImpl::saveContent(saveHandler);
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	RelationshipImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void DependencyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReferences<uml::NamedElement>("client", this->getClient());
		saveHandler->addReferences<uml::NamedElement>("supplier", this->getSupplier());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> DependencyImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getDependency_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any DependencyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::DEPENDENCY_ATTRIBUTE_CLIENT:
			return eAnyBag(getClient(),uml::umlPackage::NAMEDELEMENT_CLASS); //6715
		case uml::umlPackage::DEPENDENCY_ATTRIBUTE_SUPPLIER:
			return eAnyBag(getSupplier(),uml::umlPackage::NAMEDELEMENT_CLASS); //6716
	}
	Any result;
	result = DirectedRelationshipImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = PackageableElementImpl::eGet(featureID, resolve, coreType);
	return result;
}

bool DependencyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::DEPENDENCY_ATTRIBUTE_CLIENT:
			return getClient() != nullptr; //6715
		case uml::umlPackage::DEPENDENCY_ATTRIBUTE_SUPPLIER:
			return getSupplier() != nullptr; //6716
	}
	bool result = false;
	result = DirectedRelationshipImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = PackageableElementImpl::internalEIsSet(featureID);
	return result;
}

bool DependencyImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::DEPENDENCY_ATTRIBUTE_CLIENT:
		{
			// CAST Any to Bag<uml::NamedElement>
			if((newValue->isContainer()) && (uml::umlPackage::NAMEDELEMENT_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::NamedElement>> clientList= newValue->get<std::shared_ptr<Bag<uml::NamedElement>>>();
					std::shared_ptr<Bag<uml::NamedElement>> _client=getClient();
					for(const std::shared_ptr<uml::NamedElement> indexClient: *_client)
					{
						if (clientList->find(indexClient) == -1)
						{
							_client->erase(indexClient);
						}
					}

					for(const std::shared_ptr<uml::NamedElement> indexClient: *clientList)
					{
						if (_client->find(indexClient) == -1)
						{
							_client->add(indexClient);
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
		case uml::umlPackage::DEPENDENCY_ATTRIBUTE_SUPPLIER:
		{
			// CAST Any to Bag<uml::NamedElement>
			if((newValue->isContainer()) && (uml::umlPackage::NAMEDELEMENT_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::NamedElement>> supplierList= newValue->get<std::shared_ptr<Bag<uml::NamedElement>>>();
					std::shared_ptr<Bag<uml::NamedElement>> _supplier=getSupplier();
					for(const std::shared_ptr<uml::NamedElement> indexSupplier: *_supplier)
					{
						if (supplierList->find(indexSupplier) == -1)
						{
							_supplier->erase(indexSupplier);
						}
					}

					for(const std::shared_ptr<uml::NamedElement> indexSupplier: *supplierList)
					{
						if (_supplier->find(indexSupplier) == -1)
						{
							_supplier->add(indexSupplier);
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
	result = DirectedRelationshipImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = PackageableElementImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// EOperation Invoke
//*********************************
Any DependencyImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = DirectedRelationshipImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			result = PackageableElementImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Dependency> DependencyImpl::getThisDependencyPtr() const
{
	return m_thisDependencyPtr.lock();
}
void DependencyImpl::setThisDependencyPtr(std::weak_ptr<uml::Dependency> thisDependencyPtr)
{
	m_thisDependencyPtr = thisDependencyPtr;
	setThisDirectedRelationshipPtr(thisDependencyPtr);
	setThisPackageableElementPtr(thisDependencyPtr);
}


