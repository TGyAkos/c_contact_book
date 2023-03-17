#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helper.h"
#include "linked_list.h"
#include "data.h"
#include "main.h"

static UserListNode *userList;

int main()
{
    char bs[100];
    bs[0] = 'A';
    bs[1] = ' ';
    bs[2] = ' ';
    bs[3] = 'A';
    bs[4] = '\n';

    printf("%s", bs);

    printf("Hello world\n");
    ChooseAction();

    return 0;
}

// UserListNode CurrentUserList(UserListNode *head)
// {
//     static UserListNode *currentUserList = NULL;
//     currentUserList += head;
//     return *currentUserList;
// }

void ChooseAction()
{
    while (1)
    {
        Write();
        unsigned long int userInput = IUserInput();

        if (userInput == 1)
        {
            DataInput();
        }
        else if (userInput == 2)
        {
            DataRead();
        }
        else if (userInput == 3)
        {
            break;
        }
    }
}

void DataInput()
{
    static int a = 0;
    unsigned long int userInput;
    while (1)
    {
        WriteSecondChoice();
        userInput = IUserInput();

        if (userInput == 1 && a == 0)
        {
            a = 1;
            userList = CreateUserList(CreateUser());
        }
        else if (userInput == 1)
        {
            AddToUserList(userList, CreateUser());
        }
        else if (userInput == 2)
        {
            PrintUserList(userList);
            DataSave(userList);
            break;
        }
    }
}

User CreateUser()
{
    User *user = NULL;
    user = (User *)malloc(sizeof(User));
    if (user == NULL)
    {
        printf("ASDB");
    }

    printf("Nev\n");
    FillOutUserField(user->name);

    printf("Email\n");
    FillOutUserField(user->email);

    printf("Telefon szam\n");
    user->phoneNumber = IUserInput();

    printf("Anyja neve\n");
    FillOutUserField(user->mothersName);

    User reUser = *user;
    free(user);

    return reUser;
}

void FillOutUserField(char *userField)
{
    char *a;

    a = UserInput();
    strcpy(userField, a);
    free(a);
}

void DataRead()
{
    userList = (UserListNode *)realloc(userList, sizeof(UserListNode));
    userList = DataLoad();

    PrintUserList(userList);
}
