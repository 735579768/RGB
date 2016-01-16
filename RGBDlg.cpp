//  RGBDlg.cpp : implementation file


#include "stdafx.h"
#include "RGB.h"
#include "RGBDlg.h"
#include "ChangYongApi.h"
#include "PaintBoardDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CRGBDlg dialog

extern  CRGBDlg* m_Pdlghwnd;
extern CPaintBoardDlg* pbdlg;
CRGBDlg::CRGBDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRGBDlg::IDD, pParent)
{
	m_mouseOldPoint=NULL;
	m_invial=10;
	//{{AFX_DATA_INIT(CRGBDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRGBDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRGBDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRGBDlg, CDialog)
	//{{AFX_MSG_MAP(CRGBDlg)
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_NCHITTEST()
	ON_BN_CLICKED(IDC_STATIC_EXIT, OnStaticExit)
	ON_BN_CLICKED(IDC_STATIC_STATE, OnStaticState)
	ON_BN_CLICKED(IDC_STATIC_RGB, OnStaticRgb)
	ON_BN_CLICKED(IDC_STATIC_HELP, OnStaticHelp)
	ON_BN_CLICKED(IDC_STATIC_PAINT, OnStaticPaint)
	ON_WM_MOVE()
	ON_WM_CREATE()
	ON_WM_CTLCOLOR()
	ON_MESSAGE(WM_HOTKEY,OnHotKey)
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRGBDlg message handlers

BOOL CRGBDlg::OnInitDialog()
{
	if(0==::SetWindowPos(m_Pdlghwnd->m_hWnd,HWND_TOPMOST,0,0,0,0,SWP_NOSIZE || SWP_NOMOVE)) {
		::MessageBox(m_Pdlghwnd->m_hWnd,"窗口置顶失败","9",MB_OK);
	}
	if(0==::SetWindowPos(pbdlg->m_hWnd,HWND_TOPMOST,0,0,0,0,SWP_NOSIZE || SWP_NOMOVE)) {
		::MessageBox(m_Pdlghwnd->m_hWnd,"窗口置顶失败","9",MB_OK);
	}
	
	//	HCURSOR hCursor;
	//	hCursor = ::LoadCursor(AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDR_MAINFRAME));
	//	this->ModifyStyle(0xF,SS_BITMAP|SS_CENTERIMAGE);  
	//	SetCursor(hCursor);
	//	CDialog::OnInitDialog();
	
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	RegisterHotKey(this->m_hWnd,0xEEEE,NULL,VK_F4);	//注册系统热键
	SetTimer(m_invial,10,0);
	ModifyStyleEx(WS_EX_APPWINDOW,WS_EX_TOOLWINDOW,SWP_DRAWFRAME);//去掉任务栏的图标
	//is->CenterWindow();
	CRect dlgrect;								//以下代码让窗口居中
	int screencx=GetSystemMetrics(SM_CXSCREEN);
	int screency=GetSystemMetrics(SM_CYSCREEN);
	this->GetWindowRect(dlgrect);
	this->MoveWindow(screencx/2-dlgrect.Width()/2,0,dlgrect.Width(),dlgrect.Height(),TRUE);	
	
	CRgn trgn;
	trgn.CreateRoundRectRgn(0,0,dlgrect.Width(),dlgrect.Height(),50,50);
	SetWindowRgn(trgn,TRUE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRGBDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CRGBDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CPoint mouseNewPoint;//取鼠标坐标移动过的话就更新
	GetCursorPos(&mouseNewPoint);
	HDC dc=::GetDC(NULL);	//从这里开始获取屏幕颜色值不一样的话就更新
	COLORREF clr=::GetPixel(dc,m_mouseOldPoint.x,m_mouseOldPoint.y);
	::ReleaseDC(NULL,dc);
	if(mouseNewPoint!=m_mouseOldPoint||clrOld!=clr) {
		m_mouseOldPoint=mouseNewPoint;
		clrOld=clr;
		setRgb();
	}
	CDialog::OnTimer(nIDEvent);
}
 LRESULT CRGBDlg::OnNcHitTest(CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rc;
	GetClientRect(&rc);
	ClientToScreen(&rc);
	return rc.PtInRect(point)?HTCAPTION:CDialog::OnNcHitTest(point);
}
void CRGBDlg::OnStaticExit() 
{
	// TODO: Add your control notification handler code here
	if(IDOK==MessageBox("\t将要退出喽？","啊哦..@_@..",MB_OKCANCEL)){
	UnregisterHotKey(this->m_hWnd,0xEEEE);
	this->DestroyWindow();
	}
}

LRESULT  CRGBDlg::OnHotKey(WPARAM wparam,LPARAM lparam)
{
	state();
	return 0;
}

void CRGBDlg::OnStaticState() 
{
	// TODO: Add your control notification handler code here
	state();
}
void CRGBDlg::state()
{
	static  BOOL timerbool=FALSE;
	if(timerbool){
		//	m_Pdlghwnd->m_invial=10;
		SetTimer(m_Pdlghwnd->m_invial,10,NULL);
		CString str;
		str="正在捕获中";
		SetDlgItemText(IDC_STATIC_STATE,str);
		timerbool=FALSE;
	}else{
		CString str;
		str="已停止捕获";
		//	m_Pdlghwnd->m_invial=0;
		KillTimer(m_Pdlghwnd->m_invial);
		SetDlgItemText(IDC_STATIC_STATE,str);		
		timerbool=TRUE;
	}
}

void CRGBDlg::setRgb()
{
	CString str;
	str.Format("%d",GetBValue(clrOld));
	SetDlgItemText(IDC_STATIC_BLUE,str);
	str.Format("%d",GetGValue(clrOld));
	SetDlgItemText(IDC_STATIC_GREEN,str);
    str.Format("%d",GetRValue(clrOld));
    SetDlgItemText(IDC_STATIC_RED,str);
	
	CString str4,str1,str2,str3;
	str3.Format("%x",GetBValue(clrOld));
	str2.Format("%x",GetGValue(clrOld));
	str1.Format("%x",GetRValue(clrOld));
	if(str1.GetLength()==1)str1="0"+str1;
	if(str2.GetLength()==1)str2="0"+str2;//排除后两种颜色为0时是一位数的情况
	if(str3.GetLength()==1)str3="0"+str3;
	str4=str1+str2+str3;
	str4.MakeUpper();
//	str4.TrimLeft("0");
	str4="#"+str4;
	if (str4=="#")str4="#0";
	SetDlgItemText(IDC_STATIC_RGB,str4);
	
	CClientDC pbdc(pbdlg);
	CPen pen(PS_SOLID ,2,RGB(255,0,0));
	CBrush brush(clrOld);
	pbdc.SelectObject(&pen);
	pbdc.SelectObject(&brush);
	CRect rect;
	pbdlg->GetClientRect(&rect);
	pbdc.Rectangle(&rect);
	//pbdc.RoundRect(&rect,NULL);
}

void CRGBDlg::OnStaticRgb() 
{
	// TODO: Add your control notification handler code here
	char chr[8];
	GetDlgItemText(IDC_STATIC_RGB,chr,10);
	if(setClipboardText(chr)=="1"){
		
		CString str;
		str=chr;
		MessageBox("颜色值：“"+str+"” 已复制到剪辑板！\r\r           按下“CTRL+V”即可使用");
	}else{
		MessageBox("复制失败");
	}
}
char* CRGBDlg::setClipboardText(char *str){//设置剪贴板文本，成功返回原字符串，失败返回null

	if (OpenClipboard()==FALSE)
	{
		return NULL;
	}
	if (EmptyClipboard()==FALSE)
	{
		CloseClipboard();
		return NULL;
	}
	int sz=strlen(str)+1;
	HANDLE hMem=GlobalAlloc(GMEM_MOVEABLE,sz);
	if (hMem==NULL)
	{
		CloseClipboard();
		return NULL;
	}
	char *pMem=(char*)GlobalLock(hMem);
	if (pMem==NULL)
	{
		GlobalFree(hMem);
		CloseClipboard();
		return NULL;
	}
	memcpy(pMem,str,sz);
	GlobalUnlock(hMem);
	if (SetClipboardData(CF_TEXT,hMem)==FALSE)
	{
		GlobalFree(hMem);
		CloseClipboard();
		return NULL;
	}
	CloseClipboard();
	return "1";
}

void CRGBDlg::OnStaticHelp() 
{
	//ShellExecute(NULL, "open", "http://www.zhaokeli.com", NULL, NULL, SW_SHOW);
	// TODO: Add your control notification handler code here
	MessageBox("把鼠标放在你想要获得颜色值的颜色上面，\r之后按下“F4”后窗口中的值就会定下来，\r点击相应的数字就可以复制到剪贴板！http://www.zhaokeli.com");
}

void CRGBDlg::OnStaticPaint() 
{
	// TODO: Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_STATIC_PAINT,str);
	if (str=="隐藏色板")
	{
		pbdlg->ShowWindow(SW_HIDE);
		SetDlgItemText(IDC_STATIC_PAINT,"显示色板");
	}else{
		pbdlg->ShowWindow(SW_SHOW);
		setRgb();
		SetDlgItemText(IDC_STATIC_PAINT,"隐藏色板");
	}
}


void CRGBDlg::OnMove(int x, int y) 
{
	CDialog::OnMove(x, y);
	
	// TODO: Add your message handler code here
	CRect largerect,smallrect;
	GetWindowRect(&largerect);
	pbdlg->GetWindowRect(&smallrect);
	int rectwidth=largerect.Width()-smallrect.Width();
	smallrect.left=rectwidth/2+largerect.left;
	smallrect.right=largerect.right-rectwidth/2;
	smallrect.bottom=smallrect.bottom-smallrect.top+largerect.bottom;
	smallrect.top=largerect.bottom;
	
	pbdlg->MoveWindow(&smallrect,TRUE);

}

int CRGBDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CPaintBoardDlg* paintboarddlg=new CPaintBoardDlg();
	paintboarddlg->Create(IDD_RGB_PAINT,NULL);
	paintboarddlg->ShowWindow(SW_SHOW);
	pbdlg=paintboarddlg;

	CRect smallrect;
	paintboarddlg->GetWindowRect(smallrect);
	CRgn rgn;
	rgn.CreateRoundRectRgn(0,0,smallrect.Width(),smallrect.Height(),90,90);
	paintboarddlg->SetWindowRgn(rgn,TRUE);
	return 0;
}

HBRUSH CRGBDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	// TODO:  在此更改 DC 的任何属性
	if (nCtlColor == CTLCOLOR_BTN)          //更改按钮颜色
	{
		//pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->SetBkColor(RGB(121, 121, 255));
		HBRUSH b = CreateSolidBrush(RGB(121, 121, 255));
		return b;
	}
	else if (nCtlColor == CTLCOLOR_SCROLLBAR)  //
	{
		//pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->SetBkColor(RGB(233, 233, 220));
		HBRUSH b = CreateSolidBrush(RGB(233, 233, 220));
		return b;
	}
	else if (nCtlColor == CTLCOLOR_EDIT)   //更改编辑框
	{
		//pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->SetBkColor(RGB(165, 254, 236));
		HBRUSH b = CreateSolidBrush(RGB(165, 254, 236));
		return b;
	}
	else if (nCtlColor == CTLCOLOR_STATIC)  //更改静态文本
	{
		pDC->SetTextColor(RGB(255, 255, 0));
		pDC->SetBkColor(RGB(0, 0, 0));
		HBRUSH b = CreateSolidBrush(RGB(0, 0, 0));
		return b;
	}
	else if (nCtlColor == CTLCOLOR_DLG)   //更改对话框背景色
	{
		pDC->SetTextColor(RGB(255, 255, 0));
		pDC->SetBkColor(RGB(0, 0, 0));
		HBRUSH b = CreateSolidBrush(RGB(0, 0, 0));
		return b;
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

//BOOL CRGBDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
//{
	// TODO: Add your message handler code here and/or call default
	//HCURSOR m_mycursor;
	//m_mycursor=AfxGetApp()->LoadCursor(IDR_MYCURSOR);
	//::SetCursor(m_mycursor);
//	return CDialog::OnSetCursor(pWnd, nHitTest, message);
//	return TRUE;
//}
