#include "math.h"

int L1_Iterations(int N)
{
  int max = 0, temp_result = 0;
  int n = N;
  
  // Binary representation
  for (int i = 31; i >= 0; --i) {
    printf("%d", (n >> i) & 1);
  }
  printf("\n");

  // msb
  n |= (n >>  1);
  n |= (n >>  2);
  n |= (n >>  4);
  n |= (n >>  8);
  n |= (n >> 16);
  n = n - (n >> 1);
  printf("Most significant bit: %d\n", n);

  while(n >>= 1) {
    if (N & n) {
      if (temp_result > max)
        max = temp_result;
        temp_result = 0;
    } else {
      ++temp_result;
    }
  }

  return max;
}
