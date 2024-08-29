#pragma once    
#include <windows.h>
#include "structs.h"
#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)
#define STATUS_PARTIAL_COPY 0x8000000D

DECLSPEC_IMPORT  FARPROC WINAPI KERNEL32$GetProcAddress(HMODULE,LPCSTR);
DECLSPEC_IMPORT HANDLE WINAPI KERNEL32$CreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);
DECLSPEC_IMPORT  HANDLE WINAPI KERNEL32$CreateToolhelp32Snapshot(DWORD dwFlags,DWORD th32ProcessID);
DECLSPEC_IMPORT  BOOL WINAPI KERNEL32$ReadProcessMemory(HANDLE, LPCVOID,LPVOID, SIZE_T, SIZE_T);
DECLSPEC_IMPORT  BOOL WINAPI  KERNEL32$WriteProcessMemory(HANDLE  hProcess,LPVOID  lpBaseAddress, LPCVOID lpBuffer, SIZE_T  nSize, SIZE_T  *lpNumberOfBytesWritten);
DECLSPEC_IMPORT  BOOL WINAPI ADVAPI32$OpenProcessToken(HANDLE,DWORD,PHANDLE);
DECLSPEC_IMPORT  BOOL WINAPI ADVAPI32$LookupPrivilegeValueA(LPCSTR,LPCSTR, PLUID);
DECLSPEC_IMPORT  BOOL WINAPI ADVAPI32$AdjustTokenPrivileges(HANDLE TokenHandle, BOOL DisableAllPrivileges,PTOKEN_PRIVILEGES NewState, DWORD BufferLength, PTOKEN_PRIVILEGES PreviousState, PDWORD ReturnLength );
DECLSPEC_IMPORT  HMODULE WINAPI KERNEL32$GetModuleHandleW(LPCWSTR);
DECLSPEC_IMPORT  HANDLE WINAPI KERNEL32$GetCurrentProcess (VOID);
DECLSPEC_IMPORT  DWORD WINAPI KERNEL32$GetLastError (VOID);
DECLSPEC_IMPORT  BOOL WINAPI KERNEL32$Process32First(HANDLE,LPPROCESSENTRY32);
DECLSPEC_IMPORT  BOOL WINAPI KERNEL32$Process32Next(HANDLE,LPPROCESSENTRY32);
DECLSPEC_IMPORT int __cdecl MSVCRT$strcmp(const char *_Str1,const char *_Str2);

//NTDLL
DECLSPEC_IMPORT NTSTATUS NTDLL$NtClose(HANDLE);
DECLSPEC_IMPORT NTSTATUS NTDLL$RtlGetVersion(PRTL_OSVERSIONINFOW);
DECLSPEC_IMPORT NTSYSCALLAPI NTSTATUS NTDLL$NtOpenProcess(HANDLE,ACCESS_MASK, POBJECT_ATTRIBUTES,PCLIENT_ID);
DECLSPEC_IMPORT NTSYSCALLAPI NTSTATUS NTDLL$NtQueryVirtualMemory(HANDLE,PVOID,MEMORY_INFORMATION_CLASS,PVOID,SIZE_T,PSIZE_T);
DECLSPEC_IMPORT NTSYSCALLAPI NTSTATUS NTDLL$NtReadVirtualMemory(HANDLE,PVOID,PVOID,ULONG,PULONG);
DECLSPEC_IMPORT NTSYSCALLAPI NTSTATUS NTDLL$NtQueryInformationProcess(HANDLE,PROCESSINFOCLASS,PVOID,ULONG,PULONG);



WINBASEAPI errno_t __cdecl MSVCRT$wcscpy_s(wchar_t *_Dst, rsize_t _DstSize, const wchar_t *_Src);
WINBASEAPI size_t __cdecl MSVCRT$wcslen(const wchar_t *_Str);
WINBASEAPI void* __cdecl MSVCRT$memcpy(void* __restrict _Dst, const void* __restrict _Src, size_t _MaxCount);
WINBASEAPI void* __cdecl MSVCRT$realloc(void*,size_t);
WINBASEAPI void* WINAPI MSVCRT$malloc(SIZE_T);
WINBASEAPI void __cdecl MSVCRT$free(void *_Memory);
WINBASEAPI time_t   WINAPI  MSVCRT$time(time_t *time);
WINBASEAPI int      WINAPI  MSVCRT$rand();
WINBASEAPI void     WINAPI  MSVCRT$srand(int initial);
WINBASEAPI size_t __cdecl MSVCRT$strlen(const char *_Str);
WINBASEAPI int __cdecl MSVCRT$_wcsicmp(const wchar_t *_Str1,const wchar_t *_Str2);
