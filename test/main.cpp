#include <stdlib.h>
#include<Windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>

#include<stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/GLAUX.h>

double a=0.0,b=0.0,c=55.0;
GLfloat	l_t=0;
GLfloat	l_t1=45;
GLuint texture[50];
GLUquadricObj *IDquadric;

int flag=0;

void LoadGLTextures()
{
	AUX_RGBImageRec* TextureImage;

	glGenTextures(20,texture);

	if (TextureImage = auxDIBImageLoad("C:\\Users\\anzum\\Desktop\\asha\\test\\bin\\Debug\\roof.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("C:\\Users\\anzum\\Desktop\\asha\\test\\bin\\Debug\\door.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("C:\\Users\\anzum\\Desktop\\asha\\test\\bin\\Debug\\wall.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("C:\\Users\\anzum\\Desktop\\asha\\test\\bin\\Debug\\g.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[3]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("C:\\Users\\anzum\\Desktop\\asha\\test\\bin\\Debug\\e3.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[4]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("C:\\Users\\anzum\\Desktop\\asha\\test\\bin\\Debug\\w.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[5]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("C:\\Users\\anzum\\Desktop\\asha\\test\\bin\\Debug\\sky.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[6]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("C:\\Users\\anzum\\Desktop\\asha\\test\\bin\\Debug\\im2.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[7]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("C:\\Users\\anzum\\Desktop\\asha\\test\\bin\\Debug\\t.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[8]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


	if (TextureImage = auxDIBImageLoad("C:\\Users\\anzum\\Desktop\\asha\\test\\bin\\Debug\\c2.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[9]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("C:\\Users\\anzum\\Desktop\\asha\\test\\bin\\Debug\\c1.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[10]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("C:\\Users\\anzum\\Desktop\\asha\\test\\bin\\Debug\\r1.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[11]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("C:\\Users\\anzum\\Desktop\\asha\\test\\bin\\Debug\\b2.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[12]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

    if (TextureImage = auxDIBImageLoad("C:\\Users\\anzum\\Desktop\\asha\\test\\bin\\Debug\\h1.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[13]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

    if (TextureImage = auxDIBImageLoad("C:\\Users\\anzum\\Desktop\\asha\\test\\bin\\Debug\\n.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[14]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	 if (TextureImage = auxDIBImageLoad("C:\\Users\\anzum\\Desktop\\asha\\test\\bin\\Debug\\sa.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[15]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


}


void quad()
{

       glBindTexture(GL_TEXTURE_2D, texture[2]);
           glBegin(GL_QUADS);


            //glColor3f(1.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f); glVertex3f(-1.0f,1.0f,2.0f);					// Top front Of The Quad (left)
            glTexCoord2f(1.0f,1.0f); glVertex3f(-1.0f,1.0f,-2.0f);					// Top back Of The Quad (left)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,-2.0f);					// Bottom back Of The Quad (left)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,-1.0f,2.0f);					// Bottom front Of The Quad (left)

            //glColor3f(0.0f,1.0f,0.0f);

            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,1.0f,2.0f);					    // Top front Of The Quad (right)
            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,1.0f,-2.0f);					    // Top back Of The Quad (right)
            glTexCoord2f(1.0f,0.0f); glVertex3f(1.0f,-1.0f,-2.0f);					// Bottom back Of The Quad (right)
            glTexCoord2f(0.0f,0.0f); glVertex3f(1.0f,-1.0f,2.0f);					// Bottom front Of The Quad (right)

            glEnd();

            glBindTexture(GL_TEXTURE_2D, texture[2]);
            glBegin(GL_QUADS);

            //glColor3f(1.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,1.0f,2.0f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,1.0f,-2.0f);					    // Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,1.0f,-2.0f);				    // Left back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,1.0f,2.0f);				    // Left front Of The Quad (top)


            //glColor3f(0.0f,1.0f,1.0f);
            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,-1.0f,2.0f);					// Right front Of The Quad (bottom)
            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,-1.0f,-2.0f);					// Right back Of The Quad (bottom)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,-2.0f);				    // Left back Of The Quad (bottom)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,-1.0f,2.0f);				    // Left front Of The Quad (bottom)

           glEnd();

            glBindTexture(GL_TEXTURE_2D, texture[2]);
            glBegin(GL_QUADS);

            //glColor3f(0.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,1.0f,-2.0f);					    // Top Right Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f); glVertex3f(-1.0f,1.0f,-2.0f);					// Top Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,-2.0f);					// Bottom Left Of The Quad (Back)
            glTexCoord2f(0.0f,0.0f); glVertex3f(1.0f,-1.0f,-2.0f);					// Bottom Right Of The Quad (Back)

            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,1.0f,2.0f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f); glVertex3f(-1.0f,1.0f,2.0f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,2.0f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f); glVertex3f(1.0f,-1.0f,2.0f);					// Bottom Right Of The Quad (Front)

        glEnd();

//roof
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glBegin(GL_QUADS);

            //glColor3f(0.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);
            glVertex3f(1.0f,1.0f,-1.99f);					    // Top Right Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f);
            glVertex3f(0.0f,2.5f,-1.99f);					// Top Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f);
            glVertex3f(-1.0f,1.0f,-1.99f);
            glTexCoord2f(0.0f,0.0f);
            glVertex3f(1.0f,1.0f,-1.99f);					// Bottom Left Of The Quad (Back)
            //glVertex3f(1.0f,-1.0f,1.0f);					// Bottom Right Of The Quad (Back)
            glTexCoord2f(0.0f,1.0f);
            glVertex3f(1.0f,1.0f,2.0f);					    // Top Right Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f);
            glVertex3f(0.0f,2.5f,2.0f);					// Top Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f);
            glVertex3f(-1.0f,1.0f,2.0f);
            glTexCoord2f(0.0f,0.0f);
            glVertex3f(1.0f,1.0f,2.0f);

        glEnd();


        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glBegin(GL_QUADS);

            //glColor3f(0.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);
            glVertex3f(1.0f,1.0f,2.0f);					    // Top Right Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f);
            glVertex3f(0.0f,2.5f,2.0f);					// Top Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f);
            glVertex3f(0.0f,2.5f,-2.0f);
            glTexCoord2f(0.0f,0.0f);
            glVertex3f(1.0f,1.0f,-2.0f);					// Bottom Left Of The Quad (Back)
            //glVertex3f(1.0f,-1.0f,1.0f);					// Bottom Right Of The Quad (Back)



            glTexCoord2f(0.0f,1.0f);
            glVertex3f(-1.0f,1.0f,2.0f);					    // Top Right Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f);
            glVertex3f(0.0f,2.5f,2.0f);					// Top Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f);
            glVertex3f(0.0f,2.5f,-2.0f);
            glTexCoord2f(0.0f,0.0f);
            glVertex3f(-1.0f,1.0f,-2.0f);

        glEnd();


//roof ends


//door
        glBindTexture(GL_TEXTURE_2D, texture[1]);
        glBegin(GL_QUADS);

            //glColor3f(0.0f,0.0f,1.0f);
            glTexCoord2f(1.0f,0.0f);
            glVertex3f(.30f,-1.0f,-2.1f);					    // Top Right Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f);
            glVertex3f(.30f,.5f,-2.1f);					// Top Left Of The Quad (Back)
            glTexCoord2f(0.0f,1.0f);
            glVertex3f(-0.30f,0.5f,-2.1f);
            glTexCoord2f(0.0f,0.0f);
            glVertex3f(-0.30f,-1.0f,-2.1f);				// Bottom Left Of The Quad (Back)

            glTexCoord2f(1.0f,0.0f);
            glVertex3f(.30f,-1.0f,02.001f);					    // Top Right Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f);
            glVertex3f(.30f,.5f,02.001f);					// Top Left Of The Quad (Back)
            glTexCoord2f(0.0f,1.0f);
            glVertex3f(-0.30f,0.5f,02.001f);
            glTexCoord2f(0.0f,0.0f);
            glVertex3f(-0.30f,-1.0f,02.001f);
					// Bottom Right Of The Quad (Front)

        glEnd();


//window
        glBindTexture(GL_TEXTURE_2D, texture[5]);
        glBegin(GL_QUADS);

            //glColor3f(0.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);
            glVertex3f(.9f,.7f,2.001f);					    // Top Right Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f);
            glVertex3f(.5f,.7f,2.001f);					// Top Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f);
            glVertex3f(.5f,0.0f,2.001f);
            glTexCoord2f(0.0f,0.0f);
            glVertex3f(.9f,.0f,2.001f);			// Bottom Left Of The Quad (Back)

            glTexCoord2f(0.0f,1.0f);
            glVertex3f(-.9f,.7f,2.001f);					    // Top Right Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f);
            glVertex3f(-.5f,.7f,2.001f);					// Top Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f);
            glVertex3f(-.5f,0.0f,2.001f);
            glTexCoord2f(0.0f,0.0f);
            glVertex3f(-.9f,.0f,2.001f);
					// Bottom Right Of The Quad (Front)

        glEnd();
}

void grass()
{
 glBindTexture(GL_TEXTURE_2D, texture[7]);
        glBegin(GL_QUADS);

             //glColor3f(0.82f,0.41f,.12f);

            glTexCoord2f(1.0f,1.0f);  glVertex3f(1.5f,-.1f,-2.5f);					    // Top Right Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f);    glVertex3f(-1.5f,-.1f,-2.5f);					// Top Left Of The Quad (Back)
            glTexCoord2f(0.0f,0.0f);     glVertex3f(-1.5f,.1f,-2.5f);					// Bottom Left Of The Quad (Back)
             glTexCoord2f(0.0f,1.0f);  glVertex3f(1.5f,.1f,-2.5f);


             glTexCoord2f(1.0f,1.0f); glVertex3f(1.5f,-.1f,2.5f);					    // Top Right Of The Quad (Back)
             glTexCoord2f(1.0f,0.0f); glVertex3f(-1.5f,-.1f,2.5f);					// Top Left Of The Quad (Back)
             glTexCoord2f(0.0f,0.0f); glVertex3f(-1.5f,.1f,2.5f);					// Bottom Left Of The Quad (Back)
            glTexCoord2f(0.0f,1.0f);  glVertex3f(1.5f,.1f,2.5f);
        glEnd();

 glBindTexture(GL_TEXTURE_2D, texture[7]);
        glBegin(GL_QUADS);

             //glColor3f(0.82f,0.41f,.12f);

               glTexCoord2f(1.0f,1.0f); glVertex3f(1.5f,-.1f,2.5f);					    // Top Right Of The Quad (Back)
             glTexCoord2f(1.0f,0.0f);   glVertex3f(1.5f,.1f,2.5f);
               glTexCoord2f(0.0f,0.0f); glVertex3f(1.5f,.1f,-2.5f);
              glTexCoord2f(0.0f,1.0f);  glVertex3f(1.5f,-.1f,-2.5f);


             glTexCoord2f(1.0f,1.0f);   glVertex3f(-1.5f,-.1f,2.5f);					    // Top Right Of The Quad (Back)
              glTexCoord2f(1.0f,0.0f);  glVertex3f(-1.5f,.1f,2.5f);
              glTexCoord2f(0.0f,0.0f);  glVertex3f(-1.5f,.1f,-2.5f);
               glTexCoord2f(0.0f,1.0f); glVertex3f(-1.5,-.1f,-2.5f);
        glEnd();


 glBindTexture(GL_TEXTURE_2D, texture[3]);
        glBegin(GL_QUADS);

            // glColor3f(0.82f,0.41f,.12f);

           glTexCoord2f(1.0f,1.0f);   glVertex3f(1.5f,.1f,2.5f);					    // Top Right Of The Quad (Back)
           glTexCoord2f(1.0f,0.0f);   glVertex3f(1.5f,.1f,-2.5f);
           glTexCoord2f(0.0f,0.0f);   glVertex3f(-1.5f,.1f,-2.5f);
           glTexCoord2f(0.0f,1.0f);   glVertex3f(-1.5f,.1f,2.5f);
       glEnd();


   glBindTexture(GL_TEXTURE_2D, texture[3]);

     glBegin(GL_QUADS);

          glTexCoord2f(1.0f,1.0f);   glVertex3f(1.5f,-.1f,2.5f);					    // Top Right Of The Quad (Back)
           glTexCoord2f(1.0f,0.0f);   glVertex3f(-1.5f,-.1f,2.5f);
           glTexCoord2f(0.0f,0.0f);   glVertex3f(-1.5f,-.1f,-2.5f);
           glTexCoord2f(0.0f,1.0f);   glVertex3f(1.5f,-.1f,-2.5f);

        glEnd();
}


void boat()
{

        glBegin(GL_QUADS);

             //glColor3f(0.82f,0.41f,.12f);

            glTexCoord2f(1.0f,0.0f);  glVertex3f(1.5f,-1.5f,-2.5f);					    // Top Right Of The Quad (Back)
            glTexCoord2f(0.0f,0.0f);    glVertex3f(-1.5f,-1.5f,-2.5f);					// Top Left Of The Quad (Back)
            glTexCoord2f(0.0f,1.0f);     glVertex3f(-1.5f,1.5f,-2.5f);					// Bottom Left Of The Quad (Back)
             glTexCoord2f(1.0f,1.0f);  glVertex3f(1.5f,1.5f,-2.5f);


             glTexCoord2f(1.0f,0.0f);glVertex3f(1.5f,-1.5f,2.5f);					    // Top Right Of The Quad (Back)
              glTexCoord2f(0.0f,0.0f); glVertex3f(-1.5f,-1.5f,2.5f);					// Top Left Of The Quad (Back)
             glTexCoord2f(0.0f,1.0f); glVertex3f(-1.5f,1.5f,2.5f);					// Bottom Left Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f);  glVertex3f(1.5f,1.5f,2.5f);
        glEnd();


        glBegin(GL_QUADS);

             //glColor3f(0.82f,0.41f,.12f);

               glTexCoord2f(1.0f,1.0f); glVertex3f(1.5f,-1.5f,2.5f);					    // Top Right Of The Quad (Back)
             glTexCoord2f(1.0f,0.0f);   glVertex3f(1.5f,1.5f,2.5f);
               glTexCoord2f(0.0f,0.0f); glVertex3f(1.5f,1.5f,-2.5f);
              glTexCoord2f(0.0f,1.0f);  glVertex3f(1.5f,-1.5f,-2.5f);


             glTexCoord2f(1.0f,1.0f);   glVertex3f(-1.5f,-1.5f,2.5f);					    // Top Right Of The Quad (Back)
              glTexCoord2f(1.0f,0.0f);  glVertex3f(-1.5f,1.5f,2.5f);
              glTexCoord2f(0.0f,0.0f);  glVertex3f(-1.5f,1.5f,-2.5f);
               glTexCoord2f(0.0f,1.0f); glVertex3f(-1.5,-1.5f,-2.5f);
        glEnd();



        glBegin(GL_QUADS);

            // glColor3f(0.82f,0.41f,.12f);

           glTexCoord2f(1.0f,1.0f);   glVertex3f(1.5f,1.5f,2.5f);					    // Top Right Of The Quad (Back)
           glTexCoord2f(1.0f,0.0f);   glVertex3f(1.5f,1.5f,-2.5f);
           glTexCoord2f(0.0f,0.0f);   glVertex3f(-1.5f,1.5f,-2.5f);
           glTexCoord2f(0.0f,1.0f);   glVertex3f(-1.5f,1.5f,2.5f);
       glEnd();

     glBegin(GL_QUADS);

          glTexCoord2f(1.0f,1.0f);   glVertex3f(1.5f,-1.5f,2.5f);					    // Top Right Of The Quad (Back)
           glTexCoord2f(1.0f,0.0f);   glVertex3f(-1.5f,-1.5f,2.5f);
           glTexCoord2f(0.0f,0.0f);   glVertex3f(-1.5f,-1.5f,-2.5f);
           glTexCoord2f(0.0f,1.0f);   glVertex3f(1.5f,-1.5f,-2.5f);

        glEnd();
}


void earth (void)
{
     glBindTexture(GL_TEXTURE_2D, texture[6]);
        glBegin(GL_QUADS);

            glTexCoord2f(1.0f,1.0f); glVertex3f(35.5f,35.5f,-50.1f);					// Top front Of The Quad (left)
            glTexCoord2f(1.0f,0.0f); glVertex3f(35.5f,-35.5f,-50.1f);					// Top back Of The Quad (left)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-35.5f,-35.5f,-50.1f);					// Bottom back Of The Quad (left)
            glTexCoord2f(0.0f,1.0f); glVertex3f(-35.5f,35.5f,-50.1f);

        glEnd();


    glBindTexture(GL_TEXTURE_2D, texture[6]);
        glBegin(GL_QUADS);

            glTexCoord2f(1.0f,1.0f); glVertex3f(35.5f,35.5f,50.1f);					// Top front Of The Quad (left)
            glTexCoord2f(1.0f,0.0f); glVertex3f(35.5f,-35.5f,50.1f);					// Top back Of The Quad (left)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-35.5f,-35.5f,50.1f);					// Bottom back Of The Quad (left)
            glTexCoord2f(0.0f,1.0f); glVertex3f(-35.5f,35.5f,50.1f);

        glEnd();
}

void cleanupQuadric(void) {

//gIuDeleteQuadric(IDquadric);
}


void building(void)
{



            glBegin(GL_QUADS);

            //glColor3f(1.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,2.0f,1.0f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,2.0f,-1.0f);					    // Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,2.0f,-1.0f);				    // Left back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,2.0f,1.0f);				    // Left front Of The Quad (top)


            //glColor3f(0.0f,1.0f,1.0f);
            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,-2.0f,1.0f);					// Right front Of The Quad (bottom)
            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,-2.0f,-1.0f);					// Right back Of The Quad (bottom)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-2.0f,-1.0f);				    // Left back Of The Quad (bottom)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,-2.0f,1.0f);				    // Left front Of The Quad (bottom)

           glEnd();


        glBegin(GL_QUADS);

            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,2.0f,-1.0f);					    // Top Right Of The Quad (Back)
            glTexCoord2f(0.0f,1.0f); glVertex3f(-1.0f,2.0f,-1.0f);					// Top Left Of The Quad (Back)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,-2.0f,-1.0f);					// Bottom Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f); glVertex3f(1.0f,-2.0f,-1.0f);					// Bottom Right Of The Quad (Back)

            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,2.0f,1.0f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(0.0f,1.0f); glVertex3f(-1.0f,2.0f,1.0f);					// Top Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,-2.0f,1.0f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(1.0f,-2.0f,1.0f);					// Bottom Right Of The Quad (Front)

        glEnd();


         glBegin(GL_QUADS);

            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,2.0f,1.0f);					    // Top Right Of The Quad (Back)
            glTexCoord2f(0.0f,0.0f); glVertex3f(1.0f,-2.0f,1.0f);					// Top Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f); glVertex3f(1.0f,-2.0f,-1.0f);					// Bottom Left Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,2.0f,-1.0f);					// Bottom Right Of The Quad (Back)

            glTexCoord2f(0.0f,1.0f); glVertex3f(-1.0f,-2.0f,1.0f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,2.0f,1.0f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,2.0f,-1.0f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f); glVertex3f(-1.0f,-2.0f,-1.0f);					// Bottom Right Of The Quad (Front)

        glEnd();


}


void building1(void)
{

    glBindTexture(GL_TEXTURE_2D, texture[0]);

            glBegin(GL_QUADS);

            //glColor3f(1.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,2.0f,1.0f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,2.0f,-1.0f);					    // Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,2.0f,-1.0f);				    // Left back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,2.0f,1.0f);				    // Left front Of The Quad (top)


            //glColor3f(0.0f,1.0f,1.0f);
            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,-2.0f,1.0f);					// Right front Of The Quad (bottom)
            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,-2.0f,-1.0f);					// Right back Of The Quad (bottom)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-2.0f,-1.0f);				    // Left back Of The Quad (bottom)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,-2.0f,1.0f);				    // Left front Of The Quad (bottom)

           glEnd();


        glBindTexture(GL_TEXTURE_2D, texture[11]);
        glBegin(GL_QUADS);

            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,2.0f,-1.0f);					    // Top Right Of The Quad (Back)
            glTexCoord2f(0.0f,1.0f); glVertex3f(-1.0f,2.0f,-1.0f);					// Top Left Of The Quad (Back)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,-2.0f,-1.0f);					// Bottom Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f); glVertex3f(1.0f,-2.0f,-1.0f);					// Bottom Right Of The Quad (Back)


        glEnd();


         glBindTexture(GL_TEXTURE_2D, texture[11]);
        glBegin(GL_QUADS);


          glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,2.0f,1.0f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(0.0f,1.0f); glVertex3f(-1.0f,2.0f,1.0f);					// Top Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,-2.0f,1.0f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(1.0f,-2.0f,1.0f);

          glEnd();


         glBindTexture(GL_TEXTURE_2D, texture[12]);
         glBegin(GL_QUADS);

            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,2.0f,1.0f);					    // Top Right Of The Quad (Back)
            glTexCoord2f(0.0f,0.0f); glVertex3f(1.0f,-2.0f,1.0f);					// Top Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f); glVertex3f(1.0f,-2.0f,-1.0f);					// Bottom Left Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,2.0f,-1.0f);					// Bottom Right Of The Quad (Back)

            glTexCoord2f(0.0f,1.0f); glVertex3f(-1.0f,-2.0f,1.0f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,2.0f,1.0f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,2.0f,-1.0f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f); glVertex3f(-1.0f,-2.0f,-1.0f);					// Bottom Right Of The Quad (Front)

        glEnd();


}


