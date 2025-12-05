#include <stdio.h>
#include <windows.h>

DWORD WINAPI myThreadFunction(LPVOID lpParam) {
    printf("Hello from thread! Parameter: %d\n", *(int*)lpParam);
    return 0;
}

int main() {
    HANDLE thread;
    DWORD threadId;
    int param = 5;

    // Create thread
    thread = CreateThread(NULL, 0, myThreadFunction, &param, 0, &threadId);
    if(thread == NULL) {
        printf("Thread creation failed.\n");
        return 1;
    }

    // Wait for thread to finish (join)
    WaitForSingleObject(thread, INFINITE);
    printf("Thread finished execution.\n");

    // Close thread handle
    CloseHandle(thread);
    return 0;
}

