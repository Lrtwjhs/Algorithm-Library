#if !defined(AFX_STYLEDLG_H__77696EBA_225C_4000_9439_A3122C5EFF3D__INCLUDED_)
#define AFX_STYLEDLG_H__77696EBA_225C_4000_9439_A3122C5EFF3D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StyleDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStyleDlg dialog

class CStyleDlg : public CDialog
{
// Construction
public:
	CStyleDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CStyleDlg)
	enum { IDD = IDD_STYLE_DIADLG };
	int		m_nColor;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStyleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStyleDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STYLEDLG_H__77696EBA_225C_4000_9439_A3122C5EFF3D__INCLUDED_)
