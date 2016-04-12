
#if !defined(AFX_BUTTONSTYLE_H__5B65C070_DA55_11D8_9B00_B9FA561F9E73__INCLUDED_)
#define AFX_BUTTONSTYLE_H__5B65C070_DA55_11D8_9B00_B9FA561F9E73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ButtonStyle.h : header file
//

// Comment this: if you don't want that CButtonStyle hilights itself
// also when the window is inactive (like happens in Internet Explorer )
#define ST_LIKEIE
// Comment this: if you don't want to use CMemDC class
#define ST_USE_MEMDC


/////////////////////////////////////////////////////////////////////////////
// CButtonStyle window

class CButtonStyle : public CButton
{
// Construction
public:
	CButtonStyle();
	enum { ST_ALIGN_HORIZ, ST_ALIGN_VERT };

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CButtonStyle)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
   BOOL SetButtonCursor( int nCursorID = -1 );

   void SetFlatFocus( BOOL bDrawFlatFocus, BOOL bRepaint = FALSE );
   BOOL GetFlatFocus();

   void SetDefActiveFgColor( BOOL bRepaint = FALSE );
   void SetActiveFgColor( COLORREF crNew, BOOL bRepaint = FALSE );
   const COLORREF GetActiveFgColor();

   void SetDefActiveBgColor( BOOL bRepaint = FALSE );
   void SetActiveBgColor( COLORREF crNew = RGB( 255, 180, 48 ), BOOL bRepaint = FALSE );
   const COLORREF GetActiveBgColor();

   void SetDefInactiveFgColor( BOOL bRepaint = FALSE );
   void SetInactiveFgColor( COLORREF crNew = RGB( 255, 255, 255 ), BOOL bRepaint = FALSE );
   const COLORREF GetInactiveFgColor();

   void SetDefInactiveBgColor( BOOL bRepaint = FALSE );
   void SetInactiveBgColor( COLORREF crNew = RGB( 40, 120, 240 ), BOOL bRepaint = FALSE );
   const COLORREF GetInactiveBgColor();

   void SetShowText( BOOL bShow = TRUE );
   BOOL GetShowText();

   void SetAlign( int nAlign );
   int GetAlign();
   
   void SetFlat( BOOL bState = TRUE );
   BOOL GetFlat();

   void DrawBorder( BOOL bEnable = TRUE );
   void SetIcon( int nIconInId, int nIconOutId = 0, BYTE cx = 16, BYTE cy = 16 );

   static const short GetVersionI();
	static const char* GetVersionC();

	virtual ~CButtonStyle();

	// Generated message map functions
protected:
	//{{AFX_MSG(CButtonStyle)
	afx_msg void OnCaptureChanged(CWnd *pWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	
private:
	void DrawTheIcon( CDC *pDC, CString *title, RECT *rcItem, CRect *captionRect, BOOL IsPressed, BOOL IsDisabled );
   
   int  m_nAlign;
   BOOL m_bShowText;
   BOOL m_bDrawBorder;
   BOOL m_bIsFlat;
   BOOL m_MouseOnButton;
   BOOL m_bDrawFlatFocus;

   HCURSOR m_hCursor;

   HICON m_hIconIn;
   HICON m_hIconOut;
   BYTE  m_cxIcon;
   BYTE  m_cyIcon;
   
   COLORREF m_crInactiveBg;
   COLORREF m_crInactiveFg;
   COLORREF m_crActiveBg;
   COLORREF m_crActiveFg;  
};

#ifdef ST_USE_MEMDC
//////////////////////////////////////////////////
// CMemDC - Memory DC
//
// Author: Rikku Blue
// Email:  f-pt@163.com
// Copyright (C) 2004 Rikku Blue
//
// You may freely use or modify this code provided this
// Copyright is included in all derived versions.
//
// History - July 20/04 fav
//         
// This class implements a memory Device Context

class CMemDC : public CDC
{
public:
   CMemDC::CMemDC( CDC* pDC ) : CDC()
   {
      ASSERT( pDC != NULL );
      
      m_pDC = pDC;
      m_pOldBitmap = NULL;
      m_bMemDC = !pDC->IsPrinting();
      
      if ( m_bMemDC )   // Create a Memory DC
      {
         pDC->GetClipBox( &m_rect );
         CreateCompatibleDC( pDC );
         m_bitmap.CreateCompatibleBitmap( pDC, m_rect.Width(), m_rect.Height() );
         m_pOldBitmap = SelectObject( &m_bitmap );
         SetWindowOrg(m_rect.left, m_rect.top);
      }
      else  // Make a copy of the relevent parts of the current DC for printing
      {
         m_bPrinting = pDC->m_bPrinting;
         m_hDC       = pDC->m_hDC;
         m_hAttribDC = pDC->m_hAttribDC;
      }
   }
   
   // Destructor copies the contents of the mem DC to the original DC
   CMemDC::~CMemDC()
   {
      if ( m_bMemDC ) 
      {
         // Copy the offscreen bitmap onto the screen.
         m_pDC->BitBlt( m_rect.left, m_rect.top, m_rect.Width(), m_rect.Height(), this,
                        m_rect.left, m_rect.top, SRCCOPY );
         
         //Swap back the original bitmap.
         SelectObject( m_pOldBitmap );
      }
      else
      {
         // All we need to do is replace the DC with an illegal value,
         // this keeps us from accidently deleting the handles associated with
         // the CDC that was passed to the constructor.
         m_hDC = m_hAttribDC = NULL;
      }
   }
   
   CMemDC* operator->() { return this; }  // Allow usage as a pointer
   operator CMemDC*() { return this; }    // Allow usage as a pointer

private:
   CBitmap  m_bitmap;      // Offscreen bitmap
   CBitmap* m_pOldBitmap;  // bitmap originally found in CMemDC
   CDC*     m_pDC;         // Saves CDC passed in constructor
   CRect    m_rect;        // Rectangle of drawing area.
   BOOL     m_bMemDC;      // TRUE if CDC really is a Memory DC.
};

#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUTTONSTYLE_H__5B65C070_DA55_11D8_9B00_B9FA561F9E73__INCLUDED_)
