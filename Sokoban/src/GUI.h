#pragma once

#define GenID (__LINE__)

#include "core/Pair.h"
#include <string>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
/*
struct GUIState
{
	GUIState(int x = 0, int y = 0, int hot = 0, int active = 0, bool down = false);

	int _MouseX;
	int _MouseY;

	int _HotItem;
	int _ActiveItem;

	bool _MouseDown;
};

class GUI
{
public:

	static void RegisterWindow(SDL_Renderer* renderer);
	static void RegisterFont(TTF_Font* f);

	static void StartFrame();
	static void EndFrame();

	static bool DoButton(int id, PairInt pos, PairInt size, std::string label);
	static void DoFrame(int id, PairInt pos, PairInt size, sf::Color col);
	static void DoSlider(int id, PairInt pos, PairInt size, float& value, float max);
	
	static void Draw();

	static PairInt& GetSize();		
	static sf::RenderTexture& GetTargetTexture();
	static GUIState& GetState();

private:

	static PairInt _Size;			
	static SDL_Renderer* _Window;
	static TTF_Font* _Font;
	static sf::RenderTexture _TargetTexture;
	static GUIState _State;
};

//	Helper Functions	//
bool MouseInRect(PairInt pos, PairInt size);

*/