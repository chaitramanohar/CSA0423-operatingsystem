#include <stdio.h>
#include <string.h>

struct
{
    char dname[10];
    char fname[10][10];
    int fcount;
} dir;

int main()
{
    int choice, found, i;
    char f[10];

    printf("Enter directory name: ");
    scanf("%s", dir.dname);
    dir.fcount = 0;

    while (1)
    {
        printf("\n----- MENU -----\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Search File\n");
        printf("4. Display Files\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter file name to create: ");
            scanf("%s", f);

            found = 0;
            for (i = 0; i < dir.fcount; i++)
            {
                if (strcmp(f, dir.fname[i]) == 0)
                {
                    found = 1;
                    break;
                }
            }

            if (found)
                printf("File already exists!\n");
            else
            {
                strcpy(dir.fname[dir.fcount], f);
                dir.fcount++;
                printf("File created.\n");
            }
            break;

        case 2:
            printf("Enter file name to delete: ");
            scanf("%s", f);

            found = 0;
            for (i = 0; i < dir.fcount; i++)
            {
                if (strcmp(f, dir.fname[i]) == 0)
                {
                    found = 1;
                    strcpy(dir.fname[i], dir.fname[dir.fcount - 1]);
                    dir.fcount--;
                    printf("File deleted.\n");
                    break;
                }
            }

            if (!found)
                printf("File not found!\n");
            break;

        case 3:
            printf("Enter file name to search: ");
            scanf("%s", f);

            found = 0;
            for (i = 0; i < dir.fcount; i++)
            {
                if (strcmp(f, dir.fname[i]) == 0)
                {
                    found = 1;
                    break;
                }
            }

            if (found)
                printf("File found!\n");
            else
                printf("File not found!\n");
            break;

        case 4:
            printf("\nDirectory: %s\n", dir.dname);
            if (dir.fcount == 0)
                printf("No files.\n");
            else
            {
                for (i = 0; i < dir.fcount; i++)
                    printf("  %s\n", dir.fname[i]);
            }
            break;

        case 5:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}
