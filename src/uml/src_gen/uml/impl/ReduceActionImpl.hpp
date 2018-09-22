//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_REDUCEACTIONREDUCEACTIONIMPL_HPP
#define UML_REDUCEACTIONREDUCEACTIONIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../ReduceAction.hpp"

#include "uml/impl/ActionImpl.hpp"

//*********************************
namespace uml 
{
	class ReduceActionImpl :virtual public ActionImpl, virtual public ReduceAction 
	{
		public: 
			ReduceActionImpl(const ReduceActionImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			ReduceActionImpl& operator=(ReduceActionImpl const&) = delete;

		protected:
			friend class UmlFactoryImpl;
			ReduceActionImpl();
			virtual std::shared_ptr<ReduceAction> getThisReduceActionPtr() const;
			virtual void setThisReduceActionPtr(std::weak_ptr<ReduceAction> thisReduceActionPtr);

			//Additional constructors for the containments back reference
			ReduceActionImpl(std::weak_ptr<uml::Activity > par_activity);


			//Additional constructors for the containments back reference
			ReduceActionImpl(std::weak_ptr<uml::StructuredActivityNode > par_inStructuredNode);


			//Additional constructors for the containments back reference
			ReduceActionImpl(std::weak_ptr<uml::Namespace > par_namespace);


			//Additional constructors for the containments back reference
			ReduceActionImpl(std::weak_ptr<uml::Element > par_owner);




		public:
			//destructor
			virtual ~ReduceActionImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			 The type of the collection InputPin must be a collection. */ 
			virtual bool input_type_is_collection(Any diagnostics,std::map <   Any, Any >  context) ;
			
			/*!
			 The type of the output of the reducer Behavior must conform to the type of the result OutputPin.
			reducer.outputParameters().type->forAll(conformsTo(result.type)) */ 
			virtual bool output_types_are_compatible(Any diagnostics,std::map <   Any, Any >  context) ;
			
			/*!
			 The reducer Behavior must have two input ownedParameters and one output ownedParameter, where the type of the output Parameter and the type of elements of the input collection conform to the types of the input Parameters.
			let inputs: OrderedSet(Parameter) = reducer.inputParameters() in
			let outputs: OrderedSet(Parameter) = reducer.outputParameters() in
			inputs->size()=2 and outputs->size()=1 and
			inputs.type->forAll(t | 
				outputs.type->forAll(conformsTo(t)) and 
				-- Note that the following only checks the case when the collection is via multiple tokens.
				collection.upperBound()>1 implies collection.type.conformsTo(t)) */ 
			virtual bool reducer_inputs_output(Any diagnostics,std::map <   Any, Any >  context) ;
			
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 Indicates whether the order of the input collection should determine the order in which the reducer Behavior is applied to its elements.
			<p>From package UML::Actions.</p> */ 
			virtual bool getIsOrdered() const ;
			
			/*!
			 Indicates whether the order of the input collection should determine the order in which the reducer Behavior is applied to its elements.
			<p>From package UML::Actions.</p> */ 
			virtual void setIsOrdered (bool _isOrdered); 
			
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 The InputPin that provides the collection to be reduced.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::InputPin > getCollection() const ;
			
			/*!
			 The InputPin that provides the collection to be reduced.
			<p>From package UML::Actions.</p> */
			virtual void setCollection(std::shared_ptr<uml::InputPin> _collection_collection) ;
			/*!
			 A Behavior that is repreatedly applied to two elements of the input collection to produce a value that is of the same type as elements of the collection.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::Behavior > getReducer() const ;
			
			/*!
			 A Behavior that is repreatedly applied to two elements of the input collection to produce a value that is of the same type as elements of the collection.
			<p>From package UML::Actions.</p> */
			virtual void setReducer(std::shared_ptr<uml::Behavior> _reducer_reducer) ;
			/*!
			 The output pin on which the result value is placed.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<uml::OutputPin > getResult() const ;
			
			/*!
			 The output pin on which the result value is placed.
			<p>From package UML::Actions.</p> */
			virtual void setResult(std::shared_ptr<uml::OutputPin> _result_result) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			 ActivityGroups containing the ActivityNode.
			<p>From package UML::Activities.</p> */
			virtual std::shared_ptr<Union<uml::ActivityGroup>> getInGroup() const ;/*!
			 The ordered set of InputPins representing the inputs to the Action.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> getInput() const ;/*!
			 The ordered set of OutputPins representing outputs from the Action.
			<p>From package UML::Actions.</p> */
			virtual std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> getOutput() const ;/*!
			 The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			 The Element that owns this Element.
			<p>From package UML::CommonStructure.</p> */
			virtual std::weak_ptr<uml::Element > getOwner() const ;/*!
			 The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p> */
			virtual std::shared_ptr<Union<uml::RedefinableElement>> getRedefinedElement() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory);
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;

		private:
			std::weak_ptr<ReduceAction> m_thisReduceActionPtr;
	};
}
#endif /* end of include guard: UML_REDUCEACTIONREDUCEACTIONIMPL_HPP */