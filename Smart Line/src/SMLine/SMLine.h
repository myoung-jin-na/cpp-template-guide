// SMLine.h : main header file for the SMLINE application
//

#if !defined(AFX_SMLINE_H__438B5976_A353_4699_83F6_AE2622548F14__INCLUDED_)
#define AFX_SMLINE_H__438B5976_A353_4699_83F6_AE2622548F14__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSMLineApp:
// See SMLine.cpp for the implementation of this class
//

class CSMLineApp : public CWinApp
{
public:
	CSMLineApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSMLineApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSMLineApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SMLINE_H__438B5976_A353_4699_83F6_AE2622548F14__INCLUDED_)
