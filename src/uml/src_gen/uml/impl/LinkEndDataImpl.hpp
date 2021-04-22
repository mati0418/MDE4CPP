//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_LINKENDDATALINKENDDATAIMPL_HPP
#define UML_LINKENDDATALINKENDDATAIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../LinkEndData.hpp"

#include "uml/impl/ElementImpl.hpp"

//*********************************
namespace uml 
{
	class LinkEndDataImpl : virtual public ElementImpl, virtual public LinkEndData 
	{
		public: 
			LinkEndDataImpl(const LinkEndDataImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			LinkEndDataImpl& operator=(LinkEndDataImpl const&); 

		protected:
			friend class umlFactoryImpl;
			LinkEndDataImpl();
			virtual std::shared_ptr<LinkEndData> getThisLinkEndDataPtr() const;
			virtual void setThisLinkEndDataPtr(std::weak_ptr<LinkEndData> thisLinkEndDataPtr);

			//Additional constructors for the containments back reference
			LinkEndDataImpl(std::weak_ptr<uml::Element> par_owner);

		public:
			//destructor
			virtual ~LinkEndDataImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			Returns all the InputPins referenced by this LinkEndData. By default this includes the value and qualifier InputPins, but subclasses may override the operation to add other InputPins.
			result = (value->asBag()->union(qualifier.value))
			<p>From package UML::Actions.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::InputPin> > allPins() ;/*!
			The value InputPin is not also the qualifier value InputPin.
			value->excludesAll(qualifier.value)
			*/
			 
			virtual bool end_object_input_pin(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			The multiplicity of the value InputPin must be 1..1.
			value<>null implies value.is(1,1)
			*/
			 
			virtual bool multiplicity(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			The Property must be an Association memberEnd.
			end.association <> null
			*/
			 
			virtual bool property_is_association_end(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			The qualifiers must be qualifiers of the Association end.
			end.qualifier->includesAll(qualifier.qualifier)
			*/
			 
			virtual bool qualifiers(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			The type of the value InputPin conforms to the type of the Association end.
			value<>null implies value.type.conformsTo(end.type)
			*/
			 
			virtual bool same_type(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			The Association end for which this LinkEndData specifies values.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::Property> getEnd() const ;
			/*!
			The Association end for which this LinkEndData specifies values.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setEnd(std::shared_ptr<uml::Property>) ;
			/*!
			A set of QualifierValues used to provide values for the qualifiers of the end.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::QualifierValue, uml::Element>> getQualifier() const ;
			
			/*!
			The InputPin that provides the specified value for the given end. This InputPin is omitted if the LinkEndData specifies the "open" end for a ReadLinkAction.
			<p>From package UML::Actions.</p>
			*/
			
			virtual std::shared_ptr<uml::InputPin> getValue() const ;
			/*!
			The InputPin that provides the specified value for the given end. This InputPin is omitted if the LinkEndData specifies the "open" end for a ReadLinkAction.
			<p>From package UML::Actions.</p>
			*/
			
			virtual void setValue(std::shared_ptr<uml::InputPin>) ;
			
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ; 
			 
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
			std::weak_ptr<LinkEndData> m_thisLinkEndDataPtr;
	};
}
#endif /* end of include guard: UML_LINKENDDATALINKENDDATAIMPL_HPP */
