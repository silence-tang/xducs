// NamedChildDoc.cpp : implementation of the CNamedChildDoc class
//

#include "stdafx.h"
#include "NamedChild.h"

#include "NamedChildDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNamedChildDoc

IMPLEMENT_DYNCREATE(CNamedChildDoc, CDocument)

BEGIN_MESSAGE_MAP(CNamedChildDoc, CDocument)
	//{{AFX_MSG_MAP(CNamedChildDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNamedChildDoc construction/destruction

CNamedChildDoc::CNamedChildDoc()
{
	// TODO: add one-time construction code here

}

CNamedChildDoc::~CNamedChildDoc()
{
}

BOOL CNamedChildDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CNamedChildDoc serialization

void CNamedChildDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CNamedChildDoc diagnostics

#ifdef _DEBUG
void CNamedChildDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CNamedChildDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNamedChildDoc commands
