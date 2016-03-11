#ifndef _WORLD
#define _WORLD

class Player;
class Exit;
class Room;

class World
{
public:
	Player* my_player=nullptr;
	Room* my_rooms=nullptr;
	Exit* my_exits=nullptr;
	

public:
	void createWorld();
	World();
	~World();
};

enum roooms{starting,floor1,floor2,floor3,lowlevel,requirements,darkarts,darkwizard,bathroom,secrets,transformation};


#endif