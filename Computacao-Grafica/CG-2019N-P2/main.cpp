/*
* Prova 2 de computação gráfica
* Autora: Isabeli Rosana Reik
* Matricula : 1611100015
* Email : isabelireik2@gmail.com
*/

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

const unsigned int FRAMES_POR_SEGUNDO = 30;
const unsigned int UPDATE_INTERVAL_MS = 1000 / FRAMES_POR_SEGUNDO;

GLint gTimeLastUpdateMs = 0; //variavel para controle do tempo junto com as constantes acima
GLfloat rX = 0; //variavel para rotação eixo x
GLfloat rY = 0; //variavel para rotação eixo y
double angulo = 5.0; //variavel no controle do angulo da rotação
GLfloat parametro1[4] = { 0.2, 0.0, 0.0, 0.0 };

// função display - desenha na tela
void display(){
	glClearColor(0.4f, 0.4f, 0.4f, 1.0f); //definição da cor de fundo
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa a tela
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); // limpa transformações feitas anteriormente
	
	glTranslated(0.3, 0.0, 0.0); // translada em direção do eixo x
	glRotated(angulo, 0, 1, 0); // rotaciona no eixo y
	glColor3f(0.2f, 0.3f, 0.3f); 
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, parametro1);
	glutSolidCube(0.2);

	glLoadIdentity();
	glTranslated(-0.5, 0.0, 0.0);
	glColor3f(0.6f, 0.0f, 0.0f);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, parametro1);
	glutSolidSphere(0.1, 50, 50);

	glFlush();
	glutSwapBuffers();
}

// função update - atualiza os desenhos da tela para mandar no display
void update(int valor) {
	angulo += 0.8;
}

// função teclado
void keyboard(int key, int x, int y){
	if (key == GLUT_KEY_RIGHT) {
		rY += 5;
	} else if (key == GLUT_KEY_LEFT) {
		rY -= 5;
	} else if (key == GLUT_KEY_DOWN) {
		rX -= 5;
	} else if (key == GLUT_KEY_UP) {
		rX += 5;
	}

	glutPostRedisplay(); // solicita a atualização da display
}

// função update interna para auxiliar com o tempo - frames por segundo
void internalUpdate(int value) {
	int timeNowMs = glutGet(GLUT_ELAPSED_TIME);
	double deltaSeconds = (timeNowMs - gTimeLastUpdateMs) / 1000.0;
	gTimeLastUpdateMs = timeNowMs;
	update(deltaSeconds);
	glutPostRedisplay();
	glutTimerFunc(UPDATE_INTERVAL_MS, internalUpdate, 0);
}

int main(int argc, char **argv){
	//inicializações básicas
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Prova 2 - Isabeli Reik");

	//chamadas das funções principais
	glutDisplayFunc(display);
	glutTimerFunc(UPDATE_INTERVAL_MS, update, 0);
	glutSpecialFunc(keyboard);
	glutTimerFunc(UPDATE_INTERVAL_MS, internalUpdate, 0);

	glutMainLoop(); //loop main
	return 0;
}