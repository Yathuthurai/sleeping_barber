#include <stdio.h>
#include <stdlib.h>

struct chair
{
    int clientNum;                   //variable to store client id
    struct chair *next;              //pointer to next node
};

struct chair* create()                 //function to create  pointers
{
    struct chair *baby;
    baby=(struct chair*)malloc(sizeof(struct chair));

    return baby;
}

int main()
{
    struct chair* start=NULL;                   //pointer for initial node
    struct chair* neww;                     //pointer to create new nodes
    struct chair* ptr,*preptr;              //pointers to traverse threw the list

    int count,cnum=0,opt;       //variables  chair count, client id , option for menu
    static int i=1;                //variable to keep track of existing clients

    printf("\t\t=================>SLEEPING BARBER<=================== ");

    printf("\n\t\tHow many chairs you wish to add in the barber shop :");
    scanf("%d",&count);                                                    //receiving user input number of chair in the barber shop
    printf("\t\t=====================================================\n");

    printf("\n\t-----------------------------------------\n\t| Here are the options\t\t\t|\n\t-----------------------------------------\n\t| 1.New Client comes to the shop\t|\n\t| 2.Client leaving after hair cut\t|\n\t| 3.Exit program\t\t\t|\n\t-----------------------------------------\n");      //menu

printf("\n\t--------------------------------------");
    printf("\n\t|  No clients barber is sleeping now! |");               //initial state of barber
    printf("\n\t--------------------------------------");

    while(opt!=3)
    {
         printf("\n\nEnter the option :");
    scanf("%d",&opt);                                 //receiving user inputs

    switch (opt)
    {    //adding clients
        case 1 : if(i>count)           //checking whether a seat available for the new customer
                    printf("\n\tNo seats available. customer goes back.");
                    else{ if(i==1){    //checking : is there any previous node ?
                        start=create();            //setting the initial node
                        ptr=start;                    //accessing the start node
                        ptr->clientNum=++cnum;              //setting the customer id
                        printf("\n\tClient %d is coming to the shop , he wakes the barber and gets a haircut.",ptr->clientNum);
                    }
                    else{
                        neww=create();           //creating new nodes which follow stat node
                        ptr->next=neww;           //setting the link from previous node to new node
                        ptr=neww;                   //accessing the new node
                        ptr->clientNum=++cnum;         //setting customer id
                        printf("\n\tClient %d comes to the shop, client sits and waits",ptr->clientNum);
                    }

                    ptr->next=NULL;  //setting the last node pointer next reference as NULL
                    ++i;             //keeping track of the total clients who are currently waiting + having hair cut
                    }break;



 //remove client
        case 2 :  if(start==NULL){  //checking : is there aren't any node ?
        printf("\n\t----------------------------------");
    printf("\n\t|  No client barber is sleeping  |");
    printf("\n\t----------------------------------");}
                    else
                    {
                        preptr=start;         //if there is start node sets it as preptr
                        start=start->next;    //changing the stat position to the next node, in the list
                        printf("\n\tClient %d is leaving ",preptr->clientNum);

                        if(preptr->next!=NULL)     //checking : is there any node after the current(after the preptr) node ?
                            printf("& client %d having a hair cut",preptr->next->clientNum);

                        free(preptr);   //removing preptr
                        i--;  //keeping track of the total clients who are currently waiting + having hair cut
                         if(start==NULL){   //checking : is there aren't any node ?
                            printf("\n\t------------------------------------------");
    printf("\n\t|  No client barber goes to sleep again  |");
    printf("\n\t------------------------------------------");
                         }


                    } break;

                    case 3: printf("\nQuiting program......");break;

                    default : printf("\n\tInvalid input.");
    }
    }






    return 0;
}
