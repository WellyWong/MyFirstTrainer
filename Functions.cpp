#include "pch.h"
#include "Functions.h"

BOOL FindMyGame(DWORD& procId)
{
	BOOL gamestatus = FALSE;
	DWORD procid = 0;
	std::vector<std::string> browserClassNames
	{
		"Chrome_WidgetWin_1",        
		//"MozillaWindowClass",
		"EdgeUiInputWndClass",
		"Maxthon3Cls_MainFrm"
	};

	std::vector<std::string> activeBrowser{};

	for (auto const& name : browserClassNames)
	{
		if (FindWindow(name.c_str(), NULL) != NULL)
		{
			if (name == "Chrome_WidgetWin_1")
			{
				activeBrowser.push_back("chrome.exe");
				activeBrowser.push_back("opera");
				activeBrowser.push_back("torch");
				activeBrowser.push_back("dragon");
			}
			else if (name == "EdgeUiInputWndClass")
			{
				activeBrowser.push_back("MicrosoftEdge");
			}
			else if (name == "Maxthon3Cls_MainFrm")
			{
				activeBrowser.push_back("Maxthon.exe");
			}
		}
	}

	for (auto i : activeBrowser)
	{
		procid = FindGameProcId(i.c_str());
		if (procid)
		{
			gamestatus = FindGameModule(procid);
			if (gamestatus)
			{
				procId = procid;
				return TRUE;
			}
		}
	}

	if (!gamestatus) //check for when Firefox, icedragon.exe (uses same plugins as Firefox) and launcher active
	{
		DWORD procIdFirefox32 = 0;
		DWORD procIdFirefox64 = 0;
		DWORD procIdLauncher = 0;
		SIZE_T firefox32MemUsage = 0;
		SIZE_T firefox64Memusage = 0;
		SIZE_T launcherMemusage = 0;

		procIdFirefox32 = FindGameProcId2("FlashPlayerPlugin", firefox32MemUsage);
		if (procIdFirefox32)
		{
			procIdLauncher = GetProcId("Farmville Two.exe", launcherMemusage);
			if (procIdLauncher)
			{
				if (launcherMemusage > firefox32MemUsage)
				{
					procId = procIdLauncher;
					gamestatus = TRUE;
					return TRUE;
				}
				else
				{
					procId = procIdFirefox32;
					gamestatus = TRUE;
					return TRUE;
				}
			}

		}
		procIdFirefox64 = GetProcId("plugin-container.exe", firefox64Memusage);
		if (procIdFirefox64)
		{
			procIdLauncher = GetProcId("Farmville Two.exe", launcherMemusage);
			if (procIdLauncher)
			{
				if (launcherMemusage > firefox64Memusage)
				{
					procId = procIdLauncher;
					gamestatus = TRUE;
					return TRUE;
				}
				else
				{
					procId = procIdFirefox64;
					gamestatus = TRUE;
					return TRUE;
				}
			}
		}
	}

	//If facebook gameroom and launcher are active, find one with the most memory usage
	if (!gamestatus)
	{
		DWORD procIdLauncher = 0;
		DWORD procIdGameroom = 0;
		SIZE_T launcherMemUsage = 0;
		SIZE_T gameroomMemUsage = 0;

		procIdLauncher = GetProcId("Farmville Two.exe", launcherMemUsage);

		procIdGameroom = FindGameProcId2("Facebook", gameroomMemUsage);

		if (procIdLauncher && procIdGameroom)
		{
			if (launcherMemUsage > gameroomMemUsage)
			{
				procId = FindGameProcId("Farmville Two.exe");
				gamestatus = TRUE;
				return TRUE;
			}
			else
			{
				procId = procIdGameroom;
				gamestatus = TRUE;
				return TRUE;
			}
		}
		else if (procIdLauncher)
		{
			procId = FindGameProcId("Farmville Two.exe");
			gamestatus = TRUE;
			return TRUE;
		}
		else if (procIdGameroom)
		{
			procId = procIdGameroom;
			gamestatus = TRUE;
			return TRUE;
		}
	}

	//check for when firefox active, both plugins for 32 and 64 bit could possibly still running
	if (!gamestatus)
	{
		DWORD procId32 = 0;
		DWORD procId64 = 0;
		SIZE_T _32MemUsage = 0;
		SIZE_T _64MemUsage = 0;
		procId64 = GetProcId("plugin-container.exe", _64MemUsage);
		procId32 = FindGameProcId2("FlashPlayerPlugin", _32MemUsage);

		if (procId32 && procId64)
		{
			if (_64MemUsage > _32MemUsage)
			{
				procId = procId64;
				gamestatus = TRUE;
				return TRUE;
			}
			else
			{
				procId = procId32;
				gamestatus = TRUE;
				return TRUE;
			}
		}
		else if (procId32)
		{
			procId = procId32;
			gamestatus = TRUE;
			return TRUE;
		}
		else if (procId64)
		{
			procId = procId64;
			gamestatus = TRUE;
			return TRUE;
		}
	}

	if (!gamestatus)
	{
		procId = FindGameProcId("Farmville Two.exe");
		if (procId) gamestatus = TRUE;
	}

	return gamestatus;
}


