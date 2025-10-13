#include <stdio.h>
#define N 3


int queue[N];
int front = -1;
int rear = -1;

void enque(int x){
    if(rear == (N-1))
        printf("queue overflow");
    else if(front == -1 && rear == -1){
        front++;
        rear++;
        queue[rear] = x;
    }
    else{
        rear++;
        queue[rear] = x;
    }
}

void deque(){
    if(front == -1 && rear == -1)
        printf("queue is empty\n");
    else if(front == rear)
        front = rear = -1;
    else{
        printf("%d is deleted\n",queue[front]);
        front++;
    }
}

void display(){
    if (front == -1 && rear == -1)
        printf("queue is empty\n");
    else{
        for(int i = front;i<=rear;i++)
            printf("%d",queue[i]);
    }
}

void peek(){
    if (front == -1 && rear == -1)
        printf("queue is empty\n");
    else
        printf("%d",queue[front]);
}

void main(){
    int c,d;
    for(int i = 0;i>=0;i++){
        printf("enter 1 2 3 4 5\n");
        scanf("%d",&c);
        switch (c){
            case 1 : printf("enter value to queue\n");
                     scanf("%d",&d);
                     enque(d);
            break;
            case 2 : deque();
            break;
            case 3 : peek();
            break;
            case 4 : display();
            break;
            default : exit(1);
        }
    }
}
