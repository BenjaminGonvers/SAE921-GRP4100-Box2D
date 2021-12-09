#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>



class Box
{
private:
	sf::Sprite box_;
	sf::Texture texture_box_;

	b2BodyDef bodyDef_;
	b2Body* body_;
	b2PolygonShape dynamicBox_;
	b2FixtureDef fixtureDef_;
	

public:

	Box(b2World& , float,float);
	Box(b2World&, sf::Vector2f);
	

	sf::Sprite& draw();
	void pos_MAJ();

	b2Vec2 pixel_to_meter(sf::Vector2f);
	sf::Vector2f meter_to_pixel(b2Vec2);
	float degrees_to_radians(float);
	float radians_to_degrees(float);
	sf::Vector2f get_pos();
	b2Body* get_body_();
};
