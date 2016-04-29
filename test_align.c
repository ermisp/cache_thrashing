#include <stdio.h>

#define CACHE_LINE_SIZE 64
#define CACHE_L1_SIZE 32768
#define CACHE_L1_LINES (CACHE_L1_SIZE / CACHE_LINE_SIZE)
#define CACHE_L1_ASSOCIATIVITY 8
#define ARRAY_SIZE_TOTAL (CACHE_L1_SIZE * CACHE_L1_ASSOCIATIVITY)
#define ARRAY_SIZE_LINE (ARRAY_SIZE_TOTAL / CACHE_LINE_SIZE)
#define ARRAY_SIZE_COL (CACHE_LINE_SIZE)

#define CACHE_L2_SIZE 3145728
#define CACHE_L2_LINES (CACHE_L1_SIZE / CACHE_LINE_SIZE)
#define CACHE_L2_ASSOCIATIVITY 12
#define ARRAY2_SIZE_TOTAL CACHE_L2_SIZE*CACHE_L2_ASSOCIATIVITY*2
#define ARRAY2_SIZE_LINE ARRAY_SIZE_TOTAL/CACHE_LINE_SIZE
#define ARRAY2_SIZE_COL (CACHE_LINE_SIZE)



char array[ARRAY_SIZE_LINE][ARRAY_SIZE_COL] __attribute__ ((aligned (ARRAY_SIZE_TOTAL))) ;
char array2[1179647][ARRAY2_SIZE_COL] __attribute__ ((aligned (CACHE_L1_SIZE)));
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
void start_line2(void) {
long i;
for (i=0;i<1179647;i++) {
    //printf("Address is : %x-%x\n",&array[i][0],&array[i][63]);
    array2[i][0] = 'a';    
    }
//printf("size is %llu, int i is :%ld\n",ARRAY2_SIZE_LINE, i );
}

void end_line(void) {
for (int i=0;i<CACHE_L1_LINES*CACHE_L1_ASSOCIATIVITY;i++) {
    //printf("Address is : %x-%x\n",&array[i][0],&array[i][63]);
    array[i][63] = 'a';    
    }
}


int main (void) {
int j;
//same_line();
printf ("Calculation %d\n",ARRAY2_SIZE_TOTAL);
printf ("Size is %dx%d\n", ARRAY2_SIZE_LINE, ARRAY2_SIZE_COL);
for (j=0;j<1000;j++) {
	start_line2();
}
printf ("J is %d\n", j);

//diff_line();
//end_line();
//end_line();
return 0;
}
