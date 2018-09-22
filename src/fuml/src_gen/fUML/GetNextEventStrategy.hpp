//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_GETNEXTEVENTSTRATEGY_HPP
#define FUML_GETNEXTEVENTSTRATEGY_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations



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
namespace fUML 
{
	class ObjectActivation;
}

namespace fUML 
{
	class SemanticStrategy;
}

namespace fUML 
{
	class SignalInstance;
}

// base class includes
#include "fUML/SemanticStrategy.hpp"

// enum includes


//*********************************
namespace fUML 
{
	/*!
	 */
	class GetNextEventStrategy:virtual public SemanticStrategy
	{
		public:
 			GetNextEventStrategy(const GetNextEventStrategy &) {}
			GetNextEventStrategy& operator=(GetNextEventStrategy const&) = delete;

		protected:
			GetNextEventStrategy(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~GetNextEventStrategy() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::shared_ptr<fUML::SignalInstance> retrieveNextEvent(std::shared_ptr<fUML::ObjectActivation>  objectActivation) = 0;
			
			
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
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: FUML_GETNEXTEVENTSTRATEGY_HPP */