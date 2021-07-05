//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_VALUES_VALUEVALUEIMPL_HPP
#define FUML_SEMANTICS_VALUES_VALUEVALUEIMPL_HPP

//*********************************
// generated Includes

// namespace macro header include
#include "fUML/fUML.hpp" 

// model includes
#include "../Value.hpp"

#include "fUML/Semantics/Values/impl/ValuesFactoryImpl.hpp"
#include "fUML/Semantics/Loci/impl/SemanticVisitorImpl.hpp"

//*********************************
namespace fUML::Semantics::Values 
{
	class FUML_API ValueImpl : virtual public fUML::Semantics::Loci::SemanticVisitorImpl, virtual public Value 
	{
		public: 
			ValueImpl(const ValueImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			ValueImpl& operator=(ValueImpl const&); 

		protected:
			friend class fUML::Semantics::Values::ValuesFactoryImpl;
			ValueImpl();
			virtual std::shared_ptr<Value> getThisValuePtr() const;
			virtual void setThisValuePtr(std::weak_ptr<Value> thisValuePtr);


		public:
			//destructor
			virtual ~ValueImpl();
			
			//*********************************
			// Operations
			//*********************************
			 
			virtual std::shared_ptr<fUML::Semantics::Values::Value> _copy() ; 
			virtual bool checkAllParents(std::shared_ptr<uml::Classifier> type,std::shared_ptr<uml::Classifier> classifier) ; 
			virtual bool equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue) ; 
			virtual std::shared_ptr<Bag<uml::Classifier> > getTypes() const ; 
			virtual bool hasTypes(std::shared_ptr<uml::Classifier> type) ; 
			virtual std::string objectId() ; 
			virtual std::shared_ptr<uml::ValueSpecification> specify() ; 
			virtual std::string toString() ;
			
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
			std::weak_ptr<Value> m_thisValuePtr;
	};
}
#endif /* end of include guard: FUML_SEMANTICS_VALUES_VALUEVALUEIMPL_HPP */
