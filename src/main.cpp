#include <iostream>
#include <iomanip>
#include "Persona.hpp"
#include "Tienda.hpp"
#include "Producto.hpp"

using namespace std;

int menu();

int main()
{
    while (true)
    {
        switch (menu())
        {
        case 1:
        {

            string nombre;
            string apellido;
            cout << "Ingrese el nombre: ";
            cin >> nombre;
            cout << "Ingrese el apellido: ";
            cin >> apellido;
            Persona persona(nombre, apellido);
            cout << persona.getNombre() << " " << persona.getApellido() << endl;
            break;
        }
        case 2:
        {
            Tienda tienda("Tienda 1");
            Producto producto("Producto 1", 100);
            tienda.agregarProducto(producto);
            tienda.mostrarProductos();
            break;
        }
        default:
            return 0;
        }
    }
}

int menu()
{
    string separator = string(13, '-');
    cout << setw(13) << "MENU" << endl;
    cout << string(26, '=') << endl;
    cout << setw(10) << "1. Agregar persona" << endl;
    cout << setw(10) << "2. Agregar tienda" << endl;
    cout << setw(10) << "3. Agregar producto" << endl;
    cout << setw(10) << "4. Comprar producto" << endl;
    cout << setw(10) << "5. Mostrar productos" << endl;
    cout << setw(10) << "6. Mostrar productos por nombre" << endl;
    cout << setw(10) << "7. Mostrar productos por precio" << endl;
    cout << setw(10) << "8. Mostrar tiendas" << endl;
    cout << left << setw(10) << "9. Salir" << right << endl;
    cout << endl;

    int opcion;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    if (opcion > 9 || opcion < 1)
    {
        cout << "Opcion invalida" << endl;
        return menu();
    }
    return opcion;
}