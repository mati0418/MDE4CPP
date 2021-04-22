//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_ESTRINGTOSTRINGMAPENTRYESTRINGTOSTRINGMAPENTRYIMPL_HPP
#define ECORE_ESTRINGTOSTRINGMAPENTRYESTRINGTOSTRINGMAPENTRYIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../EStringToStringMapEntry.hpp"


#include "ecore/impl/EModelElementImpl.hpp"

//*********************************
namespace ecore 
{
	class EStringToStringMapEntryImpl : virtual public ecore::EModelElementImpl,
virtual public EStringToStringMapEntry 
	{
		public: 
			EStringToStringMapEntryImpl(const EStringToStringMapEntryImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			EStringToStringMapEntryImpl& operator=(EStringToStringMapEntryImpl const&); 

		protected:
			friend class ecoreFactoryImpl;
			EStringToStringMapEntryImpl();
			virtual std::shared_ptr<EStringToStringMapEntry> getThisEStringToStringMapEntryPtr() const;
			virtual void setThisEStringToStringMapEntryPtr(std::weak_ptr<EStringToStringMapEntry> thisEStringToStringMapEntryPtr);


		public:
			//destructor
			virtual ~EStringToStringMapEntryImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			 
			virtual std::string getKey() const ;
			 
			virtual void setKey (std::string _key);
			 
			virtual std::string getValue() const ;
			 
			virtual void setValue (std::string _value);
			
			
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
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<EStringToStringMapEntry> m_thisEStringToStringMapEntryPtr;
	};
}
#endif /* end of include guard: ECORE_ESTRINGTOSTRINGMAPENTRYESTRINGTOSTRINGMAPENTRYIMPL_HPP */
