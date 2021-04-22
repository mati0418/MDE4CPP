//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef UML_PACKAGEPACKAGEIMPL_HPP
#define UML_PACKAGEPACKAGEIMPL_HPP

//*********************************
// generated Includes

//Model includes
#include "../Package.hpp"

#include "uml/impl/NamespaceImpl.hpp"
#include "uml/impl/PackageableElementImpl.hpp"
#include "uml/impl/TemplateableElementImpl.hpp"

//*********************************
namespace uml 
{
	class PackageImpl : virtual public NamespaceImpl, virtual public PackageableElementImpl, virtual public TemplateableElementImpl, virtual public Package 
	{
		public: 
			PackageImpl(const PackageImpl & obj);
			virtual std::shared_ptr<ecore::EObject> copy() const;
			PackageImpl& operator=(PackageImpl const&); 

		protected:
			friend class umlFactoryImpl;
			PackageImpl();
			virtual std::shared_ptr<Package> getThisPackagePtr() const;
			virtual void setThisPackagePtr(std::weak_ptr<Package> thisPackagePtr);

			//Additional constructors for the containments back reference
			PackageImpl(std::weak_ptr<uml::Namespace> par_namespace);
			//Additional constructors for the containments back reference
			PackageImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id);
			//Additional constructors for the containments back reference
			PackageImpl(std::weak_ptr<uml::Element> par_owner);
			//Additional constructors for the containments back reference
			//Additional constructors for the containments back reference
			PackageImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter);

		public:
			//destructor
			virtual ~PackageImpl();
			
			//*********************************
			// Operations
			//*********************************
			/*!
			The query allApplicableStereotypes() returns all the directly or indirectly owned stereotypes, including stereotypes contained in sub-profiles.
			result = (let ownedPackages : Bag(Package) = ownedMember->select(oclIsKindOf(Package))->collect(oclAsType(Package)) in
			 ownedStereotype->union(ownedPackages.allApplicableStereotypes())->flatten()->asSet()
			)
			<p>From package UML::Packages.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Stereotype> > allApplicableStereotypes() ;/*!
			Applies the current definition of the specified profile to this package and automatically applies required stereotypes in the profile to elements within this package's namespace hieararchy. If a different definition is already applied, automatically migrates any associated stereotype values on a "best effort" basis (matching classifiers and structural features by name).
			*/
			 
			virtual std::shared_ptr<Bag<ecore::EObject> > applyProfile(std::shared_ptr<uml::Profile> profile) ;/*!
			The query containingProfile() returns the closest profile directly or indirectly containing this package (or this package itself, if it is a profile).
			result = (if self.oclIsKindOf(Profile) then 
				self.oclAsType(Profile)
			else
				self.namespace.oclAsType(Package).containingProfile()
			endif)
			<p>From package UML::Packages.</p>
			*/
			 
			virtual std::shared_ptr<uml::Profile> containingProfile() ;/*!
			Creates a(n) (abstract) class with the specified name as an owned type of this package.
			*/
			 
			virtual std::shared_ptr<uml::Class> createOwnedClass(std::string name,bool isAbstract) ;/*!
			Creates a enumeration with the specified name as an owned type of this package.
			*/
			 
			virtual std::shared_ptr<uml::Enumeration> createOwnedEnumeration(std::string name) ;/*!
			Creates an interface with the specified name as an owned type of this package.
			*/
			 
			virtual std::shared_ptr<uml::Interface> createOwnedInterface(std::string name) ;/*!
			Creates a primitive type with the specified name as an owned type of this package.
			*/
			 
			virtual std::shared_ptr<uml::PrimitiveType> createOwnedPrimitiveType(std::string name) ;/*!
			Creates a(n) (abstract) stereotype with the specified name as an owned stereotype of this profile.
			*/
			 
			virtual std::shared_ptr<uml::Stereotype> createOwnedStereotype(std::string name,bool isAbstract) ;/*!
			If an element that is owned by a package has visibility, it is public or private.
			packagedElement->forAll(e | e.visibility<> null implies e.visibility = VisibilityKind::public or e.visibility = VisibilityKind::private)
			*/
			 
			virtual bool elements_public_or_private(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context) ;/*!
			Retrieves all the profiles that are applied to this package, including profiles applied to its nesting package(s).
			*/
			 
			virtual std::shared_ptr<Bag<uml::Profile> > getAllAppliedProfiles() ;/*!
			Retrieves all the profile applications for this package, including profile applications for its nesting package(s).
			*/
			 
			virtual std::shared_ptr<Bag<uml::ProfileApplication> > getAllProfileApplications() ;/*!
			Retrieves the profile with the specified qualified name that is applied to this package, or null if no such profile is applied.
			*/
			 
			virtual std::shared_ptr<uml::Profile> getAppliedProfile(std::string qualifiedName) ;/*!
			Retrieves the profile with the specified qualified name that is applied to this package or any of its nesting packages (if indicated), or null if no such profile is applied.
			*/
			 
			virtual std::shared_ptr<uml::Profile> getAppliedProfile(std::string qualifiedName,bool recurse) ;/*!
			Retrieves the profiles that are applied to this package.
			*/
			 
			virtual std::shared_ptr<Bag<uml::Profile> > getAppliedProfiles() ;/*!
			Derivation for Package::/nestedPackage
			result = (packagedElement->select(oclIsKindOf(Package))->collect(oclAsType(Package))->asSet())
			<p>From package UML::Packages.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Package> > getNestedPackages() ;/*!
			Derivation for Package::/ownedStereotype
			result = (packagedElement->select(oclIsKindOf(Stereotype))->collect(oclAsType(Stereotype))->asSet())
			<p>From package UML::Packages.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Stereotype> > getOwnedStereotypes() ;/*!
			Derivation for Package::/ownedType
			result = (packagedElement->select(oclIsKindOf(Type))->collect(oclAsType(Type))->asSet())
			<p>From package UML::Packages.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::Type> > getOwnedTypes() ;/*!
			Retrieves the application of the specified profile to this package, or null if no such profile is applied.
			*/
			 
			virtual std::shared_ptr<uml::ProfileApplication> getProfileApplication(std::shared_ptr<uml::Profile> profile) ;/*!
			Retrieves the application of the specified profile to this package or any of its nesting packages (if indicated), or null if no such profile is applied.
			*/
			 
			virtual std::shared_ptr<uml::ProfileApplication> getProfileApplication(std::shared_ptr<uml::Profile> profile,bool recurse) ;/*!
			Determines whether this package is a model library.
			*/
			 
			virtual bool isModelLibrary() ;/*!
			Determines whether the specified profile is applied to this package.
			*/
			 
			virtual bool isProfileApplied(std::shared_ptr<uml::Profile> profile) ;/*!
			The query makesVisible() defines whether a Package makes an element visible outside itself. Elements with no visibility and elements with public visibility are made visible.
			member->includes(el)
			result = (ownedMember->includes(el) or
			(elementImport->select(ei|ei.importedElement = VisibilityKind::public)->collect(importedElement.oclAsType(NamedElement))->includes(el)) or
			(packageImport->select(visibility = VisibilityKind::public)->collect(importedPackage.member->includes(el))->notEmpty()))
			<p>From package UML::Packages.</p>
			*/
			 
			virtual bool makesVisible(std::shared_ptr<uml::NamedElement> el) ;/*!
			Unapplies the specified profile from this package and automatically unapplies stereotypes in the profile from elements within this package's namespace hieararchy.
			*/
			 
			virtual std::shared_ptr<Bag<ecore::EObject> > unapplyProfile(std::shared_ptr<uml::Profile> profile) ;/*!
			The query visibleMembers() defines which members of a Package can be accessed outside it.
			result = (member->select( m | m.oclIsKindOf(PackageableElement) and self.makesVisible(m))->collect(oclAsType(PackageableElement))->asSet())
			<p>From package UML::Packages.</p>
			*/
			 
			virtual std::shared_ptr<Bag<uml::PackageableElement> > visibleMembers() ;
			
			//*********************************
			// Attributes Getter Setter
			//*********************************
			/*!
			Provides an identifier for the package that can be used for many purposes. A URI is the universally unique identification of the package following the IETF URI specification, RFC 2396 http://www.ietf.org/rfc/rfc2396.txt and it must comply with those syntax rules.
			<p>From package UML::Packages.</p>
			*/
			 
			virtual std::string getURI() const ;
			/*!
			Provides an identifier for the package that can be used for many purposes. A URI is the universally unique identification of the package following the IETF URI specification, RFC 2396 http://www.ietf.org/rfc/rfc2396.txt and it must comply with those syntax rules.
			<p>From package UML::Packages.</p>
			*/
			 
			virtual void setURI (std::string _URI);
			
			
			//*********************************
			// Reference
			//*********************************
			/*!
			References the packaged elements that are Packages.
			<p>From package UML::Packages.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Package, uml::PackageableElement /*Subset does not reference a union*/>> getNestedPackage() const ;
			
			/*!
			References the Package that owns this Package.
			<p>From package UML::Packages.</p>
			*/
			
			virtual std::weak_ptr<uml::Package> getNestingPackage() const ;
			/*!
			References the Package that owns this Package.
			<p>From package UML::Packages.</p>
			*/
			
			virtual void setNestingPackage(std::weak_ptr<uml::Package>) ;
			/*!
			References the Stereotypes that are owned by the Package.
			<p>From package UML::Packages.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Stereotype, uml::PackageableElement /*Subset does not reference a union*/>> getOwnedStereotype() const ;
			
			/*!
			References the packaged elements that are Types.
			<p>From package UML::Packages.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::Type, uml::PackageableElement /*Subset does not reference a union*/>> getOwnedType() const ;
			
			/*!
			References the PackageMerges that are owned by this Package.
			<p>From package UML::Packages.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::PackageMerge, uml::Element>> getPackageMerge() const ;
			
			/*!
			Specifies the packageable elements that are owned by this Package.
			<p>From package UML::Packages.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::PackageableElement, uml::NamedElement>> getPackagedElement() const ;
			
			/*!
			References the ProfileApplications that indicate which profiles have been applied to the Package.
			<p>From package UML::Packages.</p>
			*/
			
			virtual std::shared_ptr<Subset<uml::ProfileApplication, uml::Element>> getProfileApplication() const ;
			
			
			
			//*********************************
			// Union Getter
			//*********************************
			/*!
			A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::NamedElement>> getMember() const ;/*!
			Specifies the Namespace that owns the NamedElement.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Namespace> getNamespace() const ;/*!
			The Elements owned by this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<Union<uml::Element>> getOwnedElement() const ;/*!
			A collection of NamedElements owned by the Namespace.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> getOwnedMember() const ;/*!
			The Element that owns this Element.
			<p>From package UML::CommonStructure.</p>
			*/
			
			virtual std::weak_ptr<uml::Element> getOwner() const ; 
			 
			//*********************************
			// Structural Feature Getter/Setter
			//*********************************

			virtual std::shared_ptr<ecore::EObject> eContainer() const ; 
			
			//*********************************
			// Persistence Functions
			//*********************************
			virtual void load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler) ;
			virtual void loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list);
			virtual void loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler);
			
			virtual void resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references) ;
			virtual void save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const ;
			virtual void saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const;
			

		protected:
			virtual std::shared_ptr<ecore::EClass> eStaticClass() const;
			virtual Any eGet(int featureID, bool resolve, bool coreType) const ;
			virtual bool internalEIsSet(int featureID) const ;
			virtual bool eSet(int featureID, Any newValue) ;
			virtual Any eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments) ;

		private:
			std::weak_ptr<Package> m_thisPackagePtr;
	};
}
#endif /* end of include guard: UML_PACKAGEPACKAGEIMPL_HPP */
