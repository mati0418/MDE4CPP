//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIOR_CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_HPP
#define FUML_SEMANTICS_COMMONBEHAVIOR_CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_HPP

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
namespace uml 
{
	class Class;
}

namespace fUML::Semantics::CommonBehavior 
{
	class EventAccepter;
}

namespace fUML::Semantics::CommonBehavior 
{
	class EventOccurrence;
}

namespace fUML::Semantics::CommonBehavior 
{
	class Execution;
}

namespace fUML::Semantics::CommonBehavior 
{
	class ObjectActivation;
}

namespace fUML::Semantics::CommonBehavior 
{
	class ParameterValue;
}

// base class includes
#include "fUML/Semantics/CommonBehavior/EventAccepter.hpp"

// enum includes


//*********************************
namespace fUML::Semantics::CommonBehavior 
{
	/*!
	 */
	class ClassifierBehaviorInvocationEventAccepter:virtual public EventAccepter
	{
		public:
 			ClassifierBehaviorInvocationEventAccepter(const ClassifierBehaviorInvocationEventAccepter &) {}
			ClassifierBehaviorInvocationEventAccepter& operator=(ClassifierBehaviorInvocationEventAccepter const&) = delete;

		protected:
			ClassifierBehaviorInvocationEventAccepter(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ClassifierBehaviorInvocationEventAccepter() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void accept(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>  eventOccurrence) = 0;
			
			
			
			/*!
			 */ 
			virtual bool match(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>  eventOccurrence) = 0;
			
			/*!
			 */ 
			virtual void terminate() = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<uml::Class > getClassifier() const = 0;
			
			/*!
			 */
			virtual void setClassifier(std::shared_ptr<uml::Class> _classifier_classifier) = 0;
			/*!
			 */
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution > getExecution() const = 0;
			
			/*!
			 */
			virtual void setExecution(std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> _execution_execution) = 0;
			/*!
			 */
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation > getObjectActivation() const = 0;
			
			/*!
			 */
			virtual void setObjectActivation(std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> _objectActivation_objectActivation) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::shared_ptr<uml::Class > m_classifier;
			/*!
			 */
			std::shared_ptr<fUML::Semantics::CommonBehavior::Execution > m_execution;
			/*!
			 */
			std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation > m_objectActivation;
			

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
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIOR_CLASSIFIERBEHAVIORINVOCATIONEVENTACCEPTER_HPP */
