//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_TIMEEVENTTIMEEVENTIMPL_HPP
#define UML_TIMEEVENTTIMEEVENTIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../TimeEvent.hpp"

#include "uml/impl/EventImpl.hpp"

//*********************************
namespace uml 
{
	class TimeEventImpl : virtual public EventImpl, virtual public TimeEvent 
	{
		public: 
			TimeEventImpl(const TimeEventImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			TimeEventImpl& operator=(TimeEventImpl const&); 

		protected:
			friend class umlFactoryImpl;
			TimeEventImpl();
			virtual std::shared_ptr<TimeEvent> getThisTimeEventPtr() const;
			virtual void setThisTimeEventPtr(std::weak_ptr<TimeEvent> thisTimeEventPtr);

			//Additional constructors for the containments back reference
			TimeEventImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			TimeEventImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			TimeEventImpl(std::weak_ptr<uml::Package> par_owningPackage);
			//Additional constructors for the containments back reference
			TimeEventImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			//destructor
			virtual ~TimeEventImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The ValueSpecification when must return a non-negative Integer.
			when.integerValue() >= 0
			*/
			 
			virtual bool when_non_negative(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			Specifies whether the TimeEvent is specified as an absolute or relative time.
			<p>From package UML::CommonBehavior.</p>
			*/
			 
			virtual bool getIsRelative() const ;
			/*!
			Specifies whether the TimeEvent is specified as an absolute or relative time.
			<p>From package UML::CommonBehavior.</p>
			*/
			 
			virtual void setIsRelative (bool _isRelative);
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			Specifies the time of the TimeEvent.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			virtual std::shared_ptr<uml::TimeExpression> getWhen() const ;
			/*!
			Specifies the time of the TimeEvent.
			<p>From package UML::CommonBehavior.</p>
			*/
			
			virtual void setWhen(std::shared_ptr<uml::TimeExpression>) ;
			
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const ;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ; 
			 
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
			std::weak_ptr<TimeEvent> m_thisTimeEventPtr;
	};
}
#endif /* end of include guard: UML_TIMEEVENTTIMEEVENTIMPL_HPP */
