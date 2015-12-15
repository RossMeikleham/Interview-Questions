#include "seperate_chaining.h"
#include "linear_probing.h"

#include <stdio.h>

#define TABLE_SIZE 1

//Uses a variation of Knuths Multiplicative Method
int hash_func(int key, int size) {
   return key * 2654435761 % size;
}

void seperate_chaining_tests() {
   Chain_HTable *t = create_chtable(TABLE_SIZE, hash_func);
   int vals[] = {345, 465, 4384932, 44324324, 432784};
   int keys[] = {323, 324, 546546, 43242, 432432};
   
   for (unsigned i = 0; i < sizeof(vals)/sizeof(int); i++) {
       if (!insert_chtable(t, keys[i], &vals[i])) {
            printf("failed to insert key:%d, val:%d pos:%d\n", keys[i],vals[i],
                        hash_func(keys[i], TABLE_SIZE));
       }
   }
   
  print_chtable_int(t);

  int *a;
  remove_chtable(t, keys[2], (void **)&a);

  printf("%d\n", *a);
  print_chtable_int(t);
   

  delete_chtable(t);  
  
  t = NULL; 
  print_chtable_int(t);  
   
  
  t = create_chtable(1024, hash_func);
  for (unsigned i = 0; i < sizeof(vals)/sizeof(int); i++) {
       if (!insert_chtable(t, keys[i], &vals[i])) {
            printf("failed to insert key:%d, val:%d pos:%d\n", keys[i],vals[i],
                        hash_func(keys[i], 1024));
       }
   }
   
  print_chtable_int(t);  
    
  int *v;
  int i = find_chtable(t, keys[0], (void **)&v); 
  printf("%d\n", *v);
  i = find_chtable(t, keys[2], (void **)&v); 
  printf("%d\n", *v);



}


void linear_probing_tests() {
   Probe_HTable *t = create_phtable(1024, hash_func);
  
   int vals[] = {345, 465, 4384932, 44324324, 432784};
   int keys[] = {323, 324, 546546, 43242, 432432};
   for (unsigned i = 0; i < sizeof(vals)/sizeof(int); i++) {
       if (!insert_phtable(t, keys[i], &vals[i])) {
            printf("failed to insert key:%d, val:%d pos:%d\n", keys[i],vals[i],
                        hash_func(keys[i], TABLE_SIZE));
       }
   }
   
  print_phtable_int(t);

  int *a;
  remove_phtable(t, keys[2], (void **)&a);

  printf("%d\n", *a);
  print_phtable_int(t);
   

  delete_phtable(t);  
  
  t = NULL; 
  print_phtable_int(t);  
    
}

int main(int argc, char *argv[]) {
    printf("------ Seperate Chaining -----\n");
    seperate_chaining_tests();
    printf("------ Linear Probing ------\n");   
    linear_probing_tests();
}
