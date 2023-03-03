#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int info;
    struct node *prev;
    struct node *next;
}s;

s *head=NULL, *tail=NULL;

void insatbeg(int val)
{
    s *p = (s*)malloc(sizeof(s));
    if(p==NULL)
        printf("Memory Overflow!!");
    else
    {
        p->info = val;
        if(head==NULL)
        {
            head=tail=p;
            p->prev=p;
            p->next=p;
        }
        else
        {
            p->next = head;
            p->prev = tail;
            head->prev= p;
            tail->next=p;
            head=p;
        }
    }
}

void insatend(int val){
    s *p=(s*)malloc(sizeof(s));
    if(p==NULL)
    printf("Memory Overflow!!");
    else
    {
        p->info = val;
        if (head==NULL){
            head=tail=p;
            p->prev=head;
            p->next=head;
        }
        else{
            p->prev= tail;
            p->next=head;
            tail->next=p;
            head->prev=p;
            tail=p;
        }
    }
}

void insatanypos(int val, int pos)
{
    int i =1, l = sizeof(s);
    s *p = (s*)malloc(sizeof(s));
    if(p==NULL)
    printf("Memory Overflow!!");
    else{
        p->info =val;
        if(pos<1 || pos>l)
        printf("Invalid Position!!!!");
        if (pos==1)
            insatbeg(val);
        if(head==NULL)
        {
            head=tail=p;
            p->prev=head;
            p->next=head;
        }
        else
        {
            s *p1=head;
            while(i<pos-1){
                p1=p1->next;
                i++;
            }
            p->prev= p1;
            p->next=p1->next;
            p1->next->prev=p;
            p1->next=p;
        }
    }
}

void delfrombeg()
{
    s *p1=head;
    if (head==NULL)
        printf("Linked List is Empty!!!");
    else{

        if(head->next==head)
        {
            head=tail=NULL;
            free(p1);
        }
        else{
            head=head->next;
            free(p1);
            head->prev= tail;
            tail->next=head;
        }
    }   
}

void delfromend(){
    s *p1=tail;
    if(head==NULL){
        printf("Linked List is empty!!!");
    }
    else{
        if(head->next==head)                     //single node
        {
            head=tail=NULL;
            free(p1);
        }
        else{
            tail=tail->prev;
            tail->next=head;
            head->prev=tail;
            free(p1);
        }
    }
}

void delfromanyposition(int pos)
{
    int i=1;
    int l = sizeof(s);
    s*p1=head;
    if(head==NULL)
        printf("Linked List is Empty!!");
    else{
        if(pos==1)
            delfrombeg();
        if(pos<1 || pos>l)
            printf("Invalid Position!!");
        else{
            while(i<=pos)
            {
                p1=p1->next;
                i++;
            }
            p1->prev->next = p1->next;
            p1->next->prev=p1->prev;
            free(p1);
        }
    }
}

void search(int item)
{
    int flag=1;
    s *p1=head;
    if(head==NULL)
    printf("Linked List is Empty!!");
    
    if(p1->info==item)
    {
        flag=0;
    }
    p1=p1->next;
    while(p1!=NULL)
    {
        if(p1->info==item)
        {
            flag=0;
            break;
        }
        p1=p1->next;
    }
    if(flag==0)
    printf("Item Found!!!");
    else{
        printf("Item not Found!!");
    }
}

void display()
{

    s *p1=head;
    if(head==NULL)
    printf("Linked List is Empty!!!");

    else{
        if(p1->next!=head)
            printf("%d-->", p1->info);
        else
            printf("%d", p1->info);
        p1=p1->next;
        while(p1!=head)
        {
            if(p1->next!=head)
            printf("%d-->", p1->info);
            else
            printf("%d", p1->info);
            p1=p1->next;
        }
    }
}

int main(){
    int val, item, pos, choice;
    do
    {
        printf("\n1. Insertion at Beginning\n");
        printf("2. Insertion at End\n");
        printf("3. Insertion at any position\n");
        printf("4. Deletion From Beginning\n");
        printf("5. Deletion From End\n");
        printf("6. Deletion From Any Position\n");
        // printf("7. Length of Circular Linked List\n");
        printf("7. Searching\n");
        printf("8. Display\n");
        printf("\n");
        printf("Enter Choice :: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            {
                printf("Enter the Value:");
                scanf("%d", &val);
                insatbeg(val);
                break;
            }
            case 2:
            {
                printf("Enter the Value:");
                scanf("%d", &val);
                insatend(val);
                break;                
            }
            case 3:
            {
                printf("Enter The Position : ");
                scanf("%d", &pos);
                printf("Enter the Value :");
                scanf("%d", &val);
                insatanypos(val, pos);
                break;
            }
            case 4:
            {
                delfrombeg();
                break;
            }
            case 5:
            {
                delfromend();
                break;
            }
            case 6:
            {
                printf("Enter the position from which you want to delete : ");
                scanf("%d", &pos);
                delfromanyposition(pos);
                break;
            }
            case 7:
            {
                printf("Enter the item : ");
                scanf("%d", &item);
                search(item);
                break;
            }
            case 8:
            {
                display();
                break;
            }
            default:
            {
                printf("Wrong Choice");
                exit(0);
            }
        }
    }while(1);

    return 0;
}