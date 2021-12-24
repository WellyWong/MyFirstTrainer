
// FV2TrainerDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "FV2Trainer.h"
#include "FV2TrainerDlg.h"
#include "Functions.h"
#include "afxdialogex.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// CFV2TrainerDlg dialog

CFV2TrainerDlg::CFV2TrainerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FV2TRAINER_DIALOG, pParent)
	, m_combo2Tractor(_T("Choose Tractor Card"))
	, m_combo3ExtendCert(_T("Choose Timer"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFV2TrainerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO2, m_combo2Tractor);
	DDX_CBString(pDX, IDC_COMBO3, m_combo3ExtendCert);
	DDX_Control(pDX, IDC_BUTTON2, m_GetTractorC);
	DDX_Control(pDX, IDC_BUTTON3, m_SwapCode);
	DDX_Control(pDX, ID_Done, m_ExitButton);
	DDX_Control(pDX, IDC_BUTTON5, m_Twins);
	DDX_Control(pDX, IDC_BUTTON6, m_Hugs);
	DDX_Control(pDX, IDC_BUTTON7, m_extendCert);
	DDX_Control(pDX, IDC_BUTTON9, m_SuperMode);
	DDX_Control(pDX, IDC_BUTTON1, m_Mode2);
	DDX_Control(pDX, IDC_BUTTON4, m_kitchenCraft);
}

BEGIN_MESSAGE_MAP(CFV2TrainerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDOK, OnFilterDefaultExitKey)
	ON_BN_CLICKED(IDC_BUTTON3, &CFV2TrainerDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CFV2TrainerDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CFV2TrainerDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CFV2TrainerDlg::OnBnClickedButton6)
	ON_BN_CLICKED(ID_Done, &CFV2TrainerDlg::OnBnClickedDone)
	ON_BN_CLICKED(IDC_BUTTON7, &CFV2TrainerDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON9, &CFV2TrainerDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON1, &CFV2TrainerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CFV2TrainerDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CFV2TrainerDlg message handlers
void CFV2TrainerDlg::OnFilterDefaultExitKey()
{
	// default exit key handler, ignore everything.
}

BOOL CFV2TrainerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

	ShowWindow(SW_MINIMIZE);

	// TODO: Add extra initialization here

	m_GetTractorC.EnableWindowsTheming(FALSE);
	m_GetTractorC.m_nFlatStyle = CMFCButton::BUTTONSTYLE_3D;
	m_GetTractorC.SetFaceColor(RGB(90, 90, 90), true);
	m_GetTractorC.SetTextColor(RGB(255, 127, 80));

	m_SwapCode.EnableWindowsTheming(FALSE);
	m_SwapCode.m_nFlatStyle = CMFCButton::BUTTONSTYLE_3D;
	m_SwapCode.SetFaceColor(RGB(90, 90, 90), true);
	m_SwapCode.SetTextColor(RGB(255, 127, 80));

	m_Twins.EnableWindowsTheming(FALSE);
	m_Twins.m_nFlatStyle = CMFCButton::BUTTONSTYLE_3D;
	m_Twins.SetFaceColor(RGB(90, 90, 90), true);
	m_Twins.SetTextColor(RGB(255, 127, 80));

	m_Hugs.EnableWindowsTheming(FALSE);
	m_Hugs.m_nFlatStyle = CMFCButton::BUTTONSTYLE_3D;
	m_Hugs.SetFaceColor(RGB(90, 90, 90), true);
	m_Hugs.SetTextColor(RGB(255, 127, 80));

	m_ExitButton.EnableWindowsTheming(FALSE);
	m_ExitButton.m_nFlatStyle = CMFCButton::BUTTONSTYLE_3D;
	m_ExitButton.SetFaceColor(RGB(70, 70, 70), true);
	m_ExitButton.SetTextColor(RGB(255, 127, 80));

	m_extendCert.EnableWindowsTheming(FALSE);
	m_extendCert.m_nFlatStyle = CMFCButton::BUTTONSTYLE_3D;
	m_extendCert.SetFaceColor(RGB(90, 90, 90), true);
	m_extendCert.SetTextColor(RGB(255, 127, 80));

	m_SuperMode.EnableWindowsTheming(FALSE);
	m_SuperMode.m_nFlatStyle = CMFCButton::BUTTONSTYLE_3D;
	m_SuperMode.SetFaceColor(RGB(200, 0, 0), true);
	m_SuperMode.SetTextColor(RGB(255, 255, 255));

	m_Mode2.EnableWindowsTheming(FALSE);
	m_Mode2.m_nFlatStyle = CMFCButton::BUTTONSTYLE_3D;
	m_Mode2.SetFaceColor(RGB(200, 0, 0), true);
	m_Mode2.SetTextColor(RGB(255, 255, 255));

	m_kitchenCraft.EnableWindowsTheming(FALSE);
	m_kitchenCraft.m_nFlatStyle = CMFCButton::BUTTONSTYLE_3D;
	m_kitchenCraft.SetFaceColor(RGB(90, 90, 90), true);
	m_kitchenCraft.SetTextColor(RGB(255, 127, 80));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFV2TrainerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFV2TrainerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFV2TrainerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CFV2TrainerDlg::OnEraseBkgnd(CDC* pDC)
{
	CRect r;
	GetClientRect(&r);
	CBrush br(RGB(50, 50, 50));
	pDC->SelectObject(br);
	pDC->FillRect(r, &br);

	return TRUE;
}

BOOL gameStatus = FALSE;
DWORD procId = 0;
char kitchen = 'z';

//Code Swapping
void CFV2TrainerDlg::OnBnClickedButton3()
{
	if (gameStatus)
	{
		char Code1[60] = {0};
		UINT nCountOfCharacters = GetDlgItemText(IDC_EDIT1, Code1, 60);

		char Code2[60] = {0};
		UINT nCountOfCharacters2 = GetDlgItemText(IDC_EDIT2, Code2, 60);

		unsigned int code1Size = 0;
		unsigned int code2Size = 0;

		SYSTEM_INFO sysInfo;
		GetSystemInfo(&sysInfo);
		LPVOID procMin = sysInfo.lpMinimumApplicationAddress;
		LPVOID procMax = sysInfo.lpMaximumApplicationAddress;

		char* cCode1 = charCounterTrim(Code1, code1Size);
		char* cCode2 = charCounterTrim(Code2, code2Size);

		if (code1Size == 0 || code2Size == 0)
		{
			MessageBoxA("Please try again!\n\nCodes must be the same size\n\nand Codes must be less than 60 character length");
		}
		else if(code1Size >= 60 || code2Size >= 60 || code1Size != code2Size)
		{
			MessageBoxA("Please try again!\n\nCodes must be the same size\n\nand Codes must be less than 60 character length");
		}
		else if (code1Size == code2Size && code1Size <= 60)
		{
			std::vector<char*> vecResult;
			HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);
			PatternScanWrapperCode(cCode1, code1Size, (char*)procMin, (char*)procMax, hProcess, vecResult);
			WritePatternCode2(cCode2, code2Size, vecResult, hProcess);
			if (vecResult.size() != 0)
			{
				MessageBoxA("Code Swapping is done!");
			}
			else
			{
				MessageBoxA("Please reload your game and try again...");
			}
			CloseHandle(hProcess);
		}
	}
	else
	{
		MessageBoxA("Please Turn ON Trainer MODE 1 or MODE 2");
	}
}


