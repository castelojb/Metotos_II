
#include <cmath>
#include <cstdio>
#include <string>
#include <iostream>

#include <GL/freeglut.h>

#include "../lib/CImg/CImg.h"
#include "../header/ExibeMenu.h"

using namespace std;

static const unsigned int   W_Npixels = 500, H_Npixels = 600;

unsigned const int tamanho_vetor_imagens = 24;
char vetor_imagens[tamanho_vetor_imagens][30];
int indice_imagens = 4;
int tipo_derivada = 2;
int controlador = 10;
int fator = 16;
float precisao = 20;
int quant_aplicacoes_borrado = 0;
int borrado = 0;
double d;
bool colorido = false;

int rgb_imagem[550][650][3];
int rgb_imagem_aux1[550][650][3];
int rgb_imagem_aux2[550][650][3];

int borra(){
	int retorno = 1;
	if (quant_aplicacoes_borrado%2) {
		retorno = 2;

		for (int y = 2; y < H_Npixels+2; y++) {
			for (int x = 2; x < W_Npixels+2; ++x) {
				rgb_imagem_aux2[x][y][0] = abs(4*rgb_imagem_aux1[x][y][0] + 2*rgb_imagem_aux1[x-1][y][0] + 2*rgb_imagem_aux1[x+1][y][0] + 2*rgb_imagem_aux1[x][y-1][0] + 2*rgb_imagem_aux1[x][y][0] + rgb_imagem_aux1[x-1][y-1][0] + rgb_imagem_aux1[x+1][y+1][0] + rgb_imagem_aux1[x-1][y+1][0] + rgb_imagem_aux1[x+1][y-1][0])/fator; 

				rgb_imagem_aux2[x][y][1] = abs(4*rgb_imagem_aux1[x][y][1] + 2*rgb_imagem_aux1[x-1][y][1] + 2*rgb_imagem_aux1[x+1][y][1] + 2*rgb_imagem_aux1[x][y-1][1] + 2*rgb_imagem_aux1[x][y][1] + rgb_imagem_aux1[x-1][y-1][1] + rgb_imagem_aux1[x+1][y+1][1] + rgb_imagem_aux1[x-1][y+1][1] + rgb_imagem_aux1[x+1][y-1][1])/fator; 

				rgb_imagem_aux2[x][y][2] = abs(4*rgb_imagem_aux1[x][y][2] + 2*rgb_imagem_aux1[x-1][y][2] + 2*rgb_imagem_aux1[x+1][y][2] + 2*rgb_imagem_aux1[x][y-1][2] + 2*rgb_imagem_aux1[x][y][2] + rgb_imagem_aux1[x-1][y-1][2] + rgb_imagem_aux1[x+1][y+1][2] + rgb_imagem_aux1[x-1][y+1][2] + rgb_imagem_aux1[x+1][y-1][2])/fator; 

			}
		}

	} else if (quant_aplicacoes_borrado) {
		for (int y = 2; y < H_Npixels+2; y++) {
			for (int x = 2; x < W_Npixels+2; ++x) {
				rgb_imagem_aux1[x][y][0] = abs(4*rgb_imagem_aux2[x][y][0] + 2*rgb_imagem_aux2[x-1][y][0] + 2*rgb_imagem_aux2[x+1][y][0] + 2*rgb_imagem_aux2[x][y-1][0] + 2*rgb_imagem_aux2[x][y][0] + rgb_imagem_aux2[x-1][y-1][0] + rgb_imagem_aux2[x+1][y+1][0] + rgb_imagem_aux2[x-1][y+1][0] + rgb_imagem_aux2[x+1][y-1][0])/fator; 

				rgb_imagem_aux1[x][y][1] = abs(4*rgb_imagem_aux2[x][y][1] + 2*rgb_imagem_aux2[x-1][y][1] + 2*rgb_imagem_aux2[x+1][y][1] + 2*rgb_imagem_aux2[x][y-1][1] + 2*rgb_imagem_aux2[x][y][1] + rgb_imagem_aux2[x-1][y-1][1] + rgb_imagem_aux2[x+1][y+1][1] + rgb_imagem_aux2[x-1][y+1][1] + rgb_imagem_aux2[x+1][y-1][1])/fator; 

				rgb_imagem_aux1[x][y][2] = abs(4*rgb_imagem_aux2[x][y][2] + 2*rgb_imagem_aux2[x-1][y][2] + 2*rgb_imagem_aux2[x+1][y][2] + 2*rgb_imagem_aux2[x][y-1][2] + 2*rgb_imagem_aux2[x][y][2] + rgb_imagem_aux2[x-1][y-1][2] + rgb_imagem_aux2[x+1][y+1][2] + rgb_imagem_aux2[x-1][y+1][2] + rgb_imagem_aux2[x+1][y-1][2])/fator; 


			}
		}

	} else {
		for (int y = 2; y < H_Npixels+2; y++) {
			for (int x = 2; x < W_Npixels+2; ++x) {
				rgb_imagem_aux1[x][y][0] = abs(4*rgb_imagem[x][y][0] + 2*rgb_imagem[x-1][y][0] + 2*rgb_imagem[x+1][y][0] + 2*rgb_imagem[x][y-1][0] + 2*rgb_imagem[x][y][0] + rgb_imagem[x-1][y-1][0] + rgb_imagem[x+1][y+1][0] + rgb_imagem[x-1][y+1][0] + rgb_imagem[x+1][y-1][0])/fator; 

				rgb_imagem_aux1[x][y][1] = abs(4*rgb_imagem[x][y][1] + 2*rgb_imagem[x-1][y][1] + 2*rgb_imagem[x+1][y][1] + 2*rgb_imagem[x][y-1][1] + 2*rgb_imagem[x][y][1] + rgb_imagem[x-1][y-1][1] + rgb_imagem[x+1][y+1][1] + rgb_imagem[x-1][y+1][1] + rgb_imagem[x+1][y-1][1])/fator; 

				rgb_imagem_aux1[x][y][2] = abs(4*rgb_imagem[x][y][2] + 2*rgb_imagem[x-1][y][2] + 2*rgb_imagem[x+1][y][2] + 2*rgb_imagem[x][y-1][2] + 2*rgb_imagem[x][y][2] + rgb_imagem[x-1][y-1][2] + rgb_imagem[x+1][y+1][2] + rgb_imagem[x-1][y+1][2] + rgb_imagem[x+1][y-1][2])/fator; 
			}
		}
	}
	quant_aplicacoes_borrado++;
	return retorno;

}


