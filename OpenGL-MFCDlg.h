
// OpenGL-MFCDlg.h : ͷ�ļ�
//

#pragma once
#include "LeftWindow.h"

// COpenGLMFCDlg �Ի���
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
// ����
public:
	COpenGLMFCDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_OPENGLMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
