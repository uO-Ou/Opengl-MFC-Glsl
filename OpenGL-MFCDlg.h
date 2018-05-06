
// OpenGL-MFCDlg.h : 头文件
//

#pragma once
#include "LeftWindow.h"

// COpenGLMFCDlg 对话框
class COpenGLMFCDlg : public CDialogEx{
	LeftWindow *m_leftWindow = nullptr;
	void myInitialize(){
		MoveWindow(100, 100, 800, 800);
		m_leftWindow = new LeftWindow;
		m_leftWindow->Create(NULL, NULL, WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_VISIBLE,
							CRect(0, 0, 800, 800),
							this,   //this is the parent
							0);
	}
// 构造
public:
	COpenGLMFCDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_OPENGLMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
