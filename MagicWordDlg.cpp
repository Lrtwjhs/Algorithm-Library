// MagicWordDlg.cpp : implementation file

#include "stdafx.h"
#include "MagicWord.h"

#include "MagicWordDlg.h"
#include "ListItemDlg.h"
#include "WordInfoDlg.h"
#include "SearchDlg.h"
#include "StudyDlg.h"
#include "StyleDlg.h"

#include "WordDaoSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMagicWordDlg dialog

CMagicWordDlg::CMagicWordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMagicWordDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMagicWordDlg)
	m_sentences = _T("");
	m_explains = _T("");
	m_word = _T("");
	m_jump = _T("");
	m_goto = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

   // 实例化m_pSet
   m_pSet = new CWordDaoSet();
}

void CMagicWordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMagicWordDlg)
	DDX_Text(pDX, IDC_EDIT_SENTENCE, m_sentences);
	DDX_Text(pDX, IDC_EDIT_EXPLAIN, m_explains);
	DDX_Text(pDX, IDC_STATIC_WORD, m_word);
	DDV_MaxChars(pDX, m_word, 26);
	DDX_Text(pDX, IDC_STATIC_JUMP, m_jump);
	DDV_MaxChars(pDX, m_jump, 26);
	DDX_Text(pDX, IDC_EDIT_GOTO, m_goto);
	DDV_MaxChars(pDX, m_goto, 26);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMagicWordDlg, CDialog)
	//{{AFX_MSG_MAP(CMagicWordDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_SETTING, OnSetting)
	ON_BN_CLICKED(IDC_STUDY, OnStudy)
	ON_BN_CLICKED(IDC_KILLSTUDY, OnKillstudy)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_JIEMIAN, OnJiemian)
	ON_BN_CLICKED(IDC_CIDIAN, OnCidian)
	ON_BN_CLICKED(IDC_TIANJIA, OnTianjia)
	ON_BN_CLICKED(IDC_SHANCHU, OnShanchu)
	ON_BN_CLICKED(IDC_SOUSUO, OnSousuo)
	ON_BN_CLICKED(IDC_XIUGAI, OnXiugai)
	ON_BN_CLICKED(IDC_GUANYU, OnGuanyu)
	ON_BN_CLICKED(IDC_TUICHU, OnTuichu)
	ON_BN_CLICKED(IDC_LISHI, OnLishi)
	ON_BN_CLICKED(IDC_TIAO, OnTiao)
	ON_BN_CLICKED(IDC_ZUIQIAN, OnZuiqian)
	ON_BN_CLICKED(IDC_SHANGYI, OnShangyi)
	ON_BN_CLICKED(IDC_XIAYI, OnXiayi)
	ON_BN_CLICKED(IDC_ZUIHOU, OnZuihou)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMagicWordDlg message handlers

BOOL CMagicWordDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);

		if (!strAboutMenu.IsEmpty())
		{
         // 改变AboutMenu的菜单显示
         // strAboutMenu = _T( "关于哈哈背单词!" );

			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);

         // 删除最大化命令
         pSysMenu->DeleteMenu( 4, MF_BYPOSITION );
		}
	}

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

   // 如果以ClassWizard定义Button对象(再改其类型为CButtonStyle)
   // 由于InitBuffonStyle()内部SubclassDlgItem()
   // 需要对话框显示出来后才能做动作
   // 所以Debug模式下会异常(Release模式下正确)
   // 个人判断，或许不正确。
   InitButtonStyle();
   HistroyVisitWord();
   DisplayFirstRecord();

	return TRUE;
}

void CMagicWordDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

void CMagicWordDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); 

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
	CRect rect;
	CPaintDC dc(this);
	GetClientRect(rect);
	switch(m_nColor)
	{
	case 0:
		dc.FillSolidRect(rect, RGB(202, 204, 169));
		break;
	case 1:
		dc.FillSolidRect(rect, RGB(34, 145, 185));
		break;
	case 2:
		dc.FillSolidRect(rect, RGB(0, 150, 0));
		break;
	case 3:
		dc.FillSolidRect(rect, RGB(78,29,76));
		break;
	case 4:
		dc.FillSolidRect(rect, RGB(102, 34, 0));
		break;
	case 5:	
		dc.FillSolidRect(rect, RGB(25,24,22));
		break;
	}

		CDialog::OnPaint();
	}
}


