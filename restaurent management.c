#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void login();
void employees();
void menu();
void main_menu();
void order(int n);
void checkout();
void farewell();
void dev();
void records();

int ordertracker[5],jjj=0;

int main()
{
    FILE *fp;
    fp=fopen("Table_21.txt", "w");
    fprintf(fp,"");
    fclose(fp);

    dev();
    getchar();

    system("cls");
    int i,j,d;

    while(1)
    {
        printf("Please select from below\n");
        printf("1. Owner \n2. Customer \n3. Exit\n");

        scanf("%d",&d);

        system("cls");

        if(d == 1)
        {
            login();
            continue;
        }

        if(d == 3)
        {
            break;
        }

        printf("                         Welcome To HiroHito's Kitchen\n\n\n\n");

        memset(ordertracker, 0, sizeof ordertracker);
        menu();
    }

    return 0;
}

void dev()
{
    FILE *fp;

            //system("color 04");

            fp=fopen("creatorinfo.txt", "r");
            char test[100000];
            while(!feof(fp))
            {
                fgets(test, 100000, fp);
                puts(test);
            }
            fclose(fp);

}

void login()
{
    char p[]="123456789", u[]="owner";

    char pass[100],u_name[100];

    int tr=0,d;

    while(1)
    {
        printf("Username: ");
        scanf(" %s",u_name);

        printf("Password: ");
        scanf(" %s",pass);

        tr++;

        if(strcmp(u_name,u))
        {
           printf("Username or Password don't match. Please try again\n");
           getchar();
           getchar();

           system("cls");
           continue;
        }

        if(strcmp(pass,p))
        {
           printf("Username or Password don't match. Please try again\n");
           getchar();
           getchar();

           system("cls");
           continue;
        }

        system("cls");

        printf("\t\tLogin Successful\n\n\n");
        getchar();
        break;
    }

    while(1){
    printf("\tWhich directory do you want to view ?\n\n");
    printf("\t\t1. Employees \n\t\t2. Customer records\n\n \t\tPress 0 to exit\n");

    scanf("%d",&d);

    if(!d){
        system("cls");
        break;
    }
    if(d == 1)
        employees();
    if(d == 2)
        records();

    system("cls");
    }

}


void menu()
{
    FILE * fp;
    int d,f;

    while(1){
            main_menu();

    printf("Please select your desired menu to see details or press 0 to proceed to check out: ");

    scanf("%d",&d);

    system("cls");

    if(!d)
        break;

    if(d == 1)
    {
        fp=fopen("fmb01.txt", "r");
    }
    else if(d == 2)
    {
        fp=fopen("fmb02.txt", "r");
    }
    else if(d == 3)
    {
        fp=fopen("fmb03.txt", "r");
    }
    else if(d == 4)
    {
        fp=fopen("fmb04.txt", "r");
    }

    char test[1000];
    while(!feof(fp))
    {
        fgets(test, 1000, fp);
        puts(test);
    }

    fclose(fp);

    printf("\n\n\t\tPress 1 to order\t\t\t Press 2 to go to main menu\n");

    scanf("%d",&f);

    if(f == 1)
            order(d);

    else{
        system("cls");
        continue;
    }

 }

    checkout();
}


void main_menu()
{
    FILE *fp;


            fp=fopen("main menu.txt", "r");
            char test[100000];
            while(!feof(fp))
            {
                fgets(test, 100000, fp);
                puts(test);
            }
            fclose(fp);

}

void order(int n)
{
    int q,price;

    printf("plese enter the quantity: ");

    scanf("%d",&q);

    system("cls");

    ordertracker[n-1]=q;
}

