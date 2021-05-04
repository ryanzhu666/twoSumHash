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
} Node;

unsigned int hash(int *key){
    unsigned int hash_value;
    hash_value = *key * *key % TABLE_SIZE;
    return hash_value;
}

void main(){

}