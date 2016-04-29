#include <stdio.h>

#define CACHE_LINE_SIZE 64
#define CACHE_L1_SIZE 32768
#define CACHE_L1_LINES (CACHE_L1_SIZE / CACHE_LINE_SIZE)
#define CACHE_L1_ASSOCIATIVITY 8
#define ARRAY_SIZE_TOTAL (CACHE_L1_SIZE * CACHE_L1_ASSOCIATIVITY)
#define ARRAY_SIZE_LINE (ARRAY_SIZE_TOTAL / CACHE_LINE_SIZE)
#define ARRAY_SIZE_COL (CACHE_LINE_SIZE)


char array[ARRAY_SIZE_LINE][ARRAY_SIZE_COL] __attribute__ ((aligned (ARRAY_SIZE_TOTAL))) ;
char a;
//void same_line(void) {
//for (int i=0;i<CACHE_L1_LINES;i++) {
//    //printf("Address is : %x\n",&array[0][i]);
//    a = array[0][i];    
//    }
//}
void diff_line(void) {
for (int i=0;i<CACHE_L1_LINES*CACHE_L1_ASSOCIATIVITY;i++) {
    //printf("Address is : %x\n",&array[i][0]);
    array[i][0] = 'a';    
    }
}
void start_line(void) {
for (int i=0;i<CACHE_L1_LINES*CACHE_L1_ASSOCIATIVITY;i++) {
    //printf("Address is : %x-%x\n",&array[i][0],&array[i][63]);
    array[i][0] = 'a';    
    }
}

void end_line(void) {
for (int i=0;i<CACHE_L1_LINES*CACHE_L1_ASSOCIATIVITY;i++) {
    //printf("Address is : %x-%x\n",&array[i][0],&array[i][63]);
    array[i][63] = 'a';    
    }
}


int main (void) {
//same_line();
start_line();
diff_line();
end_line();
end_line();
return 0;
}
