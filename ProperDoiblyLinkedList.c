#include <stdio.h>
#include <stdlib.h>

typedef struct DLLNode{
    int info;
    struct DLLNode *prev;
    struct DLLNode *next;
}s;

s *head = NULL; s *tail = NULL;

void insatbeg(int val){
    s *p = (s*)malloc(sizeof(s));
    p->info = val; 
    p->prev = p->next = NULL;
    if (p==NULL)
    printf("Memory Overflow");
    else{
        if (head==NULL){
            head=tail=p;
        }

        else{
            head->prev = p;
            p->next = head;
            head = p;
        }
    }
}

void insatend(int val){
    s *p = (s*)malloc(sizeof(s));
    p->info = val;
    p->prev=p->next=NULL;
    if (p==NULL)
    printf("Memory Overflow");
    else{
        if (head==NULL)
        head=tail=p;
        else{
            tail->next = p;
            p->prev = tail;
            tail = p;
        }
    }
}

void insatanypos(int val, int pos){
    int i=1;
    int l = sizeof(s);
    if (pos<1 || pos>l){
        printf("Invalid Position!!!");
        return;
    }
    else if (pos ==1){
        insatbeg(val);
        return;
    }
    else{
        s *p = (s*)malloc(sizeof(s)), *p1 = head;
        p->info = val;
        p->prev= p->next =NULL;
        while(i<pos-1){
            p1 = p1->next;
            i++;
        }
        p->prev = p1;
        p->next = p1->next;
        p1->next = p;
        p->next->prev=p;
    }
}
// void insafteritem(int val, int item){
//     s *p = (s*)malloc(sizeof(s));
//     s *p1;
//     p->info = val;
//     p->prev = p->next = NULL;
//     if (p==NULL)
//     printf("Memory Overflow");

//     else{
//         if (head==NULL)
//         head = tail = p;
//         else{
//             p1 = head;
//             while(p1->info!=item)
//             p1 = p1->next;    

//             p->prev = p1;
//             p->next = p1->next;
//             p1->next = p;
//             p->next->prev = p;
//         }
//     }
// }

void delfrombeg(){
    s *p1;
    if (head==NULL)
    printf("Underflow!");
    else{
        p1=head;
        head = p1->next;
        p1->next->prev = NULL;
                                                // head = head->next;
                                                // head->prev=NULL;
        free(p1);
    }
}

void delfromend(){
    s *p1;
    if (head==NULL)
    printf("Linked List is empty...!");
    else{
        p1 = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(p1);
    }
}

void delfromanypos(int pos){
     s *p1;
     int i =1, l = sizeof(s);
     if (pos==1)
     delfrombeg();
     else if (pos==l)
     delfromend();
     else{
        p1=head;
        while (i<pos){
            p1=p1->next;
            i++;
        }
        p1->prev->next = p1->next;
        p1->next->prev = p1->prev;
        free(p1);
     }
}

void lengthDLL(){
    int ctr = 0;
    s *p1;
    if (head==NULL)
    printf("Linked List is empty!");
    else{
        p1=head;
        while(p1!=NULL){
            ctr++;
            p1=p1->next;
        }
        printf("Length of Linked List : %d\n", ctr);
    }
}

void search(int item) {
    s *p1;
    int flag =0;
    if (head==NULL)
    printf("Linked List is empty...!");
    else{
        p1=head;
        while(p1!=NULL){
            if (p1->info == item){
                flag =1;
                break;
            }
            p1=p1->next;
        }
        if (flag==1)
        printf("Element found!!\n");
        else
        printf("Sorry! Element not found!!\n");
    }
}

void displayDLL(){
    s *p1= head;
    if (head==NULL)
    printf("Linked List is empty...!");
    else{
        while(p1!=NULL){
            printf("%d-->", p1->info);
            p1=p1->next;
        }
    }
    printf("\n");
}

int main() {
        int choice, n, item, pos;
        do
        {
            printf("1. Insertion at beginning\n");
            printf("2. Insertion at end\n");
            printf("3. Insertion at any Position\n");
            // printf("4. Insertion After an item\n");
            printf("4. Deletion from beginning\n");
            printf("5. Deletion from End\n");
            printf("6. Deletion from any position\n");
            printf("7. Length of Linked List\n");
            printf("8. Searching\n");
            printf("9. Display Doubly Linked List\n");
            printf("\n");
            printf("Enter Your choice ::");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
            {
                printf("Enter the value to insert : ");
                scanf("%d", &n);
                insatbeg(n);
                break;
            }

            case 2:
            {
                printf("Enter the value you want to insert : ");
                scanf("%d", &n);
                insatend(n);
                break;
            }
            case 3:
            {
                printf("Enter the value :");
                scanf("%d", &n);
                printf("Enter the position at which you want to insert :");
                scanf("%d", &pos);
                insatanypos(n, pos);
                break;
            }
            // case 4:
            // {
            //     printf("Enter the value : ");
            //     scanf("%d", &n);
            //     printf("Enter the item after which you want to insert : ");
            //     scanf("%d", &item);
            //     insafteritem(n, item);
            //     break;
            // }
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
                printf("Enter the position from which you want to delete :");
                scanf("%d", &pos);
                delfromanypos(pos);
                break;
            }
            case 7:
            {
                lengthDLL();
                break;
            }
            case 8:
            {
                printf("Enter the element you want to search ::");
                scanf("%d", &item);
                search(item);
                break;
            }
            case 9:
            {
                displayDLL();
                break;
            }
            default:
            {
                printf("Wrong Choice...!!");
                exit(0);
            }
            }
            
        }while(1);

        return 0;
}

