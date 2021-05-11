/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

typedef struct ListNode{
    int val;
    struct ListNode *next;
} ListNode;

struct ListNode* createNode(int val){
    struct ListNode *new = malloc(sizeof(ListNode) *1);
    new->val = val;
    new->next =NULL;

    return new;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    bool l1_end, l2_end;
    // ListNode test;
    // test.val = 1;
    // test.next=NULL;
    
    ListNode *return_l= malloc(sizeof(struct ListNode)); 
    return_l = createNode(-1);
    // struct ListNode *return_l=&test;
    // struct listNode *current_pos = malloc(sizeof(struct ListNode)); 
    ListNode *current_pos = return_l;
    ListNode *pre_pos = return_l;
    // return_l=&test;
    // return_l->val = 2;
    
    int carry =0;
    
    l1_end = (l1->next ==NULL);
    l2_end = (l2->next ==NULL);
    
    while((!l1_end) | (!l2_end)|(carry!=0)){
        struct ListNode *new = createNode(-1);
        
        int temp_l1=0;
        int temp_l2=0;
        if (!l1_end){
            temp_l1=l1->val;
            l1_end = (l1->next ==NULL);
            l1=l1->next;
        }
        if(!l2_end){
            temp_l2=l2->val;
            l2_end = (l2->next ==NULL);
            l2=l2->next;
        }
        int temp = temp_l1+temp_l2+carry;
        new->val = temp % 10;
        if (current_pos->val==-1){
            return_l=new;
            // current_pos=return_l;
        }
        else{
            current_pos->next=new;
        }
        if (temp>9){
            carry = 1;
        }
        else{carry = 0;}
        current_pos=new;
        // current_pos->next = new;
        
        
 
    }
    // current_pos->next=NULL;
    
    return return_l;
}

void main(){
    int num_a[3]={1,3,5};
    int num_b[3]={2,7,9};

    ListNode *l1,*l2,rl;
    ListNode *new, *pre, *first, *res;
    int size = sizeof(num_a)/sizeof(num_a[0]);
    
    // pre= malloc(sizeof(struct ListNode));
    // *(pre)=NULL; 
    pre= createNode(-1);
    for (int i=0; i < size; i++){
        new= createNode(num_a[i]);
        if(pre->val==-1){
            l1 = new;
            pre=new;
        }
        else{
            pre->next=new;
        }
        pre=new;
    }

    pre= createNode(-1);
    for (int i=0; i < size; i++){
        new= createNode(num_b[i]);
        if(pre->val==-1){
            l2 = new;
            pre=new;
        }
        else{
            pre->next=new;
        }
        pre=new;
    }
    res = addTwoNumbers(l1,l2);
    // for (int i=0; i<size; i++){
    //     printf("node value is %d \n",first->val);
    //     first=first->next;
    // }
    while (res->next!=NULL){
        printf("node value is %d \n",res->val);
        res=res->next;
    }
    // res=res->next;
    printf("node value is %d \n",res->val);
}          