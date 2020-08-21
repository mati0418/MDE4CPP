//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_IMPLEMENTATIONCLASS__HPP
#define STANDARDPROFILE_IMPLEMENTATIONCLASS__HPP




//Forward Declaration for used types
namespace uml 
{
	class Class;
}

// base class includes
#include "uml/Stereotype.hpp"



namespace StandardProfile
{
	class ImplementationClass : virtual public uml::Stereotype 
	{
		private:    
			ImplementationClass(const ImplementationClass& that) = delete;

		protected:
			ImplementationClass(){}

		public:
			//destructor
			virtual ~ImplementationClass() {}

			//*********************************
			// Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Class> getBase_Class() const  = 0;
			virtual void setBase_Class(std::weak_ptr<uml::Class> _base_Class) = 0;
			
			
			
			//*********************************
			// Operations
			//*********************************
			
			
		protected:
			//*********************************
			// Members
			//*********************************
			std::weak_ptr<uml::Class> m_base_Class;
			
	};
}
#endif /* end of include guard: STANDARDPROFILE_IMPLEMENTATIONCLASS__HPP */
