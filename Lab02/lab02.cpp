#include <iostream>
#include <vector>
using namespace std;

void imprimirCombinaciones(int cantidad, const vector<int>& monedas, int pos, vector<int>& actual) {
    if (cantidad == 0) {
        for (int i = 0; i < actual.size(); i++) {
            if (i > 0) cout << "+";
            cout << actual[i];
        }
        cout << endl;
        return;
    }
    if (cantidad < 0 || pos >= monedas.size()) return;

    actual.push_back(monedas[pos]);
    imprimirCombinaciones(cantidad - monedas[pos], monedas, pos, actual);
    actual.pop_back();

    imprimirCombinaciones(cantidad, monedas, pos + 1, actual);
}

int formasCambio(int cantidad, const vector<int>& monedas, int pos = 0) {
    if (cantidad == 0) return 1;
    if (cantidad < 0 || pos >= monedas.size()) return 0;
    return formasCambio(cantidad - monedas[pos], monedas, pos) 
         + formasCambio(cantidad, monedas, pos + 1);
}

int main() {
    int cantidad = 4;
    vector<int> monedas = {1, 2, 3};

    cout << "Formas posibles de dar cambio:" << endl;
    vector<int> actual;
    imprimirCombinaciones(cantidad, monedas, 0, actual);

    cout << "Numero total de formas: " 
         << formasCambio(cantidad, monedas) << endl;

    return 0;
}
