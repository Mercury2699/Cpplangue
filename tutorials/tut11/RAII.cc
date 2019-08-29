#include <new>

// Code Segment 1
try{
  int *arr1 = new int[10];
  int *arr2 = new int[20];
}catch(std::bad_alloc){
  // Can you make sure there is no
  // memory leak when the exception
  // is caught? Why not?
}

// Ugly "Fix" to code segment 1
try{
  int *arr1 = new int[10];
  int *arr2 = nullptr;
  try{
    arr2 = new int[20];
  }catch(std::bad_alloc &e){
    delete [] arr1;
    throw e;
  }
}catch(std::bad_alloc &e){ ... }

// With RAII
struct Wrapper{
  int *arr1 = nullptr;
  int *arr2 = nullptr;

  Wrapper(){
    arr1 = new int[10];
    arr2 = new int[20];
  }

  ~Wrapper(){
    delete [] arr1;
    delete [] arr2;
  }
};

try{
  Wrapper w;
  ...
} // Memory taken from Wrapper freed here
catch(std::bad_alloc &e){
  ...
}
