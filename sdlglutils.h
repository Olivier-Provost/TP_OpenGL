#ifndef SDLGLUTILS_H
#define SDLGLUTILS_H

#include <GL/gl.h>
#include <SDL2/SDL.h>

#ifndef GL_CLAMP_TO_EDGE
#define GL_CLAMP_TO_EDGE 0x812F
#endif

SDL_Surface * flipSurface(SDL_Surface* surface);
GLuint loadTexture(const char* filename, bool useMipMap = true);
void drawAxis(double scale = 1);


#endif //SDLGLUTILS_H
