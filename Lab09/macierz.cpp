#include "macierz"

//a
Macierz::Macierz(int a, int zakr, bool sym):n{a} {
  tab = new int*[n];
  for(int i=0; i<n; i++){
    tab[i]=new int[n];
  }
  if(sym){
    for(int i=0; i<n; i++){
      for(int j=0; j<=i; j++){
        tab[j][i]=tab[i][j]=rand()%zakr;
      }
    }
  }
  else{
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        tab[i][j]=rand()%zakr;
      }
    }
  }

}

//b
Macierz::Macierz(const Macierz& a): n{a.n} {
  tab = new int*[n];
  for(int i=0; i<n; i++){
    tab[i]=new int[n];
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      tab[i][j]=a.tab[i][j];
    }
  }
}

//c
Macierz& Macierz::operator=(const Macierz& a){
  if(this!=&a){
    for(int i=0; i<n; i++){
      delete [] tab[i];
    }
    delete [] tab;
    n=a.n;
    tab = new int*[n];
    for(int i=0; i<n; i++){
      tab[i]=new int[n];
    }
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        tab[i][j]=a.tab[i][j];
      }
    }
  }
  return *this;
}
//e
Macierz::~Macierz(){
  for(int i=0; i<n; i++){
    delete [] tab[i];
  }
  delete [] tab;
}

//f
Macierz Macierz::iloczyn(const Macierz& a){
  if(n!=a.n){
    std::cout<<"Wielkosci macierzy nie sa rowne"<<std::endl;
    return Macierz(1, 1);
  }
  Macierz b(n, 1, true);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      int suma{0};
      for(int k=0; k<n; k++){
        suma+=tab[i][k]*a.tab[k][j];
      }
      b.tab[i][j]=suma;
    }
  }
  return b;
}

//g
Macierz& Macierz::transponuj(){
for(int i=0; i<n; i++){
  for(int j=0; j<=i; j++){
    std::swap(tab[i][j], tab[j][i]);
  }
}
return *this;
}
//i
std::ostream& operator<<(std::ostream& ost, const Macierz& obj){
  for(int i=0; i<obj.n; i++){
    ost<<"[";
    for(int j=0; j<obj.n; j++){
      ost<<obj.tab[i][j];
      ost<<", ";
    }
    ost<<"]\n";
  }
  return ost;
  //return ost<<"["<<obj.tab[0][0]<<", "<<obj.tab[0][1]<<", "<<obj.tab[0][2]<<"]";
}
