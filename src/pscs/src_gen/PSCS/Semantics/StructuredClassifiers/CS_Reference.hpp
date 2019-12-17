//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_REFERENCE_HPP
#define PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_REFERENCE_HPP

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

namespace PSCS
{
	class PSCSFactory;
}

//Forward Declaration for used types
namespace PSCS::Semantics::StructuredClassifiers 
{
	class CS_InteractionPoint;
}

namespace PSCS::Semantics::StructuredClassifiers 
{
	class CS_Object;
}

namespace fUML::Semantics::CommonBehavior 
{
	class EventOccurrence;
}

namespace fUML::Semantics::CommonBehavior 
{
	class Execution;
}

namespace fUML::Semantics::StructuredClassifiers 
{
	class Object;
}

namespace uml 
{
	class Operation;
}

namespace uml 
{
	class Port;
}

namespace fUML::Semantics::StructuredClassifiers 
{
	class Reference;
}

namespace fUML::Semantics::Values 
{
	class Value;
}

// base class includes
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"

// enum includes


//*********************************
namespace PSCS::Semantics::StructuredClassifiers 
{
	/*!
	 */
	class CS_Reference:virtual public fUML::Semantics::StructuredClassifiers::Reference
	{
		public:
 			CS_Reference(const CS_Reference &) {}
			CS_Reference& operator=(CS_Reference const&) = delete;

		protected:
			CS_Reference(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~CS_Reference() {}

			//*********************************
			// Operations
			//*********************************
			
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> dispatchIn(std::shared_ptr<uml::Operation>  operation,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>  interactionPoint) = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> dispatchIn(std::shared_ptr<uml::Operation>  operation,std::shared_ptr<uml::Port>  onPort) = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> dispatchOut(std::shared_ptr<uml::Operation>  operation,std::shared_ptr<uml::Port>  onPort) = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> dispatchOut(std::shared_ptr<uml::Operation>  operation,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>  interactionPoint) = 0;
			
			/*!
			 */ 
			virtual void sendIn(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>  eventOccurrence,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>  interactionPoint) = 0;
			
			/*!
			 */ 
			virtual void sendIn(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>  eventOccurrence,std::shared_ptr<uml::Port>  onPort) = 0;
			
			/*!
			 */ 
			virtual void sendOut(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>  eventOccurrence,std::shared_ptr<uml::Port>  onPort) = 0;
			
			/*!
			 */ 
			virtual void sendOut(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence>  eventOccurrence,std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint>  interactionPoint) = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object > getCompositeReferent() const = 0;
			
			/*!
			 */
			virtual void setCompositeReferent(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object> _compositeReferent_compositeReferent) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_Object > m_compositeReferent;
			

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
#endif /* end of include guard: PSCS_SEMANTICS_STRUCTUREDCLASSIFIERS_CS_REFERENCE_HPP */
