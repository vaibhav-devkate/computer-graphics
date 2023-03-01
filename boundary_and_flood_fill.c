#include<stdio.h>
#include<GL/glut.h>

int input[2][10];
int v,flag=0,n;

float background[3];
float colours[3][10],boundary_c[3];
int x,y;

float fill_c[3];


int roundoff(float a){
   
   return (a+0.5);

}
void DDA(int x1,int y1, int x2, int y2){

       int dx,dy,steps;
	dx=x2-x1;
	dy=y2-y1;
	
	if( abs(dx)> abs(dy)){
		steps=abs(dx);
	}
	else{
		steps=abs(dy);
	}
	
	float xinc,yinc;
	xinc=(float)(dx)/steps;
	yinc=(float)(dy)/steps;
	
	float x,y;
	x=x1;
	y=y1;
        glBegin(GL_POINTS);
        
	glVertex2d(roundoff(x),roundoff(y));
	
	while(steps){
		
		x=x+xinc;
		y=y+yinc;
		
		glVertex2d(roundoff(x),roundoff(y));
		steps--;
	}
        
}


void flood_fill(int x,int y,float back[3],float fill_c[3]){

      glClearColor(1,1,1,0);

      float color[3];
      
      glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
    
      
      if ( ( color[0]==back[0] &&  color[1]==back[1] &&  color[2]==back[2])  ){
      
          glColor3f(fill_c[0],fill_c[1],fill_c[2]);
          glBegin(GL_POINTS);
          glVertex2d(x,y);
          glEnd();
          glFlush();
          
          flood_fill(x+1,y,back,fill_c);
          flood_fill(x-1,y,back,fill_c);
          
          flood_fill(x,y+1,back,fill_c);
          flood_fill(x,y-1,back,fill_c);
      
      }
      
}
void boundary_fill(int x,int y,float boundary_color[3],float fill_color[3])
{
	float color[3];
	  glClearColor(1,1,1,0);
	glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);

	
	if((color[0]!= boundary_color[0]||color[1]!= boundary_color[1]||color[2] != boundary_color[2])&&(color[0] != fill_color[0] || color[1] != fill_color[1] || color[2] != fill_color[2]))
	{
		glColor3f(fill_color[0], fill_color[1], fill_color[2]);
		glBegin(GL_POINTS);
		glVertex2d(x,y);
	
		glEnd();
		glFlush();
		
		boundary_fill(x+1,y,boundary_color,fill_color);
		boundary_fill(x-1,y,boundary_color,fill_color);
		boundary_fill(x,y+1,boundary_color,fill_color);
		boundary_fill(x,y-1,boundary_color,fill_color); 
	}
}



void Display(){

   
   
   glClear(GL_COLOR_BUFFER_BIT);
   
   
   
    printf("Enter your choice:\n");
 printf("1.boundary fill\n");
 printf("2.flood fill \n");
 scanf("%d",&n);
 
  printf("\nEnter no. of vertices");
     scanf("%d",&v);
     
      for(int i=0;i<v;i++){
     
         printf("Enter x ");
         scanf("%d",&input[0][i]);
         printf("Enter y");
         scanf("%d",&input[1][i]);
         
         
     }
     
     
   
      
     printf("\nFill Color");
     for(int i=0;i<3;i++){
     
          scanf("%f",&fill_c[i]);
     }
     
     
 
 switch(n){
   case 1: flag=0;
 
    printf("enter boundary_color:");
         scanf("%e",&boundary_c[0]);
                  scanf("%e",&boundary_c[1]);
                           scanf("%e",&boundary_c[2]);
   break;
   case 2:flag=1;
    printf("\nEnter background Colour");
    
     
     for(int i=0;i<3;i++){
         scanf("%f",&background[i]);
         
     }
       for(int i=0;i<v;i++){
          
          printf("\nEnter Colour of %d line",i+1);
          
          scanf("%f",&colours[0][i]); 
          scanf("%f",&colours[1][i]);
          scanf("%f",&colours[2][i]);
     
     }
   break;
   case 3:exit(0);
   
 
 
   
 
   }

    
    
     
    
   //glVertex2d(100,100);
   int i=0;
   for(i=0;i<v-1;i++){
   
      if(flag==0){
        glColor3f(boundary_c[0],boundary_c[1],boundary_c[2]);
      
      }
      else{
         glColor3f(colours[0][i],colours[1][i],colours[2][i]);
      
      }
       gluOrtho2D(0,640,0,480);
   
       DDA(input[0][i],input[1][i],input[0][i+1],input[1][i+1]);
   }
  if(flag==0){
        glColor3f(boundary_c[0],boundary_c[1],boundary_c[2]);
      
      }
      else{
         glColor3f(colours[0][i],colours[1][i],colours[2][i]);
      
      }
   gluOrtho2D(0,640,0,480);
   
   DDA(input[0][i],input[1][i],input[0][0],input[1][1]);
   
  /// glEnd();
  // glFlush();
   
   
}
void mymouse(int b,int s,int x,int y){
   static int  xst,yst,pt=0;
   if(b==GLUT_LEFT_BUTTON && s==GLUT_DOWN){
    if(pt==0){
    xst=x;
    yst=y;
    pt++;
    
    }
    else{
         if(flag==0){
        
        
   boundary_fill(x,480-y,boundary_c,fill_c);
   }
   else
   { 
    flood_fill(x,480-y,background,fill_c);
   
   }
   xst=x;
   yst=y;
   
   
   }
 glEnd();
 glFlush();
 
}
}

int main(int argc,char **argv){
   

     
     
    
   //  printf("\nInside Pixel");
     //scanf("%d%d",&x,&y);
    
     glutInit(&argc,argv);
     
     glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
     glutInitWindowPosition(0,0);
     glutInitWindowSize(640,480);
     glutCreateWindow("Polygon Filling");
     
     glClearColor(background[0],background[1],background[2],0);
     
     glutDisplayFunc(Display);
     glutMouseFunc(mymouse);
     
     glutMainLoop();
     return 0;
}
