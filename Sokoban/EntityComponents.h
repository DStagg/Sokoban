#ifndef ENTITYCOMPONENTS_H
#define ENTITYCOMPONENTS_H

#include "SFML\Graphics.hpp"
#include "ImageManager.h"

template <class T>
struct Pair
{
	Pair()
	{

	};
	Pair(T x, T y)
	{
		Set(x, y);
	};

	void Set(T x, T y)
	{
		_X = x;
		_Y = y;
	};

	T _X;
	T _Y;
};

typedef Pair<float> PairFloat;
typedef Pair<int> PairInt;

class Graphic
{
public:

	Graphic();
	Graphic(sf::Sprite spr);

	void AddAnimation(std::string tag, Animation anim);

	void Play(float dt);
	void Swap(std::string tag = "Static");

	std::string GetCurrentAnimName();
	Animation& GetCurrentAnim();
	AnimationFrame GetCurrentFrame();

	void SetSprite(sf::Sprite spr);
	sf::Sprite* GetSprPntr();

private:

	std::string _CurrentAnim = "Static";
	std::map <std::string, Animation > _Animations;
	sf::Sprite _Sprite;
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

#endif