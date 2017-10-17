//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CLASSIFIER_HPP
#define UML_CLASSIFIER_HPP

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

#include <string>
#include <map>
#include <vector>
#include "SubsetUnion.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/any.hpp"

//*********************************
// generated Includes

//Forward Declaration for used types
namespace uml 
{
	class Classifier;
}

namespace uml 
{
	class CollaborationUse;
}

namespace uml 
{
	class Comment;
}

namespace uml 
{
	class Constraint;
}

namespace uml 
{
	class Dependency;
}

namespace ecore 
{
	class EAnnotation;
}

namespace uml 
{
	class Element;
}

namespace uml 
{
	class ElementImport;
}

namespace uml 
{
	class Feature;
}

namespace uml 
{
	class Generalization;
}

namespace uml 
{
	class GeneralizationSet;
}

namespace uml 
{
	class Interface;
}

namespace uml 
{
	class NamedElement;
}

namespace uml 
{
	class Namespace;
}

namespace uml 
{
	class Operation;
}

namespace uml 
{
	class Package;
}

namespace uml 
{
	class PackageImport;
}

namespace uml 
{
	class PackageableElement;
}

namespace uml 
{
	class Property;
}

namespace uml 
{
	class RedefinableElement;
}

namespace uml 
{
	class StringExpression;
}

namespace uml 
{
	class StructuralFeature;
}

namespace uml 
{
	class Substitution;
}

namespace uml 
{
	class TemplateBinding;
}

namespace uml 
{
	class TemplateParameter;
}

namespace uml 
{
	class TemplateSignature;
}

namespace uml 
{
	class TemplateableElement;
}

namespace uml 
{
	class Type;
}

namespace uml 
{
	class UseCase;
}

// base class includes
#include "Namespace.hpp"

#include "RedefinableElement.hpp"

#include "TemplateableElement.hpp"

#include "Type.hpp"

// enum includes
#include "VisibilityKind.hpp"


//*********************************
namespace uml 
{
	/*!
	 A Classifier represents a classification of instances according to their Features.
	<p>From package UML::Classification.</p> */
	class Classifier:virtual public Namespace,virtual public RedefinableElement,virtual public TemplateableElement,virtual public Type
	{
		public:
 			Classifier(const Classifier &) {}
			Classifier& operator=(Classifier const&) = delete;

