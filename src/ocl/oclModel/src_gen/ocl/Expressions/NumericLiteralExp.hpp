//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_NUMERICLITERALEXP_HPP
#define OCL_EXPRESSIONS_NUMERICLITERALEXP_HPP


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
namespace ocl::Evaluations 
{
	class OclExpEval;
}
namespace ocl::Expressions 
{
	class CallExp;
	class CollectionRange;
	class ExpressionInOcl;
	class IfExp;
	class LoopExp;
	class NavigationCallExp;
	class OperationCallExp;
	class Variable;
}
namespace ecore 
{
	class EAnnotation;
	class EClassifier;
	class EGenericType;
}

// namespace macro header include
#include "ocl/ocl.hpp"

// base class includes
#include "ocl/Expressions/PrimitiveLiteralExp.hpp"




//*********************************
namespace ocl::Expressions 
{
	
	class OCL_API NumericLiteralExp: virtual public PrimitiveLiteralExp
	{
		public:
 			NumericLiteralExp(const NumericLiteralExp &) {}

		protected:
			NumericLiteralExp(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~NumericLiteralExp() {}

			//*********************************
			// Operations
			//*********************************

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
#endif /* end of include guard: OCL_EXPRESSIONS_NUMERICLITERALEXP_HPP */
