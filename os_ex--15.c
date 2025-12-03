#include <stdio.h>
#include <string.h>

struct
{
    char dname[10];
    char fname[10][10];
    int fcount;
} dir[10];

int main()
{
    int ndir, choice, i, j, found;
    char d[10], f[10];

    printf("Enter number of directories: ");
    scanf("%d", &ndir);

    for (i = 0; i < ndir; i++)
    {
        printf("Enter name of directory %d: ", i + 1);
        scanf("%s", dir[i].dname);
        dir[i].fcount = 0;
    }

    while (1)
    {
        printf("\n----- MENU -----\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Search File\n");
        printf("4. Display All Directories\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter directory name: ");
            scanf("%s", d);

            found = -1;
            for (i = 0; i < ndir; i++)
            {
                if (strcmp(d, dir[i].dname) == 0)
                {
                    found = i;
                    break;
                }
            }

            if (found == -1)
            {
                printf("Directory not found!\n");
                break;
            }

            printf("Enter file name to create: ");
            scanf("%s", f);

            // Check duplicate file
            for (j = 0; j < dir[found].fcount; j++)
            {
                if (strcmp(f, dir[found].fname[j]) == 0)
                {
                    printf("File already exists!\n");
                    goto END_CREATE;
                }
            }

            strcpy(dir[found].fname[dir[found].fcount], f);
            dir[found].fcount++;
            printf("File created.\n");

        END_CREATE:
            break;

        case 2:
            printf("Enter directory name: ");
            scanf("%s", d);

            found = -1;
            for (i = 0; i < ndir; i++)
            {
                if (strcmp(d, dir[i].dname) == 0)
                {
                    found = i;
                    break;
                }
            }

            if (found == -1)
            {
                printf("Directory not found!\n");
                break;
            }

            printf("Enter file name to delete: ");
            scanf("%s", f);

            for (j = 0; j < dir[found].fcount; j++)
            {
                if (strcmp(f, dir[found].fname[j]) == 0)
                {
                    strcpy(dir[found].fname[j], dir[found].fname[dir[found].fcount - 1]);
                    dir[found].fcount--;
                    printf("File deleted.\n");
                    goto END_DELETE;
                }
            }

            printf("File not found!\n");

        END_DELETE:
            break;

        case 3:
            printf("Enter directory name: ");
            scanf("%s", d);

            found = -1;
            for (i = 0; i < ndir; i++)
            {
                if (strcmp(d, dir[i].dname) == 0)
                {
                    found = i;
                    break;
                }
            }

            if (found == -1)
            {
                printf("Directory not found!\n");
                break;
            }

            printf("Enter file name to search: ");
            scanf("%s", f);

            for (j = 0; j < dir[found].fcount; j++)
            {
                if (strcmp(f, dir[found].fname[j]) == 0)
                {
                    printf("File found.\n");
                    goto END_SEARCH;
                }
            }

            printf("File not found!\n");

        END_SEARCH:
            break;

        case 4:
            printf("\n--- Directory Structure ---\n");
            for (i = 0; i < ndir; i++)
            {
                printf("\nDirectory: %s\n", dir[i].dname);
                if (dir[i].fcount == 0)
                    printf("  No files.\n");
                else
                {
                    for (j = 0; j < dir[i].fcount; j++)
                        printf("  %s\n", dir[i].fname[j]);
                }
            }
            break;

        case 5:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}
