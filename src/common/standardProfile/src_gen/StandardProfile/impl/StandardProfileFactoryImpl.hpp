//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef STANDARDPROFILE_FACTORYIMPL_HPP
#define STANDARDPROFILE_FACTORYIMPL_HPP

#include <functional>
#include <map>

#include "uml/impl/FactoryImpl.hpp"
#include "StandardProfile/StandardProfileFactory.hpp"

namespace StandardProfile 
{
	class StandardProfileFactoryImpl : virtual public uml::FactoryImpl , virtual public StandardProfileFactory 
	{
		protected:
			friend class StandardProfileFactory;
			// Constructor
			StandardProfileFactoryImpl();

		public:
			virtual ~StandardProfileFactoryImpl();
			virtual std::shared_ptr<uml::Element> create(const unsigned int _metaClassId,  std::shared_ptr<uml::Element> container= nullptr, const unsigned int referenceID = -1) const;
			virtual std::shared_ptr<uml::Element> create(const std::shared_ptr<uml::Class> _class,  std::shared_ptr<uml::Element> container= nullptr, const unsigned int referenceID = -1) const;
			virtual std::shared_ptr<uml::Element> create(const std::string _className,  std::shared_ptr<uml::Element> container= nullptr, const unsigned int referenceID = -1) const;

			//Creator functions
			virtual std::shared_ptr<StandardProfile::Auxiliary> createAuxiliary(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::BuildComponent> createBuildComponent(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Call> createCall(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Create> createCreate(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Derive> createDerive(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Destroy> createDestroy(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Document> createDocument(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Entity> createEntity(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Executable> createExecutable(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::File> createFile(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Focus> createFocus(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Framework> createFramework(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Implement> createImplement(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::ImplementationClass> createImplementationClass(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Instantiate> createInstantiate(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Library> createLibrary(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Metaclass> createMetaclass(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Metamodel> createMetamodel(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::ModelLibrary> createModelLibrary(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Process> createProcess(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Realization> createRealization(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Refine> createRefine(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Responsibility> createResponsibility(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Script> createScript(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Send> createSend(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Service> createService(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Source> createSource(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Specification> createSpecification(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Subsystem> createSubsystem(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::SystemModel> createSystemModel(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Trace> createTrace(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Type> createType(const int metaElementID=-1) const ;
			
			virtual std::shared_ptr<StandardProfile::Utility> createUtility(const int metaElementID=-1) const ;
			
			
			


			//Package
			virtual std::shared_ptr<StandardProfilePackage> getStandardProfilePackage();

		private:
			static StandardProfileFactory * create();
			std::map<std::string,unsigned int> m_idMap;
			virtual void init() {}
	};
}
#endif /* end of include guard: STANDARDPROFILE_FACTORYIMPL_HPP */
