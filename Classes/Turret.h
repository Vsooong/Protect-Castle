#ifndef __ProtectCastle__Turret__
#define __ProtectCastle__Turret__

#include <iostream>
#include "cocos2d.h"
#include "SpriteBase.h"
#include "Bullet.h"

// 炮塔类
class Turret : public SpriteBase
{
private:
	int _mtype = 0;
	std::string _bulletName; // 炮塔发射的炮弹名称
	bool _select = false; // 炮塔是否被安放
	Bullet* _bullet = nullptr; // 炮塔关联的炮弹对象
	int _time = 0;//炮塔发射时间
public:

	// 静态的create函数
	static Turret* create(const std::string& filename);

	static Turret* createWithSpriteFrameName(const std::string& filename);

	// setter和getter函数
	void setBulletName(std::string bulletName);

	std::string getBulletName();

	void setSelect(bool select);

	bool isSelect();

	void setBullet(Bullet* bullet);

	Bullet* getBullet();

	void setTime(int time);

	int getTime();

	void setType(int type);

	int getType();
};

#endif