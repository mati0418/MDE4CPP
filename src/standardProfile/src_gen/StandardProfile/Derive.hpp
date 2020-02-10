//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_DERIVE_HPP
#define STANDARDPROFILE_DERIVE_HPP

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
	class Abstraction;
}

// base class includes

// enum includes

#include "ecore/EObject.hpp"

//*********************************
namespace StandardProfile 
{
	/*!
	 */
	class Derive : virtual public ecore::EObject 

	{
		public:
 			Derive(const Derive &) {}
			Derive& operator=(Derive const&) = delete;

		protected:
			Derive(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~Derive() {}

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
			virtual std::shared_ptr<uml::Abstraction > getBase_Abstraction() const = 0;
			
			/*!
			 */
			virtual void setBase_Abstraction(std::shared_ptr<uml::Abstraction> _base_Abstraction_base_Abstraction) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::shared_ptr<uml::Abstraction > m_base_Abstraction;
			

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
#endif /* end of include guard: STANDARDPROFILE_DERIVE_HPP */
