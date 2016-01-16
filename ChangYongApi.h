#include <afx.h>
#include <TLHELP32.H>
#include <afxwin.h>
#include <Windows.h>
#include <stdio.h>
#ifndef KELI_API
#define KELI_API   extern "C" _declspec(dllexport)
#endif


#ifndef DEAR_I_LOVE_YOU_2012
#define DEAR_I_LOVE_YOU_2012

struct STRUCTRGB{
	CString red;
	CString green;
	CString blue;
	CString rgbcolor;
};
struct PROCESSLIST{
	CString  processName;
};

KELI_API	int			KAdd(int x,int y);							//将两个数相加。
KELI_API	bool		KSetWindowPos(HWND hWnd,HWND flg=HWND_TOPMOST);					//hwnd 是要置顶的窗口句柄，设置一个窗口最顶显示，成功返回true，失败返回false.
KELI_API	LONG		KHtoD(CString hexstr);						//将一个十六进制字符串转换成十进制数值输出，失败返回0。
KELI_API	bool		KSetClipBoardText(HWND hwnd,CString str);	//hwnd为要设置剪贴板文本的窗口句柄，成功返回1失败返回0
			STRUCTRGB	KGetPointColor();							//返回当前屏幕上鼠标所在点的颜色返回一个STRUCTRGB结构体对象,可直接用这个对象。
KELI_API	void		Kkeybd_event(UINT uCode);					//用扫描码模拟单击过程
KELI_API    bool		KIsRun();									//判断是否程序实例正在运行。
KELI_API    bool		KSetWindowAlpha(HWND hwnd,int alpha,DWORD dwFlags=0x2,COLORREF crKey=0x0);		//hwnd是透明窗口的句柄，alpha是透明度100为完全不透明，dwflags为0x1 时为指定的颜色透明，为0x2时是全部透明，默认为0x2,crkey为要透明的颜色，默认为0

#endif