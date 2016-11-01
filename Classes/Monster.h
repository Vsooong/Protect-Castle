#ifndef __ProtectCastle__Monster__
#define __ProtectCastle__Monster__

#include <iostream>
#include "cocos2d.h"
#include "SpriteBase.h"
#include "ui/CocosGUI.h"
using namespace ui;

// 怪物类
class Monster : public SpriteBase
{
private:
	int _lifeValue;  // 怪物的生命值
	LoadingBar* _HP; // 怪物血条
	double _HPInterval; // 怪物血条的更新量
public:

	// 静态的create函数
	static Monster* create(const std::string& filename);

	static Monster* createWithSpriteFrameName(const std::string& filename);

	// setter和getter函数
	void setLifeValue(int lifeValue);

	int getLifeValue();

	void setHP(LoadingBar* HP);

	LoadingBar* getHP();

	void setHPInterval(double HPInterval);

	float getHpInterval();

};

#endif