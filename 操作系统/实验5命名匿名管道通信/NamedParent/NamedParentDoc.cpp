// NamedParentDoc.cpp : implementation of the CNamedParentDoc class
//

#include "stdafx.h"
#include "NamedParent.h"

#include "NamedParentDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNamedParentDoc

IMPLEMENT_DYNCREATE(CNamedParentDoc, CDocument)

BEGIN_MESSAGE_MAP(CNamedParentDoc, CDocument)
	//{{AFX_MSG_MAP(CNamedParentDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNamedParentDoc construction/destruction

CNamedParentDoc::CNamedParentDoc()
{
	// TODO: add one-time construction code here

}

CNamedParentDoc::~CNamedParentDoc()
{
}

BOOL CNamedParentDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CNamedParentDoc serialization

void CNamedParentDoc::Serialize(CArchive& ar)
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
// CNamedParentDoc diagnostics

#ifdef _DEBUG
void CNamedParentDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CNamedParentDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNamedParentDoc commands
