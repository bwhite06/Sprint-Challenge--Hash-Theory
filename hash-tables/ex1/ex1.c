#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);
for(int i; i<length;i++){
for(int y;y<length;y++){
if (weights[i] + weights[y] == limit){
 LinkedPair *current_pair;
 for(int t;t<ht->capacity;t++){
   current_pair = ht->storage[t];
 if(weights[y] == hash_table_retrieve(ht,current_pair->key)){
    Answer*ans;
    ans = hash_table_retrieve(ht,current_pair->key);
    ans -> index_1 = current_pair->value;
   return ans;
 };
 if(weights[i] == hash_table_retrieve(ht,current_pair->key)){
  Answer*ans;
  ans = hash_table_retrieve(ht,current_pair->key);
    ans -> index_2 = current_pair->value;
   return ans;
 };
 }
  

 
 
 
  }else{
    return NULL;
  }
    
  
  
  }
  
}
  //  When calling `hash_table_retrieve` with a key that doesn't exist in the hash table, `hash_table_retrieve` will return -1.
  
  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{

  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1);  // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer* answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2);  // {1, 0}

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer* answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3);  // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4);  // {6, 2}

  return 0;
}
#endif
