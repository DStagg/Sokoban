#ifndef SOKOBANSCENE_H
#define SOKOBANSCENE_H

#include "SFMLScene.h"
#include "ImageManager.h"
#include "Level.h"
#include "GameEnts.h"
#include "GUI.h"

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

	Level _Level;
	ImageManager _ImgMan;
};

#endif