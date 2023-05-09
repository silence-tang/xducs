// A.cpp : implementation file
//

#include "stdafx.h"
#include "Parent.h"
#include "A.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CA

IMPLEMENT_DYNCREATE(CA, CView)

CA::CA()
{
}

CA::~CA()
{
}


BEGIN_MESSAGE_MAP(CA, CView)
	//{{AFX_MSG_MAP(CA)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CA drawing

void CA::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CA diagnostics

#ifdef _DEBUG
void CA::AssertValid() const
{
	CView::AssertValid();
}

void CA::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CA message handlers

AFADVF CA::D()
{

}
