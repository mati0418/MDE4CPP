//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICSFACTORYIMPL_HPP
#define FUML_SEMANTICSFACTORYIMPL_HPP

#include "ecore/impl/EFactoryImpl.hpp"

#include "fUML/Semantics/SemanticsFactory.hpp"

namespace Semantics 
{
}

namespace fUML::Semantics 
{
	class SemanticsFactoryImpl : virtual public ecore::EFactoryImpl , virtual public SemanticsFactory 
	{
		private:    
			SemanticsFactoryImpl(SemanticsFactoryImpl const&) = delete;
			SemanticsFactoryImpl& operator=(SemanticsFactoryImpl const&) = delete;

		protected:
			friend class SemanticsFactory;
			// Constructor
			SemanticsFactoryImpl();

		public:
			virtual ~SemanticsFactoryImpl();
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const;

			//Creator functions
			 

		private:
			static SemanticsFactory* create();
            std::map<std::string,int> m_idMap;
	};
}
#endif /* end of include guard: FUML_SEMANTICSFACTORYIMPL_HPP */
