//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_DERIVE_DERIVEIMPL_HPP
#define STANDARDPROFILE_DERIVE_DERIVEIMPL_HPP

#include <functional>

//Model includes
#include "../Derive.hpp"
#include "uml/impl/StereotypeImpl.hpp"

class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

namespace uml
{
	class Property;
	class Operation;
}

//*********************************
namespace StandardProfile
{
	class DeriveImpl : virtual public uml::StereotypeImpl, virtual public Derive
	{
		public: 
			DeriveImpl(const DeriveImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			DeriveImpl& operator=(DeriveImpl const&);

		protected:
			friend class StandardProfileFactoryImpl;
			//constructor
			DeriveImpl();
			virtual std::shared_ptr<Derive> getThisDerivePtr();
			virtual void setThisDerivePtr(std::weak_ptr<Derive> thisDerivePtr);


		public:

			//destructor
			virtual ~DeriveImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Abstraction> getBase_Abstraction() const ;
			virtual void setBase_Abstraction(std::weak_ptr<uml::Abstraction> _base_Abstraction);
			
			
			
			//*********************************
			// Union Getter
			//*********************************
			

		protected:
			virtual std::shared_ptr<uml::Class> getMetaClass() const;
			virtual void instantiate();
			virtual void destroy();

		public:
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			//Get
			virtual Any get(std::shared_ptr<uml::Property> _property) const ;
			virtual Any get(std::string _qualifiedName) const ;
			virtual Any get(unsigned long _uID) const ;
			//Set
			virtual void set(std::shared_ptr<uml::Property> _property, Any value) ;
			virtual void set(std::string _qualifiedName, Any value) ;
			virtual void set(unsigned long _uID, Any value) ;
			//Unset
			virtual void unset(std::shared_ptr<uml::Property> _property) ;
			virtual void unset(std::string _qualifiedName) ;
			virtual void unset(unsigned long _uID) ;
			
		
			//*********************************
			// Operation Invocation
			//*********************************
			//Invoke
			virtual Any invoke(std::shared_ptr<uml::Operation> _operation, std::shared_ptr<Bag<Any>> _arguments) ;
			virtual Any invoke(std::string _qualifiedName, std::shared_ptr<Bag<Any>> _arguments) ;
			virtual Any invoke(unsigned long _uID, std::shared_ptr<Bag<Any>> _arguments) ;

		private:
			std::weak_ptr<Derive> m_thisDerivePtr;
			std::map<unsigned long,std::function<Any()>> m_getterMap;
			std::map<unsigned long,std::function<void(Any)>> m_setterMap;
			std::map<unsigned long,std::function<void()>> m_unsetterMap;
			std::map<unsigned long,std::function<Any(std::shared_ptr<Bag<Any>>)>> m_invocationMap;
	};
}
#endif /* end of include guard: STANDARDPROFILE_DERIVE_DERIVEIMPL_HPP */
