// Clock.h : main header file for the CLOCK application
//

#if !defined(AFX_CLOCK_H__EEC688C4_28E7_11D1_813A_0020AF337325__INCLUDED_)
#define AFX_CLOCK_H__EEC688C4_28E7_11D1_813A_0020AF337325__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CClockApp:
// See Clock.cpp for the implementation of this class
//

class CClockApp : public CWinApp
{
public:
	CClockApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClockApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CClockApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLOCK_H__EEC688C4_28E7_11D1_813A_0020AF337325__INCLUDED_)
