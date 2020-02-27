//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_ACTIVITYEDGEINSTANCE_HPP
#define FUML_SEMANTICS_ACTIVITIES_ACTIVITYEDGEINSTANCE_HPP

#include <list>
#include <memory>
#include <string>


// forward declarations
template<class T> class Bag; 



//*********************************
// generated Includes

#include <map>

namespace persistence
{
	namespace interfaces
	{
		class XLoadHandler; // used for Persistence
		class XSaveHandler; // used for Persistence
	}
}

namespace fUML
{
	class FUMLFactory;
}

//Forward Declaration for used types
namespace uml 
{
	class ActivityEdge;
}

namespace fUML::Semantics::Activities 
{
	class ActivityNodeActivation;
}

namespace fUML::Semantics::Activities 
{
	class ActivityNodeActivationGroup;
}

namespace fUML::Semantics::Activities 
{
	class Offer;
}

namespace fUML::Semantics::Activities 
{
	class Token;
}

// base class includes

// enum includes

#include "ecore/EObject.hpp"

//*********************************
namespace fUML::Semantics::Activities 
{
	/*!
	 */
	class ActivityEdgeInstance : virtual public ecore::EObject 

	{
		public:
 			ActivityEdgeInstance(const ActivityEdgeInstance &) {}
			ActivityEdgeInstance& operator=(ActivityEdgeInstance const&) = delete;

		protected:
			ActivityEdgeInstance(){}


			//Additional constructors for the containments back reference

			ActivityEdgeInstance(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > par_group);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ActivityEdgeInstance() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual int countOfferedValue() = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > getOfferedTokens() = 0;
			
			/*!
			 */ 
			virtual bool hasOffer() = 0;
			
			/*!
			 */ 
			virtual void sendOffer(std::shared_ptr<Bag<fUML::Semantics::Activities::Token> >  tokens) = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > takeOfferedTokens() = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > takeOfferedTokens(int maxCount) = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<uml::ActivityEdge > getEdge() const = 0;
			
			/*!
			 */
			virtual void setEdge(std::shared_ptr<uml::ActivityEdge> _edge_edge) = 0;
			/*!
			 */
			virtual std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > getGroup() const = 0;
			
			/*!
			 */
			virtual void setGroup(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> _group_group) = 0;
			/*!
			 */
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Offer>> getOffers() const = 0;
			
			/*!
			 */
			virtual std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation > getSource() const = 0;
			
			/*!
			 */
			virtual void setSource(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> _source_source) = 0;
			/*!
			 */
			virtual std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation > getTarget() const = 0;
			
			/*!
			 */
			virtual void setTarget(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> _target_target) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::shared_ptr<uml::ActivityEdge > m_edge;
			/*!
			 */
			std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup > m_group;
			/*!
			 */
			std::shared_ptr<Bag<fUML::Semantics::Activities::Offer>> m_offers;
			/*!
			 */
			std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation > m_source;
			/*!
			 */
			std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivation > m_target;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_ACTIVITYEDGEINSTANCE_HPP */
