// ButtonStyle.cpp : implementation file


#include "stdafx.h"
#include "MagicWord.h"
#include "ButtonStyle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CButtonStyle

CButtonStyle::CButtonStyle()
{
   m_MouseOnButton = FALSE;
   m_hIconIn = NULL;
   m_hIconOut = NULL;
   m_cxIcon = 0;
   m_cyIcon = 0;
   m_hCursor = 0;
   
   m_bIsFlat = TRUE;             // Default type is "flat" button
   m_bDrawBorder = TRUE;         // Draw border in "flat" button
   m_nAlign = ST_ALIGN_HORIZ;    // Icon is aligned horizontally
   m_bShowText = TRUE;           // Show the text button
   m_bDrawFlatFocus = FALSE;     // For "flat" button don't draw the focus rect

   SetDefInactiveBgColor();
   SetDefInactiveFgColor();
   SetDefActiveBgColor();
   SetDefActiveFgColor();
}

CButtonStyle::~CButtonStyle()
{
   // Destroy the icons (if any)
   if ( m_hIconIn  != NULL )   ::DeleteObject( m_hIconIn );
   if ( m_hIconOut != NULL )   ::DeleteObject( m_hIconOut );

   // Destroy the cursor (if any)
   if ( m_hCursor != NULL )    ::DestroyCursor( m_hCursor );
}


BEGIN_MESSAGE_MAP(CButtonStyle, CButton)
	//{{AFX_MSG_MAP(CButtonStyle)
	ON_WM_CAPTURECHANGED()
	ON_WM_KILLFOCUS()
	ON_WM_MOUSEMOVE()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CButtonStyle message handlers

