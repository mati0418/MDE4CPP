//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECORE_EFACTORY_HPP
#define ECORE_EFACTORY_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations


class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

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

namespace ecore
{
	class EcoreFactory;
}

//Forward Declaration for used types
namespace ecore 
{
	class EAnnotation;
}

namespace ecore 
{
	class EClass;
}

namespace ecore 
{
	class EDataType;
}

namespace ecore 
{
	class EModelElement;
}

namespace ecore 
{
	class EObject;
}

namespace ecore 
{
	class EPackage;
}

// base class includes
#include "ecore/EModelElement.hpp"

// enum includes


//*********************************
namespace ecore 
{
	/*!
	 */
	class EFactory:virtual public EModelElement
	{
		public:
 			EFactory(const EFactory &) {}
			EFactory& operator=(EFactory const&) = delete;

		protected:
			EFactory(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~EFactory() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual std::string convertToString(std::shared_ptr<ecore::EDataType>  eDataType,Any instanceValue)  const  = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass>  eClass)  const  = 0;
			
			/*!
			 */ 
			virtual Any createFromString(std::shared_ptr<ecore::EDataType>  eDataType,std::string literalValue)  const  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<ecore::EPackage > getEPackage() const = 0;
			
			/*!
			 */
			virtual void setEPackage(std::shared_ptr<ecore::EPackage> _ePackage_ePackage) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::shared_ptr<ecore::EPackage > m_ePackage;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: ECORE_EFACTORY_HPP */
