//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_REDEFINITIONBASEDDISPATCHSTRATEGYREDEFINITIONBASEDDISPATCHSTRATEGYIMPL_HPP
#define FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_REDEFINITIONBASEDDISPATCHSTRATEGYREDEFINITIONBASEDDISPATCHSTRATEGYIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fuml/fuml.hpp" 

// model includes
#include "../RedefinitionBasedDispatchStrategy.hpp"

#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/DispatchStrategyImpl.hpp"

//*********************************
namespace fUML::Semantics::StructuredClassifiers 
{
	class FUML_API RedefinitionBasedDispatchStrategyImpl : virtual public DispatchStrategyImpl, virtual public RedefinitionBasedDispatchStrategy 
	{
		public: 
			RedefinitionBasedDispatchStrategyImpl(const RedefinitionBasedDispatchStrategyImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			RedefinitionBasedDispatchStrategyImpl& operator=(RedefinitionBasedDispatchStrategyImpl const&); 

		protected:
			friend class fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactoryImpl;
			RedefinitionBasedDispatchStrategyImpl();
			virtual std::shared_ptr<RedefinitionBasedDispatchStrategy> getThisRedefinitionBasedDispatchStrategyPtr() const;
			virtual void setThisRedefinitionBasedDispatchStrategyPtr(std::weak_ptr<RedefinitionBasedDispatchStrategy> thisRedefinitionBasedDispatchStrategyPtr);


		public:
			//destructor
			virtual ~RedefinitionBasedDispatchStrategyImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual bool operationsMatch(std::shared_ptr<uml::Operation> ownedOperation,std::shared_ptr<uml::Operation> baseOperation) ; 
			virtual std::shared_ptr<uml::Behavior> retrieveMethod(std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> object,std::shared_ptr<uml::Operation> operation) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			
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

		private:
			std::weak_ptr<RedefinitionBasedDispatchStrategy> m_thisRedefinitionBasedDispatchStrategyPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_REDEFINITIONBASEDDISPATCHSTRATEGYREDEFINITIONBASEDDISPATCHSTRATEGYIMPL_HPP */
