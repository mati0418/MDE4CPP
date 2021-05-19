//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_EXCEPTIONHANDLER_HPP
#define UML_EXCEPTIONHANDLER_HPP

#include <map>

#include <memory>
#include <string>
// forward declarations
template<class T> class Bag; 
template<class T, class ... U> class Subset;

class AnyObject;
typedef std::shared_ptr<AnyObject> Any;

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

namespace uml
{
	class umlFactory;
}

//Forward Declaration for used types 
namespace uml 
{
	class Classifier;
	class Comment;
	class ExecutableNode;
	class ObjectNode;
}

// namespace macro header include
#include "uml/uml.hpp"

// base class includes
#include "uml/Element.hpp"

// enum includes



//*********************************
namespace uml 
{
	/*!
	An ExceptionHandler is an Element that specifies a handlerBody ExecutableNode to execute in case the specified exception occurs during the execution of the protected ExecutableNode.
	<p>From package UML::Activities.</p>
	*/
	
	class UML_API ExceptionHandler: virtual public Element
	{
		public:
 			ExceptionHandler(const ExceptionHandler &) {}

		protected:
			ExceptionHandler(){}
			//Additional constructors for the containments back reference
			ExceptionHandler(std::weak_ptr<uml::Element> par_owner);

			//Additional constructors for the containments back reference
			ExceptionHandler(std::weak_ptr<uml::ExecutableNode> par_protectedNode);

		public:
			virtual std::shared_ptr<ecore::EObject> copy() const = 0;

			//destructor
			virtual ~ExceptionHandler() {}

			//*********************************
			// Operations
			//*********************************
			/*!
			An ActivityEdge that has a source within the handlerBody of an ExceptionHandler must have its target in the handlerBody also, and vice versa.
			let nodes:Set(ActivityNode) = handlerBody.oclAsType(Action).allOwnedNodes() in
			nodes.outgoing->forAll(nodes->includes(target)) and
			nodes.incoming->forAll(nodes->includes(source))
			*/
			 
