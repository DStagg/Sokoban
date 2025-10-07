#include "SDLKeyboardTracker.h"

SDLKeyboardTracker* SDLKeyboardTracker::_Instance = nullptr;

SDLKeyboardTracker* SDLKeyboardTracker::K()
{
	if (_Instance == nullptr) _Instance = new SDLKeyboardTracker();
	return _Instance;
}

SDLKeyboardTracker::~SDLKeyboardTracker()
{
	delete _Instance;
}

bool SDLKeyboardTracker::GetKeyPressed(SDL_Keycode key)
{
	if (_Keys.find(key) != _Keys.end())
		return _Keys[key];
	return false;
}

void SDLKeyboardTracker::SetKeyPressed(SDL_Keycode key, bool state)
{
	_Keys[key] = state;
}