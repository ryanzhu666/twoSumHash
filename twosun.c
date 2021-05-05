// COMP9024 assignment 3
// Almersy
// 2021-04-25
// Platform: Windows 10

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#define TABLE_SIZE 1000 

typedef struct Node{
    int key;
    int indexs;
    struct Node *next;
} Node;

typedef struct Htable{
    Node **nodes;
}Htable;

Node *createNode(int *key, int *indexs);

Htable *create(void){
    Htable *hashtable = malloc(sizeof(Htable) * 1);

    hashtable->nodes = malloc(sizeof(Node *) * TABLE_SIZE);

    for(int i=0; i<TABLE_SIZE; i++){
        hashtable->nodes[i]=NULL;
    }

    return hashtable;
}

unsigned int hash(int* key){
    int hash_value;
    // int a = key;
    hash_value = (unsigned int) *(key) * *(key) % TABLE_SIZE;
    return hash_value;
}

void insert(Htable *ht, const int *key, const int *indexs){
    unsigned int slot = hash(key);
    Node *new = ht->nodes[slot];

    if (new == NULL){
        ht->nodes[slot] = createNode(key,indexs);
        return;
    }

    Node *prev;

    while (new != NULL){
        if(new->key == *(key)){
            new->indexs = *(indexs);
            return;
        }
        prev = new;
        new = prev->next;
    }

    prev->next = createNode(key,indexs);
}

Node *createNode(int *key, int *indexs){
    Node *new = malloc(sizeof(Node) *1);
    new->key = *(key);
    new->indexs = *(indexs);
    new->next =NULL;

    return new;
}

int *getIndex(Htable *ht, int *value){
    unsigned int slot = hash(value);
    Node *return_node = ht->nodes[slot];

    if (return_node == NULL){
        return NULL;
    }

    int arraysize=10,i=0;
    int *re_array = malloc(sizeof(int)*arraysize);
    while (return_node->next != NULL){
        if(i<arraysize){
            re_array = realloc(re_array,sizeof(int)*arraysize*2);
            arraysize=arraysize*2;
        }
        re_array[i]=return_node->indexs;
        i++;
        return_node=return_node->next;
    }
    re_array[i]=return_node->indexs;
    i++;

    return re_array;
}

void main(){
    int p=3;
    printf("%d\n",hash(&p));
    Htable *ht = create();
}