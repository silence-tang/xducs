// NamedParentDoc.h : interface of the CNamedParentDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NAMEDPARENTDOC_H__8EAAF2E8_2312_47FF_98CB_559BAF5D2196__INCLUDED_)
#define AFX_NAMEDPARENTDOC_H__8EAAF2E8_2312_47FF_98CB_559BAF5D2196__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CNamedParentDoc : public CDocument
{
protected: // create from serialization only
	CNamedParentDoc();
	DECLARE_DYNCREATE(CNamedParentDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNamedParentDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNamedParentDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNamedParentDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NAMEDPARENTDOC_H__8EAAF2E8_2312_47FF_98CB_559BAF5D2196__INCLUDED_)