DWORD GetProcId(const char* procName, SIZE_T& launcherMemUsage)
{
	HANDLE hProcess = 0;
	PROCESS_MEMORY_COUNTERS pmc;
	std::vector<SIZE_T> peakWorkingSetSize{ 0 };
	std::vector<DWORD> processId{ 0 };

	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hSnap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 procEntry;
		procEntry.dwSize = sizeof(procEntry);

		if (Process32First(hSnap, &procEntry))
		{
			do
			{
				if (!std::strncmp(procEntry.szExeFile, procName, 5))
				{
					hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procEntry.th32ProcessID);

					if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
					{
						peakWorkingSetSize.push_back(pmc.PeakWorkingSetSize);
						processId.push_back(procEntry.th32ProcessID);
					}
					CloseHandle(hProcess);
				}
			} while (Process32Next(hSnap, &procEntry));
		}
	}
	CloseHandle(hSnap);

	if (processId.empty())
	{
		return 0;
	}

	auto maxElementIndex = std::max_element(peakWorkingSetSize.begin(), peakWorkingSetSize.end()) - peakWorkingSetSize.begin();
	launcherMemUsage = peakWorkingSetSize.at(maxElementIndex);
	return processId.at(maxElementIndex);
}

DWORD GetProcId2(const char* procName)
{
	DWORD processId = 0;
	HANDLE hSnap = 0;
	hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hSnap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 procEntry;
		procEntry.dwSize = sizeof(procEntry);
		if (Process32First(hSnap, &procEntry))
		{
			do
			{
				if (!std::strncmp(procEntry.szExeFile, procName, 5))
				{
					processId = procEntry.th32ProcessID;
					break;
				}
			} while (Process32Next(hSnap, &procEntry));
		}
		CloseHandle(hSnap);
	}
	return processId;
}

DWORD FindGameProcId(const char* procName) 
{
	HANDLE hProcess = 0;
	PROCESS_MEMORY_COUNTERS pmc;
	std::vector<SIZE_T> peakWorkingSetSize{0};
	std::vector<DWORD> processId{0};

	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hSnap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 procEntry;
		procEntry.dwSize = sizeof(procEntry);

		if (Process32First(hSnap, &procEntry))
		{
			do
			{
				if (!std::strncmp(procEntry.szExeFile, procName, 5)) 
				{
					hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procEntry.th32ProcessID);

					if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
					{
						peakWorkingSetSize.push_back(pmc.PeakWorkingSetSize);
						processId.push_back(procEntry.th32ProcessID);
					}
					CloseHandle(hProcess);
				}
			} while (Process32Next(hSnap, &procEntry));
		}
	}
	CloseHandle(hSnap);

	if (processId.empty())
	{
		return 0;
	}

	auto maxElementIndex = std::max_element(peakWorkingSetSize.begin(), peakWorkingSetSize.end()) - peakWorkingSetSize.begin();

	return processId.at(maxElementIndex);
}

DWORD FindGameProcId2(const char* procName, SIZE_T& MemUsage)
{
	HANDLE hProcess = 0;
	PROCESS_MEMORY_COUNTERS pmc;
	std::vector<SIZE_T> peakWorkingSetSize{0};
	std::vector<DWORD> processId{0};

	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hSnap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 procEntry;
		procEntry.dwSize = sizeof(procEntry);

		if (Process32First(hSnap, &procEntry))
		{
			do
			{
				if (!std::strncmp(procEntry.szExeFile, procName, 5))
				{
					hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procEntry.th32ProcessID);

					if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
					{
						peakWorkingSetSize.push_back(pmc.PeakWorkingSetSize);
						processId.push_back(procEntry.th32ProcessID);
					}
					CloseHandle(hProcess);
				}
			} while (Process32Next(hSnap, &procEntry));
		}
	}
	CloseHandle(hSnap);

	if (processId.empty())
	{
		return 0;
	}

	auto maxElementIndex = std::max_element(peakWorkingSetSize.begin(), peakWorkingSetSize.end()) - peakWorkingSetSize.begin();
	MemUsage = peakWorkingSetSize.at(maxElementIndex);
	return processId.at(maxElementIndex);
}