void hill(void)
{


            glBegin(GL_TRIANGLES);

            glTexCoord2f(0.0f,1.0f); glVertex3f(0.5f,0.0f,.5f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f); glVertex3f(0.0f,1.5f,.5f);					    // Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-.5f,0.0f,.5f);


            glTexCoord2f(0.0f,1.0f); glVertex3f(0.5f,0.0f,0.0f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f); glVertex3f(0.0f,1.5f,0.0f);					    // Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-.5f,0.0f,0.0f);
			    // Left front Of The Quad (bottom)

           glEnd();



       glBegin(GL_QUADS);

            glTexCoord2f(0.0f,1.0f); glVertex3f(0.5f,0.0f,.5f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f); glVertex3f(0.0f,1.5f,.5f);					    // Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f); glVertex3f(0.0f,1.5f,.0f);
            glTexCoord2f(1.0f,0.0f); glVertex3f(0.5f,0.0f,.0f);

            glTexCoord2f(0.0f,1.0f); glVertex3f(-0.5f,0.0f,.5f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f); glVertex3f(0.0f,1.5f,.5f);					    // Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f); glVertex3f(0.0f,1.5f,.0f);
            glTexCoord2f(1.0f,0.0f); glVertex3f(-0.5f,0.0f,.0f);
			    // Left front Of The Quad (bottom)

        glEnd();


        glBegin(GL_QUADS);

            glTexCoord2f(0.0f,1.0f); glVertex3f(0.5f,0.0f,.5f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f); glVertex3f(-0.5f,0.0f,.5f);
            glTexCoord2f(1.0f,1.0f); glVertex3f(-0.5f,0.0f,.0f);					    // Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f); glVertex3f(0.5f,0.0f,.0f);


        glEnd();


}

