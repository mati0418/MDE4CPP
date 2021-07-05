#include "ocl/Expressions/impl/ExpressionInOclImpl.hpp"

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

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "ecore/EcoreFactory.hpp"
#include "ocl/Expressions/ExpressionsFactory.hpp"


#include "ecore/EAnnotation.hpp"
#include "ecore/EClassifier.hpp"
#include "ecore/EGenericType.hpp"
#include "ecore/ETypedElement.hpp"
#include "ocl/Expressions/OclExpression.hpp"
#include "ocl/Expressions/Variable.hpp"

//Factories an Package includes
#include "ocl/oclPackage.hpp"
#include "ocl/Expressions/ExpressionsPackage.hpp"
#include "ecore/ecorePackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace ocl::Expressions;

//*********************************
// Constructor / Destructor
//*********************************
ExpressionInOclImpl::ExpressionInOclImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ExpressionInOclImpl::~ExpressionInOclImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExpressionInOcl "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


ExpressionInOclImpl::ExpressionInOclImpl(const ExpressionInOclImpl & obj): ExpressionInOclImpl()
{
	*this = obj;
}

ExpressionInOclImpl& ExpressionInOclImpl::operator=(const ExpressionInOclImpl & obj)
{
	//call overloaded =Operator for each base class
	ecore::ETypedElementImpl::operator=(obj);
	ExpressionInOcl::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExpressionInOcl "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	if(obj.getBodyExpression()!=nullptr)
	{
		m_bodyExpression = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(obj.getBodyExpression()->copy());
	}
	if(obj.getContextVariable()!=nullptr)
	{
		m_contextVariable = std::dynamic_pointer_cast<ocl::Expressions::Variable>(obj.getContextVariable()->copy());
	}
	std::shared_ptr<Bag<ocl::Expressions::Variable>> parameterVariableContainer = getParameterVariable();
	if(nullptr != parameterVariableContainer )
	{
		int size = parameterVariableContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _parameterVariable=(*parameterVariableContainer)[i];
			if(nullptr != _parameterVariable)
			{
				parameterVariableContainer->push_back(std::dynamic_pointer_cast<ocl::Expressions::Variable>(_parameterVariable->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container parameterVariable."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr parameterVariable."<< std::endl;)
	}
	if(obj.getResultVariable()!=nullptr)
	{
		m_resultVariable = std::dynamic_pointer_cast<ocl::Expressions::Variable>(obj.getResultVariable()->copy());
	}
	
	
	
	
	return *this;
}

std::shared_ptr<ecore::EObject> ExpressionInOclImpl::copy() const
{
	std::shared_ptr<ExpressionInOclImpl> element(new ExpressionInOclImpl());
	*element =(*this);
	element->setThisExpressionInOclPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ExpressionInOclImpl::eStaticClass() const
{
	return ocl::Expressions::ExpressionsPackage::eInstance()->getExpressionInOcl_Class();
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
Getter & Setter for reference bodyExpression
*/
std::shared_ptr<ocl::Expressions::OclExpression> ExpressionInOclImpl::getBodyExpression() const
{
//assert(m_bodyExpression);
    return m_bodyExpression;
}
void ExpressionInOclImpl::setBodyExpression(std::shared_ptr<ocl::Expressions::OclExpression> _bodyExpression)
{
    m_bodyExpression = _bodyExpression;
}


/*
Getter & Setter for reference contextVariable
*/
std::shared_ptr<ocl::Expressions::Variable> ExpressionInOclImpl::getContextVariable() const
{

    return m_contextVariable;
}
void ExpressionInOclImpl::setContextVariable(std::shared_ptr<ocl::Expressions::Variable> _contextVariable)
{
    m_contextVariable = _contextVariable;
}


/*
Getter & Setter for reference parameterVariable
*/
std::shared_ptr<Bag<ocl::Expressions::Variable>> ExpressionInOclImpl::getParameterVariable() const
{
	if(m_parameterVariable == nullptr)
	{
		m_parameterVariable.reset(new Bag<ocl::Expressions::Variable>());
		
		
	}

    return m_parameterVariable;
}



/*
Getter & Setter for reference resultVariable
*/
std::shared_ptr<ocl::Expressions::Variable> ExpressionInOclImpl::getResultVariable() const
{

    return m_resultVariable;
}
void ExpressionInOclImpl::setResultVariable(std::shared_ptr<ocl::Expressions::Variable> _resultVariable)
{
    m_resultVariable = _resultVariable;
}


//*********************************
// Union Getter
//*********************************



std::shared_ptr<ExpressionInOcl> ExpressionInOclImpl::getThisExpressionInOclPtr() const
{
	return m_thisExpressionInOclPtr.lock();
}
void ExpressionInOclImpl::setThisExpressionInOclPtr(std::weak_ptr<ExpressionInOcl> thisExpressionInOclPtr)
{
	m_thisExpressionInOclPtr = thisExpressionInOclPtr;
	setThisETypedElementPtr(thisExpressionInOclPtr);
}
std::shared_ptr<ecore::EObject> ExpressionInOclImpl::eContainer() const
{
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ExpressionInOclImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:
			return eAny(getBodyExpression()); //2710
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:
			return eAny(getContextVariable()); //2711
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<ocl::Expressions::Variable>::iterator iter = m_parameterVariable->begin();
			Bag<ocl::Expressions::Variable>::iterator end = m_parameterVariable->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //2713			
		}
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:
			return eAny(getResultVariable()); //2712
	}
	return ecore::ETypedElementImpl::eGet(featureID, resolve, coreType);
}
bool ExpressionInOclImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:
			return getBodyExpression() != nullptr; //2710
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:
			return getContextVariable() != nullptr; //2711
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:
			return getParameterVariable() != nullptr; //2713
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:
			return getResultVariable() != nullptr; //2712
	}
	return ecore::ETypedElementImpl::internalEIsSet(featureID);
}
bool ExpressionInOclImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_BODYEXPRESSION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::OclExpression> _bodyExpression = std::dynamic_pointer_cast<ocl::Expressions::OclExpression>(_temp);
			setBodyExpression(_bodyExpression); //2710
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_CONTEXTVARIABLE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::Variable> _contextVariable = std::dynamic_pointer_cast<ocl::Expressions::Variable>(_temp);
			setContextVariable(_contextVariable); //2711
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_PARAMETERVARIABLE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<ocl::Expressions::Variable>> parameterVariableList(new Bag<ocl::Expressions::Variable>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				parameterVariableList->add(std::dynamic_pointer_cast<ocl::Expressions::Variable>(*iter));
				iter++;
			}
			
			Bag<ocl::Expressions::Variable>::iterator iterParameterVariable = m_parameterVariable->begin();
			Bag<ocl::Expressions::Variable>::iterator endParameterVariable = m_parameterVariable->end();
			while (iterParameterVariable != endParameterVariable)
			{
				if (parameterVariableList->find(*iterParameterVariable) == -1)
				{
					m_parameterVariable->erase(*iterParameterVariable);
				}
				iterParameterVariable++;
			}
 
			iterParameterVariable = parameterVariableList->begin();
			endParameterVariable = parameterVariableList->end();
			while (iterParameterVariable != endParameterVariable)
			{
				if (m_parameterVariable->find(*iterParameterVariable) == -1)
				{
					m_parameterVariable->add(*iterParameterVariable);
				}
				iterParameterVariable++;			
			}
			return true;
		}
		case ocl::Expressions::ExpressionsPackage::EXPRESSIONINOCL_ATTRIBUTE_RESULTVARIABLE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<ocl::Expressions::Variable> _resultVariable = std::dynamic_pointer_cast<ocl::Expressions::Variable>(_temp);
			setResultVariable(_resultVariable); //2712
			return true;
		}
	}

	return ecore::ETypedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ExpressionInOclImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ecore::ETypedElementImpl::eInvoke(operationID, arguments);
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
void ExpressionInOclImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ExpressionInOclImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ecore::ETypedElementImpl::loadAttributes(loadHandler, attr_list);
}

void ExpressionInOclImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("bodyExpression") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChild(this->getBodyExpression()); 

			return; 
		}

		if ( nodeName.compare("contextVariable") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Variable";
			}
			loadHandler->handleChild(this->getContextVariable()); 

			return; 
		}

		if ( nodeName.compare("parameterVariable") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Variable";
			}
			loadHandler->handleChildContainer<ocl::Expressions::Variable>(this->getParameterVariable());  

			return; 
		}

		if ( nodeName.compare("resultVariable") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Variable";
			}
			loadHandler->handleChild(this->getResultVariable()); 

			return; 
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
	//load BasePackage Nodes
	ecore::ETypedElementImpl::loadNode(nodeName, loadHandler);
}

void ExpressionInOclImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ecore::ETypedElementImpl::resolveReferences(featureID, references);
}

void ExpressionInOclImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ecore::ETypedElementImpl::saveContent(saveHandler);
	
	ecore::ENamedElementImpl::saveContent(saveHandler);
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void ExpressionInOclImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<ocl::Expressions::ExpressionsPackage> package = ocl::Expressions::ExpressionsPackage::eInstance();
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'bodyExpression'

		saveHandler->addReference(this->getBodyExpression(), "bodyExpression", getBodyExpression()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getOclExpression_Class());

		// Save 'contextVariable'

		saveHandler->addReference(this->getContextVariable(), "contextVariable", getContextVariable()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getVariable_Class());

		// Save 'parameterVariable'

		saveHandler->addReferences<ocl::Expressions::Variable>("parameterVariable", this->getParameterVariable());

		// Save 'resultVariable'

		saveHandler->addReference(this->getResultVariable(), "resultVariable", getResultVariable()->eClass() != ocl::Expressions::ExpressionsPackage::eInstance()->getVariable_Class());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}
