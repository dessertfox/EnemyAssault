#pragma once

#include <GL\glew.h>
#include <GL\glut.h>
#include <math.h>
#include <vector>
#include <map>
#include <forward_list>
#include "Vector2f.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FPS 1000 / 60
#define horizonX SCREEN_WIDTH / 2
#define horizonY SCREEN_HEIGHT / 2

#define DEG2RAD 3.14159/180;
#define FOREACH(it, container) for(auto it = container.begin(); it != container.end(); it++)

inline float DistanceBetween(Vector2f objectOne, Vector2f objectTwo)
{
	return sqrt(pow(objectTwo.x - objectOne.x, 2) + pow(objectTwo.y - objectOne.y, 2));
}