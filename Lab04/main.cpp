#include <iostream>
#include <ctime>
#include <cmath>
#define SIZE 10
#define E 1e-2
void fillTab(double **, int, double(*)(double), bool);
void fillTab(double **, int, double(*)(double));
double columnAverage(double**, int, int);
double function(double);
bool checkNaive(double*, int, double);

struct reg{
  double a{};
  double b{};
  double da{};
  double db{};
};

reg calculateReg(double**, int);

int main(int argc, char **argv) {
  srand (time(NULL));
  double **Nx2 = new double* [SIZE]; 
  for(int i=0; i<SIZE; i++){
    Nx2[i]=new double[2];
  }
  double* hun=new double[100];
  for(int i=0; i<SIZE; i++){
    hun[i]=double(rand())/RAND_MAX*100;
  
  }
  fillTab(Nx2, SIZE, function, true);
  std::cout<<"Średnia kolumny 0: "<<columnAverage(Nx2, SIZE, 0)<<" Średnia kolumny 1: "<<columnAverage(Nx2, SIZE,1)<<std::endl;
  
  reg coef = calculateReg(Nx2, SIZE);
  std::cout<<"a="<<coef.a<<", b="<<coef.b<<" , da="<<coef.da<<" , db="<<coef.db<<std::endl;

  checkNaive(hun, 100, hun[8]);


  for(int i=0; i<SIZE; i++){
    delete[] Nx2[i];
  }
  delete[] Nx2;
  delete[] hun;
}

void fillTab(double** tab, int n, double(*func)(double)){
  for(int i=0; i<n; i++){
    tab[i][0]=i+1;
    tab[i][1]=func(i+1);
  }
}

void fillTab(double** tab, int n, double(*func)(double), bool noise){
  if(noise){
  for(int i=0; i<n; i++){
    tab[i][0]=i+1;
    tab[i][1]=func(i+1)+(double)rand()/RAND_MAX-0.5;
  }
  }
  else{
    for(int i=0; i<n; i++){
      tab[i][0]=i+1;
      tab[i][1]=func(i+1);
    }
  }
}
double columnAverage(double** tab, int n, int c){
  double sum=0;
  for(int i=0; i<n; i++){
     sum+=tab[i][c];
  }
  return sum/n;
}

reg calculateReg(double** tab, int n){
  reg a;
  double xAvg=columnAverage(tab, n, 0), yAvg=columnAverage(tab, n, 1), D{}, dy{};
  //D
  for(int i=0; i<n; i++){
    D+=(tab[i][0]-xAvg)*(tab[i][0]-xAvg);
  }
  //a
  for(int i=0; i<n; i++){
    a.a+=(tab[i][0]-xAvg)*tab[i][1];
  }
  a.a/=D;
  //b
  a.b=yAvg-a.a*xAvg;
  //dy
  for(int i=0; i<n; i++){
    dy+=(tab[i][1]-a.a*tab[i][0]-a.b)*(tab[i][1]-a.a*tab[i][0]-a.b);
  }
  dy=dy/(n-2);
  dy=sqrt(dy);
  //da
  a.da=dy/sqrt(D);
  //db
  a.db=dy*sqrt(1./n+xAvg*xAvg/D);
  return a;
}

bool checkNaive(double* tab, int n, double a){
  int p{};
  bool result=false;
  for(;p<n; p++){
    if((tab[p]>=a-E) && (tab[p]<=a+E)){
      result=true;
      break;
    }
  }
  std::cout<<"Liczba pętli metodą naiwną: "<<++p<<std::endl;
  return result;
}

double function(double a){

  return 0;
}