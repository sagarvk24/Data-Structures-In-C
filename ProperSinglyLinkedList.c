#include <stdio.h>
#include <stdlib.h>

typedef struct SLLNODE
{
    int info;
    struct SLLNODE *next;
} s;

s *head = NULL;
void insatbeg(int val)
{
    s *p = (s *)malloc(sizeof(s));
    if (p == NULL)
        printf("Memory Overflow!");
    else
    {
        p->info = val;
        if (head == NULL)
        {
            head = p;
            p->next = NULL;
        }
        else
        {
            // p->next = NULL;
            p->next = head;
            head = p;
        }
    }
}

void insatend(int val)
{
    s *p1;
    s *p = (s *)malloc(sizeof(s));
    p->info = val;
    p->next = NULL;
    if (p == NULL)
        printf("Overflow");
    else
    {
        if (head == NULL)
        {
            head = p;
            return;
        }
        else
        {
            p1 = head;
            while (p1->next != NULL)
            {
                p1 = p1->next;
            }
            p1->next = p;
        }
    }
}

void insertafterpos(int val, int item)
{
    s *p1;
    s *p = (s *)malloc(sizeof(s));
    p->info = val;
    p->next = NULL;
    if (p == NULL)
        printf("Overflow");
    else
    {
        if (head == NULL)
            head = p;
        else
        {
            p1 = head;
            while (p1->info != item)
            {
                p1 = p1->next;
            }
            p->next = p1->next;
            p1->next = p;
        }
    }
}

void insertbeforepos(int val, int item)
{
    s *p1, *p2;
    s *p = (s *)malloc(sizeof(s));
    p->info = val;
    p->next = NULL;

    if (p == NULL)
        printf("Memory overflow!");
    else
    {
        if (head == NULL)
        {
            head = p;
        }
        else
        {
            p1 = head;
            while (p1->info != item)
            {
                p2 = p1;
                p1 = p1->next;
            }
            p2->next = p;
            p->next = p1;
        }
    }
}

void insatanypos(int val, int pos){
    s *p = (s*)malloc(sizeof(s));
    p->info = val;
    p->next = NULL;
    pos--;
    if(p==NULL)
    printf("Overflow");
    else if(head==NULL)
    printf("Linked List is Empty....!\n");
    else{
        s *p1 = head;
        while(pos!=1){
            p1=p1->next;
            pos--;
        }

        p->next = p1->next;
        p1->next = p;
    }
}

void delfrombeg()
{
    if(head==NULL)
    {
        printf("Linked list is empty...!\n");
        return;
    }
    s *p1;
    p1 = head;
    head = head->next;
    free(p1);
}

void delfromend()
{
    if(head==NULL)
    {
        printf("Linked list is empty...!\n");
        return;
    }
    if(head->next == NULL)
    {
        head = NULL;
        return;
    }
    s *p1, *p2 = NULL;
    p1 = head;
    while (p1->next != NULL)
    {
        p2 = p1;
        p1 = p1->next;
    }
    if(p2!=NULL)
    p2->next = NULL;
    free(p1);
}

void delfrompos(int pos){
    s *p1 = head, *p2;
    if (head ==NULL)
    printf("linked List is empty...\n");
    else if(pos==1){
        delfrombeg();
        return;
    }

    else{
        while(pos!=1){
            p2=p1;
            p1=p1->next;
            pos--;
        }
        p2->next = p1->next;
        free(p1);
    }
}

void search(int val)
{
    if(!head)
    {
        printf("Linked list is empty....!\n\n");
        return;
    }

    int flag = 0;
    int index = 0;
    s *p1 = head;
    while(p1)
    {
        if(p1->info == val)
        {
            flag = 1;
            break;
        }
        p1 = p1->next;
        index++;
    }
    if(flag)
    {
        printf("Element found...!\n");
    }
    else
    {
        printf("Element not found....!\n");
    }
}

void lengthofLL(){
    int ctr=0;
    s *p1 = head;
    if(head==NULL)
    {
        printf("Linked list is empty...!\n");
        return;
    }
    else{
        while(p1!=NULL){
            ctr++;
            p1=p1->next;
        }
        printf("length of Linked List : %d\n", ctr);
    }
}

void display()
{
    if (!head)
    {
        printf("Linked List is empty....!");
        return;
    }
    s *p1 = head;
    while (p1 != NULL)
    {
        if(p1->next!=NULL){
            printf("%d-->", p1->info);
            p1 = p1->next;
        }
        else{
            printf("%d", p1->info);
            p1=p1->next;
        }
    }
    printf("\n");
}

int main()
{
    int choice, n, item, target, pos;

    do
    {
        printf("1. Insertion at beginning\n");
        printf("2. Insertion at end\n");
        printf("3. Insertion after element\n");
        printf("4. Insertion before element\n");
        printf("5. Insertion of element at any position\n");
        printf("6. Deletion from beginning\n");
        printf("7. Deletion from end\n");
        printf("8. Deletion from any position\n");
        printf("9. Searching\n");
        printf("10. Length of Linked List\n");
        printf("11. Display Linked List\n");
        printf("\n");
        printf("Enter your choice ::");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter the value to insert :");
            scanf("%d", &n);
            insatbeg(n);
            break;
        }
        case 2:
        {
            printf("Enter the value to insert :");
            scanf("%d", &n);
            insatend(n);
            break;
        }
        case 3:
        {
            printf("Enter the value : ");
            scanf("%d", &n);
            printf("Enter the item after which you want to insert :");
            scanf("%d", &item);
            insertafterpos(n, item);
            break;
        }
        case 4:
        {
            printf("Enter the value :");
            scanf("%d", &n);
            printf("Enter the element before which you want to insert : ");
            scanf("%d", &item);
            insertbeforepos(n, item);
            break;
        }
        case 5:
        {
            printf("Enter the value :");
            scanf("%d", &n);
            printf("Enter at which position you want to insert :");
            scanf("%d", &pos);
            insatanypos(n, pos);
            break;
        }

        case 6:
        {
            delfrombeg();
            break;
        }
        case 7:
        {
            delfromend();
            break;
        }

        case 8:
        {
            printf("Enter the position from which you want to delete :");
            scanf("%d", &pos);
            delfrompos(pos);
            break;
        }
        case 9:
        {
            printf("Enter the item you want to search :");
            scanf("%d", &target);
            search(target);
            break;
        }
        case 10:
        {
            lengthofLL();
            break;
        }
        case 11:
        {
            display();
            break;
        }
        default:
        {
            printf("Wrong choice......!!");
            exit(0);
        }
        }
    } while (1);

    return 0;
}