#include <iostream>
using namespace std;

int sumArr(int num[],int n) {
    int suma = 0;
    for(int i = 0; i < n; i++) {
        suma = suma+num[i];
    }
    return suma;
}

int main() {
    int num[] = {1, 2, 3, 4, 5};
    int n = sizeof(num)/sizeof(num[0]);
    cout << "Suma: " << sumArr(num,n) << endl;
    return 0;
}
