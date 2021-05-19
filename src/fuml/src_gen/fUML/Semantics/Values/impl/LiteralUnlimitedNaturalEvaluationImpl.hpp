//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_VALUES_LITERALUNLIMITEDNATURALEVALUATIONLITERALUNLIMITEDNATURALEVALUATIONIMPL_HPP
#define FUML_SEMANTICS_VALUES_LITERALUNLIMITEDNATURALEVALUATIONLITERALUNLIMITEDNATURALEVALUATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fuml/fuml.hpp" 

// model includes
#include "../LiteralUnlimitedNaturalEvaluation.hpp"

#include "fUML/Semantics/Values/impl/ValuesFactoryImpl.hpp"
#include "fUML/Semantics/Values/impl/LiteralEvaluationImpl.hpp"

//*********************************
namespace fUML::Semantics::Values 
{
	class FUML_API LiteralUnlimitedNaturalEvaluationImpl : virtual public LiteralEvaluationImpl, virtual public LiteralUnlimitedNaturalEvaluation 
	{
		public: 
			LiteralUnlimitedNaturalEvaluationImpl(const LiteralUnlimitedNaturalEvaluationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			LiteralUnlimitedNaturalEvaluationImpl& operator=(LiteralUnlimitedNaturalEvaluationImpl const&); 

		protected:
			friend class fUML::Semantics::Values::ValuesFactoryImpl;
			LiteralUnlimitedNaturalEvaluationImpl();
			virtual std::shared_ptr<LiteralUnlimitedNaturalEvaluation> getThisLiteralUnlimitedNaturalEvaluationPtr() const;
			virtual void setThisLiteralUnlimitedNaturalEvaluationPtr(std::weak_ptr<LiteralUnlimitedNaturalEvaluation> thisLiteralUnlimitedNaturalEvaluationPtr);


		public:
			//destructor
			virtual ~LiteralUnlimitedNaturalEvaluationImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> evaluate() ;
			
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
			std::weak_ptr<LiteralUnlimitedNaturalEvaluation> m_thisLiteralUnlimitedNaturalEvaluationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_VALUES_LITERALUNLIMITEDNATURALEVALUATIONLITERALUNLIMITEDNATURALEVALUATIONIMPL_HPP */
