//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICSFACTORY_HPP
#define FUML_SEMANTICSFACTORY_HPP

#include <map>
#include <memory>

// namespace macro header include
#include "fuml/fuml.hpp"

#include "ecore/EFactory.hpp"
#include "fUML/Semantics/SemanticsPackage.hpp"

namespace fUML::Semantics::Activities 
{
	class ActivityNodeActivationGroup;
}


namespace fUML::Semantics::Actions 
{
	class StructuredActivityNodeActivation;
}
namespace fUML::Semantics::Activities 
{
	class ActivityExecution;
	class ActivityNodeActivationGroup;
}






namespace fUML::Semantics::Loci 
{
	class Locus;
}











namespace fUML::Semantics 
{
	class FUML_API SemanticsFactory : virtual public ecore::EFactory 
	{
		private:    
			SemanticsFactory(SemanticsFactory const&) = delete;
			SemanticsFactory& operator=(SemanticsFactory const&) = delete;
		protected:
			SemanticsFactory(){}
		
			//Singleton Instance and Getter
			private:
				static std::shared_ptr<SemanticsFactory> instance;
			public:
				static std::shared_ptr<SemanticsFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			
	};
}
#endif /* end of include guard: FUML_SEMANTICSFACTORY_HPP */
