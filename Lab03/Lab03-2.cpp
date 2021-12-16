#include <iostream>
struct Bin{
  int len;
  int val[50]={};
};
Bin dNaB(int);

int main(int argc, char **argv) {
  int a=22;//value to be converted to binary
  Bin b=dNaB(a);
  std::cout<<"Liczba "<<a<<" w systemie binarnym to: ";
  for(int i=b.len-1; i>=0; i--)
  std::cout<<b.val[i];
  std::cout<<std::endl;
}

Bin dNaB(int a){
  int i=0;
  Bin b;
  for(; a; i++){
    b.val[i]=a%2;
    //std::cout<<b.val[i];
    a/=2;
  }
  //std::cout<<std::endl;
  b.len=i;
  return b;
}