#include <stdint.h>
#include <stdio.h>

#define Size 819000
int sieve (int N) {
  int64_t i, k, prime, count, n; 
  char flags[Size];

  for (n = 0; n < N; n++) {
    count = 0;
    for (i = 0; i < Size; i++)
      flags[i] = 1;
    for (i = 0; i < Size; i++)
      if (flags[i]) {
        prime = i + i + 3;
        for (k = i + prime; k < Size; k += prime)
          flags[k] = 0;
        count++;
      }
  }
  return count;
}
void ex100 (void) {
  printf ("sieve (100) = %d", sieve (100));
}

int main(int argc, char** argv)
{
	ex100();
	return 0;
}