			virtual bool edge_source_target(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			The exceptionInput must either have no type or every exceptionType must conform to the exceptionInput type.
			exceptionInput.type=null or 
			exceptionType->forAll(conformsTo(exceptionInput.type.oclAsType(Classifier)))
			*/
			 
			virtual bool exception_input_type(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			The handlerBody has no incoming or outgoing ActivityEdges and the exceptionInput has no incoming ActivityEdges.
			handlerBody.incoming->isEmpty() and handlerBody.outgoing->isEmpty() and exceptionInput.incoming->isEmpty()
			*/
			 
			virtual bool handler_body_edges(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			The handlerBody must have the same owner as the protectedNode.
			handlerBody.owner=protectedNode.owner
			*/
			 
			virtual bool handler_body_owner(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			The handlerBody is an Action with one InputPin, and that InputPin is the same as the exceptionInput.
			handlerBody.oclIsKindOf(Action) and
			let inputs: OrderedSet(InputPin) = handlerBody.oclAsType(Action).input in
			inputs->size()=1 and inputs->first()=exceptionInput
			*/
			 
			virtual bool one_input(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;/*!
			If the protectedNode is an Action with OutputPins, then the handlerBody must also be an Action with the same number of OutputPins, which are compatible in type, ordering, and multiplicity to those of the protectedNode.
			(protectedNode.oclIsKindOf(Action) and protectedNode.oclAsType(Action).output->notEmpty()) implies
			(
			  handlerBody.oclIsKindOf(Action) and 
			  let protectedNodeOutput : OrderedSet(OutputPin) = protectedNode.oclAsType(Action).output,
			        handlerBodyOutput : OrderedSet(OutputPin) =  handlerBody.oclAsType(Action).output in
			    protectedNodeOutput->size() = handlerBodyOutput->size() and
			    Sequence{1..protectedNodeOutput->size()}->forAll(i |
			    	handlerBodyOutput->at(i).type.conformsTo(protectedNodeOutput->at(i).type) and
			    	handlerBodyOutput->at(i).isOrdered=protectedNodeOutput->at(i).isOrdered and
			    	handlerBodyOutput->at(i).compatibleWith(protectedNodeOutput->at(i)))
			)
			*/
			 
			virtual bool output_pins(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) = 0;
			//*********************************
			// Attributes Getter Setter
			//*********************************
			
			//*********************************
			// Reference
			//*********************************
			/*!
			An ObjectNode within the handlerBody. When the ExceptionHandler catches an exception, the exception token is placed on this ObjectNode, causing the handlerBody to execute.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<uml::ObjectNode> getExceptionInput() const = 0;
			/*!
			An ObjectNode within the handlerBody. When the ExceptionHandler catches an exception, the exception token is placed on this ObjectNode, causing the handlerBody to execute.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setExceptionInput(std::shared_ptr<uml::ObjectNode>) = 0;
			/*!
			The Classifiers whose instances the ExceptionHandler catches as exceptions. If an exception occurs whose type is any exceptionType, the ExceptionHandler catches the exception and executes the handlerBody.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<Bag<uml::Classifier>> getExceptionType() const = 0;
			
			/*!
			An ExecutableNode that is executed if the ExceptionHandler catches an exception.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::shared_ptr<uml::ExecutableNode> getHandlerBody() const = 0;
			/*!
			An ExecutableNode that is executed if the ExceptionHandler catches an exception.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setHandlerBody(std::shared_ptr<uml::ExecutableNode>) = 0;
			/*!
			The ExecutableNode protected by the ExceptionHandler. If an exception propagates out of the protectedNode and has a type matching one of the exceptionTypes, then it is caught by this ExceptionHandler.
			<p>From package UML::Activities.</p>
			*/
			
			virtual std::weak_ptr<uml::ExecutableNode> getProtectedNode() const = 0;
			/*!
			The ExecutableNode protected by the ExceptionHandler. If an exception propagates out of the protectedNode and has a type matching one of the exceptionTypes, then it is caught by this ExceptionHandler.
			<p>From package UML::Activities.</p>
			*/
			
			virtual void setProtectedNode(std::weak_ptr<uml::ExecutableNode>) = 0;
			

		protected:
			//*********************************
			// Attribute Members
			//*********************************
			
			
			//*********************************
			// Reference Members
			//*********************************
			/*!
			An ObjectNode within the handlerBody. When the ExceptionHandler catches an exception, the exception token is placed on this ObjectNode, causing the handlerBody to execute.
			<p>From package UML::Activities.</p>
			*/
			
			std::shared_ptr<uml::ObjectNode> m_exceptionInput;/*!
			The Classifiers whose instances the ExceptionHandler catches as exceptions. If an exception occurs whose type is any exceptionType, the ExceptionHandler catches the exception and executes the handlerBody.
			<p>From package UML::Activities.</p>
			*/
			
			mutable std::shared_ptr<Bag<uml::Classifier>> m_exceptionType;/*!
			An ExecutableNode that is executed if the ExceptionHandler catches an exception.
			<p>From package UML::Activities.</p>
			*/
			
			std::shared_ptr<uml::ExecutableNode> m_handlerBody;/*!
			The ExecutableNode protected by the ExceptionHandler. If an exception propagates out of the protectedNode and has a type matching one of the exceptionTypes, then it is caught by this ExceptionHandler.
			<p>From package UML::Activities.</p>
			*/
			
			std::weak_ptr<uml::ExecutableNode> m_protectedNode;

		public:
			//*********************************
			// Union Getter
			//*********************************
			/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const = 0;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const = 0;

			virtual std::shared_ptr<ecore::EObject> eContainer() const = 0; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) = 0;
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) = 0;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const = 0;
			
	};

}
#endif /* end of include guard: UML_EXCEPTIONHANDLER_HPP */
