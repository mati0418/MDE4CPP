//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_SERVICE_HPP
#define STANDARDPROFILE_SERVICE_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations



//*********************************
// generated Includes

#include <map>

namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace StandardProfile
{
	class StandardProfileFactory;
}

//Forward Declaration for used types
namespace uml 
{
	class Component;
}

// base class includes

// enum includes

#include "ecore/EObject.hpp"

//*********************************
namespace StandardProfile 
{
	/*!
	 */
	class Service : virtual public ecore::EObject 

	{
		public:
 			Service(const Service &) {}
			Service& operator=(Service const&) = delete;

		protected:
			Service(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Service() {}

			//*********************************
			// Operations
			//*********************************
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<uml::Component > getBase_Component() const = 0;
			
			/*!
			 */
			virtual void setBase_Component(std::shared_ptr<uml::Component> _base_Component_base_Component) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::shared_ptr<uml::Component > m_base_Component;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: STANDARDPROFILE_SERVICE_HPP */
