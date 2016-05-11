#include "Texture.h"

Texture::Texture(){
	m_texture = nullptr;
	m_height = 0;
	m_width = 0;
}

Texture::~Texture(){
	free();
}

bool Texture::loadFromFile(const std::string path){
	free();
	SDL_Texture *newTexture = nullptr;
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	
	if (loadedSurface == nullptr){
		printf("IMG_Load: %s\n", IMG_GetError());
	}else{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0x00, 0xFF, 0xFF));
		newTexture = gRender.createTextureFromSurface(loadedSurface);

		if (newTexture == nullptr){
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}else{
			m_width = loadedSurface->w;
			m_height = loadedSurface->h;
			m_texture = newTexture;
		}
		SDL_FreeSurface(loadedSurface);
	}
	return (m_texture != nullptr);
}

void Texture::setColor( Uint8 r, Uint8 g, Uint8 b ){
	SDL_SetTextureColorMod(m_texture, r, g, b);
}

void Texture::setAlpha( Uint8 a ){
	SDL_SetTextureAlphaMod(m_texture, a);
}

void Texture::setBlendMode( SDL_BlendMode blending ){
	SDL_SetTextureBlendMode(m_texture, blending);
}

void Texture::render( int x, int y, SDL_Rect *clip /*= nullptr*/ ){
	
	SDL_Rect renderQuad = {x, y, m_width, m_height};

	if (clip != nullptr){
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	gRender.renderCopy(m_texture, clip, &renderQuad);
	//gRender.renderPresent();
}

void Texture::free(){
	if (m_texture != nullptr){
		m_texture = nullptr;
		m_height = 0;
		m_width = 0;
	}
}

int Texture::getWidth(){
	return m_width;
}

int Texture::getHeight(){
	return m_height;
}
