#if !defined(AFX_STUDYDLG_H__C02DCC0C_06F7_4261_A249_38BCE3CEA834__INCLUDED_)
#define AFX_STUDYDLG_H__C02DCC0C_06F7_4261_A249_38BCE3CEA834__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StudyDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStudyDlg dialog

class CStudyDlg : public CDialog
{
// Construction
public:
	CStudyDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CStudyDlg)
	enum { IDD = IDD_TIMER_DIALOG };
	int		m_Way;
	int		m_nTime;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStudyDlg)
	afx_msg void OnQueding();
	afx_msg void OnQuxiao();
	afx_msg void OnWay();
	afx_msg void OnWay1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDYDLG_H__C02DCC0C_06F7_4261_A249_38BCE3CEA834__INCLUDED_)
