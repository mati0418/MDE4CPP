
#include "uml/impl/ProfileApplicationImpl.hpp"

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
#include "uml/DirectedRelationship.hpp"
#include "ecore/ENamedElement.hpp"
#include "ecore/EPackage.hpp"
#include "uml/Element.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Package.hpp"
#include "uml/Profile.hpp"
//Factories and Package includes
#include "ecore/ecorePackage.hpp"
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ProfileApplicationImpl::ProfileApplicationImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ProfileApplicationImpl::~ProfileApplicationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ProfileApplication "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ProfileApplicationImpl::ProfileApplicationImpl(std::weak_ptr<uml::Package> par_applyingPackage)
:ProfileApplicationImpl()
{
	m_applyingPackage = par_applyingPackage;
	m_owner = par_applyingPackage;
}

//Additional constructor for the containments back reference
ProfileApplicationImpl::ProfileApplicationImpl(std::weak_ptr<uml::Element> par_owner)
:ProfileApplicationImpl()
{
	m_owner = par_owner;
}

ProfileApplicationImpl::ProfileApplicationImpl(const ProfileApplicationImpl & obj): ProfileApplicationImpl()
{
	*this = obj;
}

ProfileApplicationImpl& ProfileApplicationImpl::operator=(const ProfileApplicationImpl & obj)
{
	//call overloaded =Operator for each base class
	DirectedRelationshipImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ProfileApplication 
	 * which is generated by the compiler (as ProfileApplication is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ProfileApplication::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ProfileApplication "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isStrict = obj.getIsStrict();

	//copy references with no containment (soft copy)
	m_applyingPackage  = obj.getApplyingPackage();
	//Clone references with containment (deep copy)
	//clone reference 'appliedProfile'
	if(obj.getAppliedProfile()!=nullptr)
	{
		m_appliedProfile = std::dynamic_pointer_cast<uml::Profile>(obj.getAppliedProfile()->copy());
	}
	return *this;
}

std::shared_ptr<ecore::EObject> ProfileApplicationImpl::copy() const
{
	std::shared_ptr<ProfileApplicationImpl> element(new ProfileApplicationImpl());
	*element =(*this);
	element->setThisProfileApplicationPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<ecore::EPackage> ProfileApplicationImpl::getAppliedDefinition()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::ENamedElement> ProfileApplicationImpl::getAppliedDefinition(std::shared_ptr<uml::NamedElement> namedElement)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isStrict */
bool ProfileApplicationImpl::getIsStrict() const 
{
	return m_isStrict;
}
void ProfileApplicationImpl::setIsStrict(bool _isStrict)
{
	m_isStrict = _isStrict;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference appliedProfile */
std::shared_ptr<uml::Profile> ProfileApplicationImpl::getAppliedProfile() const
{
    return m_appliedProfile;
}
void ProfileApplicationImpl::setAppliedProfile(std::shared_ptr<uml::Profile> _appliedProfile)
{
    m_appliedProfile = _appliedProfile;
	
}

/* Getter & Setter for reference applyingPackage */
std::weak_ptr<uml::Package> ProfileApplicationImpl::getApplyingPackage() const
{
    return m_applyingPackage;
}
void ProfileApplicationImpl::setApplyingPackage(std::weak_ptr<uml::Package> _applyingPackage)
{
    m_applyingPackage = _applyingPackage;
	
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> ProfileApplicationImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ProfileApplicationImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::Element>> ProfileApplicationImpl::getRelatedElement() const
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

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> ProfileApplicationImpl::getSource() const
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

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> ProfileApplicationImpl::getTarget() const
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
std::shared_ptr<ecore::EObject> ProfileApplicationImpl::eContainer() const
{
	if(auto wp = m_applyingPackage.lock())
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
void ProfileApplicationImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ProfileApplicationImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isStrict");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsStrict(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("appliedProfile");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("appliedProfile")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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
}

void ProfileApplicationImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	DirectedRelationshipImpl::loadNode(nodeName, loadHandler);
}

void ProfileApplicationImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::PROFILEAPPLICATION_ATTRIBUTE_APPLIEDPROFILE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Profile> _appliedProfile = std::dynamic_pointer_cast<uml::Profile>( references.front() );
				setAppliedProfile(_appliedProfile);
			}
			
			return;
		}

		case uml::umlPackage::PROFILEAPPLICATION_ATTRIBUTE_APPLYINGPACKAGE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Package> _applyingPackage = std::dynamic_pointer_cast<uml::Package>( references.front() );
				setApplyingPackage(_applyingPackage);
			}
			
			return;
		}
	}
	DirectedRelationshipImpl::resolveReferences(featureID, references);
}

void ProfileApplicationImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DirectedRelationshipImpl::saveContent(saveHandler);
	
	RelationshipImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ProfileApplicationImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getProfileApplication_Attribute_isStrict()) )
		{
			saveHandler->addAttribute("isStrict", this->getIsStrict());
		}
	// Add references
		saveHandler->addReference(this->getAppliedProfile(), "appliedProfile", getAppliedProfile()->eClass() != uml::umlPackage::eInstance()->getProfile_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ProfileApplicationImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getProfileApplication_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ProfileApplicationImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::PROFILEAPPLICATION_ATTRIBUTE_APPLIEDPROFILE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getAppliedProfile();
			return eAny(returnValue,uml::umlPackage::PROFILE_CLASS,false); //1846
		}
		case uml::umlPackage::PROFILEAPPLICATION_ATTRIBUTE_APPLYINGPACKAGE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getApplyingPackage().lock();
			return eAny(returnValue,uml::umlPackage::PACKAGE_CLASS,false); //1848
		}
		case uml::umlPackage::PROFILEAPPLICATION_ATTRIBUTE_ISSTRICT:
			return eAny(getIsStrict(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //1847
	}
	return DirectedRelationshipImpl::eGet(featureID, resolve, coreType);
}

bool ProfileApplicationImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::PROFILEAPPLICATION_ATTRIBUTE_APPLIEDPROFILE:
			return getAppliedProfile() != nullptr; //1846
		case uml::umlPackage::PROFILEAPPLICATION_ATTRIBUTE_APPLYINGPACKAGE:
			return getApplyingPackage().lock() != nullptr; //1848
		case uml::umlPackage::PROFILEAPPLICATION_ATTRIBUTE_ISSTRICT:
			return getIsStrict() != false; //1847
	}
	return DirectedRelationshipImpl::internalEIsSet(featureID);
}

bool ProfileApplicationImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::PROFILEAPPLICATION_ATTRIBUTE_APPLIEDPROFILE:
		{
			// CAST Any to uml::Profile
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Profile> _appliedProfile = std::dynamic_pointer_cast<uml::Profile>(_temp);
			setAppliedProfile(_appliedProfile); //1846
			return true;
		}
		case uml::umlPackage::PROFILEAPPLICATION_ATTRIBUTE_APPLYINGPACKAGE:
		{
			// CAST Any to uml::Package
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Package> _applyingPackage = std::dynamic_pointer_cast<uml::Package>(_temp);
			setApplyingPackage(_applyingPackage); //1848
			return true;
		}
		case uml::umlPackage::PROFILEAPPLICATION_ATTRIBUTE_ISSTRICT:
		{
			// CAST Any to bool
			bool _isStrict = newValue->get<bool>();
			setIsStrict(_isStrict); //1847
			return true;
		}
	}

	return DirectedRelationshipImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ProfileApplicationImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// uml::ProfileApplication::getAppliedDefinition() : ecore::EPackage: 1871054573
		case umlPackage::PROFILEAPPLICATION_OPERATION_GETAPPLIEDDEFINITION:
		{
			result = eAny(this->getAppliedDefinition(), ecore::ecorePackage::EPACKAGE_CLASS,false);
			break;
		}
		// uml::ProfileApplication::getAppliedDefinition(uml::NamedElement) : ecore::ENamedElement: 1978495829
		case umlPackage::PROFILEAPPLICATION_OPERATION_GETAPPLIEDDEFINITION_NAMEDELEMENT:
		{
			//Retrieve input parameter 'namedElement'
			//parameter 0
			std::shared_ptr<uml::NamedElement> incoming_param_namedElement;
			std::list<Any>::const_iterator incoming_param_namedElement_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_namedElement = (*incoming_param_namedElement_arguments_citer)->get<std::shared_ptr<uml::NamedElement> >();
			result = eAny(this->getAppliedDefinition(incoming_param_namedElement), ecore::ecorePackage::ENAMEDELEMENT_CLASS,false);
			break;
		}

		default:
		{
			// call superTypes
			result = DirectedRelationshipImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::ProfileApplication> ProfileApplicationImpl::getThisProfileApplicationPtr() const
{
	return m_thisProfileApplicationPtr.lock();
}
void ProfileApplicationImpl::setThisProfileApplicationPtr(std::weak_ptr<uml::ProfileApplication> thisProfileApplicationPtr)
{
	m_thisProfileApplicationPtr = thisProfileApplicationPtr;
	setThisDirectedRelationshipPtr(thisProfileApplicationPtr);
}

