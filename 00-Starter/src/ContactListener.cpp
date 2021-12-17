#include <ContactListener.h>
int numFootContacts = 0;

/*void BeginContact(b2Contact* contact) {
    //check if fixture A was the foot sensor
    b2FixtureUserData fixtureUserData = contact->GetFixtureA()->GetUserData();
    if (fixtureUserData == 3) 
    {
        numFootContacts++;
    }
    //check if fixture B was the foot sensor
    fixtureUserData = contact->GetFixtureB()->GetUserData();
    if (fixtureUserData == 3)
    {
        numFootContacts++;
    }
        
}

void EndContact(b2Contact* contact) {
    //check if fixture A was the foot sensor
    b2FixtureUserData fixtureUserData = contact->GetFixtureA()->GetUserData();
    if (fixtureUserData == 3)
    {
	    numFootContacts--;
    }
        
    //check if fixture B was the foot sensor
    fixtureUserData = contact->GetFixtureB()->GetUserData();
    if (fixtureUserData == 3)
    {
	    numFootContacts--;
    }
        
}*/