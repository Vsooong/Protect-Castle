#ifndef __ProtectCastle__Monster__
#define __ProtectCastle__Monster__

#include <iostream>
#include "cocos2d.h"
#include "SpriteBase.h"
#include "ui/CocosGUI.h"
using namespace ui;

// ������
class Monster : public SpriteBase
{
private:
	int _lifeValue;  // ���������ֵ
	LoadingBar* _HP; // ����Ѫ��
	double _HPInterval; // ����Ѫ���ĸ�����
public:

	// ��̬��create����
	static Monster* create(const std::string& filename);

	static Monster* createWithSpriteFrameName(const std::string& filename);

	// setter��getter����
	void setLifeValue(int lifeValue);

	int getLifeValue();

	void setHP(LoadingBar* HP);

	LoadingBar* getHP();

	void setHPInterval(double HPInterval);

	float getHpInterval();

};

#endif