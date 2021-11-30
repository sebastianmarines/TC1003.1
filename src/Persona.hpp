#include <string>

using namespace std;

#ifndef PERSONA_HPP
#define PERSONA_HPP
class Persona
{
private:
    string nombre;
    string apellido;

public:
    Persona();
    Persona(string nombre, string apellido);
    string getNombre();
    string getApellido();
    void setNombre(string nombre);
    void setApellido(string apellido);
};
#endif