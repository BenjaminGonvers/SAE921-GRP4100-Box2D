#pragma once

#include "Player.h"
#include "NonPhysicalObject.h"
#include <box2d/box2d.h>


class PlayerContactListener final : public b2ContactListener
{
	void BeginContact(b2Contact* contact) override;
	void EndContact(b2Contact* contact) override;
	static void checkStartPlayer(b2Fixture* fixture);
	static void checkEndPlayer(b2Fixture* fixture);
	static Player* getPlayerPointer(b2Fixture* fixture);
	static bool isFootSensor(b2Fixture* fixture);
	static void checkFlagPlayer(b2Fixture* fixture);
	static void checkEndFlagPlayer(b2Fixture* fixture);
	static NonPhysicalObject* getFlagPointer(b2Fixture* fixture);
	static bool isFlagSensor(b2Fixture* fixture);
};