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
	_ImgMan.LoadTextureFromFile("Player", "Player.png");
	_ImgMan.LoadTextureFromFile("Block", "Block.png");

	_Level.GenBoxMap(12, 12);
	_Level.RefreshMapTexture(_ImgMan.GetTexturePntr("Tilesheet"));

	_Level.SetPlayer(new GridEnt(&_Level));
	_Level.GetPlayer()->GetGraphic().SetSprite(sf::Sprite(*_ImgMan.GetTexturePntr("Player")));
	_Level.GetPlayer()->GetGridPos().Set(1, 1);

	_Level.SetBlock(new GridEnt(&_Level));
	_Level.GetBlock()->GetGraphic().SetSprite(sf::Sprite(*_ImgMan.GetTexturePntr("Block")));
	_Level.GetBlock()->GetGridPos().Set(2, 2);
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
		else if (Event.type == sf::Event::KeyPressed)
		{
			switch (Event.key.code)
			{
			case sf::Keyboard::Escape:
				GetManager()->Quit();
				break;
			case sf::Keyboard::Up:
				_Level.GetPlayer()->Move(0, -1);
				break;
			case sf::Keyboard::Down:
				_Level.GetPlayer()->Move(0, 1);
				break;
			case sf::Keyboard::Left:
				_Level.GetPlayer()->Move(-1, 0);
				break;
			case sf::Keyboard::Right:
				_Level.GetPlayer()->Move(1, 0);
				break;
			default:
				break;
			}
		}

	};

	if (_Level.GetPlayer() != 0 )
		_Level.GetPlayer()->Update(dt);

	if (_Level.GetBlock() != 0)
		_Level.GetBlock()->Update(dt);
};

void SokobanScene::DrawScreen()
{
	sf::Sprite map(_Level.GetMapTexture());
	_Window->draw(map);

	if (_Level.GetPlayer() != 0)
		_Level.GetPlayer()->Draw(_Window);

	if (_Level.GetBlock() != 0)
		_Level.GetBlock()->Draw(_Window);
};