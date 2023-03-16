#include <stdio.h>
#include <stdlib.h>
#include "list_struct.h"

UserListNode CreateUserList()
{
    UserListNode *head = NULL;
    head = (UserListNode *)malloc(sizeof(UserListNode));
    if (head == NULL)
    {
        UserListNode a = {{"asd", "asd", 23, "asd"}, NULL};
        return a;
    }

    return *head;
}

void AddToUserList(UserListNode *head, User user)
{
    UserListNode *current = head;

    while (current != NULL)
    {
        current = current->next;
    }

    current->next = (UserListNode *)malloc(sizeof(UserListNode));
    current->next->userData = user;
    current->next->next = NULL;
}

void PrintUserList(UserListNode *head)
{
    UserListNode *current = head;

    while (current != NULL)
    {
        printf("{%s, %s, %lu, %s}",
               current->userData.email,
               current->userData.mothersName,
               current->userData.phoneNumber,
               current->userData.mothersName);

        current = current->next;
    }
}