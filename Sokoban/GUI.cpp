#include "GUI.h"

GUIState::GUIState(int x, int y, int hot, int active, bool down)
{
	_MouseX = x;
	_MouseY = y;
	_HotItem = hot;
	_ActiveItem = active;
	_MouseDown = down;
};

/////////////////////

PairInt GUI::_Size;
sf::RenderWindow* GUI::_Window = 0;
sf::Font GUI::_Font;
sf::RenderTexture GUI::_TargetTexture;
GUIState GUI::_State;

void GUI::RegisterWindow(sf::RenderWindow* rw)
{
	_Window = rw;
	_Size.Set((int)rw->getSize().x, (int)rw->getSize().y);
	_TargetTexture.create((int)rw->getSize().x, (int)rw->getSize().y);
};

void GUI::RegisterFont(sf::Font f)
{
	_Font = f;
};

void GUI::StartFrame()
{
	GUI::GetTargetTexture().clear(sf::Color(0, 0, 0, 0));
	GUI::GetState()._HotItem = 0;
};

void GUI::EndFrame()
{
	if (!GUI::GetState()._MouseDown)
		GUI::GetState()._ActiveItem = 0;
	else if (GUI::GetState()._ActiveItem == 0)
		GUI::GetState()._ActiveItem = -1;
};

bool GUI::DoButton(int id, PairInt pos, PairInt size, std::string message)
{
	//	Check if hot & active
	if ((GUI::GetState()._MouseX >= pos._X) && (GUI::GetState()._MouseY >= pos._Y) && (GUI::GetState()._MouseX < pos._X + size._X) && (GUI::GetState()._MouseY < pos._Y + size._Y))
	{
		GUI::GetState()._HotItem = id;
		if ((GUI::GetState()._ActiveItem == 0) && (GUI::GetState()._MouseDown))
			GUI::GetState()._ActiveItem = id;
	}

	//	Render
	sf::RectangleShape rect;
	if ((GUI::GetState()._ActiveItem == id) && (GUI::GetState()._HotItem == id))
	{
		rect.setSize(sf::Vector2f((float)size._X, (float)size._Y));
		rect.setPosition(sf::Vector2f((float)pos._X+2.f, (float)pos._Y+2.f));
		rect.setFillColor(sf::Color::Blue);
	}
	else if (GUI::GetState()._HotItem == id)
	{
		rect.setSize(sf::Vector2f((float)size._X, (float)size._Y));
		rect.setPosition(sf::Vector2f((float)pos._X, (float)pos._Y));
		rect.setFillColor(sf::Color::Blue);
	}
	else
	{
		rect.setSize(sf::Vector2f((float)size._X, (float)size._Y));
		rect.setPosition(sf::Vector2f((float)pos._X, (float)pos._Y));
		rect.setFillColor(sf::Color::Cyan);
	};
	GetTargetTexture().draw(rect);

	sf::Text text(message, _Font);
	text.setPosition(pos._X, pos._Y);
	text.setScale(0.5f, 0.5f);
	GetTargetTexture().draw(text);

	//	Trigger
	if ((GUI::GetState()._ActiveItem == id) && (GUI::GetState()._HotItem == id) && (!GUI::GetState()._MouseDown))
		return true;
	
	return false;
};

PairInt& GUI::GetSize()
{
	return _Size;
};

sf::RenderTexture& GUI::GetTargetTexture()
{
	return _TargetTexture;
};

GUIState& GUI::GetState()
{
	return _State;
};