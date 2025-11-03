#include <stdio.h>
#define N 3


int queue[N];
int front = -1;
int rear = -1;

void enque(int x){
    if(front == (rear+1)%N)
        printf("queue overflow\n");
    else if(front == -1 && rear == -1){
        front++;
        rear++;
        queue[rear] = x;
    }
    else{
        rear = (rear+1)%N;
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
        front = (front+1)%N;
    }
}

void display(){
    if (front == -1 && rear == -1)
        printf("queue is empty\n");
    else{
        int i = front;
        while(i != rear){
            printf("%d",queue[i]);
            i = (i+1)%N;
        }
        printf("%d",queue[rear]);
    }
}

void main(){
    int c,d;
    for(int i = 0;i>=0;i++){
        printf("enter 1 2 3 \n");
        scanf("%d",&c);
        switch (c){
            case 1 : printf("enter value to queue\n");
                     scanf("%d",&d);
                     enque(d);
            break;
            case 2 : deque();
            break;
            case 3 : display();
            break;
            default : exit(1);
        }
    }
}
