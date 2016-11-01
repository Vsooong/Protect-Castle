#ifndef __ProtectCastle__Game__
#define __ProtectCastle__Game__

#include <iostream>
#include "cocos2d.h"
#include "PointDelegate.h"
#include "SpriteBase.h"
#include "Monster.h"
#include "Turret.h"
#include "Bullet.h"
#include "SimpleAudioEngine.h"
#include "MonsterDataOfWave.h"
#include "TurretData.h"
#include "json/document.h"
#include "LevelManager.h"
#include "GameMenu.h"
#include "GameEnd.h"

USING_NS_CC;
using namespace CocosDenshion;

// ��Ϸ�߼���
class Game : public cocos2d::Layer
{
protected:
	TMXTiledMap* _tileMap;  // ��ͼ
	TMXLayer* _collidable;  // �ϰ���
	std::string _tileFile; // �ؿ���ͼ����
	int _number; // �ؿ������ֶ��ٲ�����
	int _currentCount; // ��ǰ���ֹ�������
	int _aliveCount;
	bool _isThisFinish;
	int _currNum; // ��ǰ���ֹ��ﲨ��
	int _goldValue; // ��ҵ�ǰ�Ľ��ֵ
	Sprite* _castle; // ����
	int _screenWidth, _screenHeight;  // ��Ļ��Ⱥ͸߶�
	int _count;  // ��Ϸ֡������
	int _delivery; // ���ֹ���ȡģ����
	Sprite* addImage;

	MonsterDataOfWave* _monsterDatas;
//	Vector<MonsterData*> _monsterDatas; // ��ǰ�ؿ��Ĺ�����Ϣ
	Vector<MonsterDataOfWave*> _monsterAllDatas;
//	std::vector<Vector<MonsterData*>> _monsterAllDatas;
//	std::vector<int> _monsterCount;
	Vector<TurretData*> _turretDatas; // ��ǰ�ؿ���������Ϣ
	Vector<PointDelegate*> _pathPoints; // ��¼��Ч·���ĵ�

	Label* _numberLabel; // ��ʾ���ﲨ����Label
	Label* _currNumLabel; // ��ʾ��ǰ���ﲨ����Label
	Label* _goldLabel; // ��ʾ��ǰ��ҽ�ҵ�Label

//	std::vector<Vector<Monster*>> _monsterVectorS;
	Vector<Monster*> _monsterVector;  // �洢���ֹ���ļ���
	bool _isFinish = false; // �ؿ����й����Ƿ�ȫ�����ֱ��
	bool _isSelect = false; // �ж��û�������ѡ��λ�û��ǽ�������

	Vector<Turret*> _turretVector; // �������ϣ�����Ѿ���ӵ�����
	Vector<Bullet*> _bulletVector; // �ڵ�����

public:
	/**
	* ��̬����������Scene����
	* ע�⣺��Cocos2d-x��û��Cocos2d-iPhone�еġ�id��,���鷵����ʵ����ָ�뷵����ʵ����ָ��
	* selectLevel����ǰ�ؿ���
	*/
	static cocos2d::Scene* createSceneWithLevel(int selectLevel);

	virtual bool init();

	bool initialize(int currentLevel);
	// TileMap����ת��ΪOpenGL����
	Point locationForTilePos(Point pos);
	// ��OpenGL����ת��ΪTileMap����
	Point tileCoordForPosition(Point position);
	// �ص����º������ú���ÿһ֡�������
	virtual void update(float delta);
	/**
	* ��ö�������
	* animName������֡������
	* delay������֡��֮֡��ļ��ʱ��
	* animNum������֡������
	*/
	Animate* getAnimateByName(std::string animName, float delay, int animNum);
	/**
	* �������·�����ƶ�
	* pathVector���ӹؿ�json�ļ��л�ȡ��·������
	* monster���ƶ��Ĺ���
	*/
	virtual void monsterMoveWithWayPoints(Vector<PointDelegate*> pathVector, Monster* monster);
	// ����HUD
	virtual void updateHUD(float delta);
	// ���¼�����
	virtual void updateLable(float delta);
	// ������ֹ���
	virtual void updateMonster(float delta);
	Vec2 & getBulletexX1(Vec2 monster, Vec2 turret, int num);
	// �������Ƿ���������Ĺ�����Χ
	bool checkPointInCircle(Point monsterPoint, Point turretPoint, int area);
	// ���㷢���ڵ�ʱ�����ڵ�����ת����
	float getTurretRotation(Point monsterPoint, Turret* turret);
	// �����ڵ��ƶ���������ڵ���Ҫ�ƶ�ʱ��
	float getBulletMoveTime(Point start, Point end);
	// ���������Ƿ��ϰ�
	bool getCollidable(Point position);
	// �������
	virtual void detectionTurret(float delta);
	// �����ײ
	virtual void collisionDetection(float delta);
	// ��⹫��
	virtual void detectionPrincess(float delta);
	// ��Ϸ������tag��0��ʾ��Ϸʧ�ܣ�1��ʾ��Ϸʤ��
	virtual void gameOver(int tag);
	// ʹ��CREATE_FUNC�괴����ǰ��Ķ���
	CREATE_FUNC(Game);
};

#endif