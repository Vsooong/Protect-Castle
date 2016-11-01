#ifndef __ProtectPrincess__Bullet__
#define __ProtectPrincess__Bullet__

#include <iostream>
#include "cocos2d.h"
#include "SpriteBase.h"

// �ڵ���
class Bullet : public SpriteBase
{
private:
	bool _shoot = false; // �ڵ��Ƿ���
	int _type = 0;
public:
	static Bullet* create(const std::string& filename);

	static Bullet* createWithSpriteFrameName(const std::string& filename);

	void setShoot(bool shoot);

	bool isShoot();

	void settype(int type);

	int gettype();

};

#endif