
// MagicWordDlg.h : header file
//

#if !defined(AFX_MAGICWORDDLG_H__C5B2E5C7_DBBC_11D8_9B00_8901F5759A73__INCLUDED_)
#define AFX_MAGICWORDDLG_H__C5B2E5C7_DBBC_11D8_9B00_8901F5759A73__INCLUDED_

#include "ButtonStyle.h"	// Added by ClassView
#include "WordDaoSet.h"	// Added by ClassView

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CWordDaoSet;
class CWordInfoDlg;

/////////////////////////////////////////////////////////////////////////////
// CMagicWordDlg dialog

class CMagicWordDlg : public CDialog
{
public:
	int m_nColor;
	int m_WAY;
	void DisplayFirstRecord();
	CMagicWordDlg(CWnd* pParent = NULL);

// Dialog Data
	//{{AFX_DATA(CMagicWordDlg)
	enum { IDD = IDD_MAGICWORD_DIALOG };
	CString	m_sentences;
	CString	m_explains;
	CString	m_word;
	CString	m_jump;
	CString	m_goto;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMagicWordDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMagicWordDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnClose();
	afx_msg void OnSetting();
	afx_msg void OnStudy();
	afx_msg void OnKillstudy();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnJiemian();
	afx_msg void OnCidian();
	afx_msg void OnTianjia();
	afx_msg void OnShanchu();
	afx_msg void OnSousuo();
	afx_msg void OnXiugai();
	afx_msg void OnGuanyu();
	afx_msg void OnTuichu();
	afx_msg void OnLishi();
	afx_msg void OnTiao();
	afx_msg void OnZuiqian();
	afx_msg void OnShangyi();
	afx_msg void OnXiayi();
	afx_msg void OnZuihou();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// 将其单独定义而不是在ClassWizard中定义，参看InitBuffonStyle();
private:
	CButtonStyle m_Setting,  m_ListItem, m_Addition, m_Remove, 
                m_Modify,   m_Search,   m_About,    m_Exit,
                m_Previous, m_Next,     m_End,      m_Home,
                m_Goto,     m_Jump;

private:
   void InitButtonStyle();
   void PublicAssign();
   void RegCurrentRecord();
   void HistroyVisitWord();

private:
   CWordDaoSet *m_pSet;
   CString      m_directory;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAGICWORDDLG_H__C5B2E5C7_DBBC_11D8_9B00_8901F5759A73__INCLUDED_)
