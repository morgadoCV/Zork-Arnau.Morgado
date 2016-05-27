#ifndef _WORLD
#define _WORLD

#include"entity.h"
#include"myvector.h"

class Player;
class Exit;
class Room;
class Item;

class World:public Entity
{
private:
	mVector<Entity*> entities;
	Player* player;
	char* input = nullptr; 
	mVector<Entity*> hole;
	

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