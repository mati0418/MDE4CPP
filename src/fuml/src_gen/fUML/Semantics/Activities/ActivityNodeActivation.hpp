//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_ACTIVITYNODEACTIVATION_HPP
#define FUML_SEMANTICS_ACTIVITIES_ACTIVITYNODEACTIVATION_HPP


#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 


//*********************************
// generated Includes
#include <map> // used for Persistence
#include <vector> // used for Persistence
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
	class fUMLFactory;
}

//Forward Declaration for used types 
namespace fUML::Semantics::Activities 
{
	class ActivityEdgeInstance;
	class ActivityExecution;
	class ActivityNodeActivationGroup;
	class Token;
}
namespace fUML::Semantics::Loci 
{
	class Locus;
}
namespace fUML::Semantics::StructuredClassifiers 
{
	class Object;
}
namespace uml 
{
	class ActivityNode;
}

// namespace macro header include
#include "fuml/fuml.hpp"

// base class includes
#include "fUML/Semantics/Loci/SemanticVisitor.hpp"

// enum includes



//*********************************
namespace fUML::Semantics::Activities 
{
	
	class FUML_API ActivityNodeActivation: virtual public fUML::Semantics::Loci::SemanticVisitor
	{
		public:
 			ActivityNodeActivation(const ActivityNodeActivation &) {}

		protected:
			ActivityNodeActivation(){}
			//Additional constructors for the containments back reference
			ActivityNodeActivation(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> par_group);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ActivityNodeActivation() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual void addIncomingEdge(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edge) = 0; 
			virtual void addOutgoingEdge(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edge) = 0; 
			virtual void addToken(std::shared_ptr<fUML::Semantics::Activities::Token> token) = 0; 
			virtual void addTokens(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> tokens) = 0; 
			virtual void clearTokens() = 0; 
			virtual void createEdgeInstances() = 0; 
			virtual void createNodeActivations() = 0; 
			virtual void fire(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> incomingTokens) = 0; 
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> getActivityExecution() = 0; 
			virtual std::shared_ptr<fUML::Semantics::StructuredClassifiers::Object> getExecutionContext() = 0; 
			virtual std::shared_ptr<fUML::Semantics::Loci::Locus> getExecutionLocus() = 0; 
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> getNodeActivation(std::shared_ptr<uml::ActivityNode> node) = 0; 
			virtual bool getRunning() = 0; 
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > getTokens() = 0; 
			virtual bool isReady() = 0; 
			virtual bool isSourceFor(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edgeInstances) = 0; 
			virtual void receiveOffer() = 0; 
			virtual int removeToken(std::shared_ptr<fUML::Semantics::Activities::Token> token) = 0; 
			virtual void resume() = 0; 
			virtual void run() = 0; 
			virtual void sendOffers(std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> tokens) = 0; 
			virtual void suspend() = 0; 
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > takeOfferedTokens() = 0; 
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token> > takeTokens() = 0; 
			virtual void terminate() = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			 
			virtual bool isRunning() const = 0;
			 
			virtual void setRunning (bool _running)= 0;
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> getGroup() const = 0;
			
			virtual void setGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup>) = 0;
			
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> getHeldTokens() const = 0;
			
			
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> getIncomingEdges() const = 0;
			
			
			virtual std::shared_ptr<uml::ActivityNode> getNode() const = 0;
			
			virtual void setNode(std::shared_ptr<uml::ActivityNode>) = 0;
			
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> getOutgoingEdges() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			 
			bool m_running = false;
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			std::weak_ptr<fUML::Semantics::Activities::ActivityNodeActivationGroup> m_group;
			mutable std::shared_ptr<Bag<fUML::Semantics::Activities::Token>> m_heldTokens;
			mutable std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> m_incomingEdges;
			std::shared_ptr<uml::ActivityNode> m_node;
			mutable std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> m_outgoingEdges;

		public:
			//*********************************
			// Union Getter
			//*********************************
			

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_ACTIVITYNODEACTIVATION_HPP */
