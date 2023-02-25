#include <stdio.h>
#include <stdlib.h>
# define N 6

int stack[N];
int top = -1;

void push(int val){
    if(top==N-1)
    printf("Overflow!!!");
    else{
        top++;
        stack[top]=val;
    }
}

void pop(){
    int item;
    if (top==0)
    printf("Stack is Empty!!!");
    else{
        item = stack[top];
        top--;
    }
    printf("%d has been popped!!\n", item);
}

void peek(){
    if(top==0)
    printf("Stack is Empty!!!");
    else{
        printf("%d is the Topmost Element of the stack.\n", stack[top]);
    }
}

void LengthofStack(){
    int ctr=0;
    if(top==0)
    printf("Stack is Empty!!!");
    else{
        for(int i=top; i>=0; i--){
            ctr++;
        }
    printf("Length of Stack :: %d\n", ctr);
    }
}

void display(){
    if(top==0)
    printf("Stack is Empty!!");
    else{
        for(int i=top; i>=0; i--)
        printf("%d\n", stack[i]);
    }
    printf("\n");
}

int main(){
    int val, choice;
    do{
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Length of Stack\n");
        printf("5. Display Stack\n");
        printf("\n");
        printf("Enter Choice :");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter the value :");
                scanf("%d", &val);
                push(val);
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                peek();
                break;
            }
            case 4:
            {
                LengthofStack();
                break;
            }
            case 5:
            {
                display();
                break;
            }
            default:
            {
                printf("Wrong Choice!!!");
                exit(0);
            }
        }
    }while(1);
    return 0;
}
