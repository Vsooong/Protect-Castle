//
//  Bullet.cpp
//  ProtectPrincess
//
//  
//
//

#include "Bullet.h"

Bullet* Bullet::create(const std::string& filename)
{
	Bullet *sprite = new Bullet();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

Bullet* Bullet::createWithSpriteFrameName(const std::string& filename)
{
	Bullet *sprite = new Bullet();
	if (sprite && sprite->initWithSpriteFrameName(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void Bullet::setShoot(bool shoot)
{
	_shoot = shoot;
}

bool Bullet::isShoot()
{
	return _shoot;
}

void Bullet::settype(int type)
{
	_type = type;
}

int Bullet::gettype()
{
	return _type;
}