		protected:
			Classifier(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Classifier() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 The query allAttributes gives an ordered set of all owned and inherited attributes of the Classifier. All owned attributes appear before any inherited attributes, and the attributes inherited from any more specific parent Classifier appear before those of any more general parent Classifier. However, if the Classifier has multiple immediate parents, then the relative ordering of the sets of attributes from those parents is not defined.
			result = (attribute->asSequence()->union(parents()->asSequence().allAttributes())->select(p | member->includes(p))->asOrderedSet())
			<p>From package UML::Classification.</p> */ 
			virtual std::shared_ptr<Bag<uml::Property> > allAttributes()  = 0;
			
			/*!
			 The query allFeatures() gives all of the Features in the namespace of the Classifier. In general, through mechanisms such as inheritance, this will be a larger set than feature.
			result = (member->select(oclIsKindOf(Feature))->collect(oclAsType(Feature))->asSet())
			<p>From package UML::Classification.</p> */ 
			virtual std::shared_ptr<Bag<uml::Feature> > allFeatures()  = 0;
			
			/*!
			 The query allParents() gives all of the direct and indirect ancestors of a generalized Classifier.
			result = (parents()->union(parents()->collect(allParents())->asSet()))
			<p>From package UML::Classification.</p> */ 
			virtual std::shared_ptr<Bag<uml::Classifier> > allParents()  = 0;
			
			/*!
			 The Interfaces realized by this Classifier and all of its generalizations
			result = (directlyRealizedInterfaces()->union(self.allParents()->collect(directlyRealizedInterfaces()))->asSet())
			<p>From package UML::Classification.</p> */ 
			virtual std::shared_ptr<Bag<uml::Interface> > allRealizedInterfaces()  = 0;
			
			/*!
			 All StructuralFeatures related to the Classifier that may have Slots, including direct attributes, inherited attributes, private attributes in generalizations, and memberEnds of Associations, but excluding redefined StructuralFeatures.
			result = (member->select(oclIsKindOf(StructuralFeature))->
			  collect(oclAsType(StructuralFeature))->
			   union(self.inherit(self.allParents()->collect(p | p.attribute)->asSet())->
			     collect(oclAsType(StructuralFeature)))->asSet())
			<p>From package UML::Classification.</p> */ 
			virtual std::shared_ptr<Bag<uml::StructuralFeature> > allSlottableFeatures()  = 0;
			
			/*!
			 The Interfaces used by this Classifier and all of its generalizations
			result = (directlyUsedInterfaces()->union(self.allParents()->collect(directlyUsedInterfaces()))->asSet())
			<p>From package UML::Classification.</p> */ 
			virtual std::shared_ptr<Bag<uml::Interface> > allUsedInterfaces()  = 0;
			
			/*!
			 The Interfaces directly realized by this Classifier
			result = ((clientDependency->
			  select(oclIsKindOf(Realization) and supplier->forAll(oclIsKindOf(Interface))))->
			      collect(supplier.oclAsType(Interface))->asSet())
			<p>From package UML::Classification.</p> */ 
			virtual std::shared_ptr<Bag<uml::Interface> > directlyRealizedInterfaces()  = 0;
			
			/*!
			 The Interfaces directly used by this Classifier
			result = ((supplierDependency->
			  select(oclIsKindOf(Usage) and client->forAll(oclIsKindOf(Interface))))->
			    collect(client.oclAsType(Interface))->asSet())
			<p>From package UML::Classification.</p> */ 
			virtual std::shared_ptr<Bag<uml::Interface> > directlyUsedInterfaces()  = 0;
			
			/*!
			 Retrieves all the attributes of this classifier, including those inherited from its parents. */ 
			virtual std::shared_ptr<Bag<uml::Property> > getAllAttributes()  = 0;
			
			/*!
			 Retrieves all the operations of this classifier, including those inherited from its parents. */ 
			virtual std::shared_ptr<Bag<uml::Operation> > getAllOperations()  = 0;
			
			/*!
			 Retrieves all the interfaces on which this classifier or any of its parents has a usage dependency. */ 
			virtual std::shared_ptr<Bag<uml::Interface> > getAllUsedInterfaces()  = 0;
			
			/*!
			 The general Classifiers are the ones referenced by the Generalization relationships.
			result = (parents())
			<p>From package UML::Classification.</p> */ 
			virtual std::shared_ptr<Bag<uml::Classifier> > getGenerals()  = 0;
			
			/*!
			 The inheritedMember association is derived by inheriting the inheritable members of the parents.
			result = (inherit(parents()->collect(inheritableMembers(self))->asSet()))
			<p>From package UML::Classification.</p> */ 
			virtual std::shared_ptr<Bag<uml::NamedElement> > getInheritedMembers()  = 0;
			
			/*!
			 Retrieves the first operation with the specified name, parameter names, and parameter types from this classifier. */ 
			virtual std::shared_ptr<uml::Operation> getOperation(std::string name,std::shared_ptr<Bag<std::string> >  parameterNames,std::shared_ptr<Bag<uml::Type> >  parameterTypes)  = 0;
			
			/*!
			 Retrieves the first operation with the specified name, parameter names, and parameter types from this classifier, ignoring case if indicated. */ 
			virtual std::shared_ptr<uml::Operation> getOperation(std::string name,std::shared_ptr<Bag<std::string> >  parameterNames,std::shared_ptr<Bag<uml::Type> >  parameterTypes,bool ignoreCase)  = 0;
			
			/*!
			 Retrieves the operations of this classifier. */ 
			virtual std::shared_ptr<Bag<uml::Operation> > getOperations()  = 0;
			
			/*!
			 Retrieves the interfaces on which this classifier has a usage dependency. */ 
			virtual std::shared_ptr<Bag<uml::Interface> > getUsedInterfaces()  = 0;
			
			/*!
			 The query hasVisibilityOf() determines whether a NamedElement is visible in the classifier. Non-private members are visible. It is only called when the argument is something owned by a parent.
			allParents()->including(self)->collect(member)->includes(n)
			result = (n.visibility <> VisibilityKind::private)
			<p>From package UML::Classification.</p> */ 
			virtual bool hasVisibilityOf(std::shared_ptr<uml::NamedElement>  n)  = 0;
			
			/*!
			 The query inherit() defines how to inherit a set of elements passed as its argument.  It excludes redefined elements from the result.
			result = (inhs->reject(inh |
			  inh.oclIsKindOf(RedefinableElement) and
			  ownedMember->select(oclIsKindOf(RedefinableElement))->
			    select(redefinedElement->includes(inh.oclAsType(RedefinableElement)))
			       ->notEmpty()))
			<p>From package UML::Classification.</p> */ 
			virtual std::shared_ptr<Bag<uml::NamedElement> > inherit(std::shared_ptr<Bag<uml::NamedElement> >  inhs)  = 0;
			
			/*!
			 The query inheritableMembers() gives all of the members of a Classifier that may be inherited in one of its descendants, subject to whatever visibility restrictions apply.
			c.allParents()->includes(self)
			result = (member->select(m | c.hasVisibilityOf(m)))
			<p>From package UML::Classification.</p> */ 
			virtual std::shared_ptr<Bag<uml::NamedElement> > inheritableMembers(std::shared_ptr<uml::Classifier>  c)  = 0;
			
			/*!
			 result = (substitution.contract->includes(contract))
			<p>From package UML::Classification.</p> */ 
			virtual bool isSubstitutableFor(std::shared_ptr<uml::Classifier>  contract)  = 0;
			
			/*!
			 The Classifier that maps to a GeneralizationSet may neither be a specific nor a general Classifier in any of the Generalization relationships defined for that GeneralizationSet. In other words, a power type may not be an instance of itself nor may its instances also be its subclasses.
			powertypeExtent->forAll( gs | 
			  gs.generalization->forAll( gen | 
			    not (gen.general = self) and not gen.general.allParents()->includes(self) and not (gen.specific = self) and not self.allParents()->includes(gen.specific) 
			  )) */ 
			virtual bool maps_to_generalization_set(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 The query maySpecializeType() determines whether this classifier may have a generalization relationship to classifiers of the specified type. By default a classifier may specialize classifiers of the same or a more general type. It is intended to be redefined by classifiers that have different specialization constraints.
			result = (self.oclIsKindOf(c.oclType()))
			<p>From package UML::Classification.</p> */ 
			virtual bool maySpecializeType(std::shared_ptr<uml::Classifier>  c)  = 0;
			
			/*!
			 Generalization hierarchies must be directed and acyclical. A Classifier can not be both a transitively general and transitively specific Classifier of the same Classifier.
			not allParents()->includes(self) */ 
			virtual bool no_cycles_in_generalization(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 The parents of a Classifier must be non-final.
			parents()->forAll(not isFinalSpecialization) */ 
			virtual bool non_final_parents(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			/*!
			 The query parents() gives all of the immediate ancestors of a generalized Classifier.
			result = (generalization.general->asSet())
			<p>From package UML::Classification.</p> */ 
			virtual std::shared_ptr<Bag<uml::Classifier> > parents()  = 0;
			
			/*!
			 A Classifier may only specialize Classifiers of a valid type.
			parents()->forAll(c | self.maySpecializeType(c)) */ 
			virtual bool specialize_type(boost::any diagnostics,std::map <   boost::any, boost::any >  context)  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 If true, the Classifier can only be instantiated by instantiating one of its specializations. An abstract Classifier is intended to be used by other Classifiers e.g., as the target of Associations or Generalizations.
			<p>From package UML::Classification.</p> */ 
			virtual bool getIsAbstract() const = 0;
			
			/*!
			 If true, the Classifier can only be instantiated by instantiating one of its specializations. An abstract Classifier is intended to be used by other Classifiers e.g., as the target of Associations or Generalizations.
			<p>From package UML::Classification.</p> */ 
			virtual void setIsAbstract (bool _isAbstract)= 0; 
			
			/*!
			 If true, the Classifier cannot be specialized.
			<p>From package UML::Classification.</p> */ 
			virtual bool getIsFinalSpecialization() const = 0;
			
			/*!
			 If true, the Classifier cannot be specialized.
			<p>From package UML::Classification.</p> */ 
			virtual void setIsFinalSpecialization (bool _isFinalSpecialization)= 0; 
			
			
			//*********************************
			// Reference
			//*********************************
			
			/*!
			 The CollaborationUses owned by the Classifier.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::CollaborationUse, uml::Element > > getCollaborationUse() const = 0;
			
			
			/*!
			 The generalizing Classifiers for this Classifier.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr< Bag<uml::Classifier> > getGeneral() const = 0;
			
			/*!
			 The Generalization relationships for this Classifier. These Generalizations navigate to more general Classifiers in the generalization hierarchy.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<Subset<uml::Generalization, uml::Element > > getGeneralization() const = 0;
			
			/*!
			 All elements inherited by this Classifier from its general Classifiers.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<Subset<uml::NamedElement, uml::NamedElement > > getInheritedMember() const = 0;
			
			/*!
			 The UseCases owned by this classifier.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<Subset<uml::UseCase, uml::NamedElement > > getOwnedUseCase() const = 0;
			
			/*!
			 The GeneralizationSet of which this Classifier is a power type.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr< Bag<uml::GeneralizationSet> > getPowertypeExtent() const = 0;
			
			/*!
			 The Classifiers redefined by this Classifier.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::Classifier, uml::RedefinableElement > > getRedefinedClassifier() const = 0;
			
			/*!
			 A CollaborationUse which indicates the Collaboration that represents this Classifier.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<uml::CollaborationUse > getRepresentation() const = 0;
			
			/*!
			 A CollaborationUse which indicates the Collaboration that represents this Classifier.
			<p>From package UML::Classification.</p> */
			virtual void setRepresentation(std::shared_ptr<uml::CollaborationUse> _representation_representation) = 0;
			/*!
			 The Substitutions owned by this Classifier.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<Subset<uml::Substitution, uml::Element > > getSubstitution() const = 0;
			
			/*!
			 The set of UseCases for which this Classifier is the subject.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr< Bag<uml::UseCase> > getUseCase() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			 If true, the Classifier can only be instantiated by instantiating one of its specializations. An abstract Classifier is intended to be used by other Classifiers e.g., as the target of Associations or Generalizations.
			<p>From package UML::Classification.</p> */ 
			bool m_isAbstract =  false;
			/*!
			 If true, the Classifier cannot be specialized.
			<p>From package UML::Classification.</p> */ 
			bool m_isFinalSpecialization =  false;
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 All of the Properties that are direct (i.e., not inherited or imported) attributes of the Classifier.
			<p>From package UML::Classification.</p> */
			std::shared_ptr<SubsetUnion<uml::Property, uml::Feature > > m_attribute;
			/*!
			 The CollaborationUses owned by the Classifier.
			<p>From package UML::Classification.</p> */
			std::shared_ptr<SubsetUnion<uml::CollaborationUse, uml::Element > > m_collaborationUse;
			/*!
			 Specifies each Feature directly defined in the classifier. Note that there may be members of the Classifier that are of the type Feature but are not included, e.g., inherited features.
			<p>From package UML::Classification.</p> */
			std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement > > m_feature;
			/*!
			 The generalizing Classifiers for this Classifier.
			<p>From package UML::Classification.</p> */
			std::shared_ptr< Bag<uml::Classifier> > m_general;
			/*!
			 The Generalization relationships for this Classifier. These Generalizations navigate to more general Classifiers in the generalization hierarchy.
			<p>From package UML::Classification.</p> */
			std::shared_ptr<Subset<uml::Generalization, uml::Element > > m_generalization;
			/*!
			 All elements inherited by this Classifier from its general Classifiers.
			<p>From package UML::Classification.</p> */
			std::shared_ptr<Subset<uml::NamedElement, uml::NamedElement > > m_inheritedMember;
			/*!
			 The UseCases owned by this classifier.
			<p>From package UML::Classification.</p> */
			std::shared_ptr<Subset<uml::UseCase, uml::NamedElement > > m_ownedUseCase;
			/*!
			 The GeneralizationSet of which this Classifier is a power type.
			<p>From package UML::Classification.</p> */
			std::shared_ptr< Bag<uml::GeneralizationSet> > m_powertypeExtent;
			/*!
			 The Classifiers redefined by this Classifier.
			<p>From package UML::Classification.</p> */
			std::shared_ptr<SubsetUnion<uml::Classifier, uml::RedefinableElement > > m_redefinedClassifier;
			/*!
			 A CollaborationUse which indicates the Collaboration that represents this Classifier.
			<p>From package UML::Classification.</p> */
			std::shared_ptr<uml::CollaborationUse > m_representation;
			/*!
			 The Substitutions owned by this Classifier.
			<p>From package UML::Classification.</p> */
			std::shared_ptr<Subset<uml::Substitution, uml::Element > > m_substitution;
			/*!
			 The set of UseCases for which this Classifier is the subject.
			<p>From package UML::Classification.</p> */
			std::shared_ptr< Bag<uml::UseCase> > m_useCase;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 All of the Properties that are direct (i.e., not inherited or imported) attributes of the Classifier.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::Property, uml::Feature > > getAttribute() const = 0;/*!
			 Specifies each Feature directly defined in the classifier. Note that there may be members of the Classifier that are of the type Feature but are not included, e.g., inherited features.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement > > getFeature() const = 0;/*!
			 A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::NamedElement> > getMember() const = 0;/*!
			 Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Namespace > getNamespace() const = 0;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element> > getOwnedElement() const = 0;/*!
			 A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > > getOwnedMember() const = 0;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const = 0;/*!
			 The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<Union<uml::RedefinableElement> > getRedefinedElement() const = 0; 
	};

}
#endif /* end of include guard: UML_CLASSIFIER_HPP */

