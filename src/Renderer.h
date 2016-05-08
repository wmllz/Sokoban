/*
**封装renderer类用与渲染管理
*/
#ifndef RENDERER_H
#define RENDERER_H

#include <SDL/SDL.h>

#include "Texture.h"
#include "Renderer.h"

class Renderer{

public:
	Renderer();
	
	void init(SDL_Renderer *renderer);
	SDL_Texture *createTextureFromSurface(SDL_Surface *surface);
	void setRenderDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	int renderClear();
	void renderCopy(
		SDL_Texture *texture, 
		const SDL_Rect *srcrect,
		const SDL_Rect *dstrect);
	void renderPresent();

private:
	SDL_Renderer *m_renderer;	
};

extern Renderer gRender;
#endif