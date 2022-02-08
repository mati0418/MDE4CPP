//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef UML4CPPPROFILE_DONOTGENERATE_DONOTGENERATEIMPL_HPP
#define UML4CPPPROFILE_DONOTGENERATE_DONOTGENERATEIMPL_HPP

#include <functional>

//Model includes
#include "../DoNotGenerate.hpp"
#include "uml/impl/StereotypeImpl.hpp"

class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

namespace uml
{
	class Property;
	class Operation;
}

//*********************************
namespace UML4CPPProfile
{
	class DoNotGenerateImpl : virtual public uml::StereotypeImpl, virtual public DoNotGenerate
	{
		public: 
			DoNotGenerateImpl(const DoNotGenerateImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;  
			DoNotGenerateImpl& operator=(DoNotGenerateImpl const&);

		protected:
			friend class UML4CPPProfileFactoryImpl;
			//constructor
			DoNotGenerateImpl();
			virtual std::shared_ptr<DoNotGenerate> getThisDoNotGeneratePtr();
			virtual void setThisDoNotGeneratePtr(std::weak_ptr<DoNotGenerate> thisDoNotGeneratePtr);


		public:

			//destructor
			virtual ~DoNotGenerateImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::shared_ptr<uml::Element> getBase_Element() const ;
			virtual void setBase_Element(std::shared_ptr<uml::Element> _base_Element);
			
			
			
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
			std::weak_ptr<DoNotGenerate> m_thisDoNotGeneratePtr;
			std::map<unsigned long,std::function<Any()>> m_getterMap;
			std::map<unsigned long,std::function<void(Any)>> m_setterMap;
			std::map<unsigned long,std::function<void()>> m_unsetterMap;
			std::map<unsigned long,std::function<Any(std::shared_ptr<Bag<Any>>)>> m_invocationMap;
	};
}
#endif /* end of include guard: UML4CPPPROFILE_DONOTGENERATE_DONOTGENERATEIMPL_HPP */
