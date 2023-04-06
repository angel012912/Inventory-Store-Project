
#include "inventario.h"
#include "dueno.h"
#include <iostream>
#include <string>

using  namespace std;

int main(){
    cout<<"Pruebas generales"<<endl;
    Inventario inv1;
    cout << inv1.agregar_producto() << endl;
    inv1.mostrar_atributos_producto();
    cout << inv1.mostrar_disponible() << endl; 
    cout << inv1.agregar_Clientes() << endl;
    inv1.mostrar_atributos_cliente();
    inv1.borrar_producto();
    inv1.recompensa_tipo_cliente();
    inv1.hacer_pedido();//Esto es parte de la implementacion de la programacion individual de Angel
    Dueno d1;//Parte individual hecha por Erika
    d1.registrar_datos_dueno();//Parte individual hecha por Erika
    cout<<d1.print_info_dueno()<<endl;//Parte individual hecha por Erika
    d1.registrar_prestamo();//Parte individual hecha por Erika
    d1.registrar_pago_prestamo();//Parte individual hecha por Erika
    d1.mostrar_deuda();//Parte individual hecha por Erika

};
