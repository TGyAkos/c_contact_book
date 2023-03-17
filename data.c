#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "data.h"

void DataSave(UserListNode *userList)
{
    FILE *fp = fopen("mentettAdat.txt", "a");

    UserListNode *current = userList;

    while (current != NULL)
    {
        User u = current->userData;

        fprintf(fp, "%s,%s,%lu,%s\n",
                u.email,
                u.mothersName,
                u.phoneNumber,
                u.mothersName);

        current = current->next;
    }
    fclose(fp);
}

UserListNode *DataLoad()
{
    FILE *fp = fopen("mentettAdat.txt", "r");
    char str[500];
    int toggler = 0;

    UserListNode *userList;

    while (fgets(str, sizeof(str), fp))
    {
        User *user;
        user = (User *)malloc(sizeof(User));

        if (toggler == 0)
        {
            StrToUserMember(str, user->name);
            StrToUserMember(str, user->email);
            IntToUserMember(str, &(user->phoneNumber));
            StrToUserMember(str, user->mothersName);

            User u = *user;
            userList = CreateUserList(u);

            toggler++;
        }
        else
        {
            StrToUserMember(str, user->name);
            StrToUserMember(str, user->email);
            IntToUserMember(str, &(user->phoneNumber));
            StrToUserMember(str, user->mothersName);

            User u = *user;
            AddToUserList(userList, u);
        }

        if (feof(fp))
        {
            break;
        }
    }
    fclose(fp);

    return userList;
}

void StrToUserMember(char *str, char *member)
{
    char *a = StrSlicer(str);
    strcpy(member, a);
    free(a);
}

void IntToUserMember(char *str, unsigned long int *member)
{
    char *a = StrSlicer(str);
    unsigned long int c;

    sscanf(a, "%lu", &c);
    *member = c;

    free(a);
}

char *StrSlicer(char *str)
{
    char *reStr = (char *)malloc(100);

    int i = 0;
    int x = 0;

    while (str[i] != ',')
    {
        if (str[i] == '\n')
        {
            break;
        }

        if (str[i] != '\r')
        {
            reStr[x] = str[i];
            x++;
        }

        str[i] = '\r';

        i++;
    }
    str[i] = '\r';
    reStr[x] = '\0';

    return reStr;
}