#include <stdio.h>
#include <windows.h>

#define SHM_SIZE 1024  // Shared memory size

int main() {
    HANDLE hMapFile;
    char *pBuf;

    // Create a named shared memory
    hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,    // Use paging file
        NULL,                    // Default security
        PAGE_READWRITE,          // Read/write access
        0,                       // Maximum object size (high-order DWORD)
        SHM_SIZE,                // Maximum object size (low-order DWORD)
        "MySharedMemory");       // Name of shared memory

    if (hMapFile == NULL) {
        printf("Could not create file mapping object (%lu).\n", GetLastError());
        return 1;
    }

    // Map view of shared memory
    pBuf = (char *) MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, SHM_SIZE);
    if (pBuf == NULL) {
        printf("Could not map view of file (%lu).\n", GetLastError());
        CloseHandle(hMapFile);
        return 1;
    }

    // Write to shared memory
    printf("Enter a message to write in shared memory: ");
    fgets(pBuf, SHM_SIZE, stdin);  // Write message

    printf("Message written to shared memory.\n");
    printf("Press Enter to read it back...");
    getchar();

    // Read from shared memory
    printf("Reading from shared memory: %s\n", pBuf);

    // Cleanup
    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);

    return 0;
}