BOOL FindGameModule(DWORD procId)
{
	BOOL gamestatus = FALSE;
	HANDLE hSnap = 0;
	hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
	
	if (hSnap != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 modEntry = { 0 };
		modEntry.dwSize = sizeof(modEntry);
		char* arr = modEntry.szExePath;

		if (Module32First(hSnap, &modEntry))
		{
			do
			{
				if (std::string(arr).find("Flash") != std::string::npos || std::string(arr).find("flash") != std::string::npos
					|| !_stricmp(modEntry.szModule, "Adobe AIR.dll"))
				{
					gamestatus = TRUE;
					break;
				}
			} while (Module32Next(hSnap, &modEntry));
		}
	}
	CloseHandle(hSnap);
	return gamestatus;
}


void PatternScanWrapperMask(char* pattern, char* mask, unsigned int patternLength, char* begin, char* end, HANDLE hProcess, std::vector<char*>& vecResult, int vecLength)
{
	char* currentChunk = begin;
	char* match = nullptr;
	SIZE_T bytesRead = 0;

	while (currentChunk < end)
	{
		MEMORY_BASIC_INFORMATION mbi;
		if (!VirtualQueryEx(hProcess, currentChunk, &mbi, sizeof(mbi)))
		{
			break;
		}
		if (mbi.State == MEM_COMMIT && mbi.Protect != PAGE_NOACCESS)
		{
			DWORD oldprotect;
			char* buffer = new char[mbi.RegionSize];

			if (VirtualProtectEx(hProcess, mbi.BaseAddress, mbi.RegionSize, PAGE_EXECUTE_READWRITE, &oldprotect))
			{
				ReadProcessMemory(hProcess, mbi.BaseAddress, buffer, mbi.RegionSize, &bytesRead);
				VirtualProtectEx(hProcess, mbi.BaseAddress, mbi.RegionSize, oldprotect, &oldprotect);

				for (unsigned int i = 0; i < (bytesRead - patternLength); i++)
				{
					bool found = true;
					for (unsigned int j = 0; j < patternLength; j++)
					{
						if (mask[j] != '?' && pattern[j] != *(buffer + i + j))
						{
							found = false;
							break;
						}
					}
					if (found)
					{
						vecResult.push_back(currentChunk + i);
						if (vecResult.size() >= vecLength)
						{
							delete[] buffer;
							buffer = nullptr;
							return;
						}
					}
				}
			}
			delete[] buffer;
			buffer = nullptr;
		}
		currentChunk = currentChunk + mbi.RegionSize;
	}
}

void WritePatternTempCash(char* match, BYTE* nop1, BYTE* nop2, BYTE* nop3, HANDLE hProcess)
{
	DWORD oldprotect;
	VirtualProtectEx(hProcess, match, 30, PAGE_READWRITE, &oldprotect);

	WriteProcessMemory(hProcess, match, nop1, 11, NULL);
	WriteProcessMemory(hProcess, match + 16, nop2, 7, NULL);
	WriteProcessMemory(hProcess, match + 28, nop3, 2, NULL);

	VirtualProtectEx(hProcess, match, 30, oldprotect, &oldprotect);
}

void WritePatternAllFree(char* match, BYTE* nopA, HANDLE hProcess, unsigned int lengthProtect, unsigned int lengthWrite)
{
	DWORD oldprotect;
	VirtualProtectEx(hProcess, match, lengthProtect, PAGE_READWRITE, &oldprotect);

	WriteProcessMemory(hProcess, match, nopA, lengthWrite, NULL);

	VirtualProtectEx(hProcess, match, lengthProtect, oldprotect, &oldprotect);
}