void CButtonStyle::DrawItem(LPDRAWITEMSTRUCT lpDIS) 
{
#ifdef ST_USE_MEMDC
   CDC    *pdrawDC = CDC::FromHandle( lpDIS->hDC );
   CMemDC memDC( pdrawDC );
   CDC    *pDC = &memDC;
#else	
   CDC*    pDC = CDC::FromHandle( lpDIS->hDC );
#endif
   
   CPen *pOldPen;
   BOOL bIsPressed  = ( lpDIS->itemState & ODS_SELECTED );
   BOOL bIsFocused  = ( lpDIS->itemState & ODS_FOCUS );
   BOOL bIsDisabled = ( lpDIS->itemState & ODS_DISABLED );
   
   CRect itemRect = lpDIS->rcItem;
   
   if ( m_bIsFlat == FALSE )
   {
      if ( bIsFocused )
      {
         CBrush br( RGB( 0, 0, 0 ) );  
         pDC->FrameRect( &itemRect, &br );
         itemRect.DeflateRect( 1, 1 );
      }
   }
   
   // Prepare draw... paint button's area with background color
   COLORREF bgColor;
   
   if ( ( m_MouseOnButton == TRUE ) || ( bIsPressed ) )
      bgColor = GetActiveBgColor();
   else
      bgColor = GetInactiveBgColor();
   
   CBrush br( bgColor );
   pDC->FillRect( &itemRect, &br );
   
   // Disegno lo sfondo del bottone draw pressed button
   if ( bIsPressed )
   {
      if ( m_bIsFlat == TRUE )
      {
         if ( m_bDrawBorder == TRUE )
         {
            CPen penBtnHiLight( PS_SOLID, 0, GetSysColor( COLOR_BTNHILIGHT ) ); // Bianco
            CPen penBtnShadow(  PS_SOLID, 0, GetSysColor( COLOR_BTNSHADOW ) );  // Grigio scuro
            
            // Disegno i bordi a sinistra e in alto
            // Dark gray line
            pOldPen = pDC->SelectObject( &penBtnShadow );
            pDC->MoveTo( itemRect.left, itemRect.bottom-1 );
            pDC->LineTo( itemRect.left, itemRect.top );
            pDC->LineTo( itemRect.right, itemRect.top );
            
            // Disegno i bordi a destra e in basso
            // White line
            pDC->SelectObject( penBtnHiLight );
            pDC->MoveTo( itemRect.left, itemRect.bottom-1 );
            pDC->LineTo( itemRect.right-1, itemRect.bottom-1 );
            pDC->LineTo( itemRect.right-1, itemRect.top-1 );
            
            pDC->SelectObject( pOldPen );
         }
      }
      else    
      {
         CBrush brBtnShadow( GetSysColor( COLOR_BTNSHADOW ) );
         pDC->FrameRect( &itemRect, &brBtnShadow );
      }
   }
   else  // ...else draw non pressed button
   {
      CPen penBtnHiLight( PS_SOLID, 0, GetSysColor( COLOR_BTNHILIGHT ) );  // White
      CPen pen3DLight(    PS_SOLID, 0, GetSysColor( COLOR_3DLIGHT ) );     // Light gray
      CPen penBtnShadow(  PS_SOLID, 0, GetSysColor( COLOR_BTNSHADOW ) );   // Dark gray
      CPen pen3DDKShadow( PS_SOLID, 0, GetSysColor( COLOR_3DDKSHADOW ) );  // Black
      
      if ( m_bIsFlat == TRUE )
      {
         if (m_MouseOnButton == TRUE && m_bDrawBorder == TRUE)
         {
            // Disegno i bordi a sinistra e in alto
            // White line
            pOldPen = pDC->SelectObject( &penBtnHiLight );
            pDC->MoveTo( itemRect.left, itemRect.bottom - 1 );
            pDC->LineTo( itemRect.left, itemRect.top );
            pDC->LineTo( itemRect.right, itemRect.top );
            
            // Disegno i bordi a destra e in basso
            // Dark gray line
            pDC->SelectObject( penBtnShadow );
            pDC->MoveTo( itemRect.left, itemRect.bottom - 1 );
            pDC->LineTo( itemRect.right - 1, itemRect.bottom - 1 );
            pDC->LineTo( itemRect.right - 1, itemRect.top - 1 );
            
            pDC->SelectObject( pOldPen );
         }
      }
      else
      {
         // Disegno i bordi a sinistra e in alto
         // White line         
         pOldPen = pDC->SelectObject( &penBtnHiLight );
         pDC->MoveTo( itemRect.left, itemRect.bottom - 1 );
         pDC->LineTo( itemRect.left, itemRect.top );
         pDC->LineTo( itemRect.right, itemRect.top );
         
         // Light gray line
         pDC->SelectObject(pen3DLight);
         pDC->MoveTo( itemRect.left + 1, itemRect.bottom - 1 );
         pDC->LineTo( itemRect.left + 1, itemRect.top + 1 );
         pDC->LineTo( itemRect.right, itemRect.top + 1 );
         
         // Disegno i bordi a destra e in basso
         // Black line
         pDC->SelectObject( pen3DDKShadow );
         pDC->MoveTo( itemRect.left, itemRect.bottom -1 );
         pDC->LineTo( itemRect.right - 1, itemRect.bottom - 1 );
         pDC->LineTo( itemRect.right - 1, itemRect.top - 1 );
         
         // Dark gray line
         pDC->SelectObject( penBtnShadow);
         pDC->MoveTo( itemRect.left + 1, itemRect.bottom - 2 );
         pDC->LineTo( itemRect.right - 2, itemRect.bottom - 2 );
         pDC->LineTo( itemRect.right - 2, itemRect.top);
         
         pDC->SelectObject( pOldPen );
      }
   }
   
   // Read the button title
   CString sTitle;
   GetWindowText( sTitle );
   
   // If we don't want the title displayed
   if ( m_bShowText == FALSE )
      sTitle.Empty();
   
   CRect captionRect = lpDIS->rcItem;
   
   // Draw the icon
   if ( m_hIconIn != NULL )
   {
      DrawTheIcon( pDC, &sTitle, &lpDIS->rcItem, &captionRect, bIsPressed, bIsDisabled );
   }
   
   // Write the button title (if any)
   if ( sTitle.IsEmpty() == FALSE )
   {
      // Disegno la caption del bottone
      // Se il bottone e' premuto muovo la captionRect di conseguenza
      if ( bIsPressed )
         captionRect.OffsetRect( 1, 1 );
      
      // ONLY FOR DEBUG
      // Evidenzia il rettangolo in cui verra' centrata la caption 
    
#ifdef ST_USE_MEMDC
      // Get dialog's font
      CFont *pCurrentFont = GetFont(); 
      CFont *pOldFont = pDC->SelectObject( pCurrentFont );
#endif
      if ( ( m_MouseOnButton == TRUE) || ( bIsPressed ) ) 
      {
         pDC->SetTextColor( GetActiveFgColor() );
         pDC->SetBkColor( GetActiveBgColor() );
      }
      else
      {
         pDC->SetTextColor( GetInactiveFgColor() );
         pDC->SetBkColor( GetInactiveBgColor() );
      }
      
      // Center text
      CRect centerRect = captionRect;
      pDC->DrawText( sTitle, -1, captionRect, DT_SINGLELINE|DT_CALCRECT );
      captionRect.OffsetRect( ( centerRect.Width()  - captionRect.Width() ) / 2,
                              ( centerRect.Height() - captionRect.Height() ) / 2 );
      
      pDC->DrawState( captionRect.TopLeft(), captionRect.Size(), (LPCTSTR) sTitle,
                      ( bIsDisabled ? DSS_DISABLED : DSS_NORMAL ), TRUE, 0, (CBrush*) NULL );

#ifdef ST_USE_MEMDC
      pDC->SelectObject( pOldFont );
#endif
   }
   
   if (m_bIsFlat == FALSE || (m_bIsFlat == TRUE && m_bDrawFlatFocus == TRUE))
   {
      // Draw the focus rect
      if ( bIsFocused )
      {
         CRect focusRect = itemRect;
         focusRect.DeflateRect( 3, 3 );
         pDC->DrawFocusRect( &focusRect );
      }
   }
}

