//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef PSCS_SEMANTICS_COMMONBEHAVIOR_CS_CALLEVENTEXECUTIONCS_CALLEVENTEXECUTIONIMPL_HPP
#define PSCS_SEMANTICS_COMMONBEHAVIOR_CS_CALLEVENTEXECUTIONCS_CALLEVENTEXECUTIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../CS_CallEventExecution.hpp"

#include "PSCS/impl/PSCSFactoryImpl.hpp"
#include "fUML/Semantics/CommonBehavior/impl/CallEventExecutionImpl.hpp"

//*********************************
namespace PSCS::Semantics::CommonBehavior 
{
	class CS_CallEventExecutionImpl :virtual public fUML::Semantics::CommonBehavior::CallEventExecutionImpl, virtual public CS_CallEventExecution 
	{
		public: 
			CS_CallEventExecutionImpl(const CS_CallEventExecutionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			CS_CallEventExecutionImpl& operator=(CS_CallEventExecutionImpl const&) = delete;

		protected:
			friend class PSCS::PSCSFactoryImpl;
			CS_CallEventExecutionImpl();
			virtual std::shared_ptr<CS_CallEventExecution> getThisCS_CallEventExecutionPtr() const;
			virtual void setThisCS_CallEventExecutionPtr(std::weak_ptr<CS_CallEventExecution> thisCS_CallEventExecutionPtr);



		public:
			//destructor
			virtual ~CS_CallEventExecutionImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> createEventOccurrence() ;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> new_() ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint > getInteractionPoint() const ;
			
			/*!
			 */
			virtual void setInteractionPoint(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> _interactionPoint_interactionPoint) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<PSCS::PSCSFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<CS_CallEventExecution> m_thisCS_CallEventExecutionPtr;
	};
}
#endif /* end of include guard: PSCS_SEMANTICS_COMMONBEHAVIOR_CS_CALLEVENTEXECUTIONCS_CALLEVENTEXECUTIONIMPL_HPP */
