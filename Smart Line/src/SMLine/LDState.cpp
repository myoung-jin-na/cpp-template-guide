// LDState.cpp: implementation of the CLDState class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SMLine.h"
#include "LDState.h"

#include "Math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLDState::CLDState()
{
	m_pMgr = NULL;
}

CLDState::~CLDState()
{

}

void CLDState::m_fnSetMgr(CLDStateMgr* pMgr)
{
	m_pMgr = pMgr;
}

// 0 = not on the line
// 1 = on the p1
// 2 = on the center
// 3 = on the p2
// 4 = on the line
int CLDState::m_fnChkMousePos(CPoint point)
{
	double a=0,b=0;
	CPoint P1,P2,PC;
	P1=m_pMgr->m_P1;
	P2=m_pMgr->m_P2;
	
	a = (double)((double)(P2.y - P1.y) / (double)(P2.x - P1.x));
	b = (double)((double)P1.y) - ((double)(a *  (double)P1.x ));

	P1.x > P2.x ? PC.x = P2.x + (abs(P1.x-P2.x)/2) : PC.x = P1.x + (abs(P1.x-P2.x)/2);
	P1.y > P2.y ? PC.y = P2.y + (abs(P1.y-P2.y)/2) : PC.y = P1.y + (abs(P1.y-P2.y)/2);

	if( P1.x > P2.x ){
		if( P1.x + 30 < point.x ) return 0;
		if( P2.x - 30 > point.x ) return 0;
	}else{
		if( P2.x + 30 < point.x ) return 0;
		if( P1.x - 30 > point.x ) return 0;
	}
	if( P1.y > P2.y ){
		if( P1.y + 30 < point.y ) return 0;
		if( P2.y - 30 > point.y ) return 0;
	}else{
		if( P2.y + 30 < point.y ) return 0;
		if( P1.y - 30 > point.y ) return 0;
	}

	if( abs(P1.x - point.x) < 5 )
	{
		if( abs(P1.y - point.y) < 5 )
		{
			return 1;
		}
	}

	if( abs(PC.x - point.x) < 5 )
	{
		if( abs(PC.y - point.y) < 5 )
		{
			return 2;
		}
	}

	if( abs(P2.x - point.x) < 5 )
	{
		if( abs(P2.y - point.y) < 5 )
		{
			return 3;
		}
	}

	if( fabs((a*(double)point.x )+b-(double)point.y) < 10.0 ){
		return 4;
	}

	return 0;
}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//			::None
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
CLDState_None::CLDState_None()
{
	
}

CLDState_None::~CLDState_None()
{
	
}

void CLDState_None::m_fnDraw(CDC& dc)
{
	
}

void CLDState_None::m_fnOnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CLDState_None::m_fnOnMouseMove(UINT nFlags, CPoint point)
{
	m_pMgr->m_P1 = point;
	m_pMgr->m_P2 = point;
}

void CLDState_None::m_fnOnLButtonDown(UINT nFlags, CPoint point)
{
	
}



///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//			::Ready
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
CLDState_Ready::CLDState_Ready()
{

}

CLDState_Ready::~CLDState_Ready()
{

}

void CLDState_Ready::m_fnDraw(CDC& dc)
{

}

void CLDState_Ready::m_fnOnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{

}

void CLDState_Ready::m_fnOnMouseMove(UINT nFlags, CPoint point)
{
	m_pMgr->m_P1 = point;
	m_pMgr->m_P2 = point;
}

void CLDState_Ready::m_fnOnLButtonDown(UINT nFlags, CPoint point)
{
	m_pMgr->m_fnDrawLineTr(CLDState::_eLDS_Drawing);
}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//			::Drawing
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
CLDState_Drawing::CLDState_Drawing()
{
	
}

CLDState_Drawing::~CLDState_Drawing()
{
	
}

void CLDState_Drawing::m_fnDraw(CDC& dc)
{
	CPen *pPen=NULL, *pOldPen=NULL;

	pPen = new CPen(PS_SOLID, 1, RGB( 0, 0, 0 ));
	pOldPen = dc.SelectObject(pPen);

	dc.MoveTo(m_pMgr->m_P1);
	dc.LineTo(m_pMgr->m_P2);

	dc.SelectObject(pOldPen);

	delete pPen;
}

void CLDState_Drawing::m_fnOnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if( nChar == VK_ESCAPE ){
		m_pMgr->m_fnDrawLineTr(CLDState::_eLDS_Ready);
	}
}

void CLDState_Drawing::m_fnOnMouseMove(UINT nFlags, CPoint point)
{
	m_pMgr->m_P2 = point;	

}

