#pragma once
#include "Animated.h"

class Player;

class Weapon {
public:
	Animated* sprite;
	int damage;
	unsigned int ammoCount;
	void shoot();
	bool canShoot();
	bool refillAmmo(int refill);
	Weapon();
	//friend
	friend class Canvas;
	friend class AmmoBox;
 private:
	bool reloading;
	int maxAmmo;
};
