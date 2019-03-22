#include "Seno.h"
#include <math.h>
#define PI 3.14159265
using namespace std;

Seno::Seno(){}

float Seno::calcula(float x){
	
	return sin(x*PI/180);

}
