//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_TYPE__HPP
#define STANDARDPROFILE_TYPE__HPP




//Forward Declaration for used types
namespace uml 
{
	class Class;
}

// base class includes
#include "uml/Stereotype.hpp"



namespace StandardProfile
{
	class Type : virtual public uml::Stereotype 
	{
		private:    
			Type(const Type& that) = delete;

		protected:
			Type(){}

		public:
			//destructor
			virtual ~Type() {}

			//*********************************
			// Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Class> getBase_Class() const  = 0;
			virtual void setBase_Class (std::weak_ptr<uml::Class> _base_Class) = 0;
			
			
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
#endif /* end of include guard: STANDARDPROFILE_TYPE__HPP */