void CFV2TrainerDlg::OnBnClickedButton2()
{
	if (gameStatus)
	{
		char cComboItem[20] = {};
		UINT nCountOfCharacters = GetDlgItemText(IDC_COMBO2, cComboItem, 20);
		BOOL selectionMade = FALSE;

		char* cCode1 = {};
		char* cCode2 = {};
		unsigned int codeSize = 0;

		if (cComboItem[2] == 'l')
		{
			cCode1 = "e_rare_crafted_cupcake_orange_heirloom";
			cCode2 = "e_rare_card_collection_mech_rare_gears";
			codeSize = 38;
			MessageBoxA("1. Open Kitchen and find HEIRLOOM ORANGE CUPCAKE\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make HEIRLOOM ORANGE CUPCAKE");
			selectionMade = TRUE;
		}
		else if (cComboItem[6] == 'y')
		{
			cCode1 = "e_rare_crafted_cake_angel_mango_heirloom";
			cCode2 = "e_rare_card_collection_mech_rare_battery";
			codeSize = 40;
			MessageBoxA("1. Open Kitchen and find HEIRLOOM MANGO ANGEL FRUIT CAKE\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make HEIRLOOM MANGO ANGEL FRUIT CAKE");
			selectionMade = TRUE;
		}
		else if (cComboItem[0] == 'D')
		{
			cCode1 = "e_rare_crafted_cream_ice_honey_lavender";
			cCode2 = "e_rare_card_collection_mech_rare_dynamo";
			codeSize = 39;
			MessageBoxA("1. Open Kitchen and find HONEY LAVENDER ICE CREAM\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make HONEY LAVENDER ICE CREAM");
			selectionMade = TRUE;
		}
		else if (cComboItem[0] == 'E')
		{
			cCode1 = "e_rare_crafted_cupcake_apple_orange_heirloom";
			cCode2 = "e_rare_card_collection_mech_epic_engineblock";
			codeSize = 44;
			MessageBoxA("1. Open Kitchen and find HEIRLOOM ORANGE APPLE CUPCAKE\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make HEIRLOOM ORANGE APPLE CUPCAKE");
			selectionMade = TRUE;
		}
		else if (cComboItem[2] == 'u')
		{
			cCode1 = "e_rare_crafted_pie_apple_anise_heirloom";
			cCode2 = "e_rare_card_collection_mech_rare_gauges";
			codeSize = 39;
			MessageBoxA("1. Open Kitchen and find HEIRLOOM ANISE APPLE PIE\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make HEIRLOOM ANISE APPLE PIE");
			selectionMade = TRUE;
		}
		else if (cComboItem[3] == 'v')
		{
			cCode1 = "e_rare_crafted_quiche_cheese_swiss_lugano";
			cCode2 = "e_rare_card_collection_mech_common_gloves";
			codeSize = 41;
			MessageBoxA("1. Open Kitchen and find LUGANO QUICHE\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make LUGANO QUICHE");
			selectionMade = TRUE;
		}
		else if (cComboItem[7] == 'C')
		{
			cCode1 = "e_rare_crafted_bites_dates_walnut_heirloom";
			cCode2 = "e_rare_card_collection_mech_rare_greasecan";
			codeSize = 42;
			MessageBoxA("1. Open Kitchen and find HEIRLOOM WALNUT STUFFED DATES\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make HEIRLOOM WALNUT STUFFED DATES");
			selectionMade = TRUE;
		}
		else if (cComboItem[2] == 'm')
		{
			cCode1 = "e_rare_crafted_cheese_mascarpone_heirloom";
			cCode2 = "e_rare_card_collection_mech_common_hammer";
			codeSize = 41;
			MessageBoxA("1. Open Kitchen and find HEIRLOOM MASCARPONE\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make HEIRLOOM MASCARPONE");
			selectionMade = TRUE;
		}
		else if (cComboItem[5] == 'D')
		{
			cCode1 = "e_rare_crafted_glazed_walnut_scones_heirloom";
			cCode2 = "e_rare_card_collection_mech_common_handdrill";
			codeSize = 44;
			MessageBoxA("1. Open Kitchen and find HEIRLOOM GLAZED WALNUT SCONES\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make HEIRLOOM GLAZED WALNUT SCONES");
			selectionMade = TRUE;
		}
		else if (cComboItem[6] == 'w')
		{
			cCode1 = "e_rare_crafted_lemon_meringue_pie_heirloom";
			cCode2 = "e_rare_card_collection_mech_common_handsaw";
			codeSize = 42;
			MessageBoxA("1. Open Kitchen and find HEIRLOOM LEMON MERINGUE PIE\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make HEIRLOOM LEMON MERINGUE PIE");
			selectionMade = TRUE;
		}
		else if (cComboItem[6] == 'm')
		{
			cCode1 = "e_rare_crafted_radishes_watercress_sauteed";
			cCode2 = "e_rare_card_collection_mech_epic_headlamps";
			codeSize = 42;
			MessageBoxA("1. Open Kitchen and find SAUTEED WATERCRESS AND RADISHES\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make SAUTEED WATERCRESS AND RADISHES");
			selectionMade = TRUE;
		}
		else if (cComboItem[0] == 'L')
		{
			cCode1 = "e_rare_crafted_lemonade_and_tea_heirloom";
			cCode2 = "e_rare_card_collection_mech_common_level";
			codeSize = 40;
			MessageBoxA("1. Open Kitchen and find HEIRLOOM TEA AND LEMONADE\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make HEIRLOOM TEA AND LEMONADE");
			selectionMade = TRUE;
		}
		else if (cComboItem[3] == 's')
		{
			cCode1 = "e_rare_crafted_crumble_cream_strawberry_heirloom";
			cCode2 = "e_rare_card_collection_mech_common_measuringtape";
			codeSize = 48;
			MessageBoxA("1. Open Kitchen and find HEIRLOOM STRAWBERRY CREAM CRUMBLE\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make HEIRLOOM STRAWBERRY CREAM CRUMBLE");
			selectionMade = TRUE;
		}
		else if (cComboItem[6] == 'I')
		{
			cCode1 = "e_rare_crafted_ratatouille_eggplant_heirloom";
			cCode2 = "e_rare_card_collection_mech_rare_metalingots";
			codeSize = 44;
			MessageBoxA("1. Open Kitchen and find HEIRLOOM EGGPLANT RATATOUILLE\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make HEIRLOOM EGGPLANT RATATOUILLE");
			selectionMade = TRUE;
		}
		else if (cComboItem[0] == 'N')
		{
			cCode1 = "e_rare_crafted_compote_nectarine_beaut_summer";
			cCode2 = "e_rare_card_collection_mech_common_nutsnbolts";
			codeSize = 45;
			MessageBoxA("1. Open Kitchen and find SUMMER BEAUT NECTARINE COMPOTE\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make SUMMER BEAUT NECTARINE COMPOTE");
			selectionMade = TRUE;
		}
		else if (cComboItem[0] == 'P')
		{
			cCode1 = "e_rare_crafted_custard_honey_fig_heirloom";
			cCode2 = "e_rare_card_collection_mech_common_pliers";
			codeSize = 41;
			MessageBoxA("1. Open Kitchen and find HEIRLOOM HONEY FIG CUSTARD\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make HEIRLOOM HONEY FIG CUSTARD");
			selectionMade = TRUE;
		}
		else if (cComboItem[0] == 'R')
		{
			cCode1 = "e_rare_crafted_cake_raisin_apple_heirloom";
			cCode2 = "e_rare_card_collection_mech_epic_radiator";
			codeSize = 41;
			MessageBoxA("1. Open Kitchen and find HEIRLOOM APPLE RAISIN CAKE\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make HEIRLOOM APPLE RAISIN CAKE");
			selectionMade = TRUE;
		}
		else if (cComboItem[1] == 'c')
		{
			cCode1 = "e_rare_crafted_pudding_tapioca_lychee_heirloom";
			cCode2 = "e_rare_card_collection_mech_common_screwdriver";
			codeSize = 46;
			MessageBoxA("1. Open Kitchen and find HEIRLOOM LYCHEE TAPIOCA PUDDING\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make HEIRLOOM LYCHEE TAPIOCA PUDDING");
			selectionMade = TRUE;
		}
		else if (cComboItem[3] == 'f')
		{
			cCode1 = "e_rare_crafted_cherry_cobbler_heirloom";
			cCode2 = "e_rare_card_collection_mech_rare_shaft";
			codeSize = 38;
			MessageBoxA("1. Open Kitchen and find HEIRLOOM CHERRY COBBLER\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make HEIRLOOM CHERRY COBBLER");
			selectionMade = TRUE;
		}
		else if (cComboItem[1] == 'p')
		{
			cCode1 = "e_rare_crafted_pie_pear_caramel_heirloom";
			cCode2 = "e_rare_card_collection_mech_rare_springs";
			codeSize = 40;
			MessageBoxA("1. Open Kitchen and find HEIRLOOM CARAMEL PEAR PIE\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make HEIRLOOM CARAMEL PEAR PIE");
			selectionMade = TRUE;
		}
		else if (cComboItem[1] == 't')
		{
			cCode1 = "e_rare_crafted_cookies_crinkle_lemony_heirloom";
			cCode2 = "e_rare_card_collection_mech_epic_steeringwheel";
			codeSize = 46;
			MessageBoxA("1. Open Kitchen and find HEIRLOOM LEMONY CRINKLE COOKIES\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make HEIRLOOM LEMONY CRINKLE COOKIES");
			selectionMade = TRUE;
		}
		else if (cComboItem[0] == 'T')
		{
			cCode1 = "e_rare_crafted_trifle_apricot_heirloom";
			cCode2 = "e_rare_card_collection_mech_epic_tyres";
			codeSize = 38;
			MessageBoxA("1. Open Kitchen and find HEIRLOOM APRICOT TRIFLE\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make HEIRLOOM APRICOT TRIFLE");
			selectionMade = TRUE;
		}
		else if (cComboItem[0] == 'W')
		{
			cCode1 = "e_rare_crafted_cake_pound_orange_heirloom";
			cCode2 = "e_rare_card_collection_mech_common_wrench";
			codeSize = 41;
			MessageBoxA("1. Open Kitchen and find HEIRLOOM ORANGE POUND CAKE\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make HEIRLOOM ORANGE POUND CAKE");
			selectionMade = TRUE;
		}
		else if(cComboItem[0] == 'S' && cComboItem[1] == 'e')
		{
			cCode1 = "e_rare_crafted_cookies_nutmeg_heirloom";
			cCode2 = "e_rare_card_collection_mech_epic_seats";
			codeSize = 38;
			MessageBoxA("1. Open Kitchen and find HEIRLOOM NUTMEG COOKIE\n\n2. Go back to trainer and click OK, then wait until a message pop up:\n   'Code Swapping done!'\n\n3. Go back to kitchen and make HEIRLOOM NUTMEG COOKIE");
			selectionMade = TRUE;
		}

		if (selectionMade)
		{
			SYSTEM_INFO sysInfo;
			GetSystemInfo(&sysInfo);
			LPVOID procMin = sysInfo.lpMinimumApplicationAddress;
			LPVOID procMax = sysInfo.lpMaximumApplicationAddress;

			std::vector<char*> vecResult;
			HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);
			PatternScanWrapperCode(cCode1, codeSize, (char*)procMin, (char*)procMax, hProcess, vecResult);
			WritePatternCode2(cCode2, codeSize, vecResult, hProcess);
			MessageBoxA("Code Swapping done!");
			CloseHandle(hProcess);
		}
		else
		{
			MessageBoxA("Please Choose a Tractor Card");
		}
	}
	else
	{
		MessageBoxA("Please Turn ON Trainer MODE 1 or MODE 2");
	}
}