void PatternScanWrapperCode(char* pattern, unsigned int codeInputSize, char* begin, char* end, HANDLE hProcess, std::vector<char*>& vecResult)
{
	char* currentChunk = begin; 
	char* match = nullptr;
	SIZE_T bytesRead = 0;

	while (currentChunk < end)
	{
		MEMORY_BASIC_INFORMATION mbi;
		if (!VirtualQueryEx(hProcess, currentChunk, &mbi, sizeof(mbi)))
		{
			break;
		}
		if (mbi.State == MEM_COMMIT && mbi.Protect != PAGE_NOACCESS)
		{
			DWORD oldprotect;
			char* buffer = new char[mbi.RegionSize];

			if (VirtualProtectEx(hProcess, mbi.BaseAddress, mbi.RegionSize, PAGE_EXECUTE_READWRITE, &oldprotect))
			{
				ReadProcessMemory(hProcess, mbi.BaseAddress, buffer, mbi.RegionSize, &bytesRead);
				VirtualProtectEx(hProcess, mbi.BaseAddress, mbi.RegionSize, oldprotect, &oldprotect);

				for (unsigned int i = 0; i < (bytesRead - codeInputSize); i++)
				{
					bool found = true;
					for (unsigned int j = 0; j < codeInputSize; j++)
					{
						if (pattern[j] != *(buffer + i + j))
						{
							found = false;
							break;
						}
					}
					if (found)
					{
						vecResult.push_back(currentChunk + i);
					}
				}
			}
			delete[] buffer;
			buffer = nullptr;
		}
		currentChunk = currentChunk + mbi.RegionSize;
	}
}

void PatternScanWrapperMaskMultiply(char* pattern, char* mask, unsigned int patternLength, char* begin, char* end, HANDLE hProcess, std::vector<char*>& vecResult)
{
	char* currentChunk = begin;
	char* match = nullptr;
	SIZE_T bytesRead = 0;

	while (currentChunk < end)
	{
		MEMORY_BASIC_INFORMATION mbi;
		if (!VirtualQueryEx(hProcess, currentChunk, &mbi, sizeof(mbi)))
		{
			break;
		}
		if (mbi.State == MEM_COMMIT && mbi.Protect != PAGE_NOACCESS)
		{
			DWORD oldprotect;
			char* buffer = new char[mbi.RegionSize];

			if (VirtualProtectEx(hProcess, mbi.BaseAddress, mbi.RegionSize, PAGE_EXECUTE_READWRITE, &oldprotect))
			{
				ReadProcessMemory(hProcess, mbi.BaseAddress, buffer, mbi.RegionSize, &bytesRead);
				VirtualProtectEx(hProcess, mbi.BaseAddress, mbi.RegionSize, oldprotect, &oldprotect);

				for (unsigned int i = 0; i < (bytesRead - patternLength); i++)
				{
					bool found = true;
					for (unsigned int j = 0; j < patternLength; j++)
					{
						if (mask[j] != '?' && pattern[j] != *(buffer + i + j))
						{
							found = false;
							break;
						}
					}
					if (found)
					{
						vecResult.push_back(currentChunk + i);
					}
				}
			}
			delete[] buffer;
			buffer = nullptr;
		}
		currentChunk = currentChunk + mbi.RegionSize;
	}
}

char* PatternScan(char* pattern, unsigned int codeInputSize, char* begin, char* end, HANDLE hProcess)
{
	char* currentChunk = begin;
	char* match = nullptr;
	SIZE_T bytesRead = 0;

	while (currentChunk < end)
	{
		MEMORY_BASIC_INFORMATION mbi;
		if (!VirtualQueryEx(hProcess, currentChunk, &mbi, sizeof(mbi)))
		{
			break;
		}
		if (mbi.State == MEM_COMMIT && mbi.Protect != PAGE_NOACCESS)
		{
			DWORD oldprotect;
			char* buffer = new char[mbi.RegionSize];

			if (VirtualProtectEx(hProcess, mbi.BaseAddress, mbi.RegionSize, PAGE_EXECUTE_READWRITE, &oldprotect))
			{
				ReadProcessMemory(hProcess, mbi.BaseAddress, buffer, mbi.RegionSize, &bytesRead);
				VirtualProtectEx(hProcess, mbi.BaseAddress, mbi.RegionSize, oldprotect, &oldprotect);

				for (unsigned int i = 0; i < (bytesRead - codeInputSize); i++)
				{
					bool found = true;
					for (unsigned int j = 0; j < codeInputSize; j++)
					{
						if (pattern[j] != *(buffer + i + j))
						{
							found = false;
							break;
						}
					}
					if (found)
					{
						return (currentChunk + i);
					}
				}
			}
			delete[] buffer;
			buffer = nullptr;
		}
		currentChunk = currentChunk + mbi.RegionSize;
	}
	return NULL;
}

char* charCounterTrim(char* codeInputs, unsigned int& numChars)
{
	unsigned int i = static_cast<unsigned int>(strlen(codeInputs));
	if (codeInputs[0] == '\0')
	{
		numChars = 0;
		return codeInputs;
	}
	while (codeInputs[--i] == ' ')
	{
		codeInputs[i] = 0;
	}
	numChars = i + 1;
	return codeInputs;
}

