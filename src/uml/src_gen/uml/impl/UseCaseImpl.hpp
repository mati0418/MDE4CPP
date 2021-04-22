//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_USECASEUSECASEIMPL_HPP
#define UML_USECASEUSECASEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../UseCase.hpp"

#include "uml/impl/BehavioredClassifierImpl.hpp"

//*********************************
namespace uml 
{
	class UseCaseImpl : virtual public BehavioredClassifierImpl, virtual public UseCase 
	{
		public: 
			UseCaseImpl(const UseCaseImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			UseCaseImpl& operator=(UseCaseImpl const&); 

		protected:
			friend class umlFactoryImpl;
			UseCaseImpl();
			virtual std::shared_ptr<UseCase> getThisUseCasePtr() const;
			virtual void setThisUseCasePtr(std::weak_ptr<UseCase> thisUseCasePtr);

			//Additional constructors for the containments back reference
			UseCaseImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			UseCaseImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			UseCaseImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			UseCaseImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);
			//Additional constructors for the containments back reference

		public:
			//destructor
			virtual ~UseCaseImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The query allIncludedUseCases() returns the transitive closure of all UseCases (directly or indirectly) included by this UseCase.
			result = (self.include.addition->union(self.include.addition->collect(uc | uc.allIncludedUseCases()))->asSet())
			<p>From package UML::UseCases.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::UseCase> > allIncludedUseCases() ;/*!
			UseCases can only be involved in binary Associations.
			Association.allInstances()->forAll(a | a.memberEnd.type->includes(self) implies a.memberEnd->size() = 2)
			*/
			 
			virtual bool binary_associations(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			A UseCase cannot include UseCases that directly or indirectly include it.
			not allIncludedUseCases()->includes(self)
			*/
			 
			virtual bool cannot_include_self(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			A UseCase must have a name.
			name -> notEmpty ()
			*/
			 
			virtual bool must_have_name(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			UseCases cannot have Associations to UseCases specifying the same subject.
			Association.allInstances()->forAll(a | a.memberEnd.type->includes(self) implies 
			   (
			   let usecases: Set(UseCase) = a.memberEnd.type->select(oclIsKindOf(UseCase))->collect(oclAsType(UseCase))->asSet() in
			   usecases->size() > 1 implies usecases->collect(subject)->size() > 1
			   )
			)
			*/
			 
			virtual bool no_association_to_use_case(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The Extend relationships owned by this UseCase.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Extend, uml::NamedElement>> getExtend() const ;
			
			/*!
			The ExtensionPoints owned by this UseCase.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ExtensionPoint, uml::NamedElement>> getExtensionPoint() const ;
			
			/*!
			The Include relationships owned by this UseCase.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Include, uml::NamedElement>> getInclude() const ;
			
			/*!
			The subjects to which this UseCase applies. Each subject or its parts realize all the UseCases that apply to it.
			<p>From package UML::UseCases.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Classifier>> getSubject() const ;
			
			
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			Specifies each Feature directly defined in the classifier. Note that there may be members of the Classifier that are of the type Feature but are not included, e.g., inherited features.
			<p>From package UML::Classification.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement>> getFeature() const ;/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const ;/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const ;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> getOwnedMember() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ;/*!
			The RedefinableElement that is being redefined by this element.
			<p>From package UML::Classification.</p>
			*/
			
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
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<UseCase> m_thisUseCasePtr;
	};
}
#endif /* end of include guard: UML_USECASEUSECASEIMPL_HPP */
