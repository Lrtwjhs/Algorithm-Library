
#if !defined(AFX_WORDDAOSET_H__2083E601_DBDD_11D8_9B00_9AC365148773__INCLUDED_)
#define AFX_WORDDAOSET_H__2083E601_DBDD_11D8_9B00_9AC365148773__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WordDaoSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWordDaoSet DAO recordset

class CWordDaoSet : public CDaoRecordset
{
public:
	CWordDaoSet(CDaoDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CWordDaoSet)

// Field/Param Data
	//{{AFX_FIELD(CWordDaoSet, CDaoRecordset)
	CString	m_Word;
	CString	m_Explain0;
	CString	m_Explain1;
	CString	m_Explain2;
	CString	m_Phrase0;
	CString	m_Phrase1;
	CString	m_Phrase2;
	CString	m_Sentence0;
	CString	m_Sentence1;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWordDaoSet)
	public:
	virtual CString GetDefaultDBName();		// Default database name
	virtual CString GetDefaultSQL();		// Default SQL for Recordset
	virtual void DoFieldExchange(CDaoFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

private:
	CString m_DataSource;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORDDAOSET_H__2083E601_DBDD_11D8_9B00_9AC365148773__INCLUDED_)
