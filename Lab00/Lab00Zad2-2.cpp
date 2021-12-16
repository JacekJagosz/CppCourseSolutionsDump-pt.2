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
    a-=b;
    b+=a;
    a = b - a;
  }
  if(b>c){
    b-=c;
    c+=b;
    b = c - b;
  }
  if(a>b){
    a-=b;
    b+=a;
    a = b - a;
  }
  std::cout << "Kolejność po posortowaniu to: " << a << ", " << b <<  ", " << c << std::endl;

}