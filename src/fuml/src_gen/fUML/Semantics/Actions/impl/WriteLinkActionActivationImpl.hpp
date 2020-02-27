//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_WRITELINKACTIONACTIVATIONWRITELINKACTIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_WRITELINKACTIONACTIVATIONWRITELINKACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../WriteLinkActionActivation.hpp"

#include "fUML/Semantics/Actions/Impl/ActionsFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/LinkActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class WriteLinkActionActivationImpl :virtual public LinkActionActivationImpl, virtual public WriteLinkActionActivation 
	{
		public: 
			WriteLinkActionActivationImpl(const WriteLinkActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			WriteLinkActionActivationImpl& operator=(WriteLinkActionActivationImpl const&) = delete;

		protected:
			friend class fUML::Semantics::Actions::ActionsFactoryImpl;
			WriteLinkActionActivationImpl();
			virtual std::shared_ptr<WriteLinkActionActivation> getThisWriteLinkActionActivationPtr() const;
			virtual void setThisWriteLinkActionActivationPtr(std::weak_ptr<WriteLinkActionActivation> thisWriteLinkActionActivationPtr);

			//Additional constructors for the containments back reference
			WriteLinkActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~WriteLinkActionActivationImpl();
			
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
			/*!
			 */
			virtual std::shared_ptr<Union<fUML::Semantics::Actions::PinActivation>> getPinActivation() const ; 
			 
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
			std::weak_ptr<WriteLinkActionActivation> m_thisWriteLinkActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_WRITELINKACTIONACTIVATIONWRITELINKACTIONACTIVATIONIMPL_HPP */
