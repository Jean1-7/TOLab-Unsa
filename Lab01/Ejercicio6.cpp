#include <iostream>
using namespace std;

int conv(int horas, int minutos, int segundos) {
    return horas*3600 + minutos*60 + segundos;
}

int main() {
    int h, m, s;
    cout << "Ingrese horas: ";
    cin >> h;
    cout << "Ingrese minutos: ";
    cin >> m;
    cout << "Ingrese segundos: ";
    cin >> s;
    cout << "Equivalente en segundos: " << conv(h, m, s) << endl;
}
