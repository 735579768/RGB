// PaintBoardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "rgb.h"
#include "PaintBoardDlg.h"
#include "RGBDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern  CRGBDlg* m_Pdlghwnd;
/////////////////////////////////////////////////////////////////////////////
// CPaintBoardDlg dialog


CPaintBoardDlg::CPaintBoardDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPaintBoardDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPaintBoardDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPaintBoardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPaintBoardDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPaintBoardDlg, CDialog)
	//{{AFX_MSG_MAP(CPaintBoardDlg)
	ON_WM_NCHITTEST()
	ON_WM_SETCURSOR()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPaintBoardDlg message handlers

 LRESULT CPaintBoardDlg::OnNcHitTest(CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rc;
	GetClientRect(&rc);
	ClientToScreen(&rc);
	return rc.PtInRect(point)?HTCAPTION:CDialog::OnNcHitTest(point);
	return CDialog::OnNcHitTest(point);
}

//BOOL CPaintBoardDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
//{
//	// TODO: Add your message handler code here and/or call default
//	
//	HCURSOR m_mycursor;
//	m_mycursor=AfxGetApp()->LoadCursor(IDR_MYCURSOR);
//	::SetCursor(m_mycursor);
////	return CDialog::OnSetCursor(pWnd, nHitTest, message);
//	return TRUE;
//}

void CPaintBoardDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	m_Pdlghwnd->setRgb();
	// Do not call CDialog::OnPaint() for painting messages
}
