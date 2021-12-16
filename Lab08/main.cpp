#include "deklaracje"

int main(int argc, char **argv) {
  Wektor w;

  //b
  std::cout<<w.dl()<<std::endl;

  //c
  std::cout<<(2*w).dl()<<std::endl;
  w=w*2;
  std::cout<<w.dl()<<std::endl;

  //d
  std::cout<<(w+Wektor()).dl()<<std::endl;

  //e
  std::cout<<w.skal(Wektor())<<std::endl;

  //f
  std::cout<<(w.wekt(Wektor())).dl()<<std::endl;

  //g
  Wektor A, B(1,1,-3), C(2,-1,-1);
  std::cout<<A.miesz(B, C)<<std::endl;

  //h
  std::cout<<B<<std::endl;

  //2
  std::cout<<indukcja(A,B)<<std::endl;

  //3
  std::cout<<lorentz(0.5,A,B,C)<<std::endl;

  //4
  std::cout<<amper(0.5, A, B, C)<<std::endl;
}