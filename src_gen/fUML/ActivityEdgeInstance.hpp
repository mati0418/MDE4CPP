//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_ACTIVITYEDGEINSTANCE_HPP
#define FUML_ACTIVITYEDGEINSTANCE_HPP

#ifdef NDEBUG
    #define DEBUG_MESSAGE(a) /**/
#else
    #define DEBUG_MESSAGE(a) a
#endif

#ifdef ACTIVITY_DEBUG_ON
    #define ACT_DEBUG(a) a
#else
    #define ACT_DEBUG(a) /**/
#endif

//#include "util/ProfileCallCount.hpp"

#include <map>
#include <string>
#include <vector>
#include <memory>
#include <cassert>

#include "abstractDataTypes/SubsetUnion.hpp"
#include "boost/any.hpp"

//*********************************
// generated Includes

//Forward Declaration for used types
namespace uml 
{
	class ActivityEdge;
}

namespace fUML 
{
	class ActivityNodeActivation;
}

namespace fUML 
{
	class ActivityNodeActivationGroup;
}

namespace fUML 
{
	class Offer;
}

namespace fUML 
{
	class Token;
}

// base class includes

// enum includes

#include "ecore/EObject.hpp"

//*********************************
namespace fUML 
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


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ActivityEdgeInstance() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual int countOfferedValue()  = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::Token> > getOfferedTokens()  = 0;
			
			/*!
			 */ 
			virtual bool hasOffer()  = 0;
			
			/*!
			 */ 
			virtual void sendOffer(std::shared_ptr<Bag<fUML::Token> >  tokens)  = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::Token> > takeOfferedTokens()  = 0;
			
			/*!
			 */ 
			virtual std::shared_ptr<Bag<fUML::Token> > takeOfferedTokens(int maxCount)  = 0;
			
			
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
			virtual std::shared_ptr<fUML::ActivityNodeActivationGroup > getGroup() const = 0;
			
			/*!
			 */
			virtual void setGroup(std::shared_ptr<fUML::ActivityNodeActivationGroup> _group_group) = 0;
			/*!
			 */
			virtual std::shared_ptr< Bag<fUML::Offer> > getOffers() const = 0;
			
			/*!
			 */
			virtual std::shared_ptr<fUML::ActivityNodeActivation > getSource() const = 0;
			
			/*!
			 */
			virtual void setSource(std::shared_ptr<fUML::ActivityNodeActivation> _source_source) = 0;
			/*!
			 */
			virtual std::shared_ptr<fUML::ActivityNodeActivation > getTarget() const = 0;
			
			/*!
			 */
			virtual void setTarget(std::shared_ptr<fUML::ActivityNodeActivation> _target_target) = 0;
			

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
			std::shared_ptr<fUML::ActivityNodeActivationGroup > m_group;
			/*!
			 */
			std::shared_ptr< Bag<fUML::Offer> > m_offers;
			/*!
			 */
			std::shared_ptr<fUML::ActivityNodeActivation > m_source;
			/*!
			 */
			std::shared_ptr<fUML::ActivityNodeActivation > m_target;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
	};

}
#endif /* end of include guard: FUML_ACTIVITYEDGEINSTANCE_HPP */