void CFV2TrainerDlg::OnBnClickedButton5()
{
	if (gameStatus)
	{
		SYSTEM_INFO sysInfo;
		GetSystemInfo(&sysInfo);
		LPVOID procMin = sysInfo.lpMinimumApplicationAddress;
		LPVOID procMax = sysInfo.lpMaximumApplicationAddress;

		char patternPedigree[] = "\xD0\x30\x20\x80\x00\x00\x63\x00\x24\x00\x63\x00\xD0\xD2\x46";
		char maskPedigree[] = "xxxx??x?xxx?xxx";
		unsigned int patternLength1 = static_cast<unsigned int> (strlen(maskPedigree));

		BYTE nopA[] = { 0xD0, 0x30, 0x24, 0x0F, 0x48 };
		

		char patternTwins[] = "\xD0\x30\x24\x00\xD6\xD0\x66\x00\x00\x00\x12\x11\x00\x00\xD0\x66";
		char maskTwins[] = "xxxxxxx???xxxxxx";
		unsigned int patternLength2 = static_cast<unsigned int> (strlen(maskTwins));

		BYTE nop1[] = { 0xD0, 0x30, 0x24, 0x64, 0x48 };
		unsigned int lengthWrite = 5;


		std::vector<char*> vecResult;
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);
		PatternScanWrapperMask(patternPedigree, maskPedigree, patternLength1, (char*)procMin, (char*)procMax, hProcess, vecResult, 1);

		if (vecResult.size() != 0)
		{
			for (int i = 0; i < vecResult.size(); ++i)
			{
				WritePatternAllFree(vecResult[i], nopA, hProcess, patternLength1, lengthWrite);
			}
		}

		std::vector<char*> vecResult2;
		PatternScanWrapperMask(patternTwins, maskTwins, patternLength2, (char*)procMin, (char*)procMax, hProcess, vecResult2, 3);

		if (vecResult2.size() != 0)
		{
			for (int i = 0; i < vecResult2.size(); ++i)
			{
				WritePatternAllFree(vecResult2[i], nop1, hProcess, patternLength2, lengthWrite);
			}
		}

		if ((vecResult.size() != 0) && (vecResult2.size() != 0))
		{
			MessageBoxA("Guaranteed Twins and Pedigree 5 is ON!\n\nGo to Breeding Barn, Breed Horses or Cows, \n\nYou will always get Twins-Pedigree 5 babies.");
		}
		else
		{
			MessageBoxA("Can't find all codes");
		}
		CloseHandle(hProcess);
	}
	else
	{
		MessageBoxA("Please Turn ON Trainer MODE 1 or MODE 2");
	}
}