int derivada(int x, int y, int tipo, int rgbXY){
	if (tipo_derivada == 1) {
		switch(rgbXY){
			case 1:
				return abs( rgb_imagem[x][y][0] - rgb_imagem[x-1][y][0] );
			case 2:
				return abs( rgb_imagem[x][y][1] - rgb_imagem[x-1][y][1] );
			case 3:
				return abs( rgb_imagem[x][y][2] - rgb_imagem[x-1][y][2] );
			case 4:
				return abs( rgb_imagem[x][y][0] - rgb_imagem[x][y-1][0] );
			case 5:
				return abs( rgb_imagem[x][y][1] - rgb_imagem[x][y-1][1] );
			case 6:
				return abs( rgb_imagem[x][y][2] - rgb_imagem[x][y-1][2] );

			default:
				break;
		}

	} else if (tipo_derivada == 2){

		switch(rgbXY){
			case 1:
				return abs( rgb_imagem[x+1][y][0] - rgb_imagem[x-1][y][0] )/2;
			case 2:
				return abs( rgb_imagem[x+1][y][1] - rgb_imagem[x-1][y][1] )/2;
			case 3:
				return abs( rgb_imagem[x+1][y][2] - rgb_imagem[x-1][y][2] )/2;
			case 4:
				return abs( rgb_imagem[x+1][y][0] - rgb_imagem[x][y-1][0] )/2;
			case 5:
				return abs( rgb_imagem[x+1][y][1] - rgb_imagem[x][y-1][1] )/2;
			case 6:
				return abs( rgb_imagem[x+1][y][2] - rgb_imagem[x][y-1][2] )/2;

			default:
				break;
		}

	} else if (tipo_derivada == 3) {
		switch(rgbXY){
			case 1:
				return abs( rgb_imagem[x][y][0] - rgb_imagem[x+1][y][0] );
			case 2:
				return abs( rgb_imagem[x][y][1] - rgb_imagem[x+1][y][1] );
			case 3:
				return abs( rgb_imagem[x][y][2] - rgb_imagem[x+1][y][2] );
			case 4:
				return abs( rgb_imagem[x][y][0] - rgb_imagem[x][y+1][0] );
			case 5:
				return abs( rgb_imagem[x][y][1] - rgb_imagem[x][y+1][1] );
			case 6:
				return abs( rgb_imagem[x][y][2] - rgb_imagem[x][y+1][2] );

			default:
				break;
		}

	} else if (tipo_derivada == 4 and x > 2 and y > 2){
	
		switch(rgbXY){
			case 1:
				return abs( abs( rgb_imagem[x+1][y][0] - rgb_imagem[x-1][y][0] )/2 -
							abs( rgb_imagem[x][y][0]   - rgb_imagem[x-2][y][0] )/2 );
			case 2:
				return abs( abs( rgb_imagem[x+1][y][1] - rgb_imagem[x-1][y][1] )/2 -
							abs( rgb_imagem[x][y][1]   - rgb_imagem[x-2][y][1] )/2 );
			case 3:
				return abs( abs( rgb_imagem[x+1][y][2] - rgb_imagem[x-1][y][2] )/2 -
							abs( rgb_imagem[x][y][2]   - rgb_imagem[x-2][y][2] )/2 );
			case 4:
				return abs(	abs( rgb_imagem[x+1][y][0] - rgb_imagem[x][y-1][0] )/2 - 
							abs( rgb_imagem[x][y][0]   - rgb_imagem[x][y-2][0] )/2 );
			case 5:
				return abs( abs( rgb_imagem[x+1][y][1] - rgb_imagem[x][y-1][1] )/2 - 
							abs( rgb_imagem[x][y][1]   - rgb_imagem[x][y-2][1] )/2 );
			case 6:
				return abs( abs( rgb_imagem[x+1][y][2] - rgb_imagem[x][y-1][2] )/2 - 
							abs( rgb_imagem[x][y][2]   - rgb_imagem[x][y-2][2] )/2 );

			default:
				break;
		}

	}

	return 0;
}


