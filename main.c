#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"file.h"

int main()
{
    int code;
    do
    {
        printf("=====MENU=====\n");
        printf("enter your choice \n");
        printf("\n1.load");
        printf("\n2.Add contact");
        printf("\n3.Search");
        printf("\n4.modify");
        printf("\n5.Print");
        printf("\n6.delete");
        printf("\n7.Save");
        printf("\n8.Exit");
        printf("\n\nEnter Choice:");
        scanf(" %d",&code);
        switch(code)
        {

        case 1:
            load();
            break;
        case 2:
            add();
            break;
        case 3:
            search();
            break;
        case 4:
            modify();
            break;
        case 5:
            printsorted();
            break;
        case 6:
            delete();
            break;
        case 7:
            save();
            break;
        case 8:
            quit();
            break;
        default:
            printf("no option with this number please try again\n");
        }
    }
    while(code<9);

    return 0;
}
