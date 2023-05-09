// NamedChildView.h : interface of the CNamedChildView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NAMEDCHILDVIEW_H__58FCDEE0_023B_4A10_B884_EFB0817E2523__INCLUDED_)
#define AFX_NAMEDCHILDVIEW_H__58FCDEE0_023B_4A10_B884_EFB0817E2523__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CNamedChildView : public CView
{
protected: // create from serialization only
	CNamedChildView();
	DECLARE_DYNCREATE(CNamedChildView)

// Attributes
public:
	CNamedChildDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNamedChildView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNamedChildView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNamedChildView)
	afx_msg void OnPipeWrite();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HANDLE hWrite;
};

#ifndef _DEBUG  // debug version in NamedChildView.cpp
inline CNamedChildDoc* CNamedChildView::GetDocument()
   { return (CNamedChildDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NAMEDCHILDVIEW_H__58FCDEE0_023B_4A10_B884_EFB0817E2523__INCLUDED_)