void CFV2TrainerDlg::OnBnClickedButton6()
{
	if (gameStatus)
	{
		SYSTEM_INFO sysInfo;
		GetSystemInfo(&sysInfo);
		LPVOID procMin = sysInfo.lpMinimumApplicationAddress;
		LPVOID procMax = sysInfo.lpMaximumApplicationAddress;

		char patternHugs[] = "\x27\xD6\x60\x00\x00\x66\x00\x00\x00\x66\x00\x00\x46\x00\x00\x00\x75\xD7\x60";
		char maskHugs[] = "xxx??x???x??x???xxx";
		unsigned int patternLength = static_cast<unsigned int> (strlen(maskHugs));

		BYTE nopA[] = { 0x26 };
		unsigned int lengthWrite = 1;

		std::vector<char*> vecResult;
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);
		PatternScanWrapperMask(patternHugs, maskHugs, patternLength, (char*)procMin, (char*)procMax, hProcess, vecResult, 1);

		if (vecResult.size() != 0)
		{
			for (int i = 0; i < vecResult.size(); ++i)
			{
				WritePatternAllFree(vecResult[i], nopA, hProcess, patternLength, lengthWrite);
			}
		}


		if (vecResult.size() != 0)
		{
			MessageBoxA("Unlimited Hugs when Visiting Neighbors is ON");
		}
		else
		{
			MessageBoxA("Can't find codes");
		}
		CloseHandle(hProcess);
	}
	else
	{
		MessageBoxA("Please Turn ON Trainer MODE 1 or MODE 2");
	}
}


