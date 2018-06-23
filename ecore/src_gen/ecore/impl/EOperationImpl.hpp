//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EOPERATIONEOPERATIONIMPL_HPP
#define ECORE_EOPERATIONEOPERATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../EOperation.hpp"

#include "ecore/impl/ETypedElementImpl.hpp"

//*********************************
namespace ecore 
{
	class EOperationImpl :virtual public ETypedElementImpl, virtual public EOperation 
	{
		public: 
			EOperationImpl(const EOperationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			EOperationImpl& operator=(EOperationImpl const&) = delete;

		protected:
			friend class EcoreFactoryImpl;
			EOperationImpl();
			virtual std::shared_ptr<EOperation> getThisEOperationPtr();
			virtual void setThisEOperationPtr(std::weak_ptr<EOperation> thisEOperationPtr);

			//Additional constructors for the containments back reference
			EOperationImpl(std::weak_ptr<ecore::EClass > par_eContainingClass);




		public:
			//destructor
			virtual ~EOperationImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			/*!
			 */ 
			virtual bool isOverrideOf(std::shared_ptr<ecore::EOperation>  someOperation)  const  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 */ 
			virtual int getOperationID() const ;
			
			/*!
			 */ 
			virtual void setOperationID (int _operationID); 
			
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::weak_ptr<ecore::EClass > getEContainingClass() const ;
			
			/*!
			 */
			virtual std::shared_ptr<Bag<ecore::EClassifier>> getEExceptions() const ;
			
			/*!
			 */
			virtual std::shared_ptr<Bag<ecore::EGenericType>> getEGenericExceptions() const ;
			
			/*!
			 */
			virtual std::shared_ptr<Bag<ecore::EParameter>> getEParameters() const ;
			
			/*!
			 */
			virtual std::shared_ptr<Bag<ecore::ETypeParameter>> getETypeParameters() const ;
			
							
			
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
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<ecore::EcoreFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<EOperation> m_thisEOperationPtr;
	};
}
#endif /* end of include guard: ECORE_EOPERATIONEOPERATIONIMPL_HPP */
