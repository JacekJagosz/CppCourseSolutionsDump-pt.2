#include <iostream>

int isPrimeDiv(int);
void isPrimeEra(int);
int isPrimeLin(int);

int main(int argc, char **argv) {
  if(argc!=2) {
    std::cout<<"Please pass just one argument"<<std::endl;
    exit(EXIT_FAILURE);
  }
  int a = atoi(argv[1]);
  if(a>0){
    std::cout<<isPrimeDiv(a)<<std::endl<<"Sito Erastotenesa: ";
    isPrimeEra(a);
    std::cout<<isPrimeDiv(a)<<std::endl<<"Sito Liniowe: ";
    isPrimeLin(a);
  }
  else std::cout<<"Not a valid number"<<std::endl;

}
int isPrimeDiv(int a){
  for(int i=2; i*i<=a; i++){
    if(a%i==0) return false;

  }

  return true;
}
void isPrimeEra(int a){
  int* tab = new int [a];
  int* head = tab+1; //pointer to element we will delete multiples of
  for(int i=1; i<=a; i++) tab[i-1]=i; //filling tab with numbers
  //std::cout<<"numbers"<<std::endl;
  for(;head<tab+a; head++){
    int* temp=head;
    //std::cout<<*head<<std::endl;
    for(;!*temp && temp<tab+a; temp++);
    //std::cout<<"temp:"<<*temp<<std::endl;
    if(!*temp) break;
    for(int i=2, h=*temp; h*i<=a; i++){
        tab[h*i-1]=0;
    }
  }
  for(int i=0; i<a; i++) std::cout<<tab[i];
    std::cout<<std::endl;
  delete [] tab;
}
int isPrimeLin(int n){
  int* S = new int [n-1];
  int* head = S+1;
  for(int i=2; i<=n; i++) S[i-2]=i;
  int p=2;
  while(p*p<=n){
    int q=p;
    while(p*q<=n){
      int x=p*q;
      while(x<=n){
        S[x-2]=0;
        x=p*x;
      }
      q++;
      for(;!S[q-2] && q<n; q++);
      //q++;
      }
    p++;
    for(;!S[p-2] && p<n; p++);
    }
  for(int i=0; i<n-1; i++) std::cout<<S[i];
    std::cout<<std::endl;
  delete [] S;
  return 0;
  }