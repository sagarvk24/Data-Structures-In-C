#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int info;
    struct Stack *next;
}s;

s *top=NULL;

void push(int val){
    s *p=(s*)malloc(sizeof(s));
    p->info=val;
    p->next=top;
    top=p;
}

void pop(){
    s *p1=top;
    if (top==NULL)
    printf("Stack is Empty!!!!");
    else{
        printf("%d has been popped!!", top->info);
        top=top->next;
        free(p1);
    }
    printf("\n");
}

void peek(){
    if(top==NULL)
    printf("Stack is Empty!!");
    else{
        printf("Topmost Element is :: %d",top->info);
    }
    printf("\n");
}

void LengthofStack(){
    int ctr=0;
    if(top==NULL)
    printf("Stack is Empty!!!");
    else{
        s *p1=top;
        while(p1!=NULL){
            ctr++;
            p1=p1->next;
        }
    }
    printf("Length of Stack ::%d", ctr);
    printf("\n");
}

void display(){
    s *p1=top;
    if (top==NULL)
    printf("Stack is Empty!!");
    else{
        while(p1!=NULL){
            printf("%d\t", p1->info);
            p1=p1->next;
        }
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
        printf("5. Display of Stack\n");
        printf("\n");
        printf("Enter Your Choice::");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter the value:");
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
