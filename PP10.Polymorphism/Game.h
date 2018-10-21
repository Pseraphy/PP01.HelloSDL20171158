#include "Player.h"
#include "TextureManager.h"
#include <vector>
#include "Enemy.h"

class Game
{

public:

	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }



private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	int m_currentFrame;

	std::vector<GameObject*> m_gameObjects;


	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;

	//TextureManager m_textureManager;

	//SDL_Texture* m_pTexture; // the new SDL_Texture variable
	//SDL_Rect m_sourceRectangle; // 원본 사각형 
	//SDL_Rect m_destinationRectangle; // 대상 사각형 
};
