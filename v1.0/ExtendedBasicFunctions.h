#ifndef EXTENDEDBASICFUNCTION_H
#define EXTENDEDBASICFUNCTION_H

#define ERROR_ICON 16
#define QUEST_ICON 32
#define WARNING_ICON 48
#define INFO_ICON 64

#define MK_OK 0
#define MK_OK_CANCEL 1
#define MK_YES_NO 4
#define MK_RETRY_CANCEL 5
#define MK_ABORT_RETRY_IGNORE 2

#define MK_MAIN_1 0
#define MK_MAIN_2 256
#define MK_MAIN_3 512

#define ID_MK_OK 1
#define ID_MK_CANCEL 2
#define ID_MK_YES 6
#define ID_MK_NO 7
#define ID_MK_ABORT 3
#define ID_MK_RETRY 4
#define ID_MK_IGNORE 5

#define MKDIR_ERROR 0
#define MKDIR_OK 1

#define DELETE_FILE_ERROR 0
#define DELETE_FILE_OK 1

#include <string>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <algorithm>

class ExtString
{
public:
	std::string CutString(std::string Data, int StartIndex, int EndIndex)
	{
		std::string Result;
		for (int Index = StartIndex; Index < EndIndex + 1; Index++)
		{
			Result += Data[Index];
		}
		return Result;
	}
};

class ExtConsole
{
public:
	void Clear()
	{
		system("cls");
	}
	void Continue()
	{
		system("pause");
	}
	void SetTitle(std::string Title)
	{
		system((std::string("Title ") + Title).c_str());
	}
	void Stop(int mSecond)
	{
		Sleep(mSecond);
	}
	void PrintTextA(std::string Data, int mSecond)
	{
		for (char Char : Data)
		{
			std::cout << Char;
			Stop(mSecond);
		}
		std::cout << std::endl;
	}
	void PrintTextB(std::string Data, int mSecond)
	{
		for (int i = Data.size() - 1; i >= 0; i--)
		{
			std::cout << Data[i];
			Stop(mSecond);
		}
		std::cout << "\r \r";
		std::cout << Data << std::endl;
	}
	std::string Input(std::string Message)
	{
		std::string Result;
		std::cout << Message;
		std::getline(std::cin, Result);
		return Result;
	}
	int GetKey()
	{
		return _getch();
	}
	int Exit(int CodeExit = 0)
	{
		ExitProcess(CodeExit);
	}
};

class ExtWindows
{
public:
	int Message(std::string TextMessage, std::string TitleMessage, unsigned int Keys)
	{
		int ID_Result = MessageBoxA(NULL, (LPCSTR)TitleMessage.c_str(), (LPCSTR)TitleMessage.c_str(), Keys);
		return ID_Result;
	}
	int Mkdir(std::string Path)
	{
		return CreateDirectoryA((LPCSTR)Path.c_str(), NULL);
	}
	int DeleteFile(std::string Path)
	{
		return DeleteFileA((LPCSTR)Path.c_str());
	}
	void Speaker(DWORD pSound, DWORD mSecond)
	{
		Beep(pSound, mSecond);
	}
};

#endif
