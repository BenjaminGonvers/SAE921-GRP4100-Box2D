#include "PlayerContactListener.h"

#include "Player.h"
#include "Ground.h"
#include "BodyFixtureType.h"


void PlayerContactListener::BeginContact(b2Contact* contact)
{
	b2ContactListener::BeginContact(contact);
	const auto fixtureA = contact->GetFixtureA();
	const auto fixtureB = contact->GetFixtureB();
	checkStartPlayer(fixtureA);
	checkStartPlayer(fixtureB);
}

void PlayerContactListener::EndContact(b2Contact* contact)
{
	b2ContactListener::EndContact(contact);
	checkEndPlayer(contact->GetFixtureA());
	checkEndPlayer(contact->GetFixtureB());
}

void PlayerContactListener::checkStartPlayer(b2Fixture* fixture)
{
	if (Player* player = getPlayerPointer(fixture); player && isFootSensor(fixture))
	{
		player->StartContact();
	}
}

void PlayerContactListener::checkEndPlayer(b2Fixture* fixture)
{
	if (Player* player = getPlayerPointer(fixture); player && isFootSensor(fixture))
	{
		player->EndContact();
	}
}

Player* PlayerContactListener::getPlayerPointer(b2Fixture* fixture)
{
	const std::uintptr_t bodyUserData = fixture->GetBody()->GetUserData().pointer;
	const auto ptr = reinterpret_cast<PhysicalObject*>(bodyUserData);  // NOLINT(performance-no-int-to-ptr)
	const auto playerPtr = dynamic_cast<Player*>(ptr);
	return playerPtr;
}

bool PlayerContactListener::isFootSensor(b2Fixture* fixture)
{
	const auto pointer = fixture->GetUserData().pointer;
	constexpr auto sensorPtr = static_cast<uintptr_t>(BodyFixtureType::PlayerFootSensor);
	return pointer == sensorPtr;
}

