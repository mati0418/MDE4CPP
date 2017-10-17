#include "DestructionOccurrenceSpecificationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Comment.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "Element.hpp"

#include "GeneralOrdering.hpp"

#include "Interaction.hpp"

#include "InteractionOperand.hpp"

#include "Lifeline.hpp"

#include "Message.hpp"

#include "MessageOccurrenceSpecification.hpp"

#include "Namespace.hpp"

#include "StringExpression.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DestructionOccurrenceSpecificationImpl::DestructionOccurrenceSpecificationImpl()
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

DestructionOccurrenceSpecificationImpl::~DestructionOccurrenceSpecificationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DestructionOccurrenceSpecification "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			DestructionOccurrenceSpecificationImpl::DestructionOccurrenceSpecificationImpl(std::weak_ptr<uml::Interaction > par_enclosingInteraction)
			:DestructionOccurrenceSpecificationImpl()
			{
			    m_enclosingInteraction = par_enclosingInteraction;
			}





//Additional constructor for the containments back reference
			DestructionOccurrenceSpecificationImpl::DestructionOccurrenceSpecificationImpl(std::weak_ptr<uml::InteractionOperand > par_enclosingOperand)
			:DestructionOccurrenceSpecificationImpl()
			{
			    m_enclosingOperand = par_enclosingOperand;
			}





//Additional constructor for the containments back reference
			DestructionOccurrenceSpecificationImpl::DestructionOccurrenceSpecificationImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:DestructionOccurrenceSpecificationImpl()
			{
			    m_namespace = par_namespace;
			}





//Additional constructor for the containments back reference
			DestructionOccurrenceSpecificationImpl::DestructionOccurrenceSpecificationImpl(std::weak_ptr<uml::Element > par_owner)
			:DestructionOccurrenceSpecificationImpl()
			{
			    m_owner = par_owner;
			}






DestructionOccurrenceSpecificationImpl::DestructionOccurrenceSpecificationImpl(const DestructionOccurrenceSpecificationImpl & obj):DestructionOccurrenceSpecificationImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DestructionOccurrenceSpecification "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr< Bag<uml::Lifeline> > _covered = obj.getCovered();
	m_covered.reset(new Bag<uml::Lifeline>(*(obj.getCovered().get())));

	m_enclosingInteraction  = obj.getEnclosingInteraction();

	m_enclosingOperand  = obj.getEnclosingOperand();

	m_message  = obj.getMessage();

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr< Bag<uml::GeneralOrdering> > _toAfter = obj.getToAfter();
	m_toAfter.reset(new Bag<uml::GeneralOrdering>(*(obj.getToAfter().get())));

	std::shared_ptr< Bag<uml::GeneralOrdering> > _toBefore = obj.getToBefore();
	m_toBefore.reset(new Bag<uml::GeneralOrdering>(*(obj.getToBefore().get())));


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::GeneralOrdering>> _generalOrderingList = obj.getGeneralOrdering();
	for(std::shared_ptr<uml::GeneralOrdering> _generalOrdering : *_generalOrderingList)
	{
		this->getGeneralOrdering()->add(std::shared_ptr<uml::GeneralOrdering>(std::dynamic_pointer_cast<uml::GeneralOrdering>(_generalOrdering->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_generalOrdering" << std::endl;
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

}

std::shared_ptr<ecore::EObject>  DestructionOccurrenceSpecificationImpl::copy() const
{
	std::shared_ptr<ecore::EObject> element(new DestructionOccurrenceSpecificationImpl(*this));
	return element;
}

std::shared_ptr<ecore::EClass> DestructionOccurrenceSpecificationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getDestructionOccurrenceSpecification();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool DestructionOccurrenceSpecificationImpl::no_occurrence_specifications_below(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > DestructionOccurrenceSpecificationImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > DestructionOccurrenceSpecificationImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > DestructionOccurrenceSpecificationImpl::getOwner() const
{
	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any DestructionOccurrenceSpecificationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2324
		case UmlPackage::INTERACTIONFRAGMENT_COVERED:
			return getCovered(); //23210
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2320
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGINTERACTION:
			return getEnclosingInteraction(); //23212
		case UmlPackage::INTERACTIONFRAGMENT_ENCLOSINGOPERAND:
			return getEnclosingOperand(); //23211
		case UmlPackage::INTERACTIONFRAGMENT_GENERALORDERING:
			return getGeneralOrdering(); //23213
		case UmlPackage::MESSAGEEND_MESSAGE:
			return getMessage(); //23210
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2325
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2326
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2327
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2321
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2322
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2323
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2328
		case UmlPackage::OCCURRENCESPECIFICATION_TOAFTER:
			return getToAfter(); //23214
		case UmlPackage::OCCURRENCESPECIFICATION_TOBEFORE:
			return getToBefore(); //23215
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2329
	}
	return boost::any();
}
