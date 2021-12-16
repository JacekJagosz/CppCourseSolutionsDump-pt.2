#include "deklaracje"
#include <ctime>

int main(int argc, char **argv) {
  srand (time(NULL));
  Stos<int> a;
  //b
  a.push(1);
  a.push(2);
  a.push(3);
  a.push(4);
  std::cout<<"b: "<<a<<std::endl;
  //c
  a.ifBigger(3);
  std::cout<<"c: "<<a<<std::endl;
  //d
  std::cout<<"d: "<<a.pop()<<" "<<a<<std::endl;
  //e
  std::cout<<"e: "<<a.top()<<" "<<a<<std::endl;
  //f
  a.topD();
  std::cout<<"f: "<<a<<std::endl;
  //g
  std::cout<<"g: "<<a.top()<<" "<<a<<std::endl;
  //h
  a.del();
  std::cout<<"h: "<<a<<std::endl;

  //2a
  int t=13;
  Stos<int> thirteen;
  while(t>0){
    thirteen.push(t%2);
    t/=2;
  }

  std::cout<<"2b: Thirteen in binary is: ";
  while(thirteen.size()){
    std::cout<<thirteen.pop();
  }
  std::cout<<std::endl<<std::endl;
  //2b
  int sum=0;
  for(int i=0; i<100; i++){
    for(int j=0; j<20; j++){
      a.ifBigger(rand()%101);
    }
    sum+=a.size();
    a.del();
  }
  std::cout<<"2b: Average: "<<sum/100.0<<std::endl;
}
