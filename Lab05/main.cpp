#include <iostream>
#include <ctime>

//a
template <class T>
void printTab(T* a, int n){
  //int n=sizeof(a)/sizeof(a[0]);
  std::cout<<'['<<a[0];
  for(int i=1; i<n; i++){
    std::cout<<','<<a[i];
  }
  std::cout<<']'<<std::endl;
}
//b
template <class T>
void swapV(T &a, T &b){
  T temp=a;
  a=b;
  b=temp;
}

//c
template <class T>
bool palin(T* a, int n){
  for(int i=0; i<n/2; i++){
    if(a[i]!=a[n-i-1]) return false;
  }
  return true;
}

//d
template <class T>
void revTab1D(T* a, int n){
  for(int i=0; i<n/2; i++){
    swapV(a[i], a[n-1-i]);
  }
}

//e
template <class T>
T inc(T a){
  return a+1;
}

double incD(double a){return a+1;};

template <class T>
void wyw(T* a, int n, T (*fun)(T)){
  for(int i=0; i<n; i++){
    a[i]=fun(a[i]);
  }
}

//6
template <class T>
int filter(T* a, int n, bool (*fun)(T)){
  int z{};
  for(int i=0; i<n; i++){
    if(fun(a[i])){
      a[z]=a[i];
      z++;
    }
  }
  return z;
}

bool cm(double a){
  return a>2;
}

//7
template <class T>
int split(T* a, int n, bool (*fun)(T)){
  int z{};
  T* b=new T [n];
  for(int i=0; i<n; i++){
    if(fun(a[i])){
      a[z]=a[i];
      z++;
    }
    else{
      b[i-z]=a[i];
    }
  }
  for(int i=0; i<n-z; i++){
    a[z+i]=b[i];
  }
  delete [] b;
  return z;
}


int main(int argc, char **argv) {
  srand (time(NULL));
  //1
  //int a[10]{};
  const int n1=10;
  int *tab1 =new int[n1]{};
  printTab(tab1, n1);
  //std::cout<<sizeof(a)<<std::endl;

  //2
  double d1=2.3, d2=3.;
  swapV(d1, d2);
  std::cout<<d1<<" "<<d2<<std::endl;

  //3
  //float tab2[]={1,2,3,4,5};
  double* tabD=new double [n1];
  int* tabI=new int [n1];
  for(int i=0; i<n1; i++){
    tabD[i]=rand()/2.0;
  }
  printTab(tabD, n1);
  revTab1D(tabD, n1);
  printTab(tabD, n1);

  for(int i=0; i<n1; i++){
    tabI[i]=rand();
  }
  printTab(tabI, n1);
  revTab1D(tabI, n1);
  printTab(tabI, n1);


  //4
  char tabZ[]="kajak";
  std::cout<<"Czy jest palindromem? "<<palin(tabZ, sizeof(tabZ)/sizeof(tabZ[0])-1)<<std::endl;

  //5
  double tab3[]={1,2,3,4,2,1};
  wyw(tab3, sizeof(tab3)/sizeof(tab3[0]), incD);
  printTab(tab3, sizeof(tab3)/sizeof(tab3[0]));

  //6
  int w=filter(tab3, sizeof(tab3)/sizeof(tab3[0]), cm);
  for(int i=0; i<w; i++){
    std::cout<<tab3[i];
  }
  std::cout<<std::endl;

  //7
  double tab4[]={1,2,3,4,2,1};
  int s = split(tab4, sizeof(tab4)/sizeof(tab4[0]), cm);
  printTab(tab4, sizeof(tab4)/sizeof(tab4[0]));
  delete [] tab1;
  delete [] tabD;
  delete [] tabI;
}
