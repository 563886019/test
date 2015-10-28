// ZBSCOMMDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ZBSCOMM.h"
#include "ZBSCOMMDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZBSCOMMDlg dialog

CZBSCOMMDlg::CZBSCOMMDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CZBSCOMMDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CZBSCOMMDlg)
	m_strEditRXData = _T("");
	m_strEditTXData = _T("");
	m_strEditPanidMsg = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CZBSCOMMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZBSCOMMDlg)
	DDX_Control(pDX, IDC_EDIT_RXDATA, m_RXEDIT);
	DDX_Control(pDX, IDC_COMBO_COMPORTSET, m_ctrlComboComPortSet);
	DDX_Control(pDX, IDC_COMBO_COMCTRL, m_ctrlComboComCtrl);
	DDX_Control(pDX, IDC_COMBO_COMCHANNEL, m_ctrlComboComChannel);
	DDX_Control(pDX, IDC_COMBO_COMBAUDSET, m_ctrlComboComBaudSet);
	DDX_Control(pDX, IDC_COMBO_COMPORT4, m_ctrlComboComStopBits);
	DDX_Control(pDX, IDC_COMBO_COMPORT3, m_ctrlComboComWordLen);
	DDX_Control(pDX, IDC_COMBO_COMPORT2, m_ctrlComboComBaud);
	DDX_Control(pDX, IDC_COMBO_COMPORT, m_ctrlComboComPort);
	DDX_Control(pDX, IDC_MSCOMM1, m_ctrlComm);
	DDX_Text(pDX, IDC_EDIT_RXDATA, m_strEditRXData);
	DDX_Text(pDX, IDC_EDIT_TXDATA, m_strEditTXData);
	DDX_Text(pDX, IDC_EDIT_GET_PANID, m_strEditPanidMsg);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CZBSCOMMDlg, CDialog)
	//{{AFX_MSG_MAP(CZBSCOMMDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_MANUALSEND, OnButtonManualsend)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, OnButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_GETCFG, OnButtonGetcfg)
	ON_BN_CLICKED(IDC_BUTTON_OPEN, OnButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, OnButtonClose)
	ON_BN_CLICKED(IDC_BUTTON_GETCHN, OnButtonGetchn)
	ON_BN_CLICKED(IDC_BUTTON_GETUART, OnButtonGetuart)
	ON_BN_CLICKED(IDC_BUTTON_GETPANID, OnButtonGetpanid)
	ON_BN_CLICKED(IDC_BUTTON_GETADDR, OnButtonGetaddr)
	ON_BN_CLICKED(IDC_BUTTON_GETFADDR, OnButtonGetfaddr)
	ON_BN_CLICKED(IDC_BUTTON_GETIEEE, OnButtonGetieee)
	ON_BN_CLICKED(IDC_BUTTON_GETFIEEE, OnButtonGetfieee)
	ON_BN_CLICKED(IDC_BUTTON_RESTART, OnButtonRestart)
	ON_BN_CLICKED(IDC_BUTTON_RESET, OnButtonReset)
	ON_BN_CLICKED(IDC_BUTTON_SETPORTCOM, OnButtonSetportcom)
	ON_BN_CLICKED(IDC_BUTTON_SETCHANNEL, OnButtonSetchannel)
	ON_BN_CLICKED(IDC_BUTTON_SETPANID, OnButtonSetpanid)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZBSCOMMDlg message handlers

BOOL CZBSCOMMDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	GetDlgItem(IDC_BUTTON_CLOSE) -> EnableWindow(FALSE);
	m_ctrlComboComPort.SetCurSel(0);
	m_ctrlComboComBaud.SetCurSel(2);
	m_ctrlComboComWordLen.SetCurSel(3);
	m_ctrlComboComStopBits.SetCurSel(0);
	m_ctrlComboComChannel.SetCurSel(0);
	m_ctrlComboComPortSet.SetCurSel(0);
	m_ctrlComboComBaudSet.SetCurSel(2);
	m_ctrlComboComCtrl.SetCurSel(0);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CZBSCOMMDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CZBSCOMMDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CZBSCOMMDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BEGIN_EVENTSINK_MAP(CZBSCOMMDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CZBSCOMMDlg)
	ON_EVENT(CZBSCOMMDlg, IDC_MSCOMM1, 1 /* OnComm */, OnComm, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CZBSCOMMDlg::OnComm() 
{
	// TODO: Add your control notification handler code here
	VARIANT variant_inp;
	COleSafeArray safearray_inp;
	LONG len, k;
	BYTE rxdata[2048];
	CString strtemp;
	if (2 == m_ctrlComm.GetCommEvent())
	{
		variant_inp = m_ctrlComm.GetInput();//从接收缓冲区内读出数据
		safearray_inp = variant_inp;
		len = safearray_inp.GetOneDimSize();
		for (k = 0; k < len; k++)
			safearray_inp.GetElement(&k, rxdata+k);
		for (k = 0; k < len; k++)
		{
			BYTE bt = *(char *)(rxdata+k);
			strtemp.Format("%c", bt);
			m_strEditRXData += strtemp;
		}
		UpdateData(FALSE);
	}
	DWORD dwSel = m_RXEDIT.GetSel();
	m_RXEDIT.SetSel(HIWORD(dwSel), -1);
}

void CZBSCOMMDlg::OnButtonManualsend() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_ctrlComm.SetOutput(COleVariant(m_strEditTXData));
}

