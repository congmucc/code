#include <stdio.h>

int main() {
   int array[10];
   int e[5] = {0, 2, 4, 6, 8};
   int odd[5]  = {1, 3, 5, 7, 9};

   int l, i, e_len, o_len;

   e_len = o_len = 5;

   i = 0;

   for(l = 0; l < e_len; l++) {
      array[i] = e[l];
      i++;
   }

   for(l = 0; l < o_len; l++) {
      array[i] = odd[l];
      i++;
   }

   printf("\n数1 -> ");

   for(l = 0; l < e_len; l++)
      printf(" %d", e[l]);
   printf("\n数2-> ");

   for(l = 0; l < o_len; l++)
      printf(" %d", odd[l]);

   printf("\n合并后 -> ");

   for(l = 0; l < 10; l++)
      printf(" %d", array[l]);

   return 0;
}
