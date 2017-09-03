#ifndef SFMLSCENE_H
#define SFMLSCENE_H

#include "Scene.h"
#include "SFML\Graphics.hpp"

class SFMLScene : public Scene
{
public:

	SFMLScene(sf::RenderWindow* rw)
	{
		if (rw == 0)
			rw = new sf::RenderWindow(sf::VideoMode(624, 624), "Default Window");
		_Window = rw;
	};

protected:

	sf::RenderWindow* _Window;
};

#endif