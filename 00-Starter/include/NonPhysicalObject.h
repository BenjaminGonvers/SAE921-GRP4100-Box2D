#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "TextureManager.h"


class NonPhysicalObject
{

protected:

	sf::Sprite Sprite_;
	b2World* world_;
	b2Body* body_;

public:

	NonPhysicalObject(b2World& , const sf::Texture* , const sf::Vector2f& ,const b2Vec2 [], const int&);
	NonPhysicalObject(b2World& , const sf::Texture* , const sf::Vector2f& , const b2Vec2 [], const int& , b2BodyType );
	~NonPhysicalObject();

	sf::Sprite& draw();
	void pos_MAJ();

	static b2Vec2 Convert_origine_pixel_to_meter(sf::Vector2f);
	static sf::Vector2f Convert_origine_meter_to_pixel(b2Vec2);
	static b2Vec2 pixel_to_meter(sf::Vector2f);
	static sf::Vector2f meter_to_pixel(b2Vec2);

	static float degrees_to_radians(float);
	static float radians_to_degrees(float);
	sf::Vector2f get_pos();
	b2Body* get_body_();

};