void CFV2TrainerDlg::OnBnClickedDone()
{
	EndDialog(ID_Done);
}


void CFV2TrainerDlg::OnBnClickedButton7()
{
	if (gameStatus)
	{
		char cComboItem[20] = {};
		UINT nCountOfCharacters = GetDlgItemText(IDC_COMBO3, cComboItem, 20);
		bool selectionMade = false;

		if (cComboItem[1] == '1' || cComboItem[1] == '2' || cComboItem[1] == '3' || cComboItem[1] == '4' || cComboItem[1] == '5')
		{
			selectionMade = true;
		}
		else
		{
			MessageBoxA("Please choose a Multiplier");
		}

		if (selectionMade)
		{
			SYSTEM_INFO sysInfo;
			GetSystemInfo(&sysInfo);
			LPVOID procMin = sysInfo.lpMinimumApplicationAddress;
			LPVOID procMax = sysInfo.lpMaximumApplicationAddress;
			double month = {};
			char codeInput[] = "Powerup\":{\"activePowerups";
			bool pwrUpConfirm = false;

			if (cComboItem[1] == '1')
			{
				month = 2.0;
			}
			else if (cComboItem[1] == '2')
			{
				month = 4.0;
			}
			else if (cComboItem[1] == '3')
			{
				month = 12.0;
			}
			else if (cComboItem[1] == '4')
			{
				month = 36.0;
			}
			else if (cComboItem[1] == '5')
			{
				month = 0.0;
			}

			double timeExtension = (double)month * (double)30 * (double)24 * (double)60 * (double)60 * (double)1000;

			HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);
			char* addyTimer = PatternScan(codeInput, 25, (char*)procMin, (char*)procMax, hProcess);
			if(addyTimer != NULL)
			{
				pwrUpConfirm = FindCertTimers(addyTimer, hProcess, timeExtension);
				if (pwrUpConfirm)
				MessageBoxA("TIMERS EXTENDED \nor REMOVED (if you chose REMOVE ALL)\n\nDO SOME FARMING, VISIT and Help 3 NEIGHBORS and Do More Farming FOR 15-45 MINUTES\nTO MAKE SURE THAT IT IS RECORDED");
			}

			if (addyTimer == NULL || !pwrUpConfirm)
			{
				for (int i = 0; i < 7; ++i)
				{
					addyTimer = PatternScan(codeInput, 25, (char*)procMin, (char*)procMax, hProcess);
					if (addyTimer != NULL)
					{
						pwrUpConfirm = FindCertTimers(addyTimer, hProcess, timeExtension);
						if (pwrUpConfirm)
						{
							MessageBoxA("TIMERS EXTENDED \nor REMOVED (if you chose REMOVE ALL)\n\nDO SOME FARMING, VISIT and Help 3 NEIGHBORS and Do More Farming FOR 15-45 MINUTES\nTO MAKE SURE THAT IT IS RECORDED");
							break;
						}
					}
				}
			}

			if (addyTimer == NULL || !pwrUpConfirm)
			{
				MessageBoxA("Can't find timers\n\nTry to activate this option when your game is still loading all the items on your farm (decorations, crops, trees, animals, etc).");
			}
			CloseHandle(hProcess);
		}
	}
	else
	{
		MessageBoxA("Please Turn ON Trainer MODE 1 or MODE 2");
	}
}

