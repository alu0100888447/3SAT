//
// Created by izm20 on 24/11/17.
//

#include "../include/Sat3.h"

Sat3::Sat3() {
    neg_.reset();
    val_.reset();
    in_.reset();
}

Sat3::Sat3(bitset<3> neg, bitset<3> val, bitset<3> in) {
    neg_ = neg;
    val_ = val;
    in_ = in;
}

Sat3::Sat3(const Sat3 &cp) {
    neg_ = cp.getNeg_();
    val_ = cp.getVal_();
    in_ = cp.getIn_();
}

Sat3::~Sat3() {
    neg_.reset();
    val_.reset();
    in_.reset();
}

void Sat3::leer(string nombreFichero) {
    ifstream fichero(nombreFichero);
    vector <string> vAux;
    string aux;
    if (fichero.is_open()) {
        while (!fichero.eof()) {
            aux = "";
            getline(fichero, aux);
            aux = espacios(aux);
            if (aux != "")
                vAux.push_back(aux);
        }
    }
    tranformacion(vAux);
}

void Sat3::tranformacion(vector<string> clausula) {
    vector <bitset<1> > val, in, neg;
    for (int i = 0; i < clausula.size(); ++i) {
        for (int j = 0; j < clausula[i].size(); ++j) {
            bitset<1> auxb (clausula[i][j]);
            if (i == 0)
                neg.push_back(auxb);
            else if (i == 1)
                val.push_back(auxb);
            else if (i == 2)
                in.push_back(auxb);
        }
    }
    salida(val, in, neg);
    switch (contar(in)) {
        case 1:
    }

}

void Sat3::salida(vector<bitset<1> > val, vector<bitset<1> > in, vector<bitset<1> > neg) {
    cout << endl << "{ ";
    for (int l = 0; l < val.size(); ++l) {
        if (in[l] == 1) {
            if (neg[l] == 1)
                cout << "¬";
            cout << "u" << l + 1 << "=" << val[l] << " ";
        }
    }
    cout << "} " << endl;
}

string Sat3::espacios(string cadena) {
    string cadenaAux;
    int i = 0;
    while(i < cadena.size()) {
        if (cadena[i] != ' ') {
            cadenaAux.push_back(cadena[i]);
        }
        ++i;
    }
    return cadenaAux;
}

int Sat3::contar(vector<bitset<1> > aux) {
    int cont = 0;
    for (int i = 0; i < aux.size(); ++i) {
        if (aux[i] == 1)
            ++cont;
    }
    return cont;
}

const bitset<3> &Sat3::getNeg_() const {
    return neg_;
}

void Sat3::setNeg_(const bitset<3> &neg_) {
    Sat3::neg_ = neg_;
}

const bitset<3> &Sat3::getVal_() const {
    return val_;
}

void Sat3::setVal_(const bitset<3> &val_) {
    Sat3::val_ = val_;
}

const bitset<3> &Sat3::getIn_() const {
    return in_;
}

void Sat3::setIn_(const bitset<3> &in_) {
    Sat3::in_ = in_;
}