void CLDState_Drawing::m_fnOnLButtonDown(UINT nFlags, CPoint point)
{
	m_pMgr->m_fnDrawLineTr(CLDState::_eLDS_DrawComp);
}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//			::DrawComp
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
CLDState_DrawComp::CLDState_DrawComp()
{
	m_bOnTheLine = 0;
}

CLDState_DrawComp::~CLDState_DrawComp()
{
	
}

void CLDState_DrawComp::m_fnDraw(CDC& dc)
{
	CPen *pPen=NULL, *pOldPen=NULL;

	if( m_bOnTheLine > 0 ){
		pPen = new CPen(PS_DOT, 1, RGB( 255, 0, 0 ));
		pOldPen = dc.SelectObject(pPen);

		CPoint P1,P2,PC;
		P1=m_pMgr->m_P1;
		P2=m_pMgr->m_P2;
				
		P1.x > P2.x ? PC.x = P2.x + (abs(P1.x-P2.x)/2) : PC.x = P1.x + (abs(P1.x-P2.x)/2);
		P1.y > P2.y ? PC.y = P2.y + (abs(P1.y-P2.y)/2) : PC.y = P1.y + (abs(P1.y-P2.y)/2);

		// Line Draw
		dc.MoveTo(m_pMgr->m_P1);
		dc.LineTo(m_pMgr->m_P2);

		// draw point
		dc.FillSolidRect(P1.x-3, P1.y-3, 6, 6, RGB(255,0,0));
		dc.FillSolidRect(P2.x-3, P2.y-3, 6, 6, RGB(255,0,0));
		dc.FillSolidRect(PC.x-3, PC.y-3, 6, 6, RGB(255,0,0));
	
	} else{
		pPen = new CPen(PS_SOLID, 1, RGB( 0, 0, 0 ));
		pOldPen = dc.SelectObject(pPen);

		dc.MoveTo(m_pMgr->m_P1);
		dc.LineTo(m_pMgr->m_P2);
	}

	dc.SelectObject(pOldPen);

	delete pPen;
}

void CLDState_DrawComp::m_fnOnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CLDState_DrawComp::m_fnOnMouseMove(UINT nFlags, CPoint point)
{
	m_bOnTheLine = m_fnChkMousePos(point);
}

void CLDState_DrawComp::m_fnOnLButtonDown(UINT nFlags, CPoint point)
{
	if( m_fnChkMousePos(point) > 0 ){
		m_pMgr->m_fnDrawLineTr(CLDState::_eLDS_ModyReady);
	}	
}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//			::ModyReady
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
CLDState_ModyReady::CLDState_ModyReady()
{
	
}

CLDState_ModyReady::~CLDState_ModyReady()
{
	
}

void CLDState_ModyReady::m_fnDraw(CDC& dc)
{
	CPen *pPen=NULL, *pOldPen=NULL;
	
	pPen = new CPen(PS_DOT, 1, RGB( 255, 0, 0 ));
	
	pOldPen = dc.SelectObject(pPen);
	
	CPoint P1,P2,PC;
	P1=m_pMgr->m_P1;
	P2=m_pMgr->m_P2;
				
	P1.x > P2.x ? PC.x = P2.x + (abs(P1.x-P2.x)/2) : PC.x = P1.x + (abs(P1.x-P2.x)/2);
	P1.y > P2.y ? PC.y = P2.y + (abs(P1.y-P2.y)/2) : PC.y = P1.y + (abs(P1.y-P2.y)/2);

	// draw line
	dc.MoveTo(m_pMgr->m_P1);
	dc.LineTo(m_pMgr->m_P2);

	// draw point
	dc.FillSolidRect(P1.x-3, P1.y-3, 6, 6, RGB(255,0,0));
	dc.FillSolidRect(P2.x-3, P2.y-3, 6, 6, RGB(255,0,0));
	dc.FillSolidRect(PC.x-3, PC.y-3, 6, 6, RGB(255,0,0));
	
	dc.SelectObject(pOldPen);
	
	delete pPen;	
}

void CLDState_ModyReady::m_fnOnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if( nChar == VK_ESCAPE ){
		m_pMgr->m_fnDrawLineTr(CLDState::_eLDS_DrawComp);
	}
}

void CLDState_ModyReady::m_fnOnMouseMove(UINT nFlags, CPoint point)
{
}

