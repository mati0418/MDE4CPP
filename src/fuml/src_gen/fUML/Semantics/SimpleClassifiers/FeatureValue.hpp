//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_SIMPLECLASSIFIERS_FEATUREVALUE_HPP
#define FUML_SEMANTICS_SIMPLECLASSIFIERS_FEATUREVALUE_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T> class Bag; 



//*********************************
// generated Includes

#include <map>

namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace fUML
{
	class FUMLFactory;
}

//Forward Declaration for used types
namespace fUML::Semantics::SimpleClassifiers 
{
	class FeatureValue;
}

namespace uml 
{
	class StructuralFeature;
}

namespace fUML::Semantics::Values 
{
	class Value;
}

// base class includes

// enum includes

#include "ecore/EObject.hpp"

//*********************************
namespace fUML::Semantics::SimpleClassifiers 
{
	/*!
	 */
	class FeatureValue : virtual public ecore::EObject 

	{
		public:
 			FeatureValue(const FeatureValue &) {}
			FeatureValue& operator=(FeatureValue const&) = delete;

		protected:
			FeatureValue(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~FeatureValue() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual bool hasEqualValues(std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue>  other) = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 */ 
			virtual int getPosition() const = 0;
			
			/*!
			 */ 
			virtual void setPosition (int _position)= 0; 
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<uml::StructuralFeature > getFeature() const = 0;
			
			/*!
			 */
			virtual void setFeature(std::shared_ptr<uml::StructuralFeature> _feature_feature) = 0;
			/*!
			 */
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value>> getValues() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			 */ 
			int m_position = 0;
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::shared_ptr<uml::StructuralFeature > m_feature;
			/*!
			 */
			std::shared_ptr<Bag<fUML::Semantics::Values::Value>> m_values;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: FUML_SEMANTICS_SIMPLECLASSIFIERS_FEATUREVALUE_HPP */
