// ClockDoc.cpp : implementation of the CClockDoc class
//

#include "stdafx.h"
#include "Clock.h"

#include "ClockDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClockDoc

IMPLEMENT_DYNCREATE(CClockDoc, CDocument)

BEGIN_MESSAGE_MAP(CClockDoc, CDocument)
	//{{AFX_MSG_MAP(CClockDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClockDoc construction/destruction

CClockDoc::CClockDoc()
{
}

CClockDoc::~CClockDoc()
{
}

BOOL CClockDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CClockDoc serialization

void CClockDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CClockDoc diagnostics

#ifdef _DEBUG
void CClockDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CClockDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CClockDoc commands
