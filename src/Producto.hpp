#include <string>

using namespace std;

#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP
class Producto
{
private:
    string nombre;
    int precio;

public:
    Producto(string nombre, int precio);
    string getNombre();
    int getPrecio();
    bool operator==(Producto &producto);
};

Producto::Producto(string nombre, int precio) : nombre(nombre), precio(precio)
{
}

string Producto::getNombre()
{
    return nombre;
}

int Producto::getPrecio()
{
    return precio;
}

bool Producto::operator==(Producto &producto)
{
    return (nombre == producto.nombre && precio == producto.precio);
}
#endif