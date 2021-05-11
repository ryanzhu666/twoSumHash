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

// typedef struct ListNode{
//     int val;
//     struct ListNode *next;
// } ListNode;

struct ListNode* createNode(int val){
    struct ListNode *new = malloc(sizeof(struct ListNode) *1);
    new->val = val;
    new->next =NULL;

    return new;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    // bool l1_end, l2_end;
    struct ListNode test;
    test.val = 1;
    test.next=NULL;
    
    struct ListNode *return_l= malloc(sizeof(struct ListNode)); 
    // struct ListNode *return_l=&test;
    // struct listNode *current_pos = malloc(sizeof(struct ListNode)); 
    //current_pos = return_l;
    return_l=&test;
    return_l->val = 2;
    
    // int carry =0;
    
    // l1_end = (l1->next ==NULL);
    // l2_end = (l2->next ==NULL);
    
    // while((!l1_end) | (!l2_end)){
    //     struct ListNode *new = (struct ListNode*) malloc(sizeof(struct ListNode));
    //     current_pos->next = new;
    //     if(!l1_end){
    //         if(!l2_end){
    //             int temp = l1->val+l2->val+carry;
    //             current_pos->val = temp % 10;
    //             if (temp>9){
    //                 carry = 1;
    //             }
    //             else{carry = 0;}
    //             l1=l1->next;
    //             l2=l2->next;
    //         }
//             else{
//                 int temp = l1->val+carry;
//                 current_pos->val = temp % 10;
//                 if (temp>9){
//                     carry = 1;
//                 }
//                 else{carry = 0;}
//                 l1=l1->next;
//             }
                
        // }
//         else{
//             if(!l2_end){
//                 int temp = l2->val+carry;
//                 current_pos->val = temp % 10;
//                 if (temp>9){
//                     carry = 1;
//                 }
//                 else{carry = 0;}
//                 l2=l2->next;
//             }
            
//         }
//         l1_end = l1->next ==NULL;
//         l2_end = l2->next ==NULL;
//         current_pos=new;
    // }
    
    return return_l;
}

void main(){
    int num_a[5]={1,3,5,4,1};
    // int num_b[5]={2,7,9,4,1};

    struct ListNode l1,l2,rl;
    struct ListNode *new, *pre, *first;
    int size = sizeof(num_a[0]/sizeof(num_a));
    
    pre= malloc(sizeof(struct ListNode)); 
    for (i=0; i < size; i++){
        new= createNode(num_a[i]);
        if(pre==NULL){
            first = new;
        }
        else{
            pre->next=new;
        }
        pre=new;
    }
    // addTwoNumbers(&l1,&l2);
}          