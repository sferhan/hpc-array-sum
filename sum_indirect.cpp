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

   bool* indices_produced = (bool*)malloc(sizeof(bool)*N);

   for(int64_t i = 0; i<N; i++) {
      indices_produced[i] = false;
   }

   for(int64_t i=0; i<N; i++) {
      int64_t random_index = -1;
      
      while(random_index == -1) {
         
         int64_t prospective_random_index = lrand48() % N;
         
         if(indices_produced[prospective_random_index] == false) {
            indices_produced[prospective_random_index] = true;
            random_index = prospective_random_index;
         }
      }

      A[i] = random_index;
   }
}

int64_t
sum(int64_t N, uint64_t A[])
{
   printf(" inside sum_indirect perform_sum, N=%lld \n", N);

   int64_t sum = 0;

   for(int i=0; i<N; i++) {
      int64_t random_index = A[i];
      sum += A[random_index];
   }

   return sum;
}