void CZBSCOMMDlg::OnButtonClear() 
{
	// TODO: Add your control notification handler code here
	m_strEditRXData = "";
	UpdateData(FALSE);
}

void CZBSCOMMDlg::OnButtonGetcfg() 
{
	// TODO: Add your control notification handler code here
	m_strEditTXData = "AT+GETCFG";
	m_ctrlComm.SetOutput(COleVariant(m_strEditTXData));
	UpdateData(FALSE);
	DWORD dwSel = m_RXEDIT.GetSel();
	m_RXEDIT.SetSel(HIWORD(dwSel), -1);
}


void CZBSCOMMDlg::OnButtonOpen() 
{
	// TODO: Add your control notification handler code here
	UINT  baud[] = {9600, 19200, 38400, 57600, 115200};
	UINT  databits[] = {5, 6, 7, 8};
	UINT  stopbits[] = {1, 2};
	char *szBaud = new char[50];

	m_ctrlComm.SetCommPort(m_ctrlComboComPort.GetCurSel() + 1); //设置串口号
	m_ctrlComm.SetInputMode(1);	//以二进制方式取回数据
	m_ctrlComm.SetInBufferSize(1024);//输入缓冲区大小
	m_ctrlComm.SetOutBufferSize(512);//发送缓冲区

	UINT nbaud = baud[m_ctrlComboComBaud.GetCurSel()];
	UINT ndatabits = databits[m_ctrlComboComWordLen.GetCurSel()];
	UINT nstopbits = stopbits[m_ctrlComboComStopBits.GetCurSel()];
	sprintf(szBaud, "%d,n,%d,%d", nbaud, ndatabits, nstopbits);
	m_ctrlComm.SetSettings(szBaud);//设置并返回波特率、奇偶校验、数据位、停止位
	if (!m_ctrlComm.GetPortOpen())	//查看串口是否打开
		m_ctrlComm.SetPortOpen(TRUE);//打开串口
	m_ctrlComm.SetRThreshold(1);	//接收到1个字符后 产生OnComm事件
	m_ctrlComm.SetInputLen(0);//使用Input将读取接收缓冲区中所有内容
	m_ctrlComm.GetInput();//从接收缓冲区内读出数据

	GetDlgItem(IDC_BUTTON_OPEN) -> EnableWindow(0);
	GetDlgItem(IDC_BUTTON_CLOSE) -> EnableWindow(1);
	delete [] szBaud;
	/*	m_ctrlComm.SetCommPort(4); //COM2
	m_ctrlComm.SetInputMode(1);
	m_ctrlComm.SetInBufferSize(1024);
	m_ctrlComm.SetOutBufferSize(512);
	m_ctrlComm.SetSettings("38400,n,8,1");

	if (!m_ctrlComm.GetPortOpen())
		m_ctrlComm.SetPortOpen(TRUE);
	m_ctrlComm.SetRThreshold(1);
	m_ctrlComm.SetInputLen(0);
	m_ctrlComm.GetInput();
*/
}

void CZBSCOMMDlg::OnButtonClose() 
{
	// TODO: Add your control notification handler code here
	if (m_ctrlComm.GetPortOpen())	//查看串口是否打开
		m_ctrlComm.SetPortOpen(FALSE);//打开串口
	GetDlgItem(IDC_BUTTON_OPEN) -> EnableWindow(1);
	GetDlgItem(IDC_BUTTON_CLOSE) -> EnableWindow(0);
}

void CZBSCOMMDlg::OnButtonGetchn() 
{
	// TODO: Add your control notification handler code here
	m_strEditTXData = "AT+GETCHN";
	m_ctrlComm.SetOutput(COleVariant(m_strEditTXData));
	UpdateData(FALSE);
	DWORD dwSel = m_RXEDIT.GetSel();
	m_RXEDIT.SetSel(HIWORD(dwSel), -1);
}

void CZBSCOMMDlg::OnButtonGetuart() 
{
	// TODO: Add your control notification handler code here
	m_strEditTXData = "AT+GETUART";
	m_ctrlComm.SetOutput(COleVariant(m_strEditTXData));
	UpdateData(FALSE);
	DWORD dwSel = m_RXEDIT.GetSel();
	m_RXEDIT.SetSel(HIWORD(dwSel), -1);
}

void CZBSCOMMDlg::OnButtonGetpanid() 
{
	// TODO: Add your control notification handler code here
	m_strEditTXData = "AT+GETPANID";
	m_ctrlComm.SetOutput(COleVariant(m_strEditTXData));
	UpdateData(FALSE);
	DWORD dwSel = m_RXEDIT.GetSel();
	m_RXEDIT.SetSel(HIWORD(dwSel), -1);
}

