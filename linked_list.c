#include <stdio.h>
#include <stdlib.h>
#include "list_struct.h"

UserListNode *CreateUserList(User user)
{
    UserListNode *head = NULL;
    head = (UserListNode *)malloc(sizeof(UserListNode));
    if (head == NULL)
    {
        printf("ASD");
        return NULL;
    }

    head->userData = user;
    head->next = NULL;

    return head;
}

void AddToUserList(UserListNode *head, User user)
{
    UserListNode *current = head;

    while (current->next != NULL)
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
        User u = current->userData;

        printf("{%s, %s, %lu, %s}\n",
               u.email,
               u.mothersName,
               u.phoneNumber,
               u.mothersName);

        current = current->next;
    }
}