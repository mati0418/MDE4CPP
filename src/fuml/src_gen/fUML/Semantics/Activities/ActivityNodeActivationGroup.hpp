//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef FUML_SEMANTICS_ACTIVITIES_ACTIVITYNODEACTIVATIONGROUP_HPP
#define FUML_SEMANTICS_ACTIVITIES_ACTIVITYNODEACTIVATIONGROUP_HPP


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
namespace fUML::Semantics::Actions 
{
	class StructuredActivityNodeActivation;
}
namespace fUML::Semantics::Activities 
{
	class ActivityEdgeInstance;
	class ActivityExecution;
	class ActivityNodeActivation;
	class ActivityParameterNodeActivation;
}
namespace uml 
{
	class ActivityEdge;
	class ActivityNode;
}

// namespace macro header include
#include "fuml/fuml.hpp"

// base class includes

// enum includes

#include "ecore/EModelElement.hpp"


//*********************************
namespace fUML::Semantics::Activities 
{
	
	class FUML_API ActivityNodeActivationGroup : virtual public ecore::EModelElement
	{
		public:
 			ActivityNodeActivationGroup(const ActivityNodeActivationGroup &) {}

		protected:
			ActivityNodeActivationGroup(){}
			//Additional constructors for the containments back reference
			ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Activities::ActivityExecution> par_activityExecution);

			//Additional constructors for the containments back reference
			ActivityNodeActivationGroup(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> par_containingNodeActivation);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ActivityNodeActivationGroup() {}

			//*********************************
			// Operations
			//*********************************
			 
			virtual void activate(std::shared_ptr<Bag<uml::ActivityNode>> nodes,std::shared_ptr<Bag<uml::ActivityEdge>> edges) = 0; 
			virtual void addEdgeInstance(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> instance) = 0; 
			virtual void addNodeActivation(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation) = 0; 
			virtual bool checkIncomingEdges(std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> incomingEdges,std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> activations) = 0; 
			virtual void createEdgeInstance(std::shared_ptr<Bag<uml::ActivityEdge>> edges) = 0; 
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> createNodeActivation(std::shared_ptr<uml::ActivityNode> node) = 0; 
			virtual void createNodeActivations(std::shared_ptr<Bag<uml::ActivityNode>> nodes) = 0; 
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> getNodeActivation(std::shared_ptr<uml::ActivityNode> node) = 0; 
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityParameterNodeActivation> > getOutputParameterNodeActivations() = 0; 
			virtual bool hasSourceFor(std::shared_ptr<fUML::Semantics::Activities::ActivityEdgeInstance> edgeInstance) = 0; 
			virtual bool isSuspended() = 0; 
			virtual void resume(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation) = 0; 
			virtual std::shared_ptr<fUML::Semantics::Activities::ActivityExecution> retrieveActivityExecution() = 0; 
			virtual void run(std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> activations) = 0; 
			virtual void runNodes(std::shared_ptr<Bag<uml::ActivityNode>> nodes) = 0; 
			virtual void suspend(std::shared_ptr<fUML::Semantics::Activities::ActivityNodeActivation> activation) = 0; 
			virtual void terminateAll() = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			
			virtual std::weak_ptr<fUML::Semantics::Activities::ActivityExecution> getActivityExecution() const = 0;
			
			virtual void setActivityExecution(std::weak_ptr<fUML::Semantics::Activities::ActivityExecution>) = 0;
			
			virtual std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> getContainingNodeActivation() const = 0;
			
			virtual void setContainingNodeActivation(std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation>) = 0;
			
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> getEdgeInstances() const = 0;
			
			
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> getNodeActivations() const = 0;
			
			
			virtual std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> getSuspendedActivations() const = 0;
			
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			
			std::weak_ptr<fUML::Semantics::Activities::ActivityExecution> m_activityExecution;
			std::weak_ptr<fUML::Semantics::Actions::StructuredActivityNodeActivation> m_containingNodeActivation;
			mutable std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityEdgeInstance>> m_edgeInstances;
			mutable std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> m_nodeActivations;
			mutable std::shared_ptr<Bag<fUML::Semantics::Activities::ActivityNodeActivation>> m_suspendedActivations;

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
#endif /* end of include guard: FUML_SEMANTICS_ACTIVITIES_ACTIVITYNODEACTIVATIONGROUP_HPP */
