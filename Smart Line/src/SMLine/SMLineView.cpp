// SMLineView.cpp : implementation of the CSMLineView class
//

#include "stdafx.h"
#include "SMLine.h"

#include "SMLineDoc.h"
#include "SMLineView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSMLineView

IMPLEMENT_DYNCREATE(CSMLineView, CScrollView)

BEGIN_MESSAGE_MAP(CSMLineView, CScrollView)
	//{{AFX_MSG_MAP(CSMLineView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_DRAW_LINE, OnDrawLine)
	ON_UPDATE_COMMAND_UI(ID_DRAW_LINE, OnUpdateDrawLine)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSMLineView construction/destruction

CSMLineView::CSMLineView()
{
	// TODO: add construction code here

	m_bDrawLine = FALSE;
}

CSMLineView::~CSMLineView()
{
}

BOOL CSMLineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSMLineView drawing

void CSMLineView::OnDraw(CDC* pDC)
{
	CSMLineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CSMLineView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CSMLineView printing

BOOL CSMLineView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSMLineView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSMLineView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSMLineView diagnostics

#ifdef _DEBUG
void CSMLineView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CSMLineView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CSMLineDoc* CSMLineView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSMLineDoc)));
	return (CSMLineDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSMLineView message handlers

void CSMLineView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_LDStateMgr.m_pLDState){
		m_LDStateMgr.m_pLDState->m_fnOnLButtonDown(nFlags, point);		
	}	
	
	CScrollView::OnLButtonDown(nFlags, point);
}

void CSMLineView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CPaintDC dc(this); // device context for painting

	if(m_LDStateMgr.m_pLDState){
		m_LDStateMgr.m_pLDState->m_fnOnMouseMove(nFlags, point);		
		m_LDStateMgr.m_pLDState->m_fnDraw(dc);		
		Invalidate();
	}

	m_LDStateMgr.m_pLDState->m_fnOnMouseMove(nFlags, point);

	
	CScrollView::OnMouseMove(nFlags, point);
}

void CSMLineView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	if(m_LDStateMgr.m_pLDState){
		m_LDStateMgr.m_pLDState->m_fnDraw(dc);		
	}	
	
	// Do not call CScrollView::OnPaint() for painting messages
}

void CSMLineView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_LDStateMgr.m_pLDState){
		m_LDStateMgr.m_pLDState->m_fnOnKeyDown(nChar, nRepCnt, nFlags);		
	}
	
	CScrollView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CSMLineView::OnDrawLine() 
{
	// TODO: Add your command handler code here
	m_bDrawLine = !m_bDrawLine;	

	m_bDrawLine ? m_LDStateMgr.m_fnDrawLineTr(CLDState::_eLDS_Ready) : m_LDStateMgr.m_fnDrawLineTr(CLDState::_eLDS_None);
	Invalidate();
}

void CSMLineView::OnUpdateDrawLine(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_bDrawLine);
}
