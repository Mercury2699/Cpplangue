#include "black_box.h"

void crash(int *i){
  *i = 1;
}

void f(int *i){
  int *j = i;
  j = sophisticated(j);
  j = complicated(j);
  crash(j);
}

int main(){
  int i;
  f(&i);
}
