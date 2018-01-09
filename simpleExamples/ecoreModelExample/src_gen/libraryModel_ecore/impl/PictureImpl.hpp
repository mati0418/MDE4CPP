//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef LIBRARYMODEL_ECORE_PICTUREPICTUREIMPL_HPP
#define LIBRARYMODEL_ECORE_PICTUREPICTUREIMPL_HPP

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

//*********************************
// generated Includes

//Model includes
#include "../Picture.hpp"

#include "impl/NamedElementImpl.hpp"

#include "SubsetUnion.hpp"



//*********************************
namespace libraryModel_ecore 
{
	class PictureImpl :virtual public NamedElementImpl, virtual public Picture 
	{
		public: 
			PictureImpl(const PictureImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;

		private:    
			PictureImpl& operator=(PictureImpl const&) = delete;

		protected:
			friend class LibraryModel_ecoreFactoryImpl;
			PictureImpl();

			//Additional constructors for the containments back reference
			PictureImpl(std::weak_ptr<libraryModel_ecore::Book > par_book);




		public:
			//destructor
			virtual ~PictureImpl();
			
			//*********************************
			// Operations
			//*********************************
			
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			 */ 
			virtual int getPageNumber() const ;
			
			/*!
			 */ 
			virtual void setPageNumber (int _pageNumber); 
			
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			 */
			virtual std::weak_ptr<libraryModel_ecore::Book > getBook() const ;
			
			/*!
			 */
			virtual void setBook(std::shared_ptr<libraryModel_ecore::Book> _book_book) ;
							
			
			//*********************************
			// Union Getter
			//*********************************
			 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************
			
			virtual boost::any eGet(int featureID, bool resolve, bool coreType) const ;
			
		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
	};
}
#endif /* end of include guard: LIBRARYMODEL_ECORE_PICTUREPICTUREIMPL_HPP */

