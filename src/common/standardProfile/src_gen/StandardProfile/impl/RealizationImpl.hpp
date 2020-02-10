//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_REALIZATION_REALIZATIONIMPL_HPP
#define STANDARDPROFILE_REALIZATION_REALIZATIONIMPL_HPP

#include <functional>

//Model includes
#include "../Realization.hpp"
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
	class RealizationImpl : virtual public uml::StereotypeImpl, virtual public Realization
	{
		private:    
			RealizationImpl(RealizationImpl const&) = delete;
			RealizationImpl& operator=(RealizationImpl const&) = delete;

		protected:
			friend class StandardProfileFactoryImpl;
			//constructor
			RealizationImpl();
			virtual std::shared_ptr<Realization> getThisRealizationPtr();
			virtual void setThisRealizationPtr(std::weak_ptr<Realization> thisRealizationPtr);


		public:
			//destructor
			virtual ~RealizationImpl();

			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			virtual std::weak_ptr<uml::Classifier> getBase_Classifier() const ;
			virtual void setBase_Classifier (std::weak_ptr<uml::Classifier> _base_Classifier);
			

		protected:
			virtual std::shared_ptr<uml::Class> getMetaClass();

		public:
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			virtual Any get(std::shared_ptr<uml::Property> _property) const ;
			virtual void set(std::shared_ptr<uml::Property> _property, Any value) ;
			virtual void unset(std::shared_ptr<uml::Property> _property) ;
			
		
		private:
			std::weak_ptr<Realization> m_thisRealizationPtr;
			std::map<std::string,std::function<Any()>> m_getterMap;
			std::map<std::string,std::function<void(Any)>> m_setterMap;
			std::map<std::string,std::function<void()>> m_unsetterMap;
	};
}
#endif /* end of include guard: STANDARDPROFILE_REALIZATION_REALIZATIONIMPL_HPP */
