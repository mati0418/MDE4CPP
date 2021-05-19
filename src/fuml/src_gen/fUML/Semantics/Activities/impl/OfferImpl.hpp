//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_OFFEROFFERIMPL_HPP
#define FUML_SEMANTICS_ACTIVITIES_OFFEROFFERIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fuml/fuml.hpp" 

// model includes
#include "../Offer.hpp"

#include "fUML/Semantics/Activities/impl/ActivitiesFactoryImpl.hpp"

#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	class FUML_API OfferImpl : virtual public ecore::EModelElementImpl,
virtual public Offer 
	{
		public: 
			OfferImpl(const OfferImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			OfferImpl& operator=(OfferImpl const&); 

		protected:
			friend class fUML::Semantics::Activities::ActivitiesFactoryImpl;
			OfferImpl();
			virtual std::shared_ptr<Offer> getThisOfferPtr() const;
			virtual void setThisOfferPtr(std::weak_ptr<Offer> thisOfferPtr);


		public:
			//destructor
			virtual ~OfferImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual int countOfferedVales() ; 
			virtual bool hasTokens() ; 
			virtual void removeOfferedValues(int count) ; 
			virtual void removeWithdrawnTokens() ; 
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > retrieveOfferedTokens() ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> getOfferedTokens() const ;
			
			
			
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
			std::weak_ptr<Offer> m_thisOfferPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_OFFEROFFERIMPL_HPP */
