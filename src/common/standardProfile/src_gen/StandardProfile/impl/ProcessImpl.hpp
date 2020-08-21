//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_PROCESS_PROCESSIMPL_HPP
#define STANDARDPROFILE_PROCESS_PROCESSIMPL_HPP

#include <functional>

//Model includes
#include "../Process.hpp"
#include "uml/impl/StereotypeImpl.hpp"
#include "uml/Property.hpp"

class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

namespace uml
{
	class Property;
}

//*********************************
namespace StandardProfile
{
	class ProcessImpl : virtual public uml::StereotypeImpl, virtual public Process
	{
		public: 
			ProcessImpl(const ProcessImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ProcessImpl& operator=(ProcessImpl const&) = delete;

		protected:
			friend class StandardProfileFactoryImpl;
			//constructor
			ProcessImpl();
			virtual std::shared_ptr<Process> getThisProcessPtr();
			virtual void setThisProcessPtr(std::weak_ptr<Process> thisProcessPtr);


		public:

			//destructor
			virtual ~ProcessImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Component> getBase_Component() const ;
			virtual void setBase_Component(std::weak_ptr<uml::Component> _base_Component);
			
			
			

		protected:
			virtual std::shared_ptr<uml::Class> getMetaClass();
			virtual void instantiate();
			virtual void destroy();

		public:
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			virtual Any get(std::shared_ptr<uml::Property> _property) const ;
			virtual void set(std::shared_ptr<uml::Property> _property, Any value) ;
			virtual void unset(std::shared_ptr<uml::Property> _property) ;
			
		
		private:
			std::weak_ptr<Process> m_thisProcessPtr;
			std::map<std::string,std::function<Any()>> m_getterMap;
			std::map<std::string,std::function<void(Any)>> m_setterMap;
			std::map<std::string,std::function<void()>> m_unsetterMap;
	};
}
#endif /* end of include guard: STANDARDPROFILE_PROCESS_PROCESSIMPL_HPP */
