#include "Player.h"
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>


Player::Player(b2World& world, sf::Texture* texture,sf::Vector2f& pos, b2Vec2 vertices[],const int& number_vertices, b2BodyType body_type):
PhysicalObject(world, texture, pos,vertices,number_vertices,body_type )
{
	body_->SetFixedRotation(true);

}

void Player::Check_Player_Action()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (!w_keyboard_pressed_)
		{
			body_->ApplyLinearImpulse(b2Vec2(0, 6), body_->GetWorldCenter(), true);
			w_keyboard_pressed_ = true;
		}
	}else
	{
		w_keyboard_pressed_ = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		body_->ApplyForceToCenter(b2Vec2(10, 0), true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		body_->ApplyForceToCenter(b2Vec2(-10, 0), true);
	}
	
	
}