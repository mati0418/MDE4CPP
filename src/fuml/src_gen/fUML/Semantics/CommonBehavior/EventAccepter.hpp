//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIOR_EVENTACCEPTER_HPP
#define FUML_SEMANTICS_COMMONBEHAVIOR_EVENTACCEPTER_HPP


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
namespace fUML::Semantics::SimpleClassifiers 
{
	class SignalInstance;
}

// namespace macro header include
#include "fUML/fUML.hpp"

// base class includes

// enum includes

#include "ecore/EModelElement.hpp"


//*********************************
namespace fUML::Semantics::CommonBehavior 
{
	
	class FUML_API EventAccepter : virtual public ecore::EModelElement
	{
		public:
 			EventAccepter(const EventAccepter &) {}

		protected:
			EventAccepter(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EventAccepter() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual void accept(std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> signalInstance) = 0; 
			virtual bool match(std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> signalInstance) = 0;
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
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIOR_EVENTACCEPTER_HPP */
