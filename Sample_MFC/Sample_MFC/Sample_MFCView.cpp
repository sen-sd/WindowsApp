
// Sample_MFCView.cpp : implementation of the CSample_MFCView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Sample_MFC.h"
#endif

#include "Sample_MFCDoc.h"
#include "Sample_MFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSample_MFCView

IMPLEMENT_DYNCREATE(CSample_MFCView, CView)

BEGIN_MESSAGE_MAP(CSample_MFCView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSample_MFCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CSample_MFCView construction/destruction

CSample_MFCView::CSample_MFCView()
{
	// TODO: add construction code here

}

CSample_MFCView::~CSample_MFCView()
{
}

BOOL CSample_MFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSample_MFCView drawing

void CSample_MFCView::OnDraw(CDC* /*pDC*/)
{
	CSample_MFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CSample_MFCView printing


void CSample_MFCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSample_MFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSample_MFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSample_MFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CSample_MFCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSample_MFCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSample_MFCView diagnostics

#ifdef _DEBUG
void CSample_MFCView::AssertValid() const
{
	CView::AssertValid();
}

void CSample_MFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSample_MFCDoc* CSample_MFCView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSample_MFCDoc)));
	return (CSample_MFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CSample_MFCView message handlers
