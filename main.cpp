#include<GL/glut.h>

void Inisialisasi (void)
{
    glClearColor(1,1,1,0);
    glColor3f (0.0f,0.0f,0.f);
    glPointSize(10);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glLineWidth(4);
    gluOrtho2D(0.0,640.0,0.0,480.0);
}

void tampil(void)
{
    float ax=50,ay=50,bx=150,by=200,cx=50,cy=200,dx=150,dy=50,
    ex=100,ey=50,fx=200,fy=200,gx=100,gy=200,hx=200,hy=50,
    mab,cab,mef,cef,mcd,ccd,mgh,cgh,px,py,pz,pi,pa1,pa2,pb1,pb2;
    glClear(GL_COLOR_BUFFER_BIT);
    //garis
    glBegin(GL_LINES);
    glColor3f(1,1,0.1);
    glVertex2f(ax,ay);
    glVertex2f(bx,by);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,1);
    glVertex2f(cx,cy);
    glVertex2f(dx,dy);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,1,0);
    glVertex2f(ex,ey);
    glVertex2f(fx,fy);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(gx,gy);
    glVertex2f(hx,hy);
    glEnd();

    //rumuz
    mab=(by-ay)/(bx-ax);
    mcd=(dy-cy)/(dx-cx);
    mef=(fy-ey)/(fx-ex);
    mgh=(hy-gy)/(hx-gx);
    cab=ay-(ax*mab);
    ccd=cy-(cx*mcd);
    cef=ey-(ex*mef);
    cgh=gy-(gx*mgh);

    //titik fotong
    px=(ccd-cab)/(mab-mcd);
    py=(mab*px)+cab;

    pz=(cgh-cab)/(mab-mgh);
    pi=(mgh*pz)+cgh;

    pa1=(cef-ccd)/(mcd-mef);
    pa2=(mef*pa1)+cef;

    pb1=(cgh-cef)/(mef-mgh);
    pb2=(mgh*pb1)+cgh;
    //Titiknya
    glBegin(GL_POINTS);
    glColor3f(1,0,0);
    glVertex2f(px,py);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(1,0,0);
    glVertex2f(pz,pi);
    glEnd();

     glBegin(GL_POINTS);
    glColor3f(1,0,0);
    glVertex2f(pa1,pa2);
    glEnd();


    glBegin(GL_POINTS);
    glColor3f(1,0,0);
    glVertex2f(pb1,pb2);
    glEnd();

    glBegin (GL_LINE_LOOP) ;
    glColor3f(0,0,0);
	glVertex2f (50,50) ; //garis bawahan,depan garis kiri
	glVertex2f (200,50) ; //garis bawahan
	glVertex2f (200,200) ; //garis pucukan,depan garis kanan
	glVertex2f (50,200) ;//garis pucukan
	glEnd ();


    glFlush();
}
int main (int argc, char **argv)
	{
	glutInit (&argc , argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowPosition (100,100);
	glutInitWindowSize (640,480) ; //ukuran dari jendela
	glutCreateWindow ("TUGAS2 Grafkom 672018219") ;
    Inisialisasi();
	glutDisplayFunc (tampil) ; //yang mau dirender
	glutMainLoop () ;
	}