void checkout()
{
    FILE *fp;
    fp=fopen("Table_21.txt", "a");

    int i=1,d;
    float total = ordertracker[0]*1661.75 + ordertracker[1]*2535.75 + ordertracker[2]*1443.25 + ordertracker[3]*1403.00;

    if(!total)
    printf("\n\n\t\t No Foods Ordered\n");

    else{
    printf("    	    Platter Name 		 Quantity	        Price\n");
    printf("           --------------               ----------            ---------\n\n");

    if(ordertracker[0])
                printf("	      %d. Sushi                       %02d              %.2f BDT\n", i++, ordertracker[0], ordertracker[0]*1661.75);

    if(ordertracker[1])
                printf("	      %d. Wagyu                       %02d              %.2f BDT\n", i++, ordertracker[1], ordertracker[1]*2535.75);

    if(ordertracker[2])
                printf("	      %d. Gyoza                       %02d              %.2f BDT\n", i++, ordertracker[2], ordertracker[2]*1443.25);

    if(ordertracker[3])
                printf("	      %d. Yakitori                    %02d              %.2f BDT\n\n", i++, ordertracker[3], ordertracker[3]*1403.00);


                printf("                                                            -------------\n");
                printf("					              Total: %.2f BDT\n\n", total);
    }

    printf("\n\n\t Press 1 to check out \t press 2 to change order\n");
    scanf("%d",&d);

    system("cls");

    if(d == 2)
        menu();
    else if(d==1 && total)
    {
        i=1;
        fprintf(fp, "Customer %d:\n" ,++jjj);
        fprintf(fp, "\tOrdered Foods: \n\n");

        fprintf(fp, "    	    Platter Name 		 Quantity	        Price\n");
        fprintf(fp, "           --------------               ----------            ---------\n\n");

        if(ordertracker[0])
                fprintf(fp, "	      %d. Sushi                       %02d              %.2f BDT\n", i++, ordertracker[0], ordertracker[0]*1661.75);

        if(ordertracker[1])
                fprintf(fp, "	      %d. Wagyu                       %02d              %.2f BDT\n", i++, ordertracker[1], ordertracker[1]*2535.75);

        if(ordertracker[2])
                fprintf(fp, "	      %d. Gyoza                       %02d              %.2f BDT\n", i++, ordertracker[2], ordertracker[2]*1443.25);

        if(ordertracker[3])
                fprintf(fp, "	      %d. Yakitori                    %02d              %.2f BDT\n\n", i++, ordertracker[3], ordertracker[3]*1403.00);


                fprintf(fp, "                                                            -------------\n");
                fprintf(fp, "					              Total: %.2f BDT\n\n", total);

        fclose(fp);

        farewell();
    }
}


void farewell()
{
    FILE *fp;
    int d,i=1,f=0;
    char cmnt[1000],rvw[100];

    while(1){
        f=0;
    printf("\t Please leave a review of the restaurant\n");

    printf("\t   1. Excellent\n");
    printf("\t   2. Good\n");
    printf("\t   3. Average\n");
    printf("\t   4. Not so good\n");
    printf("\t   5. Bad\n");

    scanf("%d",&d);

    switch (d)
    {
        case 1:
            strcpy(rvw,"Excellent"); break;
        case 2:
            strcpy(rvw,"Good"); break;
        case 3:
            strcpy(rvw,"Average"); break;
        case 4:
            strcpy(rvw,"Not so good"); break;
        case 5:
            strcpy(rvw,"Bad"); break;
        default:
            f=1; break;
    }
        if(f)
        {
            printf("\n    Please enter a valid review\n");
            getchar();
            getchar();
            system("cls");
            continue;
        }

        if(!f)
            break;

    }

    printf("Comment: ");

    scanf(" %[^\n]", cmnt);
    getchar();

    printf("\n\n\n");

    printf("\t\t\tThank You For Your Visit\n");
    printf("\t\t\t   Please Come Again\n");

    getchar();

    system("cls");

            fp=fopen("Table_21.txt", "a");

            fprintf(fp,"\tReview    : %s\n",rvw);
            fprintf(fp,"\tComments  : %s\n\n\n",cmnt);

            fclose(fp);

}

void employees()
{
    system("cls");
    FILE * fp;
    fp=fopen("employees.txt", "r");
    char test[1000000];
    while(!feof(fp))
    {
        fgets(test, 1000000, fp);
        puts(test);
    }

    fclose(fp);

    getchar();
    getchar();
    system("cls");
}

void records()
{
    FILE *f;

            system("cls");

            if(!jjj)
            printf("\n\n\n\n\t\t No Records\n");

        else{
            f=fopen("Table_21.txt", "r");
            char t[1000000];
            while(!feof(f))
            {
                fgets(t, 1000000, f);
                puts(t);
            }
            fclose(f);
        }
    getchar();
    getchar();
    system("cls");
}
