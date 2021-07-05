//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_OBJECTOBJECTIMPL_HPP
#define FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_OBJECTOBJECTIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../Object.hpp"

#include "fUML/Semantics/StructuredClassifiers/impl/StructuredClassifiersFactoryImpl.hpp"
#include "fUML/Semantics/StructuredClassifiers/impl/ExtensionalValueImpl.hpp"

//*********************************
namespace fUML::Semantics::StructuredClassifiers 
{
	class FUML_API ObjectImpl : virtual public ExtensionalValueImpl, virtual public Object 
	{
		public: 
			ObjectImpl(const ObjectImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ObjectImpl& operator=(ObjectImpl const&); 

		protected:
			friend class fUML::Semantics::StructuredClassifiers::StructuredClassifiersFactoryImpl;
			ObjectImpl();
			virtual std::shared_ptr<Object> getThisObjectPtr() const;
			virtual void setThisObjectPtr(std::weak_ptr<Object> thisObjectPtr);


		public:
			//destructor
			virtual ~ObjectImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> _copy() ; 
			virtual void _register(std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> accepter) ; 
			virtual void destroy() ; 
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::Execution> dispatch(std::shared_ptr<uml::Operation> operation) ; 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> new_() ; 
			virtual void send(std::shared_ptr<fUML::Semantics::SimpleClassifiers::SignalInstance> signalInstance) ; 
			virtual void send(std::shared_ptr<fUML::Semantics::CommonBehavior::EventOccurrence> eventOccurrence) ; 
			virtual void startBehavior(std::shared_ptr<uml::Class> classifier,std::shared_ptr<Bag<fUML::Semantics::CommonBehavior::ParameterValue>> inputs) ; 
			virtual void unregister(std::shared_ptr<fUML::Semantics::CommonBehavior::EventAccepter> accepter) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation> getObjectActivation() const ;
			
			virtual void setObjectActivation(std::shared_ptr<fUML::Semantics::CommonBehavior::ObjectActivation>) ;
			
			virtual std::shared_ptr<Bag<uml::Classifier>> getTypes() const ;
			
			
			
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
			std::weak_ptr<Object> m_thisObjectPtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_STRUCTUREDCLASSIFIERS_OBJECTOBJECTIMPL_HPP */
