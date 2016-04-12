// WordDaoSet.cpp : implementation file


#include "stdafx.h"
#include "MagicWord.h"
#include "WordDaoSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWordDaoSet

IMPLEMENT_DYNAMIC(CWordDaoSet, CDaoRecordset)

CWordDaoSet::CWordDaoSet(CDaoDatabase* pdb)
	: CDaoRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CWordDaoSet)
	m_Word = _T("");
	m_Explain0 = _T("");
	m_Explain1 = _T("");
	m_Explain2 = _T("");
	m_Phrase0 = _T("");
	m_Phrase1 = _T("");
	m_Phrase2 = _T("");
	m_Sentence0 = _T("");
	m_Sentence1 = _T("");
	m_nFields = 9;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dbOpenDynaset;
   
   char path[ MAX_PATH ] = { '\0' };
   GetCurrentDirectory( MAX_PATH, path );
   m_DataSource.Format( "%s", path );
   m_DataSource += "\\MagicWord.mdb";
}


CString CWordDaoSet::GetDefaultDBName()
{
	return _T( m_DataSource );
}

CString CWordDaoSet::GetDefaultSQL()
{
	return _T("[WordList]");
}

void CWordDaoSet::DoFieldExchange(CDaoFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CWordDaoSet)
	pFX->SetFieldType(CDaoFieldExchange::outputColumn);
	DFX_Text(pFX, _T("[Word]"), m_Word);
	DFX_Text(pFX, _T("[Explain0]"), m_Explain0);
	DFX_Text(pFX, _T("[Explain1]"), m_Explain1);
	DFX_Text(pFX, _T("[Explain2]"), m_Explain2);
	DFX_Text(pFX, _T("[Phrase0]"), m_Phrase0);
	DFX_Text(pFX, _T("[Phrase1]"), m_Phrase1);
	DFX_Text(pFX, _T("[Phrase2]"), m_Phrase2);
	DFX_Text(pFX, _T("[Sentence0]"), m_Sentence0);
	DFX_Text(pFX, _T("[Sentence1]"), m_Sentence1);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CWordDaoSet diagnostics

#ifdef _DEBUG
void CWordDaoSet::AssertValid() const
{
	CDaoRecordset::AssertValid();
}

void CWordDaoSet::Dump(CDumpContext& dc) const
{
	CDaoRecordset::Dump(dc);
}
#endif //_DEBUG