// LDState.h: interface for the CLDState class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LDSTATE_H__4E22143E_C051_4A7F_AFA0_7961B8B0D163__INCLUDED_)
#define AFX_LDSTATE_H__4E22143E_C051_4A7F_AFA0_7961B8B0D163__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLDStateMgr;

//======================================================================
//
//======================================================================
class CLDState  
{
public:
	CLDState();
	virtual ~CLDState();

	virtual void m_fnDraw(CDC& dc)=0;
	virtual void m_fnOnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)=0;
	virtual void m_fnOnMouseMove(UINT nFlags, CPoint point)=0;
	virtual void m_fnOnLButtonDown(UINT nFlags, CPoint point)=0;

	int m_fnChkMousePos(CPoint point);

	void m_fnSetMgr(CLDStateMgr* pMgr);

public:
	enum _eLDState{ _eLDS_None, _eLDS_Ready,_eLDS_Drawing, _eLDS_DrawComp, _eLDS_ModyReady,
		_eLDS_ModyP1, _eLDS_ModyP1P2, _eLDS_ModyP2 };

	CLDStateMgr* m_pMgr;
};

//======================================================================
//
//======================================================================
class CLDState_None : public CLDState
{
public:
	CLDState_None();
	virtual ~CLDState_None();
	
	void m_fnDraw(CDC& dc);
	void m_fnOnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void m_fnOnMouseMove(UINT nFlags, CPoint point);
	void m_fnOnLButtonDown(UINT nFlags, CPoint point);
};

//======================================================================
//
//======================================================================
class CLDState_Ready : public CLDState
{
public:
	CLDState_Ready();
	virtual ~CLDState_Ready();
	
	void m_fnDraw(CDC& dc);
	void m_fnOnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void m_fnOnMouseMove(UINT nFlags, CPoint point);
	void m_fnOnLButtonDown(UINT nFlags, CPoint point);
};

/***********************************************************************************
*
************************************************************************************/
class CLDState_Drawing : public CLDState
{
public:
	CLDState_Drawing();
	virtual ~CLDState_Drawing();
	
	void m_fnDraw(CDC& dc);
	void m_fnOnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void m_fnOnMouseMove(UINT nFlags, CPoint point);
	void m_fnOnLButtonDown(UINT nFlags, CPoint point);
};

/***********************************************************************************
*
************************************************************************************/
class CLDState_DrawComp : public CLDState
{
public:
	CLDState_DrawComp();
	virtual ~CLDState_DrawComp();
	
	void m_fnDraw(CDC& dc);
	void m_fnOnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void m_fnOnMouseMove(UINT nFlags, CPoint point);
	void m_fnOnLButtonDown(UINT nFlags, CPoint point);

	int m_bOnTheLine;
};

/***********************************************************************************
*
************************************************************************************/
class CLDState_ModyReady : public CLDState
{
public:
	CLDState_ModyReady();
	virtual ~CLDState_ModyReady();
	
	void m_fnDraw(CDC& dc);
	void m_fnOnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void m_fnOnMouseMove(UINT nFlags, CPoint point);
	void m_fnOnLButtonDown(UINT nFlags, CPoint point);
};

/***********************************************************************************
*
************************************************************************************/
class CLDState_ModyP1 : public CLDState
{
public:
	CLDState_ModyP1();
	virtual ~CLDState_ModyP1();
	
	void m_fnDraw(CDC& dc);
	void m_fnOnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void m_fnOnMouseMove(UINT nFlags, CPoint point);
	void m_fnOnLButtonDown(UINT nFlags, CPoint point);
};

/***********************************************************************************
*
************************************************************************************/
class CLDState_ModyP1P2 : public CLDState
{
public:
	CLDState_ModyP1P2();
	virtual ~CLDState_ModyP1P2();
	
	void m_fnDraw(CDC& dc);
	void m_fnOnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void m_fnOnMouseMove(UINT nFlags, CPoint point);
	void m_fnOnLButtonDown(UINT nFlags, CPoint point);
};

/***********************************************************************************
*
************************************************************************************/
class CLDState_ModyP2 : public CLDState
{
public:
	CLDState_ModyP2();
	virtual ~CLDState_ModyP2();
	
	void m_fnDraw(CDC& dc);
	void m_fnOnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void m_fnOnMouseMove(UINT nFlags, CPoint point);
	void m_fnOnLButtonDown(UINT nFlags, CPoint point);
};

/***********************************************************************************
*
************************************************************************************/
class CLDStateMgr  
{
public:
	CLDStateMgr();
	virtual ~CLDStateMgr();
	
	void m_fnDrawLineTr(int nState);
	
	CLDState*			m_pLDState;
	CLDState_None		m_LDStateNone;
	CLDState_Ready		m_LDStateReady;
	CLDState_Drawing	m_LDStateDrawing;
	CLDState_DrawComp	m_LDStateDrawComp;
	CLDState_ModyReady	m_LDStateModyReady;
	CLDState_ModyP1		m_LDStateModyP1;
	CLDState_ModyP1P2	m_LDStateModyP1P2;
	CLDState_ModyP2		m_LDStateModyP2;

	CPoint m_P1;
	CPoint m_P2;	
	CPoint m_P1Bak;
	CPoint m_P2Bak;
	CPoint m_PCBak;
};


#endif // !defined(AFX_LDSTATE_H__4E22143E_C051_4A7F_AFA0_7961B8B0D163__INCLUDED_)
