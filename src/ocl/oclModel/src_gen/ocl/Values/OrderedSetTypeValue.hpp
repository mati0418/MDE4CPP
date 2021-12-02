//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_VALUES_ORDEREDSETTYPEVALUE_HPP
#define OCL_VALUES_ORDEREDSETTYPEVALUE_HPP


#include <memory>
#include <string>
// forward declarations


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

namespace ocl
{
	class oclFactory;
}

//Forward Declaration for used types 
namespace ocl::Types 
{
	class CollectionType;
}
namespace ocl::Values 
{
	class Element;
}

// namespace macro header include
#include "ocl/ocl.hpp"

// base class includes
#include "ocl/Values/CollectionValue.hpp"




//*********************************
namespace ocl::Values 
{
	
	class OCL_API OrderedSetTypeValue: virtual public CollectionValue
	{
		public:
 			OrderedSetTypeValue(const OrderedSetTypeValue &) {}

		protected:
			OrderedSetTypeValue(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~OrderedSetTypeValue() {}

			//*********************************
			// Operations
			//*********************************
			virtual bool addValue(std::shared_ptr<fUML::Semantics::Values::Value> value) = 0;

			//*********************************
			// Attribute Getters & Setters
			//*********************************

			//*********************************
			// Reference Getters & Setters
			//*********************************

			//*********************************
			// Union Reference Getters
			//*********************************

			//*********************************
			// Container Getter
			//*********************************
			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 

			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			//*********************************
			// Reference Members
			//*********************************
	};
}
#endif /* end of include guard: OCL_VALUES_ORDEREDSETTYPEVALUE_HPP */
