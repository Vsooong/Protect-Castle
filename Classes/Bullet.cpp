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


float Bullet::getBulletMoveTime(Vec2 start, Vec2 end, TMXTiledMap* _tileMap)
{
	// �������յ������ת��ΪTileMap����
	Vec2 tileStart = Coordinate::tileCoordForPosition(start, _tileMap);
	Vec2 tileEnd = Coordinate::tileCoordForPosition(end, _tileMap);
	// �ƶ�һ�������ʱ��
	float duration = 0.02f;
	// �����ƶ���������ƶ�ʱ��
	duration = duration * sqrtf((tileStart.x - tileEnd.x) * (tileStart.x - tileEnd.x)
		+ (tileStart.y - tileEnd.y) * (tileStart.y - tileEnd.y));
	return duration;
}

// �����ڵ�ʱ�����ڵ�����ת����
float Bullet::getTurretRotation(Vec2 monsterPoint, Vec2 turret)
{
	// ����ת�ĽǶȣ���Ҫʹ�����Ǵ����������� = ���� / �ڱ�
	// monsterPoint.x�����������x�ᣬturret->getPosition().x�����������x��
	int offX = monsterPoint.x - turret.x;
	// monsterPoint.y�����������y�ᣬturret->getPosition().y�����������y��
	int offY = monsterPoint.y - turret.y;
	// ��ת���� = atan2f(�����к���)������/�ڱߣ�
	float radian = atan2f(offY, offX);
	// CC_RADIANS_TO_DEGREES�������Խ�����ת��Ϊ�Ƕ�
	float degrees = CC_RADIANS_TO_DEGREES(radian);
	// ת�����ĽǶȺͱ����ڵ�ͼƬ���90�ȣ���ˣ�Ϊ�˵õ���ȷ�ķ������ǰ���Ҫ���������ת����
	return 90 - degrees;
}