#include <stdio.h>
#include <stdlib.h>
 
typedef struct CLLNode{
    int info;
    struct CLLNode *next;
}s;

s *head=NULL, *tail= NULL;

void insatbeg(int val){
    s *p=(s*)malloc(sizeof(s));
    p->info=val;
    s *p1;
    if (p==NULL)
    printf("Memory Overflow!!!");
    else{
        if (head==NULL){
            head=p;
            tail=head;
            tail->next=head;
        }
        else{
            tail->next=p;
            p->next=head;
            head=p;
        }
    }
}

void insatend(int val)
{
    s *p=(s*)malloc(sizeof(s));
    
    if(p==NULL)
    printf("Memory Oveflow!!!");
    else{
        p->info=val;
        s *p1;
        if (head==NULL){
            head = p;
            tail=p;
            tail->next=p;
        }
        else{
            p->next=tail->next;
            tail->next=p;
            tail=p;
        }
    }
}

void insatanypos(int val, int pos){
    s *p = (s*)malloc(sizeof(s));
    p->info =val;
    int i =1;
    int l = sizeof(s);
    s *p1;
    if (pos<1 || pos>l)
    printf("Invalid Position!!");
    if (pos==1)
    insatbeg(val);
    else{
        if(p==NULL)
        printf("Memory Overflow!!!");
        else{
            if (head==NULL){
                head=p;
                p->next=p;
            }
            else{
                p1=head;
                while(i<pos-1){
                    p1=p1->next;
                    i++;
                }
                p->next=p1->next;
                p1->next=p;
            }
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

void delfrombeg(){
    if (head==NULL)
    printf("Linked List is Empty!!!!");
    else{
        s *p1=head;
        if(p1->next=p1){            //singlenode
            head=NULL;
            free(p1);
        }
        else{                       
            head=head->next;
            free(p1);
        }
    }
}

void delfromend(){
    if (head==NULL)
    printf("Linked List is Empty!!!!");
    else{
        s *p1=head, *p2;
        if (p1->next=p1){               //singlenode
            head=NULL;
            free(p1);
        }
        else{
            while(p1->next!=head){
                p2=p1;
                p1=p1->next;
            }
            p2->next=p1->next;
            free(p1);
        }
    }
}

void delfromanypos(int pos){
    int i=1;
    int l = sizeof(s);
    if(pos<1 || pos>l)
    printf("Invalid Position!!!");
    if (pos==1)
    delfrombeg();
    else{
        if (head==NULL)
        printf("Linked List Is Empty!!");
        else{
            s *p1=head, *p2;
            while(i<=pos){
                p2=p1;
                p1=p1->next;
                i++;
            }
            p2->next = p1->next;
            free(p1);
        }
    }
}

void LengthofCLL(){
    int ctr=0;
    if (head==NULL)
    printf("Linked List is Empty!!!!");
    else
    {
        s *p1=head->next;
        ctr++;
        while(p1!=head){
            ctr++;
            p1=p1->next;
        }
        printf("Length of Circular Linked List : %d", ctr);
    }
}
 
void search(int item){
    
    if(!head)
    {
        printf("List is emptyy...!\n\n");
        return;
    }
    
    int flag =0;
    s *p1=head;
    if(p1->info == item)
    {
        flag = 1;
        goto l1;
    }
    p1 = p1->next;
    while(p1!=head){
        if (p1->info==item){
            flag=1;
            break;
        }
        p1=p1->next;
    }
    l1:
    if(flag==1)
    printf("Item Found!!!");
    else
    printf("Sorry, Item Not Found!!!!");
}

void reverse() {
    s *p1, *p2, *p3;
    p2 = NULL;
    p1=p3=head;
    while(p3!=head){
        p3=p3->next;
        p1->next=p2;
        p2=p1;
        p1=p3;
    }
    head = p2;
}

void display(){
    s *p1=head;
    if (head==NULL)
    printf("List empty....!!!!");
    else{
        if (p1->next!=head)
            printf("%d-->", p1->info);
        else
            printf("%d", p1->info);
        p1=p1->next;
        while(p1!=head){
            if (p1->next!=head)
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
        printf("4. Insertion Before Any Element\n");
        printf("5. Insertion After An Element\n");
        printf("6. Deletion From Beginning\n");
        printf("7. Deletion From End\n");
        printf("8. Deletion From Any Position\n");
        printf("9. Length of Circular Linked List\n");
        printf("10. Searching\n");
        printf("11. Reverse\n");
        printf("12. Display\n");
        printf("\n");
        printf("Enter Choice :: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter The Value : ");
            scanf("%d", &val);
            insatbeg(val);
            break;
        }
        case 2:
        {
            printf("Enter The Value : ");
            scanf("%d", &val);
            insatend(val);
            break;
        }
        case 3:
        {
            printf("Enter The Value :");
            scanf("%d", &val);
            printf("Enter The Position At Which You Want To Insert : ");
            scanf("%d", &pos);
            insatanypos(val, pos);
            break;
        }
        case 4:
        {
            printf("Enter The Value :");
            scanf("%d", &val);
            printf("Enter The Item Before Which You Want To Insert : ");
            scanf("%d", &item);
            insertbeforepos(val, item);
            break;
        }      
        case 5:
        {
            printf("Enter The Value :");
            scanf("%d", &val);
            printf("Enter The Item After Which You Want To Insert : ");
            scanf("%d", &item);
            insertafterpos(val, item);
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
            printf("Enter The Position From Which You Want To Delete : ");
            scanf("%d", &pos);
            delfromanypos(pos);
            break;
        }
        case 10:
        {
            printf("Enter The Element You Want To Search :");
            scanf("%d", &item);
            search(item);
            break;
        }
        case 9:
        {
            LengthofCLL();
            break;
        }
        case 11:
        {
            reverse();
            break;
        }
        case 12:
        {
            display();
            break;
        }
        default:
        {
            printf("Sorry, Wrong Choice..!!");
            exit(0);
        }
        }
    }while(1);

    return 0;
}