void CZBSCOMMDlg::OnButtonGetaddr() 
{
	// TODO: Add your control notification handler code here
	m_strEditTXData = "AT+GETADDR";
	m_ctrlComm.SetOutput(COleVariant(m_strEditTXData));
	UpdateData(FALSE);
	DWORD dwSel = m_RXEDIT.GetSel();
	m_RXEDIT.SetSel(HIWORD(dwSel), -1);
}

void CZBSCOMMDlg::OnButtonGetfaddr() 
{
	// TODO: Add your control notification handler code here
	m_strEditTXData = "AT+GETFADDR";
	m_ctrlComm.SetOutput(COleVariant(m_strEditTXData));
	UpdateData(FALSE);
	DWORD dwSel = m_RXEDIT.GetSel();
	m_RXEDIT.SetSel(HIWORD(dwSel), -1);
}

void CZBSCOMMDlg::OnButtonGetieee() 
{
	// TODO: Add your control notification handler code here
	m_strEditTXData = "AT+GETIEEE";
	m_ctrlComm.SetOutput(COleVariant(m_strEditTXData));
	UpdateData(FALSE);
	DWORD dwSel = m_RXEDIT.GetSel();
	m_RXEDIT.SetSel(HIWORD(dwSel), -1);
}

void CZBSCOMMDlg::OnButtonGetfieee() 
{
	// TODO: Add your control notification handler code here
	m_strEditTXData = "AT+GETFIEEE";
	m_ctrlComm.SetOutput(COleVariant(m_strEditTXData));
	UpdateData(FALSE);	
	DWORD dwSel = m_RXEDIT.GetSel();
	m_RXEDIT.SetSel(HIWORD(dwSel), -1);
}

void CZBSCOMMDlg::OnButtonRestart() 
{
	// TODO: Add your control notification handler code here
	m_strEditTXData = "AT+RESTART";
	m_ctrlComm.SetOutput(COleVariant(m_strEditTXData));
	UpdateData(FALSE);	
	DWORD dwSel = m_RXEDIT.GetSel();
	m_RXEDIT.SetSel(HIWORD(dwSel), -1);
}

void CZBSCOMMDlg::OnButtonReset() 
{
	// TODO: Add your control notification handler code here
	m_strEditTXData = "AT+RESET";
	m_ctrlComm.SetOutput(COleVariant(m_strEditTXData));
	UpdateData(FALSE);
	DWORD dwSel = m_RXEDIT.GetSel();
	m_RXEDIT.SetSel(HIWORD(dwSel), -1);
}

void CZBSCOMMDlg::OnButtonSetportcom() 
{
	// TODO: Add your control notification handler code here
	UINT  baud[] = {9600, 19200, 38400, 57600, 115200};

	int nPortSet = m_ctrlComboComPortSet.GetCurSel();
	UINT nbaud = baud[m_ctrlComboComBaudSet.GetCurSel()];
	int nCtrl = m_ctrlComboComCtrl.GetCurSel();

	CString str; 
	str.Format("%d",nPortSet);
	CString	m_strSendMsg;
	m_strSendMsg = "AT+SETUART ";
	m_strSendMsg += str;
	m_strSendMsg += " ";
	str.Format("%d",nbaud);
	m_strSendMsg += str;
	m_strSendMsg += " ";
	str.Format("%d",nCtrl);
	m_strSendMsg += str;
	m_strSendMsg += " ";
	m_strEditTXData = m_strSendMsg;
	m_ctrlComm.SetOutput(COleVariant(m_strEditTXData));
	UpdateData(FALSE);
	DWORD dwSel = m_RXEDIT.GetSel();
	m_RXEDIT.SetSel(HIWORD(dwSel), -1);
}

void CZBSCOMMDlg::OnButtonSetchannel() 
{
	// TODO: Add your control notification handler code here
	int nChannel = m_ctrlComboComChannel.GetCurSel() + 11;
	CString str; 
	str.Format("%d",nChannel);
	CString	m_strSendMsg;
	m_strSendMsg = "AT+SETCHN ";
	m_strSendMsg += str;
	m_strEditTXData = m_strSendMsg;
	m_ctrlComm.SetOutput(COleVariant(m_strEditTXData));
	UpdateData(FALSE);
	DWORD dwSel = m_RXEDIT.GetSel();
	m_RXEDIT.SetSel(HIWORD(dwSel), -1);
}

void CZBSCOMMDlg::OnButtonSetpanid() 
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);
	CString	m_strSendMsg;
	m_strSendMsg = "AT+SETPANID ";
	m_strSendMsg += m_strEditPanidMsg;
	m_strEditTXData = m_strSendMsg;
	m_ctrlComm.SetOutput(COleVariant(m_strEditTXData));
	UpdateData(FALSE);
	DWORD dwSel = m_RXEDIT.GetSel();
	m_RXEDIT.SetSel(HIWORD(dwSel), -1);
}