void CLDState_ModyReady::m_fnOnLButtonDown(UINT nFlags, CPoint point)
{
	m_pMgr->m_P1Bak = m_pMgr->m_P1;
	m_pMgr->m_P2Bak = m_pMgr->m_P2;
	m_pMgr->m_PCBak = point;
	switch( m_fnChkMousePos(point) )
	{
	case 1:
		m_pMgr->m_fnDrawLineTr(CLDState::_eLDS_ModyP1);		break;
	case 2:
		m_pMgr->m_fnDrawLineTr(CLDState::_eLDS_ModyP1P2);	break;
	case 3:
		m_pMgr->m_fnDrawLineTr(CLDState::_eLDS_ModyP2);		break;
	}	
}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//			::ModyP1
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
CLDState_ModyP1::CLDState_ModyP1()
{
	
}

CLDState_ModyP1::~CLDState_ModyP1()
{
	
}

void CLDState_ModyP1::m_fnDraw(CDC& dc)
{
	CPen *pPen=NULL, *pOldPen=NULL;
	
	pPen = new CPen(PS_DOT, 1, RGB( 255, 0, 0 ));
	
	pOldPen = dc.SelectObject(pPen);
	
	CPoint P1,P2,PC;
	P1=m_pMgr->m_P1;
	P2=m_pMgr->m_P2;
				
	P1.x > P2.x ? PC.x = P2.x + (abs(P1.x-P2.x)/2) : PC.x = P1.x + (abs(P1.x-P2.x)/2);
	P1.y > P2.y ? PC.y = P2.y + (abs(P1.y-P2.y)/2) : PC.y = P1.y + (abs(P1.y-P2.y)/2);
	
	// draw line
	dc.MoveTo(m_pMgr->m_P1);
	dc.LineTo(m_pMgr->m_P2);

	// draw point
	dc.FillSolidRect(P1.x-3, P1.y-3, 6, 6, RGB(255,0,0));
	dc.FillSolidRect(P2.x-3, P2.y-3, 6, 6, RGB(255,0,0));
	dc.FillSolidRect(PC.x-3, PC.y-3, 6, 6, RGB(255,0,0));
	
	dc.SelectObject(pOldPen);
	
	delete pPen;	
}

void CLDState_ModyP1::m_fnOnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if( nChar == VK_ESCAPE ){
		m_pMgr->m_P1 = m_pMgr->m_P1Bak;
		m_pMgr->m_P2 = m_pMgr->m_P2Bak;
		m_pMgr->m_fnDrawLineTr(CLDState::_eLDS_ModyReady);
	}	
}

void CLDState_ModyP1::m_fnOnMouseMove(UINT nFlags, CPoint point)
{
	m_pMgr->m_P1 = point;
}

void CLDState_ModyP1::m_fnOnLButtonDown(UINT nFlags, CPoint point)
{
	m_pMgr->m_fnDrawLineTr(CLDState::_eLDS_DrawComp);	
}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//			::ModyP1P2
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
CLDState_ModyP1P2::CLDState_ModyP1P2()
{
	
}

CLDState_ModyP1P2::~CLDState_ModyP1P2()
{
	
}

void CLDState_ModyP1P2::m_fnDraw(CDC& dc)
{
	CPen *pPen=NULL, *pOldPen=NULL;
	
	pPen = new CPen(PS_DOT, 1, RGB( 255, 0, 0 ));
	
	pOldPen = dc.SelectObject(pPen);
	
	CPoint P1,P2,PC;
	P1=m_pMgr->m_P1;
	P2=m_pMgr->m_P2;
				
	P1.x > P2.x ? PC.x = P2.x + (abs(P1.x-P2.x)/2) : PC.x = P1.x + (abs(P1.x-P2.x)/2);
	P1.y > P2.y ? PC.y = P2.y + (abs(P1.y-P2.y)/2) : PC.y = P1.y + (abs(P1.y-P2.y)/2);
	
	// draw line
	dc.MoveTo(m_pMgr->m_P1);
	dc.LineTo(m_pMgr->m_P2);

	// draw point
	dc.FillSolidRect(P1.x-3, P1.y-3, 6, 6, RGB(255,0,0));
	dc.FillSolidRect(P2.x-3, P2.y-3, 6, 6, RGB(255,0,0));
	dc.FillSolidRect(PC.x-3, PC.y-3, 6, 6, RGB(255,0,0));
		
	dc.SelectObject(pOldPen);
	
	delete pPen;		
}

void CLDState_ModyP1P2::m_fnOnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if( nChar == VK_ESCAPE ){
		m_pMgr->m_P1 = m_pMgr->m_P1Bak;
		m_pMgr->m_P2 = m_pMgr->m_P2Bak;
		m_pMgr->m_fnDrawLineTr(CLDState::_eLDS_ModyReady);
	}	
}

