#include "PSCS/Semantics/StructuredClassifiers/impl/CS_DefaultRequestPropagationStrategyImpl.hpp"

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

#include <cassert>
#include <iostream>
#include <sstream>

#include "abstractDataTypes/Bag.hpp"

#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation
#include "fUML/Semantics/Actions/SendSignalActionActivation.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "PSCS/Semantics/StructuredClassifiers/CS_RequestPropagationStrategy.hpp"
#include "fUML/Semantics/StructuredClassifiers/Reference.hpp"
#include "fUML/Semantics/Loci/SemanticVisitor.hpp"

//Factories an Package includes
#include "PSCS/PSCSPackage.hpp"
#include "PSCS/Semantics/SemanticsPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "PSCS/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"
#include "fUML/Semantics/StructuredClassifiers/StructuredClassifiersPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace PSCS::Semantics::StructuredClassifiers;

//*********************************
// Constructor / Destructor
//*********************************
CS_DefaultRequestPropagationStrategyImpl::CS_DefaultRequestPropagationStrategyImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

CS_DefaultRequestPropagationStrategyImpl::~CS_DefaultRequestPropagationStrategyImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CS_DefaultRequestPropagationStrategy "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


CS_DefaultRequestPropagationStrategyImpl::CS_DefaultRequestPropagationStrategyImpl(const CS_DefaultRequestPropagationStrategyImpl & obj): CS_DefaultRequestPropagationStrategyImpl()
{
	*this = obj;
}

CS_DefaultRequestPropagationStrategyImpl& CS_DefaultRequestPropagationStrategyImpl::operator=(const CS_DefaultRequestPropagationStrategyImpl & obj)
{
	//call overloaded =Operator for each base class
	CS_RequestPropagationStrategyImpl::operator=(obj);
	CS_DefaultRequestPropagationStrategy::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CS_DefaultRequestPropagationStrategy "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> CS_DefaultRequestPropagationStrategyImpl::copy() const
{
	std::shared_ptr<CS_DefaultRequestPropagationStrategyImpl> element(new CS_DefaultRequestPropagationStrategyImpl());
	*element =(*this);
	element->setThisCS_DefaultRequestPropagationStrategyPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CS_DefaultRequestPropagationStrategyImpl::eStaticClass() const
{
	return PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance()->getCS_DefaultRequestPropagationStrategy_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference> > CS_DefaultRequestPropagationStrategyImpl::select(std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> potentialTargets,std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> context)
{
	//ADD_COUNT(__PRETTY_FUNCTION__)
	//generated from body annotation
			// returns all potential targets in the case where the context is a SendSignalActionActivation
	// returns the first potential target in the case where the context is anything else
	std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> selectedTargets(new Bag<fUML::Semantics::StructuredClassifiers::Reference>());
	if(std::dynamic_pointer_cast<fUML::Semantics::Actions::SendSignalActionActivation>(context) != nullptr) {
		for(unsigned int i = 0; i < potentialTargets->size(); i++) {
			selectedTargets->add(potentialTargets->at(i));
		}
	}
	else {
		if(potentialTargets->size() >= 1) {
			selectedTargets->add(potentialTargets->at(0));
		}
	}
	return selectedTargets;
	//end of body
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************



std::shared_ptr<CS_DefaultRequestPropagationStrategy> CS_DefaultRequestPropagationStrategyImpl::getThisCS_DefaultRequestPropagationStrategyPtr() const
{
	return m_thisCS_DefaultRequestPropagationStrategyPtr.lock();
}
void CS_DefaultRequestPropagationStrategyImpl::setThisCS_DefaultRequestPropagationStrategyPtr(std::weak_ptr<CS_DefaultRequestPropagationStrategy> thisCS_DefaultRequestPropagationStrategyPtr)
{
	m_thisCS_DefaultRequestPropagationStrategyPtr = thisCS_DefaultRequestPropagationStrategyPtr;
	setThisCS_RequestPropagationStrategyPtr(thisCS_DefaultRequestPropagationStrategyPtr);
}
std::shared_ptr<ecore::EObject> CS_DefaultRequestPropagationStrategyImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any CS_DefaultRequestPropagationStrategyImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return CS_RequestPropagationStrategyImpl::eGet(featureID, resolve, coreType);
}
bool CS_DefaultRequestPropagationStrategyImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return CS_RequestPropagationStrategyImpl::internalEIsSet(featureID);
}
bool CS_DefaultRequestPropagationStrategyImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return CS_RequestPropagationStrategyImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any CS_DefaultRequestPropagationStrategyImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 1103
		case StructuredClassifiersPackage::CS_DEFAULTREQUESTPROPAGATIONSTRATEGY_OPERATION_SELECT_REFERENCE_SEMANTICVISITOR:
		{
			//Retrieve input parameter 'potentialTargets'
			//parameter 0
			std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> incoming_param_potentialTargets;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_potentialTargets_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_potentialTargets = (*incoming_param_potentialTargets_arguments_citer)->get()->get<std::shared_ptr<Bag<fUML::Semantics::StructuredClassifiers::Reference>> >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<fUML::Semantics::Loci::SemanticVisitor> >();
			result = eAny(this->select(incoming_param_potentialTargets,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = CS_RequestPropagationStrategyImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

//*********************************
// Persistence Functions
//*********************************
void CS_DefaultRequestPropagationStrategyImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get PSCSFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void CS_DefaultRequestPropagationStrategyImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	CS_RequestPropagationStrategyImpl::loadAttributes(loadHandler, attr_list);
}

void CS_DefaultRequestPropagationStrategyImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	CS_RequestPropagationStrategyImpl::loadNode(nodeName, loadHandler);
}

void CS_DefaultRequestPropagationStrategyImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	CS_RequestPropagationStrategyImpl::resolveReferences(featureID, references);
}

void CS_DefaultRequestPropagationStrategyImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CS_RequestPropagationStrategyImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticStrategyImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void CS_DefaultRequestPropagationStrategyImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage> package = PSCS::Semantics::StructuredClassifiers::StructuredClassifiersPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

