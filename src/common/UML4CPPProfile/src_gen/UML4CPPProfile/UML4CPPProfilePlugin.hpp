//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef UML4CPPPROFILE_PLUGIN_HPP
#define UML4CPPPROFILE_PLUGIN_HPP

#include "pluginFramework/UMLModelPlugin.hpp"

namespace UML4CPPProfile
{
	class UML4CPPProfilePlugin : virtual public UMLModelPlugin
	{
		public:
			static std::shared_ptr<MDE4CPPPlugin> eInstance();
	
			virtual std::string eclipseURI() = 0;
			virtual std::string eNAME() = 0;
			virtual std::string eNS_URI() = 0;
			virtual std::string eNS_PREFIX() = 0;
	
			virtual std::shared_ptr<ecore::EObject> create(const std::string& name) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const std::string& name, std::shared_ptr<ecore::EObject> container, const unsigned int referenceID = -1) const = 0;
			virtual std::shared_ptr<uml::Factory> getFactory() = 0;
			virtual std::shared_ptr<uml::Package> getPackage() = 0;
	
		protected:
			UML4CPPProfilePlugin(){};
			virtual ~UML4CPPProfilePlugin(){};
	
		private:
			static std::shared_ptr<MDE4CPPPlugin> instance;
	};
}
#endif /* end of include guard: UML4CPPPROFILE_PLUGIN_HPP */