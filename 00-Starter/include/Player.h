#pragma once
#include <SFML/Audio/Sound.hpp>

#include "PhysicalObject.h"


class Player : public PhysicalObject 
{
private:

    bool w_keyboard_pressed_ = false;
	int footContactsCounter_ = false;
	bool LevelFinish_ = false;

	b2Fixture* footSensorFixture_;
	sf::Sound jump_sound_;


public:

	Player(b2World& , sf::Texture* ,sf::SoundBuffer*, sf::Vector2f& , b2Vec2 [], const int& , b2BodyType);

	void Check_Player_Action();

	bool isGrounded() const;

    void startFootContact();
    void endFootContact();

    void StartContact();
    void EndContact();
};