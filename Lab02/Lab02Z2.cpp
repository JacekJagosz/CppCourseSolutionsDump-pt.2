#include <iostream>
#define steps 1000

double f(double t){
  return t;
}
int main(int argc, char **argv) {
  if(argc!=3) {
    std::cout<<"Please pass just two argument"<<std::endl;
    exit(EXIT_FAILURE);
  }
  double a = atof(argv[1]), b = atof(argv[2]);
  double dx=(b-a)/steps;
  double suma=dx*(f(a)+f(b))/2;
  for(int i=1; i<steps-1; i++){
    suma+=dx*f(a+i*dx);
  }
  std::cout<<"Suma: "<<suma<<std::endl;
}