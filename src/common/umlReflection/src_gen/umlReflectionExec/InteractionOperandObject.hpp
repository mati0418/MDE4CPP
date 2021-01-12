//********************************************************************
//*    	
//* Warning: This file was generated by MDE4CPP Generator
//*
//********************************************************************

#ifndef UML_INTERACTIONOPERAND_EXECUTION_HPP
#define UML_INTERACTIONOPERAND_EXECUTION_HPP

#include "PSCS/Semantics/StructuredClassifiers/impl/CS_ObjectImpl.hpp"
#include "umlReflectionExec/InteractionFragmentObject.hpp"
#include "umlReflectionExec/NamespaceObject.hpp"

template <class T> 
class Bag;

namespace uml
{
	class InteractionOperand;
}

namespace uml
{
	class Element;
	class ConnectorEnd;
}

namespace UML 
{
	class InteractionOperandObject : virtual public UML::InteractionFragmentObject , virtual public UML::NamespaceObject
	{
		public:
		    //constructors
		    InteractionOperandObject(InteractionOperandObject &obj);
		    InteractionOperandObject(std::shared_ptr<uml::InteractionOperand>);
		 	InteractionOperandObject();
		    //destructor
		    virtual ~InteractionOperandObject();
		
		    virtual std::shared_ptr<ecore::EObject> copy();

			virtual void destroy();
			
			virtual std::shared_ptr<uml::InteractionOperand> getInteractionOperandValue() const;
			virtual std::shared_ptr<uml::Element> getUmlValue() const;
			virtual void setUmlValue(std::shared_ptr<uml::Element>);
			virtual void setInteractionOperandValue(std::shared_ptr<uml::InteractionOperand>);
			virtual void setThisInteractionOperandObjectPtr(std::weak_ptr<InteractionOperandObject> thisObjectPtr);
			virtual bool equals(std::shared_ptr<fUML::Semantics::Values::Value> otherValue);
			virtual std::string toString();
			virtual std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Object>> getDirectContainers();
			virtual void removeValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<fUML::Semantics::Values::Value> values);
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value>> getValues(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> featureValues);
			virtual std::shared_ptr<fUML::Semantics::SimpleClassifiers::FeatureValue> retrieveFeatureValue(std::shared_ptr<uml::StructuralFeature> feature);
			virtual void setFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> value, int position);
			virtual void assignFeatureValue(std::shared_ptr<uml::StructuralFeature> feature, std::shared_ptr<Bag<fUML::Semantics::Values::Value>> value, int position);
			virtual std::shared_ptr<Bag<fUML::Semantics::SimpleClassifiers::FeatureValue>> retrieveFeatureValues();

			virtual std::shared_ptr<Bag<PSCS::Semantics::StructuredClassifiers::CS_Link>> getLinks(std::shared_ptr<PSCS::Semantics::StructuredClassifiers::CS_InteractionPoint> interactionPoint);
			virtual std::shared_ptr<Bag<fUML::Semantics::Values::Value>> retrieveEndValueAsInteractionPoint(std::shared_ptr<fUML::Semantics::Values::Value> endValue, std::shared_ptr<uml::ConnectorEnd> end);

		protected:
			std::shared_ptr<uml::InteractionOperand> m_InteractionOperandValue = nullptr;
	};
}
#endif /* end of include guard: UML_INTERACTIONOPERAND_OBJECT_HPP */
