#pragma once

#include <SDL3/SDL.h>
#include "ImageManager.h"
#include "core/Pair.h"
#include <map>
#include <string>

struct Sprite
{
	Sprite(SDL_Texture* tex = nullptr, SDL_FRect rect = SDL_FRect())
	{
		_Texture = tex;
		_SrcRect = rect;
	}

	SDL_Texture* _Texture;
	SDL_FRect _SrcRect;
};

class Graphic
{
public:

	Graphic();
	Graphic(Sprite spr);

	void AddAnimation(std::string tag, Animation anim);

	void Play(float dt);
	void Swap(std::string tag = "Static");

	std::string GetCurrentAnimName();
	Animation& GetCurrentAnim();
	AnimationFrame GetCurrentFrame();

	void SetSprite(Sprite spr);
	Sprite* GetSprPntr();

private:

	std::string _CurrentAnim = "Static";
	std::map <std::string, Animation > _Animations;
	Sprite _Sprite;
};

class Stats
{
public:

	Stats(int hp = 1);

	void SetHP(int hp);
	int GetHP();
	void SetMaxHP(int hp);
	int GetMaxHP();

	void Hurt(int hp);

private:

	int _CurrentHP;
	int _MaximumHP;
};
