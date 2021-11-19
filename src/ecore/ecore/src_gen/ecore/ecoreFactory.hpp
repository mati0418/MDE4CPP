//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECOREFACTORY_HPP
#define ECOREFACTORY_HPP
// namespace macro header include
#include "ecore/ecore.hpp"

#include <map>
#include <memory>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EFactory.hpp"
#include "ecore/ecorePackage.hpp"

namespace ecore 
{
	class ecorePackage;
}



namespace ecore 
{
	class ECORE_API ecoreFactory : virtual public EFactory 
	{
		private:    
			ecoreFactory(ecoreFactory const&) = delete;
			ecoreFactory& operator=(ecoreFactory const&) = delete;
		protected:
			ecoreFactory(){}
		
			//Singleton Instance and Getter
			private:
				static std::shared_ptr<ecoreFactory> instance;
			public:
				static std::shared_ptr<ecoreFactory> eInstance();
		
			//Creator functions
			virtual std::shared_ptr<EObject> create(std::string _className,  std::shared_ptr<ecore::EObject> container=nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<EObject> create(const int classID,  std::shared_ptr<ecore::EObject> container = nullptr, const int referenceID = -1) const = 0;
			virtual std::shared_ptr<EObject> create(std::shared_ptr<EClass> _class, std::shared_ptr<EObject> _container=nullptr, const int referenceID = -1) const = 0;

			virtual std::shared_ptr<EAnnotation> createEAnnotation(const int metaElementID = ecorePackage::EANNOTATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<EAnnotation> createEAnnotation_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EANNOTATION_CLASS) const = 0;
			virtual std::shared_ptr<EAnnotation> createEAnnotation_as_eAnnotations_in_EModelElement(std::weak_ptr<ecore::EModelElement> par_EModelElement, const int metaElementID = ecorePackage::EANNOTATION_CLASS) const = 0;
			virtual std::shared_ptr<EAnnotation> createEAnnotation_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EANNOTATION_CLASS) const = 0;
			virtual std::shared_ptr<EAttribute> createEAttribute(const int metaElementID = ecorePackage::EATTRIBUTE_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<EAttribute> createEAttribute_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EATTRIBUTE_CLASS) const = 0;
			virtual std::shared_ptr<EAttribute> createEAttribute_as_eAttributes_in_EClass(std::shared_ptr<EClass> par_EClass, const int metaElementID = ecorePackage::EATTRIBUTE_CLASS) const = 0;
			virtual std::shared_ptr<EAttribute> createEAttribute_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EATTRIBUTE_CLASS) const = 0;
			virtual std::shared_ptr<EAttribute> createEAttribute_as_eStructuralFeatures_in_EClass(std::weak_ptr<ecore::EClass> par_EClass, const int metaElementID = ecorePackage::EATTRIBUTE_CLASS) const = 0;
			virtual std::shared_ptr<EClass> createEClass(const int metaElementID = ecorePackage::ECLASS_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<EClass> createEClass_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::ECLASS_CLASS) const = 0;
			virtual std::shared_ptr<EClass> createEClass_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID = ecorePackage::ECLASS_CLASS) const = 0;
			virtual std::shared_ptr<EClass> createEClass_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::ECLASS_CLASS) const = 0;
			virtual std::shared_ptr<EDataType> createEDataType(const int metaElementID = ecorePackage::EDATATYPE_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<EDataType> createEDataType_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EDATATYPE_CLASS) const = 0;
			virtual std::shared_ptr<EDataType> createEDataType_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID = ecorePackage::EDATATYPE_CLASS) const = 0;
			virtual std::shared_ptr<EDataType> createEDataType_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EDATATYPE_CLASS) const = 0;
			virtual std::shared_ptr<EEnum> createEEnum(const int metaElementID = ecorePackage::EENUM_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<EEnum> createEEnum_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EENUM_CLASS) const = 0;
			virtual std::shared_ptr<EEnum> createEEnum_as_eClassifiers_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID = ecorePackage::EENUM_CLASS) const = 0;
			virtual std::shared_ptr<EEnum> createEEnum_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EENUM_CLASS) const = 0;
			virtual std::shared_ptr<EEnumLiteral> createEEnumLiteral(const int metaElementID = ecorePackage::EENUMLITERAL_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<EEnumLiteral> createEEnumLiteral_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EENUMLITERAL_CLASS) const = 0;
			virtual std::shared_ptr<EEnumLiteral> createEEnumLiteral_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EENUMLITERAL_CLASS) const = 0;
			virtual std::shared_ptr<EEnumLiteral> createEEnumLiteral_as_eLiterals_in_EEnum(std::weak_ptr<ecore::EEnum> par_EEnum, const int metaElementID = ecorePackage::EENUMLITERAL_CLASS) const = 0;
			virtual std::shared_ptr<EFactory> createEFactory(const int metaElementID = ecorePackage::EFACTORY_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<EFactory> createEFactory_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EFACTORY_CLASS) const = 0;
			virtual std::shared_ptr<EFactory> createEFactory_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EFACTORY_CLASS) const = 0;
			virtual std::shared_ptr<EGenericType> createEGenericType(const int metaElementID = ecorePackage::EGENERICTYPE_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<EGenericType> createEGenericType_as_eBounds_in_ETypeParameter(std::shared_ptr<ETypeParameter> par_ETypeParameter, const int metaElementID = ecorePackage::EGENERICTYPE_CLASS) const = 0;
			virtual std::shared_ptr<EGenericType> createEGenericType_as_eGenericExceptions_in_EOperation(std::shared_ptr<EOperation> par_EOperation, const int metaElementID = ecorePackage::EGENERICTYPE_CLASS) const = 0;
			virtual std::shared_ptr<EGenericType> createEGenericType_as_eGenericSuperTypes_in_EClass(std::shared_ptr<EClass> par_EClass, const int metaElementID = ecorePackage::EGENERICTYPE_CLASS) const = 0;
			virtual std::shared_ptr<EGenericType> createEGenericType_as_eGenericType_in_ETypedElement(std::shared_ptr<ETypedElement> par_ETypedElement, const int metaElementID = ecorePackage::EGENERICTYPE_CLASS) const = 0;
			virtual std::shared_ptr<EGenericType> createEGenericType_as_eLowerBound_in_EGenericType(std::shared_ptr<EGenericType> par_EGenericType, const int metaElementID = ecorePackage::EGENERICTYPE_CLASS) const = 0;
			virtual std::shared_ptr<EGenericType> createEGenericType_as_eTypeArguments_in_EGenericType(std::shared_ptr<EGenericType> par_EGenericType, const int metaElementID = ecorePackage::EGENERICTYPE_CLASS) const = 0;
			virtual std::shared_ptr<EGenericType> createEGenericType_as_eUpperBound_in_EGenericType(std::shared_ptr<EGenericType> par_EGenericType, const int metaElementID = ecorePackage::EGENERICTYPE_CLASS) const = 0;
			virtual std::shared_ptr<EObject> createEObject(const int metaElementID = ecorePackage::EOBJECT_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<EObject> createEObject_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EOBJECT_CLASS) const = 0;
			virtual std::shared_ptr<EObject> createEObject_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EOBJECT_CLASS) const = 0;
			virtual std::shared_ptr<EOperation> createEOperation(const int metaElementID = ecorePackage::EOPERATION_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<EOperation> createEOperation_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EOPERATION_CLASS) const = 0;
			virtual std::shared_ptr<EOperation> createEOperation_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EOPERATION_CLASS) const = 0;
			virtual std::shared_ptr<EOperation> createEOperation_as_eOperations_in_EClass(std::weak_ptr<ecore::EClass> par_EClass, const int metaElementID = ecorePackage::EOPERATION_CLASS) const = 0;
			virtual std::shared_ptr<EPackage> createEPackage(const int metaElementID = ecorePackage::EPACKAGE_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<EPackage> createEPackage_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EPACKAGE_CLASS) const = 0;
			virtual std::shared_ptr<EPackage> createEPackage_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EPACKAGE_CLASS) const = 0;
			virtual std::shared_ptr<EPackage> createEPackage_as_eSubpackages_in_EPackage(std::weak_ptr<ecore::EPackage> par_EPackage, const int metaElementID = ecorePackage::EPACKAGE_CLASS) const = 0;
			virtual std::shared_ptr<EParameter> createEParameter(const int metaElementID = ecorePackage::EPARAMETER_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<EParameter> createEParameter_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EPARAMETER_CLASS) const = 0;
			virtual std::shared_ptr<EParameter> createEParameter_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EPARAMETER_CLASS) const = 0;
			virtual std::shared_ptr<EParameter> createEParameter_as_eParameters_in_EOperation(std::weak_ptr<ecore::EOperation> par_EOperation, const int metaElementID = ecorePackage::EPARAMETER_CLASS) const = 0;
			virtual std::shared_ptr<EReference> createEReference(const int metaElementID = ecorePackage::EREFERENCE_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<EReference> createEReference_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::EREFERENCE_CLASS) const = 0;
			virtual std::shared_ptr<EReference> createEReference_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::EREFERENCE_CLASS) const = 0;
			virtual std::shared_ptr<EReference> createEReference_as_eReferences_in_EClass(std::shared_ptr<EClass> par_EClass, const int metaElementID = ecorePackage::EREFERENCE_CLASS) const = 0;
			virtual std::shared_ptr<EReference> createEReference_as_eStructuralFeatures_in_EClass(std::weak_ptr<ecore::EClass> par_EClass, const int metaElementID = ecorePackage::EREFERENCE_CLASS) const = 0;
			virtual std::shared_ptr<EStringToStringMapEntry> createEStringToStringMapEntry(const int metaElementID = ecorePackage::ESTRINGTOSTRINGMAPENTRY_CLASS) const = 0;
			virtual std::shared_ptr<ETypeParameter> createETypeParameter(const int metaElementID = ecorePackage::ETYPEPARAMETER_CLASS) const = 0;
			//Add as contained object
			virtual std::shared_ptr<ETypeParameter> createETypeParameter_as_contents_in_EAnnotation(std::shared_ptr<EAnnotation> par_EAnnotation, const int metaElementID = ecorePackage::ETYPEPARAMETER_CLASS) const = 0;
			virtual std::shared_ptr<ETypeParameter> createETypeParameter_as_eContens_in_EObject(std::weak_ptr<ecore::EObject> par_EObject, const int metaElementID = ecorePackage::ETYPEPARAMETER_CLASS) const = 0;
			virtual std::shared_ptr<ETypeParameter> createETypeParameter_as_eTypeParameters_in_EClassifier(std::shared_ptr<EClassifier> par_EClassifier, const int metaElementID = ecorePackage::ETYPEPARAMETER_CLASS) const = 0;
			virtual std::shared_ptr<ETypeParameter> createETypeParameter_as_eTypeParameters_in_EOperation(std::shared_ptr<EOperation> par_EOperation, const int metaElementID = ecorePackage::ETYPEPARAMETER_CLASS) const = 0;
			
	};
}
#endif /* end of include guard: ECOREFACTORY_HPP */
