#include <limits.h>
#include <stdio.h>

int main()
{
   // char, short, int 
   printf("Char\n");
   printf("Con signo : min %d max %d\n", CHAR_MIN, CHAR_MAX);
   printf("Sin signo : min 0 max %u\n", UCHAR_MAX);
   printf("Short\n");
   printf("Con signo : min %d max %d\n", SHRT_MIN, SHRT_MAX);
   printf("Sin signo : min 0 max %u\n", USHRT_MAX);
   printf("Int\n");
   printf("Con signo : min %d max %d\n", INT_MIN, INT_MAX);
   printf("Sin signo : min 0 max %u\n", UINT_MAX);
}
