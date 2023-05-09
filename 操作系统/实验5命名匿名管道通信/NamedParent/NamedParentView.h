// NamedParentView.h : interface of the CNamedParentView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NAMEDPARENTVIEW_H__811A8D7B_51CB_4FF2_A7E7_888F6726B27F__INCLUDED_)
#define AFX_NAMEDPARENTVIEW_H__811A8D7B_51CB_4FF2_A7E7_888F6726B27F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CNamedParentView : public CView
{
protected: // create from serialization only
	CNamedParentView();
	DECLARE_DYNCREATE(CNamedParentView)

// Attributes
public:
	CNamedParentDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNamedParentView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
private:
	HANDLE hPipe;
	virtual ~CNamedParentView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNamedParentView)
	afx_msg void OnPipeCreate();
	afx_msg void OnPipeRead();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in NamedParentView.cpp
inline CNamedParentDoc* CNamedParentView::GetDocument()
   { return (CNamedParentDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NAMEDPARENTVIEW_H__811A8D7B_51CB_4FF2_A7E7_888F6726B27F__INCLUDED_)
