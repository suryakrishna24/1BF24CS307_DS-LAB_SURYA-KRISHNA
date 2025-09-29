#include <stdio.h>
#define N 3
int top = -1;
int stack[N];

void push(){
    int x;
    printf("enter a num\n");
    scanf("%d",&x);
    if(top == (N-1))
        printf("overflow\n");
    else{
        top++;
        stack[top] = x;
    }
}

void pop(){
    int x;
    if(top == -1)
        printf("underflow\n");
    else{
        x = stack[top];
        top--;
        printf("%d",x);
    }
}

void peek(){
    if(top == -1)
        printf("underflow\n");
    else
        printf("%d\n",stack[top]);
}

void main(){
    int ch;
    for(int y = 0;y < N+1;y++){
        printf("enter 1 for push\n");
        printf("enter 2 for pop\n");
        printf("enter 3 for peek\n");
        scanf("%d",&ch);
        switch(ch){
            case 1 : push();
            break;
            case 2 : pop();
            break;
            case 3 : peek();
            break;
        }
    }
}
