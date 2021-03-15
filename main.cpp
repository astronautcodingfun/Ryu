#include <SFML/Graphics.hpp>

using namespace sf;

class PLAYER {

public:

	float dx, dy;
	FloatRect rect;
	bool onGround;
	Sprite sprite;
	float currentFrame;
	bool punch;

	PLAYER(Texture& image)
	{
		sprite.setTexture(image);
		rect = FloatRect(7 * 32, 9 * 32, 50, 90);

		dx = dy = 0.1;
		currentFrame = 0;

	}


	void update(float time)
	{

		rect.left += dx * time;
		Collision(0);

		if (!onGround) dy = dy + 0.0005 * time;
		rect.top += dy * time;
		onGround = false;
		Collision(1);


		currentFrame += 0.005 * time;
		if (currentFrame > 6) currentFrame -= 6;

		if (dx > 0) sprite.setTextureRect(IntRect(203 + 49 * int(currentFrame), 15, 48, 90));
		if (dx < 0) sprite.setTextureRect(IntRect(203 + 49 * int(currentFrame), 15, 48, 90));
		//if (dx < 0) sprite.setTextureRect(IntRect(203 + 49 * int(currentFrame) + 49, 15, -48, 90));  target on the left

		if (!(Keyboard::isKeyPressed(Keyboard::Left)))
			if (!(Keyboard::isKeyPressed(Keyboard::Right)))
				sprite.setTextureRect(IntRect(50 * int(currentFrame / 2.5), 15, 48, 90));
		//sprite.setTextureRect(IntRect(50 * int(currentFrame / 2.5) + 48, 15, -48, 90)); target on the left

		if (dy > 0 || dy < 0)
			sprite.setTextureRect(IntRect(500, 8, 38, 90));
		//sprite.setTextureRect(IntRect(500 + 38, 8, -38, 90)); target on the left

		if (dy > 0 || dy < 0)
			if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::S))
				sprite.setTextureRect(IntRect(50, 547, 56, 70));

		if (dy > 0 || dy < 0)
			if (Keyboard::isKeyPressed(Keyboard::Q) || Keyboard::isKeyPressed(Keyboard::W))
				sprite.setTextureRect(IntRect(508, 550, 66, 68));

		sprite.setPosition(rect.left, rect.top);

		dx = 0;
	}



	void Collision(int dir)
	{
		for (int i = rect.top / 32; i < (rect.top + rect.height + 180) / 32; i++)
			for (int j = rect.left / 32; j < (rect.left + rect.width + 100) / 32; j++)
			{
				if ((dy > 0) && (dir == 1)) { if (rect.top > 300) { dy = 0;   onGround = true; } }
			}

	}
};
int main()
{
	RenderWindow window(VideoMode(600, 600), "Ryu");

	Texture t;
	t.loadFromFile("Ryu.png");

	float currentFrame = 0;

	PLAYER p(t);

	Clock clock;

	RectangleShape rectangle(Vector2f(32, 32));

	Sprite hadouken(t);
	hadouken.setTextureRect(IntRect(415, 645, 42, 45));
	hadouken.setScale(3, 3);

	std::vector<Sprite> hadoukens;
	hadoukens.push_back(Sprite(hadouken));

	Vector2f hadoukenPos;
	int hadoukenTimer = 0;

	for (size_t i = 0; i < hadoukens.size(); i++)
		hadoukens[i].setPosition(-200, -200);

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 700;

		if (time > 20) time = 20;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		p.update(time);

		p.sprite.setScale(3, 3);

		if (Keyboard::isKeyPressed(Keyboard::Left))
			if (!(Keyboard::isKeyPressed(Keyboard::Down)))
			{
				p.dx = -0.1;
				p.dx < 0;

			}

		if (Keyboard::isKeyPressed(Keyboard::Right))
			if (!(Keyboard::isKeyPressed(Keyboard::Down)))
			{
				p.dx = 0.1;
				p.dx > 0;
			}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			if (p.onGround) { p.dy = -0.40; p.onGround = false; }
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			p.sprite.setTextureRect(IntRect(180, 415, 50, 60));
			p.sprite.setPosition(p.rect.left, p.rect.top + 70);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				p.sprite.setTextureRect(IntRect(230, 415, 65, 60));
				p.sprite.setPosition(p.rect.left, p.rect.top + 70);
			}

		if (Keyboard::isKeyPressed(Keyboard::Down))
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				p.sprite.setTextureRect(IntRect(230, 415, 65, 60));
				p.sprite.setPosition(p.rect.left, p.rect.top + 70);
			}

		if (!(Keyboard::isKeyPressed(Keyboard::Down)))
			if (!(Keyboard::isKeyPressed(Keyboard::Up)))
				if (Keyboard::isKeyPressed(Keyboard::A))
					p.sprite.setTextureRect(IntRect(67, 130, 67, 90));

		if (!(Keyboard::isKeyPressed(Keyboard::Down)))
			if (!(Keyboard::isKeyPressed(Keyboard::Up)))
				if (Keyboard::isKeyPressed(Keyboard::S))
				{
					p.sprite.setTextureRect(IntRect(273, 130, 75, 90)),
						p.sprite.setScale(2.9, 2.92);
				}

		if (Keyboard::isKeyPressed(Keyboard::Down))
			if (Keyboard::isKeyPressed(Keyboard::Q))
			{
				p.sprite.setTextureRect(IntRect(711, 412, 77, 60));
				p.sprite.setPosition(p.rect.left, p.rect.top + 65);
				p.sprite.setScale(2.88, 2.9);
			}
		if (Keyboard::isKeyPressed(Keyboard::Down))
			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				p.sprite.setTextureRect(IntRect(711, 412, 77, 60));
				p.sprite.setPosition(p.rect.left, p.rect.top + 65);
				p.sprite.setScale(2.88, 2.9);
			}

		if (!(Keyboard::isKeyPressed(Keyboard::Down)))
			if (!(Keyboard::isKeyPressed(Keyboard::Up)))
				if (Keyboard::isKeyPressed(Keyboard::Q))
				{
					p.sprite.setTextureRect(IntRect(57, 255, 78, 95)),
						p.sprite.setScale(2.8, 2.8);
				}

		if (!(Keyboard::isKeyPressed(Keyboard::Down)))
			if (!(Keyboard::isKeyPressed(Keyboard::Up)))
				if (Keyboard::isKeyPressed(Keyboard::W))
				{
					p.sprite.setTextureRect(IntRect(1106, 234, 60, 115));
					p.sprite.setScale(2.8, 2.7),
						p.sprite.setPosition(p.rect.left, p.rect.top - 40);
				}

		//hadouken
		if (Keyboard::isKeyPressed(Keyboard::Left))    //body movement
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				p.sprite.setTextureRect(IntRect(58, 638, 70, 80));
				p.sprite.setPosition(p.rect.left, p.rect.top + 10);
				p.dx = 0;
			}

		if (Keyboard::isKeyPressed(Keyboard::Left))    //body movement
			if (Keyboard::isKeyPressed(Keyboard::A))
				if (Keyboard::isKeyPressed(Keyboard::S))
				{
					p.sprite.setTextureRect(IntRect(300, 638, 70, 80));
					p.sprite.setPosition(p.rect.left, p.rect.top + 10);
					p.dx = 0;
				}

		hadoukenPos = Vector2f(p.sprite.getPosition().x + 185, p.sprite.getPosition().y + 18);
		hadoukenTimer++;
		hadouken.setPosition(hadoukenPos);

		if (Keyboard::isKeyPressed(Keyboard::Left))
			if (Keyboard::isKeyPressed(Keyboard::A))
				if (Keyboard::isKeyPressed(Keyboard::S) && hadoukenTimer >= 1600) //Hadouken!
				{
					hadoukens.push_back(Sprite(hadouken));

					hadoukenTimer = 0;
				}


		for (size_t i = 0; i < hadoukens.size(); i++)
		{
			hadoukens[i].move(0.12f, 0.0f);

			if (hadoukens[i].getPosition().x > 800) hadoukens.erase(hadoukens.begin() + i);
		}
		//end hadouken

		window.clear(Color::Black);

		for (size_t i = 0; i < hadoukens.size(); i++) //draw hadouken
		{
			window.draw(hadoukens[i]);
		}
		window.draw(p.sprite);
		window.display();
	}

	return 0;
}