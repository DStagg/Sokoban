#include "SokobanScene.h"

SokobanScene::SokobanScene(sf::RenderWindow* rw) : SFMLScene(rw)
{

};
SokobanScene::~SokobanScene()
{

};

void SokobanScene::Begin()
{
	_ImgMan.LoadTextureFromFile("Tilesheet", "Tilesheet.png");
	
	_Level.GenBoxMap(12, 12);
	_Level.RefreshMapTexture(_ImgMan.GetTexturePntr("Tilesheet"));
};
void SokobanScene::End()
{

};

void SokobanScene::Pause()
{

};
void SokobanScene::Resume()
{

};

void SokobanScene::Update(float dt)
{
	sf::Event Event;
	while (_Window->pollEvent(Event))
	{
		if (Event.type == sf::Event::Closed)
			GetManager()->Quit();
		else if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
			GetManager()->Quit();
	};
};

void SokobanScene::DrawScreen()
{
	sf::Sprite map(_Level.GetMapTexture());
	_Window->draw(map);
};