void CLDState_ModyP1P2::m_fnOnMouseMove(UINT nFlags, CPoint point)
{
	CPoint PDiff = point - m_pMgr->m_PCBak;
	m_pMgr->m_P1 = m_pMgr->m_P1Bak + PDiff;
	m_pMgr->m_P2 = m_pMgr->m_P2Bak + PDiff;
}

void CLDState_ModyP1P2::m_fnOnLButtonDown(UINT nFlags, CPoint point)
{
	m_pMgr->m_fnDrawLineTr(CLDState::_eLDS_DrawComp);	
}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//			::ModyP2
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
CLDState_ModyP2::CLDState_ModyP2()
{
	
}

CLDState_ModyP2::~CLDState_ModyP2()
{
	
}

void CLDState_ModyP2::m_fnDraw(CDC& dc)
{
	CPen *pPen=NULL, *pOldPen=NULL;
	
	pPen = new CPen(PS_DOT, 1, RGB( 255, 0, 0 ));
	
	pOldPen = dc.SelectObject(pPen);
	
	CPoint P1,P2,PC;
	P1=m_pMgr->m_P1;
	P2=m_pMgr->m_P2;
				
	P1.x > P2.x ? PC.x = P2.x + (abs(P1.x-P2.x)/2) : PC.x = P1.x + (abs(P1.x-P2.x)/2);
	P1.y > P2.y ? PC.y = P2.y + (abs(P1.y-P2.y)/2) : PC.y = P1.y + (abs(P1.y-P2.y)/2);
	
	// draw line
	dc.MoveTo(m_pMgr->m_P1);
	dc.LineTo(m_pMgr->m_P2);

	// draw point
	dc.FillSolidRect(P1.x-3, P1.y-3, 6, 6, RGB(255,0,0));
	dc.FillSolidRect(P2.x-3, P2.y-3, 6, 6, RGB(255,0,0));
	dc.FillSolidRect(PC.x-3, PC.y-3, 6, 6, RGB(255,0,0));
	
	dc.SelectObject(pOldPen);
	
	delete pPen;	
}

void CLDState_ModyP2::m_fnOnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if( nChar == VK_ESCAPE ){
		m_pMgr->m_P1 = m_pMgr->m_P1Bak;
		m_pMgr->m_P2 = m_pMgr->m_P2Bak;
		m_pMgr->m_fnDrawLineTr(CLDState::_eLDS_ModyReady);
	}	
}

void CLDState_ModyP2::m_fnOnMouseMove(UINT nFlags, CPoint point)
{
	m_pMgr->m_P2 = point;
}

void CLDState_ModyP2::m_fnOnLButtonDown(UINT nFlags, CPoint point)
{
	m_pMgr->m_fnDrawLineTr(CLDState::_eLDS_DrawComp);		
}


///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//			::StateMgr
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
CLDStateMgr::CLDStateMgr()
{
	m_pLDState = NULL;	
	m_LDStateNone.m_fnSetMgr(this);
	m_LDStateReady.m_fnSetMgr(this);
	m_LDStateDrawing.m_fnSetMgr(this);
	m_LDStateDrawComp.m_fnSetMgr(this);
	m_LDStateModyReady.m_fnSetMgr(this);
	m_LDStateModyP1.m_fnSetMgr(this);
	m_LDStateModyP1P2.m_fnSetMgr(this);
	m_LDStateModyP2.m_fnSetMgr(this);
	m_pLDState = &m_LDStateNone;
}

CLDStateMgr::~CLDStateMgr()
{
	
}

void CLDStateMgr::m_fnDrawLineTr(int nState)
{
	switch( nState )
	{
	case CLDState::_eLDS_None:
		m_pLDState = &m_LDStateNone; break;
	case CLDState::_eLDS_Ready:
		m_pLDState = &m_LDStateReady; break;
	case CLDState::_eLDS_Drawing:
		m_pLDState = &m_LDStateDrawing; break;
	case CLDState::_eLDS_DrawComp:
		m_pLDState = &m_LDStateDrawComp; break;
	case CLDState::_eLDS_ModyReady:
		m_pLDState = &m_LDStateModyReady; break;
	case CLDState::_eLDS_ModyP1:
		m_pLDState = &m_LDStateModyP1; break;
	case CLDState::_eLDS_ModyP1P2:
		m_pLDState = &m_LDStateModyP1P2; break;
	case CLDState::_eLDS_ModyP2:
		m_pLDState = &m_LDStateModyP2; break;
	default:
		m_pLDState = &m_LDStateNone; break;
	}
}
