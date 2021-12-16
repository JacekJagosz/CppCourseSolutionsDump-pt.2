#include <iostream>

void bSort(int*, int);
void pSort(int*, int);
void wSort(int*, int);

int main(int argc, char **argv) {
  int tab[]={5,3,4,2,10};
  bSort(tab, sizeof(tab)/sizeof(tab[0]));
  //pSort(tab, sizeof(tab)/sizeof(tab[0]));
  //wSort(tab, sizeof(tab)/sizeof(tab[0]));
  for(int i=0; i<sizeof(tab)/sizeof(tab[0]); i++){
    std::cout<<tab[i]<<", ";
  }
  std::cout<<std::endl;
  }

void bSort(int tab[], int size){
  bool swapped = true;
  //for(int i=0; i<size*size; i++){ //maybe I should check every loop instead
  while(swapped){
    swapped=false;
    for(int j=0; j<size-1; j++){
      if(tab[j+1]<tab[j]){
        std::swap(tab[j+1], tab[j]);
        swapped=true;
      }
    }
  }
}

void pSort(int tab[], int size){
  for(int i=0; i<size-1; i++){
    int min=tab[i], index=i;
    for(int j=i+1; j<size; j++){
      if(tab[j]<min){
        min=tab[j];
        index=j;
      }
    }
    for(int j=index; j>i; j--){
      tab[j]=tab[j-1];
    }
    tab[i]=min;
  }
}

void wSort(int tab[], int size){
  for(int i=0; i<size-1; i++){
    int min=tab[i], index=i;
    for(int j=i+1; j<size; j++){
      if(tab[j]<min){
        min=tab[j];
        index=j;
      }

    }
    std::swap(tab[i], tab[index]);
  }
}