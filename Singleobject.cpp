//
//  Singleobject.cpp
//  singleobject
//
//  Created by orient on 2016/12/14.
//  Copyright © 2016年 orient. All rights reserved.
//
//把monsterCount和_currentLevel另个全局变量封装进单例singleobject中

#include <iostream>
using namespace std;

class SingleObject
{
private:
    SingleObject(){}
    static SingleObject *m_pInstance;
    
public:
    int _currentLevel;
    int monsterCount;
    static SingleObject* GetInstance()
    {
        if(m_pInstance==NULL)
        {
            m_pInstance=new SingleObject();
            m_pInstance->monsterCount=1;
            m_pInstance->_currentLevel=1;
        }
        return m_pInstance;
    }
    void SelectLevel(int selectLevel)
    {
        m_pInstance->_currentLevel=selectLevel;
    }
    void SetmonsterCount(int monster)
    {
        m_pInstance->monsterCount=monster;
    }
    int GetLevel()
    {
        return _currentLevel;
    }
    int GetmonsterCount()
    {
        return monsterCount;
    }
    
};

SingleObject* singleobject=SingleObject::GetInstance();
//_currentLevel=selectLevel替换成singleobject->SelectLevel(selectLevel)

