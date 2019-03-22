#include "Cosseno.h"
#include <math.h>
#define PI 3.14159265
using namespace std;

Cosseno::Cosseno(){}

float Cosseno::calcula(float x){
	
	return cos(x*PI/180);

}