#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int frecuencia[6] = {0};
    srand(time(0));

    for (int i = 0; i < 20000; i++) {
        int cara = rand() % 6; 
        frecuencia[cara]++;
    }

    cout << "Frecuencias de las 6 caras del dado:\n";
    for (int i = 0; i < 6; i++) 
        cout << "Cara " << (i+1) << " salio " << frecuencia[i] << "veces" << endl;
}
