#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helper.h"

void Write()
{
    printf("Mit szeretne csinalni:\n1 - Felvinni adatot\n2 - Olvasni adatot\n3 - Kilepes\n");
}

void WriteSecondChoice()
{
    printf("Mit szeretne csinalni:\n1 - Folytatni\n2 - Abba hagyni az adatfelvetelt\n");
}

char *UserInput()
{
    char str[100];
    str[99] = '\0';

    printf("Irja be a megfelelo adatot\n");

    gets(str);

    char *reStr = (char *)malloc(sizeof(str));
    if (reStr == NULL)
    {
        printf("ASDF");
        return NULL;
    }

    strcpy(reStr, str);

    return reStr;
}

unsigned long int IUserInput()
{
    unsigned long int x;
    char str[100];

    printf("Irja be a megfelelo adatot\n");

    gets(str);

    sscanf(str, "%lu", &x);

    return x;
}
