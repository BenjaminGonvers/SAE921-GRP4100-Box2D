#include "Player.h"
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <BodyFixtureType.h>


Player::Player(b2World& world, sf::Texture* texture,sf::Vector2f& pos, b2Vec2 vertices[],const int& number_vertices, b2BodyType body_type):
PhysicalObject(world, texture, pos,vertices,number_vertices,body_type )
{
	b2FixtureDef new_fixture_def;
	b2Vec2 new_fixture_vertices[4];
	b2PolygonShape dynamicBox_;
	
	new_fixture_vertices[0].x = vertices[3].x - 0.2f;
	new_fixture_vertices[0].y = vertices[3].y - 0.1f;

	new_fixture_vertices[1].x = vertices[2].x + 0.2f;
	new_fixture_vertices[1].y = vertices[2].y - 0.1f;

	new_fixture_vertices[2].x = vertices[2].x + 0.2f;
	new_fixture_vertices[2].y = vertices[2].y - 0.2f;

	new_fixture_vertices[3].x = vertices[3].x - 0.1f;
	new_fixture_vertices[3].y = vertices[3].y - 0.2f;

	dynamicBox_.Set(new_fixture_vertices, 4);
	new_fixture_def.shape= &dynamicBox_;
	new_fixture_def.isSensor = true;
	new_fixture_def.userData.pointer = static_cast<std::uintptr_t>(BodyFixtureType::PlayerFootSensor);

	footSensorFixture_ = body_->CreateFixture(&new_fixture_def);
	body_->SetFixedRotation(true);
	
}

void Player::Check_Player_Action()
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (!w_keyboard_pressed_&&isGrounded())
		{
				body_->ApplyLinearImpulse(b2Vec2(0, 15), body_->GetWorldCenter(), true);
			w_keyboard_pressed_ = true;
		}
	}else
	{
		w_keyboard_pressed_ = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		body_->ApplyForceToCenter(b2Vec2(30, 0), true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		body_->ApplyForceToCenter(b2Vec2(-30, 0), true);
	}
	
}

bool Player::isGrounded() const
{
	return footContactsCounter_ > 0;
}


void Player::startFootContact()
{
	footContactsCounter_ += 1;
}

void Player::endFootContact()
{
	footContactsCounter_ -= 1;
}


void Player::StartContact()
{
	footContactsCounter_ += 1;
}

void Player::EndContact()
{
	footContactsCounter_ -= 1;
}