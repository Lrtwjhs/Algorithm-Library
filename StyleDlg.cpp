// StyleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MagicWord.h"
#include "StyleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStyleDlg dialog


CStyleDlg::CStyleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStyleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStyleDlg)
	m_nColor = -1;
	//}}AFX_DATA_INIT
}


void CStyleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStyleDlg)
	DDX_Radio(pDX, IDC_RADIO1, m_nColor);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStyleDlg, CDialog)
	//{{AFX_MSG_MAP(CStyleDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStyleDlg message handlers

void CStyleDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);
	int n = GetCheckedRadioButton(IDC_RADIO1,IDC_RADIO6);	
	switch(n)
	{
	case  IDC_RADIO1:
		m_nColor = 1;
		break;
	case  IDC_RADIO2:
		m_nColor = 2;
		break;
	case  IDC_RADIO3:
		m_nColor = 3;
		break;
	case  IDC_RADIO4:
		m_nColor = 4;
		break;
	case  IDC_RADIO5:
		m_nColor = 5;
		break;
	case  IDC_RADIO6:
		m_nColor = 6;
		break;
	default:
		m_nColor = 0;
	}	
	CDialog::OnOK();
}

void CStyleDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
