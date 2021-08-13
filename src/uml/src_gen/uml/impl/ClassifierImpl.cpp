#include "uml/impl/ClassifierImpl.hpp"

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
#include "uml/BehavioredClassifier.hpp"
#include "uml/InterfaceRealization.hpp"
#include "uml/Interface.hpp"
#include "uml/Usage.hpp"
#include "uml/Class.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"


#include "uml/Classifier.hpp"
#include "uml/CollaborationUse.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Feature.hpp"
#include "uml/Generalization.hpp"
#include "uml/GeneralizationSet.hpp"
#include "uml/Interface.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Operation.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/Property.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuralFeature.hpp"
#include "uml/Substitution.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/TemplateableElement.hpp"
#include "uml/Type.hpp"
#include "uml/UseCase.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ClassifierImpl::ClassifierImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ClassifierImpl::~ClassifierImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Classifier "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ClassifierImpl::ClassifierImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ClassifierImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ClassifierImpl::ClassifierImpl(std::weak_ptr<uml::Element> par_owner)
:ClassifierImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ClassifierImpl::ClassifierImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:ClassifierImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		m_owningPackage = par_Package;
		m_namespace = par_Package;
		 return;
	case uml::umlPackage::TYPE_ATTRIBUTE_PACKAGE:
		m_package = par_Package;
		m_namespace = par_Package;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}

//Additional constructor for the containments back reference
ClassifierImpl::ClassifierImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:ClassifierImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}


ClassifierImpl::ClassifierImpl(const ClassifierImpl & obj): ClassifierImpl()
{
	*this = obj;
}

