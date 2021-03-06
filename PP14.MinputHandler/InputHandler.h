#pragma once
#include "SDL.h"
#include "Vector2D.h"
#include<vector>


class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	void update();
	bool isKeyDown(SDL_Scancode key);
	void clean();  // 디바이스 관련 초기화된 부분을 clear 

	enum mouse_buttons 
	{
		LEFT = 0,
		MIDDLE = 1,
		RIGHT = 2
	};

	bool getMouseButtonState(int buttonNumber);
	
	Vector2D* m_mousePosition;
	Vector2D * getMousePosition();

	void onKeyUp();
	void onKeyDown();
	void onMouseMove(SDL_Event & event);
	void onMouseButtonDown(SDL_Event & event);
	void onMouseButtonUp(SDL_Event & event);


	const Uint8* m_keystates;
	std::vector<bool>m_mouseButtonStates;

private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;

};
typedef InputHandler TheInputHandler;
