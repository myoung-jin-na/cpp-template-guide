// SMLineView.h : interface of the CSMLineView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SMLINEVIEW_H__BDE9AD31_A0D0_42EF_9DC1_DFA7EF47B13A__INCLUDED_)
#define AFX_SMLINEVIEW_H__BDE9AD31_A0D0_42EF_9DC1_DFA7EF47B13A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LDState.h"

class CSMLineView : public CScrollView
{
protected: // create from serialization only
	CSMLineView();
	DECLARE_DYNCREATE(CSMLineView)

// Attributes
public:
	CSMLineDoc* GetDocument();

	BOOL m_bDrawLine;

	CLDStateMgr m_LDStateMgr;


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSMLineView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSMLineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSMLineView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnDrawLine();
	afx_msg void OnUpdateDrawLine(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SMLineView.cpp
inline CSMLineDoc* CSMLineView::GetDocument()
   { return (CSMLineDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SMLINEVIEW_H__BDE9AD31_A0D0_42EF_9DC1_DFA7EF47B13A__INCLUDED_)
