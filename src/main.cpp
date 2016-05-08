#include <iostream>
#include <string>
#include "SDLUtils.h"
#include "Renderer.h"
#include "Texture.h"
#include "Cell.h"

using namespace std;
 
int main(int argc, char *argv[]){

	string winName("Sokoban");

	if (!initSDL(winName)){
		return -1;
	}


	system("pause");
	
	closeSDL();
	return 0;
}