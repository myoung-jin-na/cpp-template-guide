// SMLineDoc.cpp : implementation of the CSMLineDoc class
//

#include "stdafx.h"
#include "SMLine.h"

#include "SMLineDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSMLineDoc

IMPLEMENT_DYNCREATE(CSMLineDoc, CDocument)

BEGIN_MESSAGE_MAP(CSMLineDoc, CDocument)
	//{{AFX_MSG_MAP(CSMLineDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSMLineDoc construction/destruction

CSMLineDoc::CSMLineDoc()
{
	// TODO: add one-time construction code here

}

CSMLineDoc::~CSMLineDoc()
{
}

BOOL CSMLineDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSMLineDoc serialization

void CSMLineDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSMLineDoc diagnostics

#ifdef _DEBUG
void CSMLineDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSMLineDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSMLineDoc commands