void hill2(void)
{
      glBegin(GL_QUADS);

            glTexCoord2f(0.0f,1.0f); glVertex3f(0.1f,0.0f,.5f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f); glVertex3f(-0.1f,0.0f,.5f);
            glTexCoord2f(1.0f,1.0f); glVertex3f(-0.1f,1.0f,.5f);					    // Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f); glVertex3f(0.1f,1.0f,.5f);


        glEnd();


}

void hill3(void)
{


        glBegin(GL_TRIANGLES);

            glTexCoord2f(1.0f,0.0f); glVertex3f(0.5f,0.0f,1.0f);					    // Right front Of The Quad (top)
            glTexCoord2f(.5f,1.0f); glVertex3f(0.0f,1.5f,.5f);					    // Right back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-.5f,0.0f,1.0f);


            glTexCoord2f(1.0f,0.0f); glVertex3f(0.5f,0.0f,-1.0f);					    // Right front Of The Quad (top)
            glTexCoord2f(.5f,1.0f); glVertex3f(0.0f,1.5f,.5f);					    // Right back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-.5f,0.0f,-1.0f);


            glTexCoord2f(1.0f,0.0f); glVertex3f(0.5f,0.0f,1.0f);
            glTexCoord2f(0.5f,1.0f); glVertex3f(0.0f,1.5f,0.5f);				    					    // Right back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f); glVertex3f(0.5f,0.0f,-1.0f);


            glTexCoord2f(1.0f,0.0f); glVertex3f(-0.5f,0.0f,1.0f);					    // Right front Of The Quad (top)
            glTexCoord2f(.5f,1.0f); glVertex3f(0.0f,1.5f,.5f);					    // Right back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f); glVertex3f(-.5f,0.0f,-1.0f);


           glEnd();


        glBegin(GL_QUADS);

            glTexCoord2f(0.0f,1.0f); glVertex3f(0.5f,0.0f,1.0f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f); glVertex3f(-0.5f,0.0f,1.0f);
            glTexCoord2f(1.0f,1.0f); glVertex3f(-0.5f,0.0f,-1.0f);					    // Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f); glVertex3f(0.5f,0.0f,-1.0f);


        glEnd();



}


