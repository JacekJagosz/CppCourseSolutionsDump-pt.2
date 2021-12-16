#include <iostream>
#include <ctime>
#define N 5
void showSqTab(int**);
//int** newSqTab(int);
void clearSqTab(int** tab);

int main(int argc, char **argv) {
  int** tab=new int*[N];
  for(int i=0;i<N;i++)
	  tab[i]=new int[N]{};
  
  //int** tab = newSqTab[N];
  showSqTab(tab);
  
  //kwadrat
  std::cout<<"kwadrat"<<std::endl;
  
  for(int i=1; i<N-1; i++){
    for(int j=1; j<N-1; j++){
      tab[i][j]=1;
    }
  }
  showSqTab(tab);
  
  //przekatna
  std::cout<<"przekatna"<<std::endl;
  clearSqTab(tab);
  for(int i=0; i<N; i++){
    tab[i][i]=1;
  }
  showSqTab(tab);

  //2 przekatna
  std::cout<<"2 przekatna"<<std::endl;
  clearSqTab(tab);
  for(int i=0; i<N; i++){
    tab[i][N-i-1]=1;
  }
  showSqTab(tab);

  //szachownica
  std::cout<<"szachownica"<<std::endl;
  clearSqTab(tab);
  for(int i=0; i<N; i++){
    for(int j=i%2; j<N; j+=2){
      tab[i][j]=1;
    }
    
  }
  showSqTab(tab);
}

void showSqTab(int** tab){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      std::cout<<tab[i][j];
    }
    std::cout<<std::endl;
  }
  std::cout<<std::endl;
}
void clearSqTab(int** tab){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      tab[i][j]=0;
    }
  }
}
/*
int** newSqTab(int n){
  int** tab=new int*[n];
  for(int i=0;i<n;i++)
	  tab[i]=new int[n]{};
  return tab;
}*/