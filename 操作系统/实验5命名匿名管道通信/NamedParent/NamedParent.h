// NamedParent.h : main header file for the NAMEDPARENT application
//

#if !defined(AFX_NAMEDPARENT_H__7EE93384_B2B9_420A_A57A_69C4E619B536__INCLUDED_)
#define AFX_NAMEDPARENT_H__7EE93384_B2B9_420A_A57A_69C4E619B536__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CNamedParentApp:
// See NamedParent.cpp for the implementation of this class
//

class CNamedParentApp : public CWinApp
{
public:
	CNamedParentApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNamedParentApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CNamedParentApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NAMEDPARENT_H__7EE93384_B2B9_420A_A57A_69C4E619B536__INCLUDED_)
