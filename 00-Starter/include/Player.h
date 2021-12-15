#pragma once
#include "PhysicalObject.h"


class Player : public PhysicalObject
{
private:

    bool w_keyboard_pressed_ = false;

	b2Fixture* footSensorFixture_;


public:

	Player(b2World& , sf::Texture* , sf::Vector2f& , b2Vec2 [], const int& , b2BodyType);

	void Check_Player_Action();




};