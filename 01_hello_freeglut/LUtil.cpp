/**
 * @file LUtil.cpp
 * @author zk (zk@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "LUtil.h"


/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool initGL()
{
    //Initialize Projection Matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    //Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //Initialize clear color
    glClearColor( 0.f, 0.f, 0.f, 1.f );

    //Check for error
    GLenum error = glGetError();
    if( error != GL_NO_ERROR )
    {
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        return false;
    }

    return true;
}

/**
 * @brief 
 * 
 */
void update()
{

}

/**
 * @brief 
 * 
 */
void render()
{
    //Clear color buffer
    glClear( GL_COLOR_BUFFER_BIT );

    //Render quad
    glBegin( GL_QUADS );
        glVertex2f( -0.5f, -0.5f );
        glVertex2f(  0.5f, -0.5f );
        glVertex2f(  0.5f,  0.5f );
        glVertex2f( -0.5f,  0.5f );
    glEnd();

    //Update screen
    glutSwapBuffers();
}
