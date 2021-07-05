//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_COMMONBEHAVIOR_EXECUTIONEXECUTIONIMPL_HPP
#define FUML_SEMANTICS_COMMONBEHAVIOR_EXECUTIONEXECUTIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../Execution.hpp"

#include "fUML/Semantics/CommonBehavior/impl/CommonBehaviorFactoryImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/ObjectImpl.hpp"

//*********************************
namespace fUML::Semantics::CommonBehavior 
{
	class FUML_API ExecutionImpl : virtual public fUML::Semantics::StructuredClassifiers::ObjectImpl, virtual public Execution 
	{
		public: 
			ExecutionImpl(const ExecutionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ExecutionImpl& operator=(ExecutionImpl const&); 

		protected:
			friend class fUML::Semantics::CommonBehavior::CommonBehaviorFactoryImpl;
			ExecutionImpl();
			virtual std::shared_ptr<Execution> getThisExecutionPtr() const;
			virtual void setThisExecutionPtr(std::weak_ptr<Execution> thisExecutionPtr);


		public:
			//destructor
			virtual ~ExecutionImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> _copy() ; 
			virtual void execute() ; 
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue> > getOutputParameterValues() ; 
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> getParameterValue(std::shared_ptr<uml::Parameter> parameter) ; 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> new_() ; 
			virtual void setParameterValue(std::shared_ptr<fUML::Semantics::CommonBehavior::ParameterValue> parameterValue) ; 
			virtual void terminate() ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<uml::Behavior> getBehavior() const ;
			
			virtual void setBehavior(std::shared_ptr<uml::Behavior>) ;
			
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> getContext() const ;
			
			virtual void setContext(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object>) ;
			
			virtual std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> getParameterValues() const ;
			
			
			
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
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<Execution> m_thisExecutionPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_COMMONBEHAVIOR_EXECUTIONEXECUTIONIMPL_HPP */