HCURSOR CMagicWordDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

/////////////////////////////////////////////////////////////////////////////
// 设置按钮风格
void CMagicWordDlg::InitButtonStyle()
{
   CList< CButtonStyle*, CButtonStyle* > ButtonList;
   ButtonList.AddTail( &m_Setting );
   ButtonList.AddTail( &m_ListItem );
   ButtonList.AddTail( &m_Addition );
   ButtonList.AddTail( &m_Remove );
   ButtonList.AddTail( &m_Modify );
   ButtonList.AddTail( &m_Search );
   ButtonList.AddTail( &m_About );
   ButtonList.AddTail( &m_Exit );
   ButtonList.AddTail( &m_Previous );
   ButtonList.AddTail( &m_Next );
   ButtonList.AddTail( &m_End );
   ButtonList.AddTail( &m_Home );
   ButtonList.AddTail( &m_Goto );
   ButtonList.AddTail( &m_Jump );


   // 用循环实现必须手动改动Resource.h中的定义
   for ( int nIco = IDI_JUMP, nBtn = IDC_JUMP; nBtn >= IDC_LISTITEM; nIco--, nBtn-- )
   {
      CButtonStyle *Button = ButtonList.RemoveTail();
      Button->SubclassDlgItem( nBtn, this );
      Button->SetIcon( nIco );
      Button->SetInactiveBgColor();
      Button->SetInactiveFgColor();
      Button->SetActiveBgColor();
   }
}

/////////////////////////////////////////////////////////////////////////////
// 显示第一条纪录
void CMagicWordDlg::DisplayFirstRecord()
{
   try
   {
      if ( m_pSet->IsOpen() )
         m_pSet->Close();

      m_pSet->Open();
      PublicAssign();
   }
   catch( CDaoException *exception )
   {
      exception->ReportError();
      return;
   }
}

/////////////////////////////////////////////////////////////////////////////
// 为显示作必要的赋值操作
void CMagicWordDlg::PublicAssign()
{
   m_word.Empty();
   m_explains.Empty();
   m_sentences.Empty();

   CString strNewLine( "\r\n" );

   // 当前单词
   m_word = m_pSet->m_Word;

   // 翻译组合
   if ( !m_pSet->m_Explain0.IsEmpty() )
      m_explains += m_pSet->m_Explain0;
   if ( !m_pSet->m_Explain1.IsEmpty() )
      m_explains += ( strNewLine + m_pSet->m_Explain1 );
   if ( !m_pSet->m_Explain2.IsEmpty() )
      m_explains += ( strNewLine + m_pSet->m_Explain2 );

   // 短语及语句组合
   if ( !m_pSet->m_Phrase0.IsEmpty() )
      m_sentences += m_pSet->m_Phrase0;
   if ( !m_pSet->m_Phrase1.IsEmpty() )
      m_sentences += ( strNewLine + m_pSet->m_Phrase1 );
   if ( !m_pSet->m_Phrase2.IsEmpty() )
      m_sentences += ( strNewLine + m_pSet->m_Phrase2 );
   if ( !m_pSet->m_Sentence0.IsEmpty() )
      m_sentences += ( strNewLine + m_pSet->m_Sentence0 );
   if ( !m_pSet->m_Sentence1.IsEmpty() )
      m_sentences += ( strNewLine + m_pSet->m_Sentence1 );

   UpdateData( FALSE );
}

/////////////////////////////////////////////////////////////////////////////
// 程序设置功能
void CMagicWordDlg::OnSetting() 
{
}

/////////////////////////////////////////////////////////////////////////////
//词典
void CMagicWordDlg::OnCidian() 
{
	// TODO: Add your control notification handler code here
	CListItemDlg ListItemDlg;
    ListItemDlg.DoModal();	
}

