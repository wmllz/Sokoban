#include "Renderer.h"

//全局变量
Renderer gRender;

Renderer::Renderer(){
	m_renderer = nullptr;
}

void Renderer::init( SDL_Renderer *renderer){
	m_renderer = renderer;
}

SDL_Texture *Renderer::createTextureFromSurface( SDL_Surface *surface ){
	return SDL_CreateTextureFromSurface(m_renderer, surface);
}

void Renderer::setRenderDrawColor( Uint8 r, Uint8 g, Uint8 b, Uint8 a ){
	SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
}

int Renderer::renderClear(){
	return SDL_RenderClear(m_renderer);
}

void Renderer::renderCopy( SDL_Texture *texture, 
	const SDL_Rect *srcrect, const SDL_Rect *dstrect ){
		SDL_RenderCopy(m_renderer, texture, srcrect, dstrect);
}

void Renderer::drawRect(const SDL_Rect &rect){
	SDL_RenderDrawRect(m_renderer, &rect);
}

void Renderer::renderPresent(){
	SDL_RenderPresent(m_renderer);
}


