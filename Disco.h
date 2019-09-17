//
//  Disco.h
//  Proyecto 3
//
//  Created by Ernesto Garcia on 4/16/19.
//  Copyright © 2019 Ernesto Garcia. All rights reserved.
//

#ifndef Disco_h
#define Disco_h

#include "Material.h"

class Disco:public Material{
public:
    Disco();
    Disco(int,string,int);
    //Metodos de acceso
    int getDuracion(){return duracion;}
    //Métodos de modificación
    void setDuracion(int dur){duracion=dur;}
    //Métodos redefinidos
    void muestra();
    int cantidadDeDiasDePrestamo();
private:
    int duracion;
};

Disco::Disco():Material(){
    duracion=0;
}

Disco::Disco(int mat,string tit,int dur):Material(mat,tit){
    duracion=dur;
}

void Disco::muestra(){
    cout << "Disco - " << idMaterial << " " << titulo << " -- Duración: " << duracion << endl;
}

int Disco::cantidadDeDiasDePrestamo(){
    return 3;
}


#endif /* Disco_h */
