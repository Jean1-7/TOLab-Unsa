#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;
public:
    Persona(string nombre, int edad) : nombre(nombre), edad(edad) {}

    string getNombre() const { return nombre; }
    void setNombre(string nombre) { this->nombre = nombre; }

    int getEdad() const { return edad; }
    void setEdad(int edad) { this->edad = edad; }

    virtual string toString() const {
        return "Nombre: " + nombre + ", Edad: " + to_string(edad);
    }
};


class Profesor : public Persona {
public:
    Profesor(string nombre, int edad) : Persona(nombre, edad) {}

    string toString() const override {
        return "Profesor -> " + Persona::toString();
    }
};


class Estudiante : public Persona {
public:
    Estudiante(string nombre, int edad) : Persona(nombre, edad) {}

    string toString() const override {
        return "Estudiante -> " + Persona::toString();
    }
};


class Horario {
private:
    string dia;
    string hora;
public:
    Horario(string dia, string hora) : dia(dia), hora(hora) {}

    string getDia() const { return dia; }
    void setDia(string dia) { this->dia = dia; }

    string getHora() const { return hora; }
    void setHora(string hora) { this->hora = hora; }

    string toString() const {
        return "Horario: " + dia + " a las " + hora;
    }
};


class Curso {
private:
    string nombre;
    Horario horario; 
public:
    Curso(string nombre, Horario horario) : nombre(nombre), horario(horario) {}

    string getNombre() const { return nombre; }
    void setNombre(string nombre) { this->nombre = nombre; }

    Horario getHorario() const { return horario; }
    void setHorario(Horario horario) { this->horario = horario; }

    string toString() const {
        return "Curso: " + nombre + " | " + horario.toString();
    }
};


class Universidad {
private:
    string nombre;
    vector<Curso*> cursos; 
public:
    Universidad(string nombre) : nombre(nombre) {}

    void agregarCurso(Curso* curso) {
        cursos.push_back(curso);
    }

    string toString() const {
        string info = "Universidad: " + nombre + "\nCursos:\n";
        for (auto c : cursos) {
            info += "- " + c->toString() + "\n";
        }
        return info;
    }
};

class Reporte {
public:
    string generar(const Estudiante& est) {
        return "Reporte del estudiante\n------------------\n" +
               string("Nombre: ") + est.getNombre() + "\n" +
               "Edad: " + to_string(est.getEdad());
    }
};


int main() {
    Profesor prof1("Juan Pérez", 45);
    Profesor prof2("María López", 39);

    Estudiante est1("Ana Torres", 20);
    Estudiante est2("Luis Gómez", 22);
    Estudiante est3("Carla Ríos", 19);

    Curso curso1("Programación", Horario("Lunes", "10:00 AM"));
    Curso curso2("Matemáticas", Horario("Martes", "2:00 PM"));

    Universidad uni("Universidad Nacional");
    uni.agregarCurso(&curso1);
    uni.agregarCurso(&curso2);

    cout << prof1.toString() << endl;
    cout << prof2.toString() << endl;
    cout << est1.toString() << endl;
    cout << est2.toString() << endl;
    cout << est3.toString() << endl << endl;

    cout << uni.toString() << endl;

    Reporte reporte;
    cout << reporte.generar(est2) << endl;

    return 0;
}
