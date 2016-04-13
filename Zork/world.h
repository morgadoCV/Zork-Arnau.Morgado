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
	Exit* my_exits=nullptr;
	char* str = nullptr;
	int door=0,openfountain=0;
	

public:
	void createWorld();
	void moveNorth();
	void moveSouth();
	void moveEast();
	void moveWest();
	void lookRooms() const;
	void lookRoomsNorth()const;
	void lookRoomsSouth()const;
	void lookRoomsEast()const;
	void lookRoomsWest()const;
	void giveHelp() const;
	void openDoor();
	void closeDoor();
	void talkParsel();
	int checkImput();
	World();
	~World();
};

enum roooms{starting,floor1,floor2,floor3,lowlevel,requirements,darkarts,darkwizard,bathroom,secrets,transformation};


#endif