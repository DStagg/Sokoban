#include "SokobanScene.h"

SokobanScene::SokobanScene(sf::RenderWindow* rw) : SFMLScene(rw)
{

};
SokobanScene::~SokobanScene()
{

};

void SokobanScene::Begin()
{
	_Level.GenBoxMap(12, 12);

	_ImgMan.LoadTextureFromFile("Tilesheet", "Tilesheet.png");
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

	};
};

void SokobanScene::DrawScreen()
{
	sf::Image img;
	img.create(_Level.GetTileGrid().GetWidth() * 32, _Level.GetTileGrid().GetHeight() * 32);
	sf::Image source = _ImgMan.GetTexturePntr("Tilesheet")->copyToImage();
	
	for (int x = 0; x < _Level.GetTileGrid().GetWidth(); x++)
	{
		for (int y = 0; y < _Level.GetTileGrid().GetHeight(); y++)
		{
			Tile tile = _Level.GetTile(x, y);
			img.copy(source, x * 32, y * 32, sf::IntRect(tile._SheetColumn * 32, tile._SheetRow * 32, 32, 32));
		}
	}

	sf::Texture tex;
	tex.loadFromImage(img);
	sf::Sprite spr(tex);
	_Window->draw(spr);
};