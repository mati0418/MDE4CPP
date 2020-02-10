//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_CALLCALLIMPL_HPP
#define STANDARDPROFILE_CALLCALLIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../Call.hpp"


#include "ecore/impl/EObjectImpl.hpp"

//*********************************
namespace StandardProfile 
{
	class CallImpl :virtual public ecore::EObjectImpl,
virtual public Call 
	{
		public: 
			CallImpl(const CallImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			CallImpl& operator=(CallImpl const&) = delete;

		protected:
			friend class StandardProfileFactoryImpl;
			CallImpl();
			virtual std::shared_ptr<Call> getThisCallPtr() const;
			virtual void setThisCallPtr(std::weak_ptr<Call> thisCallPtr);



		public:
			//destructor
			virtual ~CallImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<uml::Usage > getBase_Usage() const ;
			
			/*!
			 */
			virtual void setBase_Usage(std::shared_ptr<uml::Usage> _base_Usage_base_Usage) ;
							
			
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
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<StandardProfile::StandardProfileFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<Call> m_thisCallPtr;
	};
}
#endif /* end of include guard: STANDARDPROFILE_CALLCALLIMPL_HPP */
