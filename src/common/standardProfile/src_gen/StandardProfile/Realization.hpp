//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_REALIZATION__HPP
#define STANDARDPROFILE_REALIZATION__HPP




//Forward Declaration for used types
namespace uml 
{
	class Classifier;
}

// base class includes
#include "uml/Stereotype.hpp"



namespace StandardProfile
{
	class Realization : virtual public uml::Stereotype 
	{
		private:    
			Realization(const Realization& that) = delete;

		protected:
			Realization(){}

		public:
			//destructor
			virtual ~Realization() {}

			//*********************************
			// Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Classifier> getBase_Classifier() const  = 0;
			virtual void setBase_Classifier(std::weak_ptr<uml::Classifier> _base_Classifier) = 0;
			
			
			
			//*********************************
			// Operations
			//*********************************
			
			
		protected:
			//*********************************
			// Members
			//*********************************
			std::weak_ptr<uml::Classifier> m_base_Classifier;
			
	};
}
#endif /* end of include guard: STANDARDPROFILE_REALIZATION__HPP */
