// SMLineDoc.h : interface of the CSMLineDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SMLINEDOC_H__68A07616_C6B0_450F_9727_39F86CF679AB__INCLUDED_)
#define AFX_SMLINEDOC_H__68A07616_C6B0_450F_9727_39F86CF679AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSMLineDoc : public CDocument
{
protected: // create from serialization only
	CSMLineDoc();
	DECLARE_DYNCREATE(CSMLineDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSMLineDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSMLineDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSMLineDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SMLINEDOC_H__68A07616_C6B0_450F_9727_39F86CF679AB__INCLUDED_)
