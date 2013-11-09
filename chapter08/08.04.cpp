/*
  Reference: http://www.zybuluo.com/smilence/note/159
*/

class ParkingLot
{
private:
    level *lvl;
    int max_level;
    static ParkingLot *pInstance;

public:
    static ParkigLot *getInstance();
    pair<int, int> parkingVehicle(Vehicle *v)
	{
	    int index;
	    for(int j = 0; j < max_level; ++j)
	    {
		index = lvl[j].parkFreeSpot(v);
		if(index != -1)
		    return pair<int, int>(j, index);
	    }
	    return -1;
	}
};

class level
{
private:
    Spot *spots;
    int max_num;
    int remain;
    int freeIndex;

public:
    int parkFreeSpot(Vehicle *v)
	{
	    int n = v->numSpots();
	    int index = findFreeSpots(n);
	    if(index = -1)
		return -1;
	    else
		v->parkVehicle(spots+index);
	    return index;
	}
    int findFreeSpots(int n)
	{
	    // find n tontinuous spots
	}
};

class Spot
{
private:
    int length;
    int width;
    bool state;
    int index;
    int lvl;
public:
    bool isFree();
};

class Vehicle
{
private:
    int length;
    int width;
    bool parked;
public:
    int getLength();
    int getWidth();
    int numSpots(Spot *s);
    void parkVehicle(Spot *s);
    void removeVehicle(Spot *s);
};

class motor: public Vehicle {};
class car: public Vehicle {};
class bus: public Vehicle {};
