//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIOR_CALLEVENTOCCURRENCE_HPP
#define FUML_SEMANTICS_COMMONBEHAVIOR_CALLEVENTOCCURRENCE_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 


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
namespace fUML::Semantics::CommonBehavior 
{
	class CallEventExecution;
	class ParameterValue;
}
namespace fUML::Semantics::StructuredClassifiers 
{
	class Reference;
}
namespace uml 
{
	class Operation;
	class Trigger;
}

// namespace macro header include
#include "fUML/fUML.hpp"

// base class includes
#include "fUML/Semantics/CommonBehavior/EventOccurrence.hpp"

// enum includes



//*********************************
namespace fUML::Semantics::CommonBehavior 
{
	
	class FUML_API CallEventOccurrence: virtual public EventOccurrence
	{
		public:
 			CallEventOccurrence(const CallEventOccurrence &) {}

		protected:
			CallEventOccurrence(){}

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CallEventOccurrence() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<uml::Operation> getOperation() = 0; 
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > getParameterValues() = 0; 
			virtual bool match(std::shared_ptr<uml::Trigger> trigger) = 0; 
			virtual void releaseCaller() = 0; 
			virtual void setOutputParameterValues(std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> parameterValues) = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecution> getExecution() const = 0;
			
			virtual void setExecution(std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecution>) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			std::shared_ptr<fUML::Semantics::CommonBehavior::CallEventExecution> m_execution;

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
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIOR_CALLEVENTOCCURRENCE_HPP */
