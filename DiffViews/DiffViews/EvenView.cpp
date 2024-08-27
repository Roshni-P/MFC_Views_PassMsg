// CEvenView.cpp : implementation file
//

#include "pch.h"
#include "DiffViews.h"
#include "EvenView.h"


// CEvenView

IMPLEMENT_DYNCREATE(CEvenView, CView)

CEvenView::CEvenView()
{
	nEven = 2;
}

CEvenView::~CEvenView()
{
}

BEGIN_MESSAGE_MAP(CEvenView, CView)
	ON_MESSAGE(ID_PROCESS_EVEN, ProcessEven)
	ON_BN_CLICKED(ID_EVEN_BTN, OnLButtonDown)
END_MESSAGE_MAP()


// CEvenView drawing

void CEvenView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}


// CEvenView diagnostics

#ifdef _DEBUG
void CEvenView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CEvenView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CEvenView message handlers
void CEvenView::OnInitialUpdate()
{
	m_EvenBtn.Create(_T("Increment Odd"), WS_VISIBLE | WS_CHILD | WS_BORDER, CRect(20, 20, 150, 100), this, ID_EVEN_BTN);
	m_EvenEdit.Create(WS_VISIBLE | WS_CHILD | WS_BORDER, CRect(20, 150, 150, 200), this, ID_EVEN_EDIT);
}

LRESULT CEvenView::ProcessEven(WPARAM wp, LPARAM lp)
{
	CString str;
	str.Format(_T("%d"), nEven);
	m_EvenEdit.SetWindowTextW(str);
	nEven += 2;

	return NULL;
}

void CEvenView::OnLButtonDown()
{
	CString *str = new CString(_T("Odd"));
	AfxGetMainWnd()->PostMessageW(ID_PROCESS_VIEW, 0,(LPARAM)str);
}