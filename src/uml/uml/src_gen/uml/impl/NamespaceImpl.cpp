
#include "uml/impl/NamespaceImpl.hpp"

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
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/StringExpression.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
NamespaceImpl::NamespaceImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

NamespaceImpl::~NamespaceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Namespace "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
NamespaceImpl::NamespaceImpl(std::weak_ptr<uml::Namespace> par_namespace)
:NamespaceImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
NamespaceImpl::NamespaceImpl(std::weak_ptr<uml::Element> par_owner)
:NamespaceImpl()
{
	m_owner = par_owner;
}

NamespaceImpl::NamespaceImpl(const NamespaceImpl & obj): NamespaceImpl()
{
	*this = obj;
}

NamespaceImpl& NamespaceImpl::operator=(const NamespaceImpl & obj)
{
	//call overloaded =Operator for each base class
	NamedElementImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Namespace 
	 * which is generated by the compiler (as Namespace is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Namespace::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Namespace "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_member  = obj.getMember();
	//Clone references with containment (deep copy)
	//clone reference 'elementImport'
	std::shared_ptr<SubsetUnion<uml::ElementImport, uml::Element>> elementImportList = obj.getElementImport();
	if(elementImportList)
	{
		/*SubsetUnion*/
		m_elementImport.reset(new SubsetUnion<uml::ElementImport, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_elementImport - SubsetUnion<uml::ElementImport, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getElementImport()->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_elementImport - SubsetUnion<uml::ElementImport, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ElementImport> elementImportindexElem: *elementImportList) 
		{
			std::shared_ptr<uml::ElementImport> temp = std::dynamic_pointer_cast<uml::ElementImport>((elementImportindexElem)->copy());
			m_elementImport->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr elementImport."<< std::endl;)
	}

	//clone reference 'importedMember'
	std::shared_ptr<Subset<uml::PackageableElement, uml::NamedElement>> importedMemberList = obj.getImportedMember();
	if(importedMemberList)
	{
		/*Subset*/
		m_importedMember.reset(new Subset<uml::PackageableElement, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_importedMember - Subset<uml::PackageableElement, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getImportedMember()->initSubset(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_importedMember - Subset<uml::PackageableElement, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::PackageableElement> importedMemberindexElem: *importedMemberList) 
		{
			std::shared_ptr<uml::PackageableElement> temp = std::dynamic_pointer_cast<uml::PackageableElement>((importedMemberindexElem)->copy());
			m_importedMember->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr importedMember."<< std::endl;)
	}

	//clone reference 'ownedRule'
	std::shared_ptr<SubsetUnion<uml::Constraint, uml::NamedElement>> ownedRuleList = obj.getOwnedRule();
	if(ownedRuleList)
	{
		/*SubsetUnion*/
		m_ownedRule.reset(new SubsetUnion<uml::Constraint, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedRule - SubsetUnion<uml::Constraint, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOwnedRule()->initSubsetUnion(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedRule - SubsetUnion<uml::Constraint, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::Constraint> ownedRuleindexElem: *ownedRuleList) 
		{
			std::shared_ptr<uml::Constraint> temp = std::dynamic_pointer_cast<uml::Constraint>((ownedRuleindexElem)->copy());
			m_ownedRule->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr ownedRule."<< std::endl;)
	}

	//clone reference 'packageImport'
	std::shared_ptr<SubsetUnion<uml::PackageImport, uml::Element>> packageImportList = obj.getPackageImport();
	if(packageImportList)
	{
		/*SubsetUnion*/
		m_packageImport.reset(new SubsetUnion<uml::PackageImport, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_packageImport - SubsetUnion<uml::PackageImport, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getPackageImport()->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_packageImport - SubsetUnion<uml::PackageImport, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::PackageImport> packageImportindexElem: *packageImportList) 
		{
			std::shared_ptr<uml::PackageImport> temp = std::dynamic_pointer_cast<uml::PackageImport>((packageImportindexElem)->copy());
			m_packageImport->push_back(temp);
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr packageImport."<< std::endl;)
	}
	/*SubsetUnion*/
	getElementImport()->initSubsetUnion(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value SubsetUnion: " << "m_elementImport - SubsetUnion<uml::ElementImport, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	/*SubsetUnion*/
	getOwnedRule()->initSubsetUnion(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value SubsetUnion: " << "m_ownedRule - SubsetUnion<uml::Constraint, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*SubsetUnion*/
	getPackageImport()->initSubsetUnion(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value SubsetUnion: " << "m_packageImport - SubsetUnion<uml::PackageImport, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

//*********************************
// Operations
//*********************************
bool NamespaceImpl::cannot_import_ownedMembers(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool NamespaceImpl::cannot_import_self(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<uml::ElementImport> NamespaceImpl::createElementImport(std::shared_ptr<uml::PackageableElement> element,uml::VisibilityKind visibility)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<uml::PackageImport> NamespaceImpl::createPackageImport(std::shared_ptr<uml::Package> package_,uml::VisibilityKind visibility)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::PackageableElement> > NamespaceImpl::excludeCollisions(std::shared_ptr<Bag<uml::PackageableElement>> imps)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::PackageableElement> > NamespaceImpl::getImportedElements()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::PackageableElement> > NamespaceImpl::getImportedMembers()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::Package> > NamespaceImpl::getImportedPackages()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<std::string> > NamespaceImpl::getNamesOfMember(std::shared_ptr<uml::NamedElement> element)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::NamedElement> > NamespaceImpl::getOwnedMembers()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

std::shared_ptr<Bag<uml::PackageableElement> > NamespaceImpl::importMembers(std::shared_ptr<Bag<uml::PackageableElement>> imps)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool NamespaceImpl::membersAreDistinguishable()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool NamespaceImpl::members_distinguishable(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference elementImport */
std::shared_ptr<SubsetUnion<uml::ElementImport, uml::Element>> NamespaceImpl::getElementImport() const
{
	if(m_elementImport == nullptr)
	{
		/*SubsetUnion*/
		m_elementImport.reset(new SubsetUnion<uml::ElementImport, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_elementImport - SubsetUnion<uml::ElementImport, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getElementImport()->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_elementImport - SubsetUnion<uml::ElementImport, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_elementImport;
}

/* Getter & Setter for reference importedMember */
std::shared_ptr<Subset<uml::PackageableElement, uml::NamedElement>> NamespaceImpl::getImportedMember() const
{
	if(m_importedMember == nullptr)
	{
		/*Subset*/
		m_importedMember.reset(new Subset<uml::PackageableElement, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_importedMember - Subset<uml::PackageableElement, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		getImportedMember()->initSubset(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_importedMember - Subset<uml::PackageableElement, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
    return m_importedMember;
}

/* Getter & Setter for reference member */

/* Getter & Setter for reference ownedMember */

/* Getter & Setter for reference ownedRule */
std::shared_ptr<SubsetUnion<uml::Constraint, uml::NamedElement>> NamespaceImpl::getOwnedRule() const
{
	if(m_ownedRule == nullptr)
	{
		/*SubsetUnion*/
		m_ownedRule.reset(new SubsetUnion<uml::Constraint, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedRule - SubsetUnion<uml::Constraint, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOwnedRule()->initSubsetUnion(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedRule - SubsetUnion<uml::Constraint, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}
    return m_ownedRule;
}

/* Getter & Setter for reference packageImport */
std::shared_ptr<SubsetUnion<uml::PackageImport, uml::Element>> NamespaceImpl::getPackageImport() const
{
	if(m_packageImport == nullptr)
	{
		/*SubsetUnion*/
		m_packageImport.reset(new SubsetUnion<uml::PackageImport, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_packageImport - SubsetUnion<uml::PackageImport, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getPackageImport()->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_packageImport - SubsetUnion<uml::PackageImport, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_packageImport;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::NamedElement>> NamespaceImpl::getMember() const
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

std::shared_ptr<Union<uml::Element>> NamespaceImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element, uml::NamedElement>> NamespaceImpl::getOwnedMember() const
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

std::weak_ptr<uml::Element> NamespaceImpl::getOwner() const
{
	return m_owner;
}

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> NamespaceImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void NamespaceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void NamespaceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void NamespaceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("elementImport") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ElementImport";
			}
			loadHandler->handleChildContainer<uml::ElementImport>(this->getElementImport());  

			return; 
		}

		if ( nodeName.compare("ownedMember") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::NamedElement>(this->getOwnedMember());  

			return; 
		}

		if ( nodeName.compare("ownedRule") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Constraint";
			}
			loadHandler->handleChildContainer<uml::Constraint>(this->getOwnedRule());  

			return; 
		}

		if ( nodeName.compare("packageImport") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "PackageImport";
			}
			loadHandler->handleChildContainer<uml::PackageImport>(this->getPackageImport());  

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
	NamedElementImpl::loadNode(nodeName, loadHandler);
}

void NamespaceImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	NamedElementImpl::resolveReferences(featureID, references);
}

void NamespaceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void NamespaceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'elementImport'

		saveHandler->addReferences<uml::ElementImport>("elementImport", this->getElementImport());

		// Save 'ownedMember'

		saveHandler->addReferences<uml::NamedElement>("ownedMember", this->getOwnedMember());

		// Save 'ownedRule'

		saveHandler->addReferences<uml::Constraint>("ownedRule", this->getOwnedRule());

		// Save 'packageImport'

		saveHandler->addReferences<uml::PackageImport>("packageImport", this->getPackageImport());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> NamespaceImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getNamespace_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any NamespaceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_ELEMENTIMPORT:
			return eAnyBag(getElementImport(),uml::umlPackage::ELEMENTIMPORT_CLASS); //15610
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_IMPORTEDMEMBER:
			return eAnyBag(getImportedMember(),uml::umlPackage::PACKAGEABLEELEMENT_CLASS); //15613
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_MEMBER:
			return eAnyBag(getMember(),uml::umlPackage::NAMEDELEMENT_CLASS); //15614
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_OWNEDMEMBER:
			return eAnyBag(getOwnedMember(),uml::umlPackage::NAMEDELEMENT_CLASS); //15612
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_OWNEDRULE:
			return eAnyBag(getOwnedRule(),uml::umlPackage::CONSTRAINT_CLASS); //1569
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_PACKAGEIMPORT:
			return eAnyBag(getPackageImport(),uml::umlPackage::PACKAGEIMPORT_CLASS); //15611
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}

bool NamespaceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_ELEMENTIMPORT:
			return getElementImport() != nullptr; //15610
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_IMPORTEDMEMBER:
			return getImportedMember() != nullptr; //15613
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_MEMBER:
			return getMember() != nullptr; //15614
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_OWNEDMEMBER:
			return getOwnedMember() != nullptr; //15612
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_OWNEDRULE:
			return getOwnedRule() != nullptr; //1569
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_PACKAGEIMPORT:
			return getPackageImport() != nullptr; //15611
	}
	return NamedElementImpl::internalEIsSet(featureID);
}

bool NamespaceImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_ELEMENTIMPORT:
		{
			// CAST Any to Bag<uml::ElementImport>
			if((newValue->isContainer()) && (uml::umlPackage::ELEMENTIMPORT_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::ElementImport>> elementImportList= newValue->get<std::shared_ptr<Bag<uml::ElementImport>>>();
					std::shared_ptr<Bag<uml::ElementImport>> _elementImport=getElementImport();
					for(const std::shared_ptr<uml::ElementImport> indexElementImport: *_elementImport)
					{
						if (elementImportList->find(indexElementImport) == -1)
						{
							_elementImport->erase(indexElementImport);
						}
					}

					for(const std::shared_ptr<uml::ElementImport> indexElementImport: *elementImportList)
					{
						if (_elementImport->find(indexElementImport) == -1)
						{
							_elementImport->add(indexElementImport);
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
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_OWNEDRULE:
		{
			// CAST Any to Bag<uml::Constraint>
			if((newValue->isContainer()) && (uml::umlPackage::CONSTRAINT_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::Constraint>> ownedRuleList= newValue->get<std::shared_ptr<Bag<uml::Constraint>>>();
					std::shared_ptr<Bag<uml::Constraint>> _ownedRule=getOwnedRule();
					for(const std::shared_ptr<uml::Constraint> indexOwnedRule: *_ownedRule)
					{
						if (ownedRuleList->find(indexOwnedRule) == -1)
						{
							_ownedRule->erase(indexOwnedRule);
						}
					}

					for(const std::shared_ptr<uml::Constraint> indexOwnedRule: *ownedRuleList)
					{
						if (_ownedRule->find(indexOwnedRule) == -1)
						{
							_ownedRule->add(indexOwnedRule);
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
		case uml::umlPackage::NAMESPACE_ATTRIBUTE_PACKAGEIMPORT:
		{
			// CAST Any to Bag<uml::PackageImport>
			if((newValue->isContainer()) && (uml::umlPackage::PACKAGEIMPORT_CLASS ==newValue->getTypeId()))
			{ 
				try
				{
					std::shared_ptr<Bag<uml::PackageImport>> packageImportList= newValue->get<std::shared_ptr<Bag<uml::PackageImport>>>();
					std::shared_ptr<Bag<uml::PackageImport>> _packageImport=getPackageImport();
					for(const std::shared_ptr<uml::PackageImport> indexPackageImport: *_packageImport)
					{
						if (packageImportList->find(indexPackageImport) == -1)
						{
							_packageImport->erase(indexPackageImport);
						}
					}

					for(const std::shared_ptr<uml::PackageImport> indexPackageImport: *packageImportList)
					{
						if (_packageImport->find(indexPackageImport) == -1)
						{
							_packageImport->add(indexPackageImport);
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

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any NamespaceImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// uml::Namespace::cannot_import_ownedMembers(Any, std::map) : bool: 802790798
		case umlPackage::NAMESPACE_OPERATION_CANNOT_IMPORT_OWNEDMEMBERS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->cannot_import_ownedMembers(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Namespace::cannot_import_self(Any, std::map) : bool: 845973580
		case umlPackage::NAMESPACE_OPERATION_CANNOT_IMPORT_SELF_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->cannot_import_self(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::Namespace::createElementImport(uml::PackageableElement, uml::VisibilityKind) : uml::ElementImport: 86368278
		case umlPackage::NAMESPACE_OPERATION_CREATEELEMENTIMPORT_PACKAGEABLEELEMENT_VISIBILITYKIND:
		{
			//Retrieve input parameter 'element'
			//parameter 0
			std::shared_ptr<uml::PackageableElement> incoming_param_element;
			std::list<Any>::const_iterator incoming_param_element_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_element = (*incoming_param_element_arguments_citer)->get<std::shared_ptr<uml::PackageableElement> >();
			//Retrieve input parameter 'visibility'
			//parameter 1
			uml::VisibilityKind incoming_param_visibility;
			std::list<Any>::const_iterator incoming_param_visibility_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_visibility = (*incoming_param_visibility_arguments_citer)->get<uml::VisibilityKind >();
			result = eAny(this->createElementImport(incoming_param_element,incoming_param_visibility), uml::umlPackage::ELEMENTIMPORT_CLASS,false);
			break;
		}
		// uml::Namespace::createPackageImport(uml::Package, uml::VisibilityKind) : uml::PackageImport: 1868922656
		case umlPackage::NAMESPACE_OPERATION_CREATEPACKAGEIMPORT_PACKAGE_VISIBILITYKIND:
		{
			//Retrieve input parameter 'package_'
			//parameter 0
			std::shared_ptr<uml::Package> incoming_param_package_;
			std::list<Any>::const_iterator incoming_param_package__arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_package_ = (*incoming_param_package__arguments_citer)->get<std::shared_ptr<uml::Package> >();
			//Retrieve input parameter 'visibility'
			//parameter 1
			uml::VisibilityKind incoming_param_visibility;
			std::list<Any>::const_iterator incoming_param_visibility_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_visibility = (*incoming_param_visibility_arguments_citer)->get<uml::VisibilityKind >();
			result = eAny(this->createPackageImport(incoming_param_package_,incoming_param_visibility), uml::umlPackage::PACKAGEIMPORT_CLASS,false);
			break;
		}
		// uml::Namespace::excludeCollisions(uml::PackageableElement[*]) : uml::PackageableElement[*]: 1265638945
		case umlPackage::NAMESPACE_OPERATION_EXCLUDECOLLISIONS_PACKAGEABLEELEMENT:
		{
			//Retrieve input parameter 'imps'
			//parameter 0
			std::shared_ptr<Bag<uml::PackageableElement>> incoming_param_imps;
			std::list<Any>::const_iterator incoming_param_imps_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_imps = (*incoming_param_imps_arguments_citer)->get<std::shared_ptr<Bag<uml::PackageableElement>> >();
			std::shared_ptr<Bag<uml::PackageableElement> > resultList = this->excludeCollisions(incoming_param_imps);
			return eAny(resultList,uml::umlPackage::PACKAGEABLEELEMENT_CLASS,true);
			break;
		}
		// uml::Namespace::getImportedElements() : uml::PackageableElement[*]: 951932827
		case umlPackage::NAMESPACE_OPERATION_GETIMPORTEDELEMENTS:
		{
			std::shared_ptr<Bag<uml::PackageableElement> > resultList = this->getImportedElements();
			return eAny(resultList,uml::umlPackage::PACKAGEABLEELEMENT_CLASS,true);
			break;
		}
		// uml::Namespace::getImportedMembers() : uml::PackageableElement[*]: 94967249
		case umlPackage::NAMESPACE_OPERATION_GETIMPORTEDMEMBERS:
		{
			std::shared_ptr<Bag<uml::PackageableElement> > resultList = this->getImportedMembers();
			return eAny(resultList,uml::umlPackage::PACKAGEABLEELEMENT_CLASS,true);
			break;
		}
		// uml::Namespace::getImportedPackages() : uml::Package[*]: 152905544
		case umlPackage::NAMESPACE_OPERATION_GETIMPORTEDPACKAGES:
		{
			std::shared_ptr<Bag<uml::Package> > resultList = this->getImportedPackages();
			return eAny(resultList,uml::umlPackage::PACKAGE_CLASS,true);
			break;
		}
		// uml::Namespace::getNamesOfMember(uml::NamedElement) : std::string[*]: 479584053
		case umlPackage::NAMESPACE_OPERATION_GETNAMESOFMEMBER_NAMEDELEMENT:
		{
			//Retrieve input parameter 'element'
			//parameter 0
			std::shared_ptr<uml::NamedElement> incoming_param_element;
			std::list<Any>::const_iterator incoming_param_element_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_element = (*incoming_param_element_arguments_citer)->get<std::shared_ptr<uml::NamedElement> >();
			result = eAny(this->getNamesOfMember(incoming_param_element),0,true);
			break;
		}
		// uml::Namespace::getOwnedMembers() : uml::NamedElement[*]: 802350881
		case umlPackage::NAMESPACE_OPERATION_GETOWNEDMEMBERS:
		{
			std::shared_ptr<Bag<uml::NamedElement> > resultList = this->getOwnedMembers();
			return eAny(resultList,uml::umlPackage::NAMEDELEMENT_CLASS,true);
			break;
		}
		// uml::Namespace::importMembers(uml::PackageableElement[*]) : uml::PackageableElement[*]: 1832013262
		case umlPackage::NAMESPACE_OPERATION_IMPORTMEMBERS_PACKAGEABLEELEMENT:
		{
			//Retrieve input parameter 'imps'
			//parameter 0
			std::shared_ptr<Bag<uml::PackageableElement>> incoming_param_imps;
			std::list<Any>::const_iterator incoming_param_imps_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_imps = (*incoming_param_imps_arguments_citer)->get<std::shared_ptr<Bag<uml::PackageableElement>> >();
			std::shared_ptr<Bag<uml::PackageableElement> > resultList = this->importMembers(incoming_param_imps);
			return eAny(resultList,uml::umlPackage::PACKAGEABLEELEMENT_CLASS,true);
			break;
		}
		// uml::Namespace::membersAreDistinguishable() : bool: 2129502144
		case umlPackage::NAMESPACE_OPERATION_MEMBERSAREDISTINGUISHABLE:
		{
			result = eAny(this->membersAreDistinguishable(),0,false);
			break;
		}
		// uml::Namespace::members_distinguishable(Any, std::map) : bool: 2127128654
		case umlPackage::NAMESPACE_OPERATION_MEMBERS_DISTINGUISHABLE_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->members_distinguishable(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = NamedElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Namespace> NamespaceImpl::getThisNamespacePtr() const
{
	return m_thisNamespacePtr.lock();
}
void NamespaceImpl::setThisNamespacePtr(std::weak_ptr<uml::Namespace> thisNamespacePtr)
{
	m_thisNamespacePtr = thisNamespacePtr;
	setThisNamedElementPtr(thisNamespacePtr);
}


