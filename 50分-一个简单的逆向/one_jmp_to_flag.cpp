#include <stdio.h>
#include <Windows.h>

int main()
{
	char flag[MAX_PATH];
	typedef DWORD (WINAPI *LPFNMsgBoxW)(HWND hWnd,LPCTSTR lpText,LPCTSTR lpCaption,UINT uType);
	HMODULE hMod = LoadLibrary(L"user32.dll");
	FARPROC func = GetProcAddress(hMod, "MessageBoxW");
	printf("请输入flag：");
	gets_s(flag);
	if(strlen(flag) <= 20)
	{
		((LPFNMsgBoxW)func)(NULL, L"you wrong!!!", L"wrong", NULL);
	}
	else
	{
		((LPFNMsgBoxW)func)(NULL, L"flag{Welcome_to_GeekFZCTF}", L"true", NULL);
	}
 	
	FreeLibrary(hMod);
	getchar();
}