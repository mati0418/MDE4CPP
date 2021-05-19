//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_OBJECTNODEACTIVATIONOBJECTNODEACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIVITIES_OBJECTNODEACTIVATIONOBJECTNODEACTIVATIONIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fuml/fuml.hpp" 

// model includes
#include "../ObjectNodeActivation.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"
#include "fUML/Semantics/Activities/impl/ActivityNodeActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	class FUML_API ObjectNodeActivationImpl : virtual public ActivityNodeActivationImpl, virtual public ObjectNodeActivation 
	{
		public: 
			ObjectNodeActivationImpl(const ObjectNodeActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ObjectNodeActivationImpl& operator=(ObjectNodeActivationImpl const&); 

		protected:
			friend class fUML::Semantics::Activities::ActivitiesFactoryImpl;
			ObjectNodeActivationImpl();
			virtual std::shared_ptr<ObjectNodeActivation> getThisObjectNodeActivationPtr() const;
			virtual void setThisObjectNodeActivationPtr(std::weak_ptr<ObjectNodeActivation> thisObjectNodeActivationPtr);

			//Additional constructors for the containments back reference
			ObjectNodeActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			//destructor
			virtual ~ObjectNodeActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual void addToken(std::shared_ptr<fUML::Semantics::Activities::Token> token) ; 
			virtual void clearTokens() ; 
			virtual int countOfferedValues() ; 
			virtual int countUnofferedTokens() ; 
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > getUnofferedTokens() ; 
			virtual int removeToken(std::shared_ptr<fUML::Semantics::Activities::Token> token) ; 
			virtual void run() ; 
			virtual void sendOffers(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> tokens) ; 
			virtual void sendUnofferedTokens() ; 
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > takeUnofferedTokens() ; 
			virtual void terminate() ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			 
			virtual int getOfferedTokenCount() const ;
			 
			virtual void setOfferedTokenCount (int _offeredTokenCount);
			
			
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
			std::weak_ptr<ObjectNodeActivation> m_thisObjectNodeActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_OBJECTNODEACTIVATIONOBJECTNODEACTIVATIONIMPL_HPP */
