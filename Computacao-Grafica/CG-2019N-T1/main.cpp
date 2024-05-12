/*+
* Autora: Isabeli Reik
* Disciplina: Computação gráfica
* Ano: 2019/1
* email: isabelireik2@gmail.com
 */

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

GLfloat altura = 0.1;
GLint bx1 = 0, by1 = 0, bz1 = 0;
GLint bx2 = 0, by2 = 0, bz2 = 0;
GLint bx3 = 0, by3 = 0, bz3 = 0;
GLint angulo1 = 0, angulo2 = 0, angulo3 = 0;

void renderCoordinateAxis(){ //plano cartesiano
	//eixo x - verde
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
		glVertex2f(-1.0, 0.0); //lado esquerdo - negativo
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 0.0); //lado direito - positivo
		glVertex2f(1.0, 0.0);
	glEnd();

	//eixo y - azul
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
		glVertex2f(0.0, 0.0); //em cima - positivo
		glVertex2f(0.0, 1.0);
		glVertex2f(0.0, 0.0); //em baixo - negativo
		glVertex2f(0.0, -1.0);
	glEnd();
}

void display(){
	glClearColor(1, 1, 1, 0); //fundo branco
	glClear(GL_COLOR_BUFFER_BIT); //limpa a tela
	glMatrixMode(GL_MODELVIEW); //queremos fazer alterações na matriz modelView
	glLoadIdentity();
	renderCoordinateAxis(); //chama a função do plano cartesiano

	//bloco 1 - base
	glColor3f(0.3f, 0.5f, 0.6f);
	glTranslatef(0.4f, 0.05f, 0.0f);
	glutWireCube(altura);
	glRotated(angulo1, bx1, by1, bz1);
	glPushMatrix();
		//bloco 2
		glColor3f(0.6f, 0.5f, 0.3f);
		glTranslatef(0.0f, 0.10f, 0.0f);
		glutWireCube(altura);
		glRotated(angulo2, bx2, by2, bz2);
		glPushMatrix();
			//bloco 3
			glColor3f(0.3f, 0.7f, 0.2f);
			glTranslatef(0.0f, 0.10f, 0.0f);
			glutWireCube(altura);
			glRotated(angulo3, bx3, by3, bz3);
			glPushMatrix();
				//bloco 4;
				glColor3f(0.7f, 0.0f, 0.0f);
				glTranslatef(0.0f, 0.15f, 0.0f);
				glScalef(1.0f, 2.0f, 1.0f);
				glutSolidCube(altura);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();

	glutSwapBuffers(); //atualiza a display
}

void keyboard(unsigned char key, int x, int y){
	if (key == 27){ //fechar o programa
		exit(0);
	}

	switch (key){ //switch para detectar as entradas do teclado
	case 'q': //bloco 2
	case 'Q':
		bz1 = 1;
		if (angulo1 > -90)
			angulo1 = angulo1 - 5;
	break;

	case 'a':
	case 'A':
		bz1 = 1;
		if (angulo1 < 90)
			angulo1 = angulo1 + 5;
	break;

	case 'w': //bloco 3
	case 'W':
		bz2 = 1;
		if (angulo2 < 35)
			angulo2 = angulo2 + 5;
	break;

	case 's':
	case 'S':
		bz2 = 1;
		if (angulo2 >- 35)
			angulo2 = angulo2 - 5;
	break;

	case 'e': //bloco 4
	case 'E':
		bz3 = 1;
		if (angulo3 < 35)
			angulo3 = angulo3 + 5;
	break;

	case 'd':
	case 'D':
		bz3 = 1;
		if (angulo3 > -35)
			angulo3 = angulo3 - 5;
	break;
	}

	glutPostRedisplay();
}

int main(int argc, char** argv){
	//chamadas para inicialização
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Braço Robótico");

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);

	glutMainLoop(); //loop mains
	return 0;
}