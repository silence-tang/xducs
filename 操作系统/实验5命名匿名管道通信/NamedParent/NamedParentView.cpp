// NamedParentView.cpp : implementation of the CNamedParentView class
//

#include "stdafx.h"
#include "NamedParent.h"

#include "NamedParentDoc.h"
#include "NamedParentView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNamedParentView

IMPLEMENT_DYNCREATE(CNamedParentView, CView)

BEGIN_MESSAGE_MAP(CNamedParentView, CView)
	//{{AFX_MSG_MAP(CNamedParentView)
	ON_COMMAND(ID_PIPECREATE, OnPipeCreate)
	ON_COMMAND(ID_PIPEREAD, OnPipeRead)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNamedParentView construction/destruction

CNamedParentView::CNamedParentView()
{
	// TODO: add construction code here
	hPipe = NULL;
}

CNamedParentView::~CNamedParentView()
{
	if(hPipe) {
		CloseHandle(hPipe);
	}
}

BOOL CNamedParentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CNamedParentView drawing

void CNamedParentView::OnDraw(CDC* pDC)
{
	CNamedParentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CNamedParentView printing

BOOL CNamedParentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CNamedParentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CNamedParentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CNamedParentView diagnostics

#ifdef _DEBUG
void CNamedParentView::AssertValid() const
{
	CView::AssertValid();
}

void CNamedParentView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNamedParentDoc* CNamedParentView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNamedParentDoc)));
	return (CNamedParentDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNamedParentView message handlers

void CNamedParentView::OnPipeCreate()
{
	// TODO: Add your command handler code here
	//dual connected mode
	hPipe = CreateNamedPipe("\\\\.\\pipe\\MyPipe",PIPE_ACCESS_DUPLEX | FILE_FLAG_OVERLAPPED,
			0,1,1024,1024,0,NULL);
	STARTUPINFO sui;
	PROCESS_INFORMATION pi;
	ZeroMemory(&sui,sizeof(sui));
	ZeroMemory(&pi,sizeof(pi));
	sui.cb = sizeof(STARTUPINFO);
	if(INVALID_HANDLE_VALUE == hPipe)
	{
		MessageBox("创建命名管道失败");
		hPipe = NULL;
		return;
	}
	if(!CreateProcess("C:\\Users\\HP\\Desktop\\OS实验\\实验5 命名匿名管道通信\\NamedChild\\Debug\\NamedChild.exe",NULL,NULL,NULL,
		TRUE,0,NULL,NULL,&sui,&pi))
	{
		CloseHandle(hPipe);
		hPipe = NULL;
		MessageBox("创建子进程失败");
		return;
	} 
	else
	{
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
}

void CNamedParentView::OnPipeRead()
{
	// TODO: Add your command handler code here
	char buf[100];
	DWORD dwRead;
    if(!ReadFile(hPipe,buf,100,&dwRead,NULL))
	{
		MessageBox("读取数据失败！");
		return;
    }
	MessageBox(buf);
}
