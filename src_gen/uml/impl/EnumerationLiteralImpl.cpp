#include "EnumerationLiteralImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Classifier.hpp"

#include "Comment.hpp"

#include "Dependency.hpp"

#include "Deployment.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "Enumeration.hpp"

#include "InstanceSpecification.hpp"

#include "Namespace.hpp"

#include "Package.hpp"

#include "PackageableElement.hpp"

#include "Slot.hpp"

#include "StringExpression.hpp"

#include "TemplateParameter.hpp"

#include "ValueSpecification.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
EnumerationLiteralImpl::EnumerationLiteralImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

	//Init references
	
}

EnumerationLiteralImpl::~EnumerationLiteralImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete EnumerationLiteral "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::Enumeration > par_enumeration)
			:EnumerationLiteralImpl()
			{
			    m_enumeration = par_enumeration;
			}





//Additional constructor for the containments back reference
			EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:EnumerationLiteralImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::Element > par_owner)
			:EnumerationLiteralImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::Package > par_owningPackage)
			:EnumerationLiteralImpl()
			{
			    m_owningPackage = par_owningPackage;
			}





//Additional constructor for the containments back reference
			EnumerationLiteralImpl::EnumerationLiteralImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:EnumerationLiteralImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
			}






EnumerationLiteralImpl::EnumerationLiteralImpl(const EnumerationLiteralImpl & obj):EnumerationLiteralImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy EnumerationLiteral "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Classifier> > _classifier = obj.getClassifier();
	m_classifier.reset(new Bag<uml::Classifier>(*(obj.getClassifier().get())));

	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr< Bag<uml::PackageableElement> > _deployedElement = obj.getDeployedElement();
	m_deployedElement.reset(new Bag<uml::PackageableElement>(*(obj.getDeployedElement().get())));

	m_enumeration  = obj.getEnumeration();

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<uml::Deployment>> _deploymentList = obj.getDeployment();
	for(std::shared_ptr<uml::Deployment> _deployment : *_deploymentList)
	{
		this->getDeployment()->add(std::shared_ptr<uml::Deployment>(std::dynamic_pointer_cast<uml::Deployment>(_deployment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_deployment" << std::endl;
	#endif
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Slot>> _slotList = obj.getSlot();
	for(std::shared_ptr<uml::Slot> _slot : *_slotList)
	{
		this->getSlot()->add(std::shared_ptr<uml::Slot>(std::dynamic_pointer_cast<uml::Slot>(_slot->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_slot" << std::endl;
	#endif
	if(obj.getSpecification()!=nullptr)
	{
		m_specification = std::dynamic_pointer_cast<uml::ValueSpecification>(obj.getSpecification()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_specification" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  EnumerationLiteralImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new EnumerationLiteralImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> EnumerationLiteralImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getEnumerationLiteral();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************


std::shared_ptr<Bag<uml::Classifier> > EnumerationLiteralImpl::getClassifiers() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::weak_ptr<uml::Enumeration > EnumerationLiteralImpl::getEnumeration() const
{
//assert(m_enumeration);
    return m_enumeration;
}
void EnumerationLiteralImpl::setEnumeration(std::shared_ptr<uml::Enumeration> _enumeration)
{
    m_enumeration = _enumeration;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > EnumerationLiteralImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > EnumerationLiteralImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > EnumerationLiteralImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any EnumerationLiteralImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::INSTANCESPECIFICATION_CLASSIFIER:
			return getClassifier(); //7815
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //784
		case UmlPackage::DEPLOYMENTTARGET_DEPLOYEDELEMENT:
			return getDeployedElement(); //7810
		case UmlPackage::DEPLOYMENTTARGET_DEPLOYMENT:
			return getDeployment(); //7811
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //780
		case UmlPackage::ENUMERATIONLITERAL_ENUMERATION:
			return getEnumeration(); //7818
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //785
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //786
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //787
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //781
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //782
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //783
		case UmlPackage::PACKAGEABLEELEMENT_OWNINGPACKAGE:
			return getOwningPackage(); //7812
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //784
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //788
		case UmlPackage::INSTANCESPECIFICATION_SLOT:
			return getSlot(); //7816
		case UmlPackage::INSTANCESPECIFICATION_SPECIFICATION:
			return getSpecification(); //7817
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //785
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //789
	}
	return boost::any();
}
