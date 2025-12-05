#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    // Create a file
    fd = creat("file1.txt", 0644);
    if(fd < 0) {
        perror("Error creating file");
        return 1;
    }
    close(fd);
    printf("File created successfully.\n");

    // Open file for writing
    fd = open("file1.txt", O_WRONLY);
    if(fd < 0) {
        perror("Error opening file");
        return 1;
    }
    write(fd, "Hello UNIX System Calls\n", 23);
    close(fd);
    printf("Data written successfully.\n");

    // Open file for reading
    fd = open("file1.txt", O_RDONLY);
    if(fd < 0) {
        perror("Error opening file");
        return 1;
    }
    read(fd, buffer, 100);
    printf("Data read from file: %s\n", buffer);
    close(fd);

    // Delete file
    if(unlink("file1.txt") == 0)
        printf("File deleted successfully.\n");
    else
        perror("Error deleting file");

    return 0;
}

