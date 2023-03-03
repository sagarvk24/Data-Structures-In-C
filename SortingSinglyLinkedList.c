#include <stdio.h>
#include <stdlib.h>

typedef struct SLLNode{
    int info;
    struct SLLNode *next;
}s;

// s *head=NULL;

s *create()
{
    s *head=NULL;
    int val, choice; 
    s *p1=NULL;
    int flag = 1;
    while(flag)
    {
        s *p=(s*)malloc(sizeof(s));
        // if p
        printf("Enter the value of node:");
        scanf("%d", &p->info);
        p->next=NULL;

        if(head==NULL)
            head=p1=p;
        else
        {
            p1->next=p;
            p1=p1->next;
        }
        printf("1.Continue\n");
        printf("2.Stop\n");
        printf("Enter Choice::");
        scanf("%d", &choice);
        if(choice!=1)
        flag = 0;
    }
    return head;
}

void display(s *head)
{
    s *p1=head;
    if(head==NULL)
        printf("Linked List is Empty!!");
    else
    {
        while(p1!=NULL)
        {
            if(p1->next!=NULL)
                printf("%d-->", p1->info);
            else
                printf("%d", p1->info);
            p1 = p1->next;
        }
    }
    printf("\n\n");
}

void descsorting(s *head)
{
    s *p1, *p2;
    int new;
    p1=head;
    while(p1->next!=NULL)
    {
        p2=p1->next;
        while(p2!=NULL)
        {
            if(p1->info < p2->info)
            {
                new=p1->info;
                p1->info=p2->info;
                p2->info=new;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
}

void ascsorting(s *head)
{
    s *p1, *p2;
    int new;
    p1=head;
    while(p1->next!=NULL)
    {
        p2=p1->next;
        while(p2!=NULL)
        {
            if(p1->info > p2->info)
            {
                new=p1->info;
                p1->info=p2->info;
                p2->info=new;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
}

int main()
{
    int choice;
    s *head = NULL;

    do{
        printf("1. To Create Linked List\n");
        printf("2. Display Linked List\n");
        printf("3. Sort The Linked List(Descecnding Order)\n");
        printf("4. Sort The Linked List(Ascending Order)\n");
        printf("\n");
        printf("Enter Choice :");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                head = create();
                break;
            }
            case 2:
            {
                display(head);
                break;
            }
            case 3:
            {
                descsorting(head);
                break;
            }
            case 4:
            {
                ascsorting(head);
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
