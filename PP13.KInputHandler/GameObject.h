#pragma once
#include <iostream>
#include "LoaderParams.h"


using namespace std;

class GameObject
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
protected:
	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}

};
//public:
//	void load(int x, int y, int width, int height,
//		std::string textureID);
//	void draw(SDL_Renderer* pRenderer);
//	virtual void update();
//	void clean();
//protected:
//	std::string m_textureID;
//	int m_currentFrame;
//	int m_currentRow;
//	int m_x;
//	int m_y;
//	int m_width;
//	int m_height;
