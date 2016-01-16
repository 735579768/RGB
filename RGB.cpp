// RGB.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "RGB.h"
#include "RGBDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
 CPaintBoardDlg* pbdlg;
/////////////////////////////////////////////////////////////////////////////
// CRGBApp

BEGIN_MESSAGE_MAP(CRGBApp, CWinApp)
	//{{AFX_MSG_MAP(CRGBApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRGBApp construction
CRGBDlg* m_Pdlghwnd;
CRGBApp::CRGBApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CRGBApp object

CRGBApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CRGBApp initialization

BOOL CRGBApp::InitInstance()
{
	HANDLE handle=::CreateMutex(NULL,true,"keli4");
	if(handle){
		if(ERROR_ALREADY_EXISTS==GetLastError()) 
		{
			AfxMessageBox("程序已经运行");
			return 0;
		}	
	}


	//SetDialogBkColor(RGB(0,0,0),RGB(255,255,0));
	CRGBDlg dlg;
	m_pMainWnd = &dlg;
	m_Pdlghwnd=&dlg;


	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
