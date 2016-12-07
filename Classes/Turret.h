#ifndef __ProtectCastle__Turret__
#define __ProtectCastle__Turret__

#include <iostream>
#include "cocos2d.h"
#include "SpriteBase.h"
#include "Bullet.h"

// ������
class Turret : public SpriteBase
{
private:
	int _mtype = 0;
	std::string _bulletName; // ����������ڵ�����
	bool _select = false; // �����Ƿ񱻰���
	Bullet* _bullet = nullptr; // �����������ڵ�����
	int _time = 0;//��������ʱ��
public:
	Turret() {}
	// ��̬��create����
	static Turret* create(const std::string& filename);

	static Turret* createWithSpriteFrameName(const std::string& filename);

	// ����Ƿ���Բ������Χ��
	static bool checkPointInCircle(Vec2 monsterPoint, Vec2 turretPoint, int area);
	// setter��getter����
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