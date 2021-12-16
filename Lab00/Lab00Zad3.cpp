#include <iostream>
#include <ctime>
#define SIZE 20

int main(int argc, char **argv) {
  int tab[SIZE];
  srand (time(NULL));
  for(int i=0; i<SIZE; i++){
    tab[i] = rand()%100;
  }
int minimum =100, indeks;
  for(int i=1; i<SIZE; i++){
    if(tab[i]<minimum){
      minimum=tab[i];
      indeks=i;
    }
  
  }
  std::cout<< "Minimum wynosi " << minimum << " i znajduje się na miejscu nr.: " <<indeks << std::endl;
}
