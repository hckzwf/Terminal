/*++
Copyright (c) Microsoft Corporation

Module Name:
- handle.h

Abstract:
- This file manages console and I/O handles.
- Mainly related to process management/interprocess communication.

Author:
- Therese Stowell (ThereseS) 16-Nov-1990

Revision History:
--*/

#pragma once

#include "consrv.h"
#include "server.h"

void LockConsole();
void UnlockConsole();

NTSTATUS RevalidateConsole(_Out_ CONSOLE_INFORMATION ** const ppConsole);
NTSTATUS AllocateConsole(_In_reads_bytes_(cbTitle) const WCHAR * const pwchTitle, _In_ const DWORD cbTitle);
void ConsoleCloseHandle(_In_ const HANDLE hClose);
bool FreeConsoleHandle(_In_ HANDLE hFree);

NTSTATUS AllocateIoHandle(_In_ const ULONG ulHandleType,
                          _Out_ HANDLE * const hOut,
                          _Inout_ PCONSOLE_OBJECT_HEADER pObjHeader,
                          _In_ const ACCESS_MASK amDesired,
                          _In_ const ULONG ulShareMode);
NTSTATUS DereferenceIoHandleNoCheck(_In_ HANDLE hIO, _Out_ PCONSOLE_HANDLE_DATA * const ppConsoleData);
NTSTATUS DereferenceIoHandle(_In_ HANDLE hIO,
                             _In_ const ULONG ulHandleType,
                             _In_ const ACCESS_MASK amRequested,
                             _Out_ PCONSOLE_HANDLE_DATA * const ppConsoleData);

void InsertScreenBuffer(_In_ PSCREEN_INFORMATION pScreenInfo);
void RemoveScreenBuffer(_In_ PSCREEN_INFORMATION pScreenInfo);

PCONSOLE_PROCESS_HANDLE AllocProcessData(_In_ CLIENT_ID const * const ClientId,
                                         _In_ ULONG const ulProcessGroupId,
                                         _In_opt_ PCONSOLE_PROCESS_HANDLE pParentProcessData);
void FreeProcessData(_In_ PCONSOLE_PROCESS_HANDLE ProcessData);

void InitializeObjectHeader(_Out_ PCONSOLE_OBJECT_HEADER pObjHeader);