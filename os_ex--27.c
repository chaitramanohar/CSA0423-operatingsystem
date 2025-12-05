#include <stdio.h>
#include <io.h>

int main() {
    struct _finddata_t fileinfo;
    intptr_t handle;

    handle = _findfirst("*.*", &fileinfo);
    if(handle == -1) {
        printf("No files found.\n");
        return 0;
    }

    printf("Files in current directory:\n");
    do {
        printf("%s\n", fileinfo.name);
    } while(_findnext(handle, &fileinfo) == 0);

    _findclose(handle);
    return 0;
}

