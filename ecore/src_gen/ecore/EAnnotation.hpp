//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EANNOTATION_HPP
#define ECORE_EANNOTATION_HPP

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
namespace ecore 
{
	class EAnnotation;
}

namespace ecore 
{
	class EModelElement;
}

namespace ecore 
{
	class EObject;
}

namespace ecore 
{
	class EStringToStringMapEntry;
}

// base class includes
#include "EModelElement.hpp"

// enum includes


//*********************************
namespace ecore 
{
	/*!
	 */
	class EAnnotation:virtual public EModelElement
	{
		public:
 			EAnnotation(const EAnnotation &) {}
			EAnnotation& operator=(EAnnotation const&) = delete;

		protected:
			EAnnotation(){}


			//Additional constructors for the containments back reference

			EAnnotation(std::weak_ptr<ecore::EModelElement > par_eModelElement);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EAnnotation() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 */ 
			virtual std::string getSource() const = 0;
			
			/*!
			 */ 
			virtual void setSource (std::string _source)= 0; 
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr< Bag<ecore::EObject> > getContents() const = 0;
			
			/*!
			 */
			virtual std::shared_ptr< Bag<ecore::EStringToStringMapEntry> > getDetails() const = 0;
			
			/*!
			 */
			virtual std::weak_ptr<ecore::EModelElement > getEModelElement() const = 0;
			
			/*!
			 */
			virtual void setEModelElement(std::shared_ptr<ecore::EModelElement> _eModelElement_eModelElement) = 0;
			/*!
			 */
			virtual std::shared_ptr< Bag<ecore::EObject> > getReferences() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			 */ 
			std::string m_source ;
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::shared_ptr< Bag<ecore::EObject> > m_contents;
			/*!
			 */
			std::shared_ptr< Bag<ecore::EStringToStringMapEntry> > m_details;
			/*!
			 */
			std::weak_ptr<ecore::EModelElement > m_eModelElement;
			/*!
			 */
			std::shared_ptr< Bag<ecore::EObject> > m_references;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			 
	};

}
#endif /* end of include guard: ECORE_EANNOTATION_HPP */

