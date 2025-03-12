#include <iostream>

enum class Drink {
	уиски,
	водка,
	кола,
	фанта,
	вода,
	вино,
	ром,
	сок
};

struct Client
{
	char name[31+1];
	uint8_t likedDrinks;
};


bool isLike(const Client& client, Drink drink)
{
	return (client.likedDrinks >> int(drink)) & 1;
}

void makeLike(Client& client, Drink drink)
{
	client.likedDrinks |= (1 << int(drink));
}

void makeNotLike(Client& client, Drink drink)
{
	client.likedDrinks &= ~(1 << int(drink));
}


int main()
{

	return 0;
}