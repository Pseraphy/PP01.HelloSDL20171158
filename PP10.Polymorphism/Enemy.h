#include "GameObject.h"

class Enemy : public GameObject
{
public:
	void load(int x, int y, int width, int height, std::string texturID);
	void draw(SDL_Renderer* pRenderer);
	virtual void update();
	void clean();
	
	int g = 0;

	// bool 변수 한개 추가 , false  or ture 작동
};