void CFV2TrainerDlg::OnBnClickedButton9()
{
	gameStatus = FALSE;
	procId = 0;
	BOOL gamestatus = FindMyGame(procId);

	if (gamestatus)
	{
		SYSTEM_INFO sysInfo;
		GetSystemInfo(&sysInfo);
		LPVOID procMin = sysInfo.lpMinimumApplicationAddress;
		LPVOID procMax = sysInfo.lpMaximumApplicationAddress;
		char patternAllFree[] = "\xD0\x30\x24\x00\xD6\xD0\x66\x00\x00\x20\x14\x07\x00\x00\x24";
		char maskAllFree[] = "xxxxxxx??xxxxxx";
		unsigned int patternLength1 = static_cast<unsigned int> (strlen(maskAllFree));

		std::vector<char*> vecResult;
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

		PatternScanWrapperMask(patternAllFree, maskAllFree, patternLength1, (char*)procMin, (char*)procMax, hProcess, vecResult, 1);
		if (vecResult.size() != 0)
		{
			gameStatus = TRUE;
			
			char patternQP[] = "\xD0\x30\xD0\x66\x00\x00\x00\x12\x24\x00\x00\xD0\xD0\x66\x00\x00\x00\xD0";
			char maskQP[] = "xxxx???xxxxxxx???x";
			std::vector<char*> vecResultQP;
			PatternScanWrapperMask(patternQP, maskQP, 18, (char*)procMin, (char*)procMax, hProcess, vecResultQP, 1);
			BYTE nopQP[] = { 0x24, 0x0a, 0x48 };
			if (vecResultQP.size() != 0)
			{
				WritePatternAllFree(vecResultQP[0] + 2, nopQP, hProcess, 18, 3);
			}

			BYTE nopA[] = { 0xD0, 0x30, 0x24, 0x00, 0x48 };
			unsigned int lengthWrite = 5;
			if (vecResult.size() != 0)
			{
				for (int i = 0; i < vecResult.size(); ++i)
				{
					WritePatternAllFree(vecResult[i], nopA, hProcess, patternLength1, lengthWrite);
				}
			}

			char patternRB[] = "\xD0\x30\x27\xD5\xD0\x66\x00\x00\x96\x2A\x12\x18\x00\x00\x29";
			char maskRB[] = "xxxxxx??xxxxxxx";
			std::vector<char*> vecResultRB;
			PatternScanWrapperMask(patternRB, maskRB, 15, (char*)procMin, (char*)procMax, hProcess, vecResultRB, 1);
			BYTE nopRB[] = { 0x26, 0x48 };
			if (vecResultRB.size() != 0)
			{
				WritePatternAllFree(vecResultRB[0]+2, nopRB, hProcess, 15, 2);
			}

			char patternM[] = "\x63\x00\xD0\x66\x00\x00\x60\x00\x00\xA2\x75\x63";
			char maskM[] = "x?xx??x??xxx";
			std::vector<char*> vecResultM;
			PatternScanWrapperMask(patternM, maskM, 12, (char*)procMin, (char*)procMax, hProcess, vecResultM, 1);

			BYTE nopM[] = { 0x25, 0x88, 0x27 };
			if (vecResultM.size() != 0)
			{
				WritePatternAllFree(vecResultM[0] + 6, nopM, hProcess, 12, 3);
			}
	
			char patternXp[] = "\xD0\x30\xD0\x66\x00\x00\x00\x60\x00\x00\xA2\x73";
			char maskXp[] = "xxxx???x??xx";
			std::vector<char*> vecResultXp;
			PatternScanWrapperMask(patternXp, maskXp, 12, (char*)procMin, (char*)procMax, hProcess, vecResultXp, 1);
			BYTE nopXp[] = { 0x25, 0x98, 0x75 };
			if (vecResultXp.size() != 0)
			{
				WritePatternAllFree(vecResultXp[0] + 7, nopXp, hProcess, 12, 3);
			}

			char patternFP[] = "\x24\x00\x74\x63\x00\xD0\x46\x00\x00\x00\x00\x80";
			char maskFP[] = "xxxx?xx????x";
			std::vector<char*> vecResultFP;
			PatternScanWrapperMask(patternFP, maskFP, 12, (char*)procMin, (char*)procMax, hProcess, vecResultFP, 1);
			BYTE nopFP[] = { 0x25, 0x98, 0x75 };
			if (vecResultFP.size() != 0)
			{
				WritePatternAllFree(vecResultFP[0], nopFP, hProcess, 12, 3);
			}

			char patternOB[] = "\xD0\x30\x20\x80\x00\x00\xD7\x26\xD5\x60\x00\x00\x66\x00\x00\x00\x66\x00\x00\x80\x00\xD6\xD0\x66\x00\x00\x12\x3F";
			char maskOB[] = "xxxx??xxxx??x???x??x?xxx??xx";
			std::vector<char*> vecResultOB;
			PatternScanWrapperMask(patternOB, maskOB, 28, (char*)procMin, (char*)procMax, hProcess, vecResultOB, 1);
			BYTE nopOB[] = { 0x26, 0x48 };
			if (vecResultOB.size() != 0)
			{
				WritePatternAllFree(vecResultOB[0] + 7, nopOB, hProcess, 28, 2);
			}

			char pattern[] = "\xD0\xD0\x66\x00\x00\x00\x00\x00\x00\x07\xA1\x00\x00\x00\x00\xD0\x24\xFF\x00\x00\x00\x07\xA2";
			char mask[] = "xxx??????xx????xxx???xx";
			unsigned int patternLength2 = static_cast<unsigned int> (strlen(mask));
			BYTE nop1[] = { 0xD0, 0x25, 0xFF, 0x7F, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02 };
			BYTE nop2[] = { 0x25, 0xFF, 0x7F, 0x02, 0x02, 0x02, 0x02 };
			BYTE nop3[] = { 0x26, 0x48 };
			std::vector<char*> vecResult2;

			PatternScanWrapperMask(pattern, mask, patternLength2, (char*)procMin, (char*)procMax, hProcess, vecResult2, 2);
			if (vecResult2.size() != 0)
			{
				for (int i = 0; i < vecResult2.size(); ++i)
				{
					WritePatternTempCash(vecResult2[i], nop1, nop2, nop3, hProcess);
				}
			}

			char patternMentorEvrg[] = "\xD0\x30\x24\x01\xD6\x60\x00\x00\xD1\x46\x00\x00\x00\x96\x2A\x12\x06\x00\x00\x29\xD0";
			char maskMentorEvrg[] = "xxxxxx??xx???xxxxxxxx";
			std::vector<char*> vecResultMentorEvrg;
			PatternScanWrapperMask(patternMentorEvrg, maskMentorEvrg, 21, (char*)procMin, (char*)procMax, hProcess, vecResultMentorEvrg, 1);
			BYTE nopMentorEvrg[] = { 0x25, 0xF4, 0x03, 0x48 };
			if (vecResultMentorEvrg.size() != 0)
			{
				PatternScanWrapperMask(patternMentorEvrg, maskMentorEvrg, 21, (char*)procMin, (char*)procMax, hProcess, vecResultMentorEvrg, 1);
				WritePatternAllFree(vecResultMentorEvrg[0] + 2, nopMentorEvrg, hProcess, 21, 4);
			}

			MessageBoxA("TRAINER MODE1 is ON\n\nOpen General Store, all items should be FREE, buy consumables to get temporary Farmbucks\n(If Market items are not FREE, reload the game and Turn On Mode 1 or Mode 2 when the game's loading bar is around 80%)\n\nOrder board and Rich Order Board are ready to complete\n\nBlue Ribbon is ON\n\nXp x15000\n\nFair points x15000\n\nHarvest animals, crops, trees, get 10x produces\n\nFarmville's Helping Hands, get 500 Mentor Points\n\nNote: If you turned On this mode after the game is fully loaded, some options may not be activated.");

		}
		CloseHandle(hProcess);
	}
	if(!gameStatus)
	{
		MessageBoxA("Reload the game and try again.\n\nNote: If you already have MODE 2 ON, there's no need to also turn on MODE 1.");
		procId = 0;
	}
}

