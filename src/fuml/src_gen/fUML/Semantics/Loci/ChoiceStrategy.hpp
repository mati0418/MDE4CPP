//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_LOCI_CHOICESTRATEGY_HPP
#define FUML_SEMANTICS_LOCI_CHOICESTRATEGY_HPP


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

namespace fUML
{
	class fUMLFactory;
}

//Forward Declaration for used types 

// namespace macro header include
#include "fuml/fuml.hpp"

// base class includes
#include "fUML/Semantics/Loci/SemanticStrategy.hpp"

// enum includes



//*********************************
namespace fUML::Semantics::Loci 
{
	
	class FUML_API ChoiceStrategy: virtual public SemanticStrategy
	{
		public:
 			ChoiceStrategy(const ChoiceStrategy &) {}

		protected:
			ChoiceStrategy(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ChoiceStrategy() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual int choose(int size) = 0; 
			virtual std::string getName() = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: FUML_SEMANTICS_LOCI_CHOICESTRATEGY_HPP */