void init(void)
{

   LoadGLTextures();
   //glClearColor (0.39, 0.78, 0.52, 0.0);

    IDquadric=gluNewQuadric();
    gluQuadricNormals(IDquadric, GLU_SMOOTH);
    gluQuadricTexture(IDquadric, GL_TRUE);
    atexit(cleanupQuadric);
}



void display(void)
{

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);      // GL_COLOR_BUFFER_BIT indicates that the buffer is currently enabled for color writing
   glMatrixMode(GL_PROJECTION);       // Specify which matrix is the current matrix mode
   glLoadIdentity();                  // Replace the current matrix with the identity matrix
   int w=glutGet(GLUT_WINDOW_WIDTH);
   int h=glutGet(GLUT_WINDOW_HEIGHT);
   gluPerspective(40,w/h,0.1,150);    // fovy specifies the field of view angle in degrees in y direction, aspect specifies aspect ratio that determines the field of view in the x direction, znear and zfar specifies the distance from viewer to the near and far clipping plane respectively (always positive)
   glMatrixMode(GL_MODELVIEW);       //  To allow transformation on 3D object

   glLoadIdentity();
   gluLookAt(                       //  eyex, eyey, eyez specify the position of the eye point, centerx, centery, centerz specify the position of reference point, upx, upy, upz specify the direction of up vector
               a,b,c,
               0,0,0,
               0,1,0
             );

