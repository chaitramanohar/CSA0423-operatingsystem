#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char data[100];

    // Open file for writing (create if not exists)
    fd = open("file3.txt", O_CREAT | O_WRONLY, 0644);
    write(fd, "First Line\n", 11);
    close(fd);

    // Append data
    fd = open("file3.txt", O_WRONLY | O_APPEND);
    write(fd, "Second Line\n", 12);
    close(fd);

    // Read file
    fd = open("file3.txt", O_RDONLY);
    int n = read(fd, data, sizeof(data));
    data[n] = '\0';
    printf("File content:\n%s", data);
    close(fd);

    // Delete file
    if(unlink("file3.txt") == 0)
        printf("File deleted successfully.\n");
    else
        perror("Error deleting file");

    return 0;
}

