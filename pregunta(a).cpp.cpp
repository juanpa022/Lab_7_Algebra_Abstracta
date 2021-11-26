#include <iostream>
#include<math.h>
using namespace std;
long long  EuclidesGeneral( long long  a,  long long  b,  long long  & x,  long long  & y);
long long  inversoM( long long int a,  long long int m);
long long int Gcd( long long int a,  long long int b);
void KEYGENERATOR( long long int a,  long long int b,  long long int & x,  long long int& y,  long long int& z);
long long int modular(unsigned long long int a, unsigned long long int exp, unsigned long long int mod);

int main(){

    cout<<"a)\n " ;
    long long int a = 65537, b = 999630013489, c = 747120213790, mensaje,x,y,tem,d;
    for (long long i = 2; i < b; i++) {
        if (!(b % i)) {
            x= i; y= b / x;
            break;
        }
    }
    tem= (x - 1) * (y - 1);
    d = inversoM(a,tem);
    mensaje = modular(c, d, b);
    cout << "El mensaje es: " << mensaje;
    c = modular(mensaje, a, b);
    cout << "\nEl encriptado es: " << c; 
    return 0;
}

 long long  EuclidesGeneral( long long  a,  long long  b,  long long  & x,  long long  & y)
{
    if (a == 0)
    {
        x = 0, y = 1;
        return b;
    }
     long long  x1, y1;
     long long  gcd = EuclidesGeneral(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

 long long  inversoM( long long int a,  long long int m) {
     long long  x = 0, y = 0;
     long long  g = EuclidesGeneral(a, m, x, y);
    if (g != 1)
        return -1;
    else {
         long long int res = (x % m + m) % m;
        return res;
    }
}

 long long int Gcd( long long int a,  long long int b) {
     long long int t;
    while (true) {
        t = a % b;
        if (t == 0)
            return b;
        a = b;
        b = t;
    }
}

void KEYGENERATOR( long long int a,  long long int b,  long long int & x,  long long int& y,  long long int& z) {
    x = a * b;
     long long int phi = (a - 1) * (b - 1);
     long long int pista = 0;
    while (y < phi) { 
        pista = Gcd(y, phi);
        if (pista == 1) {
            z = inversoM(y, phi);
            break;
        }
        else
            y++;
    }}
long long int modular(unsigned long long int a, unsigned long long int exp, unsigned long long int mod)
{
    long long int x = 1;
    int i;
    long long int power = a % mod;

    for (i = 0; i < sizeof(int) * 64; i++) {
        int least_sig_bit = 0x00000001 & (exp >> i);
        if (least_sig_bit)
            x = (x * power) % mod;
        power = (power * power) % mod;
    }

    return x;
}

