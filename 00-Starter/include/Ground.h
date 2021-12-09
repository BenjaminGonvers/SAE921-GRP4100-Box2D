#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class Ground
{
private:
	enum name_Texture_
	{
		blockerMad = 0,
		grassMid,
		grassHillLeft2,
		grassHillLeft,
		grassHillRight2,
		grassHillRight,
		castleHalf,
		grassCenter,
	};
	sf::Sprite ground_;
	sf::Texture texture_ground_;

	b2BodyDef groundBodyDef_;
	b2Body* groundBody_;
	b2PolygonShape groundBox_;

public:
	Ground(b2World&,float,float);
	Ground(b2World&, float, float, int);


	sf::Sprite& draw();
	void pos_MAJ();
	void set_pos(float,float);
	void create_rectangle(b2World& world, float axeX, float axeY);
	void create_triangle(b2World& world, float axeX, float axeY, b2Vec2 vertices[]);

	b2Vec2 pixel_to_meter(sf::Vector2f);
	sf::Vector2f meter_to_pixel(b2Vec2);
};
