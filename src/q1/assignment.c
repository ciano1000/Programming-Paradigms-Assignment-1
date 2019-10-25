#include <stdio.h>
#define getName(var) #var

int main(int arg, char* argc[]){
  int a = 2;
  int *b = &a;
  long c = 2;
  double dummyDouble = 2.0;
  double *d = &dummyDouble;
  char *dummyChar = "Dummy Char";
  char **e = &dummyChar;

  /**
   * an int is 4 bytes
   * on 32bit systems a pointer will be 4 bytes as well
  */
  printf("Size of variables: \n %d \n %d \n %d \n %d \n %d \n",sizeof(a),sizeof(b),sizeof(c),sizeof(d),sizeof(e));
  return 0;
}
