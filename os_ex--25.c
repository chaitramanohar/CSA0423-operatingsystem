#include <stdio.h>
#include <stdlib.h>
#include <io.h>      // For _findfirst, _findnext
#include <sys/stat.h>
#include <string.h>

int main() {
    FILE *fp;
    char buffer[100];

    // Open or create file
    fp = fopen("file2.txt", "w+");  // w+ = create or read/write
    if(fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Write to file
    fwrite("UNIX I/O System Calls\n", sizeof(char), 22, fp);

    // Move file pointer (fseek)
    fseek(fp, 0, SEEK_SET);
    fread(buffer, sizeof(char), 22, fp);
    buffer[22] = '\0';  // Null terminate string
    printf("File content: %s\n", buffer);

    // File information (_stat)
    struct _stat st;
    if(_stat("file2.txt", &st) == 0) {
        printf("File size: %ld bytes\n", st.st_size);
    }

    fclose(fp);

    // Directory operations (_findfirst, _findnext)
    struct _finddata_t fileinfo;
    intptr_t handle;
    handle = _findfirst("*.*", &fileinfo);
    if(handle == -1) {
        printf("No files found.\n");
    } else {
        printf("Files in current directory:\n");
        do {
            printf("%s\n", fileinfo.name);
        } while(_findnext(handle, &fileinfo) == 0);
        _findclose(handle);
    }

    return 0;
}