void CFV2TrainerDlg::OnBnClickedButton1()
{
	gameStatus = FALSE;
	procId = 0;
	BOOL gamestatus = FindMyGame(procId);

	if (gamestatus)
	{
		SYSTEM_INFO sysInfo;
		GetSystemInfo(&sysInfo);
		LPVOID procMin = sysInfo.lpMinimumApplicationAddress;
		LPVOID procMax = sysInfo.lpMaximumApplicationAddress;

		char patternAllFree[] = "\xD0\x30\x24\x00\xD6\xD0\x66\x00\x00\x20\x14\x07\x00\x00\x24";
		char maskAllFree[] = "xxxxxxx??xxxxxx";
		unsigned int patternLength1 = static_cast<unsigned int> (strlen(maskAllFree));

		std::vector<char*> vecResult;
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

		PatternScanWrapperMask(patternAllFree, maskAllFree, patternLength1, (char*)procMin, (char*)procMax, hProcess, vecResult, 1);
		if (vecResult.size() != 0)
		{
			gameStatus = TRUE;
			BYTE nopA[] = { 0xD0, 0x30, 0x24, 0x00, 0x48 };
			unsigned int lengthWrite = 5;
			for (int i = 0; i < vecResult.size(); ++i)
			{
				WritePatternAllFree(vecResult[i], nopA, hProcess, patternLength1, lengthWrite);
			}
			char pattern[] = "\xD0\xD0\x66\x00\x00\x00\x00\x00\x00\x07\xA1\x00\x00\x00\x00\xD0\x24\xFF\x00\x00\x00\x07\xA2";
			char mask[] = "xxx??????xx????xxx???xx";
			unsigned int patternLength2 = static_cast<unsigned int> (strlen(mask));
			BYTE nop1[] = { 0xD0, 0x25, 0xFF, 0x7F, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02 };
			BYTE nop2[] = { 0x25, 0xFF, 0x7F, 0x02, 0x02, 0x02, 0x02 };
			BYTE nop3[] = { 0x26, 0x48 };
			std::vector<char*> vecResult2;

			PatternScanWrapperMask(pattern, mask, patternLength2, (char*)procMin, (char*)procMax, hProcess, vecResult2, 2);
			if (vecResult2.size() != 0)
			{
				for (int i = 0; i < vecResult2.size(); ++i)
				{
					WritePatternTempCash(vecResult2[i], nop1, nop2, nop3, hProcess);
				}
			}
			MessageBoxA("TRAINER MODE 2 is ON\n\nOpen General Store, all items should be FREE, buy consumables to get temporary Farmbucks\n\nIf Market items are not FREE, reload the game and Turn On Mode 1 or Mode 2 when the game's loading bar is around 80%");
		}
		CloseHandle(hProcess);
	}
	if (!gameStatus)
	{
		MessageBoxA("Reload the game and try again.\n\nNote: If you already have MODE 1 ON, there's no need to also turn on MODE 2.");
		procId = 0;
	}
}


