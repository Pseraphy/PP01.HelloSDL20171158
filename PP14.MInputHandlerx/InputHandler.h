#pragma once
#include "SDL.h"
#include "Vector2D.h"
#include <vector>

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
	enum mouse_buttons
	{
		LEFT = 0,
		MIDDLE = 1,
		RIGHT = 2
	};

	Vector2D* m_mousePosition;
	Vector2D * getMousePosition();
	bool getMouseButtonState(int buttonNumber);
	std::vector<bool> m_mouseButtonStates;

	void update();
	bool isKeyDown(SDL_Scancode key);
	void clean(); 
	const Uint8* m_keystates;
private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;

	
};
typedef InputHandler TheInputHandler;
