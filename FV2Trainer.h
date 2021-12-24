
// FV2Trainer.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CFV2TrainerApp:
// See FV2Trainer.cpp for the implementation of this class
//

class CFV2TrainerApp : public CWinApp
{
public:
	CFV2TrainerApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CFV2TrainerApp theApp;