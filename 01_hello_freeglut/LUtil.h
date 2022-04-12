/**
 * @file LUtil.h
 * @author zk (zk@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef LUTIL_H
#define LUTIL_H

#include "LOpenGL.h"
#include <stdio.h>

//Screen Constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS = 60;

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool initGL();
/* 前提条件： -有效的 OpenGL 上下文 
发布条件： -初始化矩阵和清晰的颜色
-如果出现 OpenGL 错误，则向控制台报告 
-如果初始化时出错，则返回 false 副作用： 
-投影矩阵设置为单位矩阵 
-模型视图矩阵设置为单位矩阵 
-矩阵模式设置为模型视图 
-清除颜色设置为黑色 */ 

void update();
/* 前提条件： -无
后置条件： -每帧执行逻辑 
副作用： -无 */ 

void render();
/* 前提条件：-
有效的 OpenGL 上下文
-活动模型视图矩阵 
后置条件：
-渲染场景 
副作用： 
-清除颜色缓冲区
-交换前/后缓冲区 */
#endif
