//
//  Material.h
//  Proyecto 3
//
//  Created by Ernesto Garcia on 4/15/19.
//  Copyright © 2019 Ernesto Garcia. All rights reserved.
//

#ifndef Material_h
#define Material_h
class Material{
public:
    //Constructores
    Material();
    Material(int,string);
    //Métodos de acceso
    int getIdMaterial(){return idMaterial;}
    string getTitulo(){return titulo;}
    //Métodos de modificación
    void setIdMaterial(int mat){idMaterial=mat;}
    void setTitulo(string tit){titulo=tit;}
    //Métodos abstractos
    virtual void muestra()=0;
    virtual int cantidadDeDiasDePrestamo()=0;
    
protected:
    int idMaterial;
    string titulo;
};

Material::Material(){
    idMaterial=0;
    titulo="-";
}

Material::Material(int mat, string tit){
    idMaterial=mat;
    titulo=tit;
}

#endif /* Material_h */
