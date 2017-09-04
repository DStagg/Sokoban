#include "GUI.h"

PairInt GUI::_Size = PairInt(0, 0);
sf::RenderWindow* GUI::_Window = 0;
sf::Font GUI::_Font = sf::Font();

void GUI::RegisterWindow(sf::RenderWindow* rw)
{
	_Window = rw;
	_Size.Set((int)rw->getSize().x, (int)rw->getSize().y);
};

void GUI::RegisterFont(sf::Font f)
{
	_Font = f;
};

bool GUI::DoButton(int id, PairInt pos, PairInt size, std::string message)
{
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f((float)size._X, (float)size._Y));
	rect.setPosition(sf::Vector2f((float)pos._X, (float)pos._Y));
	rect.setFillColor(sf::Color::Green);
	_Window->draw(rect);

	sf::Text text(message,_Font);
	text.setPosition(sf::Vector2f((float)pos._X + ((size._X - text.getLocalBounds().width) / 2), (float)pos._Y + ((size._Y - text.getLocalBounds().height) / 2)));
	_Window->draw(text);

	return true;
};

PairInt& GUI::GetSize()
{
	return _Size;
};