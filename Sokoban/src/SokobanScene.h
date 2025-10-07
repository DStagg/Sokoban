#pragma once

#include <SDL3/SDL.h>
#include "SDLScene.h"
#include "ImageManager.h"
#include "Level.h"
#include "GameEnts.h"
#include "GUI.h"
#include <iostream>

class SokobanScene : public SDLScene
{
public:

	SokobanScene(SDL_Renderer* renderer);
	~SokobanScene();

	void Begin();
	void End();
	void Pause();
	void Resume();
	void Update(float dt);
	void DrawScreen();
	
private:

	Level _Level;
	ImageManager _ImgMan;

	float _TestInt;
};
