
// FV2TrainerDlg.h : header file
//

#pragma once

// CFV2TrainerDlg dialog
class CFV2TrainerDlg : public CDialogEx
{
// Construction
public:
	CFV2TrainerDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FV2TRAINER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnEraseBkgnd(CDC*);
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnBnClickedOk();
	afx_msg void OnFilterDefaultExitKey();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();	
	afx_msg void OnBnClickedDone();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();

	CString m_combo2Tractor;
	CString m_combo3ExtendCert;
	CMFCButton m_GetTractorC;
	CMFCButton m_SwapCode;
	CMFCButton m_ExitButton;
	CMFCButton m_Twins;
	CMFCButton m_Hugs;
	CMFCButton m_extendCert;
	CMFCButton m_SuperMode;
	CMFCButton m_Mode2;
	CMFCButton m_kitchenCraft;
	//CStatic m_picCtrl;
};
