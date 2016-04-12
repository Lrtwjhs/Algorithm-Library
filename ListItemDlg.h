
#if !defined(AFX_LISTITEMDLG_H__32C84F41_A732_11D6_9B01_CB22C6AB6873__INCLUDED_)
#define AFX_LISTITEMDLG_H__32C84F41_A732_11D6_9B01_CB22C6AB6873__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ListItemDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CListItemDlg dialog

class CListItemDlg : public CDialog
{
// Construction
public:
	CListItemDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CListItemDlg)
	enum { IDD = IDD_LISTITEM_DIALOG };
	CListCtrl	m_ListCtrl;
	CString	m_word;
	CString	m_Display;
	BOOL	m_bChecked;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListItemDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CListItemDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnGo();
	afx_msg void OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void MatchSingleCharacter();
	void MatchString();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTITEMDLG_H__32C84F41_A732_11D6_9B01_CB22C6AB6873__INCLUDED_)
