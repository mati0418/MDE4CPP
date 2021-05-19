//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_GENERALORDERING_HPP
#define UML_GENERALORDERING_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations

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
	class Comment;
	class Dependency;
	class Namespace;
	class OccurrenceSpecification;
	class StringExpression;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/NamedElement.hpp"

// enum includes
#include "uml/VisibilityKind.hpp"



//*********************************
namespace uml 
{
	/*!
	A GeneralOrdering represents a binary relation between two OccurrenceSpecifications, to describe that one OccurrenceSpecification must occur before the other in a valid trace. This mechanism provides the ability to define partial orders of OccurrenceSpecifications that may otherwise not have a specified order.
	<p>From package UML::Interactions.</p>
	*/
	
	class UML_API GeneralOrdering: virtual public NamedElement
	{
		public:
 			GeneralOrdering(const GeneralOrdering &) {}

		protected:
			GeneralOrdering(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~GeneralOrdering() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			An occurrence specification must not be ordered relative to itself through a series of general orderings. (In other words, the transitive closure of the general orderings is irreflexive.)
			after->closure(toAfter.after)->excludes(before)
			*/
			 
			virtual bool irreflexive_transitive_closure(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The OccurrenceSpecification referenced comes after the OccurrenceSpecification referenced by before.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::OccurrenceSpecification> getAfter() const = 0;
			/*!
			The OccurrenceSpecification referenced comes after the OccurrenceSpecification referenced by before.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setAfter(std::shared_ptr<uml::OccurrenceSpecification>) = 0;
			/*!
			The OccurrenceSpecification referenced comes before the OccurrenceSpecification referenced by after.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual std::shared_ptr<uml::OccurrenceSpecification> getBefore() const = 0;
			/*!
			The OccurrenceSpecification referenced comes before the OccurrenceSpecification referenced by after.
			<p>From package UML::Interactions.</p>
			*/
			
			virtual void setBefore(std::shared_ptr<uml::OccurrenceSpecification>) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			The OccurrenceSpecification referenced comes after the OccurrenceSpecification referenced by before.
			<p>From package UML::Interactions.</p>
			*/
			
			std::shared_ptr<uml::OccurrenceSpecification> m_after;/*!
			The OccurrenceSpecification referenced comes before the OccurrenceSpecification referenced by after.
			<p>From package UML::Interactions.</p>
			*/
			
			std::shared_ptr<uml::OccurrenceSpecification> m_before;

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
#endif /* end of include guard: UML_GENERALORDERING_HPP */
