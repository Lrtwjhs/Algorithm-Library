
#if !defined(AFX_WORDINFODLG_H__D2C9A682_DBF9_11D8_9B00_EF92B9A19C73__INCLUDED_)
#define AFX_WORDINFODLG_H__D2C9A682_DBF9_11D8_9B00_EF92B9A19C73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WordInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWordInfoDlg dialog

class CWordInfoDlg : public CDialog
{
// Construction
public:
	CString m_windowTitle;
	CWordInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWordInfoDlg)
	enum { IDD = IDD_WORDINFO_DIALOG };
	CString	m_word;
	CString	m_explain0;
	CString	m_explain1;
	CString	m_explain2;
	CString	m_phrase0;
	CString	m_phrase1;
	CString	m_phrase2;
	CString	m_sentence0;
	CString	m_sentence1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWordInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWordInfoDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORDINFODLG_H__D2C9A682_DBF9_11D8_9B00_EF92B9A19C73__INCLUDED_)
