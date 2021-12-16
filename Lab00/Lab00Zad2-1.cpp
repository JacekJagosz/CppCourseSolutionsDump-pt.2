#include <iostream>
#include <cmath>

int main(int argc, char **argv) {
  if(argc!=4){
    std::cout << "Proszę podać 3 całkowite parametry do posortowania" << std::endl;
    std::exit(0);
  }
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  int c = atoi(argv[3]);
  int temp;
  if(a>b){
    temp = a;
    a = b;
    b = temp;
  }
  if(b>c){
    temp = b;
    b = c;
    c = temp;
  }
  if(a>b){
    temp = a;
    a = b;
    b = temp;
  }
  std::cout << "Kolejność po posortowaniu to: " << a << ", " << b <<  ", " << c << std::endl;

}