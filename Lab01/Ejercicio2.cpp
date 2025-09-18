#include <iostream>
using namespace std;

int main() {
    int arr[10];
    for (int i = 0; i < 10; i++) {
        int num;
        while (true) {
            cout << "Ingrese un numero para la posicion " << i+1 << ": ";
            cin >> num;
            if (i == 0 || num > arr[i-1]) {
                arr[i] = num;
                break;
            } else {
                cout << "El nuemero a ingresar debe ser mayor al anterior\n";
            }
        }
    }
    cout << "Array: ";
    for (int i = 0; i < 10; i++) cout << arr[i] << " ";
    cout << endl;
}
