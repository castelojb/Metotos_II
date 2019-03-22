#ifndef POLINOMIO_H_
#define POLINOMIO_H_
#include "Funcao.h"

class Polinomio: public Funcao {
public:
	Polinomio(int grau)
	int getGrau();
	void setGrau(int grau);
	float calcula(float x);


	int grau;
};

#endif