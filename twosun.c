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
    int value;
    struct Node *next;
} Node;

typedef struct Htable{
    Node **nodes;
}Htable;

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

void insert(Htable *ht, const int *key, const int *value){
    unsigned int slot = hash(key);
    Node *new = ht->nodes[slot];

    if (new == NULL){
        ht->nodes[slot] = createNode(key,value);
        return;
    }

    Node *prev;

    while (new != NULL){
        if(new->key == *(key)){
            new->value = *(value);
            return;
        }
        prev = new;
        new = prev->next;
    }

    prev->next = createNode(key,value);
}

Node *createNode(int *key, int *value){
    Node *new = malloc(sizeof(Node) *1);
    new->key = *(key);
    new->value = *(value);
    new->next =NULL;

    return new;
}

void main(){
    int p=3;
    printf("%d\n",hash(&p));
    Htable *ht = create();
}