void le_imagem(){
	quant_aplicacoes_borrado = 0;
	using namespace cimg_library;

	CImg<unsigned char> imagem(vetor_imagens[indice_imagens]);

	int canais = imagem.spectrum();
	int red, green, blue;

	for (int y = 0; y < H_Npixels; ++y) {
		for (int x = 0; x < W_Npixels; ++x){
			red = imagem(x, y, 0);

			if (canais > 1) green = imagem(x, y, 1);
			else green = red;

			if (canais == 3) blue = imagem(x, y, 2);
			else blue = green;

			rgb_imagem[x][y][0] = red;
			rgb_imagem[x][y][1] = green;
			rgb_imagem[x][y][2] = blue;
		}
	}
}

void contorno(void) {

	int x = 0, y = 0;
	double red = 0, green = 0, blue = 0;
	double xRed, xGreen, xBlue, yRed, yGreen, yBlue;
	bool x_borda, y_borda;

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POINTS);

		for(y = 2; y < H_Npixels+1; y++){
			for(x = 2; x < W_Npixels; x++){
				red   = (double)rgb_imagem[x][y][0]/255;
				green = (double)rgb_imagem[x][y][1]/255;
				blue  = (double)rgb_imagem[x][y][2]/255;
				
				glColor3f(red, green, blue);
				glVertex2f(x-1, y-1);

			}

			for (int xaux = W_Npixels; xaux < 2*W_Npixels; xaux++) {
				x = xaux - W_Npixels + 1;

				xRed   = derivada(x, y, tipo_derivada, 1);
				xGreen = derivada(x, y, tipo_derivada, 2);
				xBlue  = derivada(x, y, tipo_derivada, 2);

				yRed   = derivada(x, y, tipo_derivada, 4);
				yGreen = derivada(x, y, tipo_derivada, 5);
				yBlue  = derivada(x, y, tipo_derivada, 6);
				
				x_borda = xRed > precisao or xGreen > precisao or xBlue > precisao;
				y_borda = yRed > precisao or yGreen > precisao or yBlue > precisao;
				

				if (x_borda or y_borda) {
					red = 0;
					green = 0;
					blue = 0;

				} else if (colorido){
					red   = (double)rgb_imagem[x][y][0]/255;
					green = (double)rgb_imagem[x][y][1]/255;
					blue  = (double)rgb_imagem[x][y][2]/255;
			
				} else {
					red = 1;
					green = 1;
					blue = 1;
				}

				if (tipo_derivada == 5) {
			
					if (borrado == 1) {
						red   = (double)rgb_imagem_aux1[x][y][0]/255;
						green = (double)rgb_imagem_aux1[x][y][1]/255;
						blue  = (double)rgb_imagem_aux1[x][y][2]/255;

					} else {
						red   = (double)rgb_imagem_aux2[x][y][0]/255;
						green = (double)rgb_imagem_aux2[x][y][1]/255;
						blue  = (double)rgb_imagem_aux2[x][y][2]/255;

					}
					red = abs(red);
					green = abs(green);
					blue = abs(blue);
					
				}
				glColor3f(red, green, blue);
				glVertex2f(xaux, y-1);
			}
		}
	
	glEnd();
	glFlush();

}