void CButtonStyle::PreSubclassWindow() 
{
   // Add BS_OWNERDRAW style
   SetButtonStyle( GetButtonStyle() | BS_OWNERDRAW );
	
	CButton::PreSubclassWindow();
}

void CButtonStyle::OnCaptureChanged(CWnd *pWnd) 
{
   if ( m_MouseOnButton == TRUE )
   {
      ReleaseCapture();
      Invalidate();
   }
	
	CButton::OnCaptureChanged(pWnd);
}

void CButtonStyle::OnKillFocus(CWnd* pNewWnd) 
{
	CButton::OnKillFocus(pNewWnd);

   // If our button is not flat then do nothing
   if ( m_bIsFlat == FALSE )
      return;

   if ( m_MouseOnButton = FALSE )
   {
      m_MouseOnButton = FALSE;
      Invalidate();
   }
}

void CButtonStyle::OnMouseMove(UINT nFlags, CPoint point) 
{
   CWnd *pWnd;
   CWnd *pParent;

	CButton::OnMouseMove(nFlags, point);

   // If the mouse enter the button with the left button pressed
   // then do nothing
   if ( nFlags & MK_LBUTTON && m_MouseOnButton == FALSE )
      return;

   // If button is not flat then do nothing
   if ( m_bIsFlat == FALSE )
      return;

   pWnd = GetActiveWindow();
   pParent = GetOwner();

   if ( ( GetCapture() != this ) && (
        #ifndef ST_LIKEIE
           pWnd != NULL &&
        #endif
           pParent != NULL ) )
   {
      m_MouseOnButton = TRUE;
      SetCapture();
      Invalidate();
   }
   else
   {
      CRect rc;
      GetClientRect( &rc );

      if ( !rc.PtInRect( point ) )
      {
         if ( m_MouseOnButton == TRUE )
         {
            m_MouseOnButton = FALSE;
            Invalidate();
         }

         // If user is NOT pressing left button then release capture!
         if ( ! ( nFlags & MK_LBUTTON ) )
            ReleaseCapture();
      }
   }

}

BOOL CButtonStyle::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// If a cursor was specified when use it!
   if ( m_hCursor != NULL )
   {
      ::SetCursor( m_hCursor);
      return TRUE;
   }

	return CButton::OnSetCursor(pWnd, nHitTest, message);
}

BOOL CButtonStyle::SetButtonCursor(int nCursorID)
{
   HINSTANCE hInstResource;

   if ( m_hCursor != NULL )   ::DestroyCursor( m_hCursor );

   m_hCursor = NULL;

   if ( nCursorID != -1 )
   {
      hInstResource = AfxFindResourceHandle( MAKEINTRESOURCE( nCursorID ), RT_GROUP_CURSOR );
      m_hCursor = (HCURSOR) ::LoadImage( hInstResource, MAKEINTRESOURCE( nCursorID ), IMAGE_CURSOR, 0, 0, 0 );

      if ( m_hCursor == NULL )
         return FALSE;
   }

   return TRUE;
}

void CButtonStyle::SetFlatFocus(BOOL bDrawFlatFocus, BOOL bRepaint)
{
   m_bDrawFlatFocus = bDrawFlatFocus;

   if ( bRepaint == TRUE )
      Invalidate();
}

BOOL CButtonStyle::GetFlatFocus()
{
   return m_bDrawFlatFocus;
}

void CButtonStyle::SetDefActiveFgColor(BOOL bRepaint)
{
   m_crActiveFg = ::GetSysColor( COLOR_BTNTEXT );

   if ( bRepaint == TRUE )
      Invalidate();
}

void CButtonStyle::SetActiveFgColor(COLORREF crNew, BOOL bRepaint)
{
   m_crActiveFg = crNew;

   if ( bRepaint == TRUE )
      Invalidate();
}

const COLORREF CButtonStyle::GetActiveFgColor()
{
   return m_crActiveFg;
}

void CButtonStyle::SetDefActiveBgColor(BOOL bRepaint)
{
   m_crActiveBg = ::GetSysColor( COLOR_BTNFACE );

   if ( bRepaint == TRUE )
      Invalidate();
}

void CButtonStyle::SetActiveBgColor(COLORREF crNew, BOOL bRepaint)
{
   m_crActiveBg = crNew;
   
   if ( bRepaint == TRUE )
      Invalidate();
}

