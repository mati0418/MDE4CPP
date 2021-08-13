#include "uml/impl/InformationFlowImpl.hpp"

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


#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"


#include "uml/ActivityEdge.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Connector.hpp"
#include "uml/Dependency.hpp"
#include "uml/DirectedRelationship.hpp"
#include "uml/Element.hpp"
#include "uml/Message.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Relationship.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateParameter.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InformationFlowImpl::InformationFlowImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

InformationFlowImpl::~InformationFlowImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InformationFlow "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
InformationFlowImpl::InformationFlowImpl(std::weak_ptr<uml::Namespace> par_namespace)
:InformationFlowImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
InformationFlowImpl::InformationFlowImpl(std::weak_ptr<uml::Element> par_owner)
:InformationFlowImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
InformationFlowImpl::InformationFlowImpl(std::weak_ptr<uml::Package> par_owningPackage)
:InformationFlowImpl()
{
	m_owningPackage = par_owningPackage;
	m_namespace = par_owningPackage;
}

//Additional constructor for the containments back reference
InformationFlowImpl::InformationFlowImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:InformationFlowImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

InformationFlowImpl::InformationFlowImpl(const InformationFlowImpl & obj): InformationFlowImpl()
{
	*this = obj;
}

InformationFlowImpl& InformationFlowImpl::operator=(const InformationFlowImpl & obj)
{
	//call overloaded =Operator for each base class
	PackageableElementImpl::operator=(obj);
	DirectedRelationshipImpl::operator=(obj);
	InformationFlow::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy InformationFlow "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<uml::Classifier>> _conveyed = obj.getConveyed();
	m_conveyed.reset(new Bag<uml::Classifier>(*(obj.getConveyed().get())));
	std::shared_ptr<Bag<uml::Relationship>> _realization = obj.getRealization();
	m_realization.reset(new Bag<uml::Relationship>(*(obj.getRealization().get())));
	std::shared_ptr<Bag<uml::ActivityEdge>> _realizingActivityEdge = obj.getRealizingActivityEdge();
	m_realizingActivityEdge.reset(new Bag<uml::ActivityEdge>(*(obj.getRealizingActivityEdge().get())));
	std::shared_ptr<Bag<uml::Connector>> _realizingConnector = obj.getRealizingConnector();
	m_realizingConnector.reset(new Bag<uml::Connector>(*(obj.getRealizingConnector().get())));
	std::shared_ptr<Bag<uml::Message>> _realizingMessage = obj.getRealizingMessage();
	m_realizingMessage.reset(new Bag<uml::Message>(*(obj.getRealizingMessage().get())));
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::NamedElement, uml::Element>> informationSourceContainer = getInformationSource();
	if(nullptr != informationSourceContainer )
	{
		int size = informationSourceContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _informationSource=(*informationSourceContainer)[i];
			if(nullptr != _informationSource)
			{
				informationSourceContainer->push_back(std::dynamic_pointer_cast<uml::NamedElement>(_informationSource->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container informationSource."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr informationSource."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::NamedElement, uml::Element>> informationTargetContainer = getInformationTarget();
	if(nullptr != informationTargetContainer )
	{
		int size = informationTargetContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _informationTarget=(*informationTargetContainer)[i];
			if(nullptr != _informationTarget)
			{
				informationTargetContainer->push_back(std::dynamic_pointer_cast<uml::NamedElement>(_informationTarget->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container informationTarget."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr informationTarget."<< std::endl;)
	}
	return *this;
}

std::shared_ptr<ecore::EObject> InformationFlowImpl::copy() const
{
	std::shared_ptr<InformationFlowImpl> element(new InformationFlowImpl());
	*element =(*this);
	element->setThisInformationFlowPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> InformationFlowImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getInformationFlow_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool InformationFlowImpl::convey_classifiers(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InformationFlowImpl::must_conform(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool InformationFlowImpl::sources_and_targets_kind(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference conveyed
*/
std::shared_ptr<Bag<uml::Classifier>> InformationFlowImpl::getConveyed() const
{
	if(m_conveyed == nullptr)
	{
		m_conveyed.reset(new Bag<uml::Classifier>());
		
		
	}
//assert(m_conveyed);
    return m_conveyed;
}



/*
Getter & Setter for reference informationSource
*/
std::shared_ptr<Subset<uml::NamedElement, uml::Element>> InformationFlowImpl::getInformationSource() const
{
	if(m_informationSource == nullptr)
	{
		/*Subset*/
		m_informationSource.reset(new Subset<uml::NamedElement, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_informationSource - Subset<uml::NamedElement, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_informationSource->initSubset(getSource());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_informationSource - Subset<uml::NamedElement, uml::Element >(getSource())" << std::endl;
		#endif
		
	}
//assert(m_informationSource);
    return m_informationSource;
}



/*
Getter & Setter for reference informationTarget
*/
std::shared_ptr<Subset<uml::NamedElement, uml::Element>> InformationFlowImpl::getInformationTarget() const
{
	if(m_informationTarget == nullptr)
	{
		/*Subset*/
		m_informationTarget.reset(new Subset<uml::NamedElement, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_informationTarget - Subset<uml::NamedElement, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_informationTarget->initSubset(getTarget());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_informationTarget - Subset<uml::NamedElement, uml::Element >(getTarget())" << std::endl;
		#endif
		
	}
//assert(m_informationTarget);
    return m_informationTarget;
}



/*
Getter & Setter for reference realization
*/
std::shared_ptr<Bag<uml::Relationship>> InformationFlowImpl::getRealization() const
{
	if(m_realization == nullptr)
	{
		m_realization.reset(new Bag<uml::Relationship>());
		
		
	}

    return m_realization;
}



/*
Getter & Setter for reference realizingActivityEdge
*/
std::shared_ptr<Bag<uml::ActivityEdge>> InformationFlowImpl::getRealizingActivityEdge() const
{
	if(m_realizingActivityEdge == nullptr)
	{
		m_realizingActivityEdge.reset(new Bag<uml::ActivityEdge>());
		
		
	}

    return m_realizingActivityEdge;
}



/*
Getter & Setter for reference realizingConnector
*/
std::shared_ptr<Bag<uml::Connector>> InformationFlowImpl::getRealizingConnector() const
{
	if(m_realizingConnector == nullptr)
	{
		m_realizingConnector.reset(new Bag<uml::Connector>());
		
		
	}

    return m_realizingConnector;
}



/*
Getter & Setter for reference realizingMessage
*/
std::shared_ptr<Bag<uml::Message>> InformationFlowImpl::getRealizingMessage() const
{
	if(m_realizingMessage == nullptr)
	{
		m_realizingMessage.reset(new Bag<uml::Message>());
		
		
	}

    return m_realizingMessage;
}



//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> InformationFlowImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> InformationFlowImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> InformationFlowImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::Element>> InformationFlowImpl::getRelatedElement() const
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

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> InformationFlowImpl::getSource() const
{
	if(m_source == nullptr)
	{
		/*SubsetUnion*/
		m_source.reset(new SubsetUnion<uml::Element, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_source - SubsetUnion<uml::Element, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_source->initSubsetUnion(getRelatedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_source - SubsetUnion<uml::Element, uml::Element >(getRelatedElement())" << std::endl;
		#endif
		
	}
	return m_source;
}

std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> InformationFlowImpl::getTarget() const
{
	if(m_target == nullptr)
	{
		/*SubsetUnion*/
		m_target.reset(new SubsetUnion<uml::Element, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_target - SubsetUnion<uml::Element, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_target->initSubsetUnion(getRelatedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_target - SubsetUnion<uml::Element, uml::Element >(getRelatedElement())" << std::endl;
		#endif
		
	}
	return m_target;
}




std::shared_ptr<InformationFlow> InformationFlowImpl::getThisInformationFlowPtr() const
{
	return m_thisInformationFlowPtr.lock();
}
void InformationFlowImpl::setThisInformationFlowPtr(std::weak_ptr<InformationFlow> thisInformationFlowPtr)
{
	m_thisInformationFlowPtr = thisInformationFlowPtr;
	setThisDirectedRelationshipPtr(thisInformationFlowPtr);
	setThisPackageableElementPtr(thisInformationFlowPtr);
}
std::shared_ptr<ecore::EObject> InformationFlowImpl::eContainer() const
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
// Structural Feature Getter/Setter
//*********************************
Any InformationFlowImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_CONVEYED:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Classifier>::iterator iter = getConveyed()->begin();
			Bag<uml::Classifier>::iterator end = getConveyed()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //11315			
		}
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_INFORMATIONSOURCE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::NamedElement>::iterator iter = getInformationSource()->begin();
			Bag<uml::NamedElement>::iterator end = getInformationSource()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //11316			
		}
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_INFORMATIONTARGET:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::NamedElement>::iterator iter = getInformationTarget()->begin();
			Bag<uml::NamedElement>::iterator end = getInformationTarget()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //11317			
		}
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZATION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Relationship>::iterator iter = getRealization()->begin();
			Bag<uml::Relationship>::iterator end = getRealization()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //11318			
		}
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGACTIVITYEDGE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::ActivityEdge>::iterator iter = getRealizingActivityEdge()->begin();
			Bag<uml::ActivityEdge>::iterator end = getRealizingActivityEdge()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //11319			
		}
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGCONNECTOR:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Connector>::iterator iter = getRealizingConnector()->begin();
			Bag<uml::Connector>::iterator end = getRealizingConnector()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //11320			
		}
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGMESSAGE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Message>::iterator iter = getRealizingMessage()->begin();
			Bag<uml::Message>::iterator end = getRealizingMessage()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //11321			
		}
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
bool InformationFlowImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_CONVEYED:
			return getConveyed() != nullptr; //11315
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_INFORMATIONSOURCE:
			return getInformationSource() != nullptr; //11316
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_INFORMATIONTARGET:
			return getInformationTarget() != nullptr; //11317
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZATION:
			return getRealization() != nullptr; //11318
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGACTIVITYEDGE:
			return getRealizingActivityEdge() != nullptr; //11319
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGCONNECTOR:
			return getRealizingConnector() != nullptr; //11320
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGMESSAGE:
			return getRealizingMessage() != nullptr; //11321
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
bool InformationFlowImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_CONVEYED:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Classifier>> conveyedList(new Bag<uml::Classifier>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				conveyedList->add(std::dynamic_pointer_cast<uml::Classifier>(*iter));
				iter++;
			}
			
			Bag<uml::Classifier>::iterator iterConveyed = getConveyed()->begin();
			Bag<uml::Classifier>::iterator endConveyed = getConveyed()->end();
			while (iterConveyed != endConveyed)
			{
				if (conveyedList->find(*iterConveyed) == -1)
				{
					getConveyed()->erase(*iterConveyed);
				}
				iterConveyed++;
			}
 
			iterConveyed = conveyedList->begin();
			endConveyed = conveyedList->end();
			while (iterConveyed != endConveyed)
			{
				if (getConveyed()->find(*iterConveyed) == -1)
				{
					getConveyed()->add(*iterConveyed);
				}
				iterConveyed++;			
			}
			return true;
		}
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_INFORMATIONSOURCE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::NamedElement>> informationSourceList(new Bag<uml::NamedElement>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				informationSourceList->add(std::dynamic_pointer_cast<uml::NamedElement>(*iter));
				iter++;
			}
			
			Bag<uml::NamedElement>::iterator iterInformationSource = getInformationSource()->begin();
			Bag<uml::NamedElement>::iterator endInformationSource = getInformationSource()->end();
			while (iterInformationSource != endInformationSource)
			{
				if (informationSourceList->find(*iterInformationSource) == -1)
				{
					getInformationSource()->erase(*iterInformationSource);
				}
				iterInformationSource++;
			}
 
			iterInformationSource = informationSourceList->begin();
			endInformationSource = informationSourceList->end();
			while (iterInformationSource != endInformationSource)
			{
				if (getInformationSource()->find(*iterInformationSource) == -1)
				{
					getInformationSource()->add(*iterInformationSource);
				}
				iterInformationSource++;			
			}
			return true;
		}
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_INFORMATIONTARGET:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::NamedElement>> informationTargetList(new Bag<uml::NamedElement>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				informationTargetList->add(std::dynamic_pointer_cast<uml::NamedElement>(*iter));
				iter++;
			}
			
			Bag<uml::NamedElement>::iterator iterInformationTarget = getInformationTarget()->begin();
			Bag<uml::NamedElement>::iterator endInformationTarget = getInformationTarget()->end();
			while (iterInformationTarget != endInformationTarget)
			{
				if (informationTargetList->find(*iterInformationTarget) == -1)
				{
					getInformationTarget()->erase(*iterInformationTarget);
				}
				iterInformationTarget++;
			}
 
			iterInformationTarget = informationTargetList->begin();
			endInformationTarget = informationTargetList->end();
			while (iterInformationTarget != endInformationTarget)
			{
				if (getInformationTarget()->find(*iterInformationTarget) == -1)
				{
					getInformationTarget()->add(*iterInformationTarget);
				}
				iterInformationTarget++;			
			}
			return true;
		}
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Relationship>> realizationList(new Bag<uml::Relationship>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				realizationList->add(std::dynamic_pointer_cast<uml::Relationship>(*iter));
				iter++;
			}
			
			Bag<uml::Relationship>::iterator iterRealization = getRealization()->begin();
			Bag<uml::Relationship>::iterator endRealization = getRealization()->end();
			while (iterRealization != endRealization)
			{
				if (realizationList->find(*iterRealization) == -1)
				{
					getRealization()->erase(*iterRealization);
				}
				iterRealization++;
			}
 
			iterRealization = realizationList->begin();
			endRealization = realizationList->end();
			while (iterRealization != endRealization)
			{
				if (getRealization()->find(*iterRealization) == -1)
				{
					getRealization()->add(*iterRealization);
				}
				iterRealization++;			
			}
			return true;
		}
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGACTIVITYEDGE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ActivityEdge>> realizingActivityEdgeList(new Bag<uml::ActivityEdge>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				realizingActivityEdgeList->add(std::dynamic_pointer_cast<uml::ActivityEdge>(*iter));
				iter++;
			}
			
			Bag<uml::ActivityEdge>::iterator iterRealizingActivityEdge = getRealizingActivityEdge()->begin();
			Bag<uml::ActivityEdge>::iterator endRealizingActivityEdge = getRealizingActivityEdge()->end();
			while (iterRealizingActivityEdge != endRealizingActivityEdge)
			{
				if (realizingActivityEdgeList->find(*iterRealizingActivityEdge) == -1)
				{
					getRealizingActivityEdge()->erase(*iterRealizingActivityEdge);
				}
				iterRealizingActivityEdge++;
			}
 
			iterRealizingActivityEdge = realizingActivityEdgeList->begin();
			endRealizingActivityEdge = realizingActivityEdgeList->end();
			while (iterRealizingActivityEdge != endRealizingActivityEdge)
			{
				if (getRealizingActivityEdge()->find(*iterRealizingActivityEdge) == -1)
				{
					getRealizingActivityEdge()->add(*iterRealizingActivityEdge);
				}
				iterRealizingActivityEdge++;			
			}
			return true;
		}
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGCONNECTOR:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Connector>> realizingConnectorList(new Bag<uml::Connector>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				realizingConnectorList->add(std::dynamic_pointer_cast<uml::Connector>(*iter));
				iter++;
			}
			
			Bag<uml::Connector>::iterator iterRealizingConnector = getRealizingConnector()->begin();
			Bag<uml::Connector>::iterator endRealizingConnector = getRealizingConnector()->end();
			while (iterRealizingConnector != endRealizingConnector)
			{
				if (realizingConnectorList->find(*iterRealizingConnector) == -1)
				{
					getRealizingConnector()->erase(*iterRealizingConnector);
				}
				iterRealizingConnector++;
			}
 
			iterRealizingConnector = realizingConnectorList->begin();
			endRealizingConnector = realizingConnectorList->end();
			while (iterRealizingConnector != endRealizingConnector)
			{
				if (getRealizingConnector()->find(*iterRealizingConnector) == -1)
				{
					getRealizingConnector()->add(*iterRealizingConnector);
				}
				iterRealizingConnector++;			
			}
			return true;
		}
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGMESSAGE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Message>> realizingMessageList(new Bag<uml::Message>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				realizingMessageList->add(std::dynamic_pointer_cast<uml::Message>(*iter));
				iter++;
			}
			
			Bag<uml::Message>::iterator iterRealizingMessage = getRealizingMessage()->begin();
			Bag<uml::Message>::iterator endRealizingMessage = getRealizingMessage()->end();
			while (iterRealizingMessage != endRealizingMessage)
			{
				if (realizingMessageList->find(*iterRealizingMessage) == -1)
				{
					getRealizingMessage()->erase(*iterRealizingMessage);
				}
				iterRealizingMessage++;
			}
 
			iterRealizingMessage = realizingMessageList->begin();
			endRealizingMessage = realizingMessageList->end();
			while (iterRealizingMessage != endRealizingMessage)
			{
				if (getRealizingMessage()->find(*iterRealizingMessage) == -1)
				{
					getRealizingMessage()->add(*iterRealizingMessage);
				}
				iterRealizingMessage++;			
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
// Behavioral Feature
//*********************************
Any InformationFlowImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 11383
		case umlPackage::INFORMATIONFLOW_OPERATION_CONVEY_CLASSIFIERS_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->convey_classifiers(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 11381
		case umlPackage::INFORMATIONFLOW_OPERATION_MUST_CONFORM_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->must_conform(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 11382
		case umlPackage::INFORMATIONFLOW_OPERATION_SOURCES_AND_TARGETS_KIND_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->sources_and_targets_kind(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = DirectedRelationshipImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = PackageableElementImpl::eInvoke(operationID, arguments);
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
void InformationFlowImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void InformationFlowImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("conveyed");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("conveyed")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("informationSource");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("informationSource")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("informationTarget");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("informationTarget")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("realization");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("realization")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("realizingActivityEdge");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("realizingActivityEdge")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("realizingConnector");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("realizingConnector")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("realizingMessage");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("realizingMessage")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void InformationFlowImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	DirectedRelationshipImpl::loadNode(nodeName, loadHandler);
	PackageableElementImpl::loadNode(nodeName, loadHandler);
}

void InformationFlowImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_CONVEYED:
		{
			std::shared_ptr<Bag<uml::Classifier>> _conveyed = getConveyed();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Classifier>  _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_conveyed->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_INFORMATIONSOURCE:
		{
			std::shared_ptr<Subset<uml::NamedElement, uml::Element>> _informationSource = getInformationSource();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::NamedElement>  _r = std::dynamic_pointer_cast<uml::NamedElement>(ref);
				if (_r != nullptr)
				{
					_informationSource->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_INFORMATIONTARGET:
		{
			std::shared_ptr<Subset<uml::NamedElement, uml::Element>> _informationTarget = getInformationTarget();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::NamedElement>  _r = std::dynamic_pointer_cast<uml::NamedElement>(ref);
				if (_r != nullptr)
				{
					_informationTarget->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZATION:
		{
			std::shared_ptr<Bag<uml::Relationship>> _realization = getRealization();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Relationship>  _r = std::dynamic_pointer_cast<uml::Relationship>(ref);
				if (_r != nullptr)
				{
					_realization->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGACTIVITYEDGE:
		{
			std::shared_ptr<Bag<uml::ActivityEdge>> _realizingActivityEdge = getRealizingActivityEdge();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::ActivityEdge>  _r = std::dynamic_pointer_cast<uml::ActivityEdge>(ref);
				if (_r != nullptr)
				{
					_realizingActivityEdge->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGCONNECTOR:
		{
			std::shared_ptr<Bag<uml::Connector>> _realizingConnector = getRealizingConnector();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Connector>  _r = std::dynamic_pointer_cast<uml::Connector>(ref);
				if (_r != nullptr)
				{
					_realizingConnector->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::INFORMATIONFLOW_ATTRIBUTE_REALIZINGMESSAGE:
		{
			std::shared_ptr<Bag<uml::Message>> _realizingMessage = getRealizingMessage();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Message>  _r = std::dynamic_pointer_cast<uml::Message>(ref);
				if (_r != nullptr)
				{
					_realizingMessage->push_back(_r);
				}
			}
			return;
		}
	}
	DirectedRelationshipImpl::resolveReferences(featureID, references);
	PackageableElementImpl::resolveReferences(featureID, references);
}

void InformationFlowImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void InformationFlowImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReferences<uml::Classifier>("conveyed", this->getConveyed());
		saveHandler->addReferences<uml::NamedElement>("informationSource", this->getInformationSource());
		saveHandler->addReferences<uml::NamedElement>("informationTarget", this->getInformationTarget());
		saveHandler->addReferences<uml::Relationship>("realization", this->getRealization());
		saveHandler->addReferences<uml::ActivityEdge>("realizingActivityEdge", this->getRealizingActivityEdge());
		saveHandler->addReferences<uml::Connector>("realizingConnector", this->getRealizingConnector());
		saveHandler->addReferences<uml::Message>("realizingMessage", this->getRealizingMessage());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

