# include<stdio.h>
# include<GL/glut.h>
# include<math.h>

int input[2][10],t[3][3],output[3][10],tx,ty,array[3][10];
int v,x,y;
float boundary_c[3];
float fill_c[3];

int ROUND(float a)
{
	return(int)(a+0.5);
}
void DDALine(int x1,int y1,int x2,int y2)
{
	int dx,dy,steps;
	dx=x2-x1;
	dy=y2-y1;
	
	if(abs(dx)>abs(dy))
	{
		steps=abs(dx);
	}
	else
	{
		steps=abs(dy);
	}
	
	float xinc,yinc;
	xinc=(float)(dx)/steps;
	yinc=(float)(dy)/steps;
	
	float x=x1,y=y1;
	glVertex2d(ROUND(x),ROUND(y));
	for(int i=0;i<steps;i++)
	{
		x=x+xinc;
		y=y+yinc;
		glVertex2d(ROUND(x),ROUND(y));
	}
}

/*void boundary_fill(int x,int y,float boundary_c[3],float fill_c[3])
{
	float color[3];
	
	glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
	
	if((color[0]!=boundary_c[0]) || (color[1]!=boundary_c[1]) || (color[2]!=boundary_c[2]))
	{
		
		glBegin(GL_POINTS);
		glVertex2d(x,y);
		glColor3f(fill_c[0],fill_c[1],fill_c[2]);
		glEnd();
		glFlush();
		boundary_fill(x+1,y,boundary_c,fill_c);
		boundary_fill(x-1,y,boundary_c,fill_c);
		boundary_fill(x,y+1,boundary_c,fill_c);
		boundary_fill(x,y-1,boundary_c,fill_c);
		
		
	}
	
	/*for(int i=0;i<3;i++)
	{
		printf("%f\t",color[i]);
	}
	
}*/
void Init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	//glColor3f(boundary_c[0],boundary_c[1],boundary_c[2]);
	
	gluOrtho2D(0,640,0,480);
}
void translation(){
      
      printf("\ntx:");
      scanf("%d",&tx);
      printf("\nty");
      scanf("%d",&ty);
      for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
      
      if(i==j){
      
      t[i][j]=1;
      
      }
      else{
      
      t[i][j]=0;
      }
      t[0][2]=tx;
      t[1][2]=ty;
   
   
   }

}}
void matrix(int array[3][10]){

   for(int i=0;i<3;i++){
   for(int j=0;j<v;j++){
   
   printf("%d\t",array[i][j]);
   
   
   
   }
   printf("\n");

}

}
void multiplication(){

  for(int i=0;i<3;i++){
  for(int j=0;j<v;j++){
  
  output[i][j]=0;
  for(int k=0;k<v;k++){
    
    output[i][j]+=t[i][k]*input[k][j];
    
    
  }
  
  
  }
  
  
  }

   





}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	//DDALine(100,100,200,200);
	int i;
	glColor3f(1,0,0);
	for(i=0;i<v-1;i++)
	{
		DDALine(input[0][i],input[1][i],input[0][i+1],input[1][i+1]);
	}
	
	DDALine(input[0][i],input[1][i],input[0][0],input[1][0]);
	
	
	//boundary_fill(x,y,boundary_c,fill_c);
	//glVertex2d(100,100);
	translation();
	multiplication();
	
	
	glColor3f(0,0,1);
	for(i=0;i<v-1;i++)
	{
		DDALine(output[0][i],output[1][i],output[0][i+1],output[1][i+1]);
	}
	
	DDALine(output[0][i],output[1][i],output[0][0],output[1][0]);
	
	matrix(input);
	for(int i=0;i<3;i++){
   for(int j=0;j<3;j++){
   
   printf("%d\t",t[i][j]);
   
   
   
   }
   printf("\n");

}
	
	matrix(output);
	
	glEnd();
	glFlush();
	//boundary_fill(x,y,boundary_c,fill_c);
}



int main(int argc, char **argv)
{
	//int input[2][10];
	//int v;
	
	printf("\nVertices");
	scanf("%d",&v);
	
	for(int i=0;i<v;i++)
	{
		printf("\nx_coordinates");
		scanf("%d",&input[0][i]);
		printf("\ny_coordinates");
		scanf("%d",&input[1][i]);
		input[2][i]=1;
	}
	
	/*for(int i=0;i<3;i++)
	{
		printf("\nBoundary Color");
		scanf("%f",&boundary_c[i]);
	}
	
	float x,y;
	float fill_c[3];
	printf("\nInside Pixel");
	scanf("%f%f",&x,&y);
	
	for(int i=0;i<3;i++)
	{
		printf("\nFill Color");
		scanf("%f",&fill_c[i]);
	}*/
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);
	glutCreateWindow("2D_transformation");
	Init();
	glutDisplayFunc(display);
	glutMainLoop();
}
