#include <iostream>

int bToD(int*, int);

int main(int argc, char **argv) {
  int bin[]={1, 0, 1, 1, 0};
  std::cout<<bToD(bin, sizeof(bin)/sizeof(bin[0]))<<std::endl;
  


}

int bToD(int* bin, int len){
  int dec{};
  for(int i=0; i<len; i++){
    dec*=2;
    dec+=bin[i];
  }
  return dec;
}