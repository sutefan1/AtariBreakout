#include "WinScene.h"
#include "GameScene.h"

WinScene::WinScene(Application& app) : Scene(app)
{
	mBackground = getApp().getWindow().capture();
	mBackgroundTex.loadFromImage(mBackground);
	mBackgroundSpr.setTexture(mBackgroundTex);
	mBackgroundSpr.setColor(sf::Color(255, 255, 255, 128));

	mInfo.setFont(getApp().getFont());
	mInfo.setString("Enter for new Game --------------- Escape for end Game");
	mInfo.setCharacterSize(25);
	mInfo.setColor(sf::Color(255, 255, 102));
	mInfo.setPosition(10.f, 10.f);

	mHighscore.setFont(getApp().getFont());
	mHighscore.setString("You Won!\nYour Highscore: ");
	mHighscore.setCharacterSize(50);
	mHighscore.setColor(sf::Color::White);
	//center text
	sf::FloatRect textRect = mHighscore.getLocalBounds();
	mHighscore.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	mHighscore.setPosition(sf::Vector2f(getApp().getWindow().getSize().x / 2.0f, getApp().getWindow().getSize().y / 2.0f));
}

void WinScene::processEvent(const sf::Event& e)
{
	if (e.type == sf::Event::KeyReleased)
	{
		if (e.key.code == sf::Keyboard::Return)
		{
			//new Game
			getApp().setActiveScene(new GameScene(getApp()));
		}
		else if (e.key.code == sf::Keyboard::Escape)
		{
			//end Game
			getApp().getWindow().close();
		}
	}
}

void WinScene::update()
{

}

void WinScene::render()
{
	getApp().getWindow().draw(mBackgroundSpr);
	getApp().getWindow().draw(mHighscore);
	getApp().getWindow().draw(mInfo);



}