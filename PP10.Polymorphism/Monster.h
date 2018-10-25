#include "GameObject.h"

class Monster : public GameObject
{
public:
	void load(int x, int y, int width, int height, std::string texturID);
	void draw(SDL_Renderer* pRenderer);
	virtual void update();
	void clean();
	 
	int g=0;
};