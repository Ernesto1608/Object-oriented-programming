//
//  Libro.h
//  Proyecto 3
//
//  Created by Ernesto Garcia on 4/16/19.
//  Copyright © 2019 Ernesto Garcia. All rights reserved.
//

#ifndef Libro_h
#define Libro_h

#include "Material.h"

class Libro:public Material{
public:
    Libro();
    Libro(int,string,int,string);
    //Métodos de acceso
    int getNumPag(){return numPag;}
    string getAutor(){return autor;}
    //Métodos de modificación
    void setNumPag(int num){numPag=num;}
    void setAutor(string aut){autor=aut;}
    //Métodos redefinidos
    void muestra();
    int cantidadDeDiasDePrestamo();
private:
    int numPag;
    string autor;
};

Libro::Libro():Material(){
    numPag=0;
    autor="-";
}

Libro::Libro(int mat, string nombre, int pag, string aut):Material(mat,nombre){
    numPag=pag;
    autor=aut;
}

void Libro::muestra(){
    cout << "Libro - " << idMaterial << " " << titulo << " -- Autor: " << autor << " -- NumPag: " << numPag << endl;
}

int Libro::cantidadDeDiasDePrestamo(){
    return 10;
}


#endif /* Libro_h */
