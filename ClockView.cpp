// ClockView.cpp : implementation of
// the CClockView class
//

#include "stdafx.h"
#include "Clock.h"

#include "ClockDoc.h"
#include "ClockView.h"

#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClockView

IMPLEMENT_DYNCREATE(CClockView, CView)

BEGIN_MESSAGE_MAP(CClockView, CView)
	//{{AFX_MSG_MAP(CClockView)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_COMMAND(ID_TYPE_ANALOG, OnTypeAnalog)
	ON_UPDATE_COMMAND_UI(ID_TYPE_ANALOG, OnUpdateTypeAnalog)
	ON_COMMAND(ID_TYPE_DIGITAL, OnTypeDigital)
	ON_UPDATE_COMMAND_UI(ID_TYPE_DIGITAL, OnUpdateTypeDigital)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClockView construction/destruction

CClockView::CClockView()
{

	// Set the initial clock type
	// to analog.
	m_nClockType = CLOCK_ANALOG;

}

CClockView::~CClockView()
{
}

BOOL CClockView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CClockView drawing

void CClockView::OnDraw(CDC* pDC)
{
	CClockDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// Get the client rectangle so that we
	// can dynamically fit the clock to
	// the window.
	RECT Rect;
	GetClientRect( &Rect );

	// For easier calculations, get the
	// x and y coordinates of the
	// window center.
	int nCenterX = Rect.right / 2;
	int nCenterY = Rect.bottom / 2;

	// Get the current time.
	CTime Time = CTime::GetCurrentTime();

	CString strDigits;
	int i, x, y;
	CSize size;

	switch( m_nClockType ){
		case CLOCK_ANALOG:
			{
			// Create a yellow pen with which we'll
			// draw the ellipse.
			//CPen Pen( PS_SOLID, 5, RGB( 255, 255, 0 ) );
			CPen Pen( PS_DOT, 5, RGB( 255, 255, 255) );

			// Select the new pen into the DC and
			// remember the pen that was selected out.
			CPen *pOldPen = pDC->SelectObject( &Pen );

			// Draw the clock face border with
			// the Ellipse function.
			pDC->Ellipse( 5, 5, Rect.right - 5,
				Rect.bottom - 5 );

			double Radians;

			// Out text color will be red.
			//pDC->SetTextColor( RGB( 255, 0, 0 ) );
			pDC->SetTextColor( RGB( 0, 0, 0 ) );

			for( i=1; i<=12; i++ ){

				// Format the digit CString object
				// for the current clock number.
				strDigits.Format( "%d", i );

				// Get the text extent of the
				// text so that we can center
				// it about a point.
				size =
					pDC->GetTextExtent( strDigits,
					strDigits.GetLength() );

				// Calculate the number of radians
				// for the current clock number.
				Radians = (double) i * 6.28 / 12.0;

				// Calculate the x coordinate. We
				// use the text extent to center
				// the text about a point.
				x = nCenterX -
					( size.cx / 2 ) +
					(int) ( (double) ( nCenterX - 20 ) *
						sin( Radians ) );

				// Calculate the y coordinate. We
				// use the text extent to center
				// the text about a point.
				y = nCenterY -
					( size.cy / 2 ) -
					(int) ( (double) ( nCenterY - 20 ) *
						cos( Radians ) );

				// Draw the text.
				pDC->TextOut( x, y, strDigits );

				}

			// Calculate the radians for the hour hand.
			Radians = (double) Time.GetHour() +
				(double) Time.GetMinute() / 60.0 +
				(double) Time.GetSecond() / 3600.0;
			Radians *= 6.28 / 12.0;

			// Create a pen for the hour hand that's five
			// pixels wide with a green color.
			//CPen HourPen( PS_SOLID, 5, RGB( 0, 255, 0 ) );
			CPen HourPen( PS_DOT, 5, RGB( 0, 0, 0) );
			//CPen HourPen( PS_SOLID, 5, RGB( rand()%255, rand()%255, rand()%255 ) );

			// Select the newly-created CPen object
			// into the DC.
			pDC->SelectObject( &HourPen );

			// Move to the center of the clock, then
			// draw the hour hand line.
			pDC->MoveTo( nCenterX, nCenterY );
			pDC->LineTo(
				nCenterX + (int) ( (double) ( nCenterX / 3 ) *
					sin( Radians ) ),
				nCenterY - (int) ( (double) ( nCenterY / 3 ) *
					cos( Radians ) ) );

			// Calculate the radians for the minute hand.
			Radians = (double) Time.GetMinute() +
				(double) Time.GetSecond() / 60.0;
			Radians *= 6.28 / 60.0;

			// Create a pen for the minute hand that's three
			// pixels wide with a blue color.
			//CPen MinutePen( PS_SOLID, 3, RGB( 0, 0, 255 ) );
			CPen MinutePen( PS_DOT, 3, RGB( 0, 0, 0) );

			// Select the newly-created CPen object
			// into the DC.
			pDC->SelectObject( &MinutePen );

			// Move the to center of the clock, then
			// draw the minute hand line.
			pDC->MoveTo( nCenterX, nCenterY );
			pDC->LineTo(
				nCenterX + (int) ( (double) (
					( nCenterX * 2 ) / 3 ) * sin( Radians ) ),
				nCenterY - (int) ( (double) (
					( nCenterY * 2 ) / 3 ) * cos( Radians ) ) );

			// Calculate the radians for the second hand.
			Radians = (double) Time.GetSecond();
			Radians *= 6.28 / 60.0;

			// Create a pen for the second hand that's one
			// pixels wide with a cyan color.
			//CPen SecondPen( PS_SOLID, 1, RGB( 0, 255, 255 ) );
			CPen SecondPen( PS_DOT, 1, RGB( 0, 0, 0) );

			// Select the newly-created CPen object
			// into the DC.
			pDC->SelectObject( &SecondPen );

			// Move the to center of the clock, then
			// draw the second hand line.
			pDC->MoveTo( nCenterX, nCenterY );
			pDC->LineTo(
				nCenterX + (int) ( (double) (
					( nCenterX * 4 ) / 5 ) * sin( Radians ) ),
				nCenterY - (int) ( (double) (
					( nCenterY * 4 ) / 5 ) * cos( Radians ) ) );

			// Select the old CPen object back into
			// the DC.
			pDC->SelectObject( pOldPen );
			}
			break;
		case CLOCK_DIGITAL:
			{

			// Begin by creating the text string
			// that represents the digital time.
			strDigits.Format( "%d:%02d:%02d",
				Time.GetHour(),
				Time.GetMinute(),
				Time.GetSecond() );

			CFont Font, *pOldFont;
			int nWidth = 100;
			int nHeight = 140;

			do{

				// We may have already created
				// a font in the CFont object. Here
				// we make sure it's deleted.
				if( Font.GetSafeHandle() != NULL )
					Font.DeleteObject();

				// Create the font with mostly default
				// values. Use a Times New Roman font.
				Font.CreateFont( nHeight, nWidth, 0, 0,
					FW_DONTCARE, 0, 0, 0, ANSI_CHARSET,
					OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,
					DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
					"Times New Roman" );

				// Select the newly-created CFont object into
				// the DC and remember the CFont object that
				// was selected out.
				pOldFont = pDC->SelectObject( &Font );

				// Get the text extent so we can decide if
				// this font is too large.
				size =
					pDC->GetTextExtent( strDigits,
						strDigits.GetLength() );

				// Select the old font back into the DC.
				pDC->SelectObject( pOldFont );

				// If the text extent is too wide,
				// reduce the font width.
				if( size.cx > Rect.right )
					nWidth -= 5;

				// If the text extent is too high,
				// reduce the font height.
				if( size.cy > Rect.bottom )
					nHeight -= 5;

				} while( size.cx > Rect.right ||
					size.cy > Rect.bottom );

			// Select the final font into the
			// DC and remember the CFont object
			// that's selected out.
			pOldFont = pDC->SelectObject( &Font );

			// Draw the text.
			pDC->TextOut( nCenterX - ( size.cx / 2 ),
				nCenterY - ( size.cy / 2 ),
				strDigits );

			// Select the old font back into the DC.
			pDC->SelectObject( pOldFont );

			}
			break;
		}

}

