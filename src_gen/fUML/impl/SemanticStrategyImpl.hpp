//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICSTRATEGYSEMANTICSTRATEGYIMPL_HPP
#define FUML_SEMANTICSTRATEGYSEMANTICSTRATEGYIMPL_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//*********************************
// generated Includes

//Model includes
#include "../SemanticStrategy.hpp"


#include "impl/EObjectImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace fUML 
{
	class SemanticStrategyImpl :virtual public ecore::EObjectImpl,
virtual public SemanticStrategy 
	{
		public: 
			SemanticStrategyImpl(const SemanticStrategyImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			SemanticStrategyImpl& operator=(SemanticStrategyImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			SemanticStrategyImpl();



		public:
			//destructor
			virtual ~SemanticStrategyImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::string retrieveName()  ;
			
			
			
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
			
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
	};
}
#endif /* end of include guard: FUML_SEMANTICSTRATEGYSEMANTICSTRATEGYIMPL_HPP */

