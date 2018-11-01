//#include "GameObject.h"
#pragma once
#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	/*void load(int x, int y, int width, int height, std::string texturID);
	void draw(SDL_Renderer* pRenderer);
	virtual void update();
	void clean();*/

	//int g = 0;

	// bool 변수 한개 추가 , false  or ture 작동
};