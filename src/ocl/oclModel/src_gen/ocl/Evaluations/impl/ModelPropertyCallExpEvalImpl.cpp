
#include "ocl/Evaluations/impl/ModelPropertyCallExpEvalImpl.hpp"

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
#include <stdexcept>




#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"


//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "fUML/Semantics/Loci/LociFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "fUML/Semantics/Values/ValuesFactory.hpp"
#include "uml/umlFactory.hpp"
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "ocl/Evaluations/OclExpEval.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Evaluations/PropertyCallExpEval.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"
//Factories and Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"

using namespace ocl::Evaluations;

//*********************************
// Constructor / Destructor
//*********************************
ModelPropertyCallExpEvalImpl::ModelPropertyCallExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ModelPropertyCallExpEvalImpl::~ModelPropertyCallExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ModelPropertyCallExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ModelPropertyCallExpEvalImpl::ModelPropertyCallExpEvalImpl(const ModelPropertyCallExpEvalImpl & obj): ModelPropertyCallExpEvalImpl()
{
	*this = obj;
}

ModelPropertyCallExpEvalImpl& ModelPropertyCallExpEvalImpl::operator=(const ModelPropertyCallExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	PropertyCallExpEvalImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ModelPropertyCallExpEval 
	 * which is generated by the compiler (as ModelPropertyCallExpEval is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ModelPropertyCallExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ModelPropertyCallExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ModelPropertyCallExpEvalImpl::copy() const
{
	std::shared_ptr<ModelPropertyCallExpEvalImpl> element(new ModelPropertyCallExpEvalImpl());
	*element =(*this);
	element->setThisModelPropertyCallExpEvalPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool ModelPropertyCallExpEvalImpl::atPre()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ModelPropertyCallExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void ModelPropertyCallExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get oclFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ModelPropertyCallExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	PropertyCallExpEvalImpl::loadAttributes(loadHandler, attr_list);
}

void ModelPropertyCallExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	PropertyCallExpEvalImpl::loadNode(nodeName, loadHandler);
}

void ModelPropertyCallExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	PropertyCallExpEvalImpl::resolveReferences(featureID, references);
}

void ModelPropertyCallExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	PropertyCallExpEvalImpl::saveContent(saveHandler);
	
	OclExpEvalImpl::saveContent(saveHandler);
	
	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ModelPropertyCallExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ModelPropertyCallExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getModelPropertyCallExpEval_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ModelPropertyCallExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
	}
	return PropertyCallExpEvalImpl::eGet(featureID, resolve, coreType);
}

bool ModelPropertyCallExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
	}
	return PropertyCallExpEvalImpl::internalEIsSet(featureID);
}

bool ModelPropertyCallExpEvalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
	}

	return PropertyCallExpEvalImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ModelPropertyCallExpEvalImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// ocl::Evaluations::ModelPropertyCallExpEval::atPre() : bool: 2043150223
		case EvaluationsPackage::MODELPROPERTYCALLEXPEVAL_OPERATION_ATPRE:
		{
			result = eAny(this->atPre(),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = PropertyCallExpEvalImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<ocl::Evaluations::ModelPropertyCallExpEval> ModelPropertyCallExpEvalImpl::getThisModelPropertyCallExpEvalPtr() const
{
	return m_thisModelPropertyCallExpEvalPtr.lock();
}
void ModelPropertyCallExpEvalImpl::setThisModelPropertyCallExpEvalPtr(std::weak_ptr<ocl::Evaluations::ModelPropertyCallExpEval> thisModelPropertyCallExpEvalPtr)
{
	m_thisModelPropertyCallExpEvalPtr = thisModelPropertyCallExpEvalPtr;
	setThisPropertyCallExpEvalPtr(thisModelPropertyCallExpEvalPtr);
}


