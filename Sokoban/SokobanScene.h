#ifndef SOKOBANSCENE_H
#define SOKOBANSCENE_H

#include "SFMLScene.h"

class SokobanScene : public SFMLScene
{
public:

	SokobanScene(sf::RenderWindow* rw);
	~SokobanScene();

	void Begin();
	void End();
	void Pause();
	void Resume();
	void Update(float dt);
	void DrawScreen();
	
private:


};

#endif