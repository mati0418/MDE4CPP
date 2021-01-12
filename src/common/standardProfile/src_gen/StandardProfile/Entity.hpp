//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_ENTITY__HPP
#define STANDARDPROFILE_ENTITY__HPP




//Forward Declaration for used types
namespace uml 
{
	class Component;
}

// base class includes
#include "uml/Stereotype.hpp"



namespace StandardProfile
{
	class Entity : virtual public uml::Stereotype 
	{
		private:    
			Entity(const Entity& that) = delete;

		protected:
			Entity(){}

		public:
			//destructor
			virtual ~Entity() {}

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
#endif /* end of include guard: STANDARDPROFILE_ENTITY__HPP */
