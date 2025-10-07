#include "SokobanScene.h"

SokobanScene::SokobanScene(SDL_Renderer* renderer) : SDLScene(renderer)
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

	_TestInt = 0.f;

	//	GUI Stuff
	sf::Font font;
	font.loadFromFile("Roboto-Regular.ttf");
	GUI::RegisterFont(font);
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

	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_EVENT_QUIT)
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
		else if (e.type == SDL_EVENT_KEY_DOWN)
		{
			PressKey(e.key.key);
			switch (e.key.key)
			{
			case SDLK_ESCAPE:
				GetManager()->Quit();
				break;
			case SDLK_RETURN:
				
				break;
			default:
				break;
			}
		}
		else if (e.type == SDL_EVENT_KEY_UP)
		{
			ReleaseKey(e.key.key);
		}

	};

	if (GUI::DoButton(GenID, PairInt(500, 50), PairInt(50, 50), "..."))
		std::cout << "GUI Test: " << _TestInt << std::endl;

	GUI::DoSlider(GenID, PairInt(400, 50), PairInt(50, 300), _TestInt, 125);

	if (IsKeyPressed(SDLK_RETURN))
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