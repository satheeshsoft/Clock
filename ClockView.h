// ClockView.h : interface of the CClockView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLOCKVIEW_H__EEC688CC_28E7_11D1_813A_0020AF337325__INCLUDED_)
#define AFX_CLOCKVIEW_H__EEC688CC_28E7_11D1_813A_0020AF337325__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

enum{ CLOCK_ANALOG, CLOCK_DIGITAL };

class CClockView : public CView
{
protected: // create from serialization only
	CClockView();
	DECLARE_DYNCREATE(CClockView)

// Attributes
public:
	CClockDoc* GetDocument();

	int m_nClockType;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClockView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CClockView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CClockView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnTypeAnalog();
	afx_msg void OnUpdateTypeAnalog(CCmdUI* pCmdUI);
	afx_msg void OnTypeDigital();
	afx_msg void OnUpdateTypeDigital(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ClockView.cpp
inline CClockDoc* CClockView::GetDocument()
   { return (CClockDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLOCKVIEW_H__EEC688CC_28E7_11D1_813A_0020AF337325__INCLUDED_)
