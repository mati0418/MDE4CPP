//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUMLPLUGIN_HPP
#define FUMLPLUGIN_HPP

// namespace macro header include
#include "fUML/fUML.hpp"

#include "pluginFramework/EcoreModelPlugin.hpp"

namespace fUML
{
	class FUML_API fUMLPlugin : virtual public EcoreModelPlugin
	{
		public:
			static std::shared_ptr<MDE4CPPPlugin> eInstance();
	
			virtual std::string eclipseURI() = 0;
			virtual std::string eNAME() = 0;
			virtual std::string eNS_URI() = 0;
			virtual std::string eNS_PREFIX() = 0;
			
			virtual std::shared_ptr<ecore::EObject> create(const std::string& name) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const std::string& name, std::shared_ptr<ecore::EObject> container, const unsigned int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EFactory> getEFactory() = 0;
			virtual std::shared_ptr<ecore::EPackage> getEPackage() = 0;
	
		protected:
			fUMLPlugin(){};
			virtual ~fUMLPlugin(){};
	
		private:
			static std::shared_ptr<MDE4CPPPlugin> instance;
	};
}
#endif /* end of include guard: FUMLPLUGIN_HPP */
