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

KELI_API	int			KAdd(int x,int y);							//����������ӡ�
KELI_API	bool		KSetWindowPos(HWND hWnd,HWND flg=HWND_TOPMOST);					//hwnd ��Ҫ�ö��Ĵ��ھ��������һ���������ʾ���ɹ�����true��ʧ�ܷ���false.
KELI_API	LONG		KHtoD(CString hexstr);						//��һ��ʮ�������ַ���ת����ʮ������ֵ�����ʧ�ܷ���0��
KELI_API	bool		KSetClipBoardText(HWND hwnd,CString str);	//hwndΪҪ���ü������ı��Ĵ��ھ�����ɹ�����1ʧ�ܷ���0
			STRUCTRGB	KGetPointColor();							//���ص�ǰ��Ļ��������ڵ����ɫ����һ��STRUCTRGB�ṹ�����,��ֱ�����������
KELI_API	void		Kkeybd_event(UINT uCode);					//��ɨ����ģ�ⵥ������
KELI_API    bool		KIsRun();									//�ж��Ƿ����ʵ���������С�
KELI_API    bool		KSetWindowAlpha(HWND hwnd,int alpha,DWORD dwFlags=0x2,COLORREF crKey=0x0);		//hwnd��͸�����ڵľ����alpha��͸����100Ϊ��ȫ��͸����dwflagsΪ0x1 ʱΪָ������ɫ͸����Ϊ0x2ʱ��ȫ��͸����Ĭ��Ϊ0x2,crkeyΪҪ͸������ɫ��Ĭ��Ϊ0

#endif