/////////////////////////////////////////////////////////////////////////////
//添加
void CMagicWordDlg::OnTianjia() 
{
	// TODO: Add your control notification handler code here
	 CWordInfoDlg WordInfoDlg;
   CWordDaoSet  TempSet;
   CString      strSQL;

   // 如果点击了取消按钮，则不执行添加操作。
   if ( WordInfoDlg.DoModal() != IDOK )
      return;

   // 查询当前单词是否已经被收录于数据库中
   if ( TempSet.IsOpen() )
      TempSet.Close();
   
   strSQL.Format( "SELECT * FROM WordList WHERE word = '%s'", 
                  WordInfoDlg.m_word.operator LPCTSTR() );
   TempSet.Open( AFX_DAO_USE_DEFAULT_TYPE, strSQL, 0 );

   if ( !TempSet.IsEOF() )
   {
      MessageBox( _T( "当前单词纪录已存在,没有添加的必要!" ),
                  _T( "已经存在!" ), MB_OK | MB_ICONASTERISK );
      return;
   }

   if ( TempSet.IsOpen() )
      TempSet.Close();

   // 执行添加操作
   try
   {
      m_pSet->AddNew();

      m_pSet->m_Word      = WordInfoDlg.m_word;
      m_pSet->m_Explain0  = WordInfoDlg.m_explain0;
      m_pSet->m_Explain1  = WordInfoDlg.m_explain1;
      m_pSet->m_Explain2  = WordInfoDlg.m_explain2;
      m_pSet->m_Phrase0   = WordInfoDlg.m_phrase0;
      m_pSet->m_Phrase1   = WordInfoDlg.m_phrase1;
      m_pSet->m_Phrase2   = WordInfoDlg.m_phrase2;
      m_pSet->m_Sentence0 = WordInfoDlg.m_sentence0;
      m_pSet->m_Sentence1 = WordInfoDlg.m_sentence1;

      if ( m_pSet->CanUpdate() )
      {
         m_pSet->Update();
         MessageBox( _T( "添加新单词完成!" ), 
                     _T( "添加成功!" ), MB_OK | MB_ICONASTERISK );
      }
   }
   catch( CDaoException *exception )
   {
      exception->ReportError();
      // 否则指针会指向出现异常的纪录
      m_pSet->MoveNext();
      m_pSet->MovePrev();
      return;
   }
}

/////////////////////////////////////////////////////////////////////////////
//删除
void CMagicWordDlg::OnShanchu() 
{
	// TODO: Add your control notification handler code here
	   try
   {
      if ( MessageBox( _T( "你真的不要我了么?%>_<%" ),
                       _T( "删除确认?" ), MB_OKCANCEL | MB_ICONQUESTION ) == IDOK )
      {         
         m_pSet->Delete();
         MessageBox( _T( "该单词信息已经被成功删除!" ),
                     _T( "删除成功!" ), MB_OK | MB_ICONASTERISK );
         OnXiayi();
      }
   }
   catch( CDaoException *exception )
   {
      exception->ReportError();
      m_pSet->MoveNext();
      m_pSet->MovePrev();
      return;
   }
}

/////////////////////////////////////////////////////////////////////////////
//修改
void CMagicWordDlg::OnXiugai() 
{
	// TODO: Add your control notification handler code here
	   CWordInfoDlg WordInfoDlg;
   WordInfoDlg.m_windowTitle = _T( "修改单词信息" );

   WordInfoDlg.m_word      = m_pSet->m_Word;
   WordInfoDlg.m_explain0  = m_pSet->m_Explain0;
   WordInfoDlg.m_explain1  = m_pSet->m_Explain1;
   WordInfoDlg.m_explain2  = m_pSet->m_Explain2;
   WordInfoDlg.m_phrase0   = m_pSet->m_Phrase0;
   WordInfoDlg.m_phrase1   = m_pSet->m_Phrase1;
   WordInfoDlg.m_phrase2   = m_pSet->m_Phrase2;
   WordInfoDlg.m_sentence0 = m_pSet->m_Sentence0;
   WordInfoDlg.m_sentence1 = m_pSet->m_Sentence1;

   if ( WordInfoDlg.DoModal() != IDOK )
      return;

   try
   {
      m_pSet->Edit();
      
      m_pSet->m_Word      = WordInfoDlg.m_word;
      m_pSet->m_Explain0  = WordInfoDlg.m_explain0;
      m_pSet->m_Explain1  = WordInfoDlg.m_explain1;
      m_pSet->m_Explain2  = WordInfoDlg.m_explain2;
      m_pSet->m_Phrase0   = WordInfoDlg.m_phrase0;
      m_pSet->m_Phrase1   = WordInfoDlg.m_phrase1;
      m_pSet->m_Phrase2   = WordInfoDlg.m_phrase2;
      m_pSet->m_Sentence0 = WordInfoDlg.m_sentence0;
      m_pSet->m_Sentence1 = WordInfoDlg.m_sentence1;
      
      if ( m_pSet->CanUpdate() )
      {
         m_pSet->Update();
         PublicAssign();
      }
   }
   catch( CDaoException *exception )
   {
      exception->ReportError();
      m_pSet->MoveNext();
      m_pSet->MovePrev();
      return;
   }	
}

