//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_CONDITIONALNODEACTIVATIONCONDITIONALNODEACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_CONDITIONALNODEACTIVATIONCONDITIONALNODEACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fuml/fuml.hpp" 

// model includes
#include "../ConditionalNodeActivation.hpp"

#include "fUML/Semantics/Actions/impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/StructuredActivityNodeActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class FUML_API ConditionalNodeActivationImpl : virtual public StructuredActivityNodeActivationImpl, virtual public ConditionalNodeActivation 
	{
		public: 
			ConditionalNodeActivationImpl(const ConditionalNodeActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ConditionalNodeActivationImpl& operator=(ConditionalNodeActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			ConditionalNodeActivationImpl();
			virtual std::shared_ptr<ConditionalNodeActivation> getThisConditionalNodeActivationPtr() const;
			virtual void setThisConditionalNodeActivationPtr(std::weak_ptr<ConditionalNodeActivation> thisConditionalNodeActivationPtr);

			//Additional constructors for the containments back reference
			ConditionalNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~ConditionalNodeActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<fUML::Semantics::Actions::ClauseActivation> getClauseActivation(std::shared_ptr<uml::Clause> clause) ; 
			virtual void runTest(std::shared_ptr<uml::Clause> clause) ; 
			virtual void selectBody(std::shared_ptr<uml::Clause> clause) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<Bag<fUML::Semantics::Actions::ClauseActivation>> getClauseActivations() const ;
			
			
			virtual std::shared_ptr<Bag<uml::Clause>> getSelectedClauses() const ;
			
			
			
			//*********************************
			// Union Getter
			//*********************************
			
			virtual std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> getPinActivation() const ; 
			 
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
			std::weak_ptr<ConditionalNodeActivation> m_thisConditionalNodeActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_CONDITIONALNODEACTIVATIONCONDITIONALNODEACTIVATIONIMPL_HPP */
