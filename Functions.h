#pragma once
#include <TlHelp32.h>
#include <Psapi.h>
#include <vector>
#include <algorithm>
#include <string>

BOOL FindMyGame(DWORD& procId);
DWORD GetProcId(const char* procName, SIZE_T& launcherMemUsage);
DWORD GetProcId2(const char* procName);
DWORD FindGameProcId(const char* procName);
DWORD FindGameProcId2(const char* procName, SIZE_T& MemUsage);
BOOL FindGameModule(DWORD procId);
void WritePatternTempCash(char* match, BYTE* nop1, BYTE* nop2, BYTE* nop3, HANDLE hProcess);
void WritePatternAllFree(char* match, BYTE* nopA, HANDLE hProcess, unsigned int lengthProtect, unsigned int lengthWrite);
void PatternScanWrapperCode(char* pattern, unsigned int codeInputSize, char* begin, char* end, HANDLE hProcess, std::vector<char*>& vecResult);
void PatternScanWrapperMask(char* pattern, char* mask, unsigned int patternLength, char* begin, char* end, HANDLE hProcess, std::vector<char*>& vecResult, int vecLength);
char* PatternScan(char* pattern, unsigned int codeInputSize, char* begin, char* end, HANDLE hProcess);
char* charCounterTrim(char* codeInputs, unsigned int& numChars);
void WritePatternCode2(char* codeInput2, int codeInput2Size, std::vector<char*> vecResult, HANDLE hProcess);
bool FindCertTimers(char* addy, HANDLE hProcess, double timeExtension);
void PatternScanWrapperMaskMultiply(char* pattern, char* mask, unsigned int patternLength, char* begin, char* end, HANDLE hProcess, std::vector<char*>& vecResult);
void WritePatternCode4(char* codeInput2, int codeInput2Size, std::vector<char*> vecResult, HANDLE hProcess, int ofsets);
void WritePatternInt(int coins, std::vector<char*> vecResult, HANDLE hProcess);