/////////////////////////////////////////////////////////////////////////////
//搜索
void CMagicWordDlg::OnSousuo() 
{
	// TODO: Add your control notification handler code here
	  CWordInfoDlg WordInfoDlg;
   CSearchDlg   SearchDlg;
   CWordDaoSet  TempSet;
   CString      strSQL;

   if ( SearchDlg.DoModal() != IDOK )
      return;

   if ( TempSet.IsOpen() )
      TempSet.Close();
   
   // 先用SELECT word老出错，为什么用*就是对得呢？
   strSQL.Format( "SELECT * FROM WordList WHERE word = '%s'",
                  SearchDlg.m_word.operator LPCTSTR() );
   TempSet.Open( AFX_DAO_USE_DEFAULT_TYPE, strSQL, 0 );
   
   if ( !TempSet.IsEOF() )
   {
      WordInfoDlg.m_windowTitle = _T( "显示查询单词信息" );
      // 窗口还没显示就设置标题，怪不得老在这儿非法操作
      // 在DoModal之前会调用OnInitDialog，在这儿已经处理了下面的操作
      //WordInfoDlg.SetWindowText( WordInfoDlg.m_windowTitle );
   
      WordInfoDlg.m_word      = TempSet.m_Word;
      WordInfoDlg.m_explain0  = TempSet.m_Explain0;
      WordInfoDlg.m_explain1  = TempSet.m_Explain1;
      WordInfoDlg.m_explain2  = TempSet.m_Explain2;
      WordInfoDlg.m_phrase0   = TempSet.m_Phrase0;
      WordInfoDlg.m_phrase1   = TempSet.m_Phrase1;
      WordInfoDlg.m_phrase2   = TempSet.m_Phrase2;
      WordInfoDlg.m_sentence0 = TempSet.m_Sentence0;
      WordInfoDlg.m_sentence1 = TempSet.m_Sentence1;

      WordInfoDlg.DoModal();
   }
   else
   {
      MessageBox( _T( "~~单词库中没有这个单词，赶快添加！≥▽≤y !" ),
                  _T( "查询失败!" ), MB_OK | MB_ICONASTERISK );
      return;
   }

   if ( TempSet.IsOpen() )
      TempSet.Close();
	
}

/////////////////////////////////////////////////////////////////////////////
// 界面
void CMagicWordDlg::OnJiemian() 
{
	// TODO: Add your control notification handler code here
	CStyleDlg dlg;
	if(dlg.DoModal() == IDOK)
	{
		m_nColor = dlg.m_nColor;
	}
	else
	{
	}
//	UpdateData(FALSE);
	Invalidate();	
}

/////////////////////////////////////////////////////////////////////////////
// 关于
void CMagicWordDlg::OnGuanyu() 
{
	// TODO: Add your control notification handler code here
	CAboutDlg AboutDlg;
    AboutDlg.DoModal();
	
}

/////////////////////////////////////////////////////////////////////////////
// 退出
void CMagicWordDlg::OnTuichu() 
{
	// TODO: Add your control notification handler code here
	   CDialog::OnOK();
	
}

/////////////////////////////////////////////////////////////////////////////
//开始学习
void CMagicWordDlg::OnStudy() 
{
	// TODO: Add your control notification handler code here
	CStudyDlg dlg;
	if(dlg.DoModal() == IDOK)
	{
		m_WAY = dlg.m_Way;
		SetTimer(1,dlg.m_nTime*1000,NULL);
	}
}

/////////////////////////////////////////////////////////////////////////////
//暂停学习
void CMagicWordDlg::OnKillstudy() 
{
	// TODO: Add your control notification handler code here
	KillTimer(1); 
}


