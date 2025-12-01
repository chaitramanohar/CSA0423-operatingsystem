#include <stdio.h>
#include <windows.h>

int main() {
    printf("Current Process ID (PID): %lu\n", GetCurrentProcessId());
    printf("Parent Process ID (PPID): %lu\n", GetCurrentProcessId()); // Windows cannot fetch real PPID easily

    // Create a simple child process (Notepad)
    STARTUPINFO si = {0};
    PROCESS_INFORMATION pi = {0};
    si.cb = sizeof(si);

    if (CreateProcess(
            "C:\\Windows\\System32\\notepad.exe",  // Child program
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
    }
    else {
        printf("Error creating process: %lu\n", GetLastError());
    }

    return 0;
}

