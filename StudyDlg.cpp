// StudyDlg.cpp : implementation file


#include "stdafx.h"
#include "MagicWord.h"
#include "StudyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStudyDlg dialog


CStudyDlg::CStudyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStudyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStudyDlg)
	m_Way = 0;
	m_nTime = 0;
	//}}AFX_DATA_INIT
}


void CStudyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStudyDlg)
	DDX_Radio(pDX, IDC_WAY, m_Way);
	DDX_Text(pDX, IDC_nTimeInterval, m_nTime);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStudyDlg, CDialog)
	//{{AFX_MSG_MAP(CStudyDlg)
	ON_BN_CLICKED(IDC_QUEDING, OnQueding)
	ON_BN_CLICKED(IDC_QUXIAO, OnQuxiao)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudyDlg message handlers

void CStudyDlg::OnQueding() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
   int n = GetCheckedRadioButton(IDC_WAY,IDC_WAY2);
	if(n == IDC_WAY)
	{
		m_Way = 0;
	}
	if(n == IDC_WAY1)
	{
		m_Way = 1;
	}
	if(n == IDC_WAY2)
	{
		m_Way = 2;
		m_nTime = 1;
	}

	   if ( m_nTime==0 )
   {
      MessageBox( _T( "~~你好粗心，还没输入计时秒￣□￣｜｜!" ), 
                  _T( "提醒!" ), MB_OK | MB_ICONINFORMATION );
      return;
   }

	  CDialog::OnOK();



}

void CStudyDlg::OnQuxiao() 
{
	// TODO: Add your control notification handler code here
	OnCancel();
	
}


