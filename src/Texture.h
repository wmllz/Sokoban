#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>

#include "Renderer.h"
class Texture{
public:
	Texture();
	~Texture();
	
	bool loadFromFile(const std::string path);

	void setColor(Uint8 r, Uint8 g, Uint8 b);
	void setAlpha(Uint8 a);
	void setBlendMode(SDL_BlendMode blending);
	void render(int x, int y, SDL_Rect *clip = nullptr);
	void free();
	int getWidth();
	int getHeight();
	 
private:
	int m_height;
	int m_width;
	SDL_Texture *m_texture;
};
#endif