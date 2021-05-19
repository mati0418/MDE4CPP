//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUMLFACTORYIMPL_HPP
#define FUMLFACTORYIMPL_HPP

// namespace macro header include
#include "fuml/fuml.hpp"

#include "ecore/impl/EFactoryImpl.hpp"

#include "fUML/fUMLFactory.hpp"

namespace fUML 
{
}

namespace fUML 
{
	class FUML_API fUMLFactoryImpl : virtual public ecore::EFactoryImpl , virtual public fUMLFactory 
	{
		private:    
			fUMLFactoryImpl(fUMLFactoryImpl const&) = delete;
			fUMLFactoryImpl& operator=(fUMLFactoryImpl const&) = delete;

		protected:
			friend class fUMLFactory;
			// Constructor
			fUMLFactoryImpl();

		public:
			virtual ~fUMLFactoryImpl();
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const;

			//Creator functions
			 

		private:
			static fUMLFactory* create();
            std::map<std::string,int> m_idMap;
	};
}
#endif /* end of include guard: FUMLFACTORYIMPL_HPP */
