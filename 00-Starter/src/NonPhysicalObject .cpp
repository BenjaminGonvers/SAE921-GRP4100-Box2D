#include "BodyFixtureType.h"
#include "NonPhysicalObject.h"

NonPhysicalObject::NonPhysicalObject(b2World& world, const sf::Texture* texture, const sf::Vector2f& pos, const b2Vec2 vertices[], const int& vertices_count)
{
	world_ = &world;
	b2BodyDef bodyDef_;
	b2PolygonShape dynamicBox_;
	b2FixtureDef fixtureDef_;

	Sprite_.setTexture(*texture);
	Sprite_.setOrigin(35.f, 35.f);

	bodyDef_.position = Convert_origine_pixel_to_meter(pos);
	bodyDef_.userData.pointer = reinterpret_cast<uintptr_t>(this);

	fixtureDef_.isSensor = true;
	dynamicBox_.Set(vertices, vertices_count);
	fixtureDef_.shape = &dynamicBox_;
	fixtureDef_.userData.pointer = static_cast<std::uintptr_t>(BodyFixtureType::FinishLine);

	body_ = world_->CreateBody(&bodyDef_);
	body_->CreateFixture(&fixtureDef_);
	
}


NonPhysicalObject::NonPhysicalObject(b2World& world,const sf::Texture* texture,const sf::Vector2f& pos,const b2Vec2 vertices[],const int& vertices_count,b2BodyType bodytype)
{
	world_ = &world;
	b2BodyDef bodyDef_;
	b2PolygonShape dynamicBox_;
	b2FixtureDef fixtureDef_;
	
	Sprite_.setTexture(*texture);
	Sprite_.setOrigin(35.f, 35.f);

	bodyDef_.type = bodytype;
	bodyDef_.position = Convert_origine_pixel_to_meter(pos);
	bodyDef_.userData.pointer = reinterpret_cast<uintptr_t>(this);

	dynamicBox_.Set(vertices,vertices_count);
	fixtureDef_.shape = &dynamicBox_;
	fixtureDef_.isSensor = true;
	fixtureDef_.userData.pointer = static_cast<std::uintptr_t>(BodyFixtureType::FinishLine);

	body_ = world_->CreateBody(&bodyDef_);
	body_->CreateFixture(&fixtureDef_);

}

NonPhysicalObject::~NonPhysicalObject()
{
	world_->DestroyBody(body_);
}


void NonPhysicalObject::pos_MAJ()
{
	Sprite_.setPosition(Convert_origine_meter_to_pixel(body_->GetPosition()));
	Sprite_.setRotation(radians_to_degrees(body_->GetAngle()));
}


b2Vec2 NonPhysicalObject::Convert_origine_pixel_to_meter(sf::Vector2f position)
{
	b2Vec2 new_position;
	new_position.x = position.x / 70.f;
	new_position.y = (800.f - position.y) / 70.f;
	return  new_position;
}

sf::Vector2f NonPhysicalObject::Convert_origine_meter_to_pixel(b2Vec2 position)
{
	sf::Vector2f new_position;
	new_position.x = position.x * 70.f;
	new_position.y = 800 - (position.y * 70.f);
	return new_position;
}

sf::Sprite& NonPhysicalObject::draw()
{
	return Sprite_;
}

float NonPhysicalObject::radians_to_degrees(float radians)
{

	return 360 - (radians * 180.f / 3.14159265359f);
}

float NonPhysicalObject::degrees_to_radians(float degrees)
{
	return (360 - degrees) * 3.14159265359f / 180.f;
}

sf::Vector2f NonPhysicalObject::get_pos()
{

	return Sprite_.getPosition();
}

b2Body* NonPhysicalObject::get_body_()
{
	return body_;
}

void NonPhysicalObject::StartContact()
{
	number_contact_ += 1;
}

void NonPhysicalObject::EndContact()
{
	number_contact_ -= 1;
}

int NonPhysicalObject::GetNumberContact()
{
	return number_contact_;
}

b2Vec2 NonPhysicalObject::pixel_to_meter(sf::Vector2f position)
{
	b2Vec2 new_position;
	new_position.x = position.x / 70.f;
	new_position.y = position.y / 70.f;
	return  new_position;
}

sf::Vector2f NonPhysicalObject::meter_to_pixel(b2Vec2 position)
{
	sf::Vector2f new_position;
	new_position.x = position.x * 70.f;
	new_position.y = position.y * 70.f;
	return new_position;
}