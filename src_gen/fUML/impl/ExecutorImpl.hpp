//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_EXECUTOREXECUTORIMPL_HPP
#define FUML_EXECUTOREXECUTORIMPL_HPP

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
#include "../Executor.hpp"


#include "impl/EObjectImpl.hpp"

#include "SubsetUnion.hpp"

#include "Object.hpp"
#include "FUMLFactory.hpp"


//*********************************
namespace fUML 
{
	class ExecutorImpl :virtual public ecore::EObjectImpl,
virtual public Executor 
	{
		public: 
			ExecutorImpl(const ExecutorImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ExecutorImpl& operator=(ExecutorImpl const&) = delete;

		protected:
			friend class FUMLFactoryImpl;
			ExecutorImpl();



		public:
			//destructor
			virtual ~ExecutorImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Value> evaluate(std::shared_ptr<uml::ValueSpecification>  specification)  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::ParameterValue> > execute(std::shared_ptr<uml::Behavior>  behavior,std::shared_ptr<fUML::Object>  context,std::shared_ptr<Bag<fUML::ParameterValue> >  inputs)  ;
			
			/*!
			 */ 
			virtual std::shared_ptr<fUML::Reference> start(std::shared_ptr<uml::Class>  type,std::shared_ptr<Bag<fUML::ParameterValue> >  inputs)  ;
			
			
			
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
#endif /* end of include guard: FUML_EXECUTOREXECUTORIMPL_HPP */

