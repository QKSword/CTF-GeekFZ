#include <stdio.h>
#include <Windows.h>
#include <tlhelp32.h>


//通知链接器为TLS数据在PE文件头中添加数据
#pragma comment(linker, "/INCLUDE:__tls_used")

void NTAPI dntg(PVOID DLLHandle, DWORD Reason, PVOID Red)
{
	HANDLE			hprocessShap = NULL;
	PROCESSENTRY32	pe32		 = {0};
	hprocessShap = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);

	pe32.dwSize = sizeof(PROCESSENTRY32);

	if(Process32First(hprocessShap, &pe32))
	{
		do
		{
			if(_wcsicmp(pe32.szExeFile,L"吾爱破解[LCG].exe")==0)
			{
				printf("face the od");
				ExitProcess(0);
			}
			if(_wcsicmp(pe32.szExeFile,L"ida.exe")==0)
			{
				printf("face the IDA");
				ExitProcess(0);
			}
		}
		while (Process32Next(hprocessShap, &pe32));

	}

}

//声明区段注册TLS回调函数
#pragma data_seg(".CRT$XLB")
PIMAGE_TLS_CALLBACK p_thread_callbackp[] = {dntg};
#pragma data_seg()


enum PROCESSINFOCLASS
{
    ProcessBasicInformation = 0,
    ProcessQuotaLimits,
    ProcessIoCounters,
    ProcessVmCounters,
    ProcessTimes,
    ProcessBasePriority,
    ProcessRaisePriority,
    ProcessDebugPort = 7,
    ProcessExceptionPort,
    ProcessAccessToken,
    ProcessLdtInformation,
    ProcessLdtSize,
    ProcessDefaultHardErrorMode,
    ProcessIoPortHandlers,
    ProcessPooledUsageAndLimits,
    ProcessWorkingSetWatch,
    ProcessUserModeIOPL,
    ProcessEnableAlignmentFaultFixup,
    ProcessPriorityClass,
    ProcessWx86Information,
    ProcessHandleCount,
    ProcessAffinityMask,
    ProcessPriorityBoost,
    MaxProcessInfoClass,
    ProcessWow64Information = 26,
    ProcessImageFileName = 27,
    ProcessDebugObjectHandle = 30,
    ProcessDebugFlags = 31,
    SystemKernelDebuggerInformation = 35
};

typedef DWORD (WINAPI *NtQueryInformationProcessPtr)(
												HANDLE           ProcessHandle,
												PROCESSINFOCLASS ProcessInformationClass,
												PVOID            ProcessInformation,
												ULONG            ProcessInformationLength,
												PULONG           ReturnLength
													);

BOOL CheckDebug()  
{  
    int debugPort = 0;  
    HMODULE hModule = LoadLibrary(L"Ntdll.dll");  
    NtQueryInformationProcessPtr NtQueryInformationProcess = (NtQueryInformationProcessPtr)GetProcAddress(hModule, "NtQueryInformationProcess");  
    NtQueryInformationProcess(GetCurrentProcess(), ProcessDebugPort, &debugPort, sizeof(debugPort), NULL);  
	if(debugPort == 0x0)
	{
		char flag_3[]={0x52, 0x47, 0x46, 0x5F, 0x52};
		for(int i=0; i<5; i++)
		{
			flag_3[i]^=0x33;
			printf("%c", flag_3[i]);
		}	
	}
	else
	{
		printf("indebug\n");
		ExitProcess(0);
	}
	
}  


void fts_Rdtsc()
{
	DWORD dwDelta = 0;

	__asm {
		pushad
		rdtsc   //第一次执行RDTSC指令，将TSC保存到EDX：EAX中
		push edx
		push eax    //将结果值放入到栈中
		xor eax, eax
		mov ecx, 0x3e8  //循环次数，用于消耗时间

_LOOP_START:
		inc eax
		loop _LOOP_START

		rdtsc   //第二次执行RDTSC指令
		pop esi			
		pop edi			// 把第一次的值pop出来
		// 高字节对比
		cmp edx, edi
		ja _DEBUGGER_FOUND
		// 低字节对比
		sub eax, esi
        mov dwDelta, eax
		cmp eax, 0xffffff
		jb _DEBUGGER_NOT_FOUND

        // 触发异常
_DEBUGGER_FOUND:
		xor eax, eax
		mov [eax], eax

        // 正常运行
_DEBUGGER_NOT_FOUND:
		popad
	}
		
	char flag_4[]={0x30, 0x2D, 0x2B, 0x2A, 0x37};
	for(int i=0; i<5; i++)
	{
		flag_4[i]^=0x44;
		printf("%c", flag_4[i]);
	}

}



void the_end()
{
	char flag[MAX_PATH];
	printf("\n");
	printf("最后一步了，说一下感想！！！\n");
	gets_s(flag);
	if(strlen(flag) > 30)
	{
		char flag_5[]={0xA, 0x33, 0x3A, 0x27, 0xA, 0x2C, 0x3A, 0x20, 0x28};
		for(int i=0; i<9; i++)
		{
			flag_5[i]^=0x55;
			printf("%c", flag_5[i]);
		}
	}
	
}



int main(int argc, char* argv)
{
	printf("走过八十一难，flag就在眼前\n");
	char flag_1[]={0x77, 0x7D, 0x70, 0x76, 0x6A};
	for(int i=0; i<5; i++)
	{
		flag_1[i]^= 0x11;
		printf("%c", flag_1[i]);
	}
	HWND find_OD=FindWindowW(NULL, L"吾爱破解[LCG].exe");
	HWND find_IDA=FindWindowW(NULL, L"ida.exe");
	if(find_OD != NULL && find_IDA != NULL)
	{
		char flag_2[]={0x41, 0x4D, 0x4C, 0x45, 0x50};
		for(int i=0; i<5; i++)
		{
			flag_2[i]^=0x22;
			printf("%c", flag_2[i]);
		}
		CheckDebug();
		fts_Rdtsc();
		the_end();
	}
	getchar();
	return 0;
}