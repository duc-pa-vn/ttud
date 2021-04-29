#include <stdio.h>
int main(){
     int a,b,c=3;
     int *p = &c;
       /* divide c by itself */
      a = c/ *p;
      b = c /* set b to 3 */;
      printf("a=%d, b=%d\n", a,b);
}
