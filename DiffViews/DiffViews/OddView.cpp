
// DiffViewsView.cpp : implementation of the COddView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DiffViews.h"
#endif

#include "DiffViewsDoc.h"
#include "OddView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COddView

IMPLEMENT_DYNCREATE(COddView, CView)

BEGIN_MESSAGE_MAP(COddView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &COddView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(ID_ODD_BTN, OnLButtonDown)
	ON_MESSAGE(ID_PROCESS_ODD, ProcessOdd)
END_MESSAGE_MAP()

// COddView construction/destruction

COddView::COddView() noexcept
{
	// TODO: add construction code here
	nOdd = 1;
}

COddView::~COddView()
{
}

BOOL COddView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// COddView drawing

void COddView::OnDraw(CDC* /*pDC*/)
{
	CDiffViewsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// COddView printing


void COddView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL COddView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COddView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COddView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void COddView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void COddView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// COddView diagnostics

#ifdef _DEBUG
void COddView::AssertValid() const
{
	CView::AssertValid();
}

void COddView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDiffViewsDoc* COddView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDiffViewsDoc)));
	return (CDiffViewsDoc*)m_pDocument;
}
#endif //_DEBUG


// COddView message handlers
void COddView::OnInitialUpdate()
{
	m_OddBtn.Create(_T("Increment Even"), WS_VISIBLE | WS_CHILD | WS_BORDER, CRect(20, 20, 250, 100), this, ID_ODD_BTN);
	m_OddEdit.Create(WS_VISIBLE | WS_CHILD | WS_BORDER, CRect(20, 150, 150, 200), this, ID_ODD_EDIT);
}

void COddView::OnLButtonDown()
{
	CString* str = new CString(_T("Even"));
	AfxGetMainWnd()->PostMessageW(ID_PROCESS_VIEW, 0, (LPARAM)str);
}

LRESULT COddView::ProcessOdd(WPARAM wp, LPARAM lp)
{
	CString str;
	str.Format(_T("%d"), nOdd);
	m_OddEdit.SetWindowTextW(str);
	nOdd += 2;

	return NULL;
}
