#include <stdio.h>
#include <windows.h>

// Thread function 1
DWORD WINAPI threadFunc1(LPVOID lpParameter) {
    int i;   // declare here, not inside for()
    for (i = 0; i < 5; i++) {
        printf("Thread 1 is running... (%d)\n", i);
        Sleep(500);
    }
    return 0;
}

// Thread function 2
DWORD WINAPI threadFunc2(LPVOID lpParameter) {
    int i;   // same fix
    for (i = 0; i < 5; i++) {
        printf("Thread 2 is running... (%d)\n", i);
        Sleep(500);
    }
    return 0;
}

int main() {
    HANDLE hThread1, hThread2;

    hThread1 = CreateThread(NULL, 0, threadFunc1, NULL, 0, NULL);
    hThread2 = CreateThread(NULL, 0, threadFunc2, NULL, 0, NULL);

    WaitForSingleObject(hThread1, INFINITE);
    WaitForSingleObject(hThread2, INFINITE);

    CloseHandle(hThread1);
    CloseHandle(hThread2);

    printf("Both threads finished execution.\n");
    return 0;
}