//background

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    earth();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();




//earth
glPushMatrix();
//glRotatef(l_t,0.0f,1.0f,0.0f);

 if (flag==1)
 {
     glRotatef(l_t,0.0f,1.0f,0.0f);
 }

 else if (flag==2)
 {
      glRotatef(l_t,1.0f,0.0f,0.0f);
 }
 else
  {
      glRotatef(l_t,0.0f,0.0f,1.0f);
  }


glScalef(1,.95,1);

glPushMatrix();
     //glRotatef(l_t,1.0f,0.0f,0.0f);
     glTranslatef(0.0f,-1.0f,0.0f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[4]);
    gluSphere(IDquadric,10,32,32);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


glPushMatrix();
//glRotatef(l_t,1.0f,0.0f,0.0f);
//house 1
glPushMatrix();

    glPushMatrix();
    glTranslatef(-1.65f,9.8f,1.0f);
    glEnable(GL_TEXTURE_2D);
    quad();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


 glPushMatrix();
      glTranslatef(-1.65f,8.8f,1.0f);
glEnable(GL_TEXTURE_2D);
    grass();
glDisable(GL_TEXTURE_2D);
 glPopMatrix();

glPopMatrix();


//house2
glPushMatrix();
glScalef(2,2,1);

    glPushMatrix();
    glTranslatef(0.65f,5.4f,1.0f);
    glEnable(GL_TEXTURE_2D);
    quad();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


 glPushMatrix();
      glTranslatef(0.65f,4.4f,1.0f);
