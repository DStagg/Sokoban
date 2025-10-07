#include <SDL3/SDL.h>

#include "ext/Timer.h"

#include "src/core/Scene.h"
#include "src/SokobanScene.h"

SDL_Window* _Window = nullptr;
SDL_Renderer* _Renderer = nullptr;
//MIX_Mixer* _Mixer = nullptr;

int main()
{
	Timer UpdateClock;

	SDL_CreateWindowAndRenderer("Sokoban", 624, 624, NULL, &_Window, &_Renderer);
	SDL_SetRenderDrawBlendMode(_Renderer, SDL_BLENDMODE_BLEND);
	SDL_SetDefaultTextureScaleMode(_Renderer, SDL_SCALEMODE_NEAREST);
	/*
	if (!TTF_Init())
	{
		std::cout << "Couldn't init SDL_TTF :" << SDL_GetError() << std::endl;
		return SDL_APP_FAILURE;
	}
	*/
	
	SceneManager SCM;
	SCM.PushScene(new SokobanScene(_Renderer));
	
	UpdateClock.Reset();
	while (SCM.GetActiveScenePntr() != 0)
	{
		SCM.GetActiveScenePntr()->Update(UpdateClock.Lap() / 1000.f);

		SDL_SetRenderDrawColor(_Renderer, 0, 0, 0, 255);
		SDL_RenderClear(_Renderer);
		SCM.GetActiveScenePntr()->DrawScreen();
		SDL_RenderPresent(_Renderer);
		SCM.CullScenes();
	}
	
	//TTF_Quit();
	SDL_DestroyRenderer(_Renderer);
	SDL_DestroyWindow(_Window);
	SDL_Quit();

	return SDL_APP_SUCCESS;
}