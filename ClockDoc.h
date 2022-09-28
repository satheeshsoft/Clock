// ClockDoc.h : interface of the CClockDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLOCKDOC_H__EEC688CA_28E7_11D1_813A_0020AF337325__INCLUDED_)
#define AFX_CLOCKDOC_H__EEC688CA_28E7_11D1_813A_0020AF337325__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CClockDoc : public CDocument
{
protected: // create from serialization only
	CClockDoc();
	DECLARE_DYNCREATE(CClockDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClockDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CClockDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CClockDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLOCKDOC_H__EEC688CA_28E7_11D1_813A_0020AF337325__INCLUDED_)
