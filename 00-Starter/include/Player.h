#pragma once
#include "PhysicalObject.h"


class Player : public PhysicalObject
{
private:

    bool left_mouse_pressed_ = false;
    bool w_keyboard_pressed_ = false;
    bool d_keyboard_pressed_ = false;
    bool s_keyboard_pressed_ = false;
    bool a_keyboard_pressed_ = false;



public:

	Player(b2World& , sf::Texture* , sf::Vector2f& , b2Vec2 [], const int& , b2BodyType);

	void Check_Player_Action();




};