const COLORREF CButtonStyle::GetActiveBgColor()
{
   return m_crActiveBg;
}

void CButtonStyle::SetDefInactiveFgColor(BOOL bRepaint)
{
   m_crInactiveFg = ::GetSysColor( COLOR_BTNTEXT );

   if ( bRepaint == TRUE )
      Invalidate();
}

void CButtonStyle::SetInactiveFgColor(COLORREF crNew, BOOL bRepaint)
{
   m_crInactiveFg = crNew;

   if ( bRepaint == TRUE )
      Invalidate();
}

const COLORREF CButtonStyle::GetInactiveFgColor()
{
   return m_crInactiveFg;
}

void CButtonStyle::SetDefInactiveBgColor(BOOL bRepaint)
{
   m_crInactiveBg = ::GetSysColor( COLOR_BTNFACE );
   
   if ( bRepaint == TRUE )
      Invalidate();
}

void CButtonStyle::SetInactiveBgColor(COLORREF crNew, BOOL bRepaint)
{
   m_crInactiveBg = crNew;

   if ( bRepaint == TRUE )
      Invalidate();
}

const COLORREF CButtonStyle::GetInactiveBgColor()
{
   return m_crInactiveBg;
}

void CButtonStyle::SetShowText(BOOL bShow)
{
   m_bShowText = bShow;
   Invalidate();
}

BOOL CButtonStyle::GetShowText()
{
   return m_bShowText;
}

void CButtonStyle::SetAlign(int nAlign)
{
   switch ( nAlign )
   {
   case ST_ALIGN_HORIZ:
      m_nAlign = ST_ALIGN_HORIZ;
      break;

   case ST_ALIGN_VERT:
      m_nAlign = ST_ALIGN_VERT;
      break;
   }
   Invalidate();
}

int CButtonStyle::GetAlign()
{
   return m_nAlign;
}

void CButtonStyle::SetFlat(BOOL bState)
{
   m_bIsFlat = bState;
   Invalidate();
}

BOOL CButtonStyle::GetFlat()
{
   return m_bIsFlat;
}

void CButtonStyle::DrawBorder(BOOL bEnable)
{
   m_bDrawBorder = bEnable;
}

void CButtonStyle::SetIcon(int nIconInId, int nIconOutId, BYTE cx, BYTE cy)
{
   HINSTANCE hInstResource = AfxFindResourceHandle( MAKEINTRESOURCE( nIconInId ),RT_GROUP_ICON );

   // Set icon when the mouse is IN the button
   m_hIconIn = (HICON) ::LoadImage( hInstResource, MAKEINTRESOURCE( nIconInId ), IMAGE_ICON, 0, 0, 0 );

   // Set icon when the mouse is OUT the button
   m_hIconOut = (nIconOutId == NULL ) ? m_hIconIn : (HICON) ::LoadImage( hInstResource, MAKEINTRESOURCE( nIconOutId ), IMAGE_ICON, 0, 0, 0 );

   m_cxIcon = cx;
   m_cyIcon = cy;
}

const short CButtonStyle::GetVersionI()
{
   return 23;
}

const char* CButtonStyle::GetVersionC()
{
   return "2.3";
}

void CButtonStyle::DrawTheIcon(CDC *pDC, CString *title, RECT *rcItem, CRect *captionRect, BOOL IsPressed, BOOL IsDisabled)
{
   CRect iconRect = rcItem;
   
   switch ( m_nAlign )
   {
   case ST_ALIGN_HORIZ:
      if ( title->IsEmpty() )
      {
         // Center the icon horizontally
         iconRect.left += ( ( iconRect.Width() - m_cxIcon ) / 2 );
      }
      else
      {
         // L'icona deve vedersi subito dentro il focus rect
         iconRect.left += 3;  
         captionRect->left += m_cxIcon + 3;
      }      
      // Center the icon vertically
      iconRect.top += ((iconRect.Height() - m_cyIcon)/2);
      break;
   
   case ST_ALIGN_VERT:
      // Center the icon horizontally
      iconRect.left += ( ( iconRect.Width() - m_cxIcon ) / 2 );
      
      if ( title->IsEmpty() )
      {
         // Center the icon vertically
         iconRect.top += ( ( iconRect.Height() - m_cyIcon ) / 2 );
      }
      else
      {
         captionRect->top += m_cyIcon;
      }
      break;
   }
   
   // If button is pressed then press the icon also
   if ( IsPressed )
      iconRect.OffsetRect( 1, 1 );
   
   // Ole'!
   pDC->DrawState( iconRect.TopLeft(), iconRect.Size(), 
                   ( m_MouseOnButton == TRUE || IsPressed ) ? m_hIconIn : m_hIconOut,
                   ( IsDisabled ? DSS_DISABLED : DSS_NORMAL ), (CBrush*) NULL );
}