void CFV2TrainerDlg::OnBnClickedButton4()
{
	if (gameStatus)
	{
		char cComboItem[20] = {};
		UINT nCountOfCharacters = GetDlgItemText(IDC_COMBO1, cComboItem, 20);
		BOOL selectionMade = FALSE;


		if (cComboItem[4] == '0' || cComboItem[1] == '2' || cComboItem[1] == '3' || cComboItem[1] == '4')
		{
			selectionMade = true;
		}
		
		if (selectionMade)
		{
			SYSTEM_INFO sysInfo;
			GetSystemInfo(&sysInfo);
			LPVOID procMin = sysInfo.lpMinimumApplicationAddress;
			LPVOID procMax = sysInfo.lpMaximumApplicationAddress;

			char maskKitchenMultiply[] = "xxxxxxxxxxxxxxxxxxxxxxxxx";
			unsigned int patternLength1 = static_cast<unsigned int> (strlen(maskKitchenMultiply));

			std::vector<char*> vecResult;
			HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

			//40 01 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 FF FF FF FF FF FF FF FF
			if (kitchen == 'z')
			{
				char kitchenMultiply[] = "\x40\x01\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF";
				PatternScanWrapperMaskMultiply(kitchenMultiply, maskKitchenMultiply, patternLength1, (char*)procMin, (char*)procMax, hProcess, vecResult);

			}
			else if (kitchen == 'a')
			{
				char kitchenMultiply[] = "\x40\x64\x00\x00\x00\x64\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF";
				PatternScanWrapperMaskMultiply(kitchenMultiply, maskKitchenMultiply, patternLength1, (char*)procMin, (char*)procMax, hProcess, vecResult);
			}
			else if (kitchen == 'b')
			{
				char kitchenMultiply[] = "\x40\xFA\x00\x00\x00\xFA\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF";
				PatternScanWrapperMaskMultiply(kitchenMultiply, maskKitchenMultiply, patternLength1, (char*)procMin, (char*)procMax, hProcess, vecResult);
			}
			else if (kitchen == 'c')
			{
				char kitchenMultiply[] = "\x40\xFF\xFF\x00\x00\xFF\xFF\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\x7F\xFF\x7F\xFF\xFF\xFF\xFF";
				PatternScanWrapperMaskMultiply(kitchenMultiply, maskKitchenMultiply, patternLength1, (char*)procMin, (char*)procMax, hProcess, vecResult);
			}

			if (cComboItem[4] == '0')	//kitchen x100
			{
				kitchen = 'a';
				//40 64 00 00 00 64 00 00 00 00 00 00 00 00 00 00 00 FF FF FF FF FF FF FF FF
				char codeKitchen[] = "\x40\x64\x00\x00\x00\x64\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF";
				WritePatternCode2(codeKitchen, patternLength1, vecResult, hProcess);
				MessageBoxA("Kitchen-Workshop Craft Multiplier is active!");
				CloseHandle(hProcess);
			}
			else if (cComboItem[1] == '2')	//kitchen x250
			{
				kitchen = 'b';
				//40 FA 00 00 00 FA 00 00 00 00 00 00 00 00 00 00 00 FF FF FF FF FF FF FF FF
				char codeKitchen[] = "\x40\xFA\x00\x00\x00\xFA\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF";
				WritePatternCode2(codeKitchen, patternLength1, vecResult, hProcess);
				MessageBoxA("Kitchen-Workshop Craft Multiplier is active!");
				CloseHandle(hProcess);
			}
			else if (cComboItem[1] == '3')	//kitchen x65535
			{
				kitchen = 'c';
				//40 ff ff 00 00 ff ff 00 00 00 00 00 00 00 00 00 00 FF 7F FF 7F FF FF FF FF
				char codeKitchen[] = "\x40\xDE\x3F\x00\x00\xDE\x3F\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\x7F\xFF\x7F\xFF\xFF\xFF\xFF";
				WritePatternCode2(codeKitchen, patternLength1, vecResult, hProcess);
				MessageBoxA("Kitchen-Workshop Craft Multiplier is active!");
				CloseHandle(hProcess);
			}
			else if (cComboItem[1] == '4')
			{
				SYSTEM_INFO sysInfo;
				GetSystemInfo(&sysInfo);
				LPVOID procMin = sysInfo.lpMinimumApplicationAddress;
				LPVOID procMax = sysInfo.lpMaximumApplicationAddress;
				
				std::vector<char*> vecResult;
				HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

				if (kitchen == 'a')
				{
					char codeKitchenR[] = "\x40\x64\x00\x00\x00\x64\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF";
					char maskKitchenR[] = "xxxxxxxxxxxxxxxxxxxxxxxxx";
					unsigned int patternLength1 = static_cast<unsigned int> (strlen(maskKitchenR));
					char codeKitchen[] = "\x40\x01\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF";

					PatternScanWrapperMaskMultiply(codeKitchenR, maskKitchenR, patternLength1, (char*)procMin, (char*)procMax, hProcess, vecResult);

					WritePatternCode2(codeKitchen, patternLength1, vecResult, hProcess);
					kitchen = 'z';
					MessageBoxA("Kitchen-Workshop Craft Multiplier is OFF!");
					CloseHandle(hProcess);
				}
				else if (kitchen == 'b')
				{
					char codeKitchenR[] = "\x40\xFA\x00\x00\x00\xFA\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF";
					char maskKitchenR[] = "xxxxxxxxxxxxxxxxxxxxxxxxx";
					unsigned int patternLength1 = static_cast<unsigned int> (strlen(maskKitchenR));
					char codeKitchen[] = "\x40\x01\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF";

					PatternScanWrapperMaskMultiply(codeKitchenR, maskKitchenR, patternLength1, (char*)procMin, (char*)procMax, hProcess, vecResult);

					WritePatternCode2(codeKitchen, patternLength1, vecResult, hProcess);
					kitchen = 'z';
					MessageBoxA("Kitchen-Workshop Craft Multiplier is OFF!");
					CloseHandle(hProcess);
				}
				else if (kitchen == 'c')
				{
					char codeKitchenR[] = "\x40\xDE\x3F\x00\x00\xDE\x3F\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\x7F\xFF\x7F\xFF\xFF\xFF\xFF";
					char maskKitchenR[] = "xxxxxxxxxxxxxxxxxxxxxxxxx";
					unsigned int patternLength1 = static_cast<unsigned int> (strlen(maskKitchenR));
					char codeKitchen[] = "\x40\x01\x00\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF";

					PatternScanWrapperMaskMultiply(codeKitchenR, maskKitchenR, patternLength1, (char*)procMin, (char*)procMax, hProcess, vecResult);

					WritePatternCode2(codeKitchen, patternLength1, vecResult, hProcess);
					kitchen = 'z';
					MessageBoxA("Kitchen-Workshop Craft Multiplier is OFF!");
					CloseHandle(hProcess);
				}
			}
		}
		else
		{
			MessageBoxA("Please Choose a Multiplier");
		}
	}
	else
	{
		MessageBoxA("Please Turn ON Trainer MODE 1 or MODE 2");
	}
}

