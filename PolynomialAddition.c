#include <stdio.h>
#include <stdlib.h>

typedef struct polyadd{
    int coefficient;
    int exponent;
    struct polyadd *next;
}p;

p* insert(p* head, int coeff, int expo){
    p *s=(p*)malloc(sizeof(p));
    s->coefficient = coeff;
    s->exponent=expo;
    s->next=NULL;  
    p *p1;

    if (head==NULL || expo > head->exponent){
        s->next = head;
        head = s;
    }
    else{
        p1=head;
        while(p1->next !=NULL && p1->next->exponent > expo)
        p1 = p1->next;
        s->next = p1->next;
        p1->next = s;
    }
    return head;
} 

p* createP(p *head){
    int n;
    int coeff;
    int expo;
    printf("Enter Number of Terms :");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Enter The Coefficient of Term %d ::", i+1);
        scanf("%d", &coeff);
        printf("Enter The Exponent of Term %d ::", i+1);
        scanf("%d", &expo);

        head = insert(head, coeff, expo);
    }
    return head; 
}

void display(p *head){
    if (head==NULL)
    printf("Linked List is empty!!");
    else{
        p *p1= head;
        while(p1!=NULL){
            printf("(%dx^%d)", p1->coefficient, p1->exponent);
            p1=p1->next;
            if(p1!=NULL)
            printf(" + ");
            else
            printf("\n");
        }
    }
} 

void polyaddition(p *head1, p *head2){
    p *p1 = head1;      //firstll
    p *p2 = head2;      //secondll
    p *head3 = NULL;       //resultant

    while(p1 && p2){

        if (p1->exponent == p2->exponent){
            head3 = insert(head3, (p1->coefficient+p2->coefficient), p1->exponent);
            p1=p1->next;
            p2=p2->next; 
        }

        else{
            if (p1->exponent>p2->exponent){
                head3 = insert(head3, p1->coefficient, p1->exponent);
                p1=p1->next;
            }
            else if(p1->exponent<p2->exponent){
                head3 = insert(head3, p2->coefficient, p2->exponent);
                p2=p2->next;
            }
        }
    }

    while(p1!=NULL){
        head3 = insert(head3, p1->coefficient, p1->exponent);
        p1=p1->next;
    }
    while(p2!=NULL){
        head3 = insert(head3, p2->coefficient, p2->exponent);
        p2=p2->next;
    }
    printf("Resultant Polynomial ::::");
    display(head3);
}


int main(){
    p *head1 = NULL;
    p *head2 = NULL;
    printf("Enter First Polynomial->>\n");
    head1 = createP(head1);
    printf("Enter Second Polynomial->>\n");
    head2 = createP(head2);

    polyaddition(head1, head2);
    return 0;
}