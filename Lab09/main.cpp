#include "macierz"
#include <ctime>

int main(int argc, char **argv) {
  srand (time(NULL));
  //a
  std::cout<<"a:"<<std::endl;
  Macierz A(5, 10, true);
  std::cout<<A<<std::endl;
  //b
  std::cout<<"b:"<<std::endl;
  Macierz B(A);
  std::cout<<B<<std::endl;
  //c
  std::cout<<"c:"<<std::endl;
  Macierz C(1, 10, true);
  C=A;
  std::cout<<C<<std::endl;
  //d
  std::cout<<"d:"<<std::endl;
  //f
  std::cout<<"f:"<<std::endl;
  std::cout<<A.iloczyn(C)<<std::endl;
  //g
  std::cout<<"g:"<<std::endl;
  Macierz D(3,10);
  std::cout<<D<<std::endl;
  std::cout<<D.transponuj()<<std::endl;
}