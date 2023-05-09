// NamedChildView.cpp : implementation of the CNamedChildView class
//

#include "stdafx.h"
#include "NamedChild.h"

#include "NamedChildDoc.h"
#include "NamedChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNamedChildView

IMPLEMENT_DYNCREATE(CNamedChildView, CView)

BEGIN_MESSAGE_MAP(CNamedChildView, CView)
	//{{AFX_MSG_MAP(CNamedChildView)
	ON_COMMAND(ID_PIPEWRITE, OnPipeWrite)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNamedChildView construction/destruction

CNamedChildView::CNamedChildView()
{
	// TODO: add construction code here
	hWrite = NULL;
}

CNamedChildView::~CNamedChildView()
{
	if(hWrite) {
		CloseHandle(hWrite);
	}
}

BOOL CNamedChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CNamedChildView drawing

void CNamedChildView::OnDraw(CDC* pDC)
{
	CNamedChildDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CNamedChildView printing

BOOL CNamedChildView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CNamedChildView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CNamedChildView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CNamedChildView diagnostics

#ifdef _DEBUG
void CNamedChildView::AssertValid() const
{
	CView::AssertValid();
}

void CNamedChildView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNamedChildDoc* CNamedChildView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNamedChildDoc)));
	return (CNamedChildDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNamedChildView message handlers

void CNamedChildView::OnPipeWrite() 
{
	// TODO: Add your command handler code here
	char buf[]="命名管道测试程序";
	DWORD dwWrite;
	if(!WriteFile(hWrite,buf,strlen(buf)+1,&dwWrite,NULL))
	{
		MessageBox("写入数据失败！");
		return;
	}
}

void CNamedChildView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	hWrite = CreateFile("\\\\.\\pipe\\MyPipe",GENERIC_READ| GENERIC_WRITE,
                 0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	if(INVALID_HANDLE_VALUE == hWrite)
	{
		MessageBox("打开命名管道失败！");
		hWrite = NULL;
		return;
	}
}
