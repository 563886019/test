// ZBSCOMM.h : main header file for the ZBSCOMM application
//

#if !defined(AFX_ZBSCOMM_H__0E7FB9CD_3887_440F_AB6C_53A8D25E79AF__INCLUDED_)
#define AFX_ZBSCOMM_H__0E7FB9CD_3887_440F_AB6C_53A8D25E79AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CZBSCOMMApp:
// See ZBSCOMM.cpp for the implementation of this class
//

class CZBSCOMMApp : public CWinApp
{
public:
	CZBSCOMMApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZBSCOMMApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CZBSCOMMApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZBSCOMM_H__0E7FB9CD_3887_440F_AB6C_53A8D25E79AF__INCLUDED_)
