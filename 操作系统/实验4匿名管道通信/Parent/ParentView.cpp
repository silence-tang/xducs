// ParentView.cpp : implementation of the CParentView class
//

#include "stdafx.h"
#include "Parent.h"

#include "ParentDoc.h"
#include "ParentView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CParentView

IMPLEMENT_DYNCREATE(CParentView, CView)

BEGIN_MESSAGE_MAP(CParentView, CView)
	//{{AFX_MSG_MAP(CParentView)
	ON_COMMAND(ID_PIPECREATE, OnPipeCreate)
	ON_COMMAND(ID_READPIPE, OnReadPipe)
	ON_COMMAND(ID_WRITEPIPE, OnWritePipe)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CParentView construction/destruction

CParentView::CParentView()
{
	// TODO: add construction code here
	hRead= NULL;
    hWrite= NULL;
}

CParentView::~CParentView()
{
	if(hRead)
		CloseHandle(hRead);
    if(hWrite)
		CloseHandle(hWrite);
}

BOOL CParentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CParentView drawing

void CParentView::OnDraw(CDC* pDC)
{
	CParentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CParentView printing

BOOL CParentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CParentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CParentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CParentView diagnostics

#ifdef _DEBUG
void CParentView::AssertValid() const
{
	CView::AssertValid();
}

void CParentView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CParentDoc* CParentView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CParentDoc)));
	return (CParentDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CParentView message handlers

void CParentView::OnPipeCreate() 
{
	// TODO: Add your command handler code here
	//TODO: Add your command handler code here
         SECURITY_ATTRIBUTES sa;
         sa.bInheritHandle=TRUE;
         sa.lpSecurityDescriptor=NULL;
         sa.nLength=sizeof(SECURITY_ATTRIBUTES);
         if(!CreatePipe(&hRead,&hWrite,&sa,0))
         {
                   MessageBox("���������ܵ�ʧ�ܣ�");
                   return;
         }
         STARTUPINFO sui;
         PROCESS_INFORMATION pi;
         ZeroMemory(&sui,sizeof(STARTUPINFO));
         sui.cb=sizeof(STARTUPINFO);
         sui.dwFlags=STARTF_USESTDHANDLES;
         sui.hStdInput=hRead;
         sui.hStdOutput=hWrite;
         sui.hStdError=GetStdHandle(STD_ERROR_HANDLE);
        
         if(!CreateProcess("C:\\Users\\HP\\Desktop\\OSʵ��\\ʵ��4 �����ܵ�ͨ��\\Child\\Debug\\Child.exe",NULL,NULL,NULL,
                            TRUE,0,NULL,NULL,&sui,&pi))
         {
                   CloseHandle(hRead);
                   CloseHandle(hWrite);
                   hRead=NULL;
                   hWrite=NULL;
                   MessageBox("�����ӽ���ʧ�ܣ�");
                   return;
         }
         else
         {
                   CloseHandle(pi.hProcess);
                   CloseHandle(pi.hThread);
         }
}

void CParentView::OnReadPipe() 
{
	// TODO: Add your command handler code here
	char buf[100];
    DWORD dwRead;
    if(!ReadFile(hRead,buf,100,&dwRead,NULL))
    {
		MessageBox("��ȡ����ʧ�ܣ�");
		return;
    }
	MessageBox(buf);
}

void CParentView::OnWritePipe() 
{
	// TODO: Add your command handler code here
	char buf[]="I AM A XDUER.";
    DWORD dwWrite;
    if(!WriteFile(hWrite,buf,strlen(buf)+1,&dwWrite,NULL))
    {
         MessageBox("д������ʧ�ܣ�");
         return;
    }
}
