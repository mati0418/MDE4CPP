//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_EVALUATIONEVALUATIONIMPL_HPP
#define FUML_EVALUATIONEVALUATIONIMPL_HPP

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
#include "../Evaluation.hpp"

#include "impl/SemanticVisitorImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace fUML 
{
	class EvaluationImpl :virtual public SemanticVisitorImpl, virtual public Evaluation 
	{
		public: 
			EvaluationImpl(const EvaluationImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			EvaluationImpl& operator=(EvaluationImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			EvaluationImpl();



		public:
			//destructor
			virtual ~EvaluationImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Value> evaluate()  ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<fUML::Locus > getLocus() const ;
			
			/*!
			 */
			virtual void setLocus(std::shared_ptr<fUML::Locus> _locus_locus) ;
			/*!
			 */
			virtual std::shared_ptr<uml::ValueSpecification > getSpecification() const ;
			
			/*!
			 */
			virtual void setSpecification(std::shared_ptr<uml::ValueSpecification> _specification_specification) ;
							
			
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
#endif /* end of include guard: FUML_EVALUATIONEVALUATIONIMPL_HPP */

