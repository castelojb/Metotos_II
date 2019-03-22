#include "Polinomio.h"
#include <math.h>

using namespace std;

Polinomio(int grau){
	this->grau=grau;
}

int Polinomio::getGrau(){
	return this->grau;
}

void Polinomio::setGrau(int grau){
	this->grau = grau;
}


float Polinomio::calcula(float x){
	
	//ja eh inicializado com 0's
	float lista_de_coeficientes[grau+1];

	//usuario coloca os coeficientes do polinomio
	//lista_de_coeficientes[0] = coeficiente do termo pow(x,0)
	//lista_de_coeficientes[1] = coeficiente do termo pow(x,1)
	//lista_de_coeficientes[...] = coeficiente do termo pow(x,...)
	//lista_de_coeficientes[grau] = coeficiente do termo pow(x,grau)

	float resultado;
	for(int i = 0 ; i++ ;i<= this->grau){
		resultado = resultado + lista_de_coeficientes[i] * pow(x,i);
	}


	return resultado;

}