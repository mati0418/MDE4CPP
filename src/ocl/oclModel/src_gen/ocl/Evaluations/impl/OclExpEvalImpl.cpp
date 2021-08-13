#include "ocl/Evaluations/impl/OclExpEvalImpl.hpp"

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



#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation
#include "fUML/fUMLFactory.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ocl/Evaluations/EvaluationsFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"
#include "uml/umlFactory.hpp"
#include "fUML/Semantics/Values/ValuesFactory.hpp"
#include "fUML/Semantics/Loci/LociFactory.hpp"


#include "ocl/Evaluations/EvalEnvironment.hpp"
#include "fUML/Semantics/Values/Evaluation.hpp"
#include "fUML/Semantics/Loci/Locus.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "fUML/Semantics/Values/Value.hpp"
#include "uml/ValueSpecification.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Evaluations/EvaluationsPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "fUML/Semantics/Loci/LociPackage.hpp"
#include "fUML/Semantics/Values/ValuesPackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Evaluations;

//*********************************
// Constructor / Destructor
//*********************************
OclExpEvalImpl::OclExpEvalImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

OclExpEvalImpl::~OclExpEvalImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OclExpEval "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


OclExpEvalImpl::OclExpEvalImpl(const OclExpEvalImpl & obj): OclExpEvalImpl()
{
	*this = obj;
}

OclExpEvalImpl& OclExpEvalImpl::operator=(const OclExpEvalImpl & obj)
{
	//call overloaded =Operator for each base class
	fUML::Semantics::Values::EvaluationImpl::operator=(obj);
	OclExpEval::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OclExpEval "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_beforeEnvironment  = obj.getBeforeEnvironment();
	m_environment  = obj.getEnvironment();
	m_model  = obj.getModel();
	m_resultValue  = obj.getResultValue();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> OclExpEvalImpl::copy() const
{
	std::shared_ptr<OclExpEvalImpl> element(new OclExpEvalImpl());
	*element =(*this);
	element->setThisOclExpEvalPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> OclExpEvalImpl::eStaticClass() const
{
	return ocl::Evaluations::EvaluationsPackage::eInstance()->getOclExpEval_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
/*
Getter & Setter for reference beforeEnvironment
*/
std::shared_ptr<ocl::Evaluations::EvalEnvironment> OclExpEvalImpl::getBeforeEnvironment() const
{

    return m_beforeEnvironment;
}
void OclExpEvalImpl::setBeforeEnvironment(std::shared_ptr<ocl::Evaluations::EvalEnvironment> _beforeEnvironment)
{
    m_beforeEnvironment = _beforeEnvironment;
	
}


/*
Getter & Setter for reference environment
*/
std::shared_ptr<ocl::Evaluations::EvalEnvironment> OclExpEvalImpl::getEnvironment() const
{
//assert(m_environment);
    return m_environment;
}
void OclExpEvalImpl::setEnvironment(std::shared_ptr<ocl::Evaluations::EvalEnvironment> _environment)
{
    m_environment = _environment;
	
}


/*
Getter & Setter for reference model
*/
std::shared_ptr<ocl::Expressions::OclExpression> OclExpEvalImpl::getModel() const
{
//assert(m_model);
    return m_model;
}
void OclExpEvalImpl::setModel(std::shared_ptr<ocl::Expressions::OclExpression> _model)
{
    m_model = _model;
	
}


/*
Getter & Setter for reference resultValue
*/
std::shared_ptr<fUML::Semantics::Values::Value> OclExpEvalImpl::getResultValue() const
{
//assert(m_resultValue);
    return m_resultValue;
}
void OclExpEvalImpl::setResultValue(std::shared_ptr<fUML::Semantics::Values::Value> _resultValue)
{
    m_resultValue = _resultValue;
	
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<OclExpEval> OclExpEvalImpl::getThisOclExpEvalPtr() const
{
	return m_thisOclExpEvalPtr.lock();
}
void OclExpEvalImpl::setThisOclExpEvalPtr(std::weak_ptr<OclExpEval> thisOclExpEvalPtr)
{
	m_thisOclExpEvalPtr = thisOclExpEvalPtr;
	setThisEvaluationPtr(thisOclExpEvalPtr);
}
std::shared_ptr<ecore::EObject> OclExpEvalImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any OclExpEvalImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_BEFOREENVIRONMENT:
			{
				std::shared_ptr<ecore::EObject> returnValue=getBeforeEnvironment();
				return eAny(returnValue); //593
			}
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_ENVIRONMENT:
			{
				std::shared_ptr<ecore::EObject> returnValue=getEnvironment();
				return eAny(returnValue); //592
			}
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_MODEL:
			{
				std::shared_ptr<ecore::EObject> returnValue=getModel();
				return eAny(returnValue); //595
			}
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_RESULTVALUE:
			{
				std::shared_ptr<ecore::EObject> returnValue=getResultValue();
				return eAny(returnValue); //594
			}
	}
	return fUML::Semantics::Values::EvaluationImpl::eGet(featureID, resolve, coreType);
}
bool OclExpEvalImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_BEFOREENVIRONMENT:
			return getBeforeEnvironment() != nullptr; //593
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_ENVIRONMENT:
			return getEnvironment() != nullptr; //592
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_MODEL:
			return getModel() != nullptr; //595
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_RESULTVALUE:
			return getResultValue() != nullptr; //594
	}
	return fUML::Semantics::Values::EvaluationImpl::internalEIsSet(featureID);
}
bool OclExpEvalImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_BEFOREENVIRONMENT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Evaluations::EvalEnvironment> _beforeEnvironment = std::dynamic_pointer_cast<ocl::Evaluations::EvalEnvironment>(_temp);
			setBeforeEnvironment(_beforeEnvironment); //593
			return true;
		}
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_ENVIRONMENT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Evaluations::EvalEnvironment> _environment = std::dynamic_pointer_cast<ocl::Evaluations::EvalEnvironment>(_temp);
			setEnvironment(_environment); //592
			return true;
		}
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_MODEL:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::OclExpression> _model = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(_temp);
			setModel(_model); //595
			return true;
		}
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_RESULTVALUE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<fUML::Semantics::Values::Value> _resultValue = std::dynamic_pointer_cast<fUML::Semantics::Values::Value>(_temp);
			setResultValue(_resultValue); //594
			return true;
		}
	}

	return fUML::Semantics::Values::EvaluationImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any OclExpEvalImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = fUML::Semantics::Values::EvaluationImpl::eInvoke(operationID, arguments);
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
void OclExpEvalImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OclExpEvalImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("beforeEnvironment");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("beforeEnvironment")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("environment");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("environment")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("model");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("model")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("resultValue");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("resultValue")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
	catch (...) 
	{
		std::cout << "| ERROR    | " <<  "Exception occurred" << std::endl;
	}

	fUML::Semantics::Values::EvaluationImpl::loadAttributes(loadHandler, attr_list);
}

void OclExpEvalImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	fUML::Semantics::Values::EvaluationImpl::loadNode(nodeName, loadHandler);
}

void OclExpEvalImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_BEFOREENVIRONMENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::EvalEnvironment> _beforeEnvironment = std::dynamic_pointer_cast<ocl::Evaluations::EvalEnvironment>( references.front() );
				setBeforeEnvironment(_beforeEnvironment);
			}
			
			return;
		}

		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_ENVIRONMENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Evaluations::EvalEnvironment> _environment = std::dynamic_pointer_cast<ocl::Evaluations::EvalEnvironment>( references.front() );
				setEnvironment(_environment);
			}
			
			return;
		}

		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_MODEL:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<ocl::Expressions::OclExpression> _model = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>( references.front() );
				setModel(_model);
			}
			
			return;
		}

		case ocl::Evaluations::EvaluationsPackage::OCLEXPEVAL_ATTRIBUTE_RESULTVALUE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<fUML::Semantics::Values::Value> _resultValue = std::dynamic_pointer_cast<fUML::Semantics::Values::Value>( references.front() );
				setResultValue(_resultValue);
			}
			
			return;
		}
	}
	fUML::Semantics::Values::EvaluationImpl::resolveReferences(featureID, references);
}

void OclExpEvalImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	fUML::Semantics::Values::EvaluationImpl::saveContent(saveHandler);
	
	fUML::Semantics::Loci::SemanticVisitorImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void OclExpEvalImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Evaluations::EvaluationsPackage> package = ocl::Evaluations::EvaluationsPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getBeforeEnvironment(), "beforeEnvironment", getBeforeEnvironment()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getEvalEnvironment_Class()); 
		saveHandler->addReference(this->getEnvironment(), "environment", getEnvironment()->eClass() != ocl::Evaluations::EvaluationsPackage::eInstance()->getEvalEnvironment_Class()); 
		saveHandler->addReference(this->getModel(), "model", getModel()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Class()); 
		saveHandler->addReference(this->getResultValue(), "resultValue", getResultValue()->eClass() != fUML::Semantics::Values::ValuesPackage::eInstance()->getValue_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

