//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_TOKENSETTOKENSETIMPL_HPP
#define FUML_SEMANTICS_ACTIVITIES_TOKENSETTOKENSETIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../TokenSet.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"

#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	class TokenSetImpl : virtual public ecore::EModelElementImpl,
virtual public TokenSet 
	{
		public: 
			TokenSetImpl(const TokenSetImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			TokenSetImpl& operator=(TokenSetImpl const&); 

		protected:
			friend class fUML::Semantics::Activities::ActivitiesFactoryImpl;
			TokenSetImpl();
			virtual std::shared_ptr<TokenSet> getThisTokenSetPtr() const;
			virtual void setThisTokenSetPtr(std::weak_ptr<TokenSet> thisTokenSetPtr);


		public:
			//destructor
			virtual ~TokenSetImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> getTokens() const ;
			
			
			
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
			std::weak_ptr<TokenSet> m_thisTokenSetPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_TOKENSETTOKENSETIMPL_HPP */
