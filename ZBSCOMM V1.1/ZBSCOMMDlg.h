// ZBSCOMMDlg.h : header file
//
//{{AFX_INCLUDES()
#include "mscomm1.h"
//}}AFX_INCLUDES

#if !defined(AFX_ZBSCOMMDLG_H__86D9CAF4_6C3F_4BF2_8C4A_6E2FAAC9E163__INCLUDED_)
#define AFX_ZBSCOMMDLG_H__86D9CAF4_6C3F_4BF2_8C4A_6E2FAAC9E163__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CZBSCOMMDlg dialog

class CZBSCOMMDlg : public CDialog
{
// Construction
public:
	CZBSCOMMDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CZBSCOMMDlg)
	enum { IDD = IDD_ZBSCOMM_DIALOG };
	CEdit	m_RXEDIT;
	CComboBox	m_ctrlComboComPortSet;
	CComboBox	m_ctrlComboComCtrl;
	CComboBox	m_ctrlComboComChannel;
	CComboBox	m_ctrlComboComBaudSet;
	CComboBox	m_ctrlComboComStopBits;
	CComboBox	m_ctrlComboComWordLen;
	CComboBox	m_ctrlComboComBaud;
	CComboBox	m_ctrlComboComPort;
	CMSComm	m_ctrlComm;
	CString	m_strEditRXData;
	CString	m_strEditTXData;
	CString	m_strEditPanidMsg;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZBSCOMMDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CZBSCOMMDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnComm();
	afx_msg void OnButtonManualsend();
	afx_msg void OnButtonClear();
	afx_msg void OnButtonGetcfg();
	afx_msg void OnButtonOpen();
	afx_msg void OnButtonClose();
	afx_msg void OnButtonGetchn();
	afx_msg void OnButtonGetuart();
	afx_msg void OnButtonGetpanid();
	afx_msg void OnButtonGetaddr();
	afx_msg void OnButtonGetfaddr();
	afx_msg void OnButtonGetieee();
	afx_msg void OnButtonGetfieee();
	afx_msg void OnButtonRestart();
	afx_msg void OnButtonReset();
	afx_msg void OnButtonSetportcom();
	afx_msg void OnButtonSetchannel();
	afx_msg void OnButtonSetpanid();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZBSCOMMDLG_H__86D9CAF4_6C3F_4BF2_8C4A_6E2FAAC9E163__INCLUDED_)
