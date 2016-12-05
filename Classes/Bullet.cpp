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
	// 将起点和终点的坐标转换为TileMap坐标
	Vec2 tileStart = Coordinate::tileCoordForPosition(start, _tileMap);
	Vec2 tileEnd = Coordinate::tileCoordForPosition(end, _tileMap);
	// 移动一个网格的时间
	float duration = 0.02f;
	// 根据移动网格计算移动时间
	duration = duration * sqrtf((tileStart.x - tileEnd.x) * (tileStart.x - tileEnd.x)
		+ (tileStart.y - tileEnd.y) * (tileStart.y - tileEnd.y));
	return duration;
}

// 发射炮弹时计算炮弹的旋转方向
float Bullet::getTurretRotation(Vec2 monsterPoint, Vec2 turret)
{
	// 求旋转的角度，需要使用三角代数：反正切 = 对面 / 邻边
	// monsterPoint.x：怪物坐标的x轴，turret->getPosition().x：炮塔坐标的x轴
	int offX = monsterPoint.x - turret.x;
	// monsterPoint.y：怪物坐标的y轴，turret->getPosition().y：炮塔坐标的y轴
	int offY = monsterPoint.y - turret.y;
	// 旋转弧度 = atan2f(反正切函数)（对面/邻边）
	float radian = atan2f(offY, offX);
	// CC_RADIANS_TO_DEGREES函数可以将弧度转化为角度
	float degrees = CC_RADIANS_TO_DEGREES(radian);
	// 转出来的角度和本例炮弹图片相差90度，因此，为了得到正确的方向，我们把需要将结果进行转换。
	return 90 - degrees;
}