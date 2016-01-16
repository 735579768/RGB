#if !defined(AFX_PAINTBOARDDLG_H__20C0CDA2_4039_4BBF_B973_453170F2B1A7__INCLUDED_)
#define AFX_PAINTBOARDDLG_H__20C0CDA2_4039_4BBF_B973_453170F2B1A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PaintBoardDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPaintBoardDlg dialog

class CPaintBoardDlg : public CDialog
{
// Construction
public:
	CPaintBoardDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPaintBoardDlg)
	enum { IDD = IDD_RGB_PAINT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaintBoardDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPaintBoardDlg)
	afx_msg LRESULT OnNcHitTest(CPoint point);
	/*afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);*/
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAINTBOARDDLG_H__20C0CDA2_4039_4BBF_B973_453170F2B1A7__INCLUDED_)
