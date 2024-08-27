#pragma once


// CEvenView view

class CEvenView : public CView
{
	DECLARE_DYNCREATE(CEvenView)

protected:
	CEvenView();           // protected constructor used by dynamic creation
	virtual ~CEvenView();

public:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();
	afx_msg LRESULT ProcessEven(WPARAM wp, LPARAM lp);
	virtual void OnLButtonDown();
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif
	CButton m_EvenBtn;
	CEdit	m_EvenEdit;
	int		nEven;
protected:
	DECLARE_MESSAGE_MAP()
};


