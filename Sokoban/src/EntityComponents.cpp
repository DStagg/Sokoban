#include "EntityComponents.h"

//	Graphic

Graphic::Graphic()
{
	
};
Graphic::Graphic(Sprite spr)
{
	SetSprite(spr);
};

void Graphic::AddAnimation(std::string tag, Animation anim)
{
	_Animations[tag] = anim;
};

void Graphic::Play(float dt)
{
	if (GetCurrentAnimName() == "Static")
		return;

	GetCurrentAnim().Play(dt);
	_Sprite._SrcRect.x = GetCurrentFrame()._X;
	_Sprite._SrcRect.y = GetCurrentFrame()._Y;
	_Sprite._SrcRect.w = GetCurrentFrame()._Width;
	_Sprite._SrcRect.h = GetCurrentFrame()._Height;
};

void Graphic::Swap(std::string tag)
{
	GetCurrentAnim()._CurrentFrame = 0;
	GetCurrentAnim()._Time = 0.f;

	_CurrentAnim = tag;

	if (tag == "Static")
	{
		_Sprite._SrcRect.x = 0.f;
		_Sprite._SrcRect.y = 0.f;
		if (_Sprite._Texture) _Sprite._SrcRect.w = _Sprite._Texture->w;
		else _Sprite._SrcRect.w = 1.0f;
		if (_Sprite._Texture) _Sprite._SrcRect.h = _Sprite._Texture->h;
		else _Sprite._SrcRect.h = 1.0f;
	}
}

std::string Graphic::GetCurrentAnimName()
{
	return _CurrentAnim;
};
Animation& Graphic::GetCurrentAnim()
{
	return _Animations[GetCurrentAnimName()];
};
AnimationFrame Graphic::GetCurrentFrame()
{
	if (GetCurrentAnimName() == "Static")
	{
		float w, h;
		if (_Sprite._Texture) w = _Sprite._Texture->w;
		else w = 1.0f;
		if (_Sprite._Texture) h = _Sprite._Texture->h;
		else h = 1.0f;
		return AnimationFrame(0.f, 0.f, w, h, 0.f);
	}

	return _Animations[GetCurrentAnimName()].GetCurrFrame();
};

void Graphic::SetSprite(Sprite spr)
{
	_Sprite = spr;
};

Sprite* Graphic::GetSprPntr()
{
	return &_Sprite;
};




//	Stats		//

Stats::Stats(int hp)
{
	SetHP(hp);
	SetMaxHP(hp);
};

void Stats::SetHP(int hp)
{
	_CurrentHP = hp;
};
int Stats::GetHP()
{
	return _CurrentHP;
};

void Stats::SetMaxHP(int hp)
{
	_MaximumHP = hp;
};
int Stats::GetMaxHP()
{
	return _MaximumHP;
};

void Stats::Hurt(int hp)
{
	SetHP(GetHP() - hp);
};