void WritePatternCode2(char* codeInput2, int codeInput2Size, std::vector<char*> vecResult, HANDLE hProcess)
{
	for (int i = 0; i < vecResult.size(); ++i)
	{
		DWORD oldprotect;
		VirtualProtectEx(hProcess, vecResult[i], codeInput2Size, PAGE_READWRITE, &oldprotect);

		WriteProcessMemory(hProcess, vecResult[i], codeInput2, codeInput2Size, NULL);

		VirtualProtectEx(hProcess, vecResult[i], codeInput2Size, oldprotect, &oldprotect);
	}
}


void WritePatternCode4(char* codeInput2, int codeInput2Size, std::vector<char*> vecResult, HANDLE hProcess, int ofsets)
{
	for (int i = 0; i < vecResult.size(); ++i)
	{
		DWORD oldprotect;
		VirtualProtectEx(hProcess, vecResult[i], codeInput2Size, PAGE_READWRITE, &oldprotect);

		WriteProcessMemory(hProcess, vecResult[i]+ofsets, codeInput2, codeInput2Size, NULL);

		VirtualProtectEx(hProcess, vecResult[i], codeInput2Size, oldprotect, &oldprotect);
	}
}

void WritePatternInt(int coins, std::vector<char*> vecResult, HANDLE hProcess)
{
	for (int i = 0; i < vecResult.size(); ++i)
	{
		DWORD oldprotect;
		VirtualProtectEx(hProcess, vecResult[i], 4, PAGE_READWRITE, &oldprotect);

		WriteProcessMemory(hProcess, vecResult[i], (char*)&coins, 4, NULL);

		VirtualProtectEx(hProcess, vecResult[i], 4, oldprotect, &oldprotect);
	}
}

bool FindCertTimers(char* addy, HANDLE hProcess, double timeExtension)
{
	SIZE_T size = 450;  //try to reduce this 1200 number, assuming 8-10 active certificates
	char* buffer = new char[size];
	DWORD oldProtect;
	SIZE_T bytesRead;
	char timer[14] = { 0 };
	const char* namePwrUp = "Powerup";

	SYSTEM_INFO sysInfo; // Holds System Information
	GetSystemInfo(&sysInfo);
	LPVOID procMin = sysInfo.lpMinimumApplicationAddress;  // Minimum memory address of process
	LPVOID procMax = sysInfo.lpMaximumApplicationAddress;

	VirtualProtectEx(hProcess, addy, size, PAGE_READWRITE, &oldProtect);
	ReadProcessMemory(hProcess, addy, buffer, size, &bytesRead);

	VirtualProtectEx(hProcess, addy, size, oldProtect, &oldProtect);

	//confirm that it's not empty, check: Powerup":{"activePowerups":{"data":{"
	//if (!std::strncmp(procEntry.szExeFile, procName, 5))  strncmp return 0 if the contents of both strings are equal
	if (!std::strncmp(buffer, namePwrUp, 7) )
	{

	}
	else
	{
		delete[] buffer;
		buffer = nullptr;
		return false;
	}

	//find 13 digits number, push each 13-digits found into vecTimers
	for (unsigned int i = 0; i < bytesRead; ++i)
	{
		if (isdigit(buffer[i]))
		{
			unsigned int j;
			for (j = 0; j < 13; j++)
			{
				timer[j] = buffer[ i + j];
				if (!isdigit(buffer[ i + j]))
				{
					break;
				}
			}
			if (j == 13)
			{
				std::vector<char*> vecResult2;
				double d = std::stod(timer, nullptr);
				PatternScanWrapperCode((char*)&d, 8, (char*)procMin, (char*)procMax, hProcess, vecResult2);

				if (timeExtension == 0.0)
				{
					d = (double)0;
				}
				else
				{
					d += timeExtension;
				}

				if (vecResult2.size() != 0)
				{
					if(*(buffer+i-15) == 'w' && *(buffer+i-14) == 'w')
					{

					}
					else
					{
						for (unsigned int k = 0; k < vecResult2.size(); ++k)
						{
							DWORD oldprotect;
							VirtualProtectEx(hProcess, vecResult2[k], 8, PAGE_READWRITE, &oldprotect);  //change 30 to less, 8 or 10?

							WriteProcessMemory(hProcess, vecResult2[k], (char*)&d, 8, NULL);

							VirtualProtectEx(hProcess, vecResult2[k], 8, oldprotect, &oldprotect); //change 30 to less, 8 or 10?
						}
					}
				}

				i += 12;
			}
		}
		if (buffer[i + 1] == '}' && buffer[i + 2] == '}' && buffer[i + 3] == '}')
		{
			break;
		}
	}
	delete[] buffer;
	buffer = nullptr;
	return true;
}