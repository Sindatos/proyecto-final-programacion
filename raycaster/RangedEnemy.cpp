#include <iostream>
#include "RangedEnemy.h"
#include "TextureManager.h"
#include "RayCaster.h"
#include "SoundManager.h"

void RangedEnemy::act(Map& map)
{
	Enemy::act(map);
	checkForProjectileColision();
}

void RangedEnemy::attack()
{
	RayCaster rayCaster;
	RayCastResult rayToWall = rayCaster.rayCast(angle, position, *Map::getInstance());
	Player player = *Player::getInstance();
	double enemyPlayerDist = sprite->getDistanceFromPlayer(position, player);

	Projectile* proj;

	if (attacking) {
		SoundManager* soundManager = SoundManager::getInstance();
		Sound pewSound = soundManager->getSound("pew.mp3"); //sonido de disparo enemigos
		PlaySound(pewSound);
		proj = new Projectile(position, angle, damage);
		projectiles.push_back(proj);
		attacking = false;
	}
	else {
		if (enemyPlayerDist < rayToWall.depth and attackTimer > attackCoolDown) {
			attacking = true;
			attackTimer = 0;
		}
	}
	attackTimer += GetFrameTime();
}

void RangedEnemy::checkForProjectileColision()
{
	int counter = 0;
	for (auto it = projectiles.begin(); it != projectiles.end(); ) {
		if ((*it)->shoot()) {
			delete *it;
			it = projectiles.erase(it);
		} else {
			++it;
		}
	}
}


void RangedEnemy::move(Map map)
{
	if (!attacking) {
		Enemy::move(map);
	}
}
std::vector<Projectile*> RangedEnemy::getProjectiles()
{
	return projectiles;
}

RangedEnemy::RangedEnemy(Point2D position)
{
	this->position = position;
	attacking = false;
	attackTimer = 0;
	attackCoolDown = 1.3;
}