/////////////////////////////////////////////////////////////////////////////
// CClockView diagnostics

#ifdef _DEBUG
void CClockView::AssertValid() const
{
	CView::AssertValid();
}

void CClockView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CClockDoc* CClockView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CClockDoc)));
	return (CClockDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CClockView message handlers

int CClockView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// Kick off the timer.
	SetTimer( 1, 1000, NULL );
	
	return 0;
}

void CClockView::OnTimer(UINT nIDEvent) 
{

	// The timer just causes a redraw to occur.
	// In the OnDraw() function the current
	// time is obtained.
	InvalidateRect( NULL, TRUE );
	UpdateWindow();

	CView::OnTimer(nIDEvent);
}

void CClockView::OnTypeAnalog() 
{

	// Set to an analog clock and
	// cause a window redraw.
	m_nClockType = CLOCK_ANALOG;
	InvalidateRect( NULL, TRUE );
	UpdateWindow();

}

void CClockView::OnUpdateTypeAnalog(CCmdUI* pCmdUI) 
{

	// Set the check if we have an analog clock.
	pCmdUI->SetCheck( m_nClockType == CLOCK_ANALOG );

}

void CClockView::OnTypeDigital() 
{

	// Set to an digital clock and
	// cause a window redraw.
	m_nClockType = CLOCK_DIGITAL;
	InvalidateRect( NULL, TRUE );
	UpdateWindow();

}

void CClockView::OnUpdateTypeDigital(CCmdUI* pCmdUI) 
{

	// Set the check if we have an digital clock.
	pCmdUI->SetCheck( m_nClockType == CLOCK_DIGITAL );

}
