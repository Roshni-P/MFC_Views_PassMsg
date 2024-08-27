
// OddView.h : interface of the COddView class
//

#pragma once

class CDiffViewsDoc;

class COddView : public CView
{
protected: // create from serialization only
	COddView() noexcept;
	DECLARE_DYNCREATE(COddView)

// Attributes
public:
	CDiffViewsDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~COddView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
	virtual void OnInitialUpdate();
	virtual void OnLButtonDown();
	LRESULT ProcessOdd(WPARAM wp, LPARAM lp);

#endif
	CButton m_OddBtn;
	CEdit	m_OddEdit;
	int nOdd;

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DiffViewsView.cpp
inline CDiffViewsDoc* COddView::GetDocument() const
   { return reinterpret_cast<CDiffViewsDoc*>(m_pDocument); }
#endif

