#ifndef SOKOBANSCENE_H
#define SOKOBANSCENE_H

#include "Scene.h"

class SokobanScene : public Scene
{
public:

	SokobanScene();
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