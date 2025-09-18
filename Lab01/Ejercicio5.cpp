#include <iostream>
using namespace std;

double estacionamiento(int horas) {
    if (horas <= 1) 
        return 3.0;
    double cuenta = 3 + (horas-1)*0.5;
    if(cuenta>12)
        return 12;
    else 
        return cuenta;
}

int main() {
    int horas;
    cout << "Ingrese horas de estacionamiento: ";
    cin >> horas;
    cout << "El cargo es: " << estacionamiento(horas)<< " soles" << endl;
}
