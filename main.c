#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 // This Functions Contains Menu of what Customers can in our service !
    void MenuPrin(){
        printf("\t\t\t****************Menu********************************\n");
     printf("\t\t\t--> 1  - Create an Account\n");
     printf("\t\t\t--> 2  - Diposit balance\n");
     printf("\t\t\t--> 3  - WithDraw balance\n");
     printf("\t\t\t--> 4  - Check Balance\n");
     printf("\t\t\t--> 5  - List of The Customers(Clients)\n");
     printf("\t\t\t--> 6  -Sorting by Ascending \n");
     printf("\t\t\t--> 7  -Sorting by Descending\n");
     printf("\t\t\t--> 8  -Search by CIN\n");
     printf("\t\t\t--> 9  -Loyalty\n");
     printf("\t\t\t--> 10  -Exit\n");
        printf("\t\t\t********************welcome to our service**************************\n");
}
// Struct Contains what Customers Need To Create / get into Account
typedef struct Customer{
        char FirstName[100];
        char LastName[100];        // Account info contains all elements that we need to create an account !!
        char CIN [20];
        float Balance ;

    }customer;


     int main(){
        customer  customer[40];
        int i,j;
        int Choice;       // customer choice --> Main Menu
        char Cheking[20]; // Check if THE CIN Is Correct or not !
        int AccountNmbr;
        int Change;
        int Exit;
        printf("\t\t-------------------------------Welcom-------------------------------\n\n");
        printf("\t\t\t*****************Bank Management***************** \n");
        printf("---------------------------------------------------------------------------------------------------\n");
        printf("\n");
        do {
        MenuPrin();
        printf("--> Please What is your choice :");
        scanf("%d",&Choice);
        printf("=================================================================================================\n");
            switch(Choice){
                case 1 :
                printf("How Many Account You Want to Create : ");
                scanf("%d",&AccountNmbr);
                printf("-----------------------------------------------------------------------------------------\n");
                for (i=0 ; i<AccountNmbr;i++){
                    printf("\t -First Name of account holder              : ");
                    scanf(" %s",&customer[i].FirstName);
                    printf("\t -Last Name of account holder               : ");
                    scanf(" %s",&customer[i].LastName);
                    printf("\t -CIN of the account holder                  : ");
                    scanf(" %s",&customer[i].CIN);
                    printf("\t -Balance  to complete creation( =100 DH )  : ");
                    scanf("%f",&customer[i].Balance);
                    // Verification of Condition
                        if (customer[i].Balance == 100){
                            printf("\nAccount has been created successfully ! \n\n");
                        }else if(customer[i] .Balance != 100){
                            printf("\t -Please you must pay just 100 DH ( =100 DH )   : ");
                            scanf(" %d",&customer[i] .Balance);
                        if(customer[i].Balance = 100) {
                            printf("\nAccount has been created successfully ! \n\n");

                         }
                        }
                    printf("=================================================================================================\n");
                }
                break;

                case 2 :
                        for (i=0 ; i<AccountNmbr ; i++){
                            printf("-->Please Enter The CIN to get The Abilitiy to :diposit Balance :");
                            scanf(" %s",&Cheking);
                            printf("PIN is %s \n ",Cheking);
                                for(j=0 ; j<AccountNmbr ;j++){
                                if (strcmp(customer[j].CIN , Cheking)==0) {
                                printf("-->%s %s \n",customer[j].FirstName,customer[j].LastName);
                                printf("\tEnter deposit amount ( DH ) :");
                                float deposit;
                                scanf("%f",&deposit);
                                customer[j].Balance += deposit;
                                printf("--> You Just Diposit %.2f DH \n",deposit);
                                printf("--> Now You Have %.2f DH on your Account\n\n",customer[j].Balance);
                                }
                             }break;
                        }
                                break;
                case 3 :
                     for (i=0 ; i<AccountNmbr ; i++){
                        printf("-->Please Enter The CIN to get The Abilitiy to : WithDraw Balance :");
                        scanf(" %s",&Cheking);
                        printf("-->PIN is: %s \n",Cheking);
                        for (j=0 ; j<AccountNmbr ; j++){
                            if (strcmp(customer[j].CIN , Cheking)==0) {
                                printf(" %s %s \n",customer[j].FirstName,customer[j].LastName);
                                printf("\tEnter WithDraw amount ( DH ) :");
                                float WithDraw;
                                scanf("%f",&WithDraw);
                                customer[j].Balance -= WithDraw;
                                printf("--> You WithDraw %.2f DH from you Account \n",WithDraw);
                                printf("--> Now You Have %.2f DH on your Account\n",customer[j].Balance);
                                  }
                        }break;
                     }
                            break;
                case 4 :
                    for (i=0 ;i<AccountNmbr ; i++){
                     printf("--> %s %s  have %.2f DH on your Account\n",customer[i].FirstName,customer[i].LastName,customer[i].Balance);
                    }
                    break;


                case 5 :
                    printf("\n께께께께께께께께께께께께께께께께께께께께콼ist Of Customers께께께께께께께께께께께께께께께께께께께께께�\n");
                    for(i=0 ; i<AccountNmbr ; i++){
                        printf("--> Account %d- under Name %s %s have %.2f DH\n",i+1,customer[i].FirstName,customer[i].LastName,customer[i].Balance);

                    }
                    printf("께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께\n");
                    break;

                case 6 :
                    printf("display of the balance in ascending order :\n");
                    for (i=0 ; i<AccountNmbr ; i++){
                    for (j=i+1 ; j<AccountNmbr ; j++){
                        if(customer[i].Balance > customer[j].Balance){
                            Change = customer[i].Balance;
                            customer[i].Balance = customer[j].Balance;
                            customer[j].Balance = Change;
                            }
                        }
                    }
                    for (i=0 ; i<AccountNmbr ; i++) {
                        printf(" %d)- %.2f \n",i+1,customer[i].Balance);
                    }
                    printf("=================================================================================================\n");
                    break;


                case 7 :
                    printf("display of the balance in descending order\n");
                    for (i=0 ; i<AccountNmbr ; i++){
                    for (j=i+1 ; j<AccountNmbr ; j++){
                        if(customer[i].Balance < customer[j].Balance){
                            Change = customer[i].Balance;
                            customer[i].Balance = customer[j].Balance;
                            customer[j].Balance = Change;
                            }
                        }
                    }
                        for (i = 0 ; i<AccountNmbr ; i++) {
                            printf(" %d)- %.2f \n",i+1,customer[i].Balance);
                        }
                       printf("=================================================================================================\n");
                    break;

                case 8 :

                    printf("Search By CIN\n");
                    char Search [50];
                    printf("Please Enter CIN You Looking For :");
                    scanf("%s",&Search);
                    printf("=================================================================================================\n");
                     for (i=0 ; i<AccountNmbr ; i++){
                            if(strcmp(customer[i].CIN , Search)==0) {
                                printf("Account is nominated To : %s %s \n",customer[i].FirstName,customer[i].LastName);
                                break;
                            }
                            if (strcmp(customer[i].CIN , Search)==1){
                            printf("Account Doesn't Exist !\n");
                            break;
                        }
                        }
                    printf("=================================================================================================\n");
                     break;

                case 9 :
                    printf("=================================================================================================\n");
                    printf("Adding 1.3 to First 3 Loyalty Clients\n");
                    for (i=0 ; i<AccountNmbr ; i++){
                    for (j=0 ; j<AccountNmbr ; j++){
                        if(customer[i].Balance > customer[j].Balance){
                            Change = customer[i].Balance;
                            customer[i].Balance = customer[j].Balance;
                            customer[j].Balance = Change;
                            }
                        }
                    }
                    for (i=0 ; i<3 ; i++) {
                        customer[i].Balance += customer[i].Balance * 0.013;
                    }
                    printf("Pourcentage Aded successfully \n");
                    printf("Go Back To main menu and check List of Customers\n");
                    printf("=================================================================================================\n");
                    break;

                default :
                    printf("Your Choice Is Invalid\n");
            } // switch case!
            } while (Choice != 11);



return 0;
}




