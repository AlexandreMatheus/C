#include <stdio.h>
int main(){  
  unsigned long long int n=0,a=0;
  int v=0;
  for(n=1;n>=0 && v!=64;n=n+n){
   v++;
   a+=n;
   printf("%i Quad. tem %llu graos\n",v,a);
  }
  return 0;
}