/////////////////////////////////////////////////////////////////////////////
// 显示下一个单词信息
void CMagicWordDlg::OnXiayi() 
{
	// TODO: Add your control notification handler code here
	   try
   {
      m_pSet->MoveNext();

      if ( m_pSet->IsEOF() )
         m_pSet->MoveFirst();

      PublicAssign();
   }
   catch( CDaoException *exception )
   {
      exception->ReportError();
      m_pSet->MovePrev();
      return;
   }
	
}

/////////////////////////////////////////////////////////////////////////////
// 显示上一个单词信息
void CMagicWordDlg::OnShangyi() 
{
	// TODO: Add your control notification handler code here
	  try
   {
      m_pSet->MovePrev();

      if ( m_pSet->IsBOF() )
         m_pSet->MoveLast();

      PublicAssign();
   }
   catch(  CDaoException *exception )
   {
      exception->ReportError();
      m_pSet->MoveNext();
      return;
   }
	
}

/////////////////////////////////////////////////////////////////////////////
// 显示最后一个单词信息
void CMagicWordDlg::OnZuihou() 
{
	// TODO: Add your control notification handler code here
	  try
   {
      m_pSet->MoveLast();
      PublicAssign();
   }
   catch(  CDaoException *exception )
   {
      exception->ReportError();
      m_pSet->MoveNext();
      m_pSet->MovePrev();
      return;
   }
	
}

/////////////////////////////////////////////////////////////////////////////
// 显示最前一个单词信息
void CMagicWordDlg::OnZuiqian() 
{
	// TODO: Add your control notification handler code here
	  try
   {
      m_pSet->MoveFirst();
      PublicAssign();
   }
   catch(  CDaoException *exception )
   {
      exception->ReportError();
      m_pSet->MoveNext();
      m_pSet->MovePrev();
      return;
   }   
	
}

/////////////////////////////////////////////////////////////////////////////
//历史跳转
void CMagicWordDlg::OnLishi() 
{
	// TODO: Add your control notification handler code here
	  HKEY hKey = 0;
   BYTE szBuffer[26] = { '\0' };
   DWORD dwType = REG_SZ;
   DWORD dwSize = 27;

   memset( szBuffer, 0, dwSize );

   // 如果打开注册表成功，获取键值并实现跳转。
   if ( RegOpenKeyEx( HKEY_CURRENT_USER, "SOFTWARE\\MagicWord",
                      NULL, KEY_ALL_ACCESS, &hKey ) == ERROR_SUCCESS )
   {
      if ( RegQueryValueEx( hKey, "CurrentWord", NULL, &dwType, szBuffer, &dwSize ) == ERROR_SUCCESS )
      {
         CWordDaoSet TempSet;
         CString     strSQL;

         if ( TempSet.IsOpen() )
            TempSet.Close();
            
         strSQL.Format( "SELECT * from WordList WHERE word = '%s'", szBuffer );
         TempSet.Open( AFX_DAO_USE_DEFAULT_TYPE, strSQL, 0 );
            
         // 没有找到则不移动m_pSet，保证了OnNext/OnModify()等可以正常操作
         if ( TempSet.IsEOF() )
         {
            MessageBox( _T( "~~单词库中没有这个单词，赶快添加！≥▽≤y !" ),
                        _T( "跳转失败!" ), MB_OK | MB_ICONASTERISK );
            return;
         }
      }
   }
   
   // 找到的话，则m_pSet跳转到该处。
   m_pSet->MoveFirst();
   
   while ( !m_pSet->IsEOF() )
   {
      if ( m_pSet->m_Word == szBuffer )
      {
         PublicAssign();
         break;
      }
      m_pSet->MoveNext();
   }
	
}

