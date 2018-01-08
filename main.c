#include <stdio.h>

int sum(int* input, int length) {
  int sum = 0;
  for (int i = 0; i < length; ++i) {
    sum += input[i];
  }
  return sum;
}

int main(void) {
    int tbl[5] = {1,2,3,4,5};
    int len = 5,res;
    
    res = sum(tbl,len);
    printf("Result is : %d\n", res);
return 0;
}
