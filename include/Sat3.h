//
// Created by izm20 on 24/11/17.
//

#ifndef PRACTICA4_SAT3_H
#define PRACTICA4_SAT3_H

#include <iostream>
#include <bitset>
#include <fstream>
#include <vector>

using  namespace std;

class Sat3 {
private:
    bitset <3> neg_;
    bitset <3> val_;
    bitset <3> in_;
public:
    Sat3();
    Sat3(bitset <3> neg, bitset <3> val, bitset <3> in);
    Sat3(const Sat3 &cp);
    virtual ~Sat3();

    void leer(string nombreFichero);
    void tranformacion(vector <string> clausula);
    string espacios(string cadena);
    void salida(vector <bitset<1> > val, vector <bitset<1> > in, vector <bitset<1> > neg);
    int contar(vector <bitset<1> > aux);

    const bitset<3> &getNeg_() const;
    void setNeg_(const bitset<3> &neg_);
    const bitset<3> &getVal_() const;
    void setVal_(const bitset<3> &val_);
    const bitset<3> &getIn_() const;
    void setIn_(const bitset<3> &in_);
};

#endif //PRACTICA4_SAT3_H
