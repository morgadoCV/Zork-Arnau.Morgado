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
	mVector<Item*> items;
	char* input = nullptr; 
	

public:
	void createWorld();
	void moveNorth();
	void moveSouth();
	void moveEast();
	void moveWest();
	void lookRooms() const;
	void lookRoomsNorth() const;
	void lookRoomsSouth() const;
	void lookRoomsEast() const;
	void lookRoomsWest() const;
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