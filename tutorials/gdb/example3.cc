#include "black_box.h"
#include "fun.h"

int main(){
  int x = 16;

  mystery(x,1);
  if(x % 2){
    fun(x);
  }else{
    funner(x);
  }
}
