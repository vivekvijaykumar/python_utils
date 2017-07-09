#include <stdio.h>
#include <stdlib.h>
struct node;

struct node {
    int val;
    struct node *next;
};


struct node *addlist(struct node *n1, struct node *n2, int *carry)
{
    if(n1 == NULL && n2 == NULL)
        return NULL;
    /*
     * check for the last node at this point and add them and set the
     * carry over 
     */
    struct node *n = addlist(n1->next, n2->next, carry);
    if(!n) {
        int temp = n1->val + n2->val;
        n = malloc(sizeof(struct node) * 1);
        *carry = temp/10;
        n->val = temp%10;
        n->next = NULL;
        printf("[%d+%d] Val:%d carry:%d \n",n1->val, n2->val, n->val, *carry);
        return n;
    } 

    /*
     * For all the nodes other than the last node we 
     * keep creating the new list and chain them in 
     * the same reverse order and set the carry.
     * when we reach the head of the 2 lists the carry
     * is still set and we will create a node for the 
     * carry in the driver util and finish up the list.
     */
    struct node *new = malloc(sizeof(struct node) *1);
    new->next = n;
    int temp = n1->val + n2->val + *carry;
    *carry = temp/10;
    new->val = temp%10;
    printf("[%d+%d] Val:%d carry:%d \n",n1->val, n2->val, new->val, *carry);
    return new;
}

int main()
{
    struct node n1,n2,n3;
    struct node n4,n5,n6;
    n1.val = 7; n1.next = &n2;
    n2.val = 1; n2.next = &n3;
    n3.val = 6; n3.next = NULL;

    n4.val = 5; n4.next = &n5;
    n5.val = 9; n5.next = &n6;
    n6.val = 2; n6.next = NULL;
   
    int carry = 0;
    struct node *head;
    struct node *n = addlist(&n1,&n4,&carry);
    if(carry) {
        head = malloc(sizeof(struct node));
        head->val = carry;
        head->next = n;
    } else {
        head = n;
    }
    while(head) {
        printf("%d ",head->val);
        head = head->next;
    }
    printf("\n");
    return 0;
}
