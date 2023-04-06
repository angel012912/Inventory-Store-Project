/*
Author: Jose Angel Garcia Gomez
Date: 30/11/2020
Description: This file is the definition of the class Producto.
*/

#ifndef PRODUCTO_C
#define PRODUCTO_C


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Producto{
    float precio, promocion, promocion_cliente_frecuente;
    int id_producto;
    string genero_prenda, tipo_cliente;
    public:
    Producto(){
        id_producto = 0;
        promocion_cliente_frecuente = .85;
    }
        
    Producto(float precio, float promocion, float promocion_cliente_frecuente, int id_producto,string genero_prenda, string tipo_cliente){
        this->precio = precio;
        this->promocion = promocion;
        this->promocion_cliente_frecuente = promocion_cliente_frecuente;
        this->id_producto = id_producto;
        this->genero_prenda = genero_prenda;
        this->tipo_cliente = tipo_cliente;
    }
    float getPrecio(){return precio;}
    float getPromocion(){return promocion;}
    float getPromocion_cliente_frecuente(){return promocion_cliente_frecuente;}
    int getId_producto(){return id_producto;}
    string getGenero_prenda(){return genero_prenda;}
    string getTipo_cliente(){return tipo_cliente;}

    void setPrecio(float precio){this->precio = precio;}
    void setPromocion(float promocion){this->promocion = promocion;}
    void setPromocion_cliente_frecuente(float promocion_cliente_frecuente){this->promocion_cliente_frecuente = promocion_cliente_frecuente;}
    void setId_producto(int id_producto){this->id_producto = id_producto;}
    void setGenero_prenda(string genero_prenda){this->genero_prenda = genero_prenda;}
    void setTipo_cliente(string tipo_cliente){this->tipo_cliente = tipo_cliente;}
    
    int otorgar_id_producto(){
        ++id_producto;
        return id_producto;
    }//otorgar id producto



    void aplicar_descuento_cliente(){
        precio = precio * promocion_cliente_frecuente;
    }//Aplicar descuento cliente

    void datos_producto(){
        //vector<Producto> datos;
        float costo;
        float promo;
        string genero;
        cout<<"Ingresa el precio del producto para el cliente: "; cin >> costo;
        cout<<"¿El producto tiene una promocion? (si no tiene pon 0, si si escribelo como decimal): "; cin >> promo;
        cout<<"¿De que genero es la prenda? (H/M) ";cin >>genero;
        cout<<endl;
        setPrecio(costo);
        setPromocion(promo);
        setGenero_prenda(genero);
        aplicar_promocion();
    }//datos producto
    string print(){
        return"\nProducto: \n\tID: " + to_string(id_producto) + "\n\tEl precio del producto es de: $"+ to_string(precio)+"\n\tEse producto tiene promocion del "+ to_string(promocion) +" porciento.\n\t"+"Esa prenda está disponible para " + genero_prenda+ "\n";
    }//print
    void aplicar_promocion(){
        float descuento;
        descuento = precio * promocion;
        precio = precio - descuento;
        cout << "\tCon la promocion el nuevo precio es: $"+to_string(precio)<<endl;
        
    }//aplicar promocion
};//Clase Producto

#endif