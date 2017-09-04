#ifndef GUI_H
#define GUI_H

#include "Pair.h"
#include <string>
#include "SFML\Graphics.hpp"

class GUI
{
public:

	static void RegisterWindow(sf::RenderWindow* rw);
	static void RegisterFont(sf::Font f);

	static bool DoButton(int id, PairInt pos, PairInt size, std::string label);
	
	static PairInt& GetSize();		//	Return reference to size of screen in pixels

private:

	static PairInt _Size;			//	Store size of screen in pixels
	static sf::RenderWindow* _Window;
	static sf::Font _Font;
};



#endif