#include <stdio.h>
#include <windows.h>

int main() {
    DWORD pid = GetCurrentProcessId();
    printf("Current Process ID (PID): %lu\n", pid);

    printf("Parent Process ID (PPID): %lu\n", pid);

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (CreateProcess(
            "C:\\Windows\\System32\\notepad.exe",
            NULL,
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL,
            &si,
            &pi))
    {
        printf("Child Process Created!\n");
        printf("Child PID: %lu\n", pi.dwProcessId);

        WaitForSingleObject(pi.hProcess, INFINITE);

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    else {
        printf("Error creating child process. Error code: %lu\n", GetLastError());
    }

    return 0;
}

