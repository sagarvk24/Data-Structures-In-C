#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
}s;

s *create()
{
    s *head = NULL,*tail = NULL;
    int n;
    while(true)
    {
        printf("Enter the number (-1 to end): ");
        scanf("%d",&n);
        if(n==-1)
            break;
        
        s *ptr = (s *)malloc(sizeof(s));
        if(!ptr)
        {
            printf("Memory overflow...!\n\n");
        }

        ptr->info = n;
        ptr->next = NULL;

        if(!head)
        {
            head = ptr;
            tail = ptr;
        }
        else
        {
            tail->next = ptr;
            tail = tail->next;
        }
    }
    return head;
}

void display(s *head)
{
    if(!head)
    {
        printf("Linked list is empty...!\n");
        return;
    }

    s *ptr = head;
    printf("\n");
    while(ptr)
    {
        printf("%d ",ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}


s *merge(s *head1, s *head2)
{
    s *head3 = NULL, *tail= NULL;
    if(!head1 && !head2)
    {
        printf("Both the linked list is empty..!\n");
        return NULL;
    }
    else if(!head1)
    {
        return head2;
    }
    else if(!head2)
    {
        return head1;
    }
    else
    {
        int i = 0;
        s *t1 = head1, *t2 = head2;

        //if both the lists are not empty
        // we are merging alternative nodes from both the lists   
        while(t1 && t2)
        {
            if(i % 2 ==0)
            {
                if(head3==NULL)
                {
                    head3 = t1;
                    tail = t1;
                }
                else
                {
                    tail->next = t1;
                    tail = tail->next;
                }
                t1 = t1->next;
            }
            else
            {    
                tail->next = t2;
                tail = tail->next;
                t2 = t2->next;
            }
            i++;
        }   
        //case : if t1 (head1) list is bigger than t2(head2)
        while(t1)
        {
            tail->next = t1;
            tail = tail->next;
            t1 = t1->next;
        } 
        //case : if t2 (head2) list is bigger than t1(head1)

        while(t2)
        {
            tail->next = t2;
            tail = tail->next;
            t2 = t2->next;
        }     
    }
    return head3;
}


int main()
{
    s *head1 = NULL, *head2 = NULL, *head3 = NULL;
    head1 = create();
    display(head1);
    head2 = create();
    display(head2);
    head3 = merge(head1,head2);
    display(head3);
}