// Parent.h : main header file for the PARENT application
//

#if !defined(AFX_PARENT_H__D8CA4E98_483D_43FF_81C7_FD83BC70D8CE__INCLUDED_)
#define AFX_PARENT_H__D8CA4E98_483D_43FF_81C7_FD83BC70D8CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CParentApp:
// See Parent.cpp for the implementation of this class
//

class CParentApp : public CWinApp
{
public:
	CParentApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CParentApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CParentApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARENT_H__D8CA4E98_483D_43FF_81C7_FD83BC70D8CE__INCLUDED_)
