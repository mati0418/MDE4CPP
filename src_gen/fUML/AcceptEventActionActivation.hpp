//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_ACCEPTEVENTACTIONACTIVATION_HPP
#define FUML_ACCEPTEVENTACTIONACTIVATION_HPP

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
namespace fUML 
{
	class AcceptEventActionEventAccepter;
}

namespace fUML 
{
	class ActionActivation;
}

namespace fUML 
{
	class ActivityEdgeInstance;
}

namespace uml 
{
	class ActivityNode;
}

namespace fUML 
{
	class ActivityNodeActivationGroup;
}

namespace fUML 
{
	class PinActivation;
}

namespace fUML 
{
	class SignalInstance;
}

namespace fUML 
{
	class Token;
}

// base class includes
#include "fUML/ActionActivation.hpp"

// enum includes


//*********************************
namespace fUML 
{
	/*!
	 */
	class AcceptEventActionActivation:virtual public ActionActivation
	{
		public:
 			AcceptEventActionActivation(const AcceptEventActionActivation &) {}
			AcceptEventActionActivation& operator=(AcceptEventActionActivation const&) = delete;

		protected:
			AcceptEventActionActivation(){}


		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~AcceptEventActionActivation() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			 */ 
			virtual void accept(std::shared_ptr<fUML::SignalInstance>  signalInstance)  = 0;
			
			/*!
			 */ 
			virtual bool match(std::shared_ptr<fUML::SignalInstance>  signalInstance)  = 0;
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 */ 
			virtual bool isWaiting() const = 0;
			
			/*!
			 */ 
			virtual void setWaiting (bool _waiting)= 0; 
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::shared_ptr<fUML::AcceptEventActionEventAccepter > getEventAccepter() const = 0;
			
			/*!
			 */
			virtual void setEventAccepter(std::shared_ptr<fUML::AcceptEventActionEventAccepter> _eventAccepter_eventAccepter) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			/*!
			 */ 
			bool m_waiting ;
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			 */
			std::shared_ptr<fUML::AcceptEventActionEventAccepter > m_eventAccepter;
			

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
	};

}
#endif /* end of include guard: FUML_ACCEPTEVENTACTIONACTIVATION_HPP */

