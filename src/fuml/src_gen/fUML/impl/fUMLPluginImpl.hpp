//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUMLPLUGINIMPL_HPP
#define FUMLPLUGINIMPL_HPP

// namespace macro header include
#include "fuml/fuml.hpp"

#include "fUML/fUMLPlugin.hpp"

namespace fUML 
{
	class FUML_API fUMLPluginImpl : virtual public fUMLPlugin 
	{
		public:
			fUMLPluginImpl();
			virtual ~fUMLPluginImpl();
		
			virtual std::string eclipseURI();
			virtual std::string eNAME();
			virtual std::string eNS_URI();
			virtual std::string eNS_PREFIX();
		
			virtual std::shared_ptr<ecore::EObject> create(const std::string& name) const;
			virtual std::shared_ptr<ecore::EObject> create(const std::string& name, std::shared_ptr<ecore::EObject> container, const unsigned int referenceID = -1) const;
			virtual std::shared_ptr<ecore::EFactory> getEFactory();
			virtual std::shared_ptr<ecore::EPackage> getEPackage();
	};
}
#endif /* end of include guard: FUMLPLUGINIMPL_HPP */
