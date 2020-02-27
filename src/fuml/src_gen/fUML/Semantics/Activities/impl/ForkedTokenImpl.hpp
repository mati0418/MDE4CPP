//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_FORKEDTOKENFORKEDTOKENIMPL_HPP
#define FUML_SEMANTICS_ACTIVITIES_FORKEDTOKENFORKEDTOKENIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ForkedToken.hpp"

#include "fUML/Semantics/Activities/Impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/Activities/impl/TokenImpl.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	class ForkedTokenImpl :virtual public TokenImpl, virtual public ForkedToken 
	{
		public: 
			ForkedTokenImpl(const ForkedTokenImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ForkedTokenImpl& operator=(ForkedTokenImpl const&) = delete;

		protected:
			friend class fUML::Semantics::Activities::ActivitiesFactoryImpl;
			ForkedTokenImpl();
			virtual std::shared_ptr<ForkedToken> getThisForkedTokenPtr() const;
			virtual void setThisForkedTokenPtr(std::weak_ptr<ForkedToken> thisForkedTokenPtr);



		public:
			//destructor
			virtual ~ForkedTokenImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual bool equals(std::shared_ptr<fUML::Semantics::Activities::Token>  otherToken) ;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> getValue() const ;
			
			/*!
			 */ 
			virtual bool isControl() ;
			
			/*!
			 */ 
			virtual void withdraw() ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 */ 
			virtual bool isBaseTokenIsWithdrawn() const ;
			
			/*!
			 */ 
			virtual void setBaseTokenIsWithdrawn (bool _baseTokenIsWithdrawn); 
			
			/*!
			 */ 
			virtual int getRemainingOffersCount() const ;
			
			/*!
			 */ 
			virtual void setRemainingOffersCount (int _remainingOffersCount); 
			
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<fUML::Semantics::Activities::Token > getBaseToken() const ;
			
			/*!
			 */
			virtual void setBaseToken(std::shared_ptr<fUML::Semantics::Activities::Token> _baseToken_baseToken) ;
							
			
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
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<ForkedToken> m_thisForkedTokenPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_FORKEDTOKENFORKEDTOKENIMPL_HPP */
