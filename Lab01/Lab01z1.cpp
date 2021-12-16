#include <iostream>
#include <ctime>
#include <cmath>
#define N 1e2 //uzywam 1e2 do testow
#define zakres 10000

int main(int argc, char **argv) {
  std::srand (time(NULL));
  int* tab=new int[N]{};

  //zapelnianie tabeli losowymi liczbami
  for(int i=0; i<N; i++){
    tab[i]=rand()%zakres;
  }

  //wypisywanie sumy cyfr kolejnych liczb
  for(int i=0; i<N; i++){
    int sumaC = tab[i]/1000 + (tab[i]/100)%10 + (tab[i]/10)%10 + tab[i]%10;
    std::cout<<tab[i]<<" - "<<sumaC<<std::endl;
  }

  //sprawdzanie ile jest 1, 2, itd. -cyfrowych liczb
  int dlZakr=0;
  for(int i=zakres; i; i/=10, dlZakr++);
  std::cout<<dlZakr<<std::endl;
  //int cyfr[dlZakr-1]={};
  int cyfr[100]={};
  for(int i=0; i<N; i++){
    int a = tab[i];
    for(int i=dlZakr-1; i; i--){
      if(a/pow(10, dlZakr)){ //tutaj konwertuje na double a potem z powrotem na int, nie mialem lepszego pomyslu
        cyfr[i-1]++;
        break;
      }
    }
  }
for(int i=0; i<=dlZakr-2; i++){
  std::cout<<cyfr[i]<<std::endl;
}
  int jedno=0, dwu=0, trzy=0, cztero=0;
  for(int i=0; i<N; i++){
    int a = tab[i];
    if(a/1000)
      cztero++;
    else if(a/100)
      trzy++;
    else if(a/10)
      dwu++;
    else if(a)
      jedno++;
  }
  std::cout<<"Jednocyfrowe: "<<jedno<<std::endl;
  std::cout<<"Dwucyfrowe: "<<dwu<<std::endl;
  std::cout<<"Trzycyfrowe: "<<trzy<<std::endl;
  std::cout<<"Czerocyfrowe: "<<cztero<<std::endl;

  //std::cout<<tab[1]<<std::endl;
  delete [] tab;

}
