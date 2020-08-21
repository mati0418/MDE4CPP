//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_IMPLEMENT__HPP
#define STANDARDPROFILE_IMPLEMENT__HPP




//Forward Declaration for used types
namespace uml 
{
	class Component;
}

// base class includes
#include "uml/Stereotype.hpp"



namespace StandardProfile
{
	class Implement : virtual public uml::Stereotype 
	{
		private:    
			Implement(const Implement& that) = delete;

		protected:
			Implement(){}

		public:
			//destructor
			virtual ~Implement() {}

			//*********************************
			// Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Component> getBase_Component() const  = 0;
			virtual void setBase_Component(std::weak_ptr<uml::Component> _base_Component) = 0;
			
			
			
			//*********************************
			// Operations
			//*********************************
			
			
		protected:
			//*********************************
			// Members
			//*********************************
			std::weak_ptr<uml::Component> m_base_Component;
			
	};
}
#endif /* end of include guard: STANDARDPROFILE_IMPLEMENT__HPP */