ClassifierImpl& ClassifierImpl::operator=(const ClassifierImpl & obj)
{
	//call overloaded =Operator for each base class
	NamespaceImpl::operator=(obj);
	RedefinableElementImpl::operator=(obj);
	TypeImpl::operator=(obj);
	TemplateableElementImpl::operator=(obj);
	Classifier::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Classifier "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isAbstract = obj.getIsAbstract();
	m_isFinalSpecialization = obj.getIsFinalSpecialization();

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<uml::Classifier>> _general = obj.getGeneral();
	m_general.reset(new Bag<uml::Classifier>(*(obj.getGeneral().get())));
	std::shared_ptr<Bag<uml::GeneralizationSet>> _powertypeExtent = obj.getPowertypeExtent();
	m_powertypeExtent.reset(new Bag<uml::GeneralizationSet>(*(obj.getPowertypeExtent().get())));
	std::shared_ptr<Bag<uml::UseCase>> _useCase = obj.getUseCase();
	m_useCase.reset(new Bag<uml::UseCase>(*(obj.getUseCase().get())));
	//Clone references with containment (deep copy)
	std::shared_ptr<SubsetUnion<uml::CollaborationUse, uml::Element>> collaborationUseContainer = getCollaborationUse();
	if(nullptr != collaborationUseContainer )
	{
		int size = collaborationUseContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _collaborationUse=(*collaborationUseContainer)[i];
			if(nullptr != _collaborationUse)
			{
				collaborationUseContainer->push_back(std::dynamic_pointer_cast<uml::CollaborationUse>(_collaborationUse->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container collaborationUse."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr collaborationUse."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Generalization, uml::Element>> generalizationContainer = getGeneralization();
	if(nullptr != generalizationContainer )
	{
		int size = generalizationContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _generalization=(*generalizationContainer)[i];
			if(nullptr != _generalization)
			{
				generalizationContainer->push_back(std::dynamic_pointer_cast<uml::Generalization>(_generalization->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container generalization."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr generalization."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::NamedElement, uml::NamedElement>> inheritedMemberContainer = getInheritedMember();
	if(nullptr != inheritedMemberContainer )
	{
		int size = inheritedMemberContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _inheritedMember=(*inheritedMemberContainer)[i];
			if(nullptr != _inheritedMember)
			{
				inheritedMemberContainer->push_back(std::dynamic_pointer_cast<uml::NamedElement>(_inheritedMember->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container inheritedMember."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr inheritedMember."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::UseCase, uml::NamedElement>> ownedUseCaseContainer = getOwnedUseCase();
	if(nullptr != ownedUseCaseContainer )
	{
		int size = ownedUseCaseContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _ownedUseCase=(*ownedUseCaseContainer)[i];
			if(nullptr != _ownedUseCase)
			{
				ownedUseCaseContainer->push_back(std::dynamic_pointer_cast<uml::UseCase>(_ownedUseCase->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container ownedUseCase."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr ownedUseCase."<< std::endl;)
	}
	std::shared_ptr<SubsetUnion<uml::Classifier, uml::RedefinableElement>> redefinedClassifierContainer = getRedefinedClassifier();
	if(nullptr != redefinedClassifierContainer )
	{
		int size = redefinedClassifierContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _redefinedClassifier=(*redefinedClassifierContainer)[i];
			if(nullptr != _redefinedClassifier)
			{
				redefinedClassifierContainer->push_back(std::dynamic_pointer_cast<uml::Classifier>(_redefinedClassifier->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container redefinedClassifier."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr redefinedClassifier."<< std::endl;)
	}
	if(obj.getRepresentation()!=nullptr)
	{
		m_representation = std::dynamic_pointer_cast<uml::CollaborationUse>(obj.getRepresentation()->copy());
	}
	std::shared_ptr<Subset<uml::Substitution, uml::Element>> substitutionContainer = getSubstitution();
	if(nullptr != substitutionContainer )
	{
		int size = substitutionContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _substitution=(*substitutionContainer)[i];
			if(nullptr != _substitution)
			{
				substitutionContainer->push_back(std::dynamic_pointer_cast<uml::Substitution>(_substitution->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container substitution."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr substitution."<< std::endl;)
	}
	/*SubsetUnion*/
	m_collaborationUse->initSubsetUnion(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value SubsetUnion: " << "m_collaborationUse - SubsetUnion<uml::CollaborationUse, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	/*Subset*/
	m_generalization->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_generalization - Subset<uml::Generalization, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	/*Subset*/
	m_ownedUseCase->initSubset(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedUseCase - Subset<uml::UseCase, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	m_substitution->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_substitution - Subset<uml::Substitution, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> ClassifierImpl::copy() const
{
	std::shared_ptr<ClassifierImpl> element(new ClassifierImpl());
	*element =(*this);
	element->setThisClassifierPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ClassifierImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getClassifier_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isAbstract
*/
bool ClassifierImpl::getIsAbstract() const 
{
	return m_isAbstract;
}
void ClassifierImpl::setIsAbstract(bool _isAbstract)
{
	m_isAbstract = _isAbstract;
	
} 


/*
Getter & Setter for attribute isFinalSpecialization
*/
bool ClassifierImpl::getIsFinalSpecialization() const 
{
	return m_isFinalSpecialization;
}
void ClassifierImpl::setIsFinalSpecialization(bool _isFinalSpecialization)
{
	m_isFinalSpecialization = _isFinalSpecialization;
	
} 


//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::Property> > ClassifierImpl::allAttributes()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Feature> > ClassifierImpl::allFeatures()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Classifier> > ClassifierImpl::allParents()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> > ClassifierImpl::allRealizedInterfaces()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::Interface>> allRealizedInterface(new Bag<uml::Interface>());
std::shared_ptr<Bag<uml::Interface>> directlyRealizedInterfaces = this->directlyRealizedInterfaces();
	
allRealizedInterface->insert(allRealizedInterface->end(), directlyRealizedInterfaces->begin(), directlyRealizedInterfaces->end());
	
std::shared_ptr<Bag<uml::Classifier>> superClasses = this->getGenerals();
for(unsigned int i = 0; i < superClasses->size(); i++)
{
	std::shared_ptr<Bag<uml::Interface>> superRealizedInterfaces = superClasses->at(i)->allRealizedInterfaces();
	allRealizedInterface->insert(allRealizedInterface->end(), superRealizedInterfaces->begin(), superRealizedInterfaces->end());
}

return allRealizedInterface;
	//end of body
}

std::shared_ptr<Bag<uml::StructuralFeature> > ClassifierImpl::allSlottableFeatures()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Interface> > ClassifierImpl::allUsedInterfaces()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<uml::Interface>> allUsedInterfaces(new Bag<uml::Interface>());
	std::shared_ptr<Bag<uml::Interface>> directlyUsedInterfaces = this->directlyUsedInterfaces();
	
	allUsedInterfaces->insert(allUsedInterfaces->end(), directlyUsedInterfaces->begin(), directlyUsedInterfaces->end());
	
	std::shared_ptr<Bag<uml::Classifier>> superClasses = this->getGenerals();
	for(unsigned int i = 0; i < superClasses->size(); i++)
	{
		std::shared_ptr<Bag<uml::Interface>> superUsedInterfaces = superClasses->at(i)->allUsedInterfaces();
		allUsedInterfaces->insert(allUsedInterfaces->end(), superUsedInterfaces->begin(), superUsedInterfaces->end());
	}

	return allUsedInterfaces;
	//end of body
}

std::shared_ptr<Bag<uml::Interface> > ClassifierImpl::directlyRealizedInterfaces()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr<Bag<uml::Interface>> directlyRealizedInterfaces(new Bag<uml::Interface>());
std::shared_ptr<uml::BehavioredClassifier> bClassifier = std::dynamic_pointer_cast<uml::BehavioredClassifier>(getThisClassifierPtr());

if(bClassifier != nullptr)
{
	std::shared_ptr<Bag<uml::InterfaceRealization>> interfaceRealizations = bClassifier->getInterfaceRealization();
	for(unsigned int i = 0; i < interfaceRealizations->size(); i++)
	{
		std::shared_ptr<uml::InterfaceRealization> interfaceRealization = interfaceRealizations->at(i);
		std::shared_ptr<uml::Interface> contract = interfaceRealization->getContract();

		if(contract != nullptr)
		{
			directlyRealizedInterfaces->add(contract);
		}
	}
}

return directlyRealizedInterfaces;
	//end of body
}

std::shared_ptr<Bag<uml::Interface> > ClassifierImpl::directlyUsedInterfaces()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<uml::Interface>> directlyUsedInterfaces(new Bag<uml::Interface>());

	std::shared_ptr<Bag<uml::Dependency>> clientDependencies = this->getClientDependency();
	
	for(unsigned int i = 0; i < clientDependencies->size(); i++)
	{
		std::shared_ptr<uml::Usage> usage = std::dynamic_pointer_cast<uml::Usage>(clientDependencies->at(i));
		if(usage != nullptr)
		{
			std::shared_ptr<Bag<uml::NamedElement>> suppliers = usage->getSupplier();
			std::shared_ptr<Bag<uml::Interface>> interfacesInSuppliers(new Bag<uml::Interface>());
			
			for(unsigned int j = 0; j < suppliers->size(); j++)
			{
				std::shared_ptr<uml::Interface> supplyingInterface = std::dynamic_pointer_cast<uml::Interface>(suppliers->at(j));
				if(supplyingInterface != nullptr)
				{
					interfacesInSuppliers->add(supplyingInterface);
				}
			}
			
			directlyUsedInterfaces->insert(directlyUsedInterfaces->end(), interfacesInSuppliers->begin(), interfacesInSuppliers->end());
		}
	}
	
	return directlyUsedInterfaces;
	//end of body
}

std::shared_ptr<Bag<uml::Property> > ClassifierImpl::getAllAttributes()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	    std::shared_ptr<Bag<uml::Property>> eAllAttributes(new Bag<uml::Property>());

    std::shared_ptr<Bag<uml::Property>> attributeList = this->getAttribute();
    eAllAttributes->insert(eAllAttributes->end(), attributeList->begin(), attributeList->end());

    std::shared_ptr<Bag<Classifier> > classList = this->getGenerals();
    for (std::shared_ptr<Classifier> c : *classList)
    {
        std::shared_ptr<Bag<Property> > attributeList = c->getAllAttributes();
        eAllAttributes->insert(eAllAttributes->end(), attributeList->begin(), attributeList->end());
    }
    return eAllAttributes;
	//end of body
}

std::shared_ptr<Bag<uml::Operation> > ClassifierImpl::getAllOperations()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<uml::Operation>> allOperations(new Bag<uml::Operation>());
	std::shared_ptr<Bag<uml::Feature>> allDirectFeatures = this->getFeature();
	
	for(unsigned int i = 0; i < allDirectFeatures->size(); i++)
	{
		std::shared_ptr<uml::Operation> operation = std::dynamic_pointer_cast<uml::Operation>(allDirectFeatures->at(i));
		if(operation != nullptr){ allOperations->add(operation); }
	}
	
	std::shared_ptr<Bag<uml::Classifier>> superTypes = this->getGenerals();
	
	for(unsigned int i = 0; i < superTypes->size(); i++)
	{
		std::shared_ptr<Bag<uml::Operation>> superTypeOperations = superTypes->at(i)->getAllOperations();
		allOperations->insert(allOperations->end(), superTypeOperations->begin(), superTypeOperations->end());
	}
	
	return allOperations;
	//end of body
}

std::shared_ptr<Bag<uml::Interface> > ClassifierImpl::getAllUsedInterfaces()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Classifier> > ClassifierImpl::getGenerals()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	return parents();
	//end of body
}

std::shared_ptr<Bag<uml::NamedElement> > ClassifierImpl::getInheritedMembers()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Operation> ClassifierImpl::getOperation(std::string name,std::shared_ptr<Bag<std::string>> parameterNames,std::shared_ptr<Bag<uml::Type>> parameterTypes)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Operation> ClassifierImpl::getOperation(std::string name,std::shared_ptr<Bag<std::string>> parameterNames,std::shared_ptr<Bag<uml::Type>> parameterTypes,bool ignoreCase)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Operation> > ClassifierImpl::getOperations()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

Any ClassifierImpl::getPropertyValue(std::string propertyName)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
		std::shared_ptr<Bag<uml::Property> > propertyList = this->getMetaClass()->getAttribute();
	for(std::shared_ptr<uml::Property> p: *propertyList)
	{
		if(p->getName()==propertyName)
		{
			return this->get(p);
		}
	}
	return Any();
	//end of body
}

std::shared_ptr<Bag<uml::Interface> > ClassifierImpl::getUsedInterfaces()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::hasVisibilityOf(std::shared_ptr<uml::NamedElement> n)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::NamedElement> > ClassifierImpl::inherit(std::shared_ptr<Bag<uml::NamedElement>> inhs)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::NamedElement> > ClassifierImpl::inheritableMembers(std::shared_ptr<uml::Classifier> c)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::isSubstitutableFor(std::shared_ptr<uml::Classifier> contract)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::maps_to_generalization_set(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::maySpecializeType(std::shared_ptr<uml::Classifier> c)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::no_cycles_in_generalization(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ClassifierImpl::non_final_parents(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Classifier> > ClassifierImpl::parents()
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
	std::shared_ptr< Bag<uml::Classifier> > returnList(new Bag<uml::Classifier>());

	for(std::shared_ptr<Generalization> gen : *getGeneralization())
	{
		returnList->push_back(gen->getGeneral());
	}

	return returnList;
	//end of body
}

bool ClassifierImpl::specialize_type(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference attribute
*/




/*
Getter & Setter for reference collaborationUse
*/
std::shared_ptr<SubsetUnion<uml::CollaborationUse, uml::Element>> ClassifierImpl::getCollaborationUse() const
{
	if(m_collaborationUse == nullptr)
	{
		/*SubsetUnion*/
		m_collaborationUse.reset(new SubsetUnion<uml::CollaborationUse, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_collaborationUse - SubsetUnion<uml::CollaborationUse, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_collaborationUse->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_collaborationUse - SubsetUnion<uml::CollaborationUse, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_collaborationUse;
}



/*
Getter & Setter for reference feature
*/




/*
Getter & Setter for reference general
*/
std::shared_ptr<Bag<uml::Classifier>> ClassifierImpl::getGeneral() const
{
	if(m_general == nullptr)
	{
		m_general.reset(new Bag<uml::Classifier>());
		
		
	}

    return m_general;
}



/*
Getter & Setter for reference generalization
*/
std::shared_ptr<Subset<uml::Generalization, uml::Element>> ClassifierImpl::getGeneralization() const
{
	if(m_generalization == nullptr)
	{
		/*Subset*/
		m_generalization.reset(new Subset<uml::Generalization, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_generalization - Subset<uml::Generalization, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_generalization->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_generalization - Subset<uml::Generalization, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_generalization;
}



/*
Getter & Setter for reference inheritedMember
*/
std::shared_ptr<Subset<uml::NamedElement, uml::NamedElement>> ClassifierImpl::getInheritedMember() const
{
	if(m_inheritedMember == nullptr)
	{
		/*Subset*/
		m_inheritedMember.reset(new Subset<uml::NamedElement, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inheritedMember - Subset<uml::NamedElement, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_inheritedMember->initSubset(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inheritedMember - Subset<uml::NamedElement, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}

    return m_inheritedMember;
}



/*
Getter & Setter for reference ownedUseCase
*/
std::shared_ptr<Subset<uml::UseCase, uml::NamedElement>> ClassifierImpl::getOwnedUseCase() const
{
	if(m_ownedUseCase == nullptr)
	{
		/*Subset*/
		m_ownedUseCase.reset(new Subset<uml::UseCase, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedUseCase - Subset<uml::UseCase, uml::NamedElement >()" << std::endl;
		#endif
		
		/*Subset*/
		m_ownedUseCase->initSubset(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedUseCase - Subset<uml::UseCase, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_ownedUseCase;
}



/*
Getter & Setter for reference powertypeExtent
*/
std::shared_ptr<Bag<uml::GeneralizationSet>> ClassifierImpl::getPowertypeExtent() const
{
	if(m_powertypeExtent == nullptr)
	{
		m_powertypeExtent.reset(new Bag<uml::GeneralizationSet>());
		
		
	}

    return m_powertypeExtent;
}



/*
Getter & Setter for reference redefinedClassifier
*/
std::shared_ptr<SubsetUnion<uml::Classifier, uml::RedefinableElement>> ClassifierImpl::getRedefinedClassifier() const
{
	if(m_redefinedClassifier == nullptr)
	{
		/*SubsetUnion*/
		m_redefinedClassifier.reset(new SubsetUnion<uml::Classifier, uml::RedefinableElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_redefinedClassifier - SubsetUnion<uml::Classifier, uml::RedefinableElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_redefinedClassifier->initSubsetUnion(getRedefinedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_redefinedClassifier - SubsetUnion<uml::Classifier, uml::RedefinableElement >(getRedefinedElement())" << std::endl;
		#endif
		
	}

    return m_redefinedClassifier;
}



/*
Getter & Setter for reference representation
*/
std::shared_ptr<uml::CollaborationUse> ClassifierImpl::getRepresentation() const
{

    return m_representation;
}
void ClassifierImpl::setRepresentation(std::shared_ptr<uml::CollaborationUse> _representation)
{
    m_representation = _representation;
	
	
	
}


/*
Getter & Setter for reference substitution
*/
std::shared_ptr<Subset<uml::Substitution, uml::Element>> ClassifierImpl::getSubstitution() const
{
	if(m_substitution == nullptr)
	{
		/*Subset*/
		m_substitution.reset(new Subset<uml::Substitution, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_substitution - Subset<uml::Substitution, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_substitution->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_substitution - Subset<uml::Substitution, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_substitution;
}



/*
Getter & Setter for reference useCase
*/
std::shared_ptr<Bag<uml::UseCase>> ClassifierImpl::getUseCase() const
{
	if(m_useCase == nullptr)
	{
		m_useCase.reset(new Bag<uml::UseCase>());
		
		
	}

    return m_useCase;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::Property, uml::Feature>> ClassifierImpl::getAttribute() const
{
	if(m_attribute == nullptr)
	{
		/*SubsetUnion*/
		m_attribute.reset(new SubsetUnion<uml::Property, uml::Feature >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_attribute->initSubsetUnion(getFeature());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_attribute - SubsetUnion<uml::Property, uml::Feature >(getFeature())" << std::endl;
		#endif
		
	}
	return m_attribute;
}

std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> ClassifierImpl::getFeature() const
{
	if(m_feature == nullptr)
	{
		/*SubsetUnion*/
		m_feature.reset(new SubsetUnion<uml::Feature, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_feature->initSubsetUnion(getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_feature - SubsetUnion<uml::Feature, uml::NamedElement >(getMember())" << std::endl;
		#endif
		
	}
	return m_feature;
}

std::shared_ptr<Union<uml::NamedElement>> ClassifierImpl::getMember() const
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

std::weak_ptr<uml::Namespace> ClassifierImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ClassifierImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> ClassifierImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_ownedMember->initSubsetUnion(getOwnedElement(),getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >(getOwnedElement(),getMember())" << std::endl;
		#endif
		
	}
	return m_ownedMember;
}

std::weak_ptr<uml::Element> ClassifierImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ClassifierImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}




std::shared_ptr<Classifier> ClassifierImpl::getThisClassifierPtr() const
{
	return m_thisClassifierPtr.lock();
}
void ClassifierImpl::setThisClassifierPtr(std::weak_ptr<Classifier> thisClassifierPtr)
{
	m_thisClassifierPtr = thisClassifierPtr;
	setThisNamespacePtr(thisClassifierPtr);
	setThisRedefinableElementPtr(thisClassifierPtr);
	setThisTemplateableElementPtr(thisClassifierPtr);
	setThisTypePtr(thisClassifierPtr);
}
std::shared_ptr<ecore::EObject> ClassifierImpl::eContainer() const
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
	if(auto wp = m_package.lock())
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
Any ClassifierImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_ATTRIBUTE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Property>::iterator iter = getAttribute()->begin();
			Bag<uml::Property>::iterator end = getAttribute()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //3625			
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_COLLABORATIONUSE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::CollaborationUse>::iterator iter = getCollaborationUse()->begin();
			Bag<uml::CollaborationUse>::iterator end = getCollaborationUse()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //3626			
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_FEATURE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Feature>::iterator iter = getFeature()->begin();
			Bag<uml::Feature>::iterator end = getFeature()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //3624			
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_GENERAL:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Classifier>::iterator iter = getGeneral()->begin();
			Bag<uml::Classifier>::iterator end = getGeneral()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //3627			
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_GENERALIZATION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Generalization>::iterator iter = getGeneralization()->begin();
			Bag<uml::Generalization>::iterator end = getGeneralization()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //3628			
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_INHERITEDMEMBER:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::NamedElement>::iterator iter = getInheritedMember()->begin();
			Bag<uml::NamedElement>::iterator end = getInheritedMember()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //3630			
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_ISABSTRACT:
			return eAny(getIsAbstract()); //3631
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_ISFINALSPECIALIZATION:
			return eAny(getIsFinalSpecialization()); //3632
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_OWNEDUSECASE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::UseCase>::iterator iter = getOwnedUseCase()->begin();
			Bag<uml::UseCase>::iterator end = getOwnedUseCase()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //3633			
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_POWERTYPEEXTENT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::GeneralizationSet>::iterator iter = getPowertypeExtent()->begin();
			Bag<uml::GeneralizationSet>::iterator end = getPowertypeExtent()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //3629			
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_REDEFINEDCLASSIFIER:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Classifier>::iterator iter = getRedefinedClassifier()->begin();
			Bag<uml::Classifier>::iterator end = getRedefinedClassifier()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //3635			
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_REPRESENTATION:
			{
				std::shared_ptr<ecore::EObject> returnValue=getRepresentation();
				return eAny(returnValue); //3636
			}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_SUBSTITUTION:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Substitution>::iterator iter = getSubstitution()->begin();
			Bag<uml::Substitution>::iterator end = getSubstitution()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //3637			
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_USECASE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::UseCase>::iterator iter = getUseCase()->begin();
			Bag<uml::UseCase>::iterator end = getUseCase()->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //3634			
		}
	}
	Any result;
	result = NamespaceImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = RedefinableElementImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = TemplateableElementImpl::eGet(featureID, resolve, coreType);
	if (result != nullptr && !result->isEmpty())
	{
		return result;
	}
	result = TypeImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool ClassifierImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_ATTRIBUTE:
			return getAttribute() != nullptr; //3625
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_COLLABORATIONUSE:
			return getCollaborationUse() != nullptr; //3626
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_FEATURE:
			return getFeature() != nullptr; //3624
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_GENERAL:
			return getGeneral() != nullptr; //3627
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_GENERALIZATION:
			return getGeneralization() != nullptr; //3628
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_INHERITEDMEMBER:
			return getInheritedMember() != nullptr; //3630
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_ISABSTRACT:
			return getIsAbstract() != false; //3631
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_ISFINALSPECIALIZATION:
			return getIsFinalSpecialization() != false; //3632
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_OWNEDUSECASE:
			return getOwnedUseCase() != nullptr; //3633
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_POWERTYPEEXTENT:
			return getPowertypeExtent() != nullptr; //3629
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_REDEFINEDCLASSIFIER:
			return getRedefinedClassifier() != nullptr; //3635
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_REPRESENTATION:
			return getRepresentation() != nullptr; //3636
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_SUBSTITUTION:
			return getSubstitution() != nullptr; //3637
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_USECASE:
			return getUseCase() != nullptr; //3634
	}
	bool result = false;
	result = NamespaceImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = RedefinableElementImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = TemplateableElementImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = TypeImpl::internalEIsSet(featureID);
	return result;
}
bool ClassifierImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_COLLABORATIONUSE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::CollaborationUse>> collaborationUseList(new Bag<uml::CollaborationUse>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				collaborationUseList->add(std::dynamic_pointer_cast<uml::CollaborationUse>(*iter));
				iter++;
			}
			
			Bag<uml::CollaborationUse>::iterator iterCollaborationUse = getCollaborationUse()->begin();
			Bag<uml::CollaborationUse>::iterator endCollaborationUse = getCollaborationUse()->end();
			while (iterCollaborationUse != endCollaborationUse)
			{
				if (collaborationUseList->find(*iterCollaborationUse) == -1)
				{
					getCollaborationUse()->erase(*iterCollaborationUse);
				}
				iterCollaborationUse++;
			}
 
			iterCollaborationUse = collaborationUseList->begin();
			endCollaborationUse = collaborationUseList->end();
			while (iterCollaborationUse != endCollaborationUse)
			{
				if (getCollaborationUse()->find(*iterCollaborationUse) == -1)
				{
					getCollaborationUse()->add(*iterCollaborationUse);
				}
				iterCollaborationUse++;			
			}
			return true;
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_GENERAL:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Classifier>> generalList(new Bag<uml::Classifier>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				generalList->add(std::dynamic_pointer_cast<uml::Classifier>(*iter));
				iter++;
			}
			
			Bag<uml::Classifier>::iterator iterGeneral = getGeneral()->begin();
			Bag<uml::Classifier>::iterator endGeneral = getGeneral()->end();
			while (iterGeneral != endGeneral)
			{
				if (generalList->find(*iterGeneral) == -1)
				{
					getGeneral()->erase(*iterGeneral);
				}
				iterGeneral++;
			}
 
			iterGeneral = generalList->begin();
			endGeneral = generalList->end();
			while (iterGeneral != endGeneral)
			{
				if (getGeneral()->find(*iterGeneral) == -1)
				{
					getGeneral()->add(*iterGeneral);
				}
				iterGeneral++;			
			}
			return true;
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_GENERALIZATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Generalization>> generalizationList(new Bag<uml::Generalization>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				generalizationList->add(std::dynamic_pointer_cast<uml::Generalization>(*iter));
				iter++;
			}
			
			Bag<uml::Generalization>::iterator iterGeneralization = getGeneralization()->begin();
			Bag<uml::Generalization>::iterator endGeneralization = getGeneralization()->end();
			while (iterGeneralization != endGeneralization)
			{
				if (generalizationList->find(*iterGeneralization) == -1)
				{
					getGeneralization()->erase(*iterGeneralization);
				}
				iterGeneralization++;
			}
 
			iterGeneralization = generalizationList->begin();
			endGeneralization = generalizationList->end();
			while (iterGeneralization != endGeneralization)
			{
				if (getGeneralization()->find(*iterGeneralization) == -1)
				{
					getGeneralization()->add(*iterGeneralization);
				}
				iterGeneralization++;			
			}
			return true;
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_ISABSTRACT:
		{
			// BOOST CAST
			bool _isAbstract = newValue->get<bool>();
			setIsAbstract(_isAbstract); //3631
			return true;
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_ISFINALSPECIALIZATION:
		{
			// BOOST CAST
			bool _isFinalSpecialization = newValue->get<bool>();
			setIsFinalSpecialization(_isFinalSpecialization); //3632
			return true;
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_OWNEDUSECASE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::UseCase>> ownedUseCaseList(new Bag<uml::UseCase>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedUseCaseList->add(std::dynamic_pointer_cast<uml::UseCase>(*iter));
				iter++;
			}
			
			Bag<uml::UseCase>::iterator iterOwnedUseCase = getOwnedUseCase()->begin();
			Bag<uml::UseCase>::iterator endOwnedUseCase = getOwnedUseCase()->end();
			while (iterOwnedUseCase != endOwnedUseCase)
			{
				if (ownedUseCaseList->find(*iterOwnedUseCase) == -1)
				{
					getOwnedUseCase()->erase(*iterOwnedUseCase);
				}
				iterOwnedUseCase++;
			}
 
			iterOwnedUseCase = ownedUseCaseList->begin();
			endOwnedUseCase = ownedUseCaseList->end();
			while (iterOwnedUseCase != endOwnedUseCase)
			{
				if (getOwnedUseCase()->find(*iterOwnedUseCase) == -1)
				{
					getOwnedUseCase()->add(*iterOwnedUseCase);
				}
				iterOwnedUseCase++;			
			}
			return true;
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_POWERTYPEEXTENT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::GeneralizationSet>> powertypeExtentList(new Bag<uml::GeneralizationSet>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				powertypeExtentList->add(std::dynamic_pointer_cast<uml::GeneralizationSet>(*iter));
				iter++;
			}
			
			Bag<uml::GeneralizationSet>::iterator iterPowertypeExtent = getPowertypeExtent()->begin();
			Bag<uml::GeneralizationSet>::iterator endPowertypeExtent = getPowertypeExtent()->end();
			while (iterPowertypeExtent != endPowertypeExtent)
			{
				if (powertypeExtentList->find(*iterPowertypeExtent) == -1)
				{
					getPowertypeExtent()->erase(*iterPowertypeExtent);
				}
				iterPowertypeExtent++;
			}
 
			iterPowertypeExtent = powertypeExtentList->begin();
			endPowertypeExtent = powertypeExtentList->end();
			while (iterPowertypeExtent != endPowertypeExtent)
			{
				if (getPowertypeExtent()->find(*iterPowertypeExtent) == -1)
				{
					getPowertypeExtent()->add(*iterPowertypeExtent);
				}
				iterPowertypeExtent++;			
			}
			return true;
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_REDEFINEDCLASSIFIER:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Classifier>> redefinedClassifierList(new Bag<uml::Classifier>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				redefinedClassifierList->add(std::dynamic_pointer_cast<uml::Classifier>(*iter));
				iter++;
			}
			
			Bag<uml::Classifier>::iterator iterRedefinedClassifier = getRedefinedClassifier()->begin();
			Bag<uml::Classifier>::iterator endRedefinedClassifier = getRedefinedClassifier()->end();
			while (iterRedefinedClassifier != endRedefinedClassifier)
			{
				if (redefinedClassifierList->find(*iterRedefinedClassifier) == -1)
				{
					getRedefinedClassifier()->erase(*iterRedefinedClassifier);
				}
				iterRedefinedClassifier++;
			}
 
			iterRedefinedClassifier = redefinedClassifierList->begin();
			endRedefinedClassifier = redefinedClassifierList->end();
			while (iterRedefinedClassifier != endRedefinedClassifier)
			{
				if (getRedefinedClassifier()->find(*iterRedefinedClassifier) == -1)
				{
					getRedefinedClassifier()->add(*iterRedefinedClassifier);
				}
				iterRedefinedClassifier++;			
			}
			return true;
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_REPRESENTATION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::CollaborationUse> _representation = std::dynamic_pointer_cast<uml::CollaborationUse>(_temp);
			setRepresentation(_representation); //3636
			return true;
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_SUBSTITUTION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Substitution>> substitutionList(new Bag<uml::Substitution>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				substitutionList->add(std::dynamic_pointer_cast<uml::Substitution>(*iter));
				iter++;
			}
			
			Bag<uml::Substitution>::iterator iterSubstitution = getSubstitution()->begin();
			Bag<uml::Substitution>::iterator endSubstitution = getSubstitution()->end();
			while (iterSubstitution != endSubstitution)
			{
				if (substitutionList->find(*iterSubstitution) == -1)
				{
					getSubstitution()->erase(*iterSubstitution);
				}
				iterSubstitution++;
			}
 
			iterSubstitution = substitutionList->begin();
			endSubstitution = substitutionList->end();
			while (iterSubstitution != endSubstitution)
			{
				if (getSubstitution()->find(*iterSubstitution) == -1)
				{
					getSubstitution()->add(*iterSubstitution);
				}
				iterSubstitution++;			
			}
			return true;
		}
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_USECASE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::UseCase>> useCaseList(new Bag<uml::UseCase>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				useCaseList->add(std::dynamic_pointer_cast<uml::UseCase>(*iter));
				iter++;
			}
			
			Bag<uml::UseCase>::iterator iterUseCase = getUseCase()->begin();
			Bag<uml::UseCase>::iterator endUseCase = getUseCase()->end();
			while (iterUseCase != endUseCase)
			{
				if (useCaseList->find(*iterUseCase) == -1)
				{
					getUseCase()->erase(*iterUseCase);
				}
				iterUseCase++;
			}
 
			iterUseCase = useCaseList->begin();
			endUseCase = useCaseList->end();
			while (iterUseCase != endUseCase)
			{
				if (getUseCase()->find(*iterUseCase) == -1)
				{
					getUseCase()->add(*iterUseCase);
				}
				iterUseCase++;			
			}
			return true;
		}
	}

	bool result = false;
	result = NamespaceImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = RedefinableElementImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = TemplateableElementImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = TypeImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Behavioral Feature
//*********************************
Any ClassifierImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 3745
		case umlPackage::CLASSIFIER_OPERATION_ALLATTRIBUTES:
		{
			result = eAny(this->allAttributes());
			break;
		}
		
		// 3731
		case umlPackage::CLASSIFIER_OPERATION_ALLFEATURES:
		{
			result = eAny(this->allFeatures());
			break;
		}
		
		// 3732
		case umlPackage::CLASSIFIER_OPERATION_ALLPARENTS:
		{
			result = eAny(this->allParents());
			break;
		}
		
		// 3742
		case umlPackage::CLASSIFIER_OPERATION_ALLREALIZEDINTERFACES:
		{
			result = eAny(this->allRealizedInterfaces());
			break;
		}
		
		// 3746
		case umlPackage::CLASSIFIER_OPERATION_ALLSLOTTABLEFEATURES:
		{
			result = eAny(this->allSlottableFeatures());
			break;
		}
		
		// 3743
		case umlPackage::CLASSIFIER_OPERATION_ALLUSEDINTERFACES:
		{
			result = eAny(this->allUsedInterfaces());
			break;
		}
		
		// 3740
		case umlPackage::CLASSIFIER_OPERATION_DIRECTLYREALIZEDINTERFACES:
		{
			result = eAny(this->directlyRealizedInterfaces());
			break;
		}
		
		// 3741
		case umlPackage::CLASSIFIER_OPERATION_DIRECTLYUSEDINTERFACES:
		{
			result = eAny(this->directlyUsedInterfaces());
			break;
		}
		
		// 3724
		case umlPackage::CLASSIFIER_OPERATION_GETALLATTRIBUTES:
		{
			result = eAny(this->getAllAttributes());
			break;
		}
		
		// 3725
		case umlPackage::CLASSIFIER_OPERATION_GETALLOPERATIONS:
		{
			result = eAny(this->getAllOperations());
			break;
		}
		
		// 3726
		case umlPackage::CLASSIFIER_OPERATION_GETALLUSEDINTERFACES:
		{
			result = eAny(this->getAllUsedInterfaces());
			break;
		}
		
		// 3733
		case umlPackage::CLASSIFIER_OPERATION_GETGENERALS:
		{
			result = eAny(this->getGenerals());
			break;
		}
		
		// 3737
		case umlPackage::CLASSIFIER_OPERATION_GETINHERITEDMEMBERS:
		{
			result = eAny(this->getInheritedMembers());
			break;
		}
		
		// 3727
		case umlPackage::CLASSIFIER_OPERATION_GETOPERATION_STRING_TYPE:
		{
			//Retrieve input parameter 'name'
			//parameter 0
			std::string incoming_param_name;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_name_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_name = (*incoming_param_name_arguments_citer)->get()->get<std::string >();
			//Retrieve input parameter 'parameterNames'
			//parameter 1
			std::shared_ptr<Bag<std::string>> incoming_param_parameterNames;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_parameterNames_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_parameterNames = (*incoming_param_parameterNames_arguments_citer)->get()->get<std::shared_ptr<Bag<std::string>> >();
			//Retrieve input parameter 'parameterTypes'
			//parameter 2
			std::shared_ptr<Bag<uml::Type>> incoming_param_parameterTypes;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_parameterTypes_arguments_citer = std::next(arguments->begin(), 2);
			incoming_param_parameterTypes = (*incoming_param_parameterTypes_arguments_citer)->get()->get<std::shared_ptr<Bag<uml::Type>> >();
			result = eAny(this->getOperation(incoming_param_name,incoming_param_parameterNames,incoming_param_parameterTypes));
			break;
		}
		
		// 3728
		case umlPackage::CLASSIFIER_OPERATION_GETOPERATION_STRING_BOOLEAN:
		{
			//Retrieve input parameter 'name'
			//parameter 0
			std::string incoming_param_name;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_name_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_name = (*incoming_param_name_arguments_citer)->get()->get<std::string >();
			//Retrieve input parameter 'parameterNames'
			//parameter 1
			std::shared_ptr<Bag<std::string>> incoming_param_parameterNames;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_parameterNames_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_parameterNames = (*incoming_param_parameterNames_arguments_citer)->get()->get<std::shared_ptr<Bag<std::string>> >();
			//Retrieve input parameter 'parameterTypes'
			//parameter 2
			std::shared_ptr<Bag<uml::Type>> incoming_param_parameterTypes;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_parameterTypes_arguments_citer = std::next(arguments->begin(), 2);
			incoming_param_parameterTypes = (*incoming_param_parameterTypes_arguments_citer)->get()->get<std::shared_ptr<Bag<uml::Type>> >();
			//Retrieve input parameter 'ignoreCase'
			//parameter 3
			bool incoming_param_ignoreCase;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_ignoreCase_arguments_citer = std::next(arguments->begin(), 3);
			incoming_param_ignoreCase = (*incoming_param_ignoreCase_arguments_citer)->get()->get<bool >();
			result = eAny(this->getOperation(incoming_param_name,incoming_param_parameterNames,incoming_param_parameterTypes,incoming_param_ignoreCase));
			break;
		}
		
		// 3729
		case umlPackage::CLASSIFIER_OPERATION_GETOPERATIONS:
		{
			result = eAny(this->getOperations());
			break;
		}
		
		// 3747
		case umlPackage::CLASSIFIER_OPERATION_GETPROPERTYVALUE_STRING:
		{
			//Retrieve input parameter 'propertyName'
			//parameter 0
			std::string incoming_param_propertyName;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_propertyName_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_propertyName = (*incoming_param_propertyName_arguments_citer)->get()->get<std::string >();
			result = eAny(this->getPropertyValue(incoming_param_propertyName));
			break;
		}
		
		// 3730
		case umlPackage::CLASSIFIER_OPERATION_GETUSEDINTERFACES:
		{
			result = eAny(this->getUsedInterfaces());
			break;
		}
		
		// 3734
		case umlPackage::CLASSIFIER_OPERATION_HASVISIBILITYOF_NAMEDELEMENT:
		{
			//Retrieve input parameter 'n'
			//parameter 0
			std::shared_ptr<uml::NamedElement> incoming_param_n;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_n_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_n = (*incoming_param_n_arguments_citer)->get()->get<std::shared_ptr<uml::NamedElement> >();
			result = eAny(this->hasVisibilityOf(incoming_param_n));
			break;
		}
		
		// 3735
		case umlPackage::CLASSIFIER_OPERATION_INHERIT_NAMEDELEMENT:
		{
			//Retrieve input parameter 'inhs'
			//parameter 0
			std::shared_ptr<Bag<uml::NamedElement>> incoming_param_inhs;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_inhs_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_inhs = (*incoming_param_inhs_arguments_citer)->get()->get<std::shared_ptr<Bag<uml::NamedElement>> >();
			result = eAny(this->inherit(incoming_param_inhs));
			break;
		}
		
		// 3736
		case umlPackage::CLASSIFIER_OPERATION_INHERITABLEMEMBERS_CLASSIFIER:
		{
			//Retrieve input parameter 'c'
			//parameter 0
			std::shared_ptr<uml::Classifier> incoming_param_c;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_c_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_c = (*incoming_param_c_arguments_citer)->get()->get<std::shared_ptr<uml::Classifier> >();
			result = eAny(this->inheritableMembers(incoming_param_c));
			break;
		}
		
		// 3744
		case umlPackage::CLASSIFIER_OPERATION_ISSUBSTITUTABLEFOR_CLASSIFIER:
		{
			//Retrieve input parameter 'contract'
			//parameter 0
			std::shared_ptr<uml::Classifier> incoming_param_contract;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_contract_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_contract = (*incoming_param_contract_arguments_citer)->get()->get<std::shared_ptr<uml::Classifier> >();
			result = eAny(this->isSubstitutableFor(incoming_param_contract));
			break;
		}
		
		// 3721
		case umlPackage::CLASSIFIER_OPERATION_MAPS_TO_GENERALIZATION_SET_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->maps_to_generalization_set(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 3738
		case umlPackage::CLASSIFIER_OPERATION_MAYSPECIALIZETYPE_CLASSIFIER:
		{
			//Retrieve input parameter 'c'
			//parameter 0
			std::shared_ptr<uml::Classifier> incoming_param_c;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_c_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_c = (*incoming_param_c_arguments_citer)->get()->get<std::shared_ptr<uml::Classifier> >();
			result = eAny(this->maySpecializeType(incoming_param_c));
			break;
		}
		
		// 3723
		case umlPackage::CLASSIFIER_OPERATION_NO_CYCLES_IN_GENERALIZATION_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->no_cycles_in_generalization(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 3722
		case umlPackage::CLASSIFIER_OPERATION_NON_FINAL_PARENTS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->non_final_parents(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 3739
		case umlPackage::CLASSIFIER_OPERATION_PARENTS:
		{
			result = eAny(this->parents());
			break;
		}
		
		// 3720
		case umlPackage::CLASSIFIER_OPERATION_SPECIALIZE_TYPE_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->specialize_type(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = TemplateableElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = TypeImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = RedefinableElementImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			result = NamespaceImpl::eInvoke(operationID, arguments);
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
void ClassifierImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ClassifierImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isAbstract");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsAbstract(value);
		}

		iter = attr_list.find("isFinalSpecialization");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsFinalSpecialization(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("general");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("general")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("powertypeExtent");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("powertypeExtent")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("redefinedClassifier");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("redefinedClassifier")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("representation");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("representation")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("useCase");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("useCase")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	NamespaceImpl::loadAttributes(loadHandler, attr_list);
	RedefinableElementImpl::loadAttributes(loadHandler, attr_list);
	TemplateableElementImpl::loadAttributes(loadHandler, attr_list);
	TypeImpl::loadAttributes(loadHandler, attr_list);
}

void ClassifierImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("collaborationUse") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "CollaborationUse";
			}
			loadHandler->handleChildContainer<uml::CollaborationUse>(this->getCollaborationUse());  

			return; 
		}

		if ( nodeName.compare("generalization") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Generalization";
			}
			loadHandler->handleChildContainer<uml::Generalization>(this->getGeneralization());  

			return; 
		}

		if ( nodeName.compare("ownedUseCase") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "UseCase";
			}
			loadHandler->handleChildContainer<uml::UseCase>(this->getOwnedUseCase());  

			return; 
		}

		if ( nodeName.compare("substitution") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Substitution";
			}
			loadHandler->handleChildContainer<uml::Substitution>(this->getSubstitution());  

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
	NamespaceImpl::loadNode(nodeName, loadHandler);
	RedefinableElementImpl::loadNode(nodeName, loadHandler);
	TemplateableElementImpl::loadNode(nodeName, loadHandler);
	TypeImpl::loadNode(nodeName, loadHandler);
}

void ClassifierImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_GENERAL:
		{
			std::shared_ptr<Bag<uml::Classifier>> _general = getGeneral();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Classifier>  _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_general->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_POWERTYPEEXTENT:
		{
			std::shared_ptr<Bag<uml::GeneralizationSet>> _powertypeExtent = getPowertypeExtent();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::GeneralizationSet>  _r = std::dynamic_pointer_cast<uml::GeneralizationSet>(ref);
				if (_r != nullptr)
				{
					_powertypeExtent->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_REDEFINEDCLASSIFIER:
		{
			std::shared_ptr<SubsetUnion<uml::Classifier, uml::RedefinableElement>> _redefinedClassifier = getRedefinedClassifier();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Classifier>  _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_redefinedClassifier->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_REPRESENTATION:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::CollaborationUse> _representation = std::dynamic_pointer_cast<uml::CollaborationUse>( references.front() );
				setRepresentation(_representation);
			}
			
			return;
		}

		case uml::umlPackage::CLASSIFIER_ATTRIBUTE_USECASE:
		{
			std::shared_ptr<Bag<uml::UseCase>> _useCase = getUseCase();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::UseCase>  _r = std::dynamic_pointer_cast<uml::UseCase>(ref);
				if (_r != nullptr)
				{
					_useCase->push_back(_r);
				}
			}
			return;
		}
	}
	NamespaceImpl::resolveReferences(featureID, references);
	RedefinableElementImpl::resolveReferences(featureID, references);
	TemplateableElementImpl::resolveReferences(featureID, references);
	TypeImpl::resolveReferences(featureID, references);
}

void ClassifierImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamespaceImpl::saveContent(saveHandler);
	RedefinableElementImpl::saveContent(saveHandler);
	TemplateableElementImpl::saveContent(saveHandler);
	TypeImpl::saveContent(saveHandler);
	
	PackageableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void ClassifierImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'generalization'
		for (std::shared_ptr<uml::Generalization> generalization : *this->getGeneralization()) 
		{
			saveHandler->addReference(generalization, "generalization", generalization->eClass() != package->getGeneralization_Class());
		}

		// Save 'ownedUseCase'
		for (std::shared_ptr<uml::UseCase> ownedUseCase : *this->getOwnedUseCase()) 
		{
			saveHandler->addReference(ownedUseCase, "ownedUseCase", ownedUseCase->eClass() != package->getUseCase_Class());
		}

		// Save 'substitution'
		for (std::shared_ptr<uml::Substitution> substitution : *this->getSubstitution()) 
		{
			saveHandler->addReference(substitution, "substitution", substitution->eClass() != package->getSubstitution_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getClassifier_Attribute_isAbstract()) )
		{
			saveHandler->addAttribute("isAbstract", this->getIsAbstract());
		}

		if ( this->eIsSet(package->getClassifier_Attribute_isFinalSpecialization()) )
		{
			saveHandler->addAttribute("isFinalSpecialization", this->getIsFinalSpecialization());
		}
	// Add references
		saveHandler->addReferences<uml::Classifier>("general", this->getGeneral());
		saveHandler->addReferences<uml::GeneralizationSet>("powertypeExtent", this->getPowertypeExtent());
		saveHandler->addReferences<uml::Classifier>("redefinedClassifier", this->getRedefinedClassifier());
		saveHandler->addReference(this->getRepresentation(), "representation", getRepresentation()->eClass() != uml::umlPackage::eInstance()->getCollaborationUse_Class()); 
		saveHandler->addReferences<uml::UseCase>("useCase", this->getUseCase());
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'collaborationUse'

		saveHandler->addReferences<uml::CollaborationUse>("collaborationUse", this->getCollaborationUse());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

