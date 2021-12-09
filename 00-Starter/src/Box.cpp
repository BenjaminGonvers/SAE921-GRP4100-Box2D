#include "Box.h"

Box::Box(b2World& world , float axeX, float axeY)
{
	texture_box_.loadFromFile("./data/box.png");

	box_.setTexture(texture_box_);
	box_.setOrigin(35.f, 35.f);
	
	bodyDef_.type = b2_dynamicBody;
	bodyDef_.position.Set(axeX/70.f,(800-axeY)/70.f);
	body_ = world.CreateBody(&bodyDef_);

	dynamicBox_.SetAsBox(0.5f, 0.5f);

	fixtureDef_.shape = &dynamicBox_;
	fixtureDef_.density = 1.0f;
	fixtureDef_.friction = 0.3f;

	body_->CreateFixture(&fixtureDef_);
	
}

Box::Box(b2World& world, sf::Vector2f pos)
{
	const float axeX = pos.x;
	const float axeY = pos.y;
	texture_box_.loadFromFile("./data/box.png");

	box_.setTexture(texture_box_);
	box_.setOrigin(35.f, 35.f);

	bodyDef_.type = b2_dynamicBody;
	bodyDef_.position.Set(axeX / 70.f, (800 - axeY) / 70.f);
	body_ = world.CreateBody(&bodyDef_);

	dynamicBox_.SetAsBox(0.5f, 0.5f);

	fixtureDef_.shape = &dynamicBox_;
	fixtureDef_.density = 1.0f;
	fixtureDef_.friction = 0.3f;

	body_->CreateFixture(&fixtureDef_);
}


void Box::pos_MAJ()
{
	box_.setPosition(meter_to_pixel(body_->GetPosition()));
	box_.setRotation(radians_to_degrees(body_->GetAngle()));
}


b2Vec2 Box::pixel_to_meter(sf::Vector2f position)
{
    b2Vec2 new_position;
    new_position.x = position.x / 70.f;
    new_position.y = (800.f - position.y)/70.f;
    return  new_position;
}

sf::Vector2f Box::meter_to_pixel(b2Vec2 position)
{
    sf::Vector2f new_position;
    new_position.x = position.x * 70.f;
    new_position.y = 800 - (position.y * 70.f);
	return new_position;
}

sf::Sprite& Box::draw()
{
	return box_;
}

float Box::radians_to_degrees(float radians)
{
	
	return 360-(radians * 180.f / 3.14159265359f);
}

float Box::degrees_to_radians(float degrees)
{
	return (360-degrees) * 3.14159265359f / 180.f;
}

sf::Vector2f Box::get_pos()
{

	return box_.getPosition();
}

b2Body* Box::get_body_()
{
	return body_;
}