// C program for array implementation of queue
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>

// A structure to represent a queue
struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// function to create a queue of given capacity.
// It initializes size of queue as 0
struct Queue* createQueue(unsigned cap)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = cap;
    queue->front = queue->size = 0;
    queue->rear = cap - 1;  // This is important, see the enqueue
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Queue is full when size becomes equal to the capacity
bool isFull(struct Queue* queue)
{  return (queue->size == queue->capacity);  }

// Queue is empty when size is 0
bool isEmpty(struct Queue* queue)
{  return (queue->size == 0); }

// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d Added to waiting room\n\n", item);
}

// Function to remove an item from queue.
// It changes front and size
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to get front of queue
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// Function to get rear of queue
int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

static bool barber = false;

void saloon(char ch,int time,struct Queue* queue ){
    if(toupper(ch)=='A'){
        enqueue(queue,time);
        barber = true;
        ch = true;
    }
}



// Driver program to test above functions./
int main()
{

    bool ch = true,sleep = false;;
    char check = 'X';
    int n;
    printf("\n\n##########################################################\n\n");
    printf("################ Welcome to Sleeping Barber ##############\n\n");
    printf("##########################################################\n");


    printf("\n\n\t\t COMMAND INFORMATION \n\n");

    printf("Type 'A' to add customer to the saloon\n");
    printf("Type 'F' to finish the hair cut of current customer\n");
    printf("Type 'Q' to quit this program\n\n\n");

    printf("Enter the number of chairs in waiting room:");
    if(scanf("%d", &n) != 1){
        printf("The Number you entered is wrong. Enter an integer number!\n");
        return 0;
    }

    getchar(); //avoiding enter
    printf("\n\n");
    struct Queue* queue = createQueue(n);
    int count =1;

    while(check!='Q'){

        printf("Enter your option A or F or Q:");
        scanf("%c",&check);
        getchar();
        if(barber==false && toupper(check)=='A'){
            count = 1;
            if(sleep==false)
                printf("Client came.Barber is Busy\n\n");
            else
                printf("Client came! & wake up barber.\n barber is busy now\n\n");
            barber = true;
            ch = true;
            count++;

        }
        else if(count>1 && !isFull(queue) && toupper(check)=='A'){

            saloon(check,count-1,queue);
            count++;

        }
        else if(isFull(queue) && toupper(check)!= 'F'){
            printf("Waiting room is full. So clients leave\n\n");
        }
        else if(toupper(check)== 'F' && !isEmpty(queue)){
            printf("Current Client's cutting finished!\n\n");

            count--;
            dequeue(queue);
        }
        else if(barber == false && isEmpty(queue) && toupper(check)!= 'Q' && ch!=false && toupper(check)!= 'F'){
            printf("Current Client's cutting finished!\n\n");
            printf("Barber is going to sleep\n\n");
            ch = false;
            sleep = true;
        }
        else if(toupper(check)== 'Q'){
            printf("You quited the program bye bye!!!!\n\n\n");
            return 0;
        }
        else if(toupper(check)== 'F' && isEmpty(queue) && barber == true){
            printf("Current Client's cutting finished. No clients so barber is going to sleep!\n\n");
            barber = false;
            count = 1;
        }
        else if(toupper(check)== 'F' && isEmpty(queue) && barber == false){
            printf("There is no one for hair cutting.\n\n");
        }
        else if(toupper(check)!= 'A' && toupper(check)== 'F' && toupper(check)!= 'Q'){
            printf("The command you entered is wrong. Re-Enter the write Command!\n\n");
        }
        else if(toupper(check)!= 'Q' && toupper(check)!= 'F' && toupper(check)== 'Q'){
            printf("The command you entered is wrong. Re-Enter the write Command!\n\n");
        }
        else if(toupper(check)!='F' && toupper(check)== 'A' && toupper(check)!= 'Q'){
            printf("The command you entered is wrong. Re-Enter the write Command!\n\n");
        }






    }
    printf("\n");

    return 0;
}
