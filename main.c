#include <stdio.h>
#include <stdlib.h>
void MenuPrin(){
    printf("\t\t\t****************Munu****************\n");
 printf("\t\t\t--> 1  - Create an Account\n");
 printf("\t\t\t--> 2  - Diposit balance\n");
 printf("\t\t\t--> 3  - WithDraw balance\n");
 printf("\t\t\t--> 4  - Check Balance\n");
 printf("\t\t\t--> 5  - Account Holder Info's \n");
 printf("\t\t\t--> 6  - List of The Customers(Clients)\n");
 printf("\t\t\t--> 7 - Exit\n");


}
struct AccountInfo{
    char FirstName[100];
    char LastName[100];        // Account info contains all elements that we need to create an account !!
    char CIN [50];
    int Balance , Diposit , WithDraw;
}Account;


int AccCreation(){
    FILE *fPointer;
    fPointer = fopen("List.txt","w");
        // Declaration of a Function that help us to give the user Steps to create an account
    printf("\t -First Name of account holder              : ");
    scanf(" %s",&Account.FirstName);
    printf("\t -Last Name of account holder               : ");
    scanf(" %s",&Account.LastName);
    printf("\t -CIN of the account holer                  : ");
    scanf(" %s",&Account.CIN);
    printf("\t -Balance  to complete creation( =100 DH )   : "); // to create Account Successuflly (The customer must pay 10 DH)
    scanf(" %d",&Account.Balance);
    // Verification of Condition
    if (Account.Balance ==100){
            printf("\nAccount has been created successfully ! \n\n");
    }while(Account.Balance != 100){
            printf("\t -Please you must pay just 100 DH ( =100 DH )   : ");
            scanf(" %d",&Account.Balance);
        if(Account.Balance == 100) {
            printf("\nAccount has been created successfully ! \n\n");
        }
        }

        fprintf(fPointer,"the account under name %s %s ID %s have %d DH\n",Account.FirstName,Account.LastName,Account.CIN,Account.Balance);
         fclose(fPointer);
}
int DipositBalance(){
    printf("\tEnter deposit amount ( DH ) :");
    scanf("%d",&Account.Diposit);
    Account.Balance += Account.Diposit;
    printf("--> You Just Diposit %d DH \n",Account.Diposit);
    printf("--> Now You Have %d DH on your Account\n",Account.Balance);
    printf("------------------------------------------------------------------\n");
}
int WithDrawBalance(){
    printf("\tEnter WithDraw amount ( DH ): ");
    scanf("%d",&Account.WithDraw);
    /* Cheking if (Balance Amount >WithDrawn) let Costumer to WithDraw Money if not tell the Costumer that his can not
    to With Draw Money */
    if(Account.WithDraw <= Account.Balance) {
        printf("--> You Have Just Take %d DH from Your Account !! \n",Account.WithDraw);
        Account.Balance -= Account.WithDraw;
        printf("--> Now You Have %d DH on your Account\n",Account.Balance);
        printf("------------------------------------------------------------------\n\n");
        }
    while (Account.WithDraw > Account.Balance){
        printf("You Just Have %d DH , You Can't WithDrawn %d DH!!!!!\n",Account.Balance,Account.WithDraw);
        printf("Please Enter WithDraw  <= Balane of Your Account :");
        scanf("%d",&Account.WithDraw);}
        if(Account.WithDraw <= Account.Balance) {
            printf("------------------------------------------------------------------\n");
            printf("--> You Have Just Take %d DH from Your Account !! \n",Account.WithDraw);
        Account.Balance -= Account.WithDraw;
            printf("--> You Have Now %d DH on your Account !\n",Account.Balance);
            printf("------------------------------------------------------------------\n\n");
        }
}


int CheckBalance(){
    printf("    --> Now You Have : %d DH \n",Account.Balance);
}

int Details() {
    printf("께께께께께께께께께께께께께께께께께께께께콭ccount Holder 께께께께께께께께께께께께께께께께께께께께께�\n");
    printf("\t -First Name of account holder  : %s \n",Account.FirstName);
    printf("\t -Last Name of account holder   : %s \n",Account.LastName);
    printf("\t - Amount withdrawn is          : %d DH \n",Account.WithDraw);
    printf("\t -You Have Now / Balance Amount : %d DH \n",Account.Balance);
    printf("께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께\n");
}

int Customers(){
    printf("께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께");
    printf("\t\tThe List Of Customers (clients) !: \n");

    FILE *fPointer;
    char display[150];
    fPointer = fopen("List.txt","r");
    while(fgets(display,150,fPointer)){
        printf("%s",display);

    }
    fclose(fPointer);
    printf("께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께\n");


}


int main()
{   int Choice; // It is a directed variable to the User to chose one of the menu elements !
    printf("\t\t*****************Gestion Bancaire***************** \n");
    printf("---------------------------------------------------------------------------------------------------\n");
    printf("\n");
    do {
        MenuPrin(); // Calling Function inside loop after the end of Cases!
        printf("--> *you Need to :");
        scanf("%d",&Choice);
        printf("=================================================================================================\n");
        switch(Choice){
            case 1 : AccCreation();     break;
            case 2 : DipositBalance();  break;
            case 3 : WithDrawBalance(); break;
            case 4 : CheckBalance();    break;
            case 5 : Details();         break;
            case 6 : Customers();       break;

        }
    }while(Choice != 7);




    return 0;
}
