#include "deklaracje"
//a
Wektor::Wektor(): x{1}, y{1}, z{1} {};
Wektor::Wektor(double a, double b, double c): x{a}, y{b}, z{c} {};
//b
double Wektor::dl() const{
  return sqrt(x*x+y*y+z*z);
}
//c
Wektor Wektor::operator*(double a) const{
  return Wektor(x*a, y*a, z*a);
}
Wektor operator*(double a, const Wektor &b){
  return Wektor(b.x*a, b.y*a, b.z*a);
}
//d
Wektor Wektor::operator+(const Wektor &a) const{
  return Wektor(x+a.x, y+a.y, z+a.z);
}
//e
double Wektor::skal(const Wektor &a) const{
  return x*a.x+y*a.y+z*a.z;
}
//f
Wektor Wektor::wekt(const Wektor &a) const{
  return Wektor(y*a.z-z*a.y, z*a.x-x*a.z, x*a.y-y*a.x);
}
//g
double Wektor::miesz(const Wektor &a, const Wektor &b) const{
  return this->skal(a.wekt(b));
}
//h
std::ostream& operator<<(std::ostream& ost, const Wektor& obj){
  return ost<<"["<<obj.x<<", "<<obj.y<<", "<<obj.z<<"]";
}

//2
double indukcja(const Wektor &B, const Wektor &S){
  return B.skal(S);
}
//3
Wektor lorentz(double q, const Wektor &E, const Wektor &v, const Wektor &B){
  return (E+v.wekt(B))*q;
}
//4
double amper(double I, const Wektor &dr, const Wektor &dl, const Wektor &B){
  return I*dr.skal(dl.wekt(B));
}