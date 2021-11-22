#include <stdio.h>
#include <stdlib.h>
 // This Functions Contains Menu of what Customers Can Get Into it
    void MenuPrin(){
        printf("\t\t\t****************Menu****************\n");
     printf("\t\t\t--> 1  - Create an Account\n");
     printf("\t\t\t--> 2  - Diposit balance\n");
     printf("\t\t\t--> 3  - WithDraw balance\n");
     printf("\t\t\t--> 4  - Check Balance\n");
     printf("\t\t\t--> 5  - Account Holder Info's \n");
     printf("\t\t\t--> 6  - List of The Customers(Clients)\n");
     printf("\t\t\t--> 7 - Exit\n");
}
// Struct Contains what Customers Need To Create or to get into Account
    struct AccountInfo{
        char FirstName[100];
        char LastName[100];        // Account info contains all elements that we need to create an account !!
        char CIN [20];
        int Balance , Diposit , WithDraw;

    }Account;
// Function Related To The First Elements of Menu ( 1 - Creation an account)

    int AccCreation(){
// Declaration of a Function that help us to give the user Steps to create an account
        printf("\t -First Name of account holder              : ");
        scanf("%s",&Account.FirstName);
        printf("\t -Last Name of account holder               : ");
        scanf("%s",&Account.LastName);
        printf("\t -CIN of the account holer                  : ");
        scanf("%s",&Account.CIN);
        printf("\t -Balance  to complete creation( =100 DH )  : "); // to create Account Successuflly (The customer must pay 10 DH)
        scanf("%d",&Account.Balance);
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

    }
// Function Related To The Secound Elements of Menu ( 1 - Creation an account)
    int DipositBalance(){
 /*After getting into the function The Customer Must give CIN to complete instructions and for that we're going to add
    a Variable that Check if The CIN =true or CIN = false . ! */
        char Cheking[20];
        printf("-->Please Enter The CIN to get The Abilitiy to :diposit Balance :");
        scanf(" %s",&Cheking);
        if (strcmp(Account.CIN, Cheking)==0) {
             printf("\tEnter deposit amount ( DH ) :");
            scanf("%d",&Account.Diposit);
            Account.Balance += Account.Diposit;
            printf("--> You Just Diposit %d DH \n",Account.Diposit);
            printf("--> Now You Have %d DH on your Account\n",Account.Balance);

        }else {
            printf("-->CIN INVALIDE !!. Back to main menu and choose(2)to try Again ! \n");
            printf("==========================================================================================\n");
        }

    }
//// Function Related To The Third Elements of Menu ( 3- WithDrawn Balance) !
   int WithDrawBalance(){
    char Cheking[20];
    printf("-->Please Enter The CIN to get The Abilitiy to :WithDrawn Balance :");
    scanf("%s",&Cheking);
    if (strcmp(Account.CIN, Cheking)==0) {
        printf("\tEnter WithDraw amount ( DH ): ");
        scanf("%d",&Account.WithDraw);
/* Cheking if (Balance Amount >WithDrawn) let Costumer to WithDraw Money if not tell the Costumer that his can not
    to With Draw Money */
    if(Account.WithDraw <= Account.Balance) {
        printf("-----------------------------------------------------------------------------------------------\n");
        printf("--> You Have Just Take %d DH from Your Account !! \n",Account.WithDraw);
        Account.Balance -= Account.WithDraw;
        printf("--> Now You Have %d DH on your Account\n",Account.Balance);
        printf("------------------------------------------------------------------\n\n");

        }
        else if (Account.WithDraw > Account.Balance){
        printf("You Just Have %d DH , You Can't WithDrawn %d DH!!!!!\n",Account.Balance,Account.WithDraw);
        printf("Please Go  Back To main Menu and Try Again ! with Withdrawn <= Balance of Your Account :");
        printf("------------------------------------------------------------------\n\n");
            }
    }else {
            printf("-->CIN INVALIDE !!. Back to main menu and choose(2)to try Again ! \n");
            printf("==========================================================================================\n");
        }
 }

//Function Related To The forth Elements of Menu ( 4 - Check Balance )
    int CheckBalance(){
        printf("    --> Now You Have : %d DH \n",Account.Balance);
    }
//Function Related To The 5 Elements of Menu ( 5 - Account Holder Info's )
    int Details() {
        printf("께께께께께께께께께께께께께께께께께께께께콭ccount Holder 께께께께께께께께께께께께께께께께께께께께께�\n");
        printf("\t -First Name of account holder  : %s \n",Account.FirstName);
        printf("\t -Last Name of account holder   : %s \n",Account.LastName);
        printf("\t - Amount withdrawn is          : %d DH \n",Account.WithDraw);
        printf("\t -You Have Now / Balance Amount : %d DH \n",Account.Balance);
        printf("께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께\n");
    }

        int Customers(){
        printf("께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께\n");
        printf("\t\tThe List Of Customers (clients) !: \n");

        FILE *fPointer;
        char display[150];
        fPointer = fopen("List.txt","r+");
        while(fgets(display,150,fPointer)){
            printf("%s",display);

        }
        fclose(fPointer);
        printf("께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께\n");





  int main()
{   int Choice; // It is a directed variable to the User to chose one of the menu elements !
    printf("\t\t-------------------------------Welcom-------------------------------\n\n");
    printf("\t\t\t*****************Gestion Bancaire***************** \n");
    printf("---------------------------------------------------------------------------------------------------\n");
    printf("\n");
    do {
        MenuPrin(); // Calling Function inside loop after the end of Cases!
        printf("--> *you Need to :");
        scanf("%d",&Choice);
        printf("=================================================================================================\n");
        switch(Choice){
            case 1 : AccCreation();              break;
            case 2 : DipositBalance();           break;
            case 3 : WithDrawBalance();          break;
            case 4 : CheckBalance();             break;
            case 5 : Details();                  break;
            case 6 : Customers();                break;




        }
    }while(Choice != 7);




    return 0;
}



