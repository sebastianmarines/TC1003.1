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

Persona::Persona()
{
}

Persona::Persona(string nombre, string apellido) : nombre(nombre), apellido(apellido)
{
}

string Persona::getNombre()
{
    return nombre;
}

string Persona::getApellido()
{
    return apellido;
}

void Persona::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Persona::setApellido(string apellido)
{
    this->apellido = apellido;
}

#endif