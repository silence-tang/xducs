// ParentView.h : interface of the CParentView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARENTVIEW_H__350CB978_CAA4_46A7_AA44_4765A7C2D13A__INCLUDED_)
#define AFX_PARENTVIEW_H__350CB978_CAA4_46A7_AA44_4765A7C2D13A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CParentView : public CView
{
protected: // create from serialization only
	CParentView();
	DECLARE_DYNCREATE(CParentView)

// Attributes
public:
	CParentDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CParentView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CParentView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CParentView)
	afx_msg void OnPipeCreate();
	afx_msg void OnReadPipe();
	afx_msg void OnWritePipe();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HANDLE hWrite;
	HANDLE hRead;
};

#ifndef _DEBUG  // debug version in ParentView.cpp
inline CParentDoc* CParentView::GetDocument()
   { return (CParentDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARENTVIEW_H__350CB978_CAA4_46A7_AA44_4765A7C2D13A__INCLUDED_)
