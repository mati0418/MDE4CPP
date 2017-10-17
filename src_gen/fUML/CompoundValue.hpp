//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_COMPOUNDVALUE_HPP
#define FUML_COMPOUNDVALUE_HPP

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

namespace fUML 
{
	class FeatureValue;
}

namespace uml 
{
	class StructuralFeature;
}

namespace fUML 
{
	class StructuredValue;
}

namespace fUML 
{
	class Value;
}

// base class includes
#include "StructuredValue.hpp"

// enum includes


//*********************************
namespace fUML 
{
	/*!
	 */
	class CompoundValue:virtual public StructuredValue
	{
		public:
 			CompoundValue(const CompoundValue &) {}
			CompoundValue& operator=(CompoundValue const&) = delete;

		protected:
			CompoundValue(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CompoundValue() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void assignFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature,std::shared_ptr<Bag<fUML::Value> >  values,int position)  = 0;
			
			/*!
			 */ 
			virtual bool equals(std::shared_ptr<fUML::Value>  otherValue)  = 0;
			
			/*!
			 */ 
			virtual void removeFeatureValues(std::shared_ptr<uml::Classifier>  classifier)  = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::FeatureValue> retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature>  feature)  = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::FeatureValue> > retrieveFeatureValues()  = 0;
			
			/*!
			 */ 
			virtual std::string toString()  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr< Bag<fUML::FeatureValue> > getFeatureValues() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::shared_ptr< Bag<fUML::FeatureValue> > m_featureValues;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			 
	};

}
#endif /* end of include guard: FUML_COMPOUNDVALUE_HPP */

