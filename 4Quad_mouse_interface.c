#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int xa,ya,xb,yb;
int ROUND(float a){
 
return (int)(a+0.5);
}

void Init()
{
 glClearColor(1.0,1.0,1.0,0);
 glColor3f(0.0,0.0,0.0);
 gluOrtho2D(0,640,0,480);

}
void DDALINE(int xa,int ya, int xb,int yb){
 int dx,dy,steps;
 dx=xb-xa;
 dy=yb-ya;

  if(abs(dx)>abs(dy))
  {
    steps=abs(dx);
  }
  else 
  {
    steps=abs(dy);
  }
  float xincrement,yincrement;
  xincrement=(float)(dx)/steps;
  yincrement=(float)(dy)/steps;
 
 
  

  float x=xa,y=ya;


 for(int i=0;i<steps;i++)
 {
  x=x+xincrement;
  y=y+yincrement;
 glVertex2d(ROUND(x),ROUND(y));
 }
   

}
void mymouse(int button,int state,int x,int y){

 static int xst,yst,pt=0;
 if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
     if(pt==0){
     xst=x;
     yst=y;
     pt++;
     
     
     }
     else{
      DDALINE(xst,480-yst,x,480-y);
        xst=x;
        yst=y;
        glEnd();
     
     }
 }
 if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
  pt=0;
 
 }
glFlush();



}
void Display()
{

   glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POINTS);
  
 DDALINE(0,240,640,240); 
 DDALINE(320,480,320,0); 

 //DDALINE(320+xa,240+ya,320+xb,240+yb); 
 

 
 
}

int main(int argc, char **argv){

 /*printf("first");
 scanf("%d%d",&xa,&ya);
 printf("second");
 scanf("%d%d",&xb,&yb);*/


 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(0,0);
 glutInitWindowSize(640,480);
 glutCreateWindow("DDA LINE");
 Init();
 glutDisplayFunc(Display);
 
 glutMouseFunc(mymouse);
 glutMainLoop();

 return 0;
}

