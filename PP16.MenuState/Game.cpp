#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include <SDL_image.h>
#include "TextureManager.h"
#include "InputHandler.h"
#include "GameStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"

Game* Game::s_pInstance = 0;
InputHandler* InputHandler::s_pInstance = 0;
PlayState* PlayState::s_pInstance = 0;
MenuState* MenuState::s_pInstance = 0;


bool Game::init(const char* title, int xpos, int ypos,
	int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		m_bRunning = true;

		// load �κ� ��ġ   
		if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
		{
			return false;
		}


		m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
		m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));
		m_pGameStateMachine = new GameStateMachine();
		//m_pGameStateMachine->changeState(MenuState::Instance());/////////////
		m_pGameStateMachine->changeState(MenuState::Instance());



	}
	else {
		return false; // sdl could not initialize

	}
	return true;

}
//void Game::update()
//{
//	for (std::vector<GameObject*>::size_type i = 0;
//		i != m_gameObjects.size(); i++)
//	{
//		m_gameObjects[i]->update();
//	}
//}
//void Game::render()
//{
//	SDL_RenderClear(m_pRenderer); // clear to the draw colour
//	for (std::vector<GameObject*>::size_type i = 0;
//		i != m_gameObjects.size(); i++)
//	{
//		m_gameObjects[i]->draw();
//	}
//	SDL_RenderPresent(m_pRenderer); // draw to the screen
//}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	m_pGameStateMachine->render();
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
	m_pGameStateMachine->update();
}

void Game::clean()
{
	std::cout << "cleanig game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	TheInputHandler::Instance()->clean();
	SDL_Quit();
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(PlayState::Instance());
	}

	TheInputHandler::Instance()->update();
}
