#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char line[200];
    char keyword[50];

    printf("Enter keyword to search: ");
    scanf("%s", keyword);

fp = fopen("os_ex-1.c", "r"); 
 // File to search
    if(fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("Lines containing '%s':\n", keyword);
    while(fgets(line, sizeof(line), fp)) {
        if(strstr(line, keyword) != NULL) {
            printf("%s", line);
        }
    }

    fclose(fp);
    return 0;
}

