//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_CLASSIFIERTEMPLATEPARAMETER_HPP
#define UML_CLASSIFIERTEMPLATEPARAMETER_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 

class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

//*********************************
// generated Includes
#include <map> // used for Persistence
#include <vector> // used for Persistence
namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace uml
{
	class umlFactory;
}

//Forward Declaration for used types 
namespace uml 
{
	class Classifier;
	class Comment;
	class ParameterableElement;
	class TemplateSignature;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/TemplateParameter.hpp"

// enum includes



//*********************************
namespace uml 
{
	/*!
	A ClassifierTemplateParameter exposes a Classifier as a formal template parameter.
	<p>From package UML::Classification.</p>
	*/
	
	class UML_API ClassifierTemplateParameter: virtual public TemplateParameter
	{
		public:
 			ClassifierTemplateParameter(const ClassifierTemplateParameter &) {}

		protected:
			ClassifierTemplateParameter(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ClassifierTemplateParameter() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			The argument to a ClassifierTemplateParameter is a Classifier.
			 templateParameterSubstitution.actual->forAll(a | a.oclIsKindOf(Classifier))
			*/
			 
			virtual bool actual_is_classifier(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			If there are any constrainingClassifiers, then every argument must be the same as or a specialization of them, or if allowSubstitutable is true, then it can also be substitutable.
			templateParameterSubstitution.actual->forAll( a |
			  let arg : Classifier = a.oclAsType(Classifier) in
			    constrainingClassifier->forAll(
			      cc |  
			         arg = cc or arg.conformsTo(cc) or (allowSubstitutable and arg.isSubstitutableFor(cc))
			      )
			)
			*/
			 
			virtual bool constraining_classifiers_constrain_args(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			If there are any constrainingClassifiers, then the parameteredElement must be the same as or a specialization of them, or if allowSubstitutable is true, then it can also be substitutable.
			constrainingClassifier->forAll(
			     cc |  parameteredElement = cc or parameteredElement.conformsTo(cc) or (allowSubstitutable and parameteredElement.isSubstitutableFor(cc))
			)
			*/
			 
			virtual bool constraining_classifiers_constrain_parametered_element(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			If allowSubstitutable is true, then there must be a constrainingClassifier.
			allowSubstitutable implies constrainingClassifier->notEmpty()
			*/
			 
			virtual bool has_constraining_classifier(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			If the parameteredElement is not abstract, then the Classifier used as an argument shall not be abstract.
			(not parameteredElement.isAbstract) implies templateParameterSubstitution.actual->forAll(a | not a.oclAsType(Classifier).isAbstract)
			*/
			 
			virtual bool matching_abstract(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			The parameteredElement has no direct features, and if constrainedElement is empty it has no generalizations.
			parameteredElement.feature->isEmpty() and (constrainingClassifier->isEmpty() implies  parameteredElement.allParents()->isEmpty())
			*/
			 
			virtual bool parametered_element_no_features(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			Constrains the required relationship between an actual parameter and the parameteredElement for this formal parameter.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual bool getAllowSubstitutable() const = 0;
			/*!
			Constrains the required relationship between an actual parameter and the parameteredElement for this formal parameter.
			<p>From package UML::Classification.</p>
			*/
			 
			virtual void setAllowSubstitutable (bool _allowSubstitutable)= 0;
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The classifiers that constrain the argument that can be used for the parameter. If the allowSubstitutable attribute is true, then any Classifier that is compatible with this constraining Classifier can be substituted; otherwise, it must be either this Classifier or one of its specializations. If this property is empty, there are no constraints on the Classifier that can be used as an argument.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Classifier>> getConstrainingClassifier() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			Constrains the required relationship between an actual parameter and the parameteredElement for this formal parameter.
			<p>From package UML::Classification.</p>
			*/
			
			bool m_allowSubstitutable = true;
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The classifiers that constrain the argument that can be used for the parameter. If the allowSubstitutable attribute is true, then any Classifier that is compatible with this constraining Classifier can be substituted; otherwise, it must be either this Classifier or one of its specializations. If this property is empty, there are no constraints on the Classifier that can be used as an argument.
			<p>From package UML::Classification.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Classifier>> m_constrainingClassifier;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_CLASSIFIERTEMPLATEPARAMETER_HPP */