void setGlobais(){
	glClearColor(0.8, 0.9, 0.9, 0.0);

	strcpy(vetor_imagens[0], "imagem/imagem0.jpg");
	strcpy(vetor_imagens[1], "imagem/imagem1.jpg");
	strcpy(vetor_imagens[2], "imagem/imagem2.jpg");
	strcpy(vetor_imagens[3], "imagem/imagem3.jpg");
	strcpy(vetor_imagens[4], "imagem/imagem4.jpg");
	strcpy(vetor_imagens[5], "imagem/imagem5.jpg");
	strcpy(vetor_imagens[6], "imagem/imagem6.jpg");
	strcpy(vetor_imagens[7], "imagem/imagem7.jpg");
	strcpy(vetor_imagens[8], "imagem/imagem8.jpg");
	strcpy(vetor_imagens[9], "imagem/imagem9.jpg");
	strcpy(vetor_imagens[10], "imagem/imagem10.jpg");
	strcpy(vetor_imagens[11], "imagem/imagem11.jpg");
	strcpy(vetor_imagens[12], "imagem/imagem12.jpg");
	strcpy(vetor_imagens[13], "imagem/imagem13.jpg");
	strcpy(vetor_imagens[14], "imagem/imagem14.jpg");
	strcpy(vetor_imagens[15], "imagem/imagem15.jpg");
	strcpy(vetor_imagens[16], "imagem/imagem16.jpg");
	strcpy(vetor_imagens[17], "imagem/imagem17.jpg");
	strcpy(vetor_imagens[18], "imagem/imagem18.jpg");
	strcpy(vetor_imagens[19], "imagem/imagem19.jpg");
	strcpy(vetor_imagens[20], "imagem/imagem20.jpg");
	strcpy(vetor_imagens[21], "imagem/imagem21.jpg");
	strcpy(vetor_imagens[22], "imagem/imagem22.jpg");
	strcpy(vetor_imagens[23], "imagem/imagem23.jpg");

}

void Especial(int key, int x, int y){
	switch(key){
		case GLUT_KEY_LEFT:
			if (indice_imagens + 1 == tamanho_vetor_imagens) indice_imagens = 0;
			else indice_imagens ++; 
			le_imagem(); 
			if (tipo_derivada == 5) borrado = borra(); 
			break;
		
		case GLUT_KEY_RIGHT:
			if (indice_imagens - 1 == -1) indice_imagens = tamanho_vetor_imagens - 1;
			else indice_imagens --; 
			le_imagem(); 
			if (tipo_derivada == 5) borrado = borra();
			break;

		case GLUT_KEY_UP:
			precisao += 0.5; break;
		
		case GLUT_KEY_DOWN:
			if (precisao - 0.5 <= 0) precisao = 0.5;
			else precisao -= 0.5; break;
		
		default:
			break;
	}
	glutPostRedisplay();

}

void Mouse(int button, int state, int x, int y) {
	switch((char)button) {
		case 3:
			if (state == GLUT_UP) if (tipo_derivada == 5) borrado = borra();
			else if (state == GLUT_UP) if (fator - 1 > 0) fator--; break;

		case 4:
			if (state == GLUT_UP) fator++;
			else if (state == GLUT_UP) if (fator - 1 > 0) fator--; break;

		default:
			break;
	}
	glutPostRedisplay();
}

//Pra fechar a janeça com o ESC
void Teclado(unsigned char key, int x, int y) {	
	switch((char)key) {
		case 27: //ESC
			limpaMenu(); glutDestroyWindow(0); exit(0); break;

		case 'a':
			if (indice_imagens + 1 == tamanho_vetor_imagens) indice_imagens = 0;
			else indice_imagens ++; break;

		case 'A':
			if (indice_imagens + 1 == tamanho_vetor_imagens) indice_imagens = 0;
			else indice_imagens ++; break;

		case 'B':
			if (tipo_derivada == 5) borrado = borra();

		case 'b':
			if (tipo_derivada == 5) borrado = borra();

		case 32: //Espaço
			if (indice_imagens - 1 == -1) indice_imagens = tamanho_vetor_imagens - 1;
			else indice_imagens --; break;

		case '+': 
			fator++; break;

		case '-': 
			if (fator - 1 <= 0) fator = 1;
			else fator--; break;

		case 'c':
			if (colorido) colorido = false;
			else colorido = true; break;

		case 'C':
			if (colorido) colorido = false;
			else colorido = true; break;

		case '1':
			tipo_derivada = 1; break;

		case '2':
			tipo_derivada = 2; break;

		case '3':
			tipo_derivada = 3; break;

		case '4':
			tipo_derivada = 4; break;

		case '5':
			tipo_derivada = 5; 
			borrado = borra(); break;

		default:
			break;
	}
	glutPostRedisplay();
}

void redimenciona(int w, int h) {
	glViewport(0, 0,  w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 2*W_Npixels, H_Npixels, 0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char **argv) {
	exibeMenu();
	setGlobais();
	le_imagem();

	glutInit(&argc, argv);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); 
	glutInitWindowSize(2*W_Npixels, H_Npixels);
	glutInitWindowPosition(50, 50);


	glutCreateWindow("     ORIGINAL  X  CONTORNO ");
	glutDisplayFunc(contorno);
	glutReshapeFunc(redimenciona);
	glutKeyboardFunc(Teclado);
	//glutMouseFunc(Mouse);
	glutSpecialFunc(Especial);

	glutCloseFunc(limpaMenu);


	glutMainLoop(); 
}
