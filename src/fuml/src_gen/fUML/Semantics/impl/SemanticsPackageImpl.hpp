//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICSPACKAGEIMPL_HPP
#define FUML_SEMANTICSPACKAGEIMPL_HPP

// namespace macro header include
#include "fuml/fuml.hpp"

#include "ecore/ecorePackage.hpp"
#include "ecore/impl/EPackageImpl.hpp"

#include "fUML/Semantics/SemanticsPackage.hpp" 


namespace fUML::Semantics 
{
	namespace Actions 
	{
		class ActionsPackage;
	}

	namespace Activities 
	{
		class ActivitiesPackage;
	}

	namespace Classification 
	{
		class ClassificationPackage;
	}

	namespace CommonBehavior 
	{
		class CommonBehaviorPackage;
	}

	namespace Loci 
	{
		class LociPackage;
	}

	namespace SimpleClassifiers 
	{
		class SimpleClassifiersPackage;
	}

	namespace StructuredClassifiers 
	{
		class StructuredClassifiersPackage;
	}

	namespace Values 
	{
		class ValuesPackage;
	}
}

namespace ecore
{
	class ecoreFactory;
}

namespace fUML::Semantics
{
	class FUML_API SemanticsPackageImpl : public ecore::EPackageImpl ,virtual public SemanticsPackage
	{
		private:    
			SemanticsPackageImpl(SemanticsPackageImpl const&) = delete;
			SemanticsPackageImpl& operator=(SemanticsPackageImpl const&) = delete;

		protected:
			SemanticsPackageImpl();

		public:
			virtual ~SemanticsPackageImpl();


			
			// SubPackages Getters
			virtual std::shared_ptr<Actions::ActionsPackage> getActions_Package() const ;
			virtual std::shared_ptr<Activities::ActivitiesPackage> getActivities_Package() const ;
			virtual std::shared_ptr<Classification::ClassificationPackage> getClassification_Package() const ;
			virtual std::shared_ptr<CommonBehavior::CommonBehaviorPackage> getCommonBehavior_Package() const ;
			virtual std::shared_ptr<Loci::LociPackage> getLoci_Package() const ;
			virtual std::shared_ptr<SimpleClassifiers::SimpleClassifiersPackage> getSimpleClassifiers_Package() const ;
			virtual std::shared_ptr<StructuredClassifiers::StructuredClassifiersPackage> getStructuredClassifiers_Package() const ;
			virtual std::shared_ptr<Values::ValuesPackage> getValues_Package() const ;
			

		private:
			
			
			
			
			

			friend class SemanticsPackage;

			static bool isInited;
			static SemanticsPackage* create();
			bool isInitialized = false;
 			bool isCreated = false;

			virtual void init(std::shared_ptr<ecore::EPackage> package);

		public:
			void createPackageContents(std::shared_ptr<ecore::EPackage> package);
			void initializePackageContents();

		private:
			void createPackageEDataTypes(std::shared_ptr<ecore::EPackage> package, std::shared_ptr<ecore::ecoreFactory> factory);

			void initializePackageEDataTypes();



	};
}
#endif /* end of include guard: FUML_SEMANTICSPACKAGEIMPL_HPP */
