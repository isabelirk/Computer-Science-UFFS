/*
* Prova 1 de computação gráfica
* Autora: Isabeli Rosana Reik
* Matricula: 1611100015
* Email: isabelireik2@gmail.com
*/

//OBS: o trabalho esta com problemas para aparecer todas as faces do cubo, 
//conforme conversamos em um horario marcado para tirar duvidas

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

const unsigned int FRAMES_POR_SEGUNDO = 30;
const unsigned int UPDATE_INTERVAL_MS = 1000 / FRAMES_POR_SEGUNDO;

GLfloat rX = 0; //variavel para rotação eixo x
GLfloat rY = 0; //variavel para rotação eixo y
GLfloat x = 0.2f, y = 0.2f, z = 0.2f; //coordenadas dos vertices do cubo
double angulo = 5.0;
int gTimeLastUpdateMs = 0;

void display(){
	glClearColor(0.8f, 0.8f, 0.8f, 1.0f); //definição da cor de fundo
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa a tela
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); //reseta qualquer transformação feita anteriormente

	//------------------------------CUBO CENTRAL-----------------------------------
	glRotated(angulo, 0, 1, 0); //rotaciona no eixo y
	glRotated(20, 1, 0, 0);
	//frente
	glColor3f(0.3f, 0.5f, 0.6f); //desenho dos pontos tem que ser da esquerda p direita, em circulo
	glBegin(GL_QUADS);
	glVertex3f(0, 0, z); //e
	glVertex3f(0, 0, 0); //a
	glVertex3f(x, 0, 0); //b
	glVertex3f(x, 0, z); //f
	glEnd();

	//direito
	glColor3f(0.5f, 0.3f, 0.2f);
	glBegin(GL_QUADS);
	glVertex3f(x, 0, z); //f
	glVertex3f(x, 0, 0); //b
	glVertex3f(x, y, 0); //c
	glVertex3f(x, y, z); //g
	glEnd();

	//atras
	glColor3f(0.7f, 0.5f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(x, y, z); //g
	glVertex3f(x, y, 0); //c
	glVertex3f(0, y, 0); //d
	glVertex3f(0, y, z); //h
	glEnd();

	//esquerdo
	glColor3f(0.8f, 0.0f, 0.1f);
	glBegin(GL_QUADS);
	glVertex3f(0, y, z); //h
	glVertex3f(0, y, 0); //d
	glVertex3f(0, 0, 0); //a
	glVertex3f(0, 0, z); //e
	glEnd();

	//em cima
	glColor3f(0.0f, 0.5f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(0, 0, z); //e
	glVertex3f(x, 0, z); //f
	glVertex3f(x, y, z); //g
	glVertex3f(0, y, z); //h
	glEnd();

	//em baixo
	glColor3f(0.1f, 0.3f, 0.3f);
	glBegin(GL_QUADS);
	glVertex3f(0, 0, 0); //a
	glVertex3f(x, 0, 0); //b
	glVertex3f(x, y, 0); //c
	glVertex3f(0, y, 0); //d
	glEnd();

	//----------------------------------CUBO LATERAL----------------------------
	glTranslatef(0.8f, 0.5f, 0.0f);
	glRotated(angulo, 0, 0, 1);
	//frente
	glColor3f(0.3f, 0.5f, 0.6f); //desenho dos pontos tem que ser da esquerda p direita, em circulo
	glBegin(GL_QUADS);
	glVertex3f(0, 0, z); //e
	glVertex3f(0, 0, 0); //a
	glVertex3f(x, 0, 0); //b
	glVertex3f(x, 0, z); //f
	glEnd();

	//direito
	glColor3f(0.5f, 0.3f, 0.2f);
	glBegin(GL_QUADS);
	glVertex3f(x, 0, z); //f
	glVertex3f(x, 0, 0); //b
	glVertex3f(x, y, 0); //c
	glVertex3f(x, y, z); //g
	glEnd();

	//atras
	glColor3f(0.7f, 0.5f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(x, y, z); //g
	glVertex3f(x, y, 0); //c
	glVertex3f(0, y, 0); //d
	glVertex3f(0, y, z); //h
	glEnd();

	//esquerdo
	glColor3f(0.8f, 0.0f, 0.1f);
	glBegin(GL_QUADS);
	glVertex3f(0, y, z); //h
	glVertex3f(0, y, 0); //d
	glVertex3f(0, 0, 0); //a
	glVertex3f(0, 0, z); //e
	glEnd();

	//em cima
	glColor3f(0.0f, 0.5f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(0, 0, z); //e
	glVertex3f(x, 0, z); //f
	glVertex3f(x, y, z); //g
	glVertex3f(0, y, z); //h
	glEnd();

	//em baixo
	glColor3f(0.1f, 0.3f, 0.3f);
	glBegin(GL_QUADS);
	glVertex3f(0, 0, 0); //a
	glVertex3f(x, 0, 0); //b
	glVertex3f(x, y, 0); //c
	glVertex3f(0, y, 0); //d
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void update(int valor){
	angulo += 0.8;
}

void internalUpdate(int value){
	int timeNowMs = glutGet(GLUT_ELAPSED_TIME);
	double deltaSeconds = (timeNowMs - gTimeLastUpdateMs) / 1000.0;
	gTimeLastUpdateMs = timeNowMs;
	update(deltaSeconds);
	glutPostRedisplay();
	glutTimerFunc(UPDATE_INTERVAL_MS, internalUpdate, 0);
}

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
	glutPostRedisplay(); //Solicita a atualização da display
}

int main(int argc, char **argv){
	glutInit(&argc, argv); //Inicializações básicas
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
	glutInitWindowSize(700, 700); //definição da janela de exibição no windows
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Prova 1 - Isabeli Reik"); //nome da janela

	glutDisplayFunc(display); //chama a função principal display
	glutTimerFunc(UPDATE_INTERVAL_MS, update, 0);
	glutSpecialFunc(keyboard); //chama a função para atualização do desenho do cubo
	glutTimerFunc(UPDATE_INTERVAL_MS, internalUpdate, 0);

	glutMainLoop(); //loop da main
	return 0;
}