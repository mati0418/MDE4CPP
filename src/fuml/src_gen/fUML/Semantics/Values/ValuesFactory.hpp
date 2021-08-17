//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_VALUESFACTORY_HPP
#define FUML_SEMANTICS_VALUESFACTORY_HPP
// namespace macro header include
#include "fUML/fUML.hpp"

#include <map>
#include <memory>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EFactory.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"

namespace fUML::Semantics::Activities
{
	class ObjectToken;
}
namespace fUML::Semantics::CommonBehavior
{
	class ParameterValue;
}
namespace fUML::Semantics::SimpleClassifiers
{
	class FeatureValue;
}



namespace fUML::Semantics::Values 
{
	class FUML_API ValuesFactory : virtual public ecore::EFactory 
	{
		private:    
			ValuesFactory(ValuesFactory const&) = delete;
			ValuesFactory& operator=(ValuesFactory const&) = delete;
		protected:
			ValuesFactory(){}
		
			//Singleton Instance and Getter
			private:
				static std::shared_ptr<ValuesFactory> instance;
			public:
				static std::shared_ptr<ValuesFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<ecore::EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<ecore::EObject> create(std::shared_ptr<ecore::EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			virtual std::shared_ptr<fUML::Semantics::Values::LiteralBooleanEvaluation> createLiteralBooleanEvaluation(const int metaElementID = ValuesPackage::LITERALBOOLEANEVALUATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Values::LiteralIntegerEvaluation> createLiteralIntegerEvaluation(const int metaElementID = ValuesPackage::LITERALINTEGEREVALUATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Values::LiteralNullEvaluation> createLiteralNullEvaluation(const int metaElementID = ValuesPackage::LITERALNULLEVALUATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Values::LiteralRealEvaluation> createLiteralRealEvaluation(const int metaElementID = ValuesPackage::LITERALREALEVALUATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Values::LiteralStringEvaluation> createLiteralStringEvaluation(const int metaElementID = ValuesPackage::LITERALSTRINGEVALUATION_CLASS) const = 0;
			virtual std::shared_ptr<fUML::Semantics::Values::LiteralUnlimitedNaturalEvaluation> createLiteralUnlimitedNaturalEvaluation(const int metaElementID = ValuesPackage::LITERALUNLIMITEDNATURALEVALUATION_CLASS) const = 0;
			
	};
}
#endif /* end of include guard: FUML_SEMANTICS_VALUESFACTORY_HPP */
