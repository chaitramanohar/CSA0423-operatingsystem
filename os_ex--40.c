#include <stdio.h>

struct Permissions {
    char user[10];
    char perm[4];     // rwx
    int value;        // numeric value
};

int main() {

    struct Permissions p[3] = {
        {"Owner",  "rwx", 7},
        {"Group",  "rw-", 6},
        {"Others", "r--", 4}
    };

    int i;   // declare here (important for Dev-C++)

    printf("Linux File Access Permissions:\n\n");
    printf("User Type\tPermissions\tNumeric\n");
    printf("---------------------------------------------\n");

    for (i = 0; i < 3; i++) {
        printf("%s\t\t%s\t\t%d\n", p[i].user, p[i].perm, p[i].value);
    }

    printf("\nMeaning of Each Symbol:\n");
    printf("r = Read (4)\n");
    printf("w = Write (2)\n");
    printf("x = Execute (1)\n");
    printf("- = No Permission (0)\n");

    printf("\nExample: 764 means:\n");
    printf("Owner  ? rwx ? 7\n");
    printf("Group  ? rw- ? 6\n");
    printf("Others ? r-- ? 4\n");

    return 0;
}