glEnable(GL_TEXTURE_2D);
    grass();
glDisable(GL_TEXTURE_2D);
 glPopMatrix();

 glPopMatrix();


//trees

//front
    glPushMatrix();
    glTranslatef(1.0f,8.5f,4.0f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    gluSphere(IDquadric,1,50,50);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.6f,8.2f,3.8f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    gluSphere(IDquadric,1,50,50);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

     glPushMatrix();
    glTranslatef(2.2f,8.5f,3.8f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    gluSphere(IDquadric,1,50,50);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.0f,8.0f,3.5f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    gluSphere(IDquadric,1.5,50,50);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-2.0f,7.5f,3.5f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    gluSphere(IDquadric,1.5,50,50);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-4.0f,8.5f,2.5f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    gluSphere(IDquadric,1.5,50,50);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-4.0f,8.5f,2.5f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    gluSphere(IDquadric,1.5,50,50);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-3.5f,8.6f,1.0f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    gluSphere(IDquadric,1,50,50);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-3.5f,8.8f,-0.5f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    gluSphere(IDquadric,1,50,50);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-3.5f,8.5f,-1.5f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    gluSphere(IDquadric,1.5,50,50);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(4.0f,8.5f,-2.0f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    gluSphere(IDquadric,1.5,50,50);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();



    glPushMatrix();
    glTranslatef(2.0f,8.5f,-2.0f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    gluSphere(IDquadric,1,50,50);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(4.5f,8.5f,-0.0f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    gluSphere(IDquadric,1,50,50);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

glPopMatrix();
//trees ends

glPushMatrix();

    glScalef(.95,1.2,1);
//city
    glPushMatrix();
    glRotatef(-90,0.0f,0.0f,1.0f);

    glTranslatef(0.0f,11.7f,1.0f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[9]);
    building();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    glPushMatrix();
    glRotatef(-90,0.0f,0.0f,1.0f);
    glTranslatef(3.0f,11.2f,0.5f);
    glScalef(2,1,1);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[10]);
    building();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    glPushMatrix();
    glRotatef(-90,0.0f,0.0f,1.0f);
    glTranslatef(-2.5f,10.5f,0.8f);
    glScalef(1.5,.7,1);
    glEnable(GL_TEXTURE_2D);
    building1();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


    glPushMatrix();
    glRotatef(-90,0.0f,0.0f,1.0f);
    glTranslatef(-2.0f,9.5f,0.8f);
    glScalef(1.2,2.5,1);
    glBindTexture(GL_TEXTURE_2D, texture[12]);
    glEnable(GL_TEXTURE_2D);
    building();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

//tree1

glPushMatrix();

    glRotatef(-90,0.0f,0.0f,1.0f);
    glTranslatef(-4.5f,-1.7f,-6.2f);


    glPushMatrix();
    //glRotatef(-90,0.0f,0.0f,1.0f);
    glTranslatef(0.5f,10.6f,8.0f);
    glScalef(1.5,1.7,1);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    glEnable(GL_TEXTURE_2D);
    hill();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5f,9.9f,7.75f);
    glBindTexture(GL_TEXTURE_2D, texture[7]);
    glEnable(GL_TEXTURE_2D);
    hill2();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
glPopMatrix();


glPushMatrix();

    glRotatef(-90,0.0f,0.0f,1.0f);
    glTranslatef(4.0f,-1.0f,-6.2f);


    glPushMatrix();
    //glRotatef(-90,0.0f,0.0f,1.0f);
    glTranslatef(0.5f,10.6f,8.0f);
    glScalef(1.5,1.7,1);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    glEnable(GL_TEXTURE_2D);
    hill();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5f,9.9f,7.75f);
    glBindTexture(GL_TEXTURE_2D, texture[7]);
    glEnable(GL_TEXTURE_2D);
    hill2();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
glPopMatrix();


glPushMatrix();

    glRotatef(-90,0.0f,0.0f,1.0f);
    glTranslatef(.8f,-.4f,-6.2f);


    glPushMatrix();
    //glRotatef(-90,0.0f,0.0f,1.0f);
    glTranslatef(0.5f,10.6f,8.0f);
    glScalef(1.5,1.7,1);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    glEnable(GL_TEXTURE_2D);
    hill();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5f,9.9f,7.75f);
    glBindTexture(GL_TEXTURE_2D, texture[7]);
    glEnable(GL_TEXTURE_2D);
    hill2();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
glPopMatrix();




//trees2

glPushMatrix();

    glRotatef(-90,0.0f,0.0f,1.0f);
    glTranslatef(-4.5f,-1.7f,-9.2f);


    glPushMatrix();
    //glRotatef(-90,0.0f,0.0f,1.0f);
    glTranslatef(0.5f,10.6f,8.0f);
    glScalef(1.5,1.7,1);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    glEnable(GL_TEXTURE_2D);
    hill();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5f,9.9f,7.75f);
    glBindTexture(GL_TEXTURE_2D, texture[7]);
    glEnable(GL_TEXTURE_2D);
    hill2();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
