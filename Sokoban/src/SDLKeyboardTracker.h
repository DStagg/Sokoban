#pragma once

#include <SDL3/SDL.h>
#include <map>

#define IsKeyPressed(x) SDLKeyboardTracker::K()->GetKeyPressed(x)
#define PressKey(x) SDLKeyboardTracker::K()->SetKeyPressed(x, true);
#define ReleaseKey(x) SDLKeyboardTracker::K()->SetKeyPressed(x, false);

class SDLKeyboardTracker
{
public:

	static SDLKeyboardTracker* K();
	~SDLKeyboardTracker();

	bool GetKeyPressed(SDL_Keycode key);
	void SetKeyPressed(SDL_Keycode key, bool state);

private:

	SDLKeyboardTracker() {};
	static SDLKeyboardTracker* _Instance;

	std::map<SDL_Keycode, bool> _Keys;
};