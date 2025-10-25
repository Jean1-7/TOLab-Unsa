#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

const int MAX_ITER = 1000;

class Funcion {
private:
    function<double(double)> f;
public:
    Funcion(function<double(double)> func) : f(func) {}
    friend double evaluar(const Funcion& fun, double x);
};

inline double evaluar(const Funcion& fun, double x) {
    return fun.f(x);
}

class Trapecio {
private:
    double a, b;
    int n;
public:
    Trapecio(double _a, double _b, int _n) : a(_a), b(_b), n(_n) {
        if (_n <= 0)
            throw invalid_argument("El número de subintervalos debe ser positivo.");
        if (_n > MAX_ITER)
            throw overflow_error("Número de subintervalos excede el límite permitido.");
        if (_a >= _b)
            throw invalid_argument("El límite inferior debe ser menor que el superior.");
    }

    double operator()(const Funcion& fun) const {
        double h = (b - a) / n;
        double suma = 0.0;
        for (int i = 1; i < n; ++i)
            suma += evaluar(fun, a + i * h);
        double resultado = (h / 2.0) * (evaluar(fun, a) + 2 * suma + evaluar(fun, b));
        return resultado;
    }

    friend ostream& operator<<(ostream& os, const Trapecio& t) {
        os << "Método del Trapecio: [" << t.a << ", " << t.b << "] con n=" << t.n;
        return os;
    }
};

int main() {
    try {
        Funcion f([](double x) { return sin(x); });
        Trapecio trap(0.0, M_PI, 100);
        cout << trap << endl;
        double resultado = trap(f);
        cout << "Resultado de la integral ≈ " << resultado << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
