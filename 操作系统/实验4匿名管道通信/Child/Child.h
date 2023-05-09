// Child.h : main header file for the CHILD application
//

#if !defined(AFX_CHILD_H__27D47415_481C_4E9A_91A2_C6EA674D2120__INCLUDED_)
#define AFX_CHILD_H__27D47415_481C_4E9A_91A2_C6EA674D2120__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CChildApp:
// See Child.cpp for the implementation of this class
//

class CChildApp : public CWinApp
{
public:
	CChildApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CChildApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILD_H__27D47415_481C_4E9A_91A2_C6EA674D2120__INCLUDED_)
