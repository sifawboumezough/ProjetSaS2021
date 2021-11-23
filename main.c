#include <stdio.h>
#include <stdlib.h>
 // This Functions Contains Menu of what Customers Can Get Into it
    void MenuPrin(){
        printf("\t\t\t****************Menu****************\n");
     printf("\t\t\t--> 1  - Create an Account\n");
     printf("\t\t\t--> 2  - Diposit balance\n");
     printf("\t\t\t--> 3  - WithDraw balance\n");
     printf("\t\t\t--> 4  - Check Balance\n");
     printf("\t\t\t--> 5  - List of The Customers(Clients)\n");
     printf("\t\t\t--> 6 - Exit\n");
}
// Struct Contains what Customers Need To Create or to get into Account
typedef   struct Customer{
        char FirstName[100];
        char LastName[100];        // Account info contains all elements that we need to create an account !!
        char CIN [20];
        float Balance ;
    }customer;


     int main(){
        customer  customer[5];
        int i,j;
        int Choice;
        int AccountNmbr;
         char Cheking[20]; // Check if THE CIN Is Correct or not !
        printf("\t\t-------------------------------Welcom-------------------------------\n\n");
        printf("\t\t\t*****************Gestion Bancaire***************** \n");
        printf("---------------------------------------------------------------------------------------------------\n");
        printf("\n");
        do {
        BACK : MenuPrin();
        printf("--> *you Need to :");
        scanf("%d",&Choice);
        printf("=================================================================================================\n");
            switch(Choice){
                case 1 :
                printf("How Many Account You Want to Create : ");
                scanf("%d",&AccountNmbr);
                printf("-----------------------------------------------------------------------------------------\n");
                for (j=0 ; j<AccountNmbr ; i++){
                for (i=0 ; i<AccountNmbr;i++){
                    printf("\t -First Name of account holder              : ");
                    scanf("%s",&customer[i].FirstName);
                    printf("\t -Last Name of account holder               : ");
                    scanf("%s",&customer[i].LastName);
                    printf("\t -CIN of the account holder                  : ");
                    scanf("%s",&customer[i].CIN);
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
                    printf("-----------------------------------------------------------------------\n");
                }
                    break;
                }


                break;

                case 2 :

                        for (i=0 ; i<AccountNmbr ; i++){
                            printf("-->Please Enter The CIN to get The Abilitiy to :diposit Balance :");
                            scanf(" %s",&Cheking);
                            printf("Your PIN is %s \n ",Cheking);
                            for (j=0 ; j<AccountNmbr ; j++){
                                if (strcmp(customer[j].CIN , Cheking)==0) {
                                printf(" %s %s \n",customer[j].FirstName,customer[j].LastName);
                                printf("\tEnter deposit amount ( DH ) :");
                                float deposit;
                                scanf("%f",&deposit);
                                customer[i].Balance += deposit;
                                printf("--> You Just Diposit %.2f DH \n",deposit);
                                printf("--> Now You Have %.2f DH on your Account\n\n",customer[i].Balance);
                                }
                            }
                        }
                                break;
                case 3 :
                     for (i=0 ; i<AccountNmbr ; i++){
                        printf("-->Please Enter The CIN to get The Abilitiy to : WithDraw Balance :");
                        scanf(" %s",&Cheking);
                        printf("Your PIN is %s \n",Cheking);
                        for (j=0 ; j<AccountNmbr ; j++){
                            if (strcmp(customer[j].CIN , Cheking)==0) {
                                printf(" %s %s \n",customer[j].FirstName,customer[j].LastName);
                                printf("\tEnter WithDraw amount ( DH ) :");
                                float WithDraw;
                                scanf("%f",&WithDraw);
                                customer[i].Balance -= WithDraw;
                                printf("--> You Just Diposit %.2f DH \n",WithDraw);
                                printf("--> Now You Have %.2f DH on your Account\n",customer[i].Balance);
                            }
                        }
                     }
                            break;
                case 4 :
                    for (i=0 ;i<AccountNmbr ; i++){
                     printf("--> %s %s  have %.2f DH on your Account\n",customer[i].FirstName,customer[i].LastName,customer[i].Balance);
                    }
                    break;


                case 5 :
                    printf("\n께께께께께께께께께께께께께께께께께께께께콼ist Of Customers께께께께께께께께께께께께께께께께께께께께께�\n");
                    for (j=0 ; j<AccountNmbr ; i++){
                    for(i=0 ; i<AccountNmbr ; i++){
                        printf("--> Account %d- under Name %s %s have %.2f DH\n",i+1,customer[i].FirstName,customer[i].LastName,customer[i].Balance);

                    }
                    break;
                    }


                    printf("께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께께\n");
                    break;

            } // switch case!
            } while (Choice != 6);



return 0;
}




