#include <iostream>
#include <math.h>
#define E 1e-6

int main(int argc, char **argv) {
  if(argc!=4){
    std::cout << "Proszę podać parametry równania kwadratowego a b c" << std::endl;
    std::exit(0);
  }
  double a = atof(argv[1]);
  double b = atof(argv[2]);
  double c = atof(argv[3]);
  double delta = b*b - 4*a*c;
  std::cout << "Delta wynosi: " << delta << std::endl;
  /*
  double param[3];
  for(int i=1; i<argc; i++){
    param[i-1] = std::stof(argv[i]);
    std::cout << param[i-1] << std::endl;
  }
  double delta = param[1]*param[1] - 4*param[0]*param[2];
  */
  if (delta <0){
    std::cout << "Brak rozwiązań równania kwadratowego" << std::endl;
    //std::exit(0);
  }
  else {
    if(std::abs(a) < E){
      std::cout << "Ochrona przed dzieleniem przez 0. Proszę podać a różne od 0" << std::endl;
      std::exit(0);
    }
    if(fabs(delta) < E){
      std::cout << "Rozwiązaniem równania kwatratowego jest: " << -b/(2*a) << std::endl;
    }
    else {
      std::cout << "Rozwiązaniami równania kwatratowego są: " << (-b - sqrt(delta))/(2*a) << " i "<< (-b + sqrt(delta))/(2*a) << std::endl;
  }}
  //std::cout << ;
}