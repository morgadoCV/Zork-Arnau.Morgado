#ifndef _WORLD
#define _WORLD

#include"entity.h"
#include"myvector.h"

class Player;
class Exit;
class Room;


class World:public Entity
{
private:
	mVector<Player*> player;
	mVector<Room*> rooms;
	mVector<Exit*> exits;
	char* input = nullptr; 
	

public:
	void createWorld();
	void moveNorth();
	void moveSouth();
	void moveEast();
	void moveWest();
	void lookRooms();
	void lookRoomsNorth();
	void lookRoomsSouth();
	void lookRoomsEast();
	void lookRoomsWest();
	void giveHelp() const;
	void openDoor();
	void closeDoor();
	void talkParsel();
	int checkImput();
	void getinput();
	World(const char* str1, const char* str2);
	~World();
	World();
	
	

};



#endif