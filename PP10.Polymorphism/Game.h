﻿#pragma once
#include "SDL.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Monster.h"
#include <vector>

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

	//GameObject m_go;
	//Player m_player;

	std::vector<GameObject*>m_gameObjects;

	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;
	GameObject* m_monster;

	int m_currentFrame;
	//TextureManager m_textureManager;

	//SDL_Texture* m_pTexture; // the new SDL_Texture variable
	//SDL_Rect m_sourceRectangle; // ¿øº» »ç°¢Çü 
	//SDL_Rect m_destinationRectangle; // ´ë»ó »ç°¢Çü 
};