//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_EXPRESSIONS_COLLECTIONITEMCOLLECTIONITEMIMPL_HPP
#define OCL_EXPRESSIONS_COLLECTIONITEMCOLLECTIONITEMIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "ocl/ocl.hpp" 

// model includes
#include "../CollectionItem.hpp"

#include "ocl/Expressions/impl/ExpressionsFactoryImpl.hpp"
#include "ocl/Expressions/impl/CollectionLiteralPartImpl.hpp"

//*********************************
namespace ocl::Expressions 
{
	class OCL_API CollectionItemImpl : virtual public CollectionLiteralPartImpl, virtual public CollectionItem 
	{
		public: 
			CollectionItemImpl(const CollectionItemImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			CollectionItemImpl& operator=(CollectionItemImpl const&); 

		protected:
			friend class ocl::Expressions::ExpressionsFactoryImpl;
			CollectionItemImpl();
			virtual std::shared_ptr<CollectionItem> getThisCollectionItemPtr() const;
			virtual void setThisCollectionItemPtr(std::weak_ptr<CollectionItem> thisCollectionItemPtr);


		public:
			//destructor
			virtual ~CollectionItemImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<ocl::Expressions::OclExpression> getItem() const ;
			
			virtual void setItem(std::shared_ptr<ocl::Expressions::OclExpression>) ;
			
			
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
			std::weak_ptr<CollectionItem> m_thisCollectionItemPtr;
	};
}
#endif /* end of include guard: OCL_EXPRESSIONS_COLLECTIONITEMCOLLECTIONITEMIMPL_HPP */