glPopMatrix();


glPushMatrix();

    glRotatef(-90,0.0f,0.0f,1.0f);
    glTranslatef(4.0f,-1.0f,-9.2f);


    glPushMatrix();
    //glRotatef(-90,0.0f,0.0f,1.0f);
    glTranslatef(0.5f,10.6f,8.0f);
    glScalef(1.5,1.7,1);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    glEnable(GL_TEXTURE_2D);
    hill();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5f,9.9f,7.75f);
    glBindTexture(GL_TEXTURE_2D, texture[7]);
    glEnable(GL_TEXTURE_2D);
    hill2();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
glPopMatrix();


glPushMatrix();

    glRotatef(-90,0.0f,0.0f,1.0f);
    glTranslatef(-1.5f,-.4f,-9.2f);


    glPushMatrix();
    //glRotatef(-90,0.0f,0.0f,1.0f);
    glTranslatef(0.5f,10.6f,8.0f);
    glScalef(1.5,1.7,1);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    glEnable(GL_TEXTURE_2D);
    hill();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5f,9.9f,7.75f);
    glBindTexture(GL_TEXTURE_2D, texture[7]);
    glEnable(GL_TEXTURE_2D);
    hill2();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
glPopMatrix();

glPopMatrix();


//hills
glPushMatrix();
    glRotatef(90,0.0f,0.0f,1.0f);
    glTranslatef(-1.0f,9.0f,2.0f);

    glScalef(4.5,3,1.5);
    glBindTexture(GL_TEXTURE_2D, texture[13]);
    glEnable(GL_TEXTURE_2D);
    hill3();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


