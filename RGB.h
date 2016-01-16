// RGB.h : main header file for the RGB application
//

#if !defined(AFX_RGB_H__F002D241_994F_4B28_874B_60952C17A2AA__INCLUDED_)
#define AFX_RGB_H__F002D241_994F_4B28_874B_60952C17A2AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRGBApp:
// See RGB.cpp for the implementation of this class
//

class CRGBApp : public CWinApp
{
public:
	CRGBApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRGBApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRGBApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RGB_H__F002D241_994F_4B28_874B_60952C17A2AA__INCLUDED_)
