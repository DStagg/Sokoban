#pragma once

#include "core/Scene.h"
#include <SDL3/SDL.h>

class SDLScene : public Scene
{
public:

	SDLScene(SDL_Renderer* renderer)
	{
		_Window = renderer;
		RefreshDimensions();
	};

protected:

	void RefreshDimensions()
	{
		SDL_GetRenderOutputSize(_Window, &_Width, &_Height);
	}

	int _Width, _Height;
	
	SDL_Renderer* _Window;
};