/////////////////////////////////////////////////////////////////////////////
//直接跳转
void CMagicWordDlg::OnTiao() 
{
	// TODO: Add your control notification handler code here
	  CWordDaoSet TempSet;
   CString     strSQL;
   UpdateData();

   if ( m_goto.IsEmpty() )
   {
      MessageBox( _T( "~~同学，你居然不先输入单词<(￣︶￣)>!" ),
                  _T( "请输入单词!" ), MB_OK | MB_ICONASTERISK );
      return;
   }
     if ( !m_goto.Find( ' ' ) )
   {
      MessageBox( _T( "~~单词中不能有空的哦￣▽￣~*!" ),
                  _T( "提醒" ), MB_OK | MB_ICONINFORMATION );
      return;
   }

   // 首先用CWordDaoSet临时对象作查询
   if ( TempSet.IsOpen() )
      TempSet.Close();
   
   strSQL.Format( "SELECT * from WordList WHERE word = '%s'", m_goto.operator LPCTSTR() );
   TempSet.Open( AFX_DAO_USE_DEFAULT_TYPE, strSQL, 0 );

   // 没有找到则不移动m_pSet，保证了OnNext()等可以正常操作
   if ( TempSet.IsEOF() )
   {
      MessageBox( _T( "~~单词库中没有这个单词，赶快添加！≥▽≤y !" ),
                  _T( "跳转失败!" ), MB_OK | MB_ICONASTERISK );
      return;
   }
   
   // 找到的话，则m_pSet跳转到该处。
   m_pSet->MoveFirst();
   
   while ( !m_pSet->IsEOF() )
   {
      if ( !m_pSet->m_Word.CompareNoCase( m_goto ) )
      {
         PublicAssign();
         break;
      }
      m_pSet->MoveNext();
   }

   // 清空m_goto对象
   m_goto.Empty();   
	
}

/////////////////////////////////////////////////////////////////////////////
// 显示上次退出时注册的单词
void CMagicWordDlg::HistroyVisitWord()
{
   HKEY hKey = 0;
   BYTE szBuffer[26] = { '\0' };
   DWORD dwType = REG_SZ;
   DWORD dwSize = 27;

   memset( szBuffer, 0, dwSize );

   if ( RegOpenKeyEx( HKEY_CURRENT_USER, "SOFTWARE\\MagicWord",
                      NULL, KEY_ALL_ACCESS, &hKey ) == ERROR_SUCCESS )
   {
      if ( RegQueryValueEx( hKey, "CurrentWord", NULL, &dwType, szBuffer, &dwSize ) == ERROR_SUCCESS )
         m_jump = szBuffer;
   }
}

/////////////////////////////////////////////////////////////////////////////
// 窗口被销毁时注册当前单词
BOOL CMagicWordDlg::DestroyWindow() 
{
   RegCurrentRecord();

   if ( m_pSet->IsOpen() )
      m_pSet->Close();

   if ( m_pSet )
      delete m_pSet;

	return CDialog::DestroyWindow();
}


/////////////////////////////////////////////////////////////////////////////
// 获得WM_CLOSE控制(注册当前单词)
void CMagicWordDlg::OnClose() 
{
	CDialog::OnClose();
}

/////////////////////////////////////////////////////////////////////////////
// 注册最后一个被显示的单词信息
void CMagicWordDlg::RegCurrentRecord()
{
   HKEY hKey = 0;
   char szStatus[26] = { '\0' };
   DWORD dwSize = 27;

   if ( RegOpenKeyEx( HKEY_CURRENT_USER, "SOFTWARE\\MagicWord", 
                      NULL, KEY_ALL_ACCESS, &hKey ) == ERROR_SUCCESS )
   {
      wsprintf( szStatus, "%s", m_pSet->m_Word );
      RegSetValueEx( hKey, "CurrentWord", 0, REG_SZ, (CONST BYTE*) szStatus, dwSize );
      RegCloseKey( hKey );
   }
   else
   {
      RegCreateKey( HKEY_CURRENT_USER, "SOFTWARE\\MagicWord", &hKey );
      wsprintf( szStatus, "%s", m_pSet->m_Word );
      RegSetValueEx( hKey, "CurrentWord", 0, REG_SZ, (CONST BYTE*) szStatus, dwSize );
      RegCloseKey( hKey );
   }
}

/////////////////////////////////////////////////////////////////////////////
// 使回车键无效
void CMagicWordDlg::OnOK() 
{
}

//计时器响应函数
void CMagicWordDlg::OnTimer(UINT nIDEvent) 
{
	switch(m_WAY)
	{
	case 0:

		OnXiayi();
		break;
	case 1:
		OnShangyi();
		break;
	case 2:
     MessageBox( _T( "~~好奇心害死猫，我都说了不要点!!! 重启吧(>﹏<)~~" ), 
                  _T( "提醒!" ), MB_OK | MB_ICONINFORMATION );
		break;
	default:
		break;
	}
	CDialog::OnTimer(nIDEvent);
}
