glPushMatrix();
    glRotatef(90,0.0f,0.0f,1.0f);
    glTranslatef(2.0f,8.5f,2.2f);

    glScalef(3.5,2.5,1.5);
    glBindTexture(GL_TEXTURE_2D, texture[13]);
    glEnable(GL_TEXTURE_2D);
    hill3();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


glPushMatrix();
    glRotatef(90,0.0f,0.0f,1.0f);
    glTranslatef(-4.0f,8.5f,1.8f);

    glScalef(3.5,2.5,1.5);
    glBindTexture(GL_TEXTURE_2D, texture[13]);
    glEnable(GL_TEXTURE_2D);
    hill3();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


glPushMatrix();
    glRotatef(90,0.0f,0.0f,1.0f);
    glTranslatef(0.6f,8.5f,3.5f);

    glScalef(3.5,2,1);
    glBindTexture(GL_TEXTURE_2D, texture[13]);
    glEnable(GL_TEXTURE_2D);
    hill3();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


glPushMatrix();
    glRotatef(90,0.0f,0.0f,1.0f);
    glTranslatef(-2.6f,8.5f,3.5f);

    glScalef(3.5,2,1);
    glBindTexture(GL_TEXTURE_2D, texture[13]);
    glEnable(GL_TEXTURE_2D);
    hill3();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


 glPushMatrix();
    glTranslatef(-8.6f,3.0f,4.0f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    gluSphere(IDquadric,1,50,50);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

 glPushMatrix();
    glTranslatef(-8.9f,3.8f,2.3f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    gluSphere(IDquadric,1.5,50,50);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


glPushMatrix();
    glTranslatef(-7.8f,-6.0f,3.5f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    gluSphere(IDquadric,1.0,50,50);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


glPushMatrix();
    glTranslatef(-8.0f,-4.5f,4.0f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    gluSphere(IDquadric,1.5,50,50);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

glPopMatrix();
//hill ends


//boat starts


glPushMatrix();

    glRotatef(l_t1,1.0f,0.0f,0.0f);
    glScalef(1,1,.5);
    glBindTexture(GL_TEXTURE_2D, texture[15]);
    glEnable(GL_TEXTURE_2D);
    boat();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();




 if (flag!=3)
 {
      l_t =l_t+0.2;
      l_t1 =l_t1+0.1;
      glutPostRedisplay();
 }


   glFlush(); // Force execution of GL commands in finite time

}

void my_keyboard(unsigned char key, int p, int q)
{
switch (key)
{
    case 'f':  //front view
        a=0.0,b=0.0,c=45.0,l_t=0;
        glutPostRedisplay();
		break;
    case 'l':  //left view
        a=-45.0,b=0.0,c=5.0,l_t=0.0;
        glutPostRedisplay();
		break;
    case 'r':  //right view
        a=45.0,b=0.0,c=5.0,l_t=0.0;
        glutPostRedisplay();
		break;
    case 'b':  //back view
        a=0.0,b=-45,c=-5.0,l_t=0.0;
        glutPostRedisplay();
		break;
    case 't': //top view
        a=0.0,b=45.0,c=5.0,l_t=0.0;
        glutPostRedisplay();
		break;

    case 'm': //bottom view
        a=0.0,b=-45.0,c=5.0,l_t=0.0;
        glutPostRedisplay();
		break;

    case 'p': //bottom view
        flag=1;
        glutPostRedisplay();

		break;

    case 'q': //bottom view
        flag=2;
        glutPostRedisplay();

		break;

     default:
        break;
}
}

void spinDisplay_left(void)		//spin speed
{
    flag=3;
    l_t=0;
    glutPostRedisplay();

}

void spinDisplay_right(void)		//spin speed
{
     flag=0;
     glutPostRedisplay();

}

void specialKeys(int key,int x,int y)
{

   if(key==GLUT_KEY_UP)
   {
       if(c>=-40.0)
       c--;

   }

   else if(key==GLUT_KEY_DOWN)
   {
       if(c<=45)
       c++;

   }

    glutPostRedisplay();
}

void mouse(int button, int state, int s, int t)
{

   switch (button)
   {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay_left);
         break;
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay_right);
         break;
      default:
         break;
   }
}

int main()
{
    PlaySound("kids_for_saving_earth_promise_song.wav", NULL, SND_FILENAME| SND_ASYNC | SND_LOOP);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (850, 700);
	glutInitWindowPosition (250, 20);
	glutCreateWindow ("Save Planet");
	//glutFullScreen();
	init();
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glEnable(GL_DEPTH_TEST);
    glutKeyboardFunc(my_keyboard);
    glutMouseFunc(mouse);

	glutMainLoop();
	return 0;
}
