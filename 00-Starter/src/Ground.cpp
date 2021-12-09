#include "Ground.h"



Ground::Ground(b2World& world, float axeX, float axeY)
{


	texture_ground_.loadFromFile("./data/grassMid.png");

	ground_.setTexture(texture_ground_);
	ground_.setOrigin(35.f, 35.f);

	groundBodyDef_.position.Set(axeX / 70.f, (800 - axeY) / 70.f);
	groundBody_ = world.CreateBody(&groundBodyDef_);
	groundBox_.SetAsBox(0.5f, 0.5f);
	groundBody_->CreateFixture(&groundBox_, 0.0f);

}

Ground::Ground(b2World& world, float axeX, float axeY, int tile)
{

	switch (tile)
	{
	case grassMid:
		texture_ground_.loadFromFile("./data/grassMid.png");
		create_rectangle(world, axeX, axeY);
		break;
	case grassHillLeft2:
		texture_ground_.loadFromFile("./data/grassHillLeft2.png");
		create_rectangle(world, axeX, axeY);
		break;
	case grassHillLeft:
	{
		texture_ground_.loadFromFile("./data/grassHillLeft.png");
		b2Vec2 vertices[3];
		vertices[0].Set(0.5, 0.5);
		vertices[1].Set(0.5, -0.5);
		vertices[2].Set(-0.5, -0.5);
		create_triangle(world, axeX, axeY, vertices);
	}

	break;
	case grassHillRight2:
		texture_ground_.loadFromFile("./data/grassHillRight2.png");
		create_rectangle(world, axeX, axeY);
		break;
	case grassHillRight:
	{
		texture_ground_.loadFromFile("./data/grassHillRight.png");
		b2Vec2 vertices[3];
		vertices[0].Set(-0.5, 0.5);
		vertices[1].Set(0.5, -0.5);
		vertices[2].Set(-0.5, -0.5);
		create_triangle(world, axeX, axeY, vertices);
	}
	break;
	case castleHalf:
		texture_ground_.loadFromFile("./data/castleHalf.png");
		create_rectangle(world, axeX, axeY);
		break;
	case grassCenter:
		texture_ground_.loadFromFile("./data/grassCenter.png");
		create_rectangle(world, axeX, axeY);
		break;
	case blockerMad:
		texture_ground_.loadFromFile("./data/blockerMad.png");
		create_rectangle(world, axeX, axeY);
		break;
	default:
		texture_ground_.loadFromFile("./data/blockerMad.png");
		create_rectangle(world, axeX, axeY);
	}


}

void Ground::pos_MAJ()
{
	ground_.setPosition(meter_to_pixel(groundBody_->GetPosition()));
	ground_.setRotation(groundBody_->GetAngle());
}

void Ground::set_pos(float axeX, float axeY)
{
	groundBodyDef_.position.Set(axeX / 70.f, (800 - axeY) / 70.f);
}

void Ground::create_rectangle(b2World& world, float axeX, float axeY)
{
	ground_.setTexture(texture_ground_);
	ground_.setOrigin(35.f, 35.f);

	groundBodyDef_.position.Set(axeX / 70.f, (800 - axeY) / 70.f);
	groundBody_ = world.CreateBody(&groundBodyDef_);
	groundBox_.SetAsBox(0.5f, 0.5f);
	groundBody_->CreateFixture(&groundBox_, 0.0f);
}

void Ground::create_triangle(b2World& world, float axeX, float axeY, b2Vec2 vertices[3])
{
	ground_.setTexture(texture_ground_);
	ground_.setOrigin(35.f, 35.f);


	groundBodyDef_.position.Set(axeX / 70.f, (800 - axeY) / 70.f);
	groundBody_ = world.CreateBody(&groundBodyDef_);
	groundBox_.Set(vertices, 3);
	groundBody_->CreateFixture(&groundBox_, 0.0f);
}



b2Vec2 Ground::pixel_to_meter(sf::Vector2f position)
{
	b2Vec2 new_position;
	new_position.x = position.x / 70.f;
	new_position.y = (800.f - position.y) / 70.f;
	return  new_position;
}

sf::Vector2f Ground::meter_to_pixel(b2Vec2 position)
{
	sf::Vector2f new_position;
	new_position.x = position.x * 70.f;
	new_position.y = 800 - (position.y * 70.f);
	return new_position;
}

sf::Sprite& Ground::draw()
{
	return ground_;
}