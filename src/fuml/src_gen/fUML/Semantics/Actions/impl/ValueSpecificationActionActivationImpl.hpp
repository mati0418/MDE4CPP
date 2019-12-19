//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIONS_VALUESPECIFICATIONACTIONACTIVATIONVALUESPECIFICATIONACTIONACTIVATIONIMPL_HPP
#define FUML_SEMANTICS_ACTIONS_VALUESPECIFICATIONACTIONACTIVATIONVALUESPECIFICATIONACTIONACTIVATIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ValueSpecificationActionActivation.hpp"

#include "fUML/impl/FUMLFactoryImpl.hpp"
#include "fUML/Semantics/Actions/impl/ActionActivationImpl.hpp"

//*********************************
namespace fUML::Semantics::Actions 
{
	class ValueSpecificationActionActivationImpl :virtual public ActionActivationImpl, virtual public ValueSpecificationActionActivation 
	{
		public: 
			ValueSpecificationActionActivationImpl(const ValueSpecificationActionActivationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ValueSpecificationActionActivationImpl& operator=(ValueSpecificationActionActivationImpl const&) = delete;

		protected:
			friend class fUML::FUMLFactoryImpl;
			ValueSpecificationActionActivationImpl();
			virtual std::shared_ptr<ValueSpecificationActionActivation> getThisValueSpecificationActionActivationPtr() const;
			virtual void setThisValueSpecificationActionActivationPtr(std::weak_ptr<ValueSpecificationActionActivation> thisValueSpecificationActionActivationPtr);

			//Additional constructors for the containments back reference
			ValueSpecificationActionActivationImpl(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group);




		public:
			//destructor
			virtual ~ValueSpecificationActionActivationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void doAction() ;
			
			
			
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
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<fUML::FUMLFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<ValueSpecificationActionActivation> m_thisValueSpecificationActionActivationPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_ACTIONS_VALUESPECIFICATIONACTIONACTIVATIONVALUESPECIFICATIONACTIONACTIVATIONIMPL_HPP */