//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_SOURCESOURCEIMPL_HPP
#define STANDARDPROFILE_SOURCESOURCEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../Source.hpp"

#include "StandardProfile/impl/FileImpl.hpp"

//*********************************
namespace StandardProfile 
{
	class SourceImpl :virtual public FileImpl, virtual public Source 
	{
		public: 
			SourceImpl(const SourceImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			SourceImpl& operator=(SourceImpl const&) = delete;

		protected:
			friend class StandardProfileFactoryImpl;
			SourceImpl();
			virtual std::shared_ptr<Source> getThisSourcePtr() const;
			virtual void setThisSourcePtr(std::weak_ptr<Source> thisSourcePtr);



		public:
			//destructor
			virtual ~SourceImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
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
			std::weak_ptr<Source> m_thisSourcePtr;
	};
}
#endif /* end of include guard: STANDARDPROFILE_SOURCESOURCEIMPL_HPP */
