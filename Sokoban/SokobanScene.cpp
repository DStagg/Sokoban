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

	//_Level.SetPlayer(new GridEnt(&_Level));
	_Level.SetPlayer(new PlayerEnt(&_Level));
	_Level.GetPlayer()->GetGraphic().SetSprite(sf::Sprite(*_ImgMan.GetTexturePntr("Player")));
	_Level.GetPlayer()->GetGridPos().Set(1, 1);

	_Level.SetBlock(new GridEnt(&_Level));
	_Level.GetBlock()->GetGraphic().SetSprite(sf::Sprite(*_ImgMan.GetTexturePntr("Block")));
	_Level.GetBlock()->GetGridPos().Set(2, 2);


	//	GUI Stuff
	sf::Font font;
	font.loadFromFile("Roboto-Regular.ttf");
	GUI::RegisterFont(f);
	GUI::RegisterWindow(_Window);
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
	GUI::StartFrame();

	sf::Event Event;
	while (_Window->pollEvent(Event))
	{
		if (Event.type == sf::Event::Closed)
			GetManager()->Quit();
		else if (Event.type == sf::Event::MouseMoved)
		{
			GUI::GetState()._MouseX = sf::Mouse::getPosition(*_Window).x;
			GUI::GetState()._MouseY = sf::Mouse::getPosition(*_Window).y;
		}
		else if ((Event.type == sf::Event::MouseButtonPressed) && (Event.mouseButton.button == sf::Mouse::Left))
		{
			GUI::GetState()._MouseDown = true;
		}
		else if ((Event.type == sf::Event::MouseButtonReleased) && (Event.mouseButton.button == sf::Mouse::Left))
		{
			GUI::GetState()._MouseDown = false;
		}
		else if (Event.type == sf::Event::KeyPressed)
		{
			switch (Event.key.code)
			{
			case sf::Keyboard::Escape:
				GetManager()->Quit();
				break;
			case sf::Keyboard::Return:
				
				break;
			default:
				break;
			}
		}

	};

	if (GUI::DoButton(GenID, PairInt(500, 0), PairInt(50, 50), "..."))
		std::cout << "GUI Test" << std::endl;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
	{
		std::cout << "GUI State:" << std::endl << "----------" << std::endl;
		std::cout << "Hot: " << GUI::GetState()._HotItem << std::endl;
		std::cout << "Active: " << GUI::GetState()._ActiveItem << std::endl;
		std::cout << "Mouse: " << GUI::GetState()._MouseX << "," << GUI::GetState()._MouseY << std::endl;
		std::cout << "MouseDown: " << GUI::GetState()._MouseDown << std::endl << std::endl;
	}

	if (_Level.GetPlayer() != 0 )
		_Level.GetPlayer()->Update(dt);

	if (_Level.GetBlock() != 0)
		_Level.GetBlock()->Update(dt);

	GUI::EndFrame();
};

void SokobanScene::DrawScreen()
{
	sf::Sprite map(_Level.GetMapTexture());
	_Window->draw(map);

	if (_Level.GetPlayer() != 0)
		_Level.GetPlayer()->Draw(_Window);

	if (_Level.GetBlock() != 0)
		_Level.GetBlock()->Draw(_Window);

	GUI::Draw();
};