#include <ctime>
#include <windows.h>

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <sstream>
#include <queue>
#include <map>
#include <set>

using namespace std;

#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#ifndef M_PI
#define M_PI (3.1415926535897932384626433832795)
#define DEGTORAD(degree) ((degree) * (M_PI / 180.0f))
#define RADTODEG(radian) ((radian) * (180.0f / M_PI))
#endif

#ifdef WIN32
#define drand48() (((float) rand())/((float) RAND_MAX))
#define srand48(x) (srand((x)))
#define randomVal(min, max) ((float)(min + (max - min) * drand48()))
#endif

#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 512

