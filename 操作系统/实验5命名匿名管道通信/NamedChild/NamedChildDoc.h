// NamedChildDoc.h : interface of the CNamedChildDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NAMEDCHILDDOC_H__775CE385_C7F9_4BF3_9759_A759BC70C7A1__INCLUDED_)
#define AFX_NAMEDCHILDDOC_H__775CE385_C7F9_4BF3_9759_A759BC70C7A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CNamedChildDoc : public CDocument
{
protected: // create from serialization only
	CNamedChildDoc();
	DECLARE_DYNCREATE(CNamedChildDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNamedChildDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNamedChildDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNamedChildDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NAMEDCHILDDOC_H__775CE385_C7F9_4BF3_9759_A759BC70C7A1__INCLUDED_)
