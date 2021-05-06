#include"file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count=0;
contact c[1000];

void load()
{
    FILE *f;
    f=fopen("project.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%[^,],",c[count].firstname);
        fscanf(f,"%[^,],",c[count].lastname);
        fscanf(f,"%d-",&c[count].birthdate.day);
        fscanf(f,"%d-",&c[count].birthdate.month);
        fscanf(f,"%d,",&c[count].birthdate.year);
        fscanf(f,"%[^,],",c[count].address);
        fscanf(f,"%[^,],",c[count].email);
        fscanf(f,"%s\n",c[count].phonenumber);
        count++;
    }
    fclose(f);
}
void add()
{
    printf("\t\t Adding a Contact\n");
    contact con;
    int x=0;
    int i;
    printf("\tFirst Name: ");
    scanf(" %s", con.firstname);
    printf("\tLast Name: ");
    scanf(" %s",con.lastname);
    do
    {
        printf("\t  Date:-\n ");
        printf("\t day:");
        scanf(" %d",& con.birthdate.day);
        printf("\t month: ");
        scanf(" %d", &con.birthdate.month);
        printf("\t year: ");
        scanf("%d",&con.birthdate.year);
        if(con.birthdate.day>0&&con.birthdate.day<32&&con.birthdate.month>0&&con.birthdate.month<13&&con.birthdate.year>1900&&con.birthdate.year<2018)
        {
            break;
        }
        else
        {
            printf("invalid birthdate please try again\n");
        }
    }
    while(1);
    printf("\tAddress:");
    scanf(" %[^\n]", con.address);
    printf("\tPhone: ");
    scanf(" %s", con.phonenumber);
    do
    {
        printf("\tE-mail: ");
        scanf(" %[^\n]", con.email);
        if(strchr(con.email,' '))
        {
        }
        else
        {
            for(i=0; i<100; i++)
            {
                if(con.email[i]=='@')
                {
                    for(int j=i+2; j<100; j++)
                    {
                        if(con.email[j]=='.')
                        {
                            ++x;
                            break;
                        }
                    }
                }
                if(x==1)
                {
                    break;
                }
            }
        }
        if(x==1)
        {
            break;
        }
        else
        {
            printf("invalid email please try again\n");
        }
    }
    while(1);
    c[count]=con;
    count++;
}
void printsorted()
{
    int x,i;
    printf("enter a sorting method\n");
    printf("1-by name\n");
    printf("2-by date of birth\n");
    scanf("%d",&x);
    switch(x)
    {
    case 1:
        sort_by_name();
        break;
    case 2:
        sort_by_date();
        break;
    }
    for(i=0; i<count; i++)
    {
        printf("Lastname: %s \n",c[i].lastname);
        printf("Firstname: %s \n",c[i].firstname);
        printf("Date of birth\n");
        printf("Day: %d \n",c[i].birthdate.day);
        printf("Month: %d \n",c[i].birthdate.month);
        printf("Year: %d \n",c[i].birthdate.year);
        printf("Address: %s \n",c[i].address);
        printf("Phone number: %s \n",c[i].phonenumber);
        printf("Email: %s \n",c[i].email);
        printf("==========================\n");
    }
}
void sort_by_name()
{
    contact temp;
    int i,j;
    for(i=0; i<count-1; i++)
    {
        for(j=0; j<count-i-1; j++)
        {
            if(strcasecmp(c[j].lastname,c[j+1].lastname)>0)
            {
                temp=c[j];
                c[j]=c[j+1];
                c[j+1]=temp;
            }
        }
    }
}
void sort_by_date()
{
    contact swap;
    int i,j;
    for(i=0; i<count-1; i++)
    {
        for(j=0; j<count-i-1; j++)
        {
            if(c[j].birthdate.year<c[j+1].birthdate.year)
            {
                swap=c[j];
                c[j]=c[j+1];
                c[j+1]=swap;
            }
            else if(c[j].birthdate.year==c[j+1].birthdate.year&&c[j].birthdate.month<c[j+1].birthdate.month)
            {
                swap=c[j];
                c[j]=c[j+1];
                c[j+1]=swap;
            }
            else if(c[j].birthdate.year==c[j+1].birthdate.year&&c[j].birthdate.month==c[j+1].birthdate.month&&c[j].birthdate.day<c[j+1].birthdate.day)
            {
                swap=c[j];
                c[j]=c[j+1];
                c[j+1]=swap;
            }
        }
    }
}
void search()
{

    char m[10];
    printf("enter last name of person you want to search: ");
    scanf("%s",m);
    int i,x;
    int y=0;
    for (i=0; i<count; i++)
    {
        x=strcasecmp(c[i].lastname,m);
        if(x==0)
        {
            printf("first name: %s\n",c[i].firstname);
            printf("last name: %s\n",c[i].lastname);
            printf("date of birth\n");
            printf("day:%d month:%d year:%d \n",c[i].birthdate.day,c[i].birthdate.month,c[i].birthdate.year);
            printf("address: %s \n",c[i].address);
            printf("email: %s \n",c[i].email);
            printf("phone number: %s \n",c[i].phonenumber);
            printf("--------------------\n");
            ++y;
        }
    }
    if(y>0)
    {
        printf("there are %d contacts found with the same last name\n",y);
    }
    else
    {
        printf("no contact found with this last name\n");
    }
}
void modify()
{
    char n[10];
    int z;
    printf("enter last name of person you want to modify:\n");
    scanf("%s",n);
    int i,x,k,y=0;
    for (i=0; i<count; i++)
    {
        x=strcasecmp(c[i].lastname,n);
        if(x==0)
        {

            printf("Do you want to modify this contact?\n");
            printf("%s %s\n",c[i].firstname,c[i].lastname);
            printf("1-Yes     2-No\n");
            scanf("%d",&k);
            if(k==1)
            {
                printf("choose what you want you to modify\n");
                printf("1-firstname\n 2-lastname \n 3-birthdate \n 4-address \n 5-emai \n 6-phonenumber\n");
                scanf("%d",&z);
                switch(z)
                {
                case 1:
                    printf("enter the new first name\n");
                    scanf("%s",c[i].firstname);
                    break;
                case 2:
                    printf("enter the new last name\n");
                    scanf("%s",c[i].lastname);
                    break;
                case 3:
                    do
                    {
                        printf("enter day \n");
                        scanf("%d",&c[i].birthdate.day);
                        printf("enter month \n");
                        scanf("%d",&c[i].birthdate.month);
                        printf("enter year");
                        scanf("%d",&c[i].birthdate.year);
                        if(c[i].birthdate.day>0&&c[i].birthdate.day<32&&c[i].birthdate.month>0&&c[i].birthdate.month<13&&c[i].birthdate.year>1900&&c[i].birthdate.year<2018)
                        {
                            break;
                        }
                        else
                        {
                            printf("invalid birthdate please try again\n");
                        }
                    }
                    while(1);
                    break;
                case 4:
                    printf("enter the new address\n");
                    scanf(" %[^\n]", c[i].address);
                    break;
                case 5:
                    do
                    {
                        printf("\tE-mail: ");
                        scanf(" %[^\n]", c[i].email);
                        if(strchr(c[i].email,' '))
                        {
                        }
                        else
                        {
                            for(int b=0; b<100; b++)
                            {
                                if(c[i].email[b]=='@')
                                {
                                    for(int j=b+2; j<100; j++)
                                    {
                                        if(c[i].email[j]=='.')
                                        {
                                            ++y;
                                            break;
                                        }
                                    }
                                }
                                if(y==1)
                                {
                                    break;
                                }
                            }
                        }
                        if(y==1)
                        {
                            break;
                        }
                        else
                        {
                            printf("invalid email please try again\n");
                        }
                    }
                    while(1);
                    break;
                case 6:
                    printf("enter the new phonenumber\n");
                    scanf("%s",c[i].phonenumber);
                    break;
                }
                break;
            }
        }
    }

}
void delete()
{
    int i;
    char m[20];
    char n[20];
    int x,y,z=0,k;
    printf("enter first name: ");
    scanf("%s",m);
    printf("enter last name: ");
    scanf("%s",n);
    for(i=0; i<count; i++)
    {
        x=strcasecmp(c[i].firstname,m);
        y=strcasecmp(c[i].lastname,n);
        if(y==0&&x==0)
        {
            printf("Are you sure you want to delete this contact?\n");
            printf("%s %s      his phone number: %s\n",c[i].firstname,c[i].lastname,c[i].phonenumber);
            printf("1-Yes   2-No\n");
            scanf("%d",&k);
            if(k==1)
            {
                c[i]=c[count-1];
                count--;
                z++;
            }

        }
    }
    if(!z)
    {
        printf("can't find contact\n");
    }
    else
    {
        printf("contact deleted\n");
    }



}
void save()
{
    FILE *f;
    printf(" there are %d contacts", count);
    int i;
    f= fopen("project.txt", "w");
    for (i = 0; i < count; i++)
    {
        fprintf(f, "%s,%s,",c[i].firstname, c[i].lastname);
        fprintf(f, "%d-%d-%d,",c[i].birthdate.day, c[i].birthdate.month, c[i].birthdate.year);
        fprintf(f, "%s,%s,%s\n",c[i].address, c[i].email,c[i].phonenumber);
    }

    fclose(f);
}
void quit()
{
    int x;
    printf("Are you sure you want to exit program?\n");
    printf("1-Yes    2-No\n");
    scanf("%d",&x);
    if(x==1)
    {
        printf("good bye\n");
        exit(0);
    }
}
