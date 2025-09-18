#include <iostream>
#include <algorithm>
using namespace std;

double menor(double a, double b, double c) {
    if(a<b && a<c)
        return a;
    if(b<a && b<c)
        return b;
    else
        return c;
}

int main() {
    double x, y, z;
    cout << "Ingrese tres numeros decimales: ";
    cin >> x >> y >> z;
    cout << "El menor es: " << menor(x, y, z) << endl;
}
