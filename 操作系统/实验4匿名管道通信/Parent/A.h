#if !defined(AFX_A_H__890A044D_9AFA_47F7_99D8_CF6CADFFBB99__INCLUDED_)
#define AFX_A_H__890A044D_9AFA_47F7_99D8_CF6CADFFBB99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// A.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CA view

class CA : public CView
{
protected:
	CA();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CA)

// Attributes
public:

// Operations
public:
	AFADVF D();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CA)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CA();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	HANDLE hRead;
	//{{AFX_MSG(CA)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_A_H__890A044D_9AFA_47F7_99D8_CF6CADFFBB99__INCLUDED_)
