typedef struct User
{
    char name[100];
    char email[100];
    unsigned long int phoneNumber;
    char mothersName[100];
} User;

typedef struct UserListNode
{
    User userData;
    struct UserListNode *next;
} UserListNode;