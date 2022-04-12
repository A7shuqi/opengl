/**
 * @file main.cpp
 * @author zk (zk@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "LUtil.h"

void runMainLoop( int val );
;/* 前提条件： -初始化 freeGLUT Post Condition：
 -调用 main 循环函数并将自身设置为在 1000 / SCREEN_FPS 
 毫秒内被回调 副作用：
  -Set glutTimerFunc 
  */
int main( int argc, char* args[] )
{
	//Initialize FreeGLUT
	glutInit( &argc, args );

	//Create OpenGL 2.1 context
	glutInitContextVersion( 2, 1 ); //在这里，我们将OpenGL上下文版本设置为2.1

	//Create Double Buffered Window
	glutInitDisplayMode( GLUT_DOUBLE ); //创建双缓冲窗口
		//在这里，我们将窗口设置为使用 glutInitDisplayMode（） 
	//进行双重缓冲。之后，我们调用 glutInitWindowSize（） 
	//来设置窗口尺寸。在设置了所有窗口属性之后，
	//使用 glutCreateWindow（） 
	//创建带有标题“OpenGL”的窗口。
	glutInitWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
	glutCreateWindow( "OpenGL" );


	//Do post window/context creation initialization
	if( !initGL() )
	{
		printf( "Unable to initialize graphics library!\n" );
		return 1;
	}

	//Set rendering function

	/*
	我们使用 glutDisplayFunc 设置渲染回调，
	因此每当 freeGLUT 需要更新屏幕时，
	它都会调用我们的 render（） 函数。*/
	glutDisplayFunc( render );

/*
在这里，我们调用 glutTimerFunc（） 
来设置计时器回调。
在 1000 / SCREEN_FPS 毫秒后，
调用 runMainLoop（）*/
	glutTimerFunc( 1000 / SCREEN_FPS, runMainLoop, 0 );

/*

我们启动 freeGLUT 主循环，以便它可以开始工作，
我们可以开始与应用程序交互。
这运行freeGLUT的内部主循环，而不是我们的主循环。
*/
	glutMainLoop();

	return 0;
}

void runMainLoop( int val )
{
    //Frame logic
    update();
    render();

    //Run frame one more time
    glutTimerFunc( 1000 / SCREEN_FPS, runMainLoop, val );
}
