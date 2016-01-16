// RGBDlg.h : header file
//

#if !defined(AFX_RGBDLG_H__43EA6B97_57C9_45E0_8D21_7FD5550DCD16__INCLUDED_)
#define AFX_RGBDLG_H__43EA6B97_57C9_45E0_8D21_7FD5550DCD16__INCLUDED_
#include "PaintBoardDlg.h"	// Added by ClassView
#define WM_SHOWTASK 0x2012
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRGBDlg dialog
 
class CRGBDlg : public CDialog
{
// Construction
public:
//	LRESULT OnShowTask(WPARAM wparam,LPARAM lparam);
//	void toTray();
	void setRgb();
	LRESULT  OnHotKey(WPARAM wparam,LPARAM lparam);
	int m_invial;
	CRGBDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRGBDlg)
	enum { IDD = IDD_RGB_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRGBDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	// Generated message map functions
	//{{AFX_MSG(CRGBDlg)
	virtual BOOL OnInitDialog();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg  LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnStaticExit();
	afx_msg void OnStaticState();
	afx_msg void OnStaticRgb();
	afx_msg void OnStaticHelp();
	afx_msg void OnStaticPaint();
	afx_msg void OnMove(int x, int y);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	COLORREF clrOld;

	char* setClipboardText(char* str);

	CPoint m_mouseOldPoint;
	void state();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RGBDLG_H__43EA6B97_57C9_45E0_8D21_7FD5550DCD16__INCLUDED_)
