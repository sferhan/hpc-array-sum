#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>
#include <cstdlib>


void 
setup(int64_t N, uint64_t A[])
{
   printf(" inside sum_indirect problem_setup, N=%lld \n", N);
   for(int i=0; i<N; i++) {
      A[i] = lrand48();
   }
}

int64_t* generate_random_arr_indices(const int64_t arr_size) {
   int64_t* indices = (int64_t*)malloc(sizeof(int64_t)*arr_size);

   for(int64_t i = 0; i<arr_size; i++) {
      indices[i] = NULL;
   }

   int64_t i = 0;
   while(i < arr_size) {
      int64_t random_index = lrand48() % arr_size;
      if(indices[random_index] == NULL) {
         indices[i] = random_index;
         i += 1;
      }
   }

   return indices;
}

int64_t
sum(int64_t N, uint64_t A[])
{
   printf(" inside sum_indirect perform_sum, N=%lld \n", N);
   
   int64_t* random_indices = generate_random_arr_indices(N);

   int64_t sum = 0;

   for(int i=0; i<N; i++) {
      sum += A[random_indices[i]];
   }

   return sum;
}

