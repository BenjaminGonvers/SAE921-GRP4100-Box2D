#include "PhysicalObject.h"

PhysicalObject::PhysicalObject(b2World& world, const sf::Texture* texture, const sf::Vector2f& pos, const b2Vec2 vertices[], const int& vertices_count)
{
	world_ = &world;
	b2BodyDef bodyDef_;
	b2PolygonShape dynamicBox_;
	b2FixtureDef fixtureDef_;

	Sprite_.setTexture(*texture);
	Sprite_.setOrigin(35.f, 35.f);

	bodyDef_.position = Convert_origine_pixel_to_meter(pos);

	dynamicBox_.Set(vertices, vertices_count);
	fixtureDef_.shape = &dynamicBox_;
	fixtureDef_.density = 1.0f;
	fixtureDef_.friction = 0.3f;

	body_ = world_->CreateBody(&bodyDef_);
	body_->CreateFixture(&fixtureDef_);
}


PhysicalObject::PhysicalObject(b2World& world,const sf::Texture* texture,const sf::Vector2f& pos,const b2Vec2 vertices[],const int& vertices_count,b2BodyType bodytype)
{
	world_ = &world;
	b2BodyDef bodyDef_;
	b2PolygonShape dynamicBox_;
	b2FixtureDef fixtureDef_;
	
	Sprite_.setTexture(*texture);
	Sprite_.setOrigin(35.f, 35.f);

	bodyDef_.type = bodytype;
	bodyDef_.position = Convert_origine_pixel_to_meter(pos);

	dynamicBox_.Set(vertices,vertices_count);
	fixtureDef_.shape = &dynamicBox_;
	fixtureDef_.density = 1.0f;
	fixtureDef_.friction = 0.3f;

	body_ = world_->CreateBody(&bodyDef_);
	body_->CreateFixture(&fixtureDef_);

}

PhysicalObject::~PhysicalObject()
{
	world_->DestroyBody(body_);
}


void PhysicalObject::pos_MAJ()
{
	Sprite_.setPosition(Convert_origine_meter_to_pixel(body_->GetPosition()));
	Sprite_.setRotation(radians_to_degrees(body_->GetAngle()));
}


b2Vec2 PhysicalObject::Convert_origine_pixel_to_meter(sf::Vector2f position)
{
	b2Vec2 new_position;
	new_position.x = position.x / 70.f;
	new_position.y = (800.f - position.y) / 70.f;
	return  new_position;
}

sf::Vector2f PhysicalObject::Convert_origine_meter_to_pixel(b2Vec2 position)
{
	sf::Vector2f new_position;
	new_position.x = position.x * 70.f;
	new_position.y = 800 - (position.y * 70.f);
	return new_position;
}

sf::Sprite& PhysicalObject::draw()
{
	return Sprite_;
}

float PhysicalObject::radians_to_degrees(float radians)
{

	return 360 - (radians * 180.f / 3.14159265359f);
}

float PhysicalObject::degrees_to_radians(float degrees)
{
	return (360 - degrees) * 3.14159265359f / 180.f;
}

sf::Vector2f PhysicalObject::get_pos()
{

	return Sprite_.getPosition();
}

b2Body* PhysicalObject::get_body_()
{
	return body_;
}

b2Vec2 PhysicalObject::pixel_to_meter(sf::Vector2f position)
{
	b2Vec2 new_position;
	new_position.x = position.x / 70.f;
	new_position.y = position.y / 70.f;
	return  new_position;
}

sf::Vector2f PhysicalObject::meter_to_pixel(b2Vec2 position)
{
	sf::Vector2f new_position;
	new_position.x = position.x * 70.f;
	new_position.y = position.y * 70.f;
	return new_position;
}