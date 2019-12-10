#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define	small 0
#define medium 1
#define large 2
#define Ak47 0
#define M4a1 1
class Bullet
{
private:
	int speed;
	int damage;
	Bullet() {};
public:
	static int count;
	
	Bullet(int speed, int damage)
	{
		++count;
		this->speed = speed;
		this->damage = damage;
	};
	int getSpeed() { return speed; };
	int getDamage() { return damage; };
};
int Bullet::count = 0;
class Gun
{
public:
	virtual void setNumberOfBullets(int size) {};
	virtual int getType() { return 0; };
	virtual void fire() {};
	virtual Bullet* getBullet() { return nullptr; };
};
class Ak47Gun:public Gun
{
private:
	Bullet * bullet;
	int numOfBullet;
	int type;
	Ak47Gun() {};
public:
	Ak47Gun(Bullet *bullet)
	{
		this->bullet = bullet;
		type = Ak47;
	};
	void setNumberOfBullets(int num)
	{
		numOfBullet = num;
	};
	Bullet* getBullet()
	{
		return bullet;
	}
	int getType() { return type; };
	void fire()
	{
cout<<"Gun type:"<< type <<" fire with "<<numOfBullet<<" speed,dame:"<< bullet->getSpeed() <<","<< bullet->getDamage() <<endl;
	};
};
class M4a1Gun :public Gun
{
private:
	Bullet * bullet;
	int numOfBullet;
	int type;
	M4a1Gun() {};
public:
	M4a1Gun(Bullet *bullet)
	{
		this->bullet = bullet;
		type = M4a1;
	};
	void setNumberOfBullets(int num)
	{
		numOfBullet = num;
	};
	Bullet* getBullet()
	{
		return bullet;
	}
	int getType() { return type; };
	void fire()
	{
cout<<"Gun type:"<< type <<" fire with "<<numOfBullet<<" speed,dame:"<< bullet->getSpeed() <<","<< bullet->getDamage() <<endl;
	};

};
class GunFactory
{
private:
	vector<Bullet*> v;
	GunFactory() {};
	static GunFactory * g;
public:
	static GunFactory *getInstance()
	{
		if (g == nullptr)
			g = new GunFactory;
		return g;
	}
Gun *createGun(int type,int NumberOfBullet, int bulletSpeed, int bulletDame)
	{
		Bullet* b = nullptr;
		Gun *g;
		for (vector<Bullet*>::iterator it = v.begin();it!=v.end();++it)
		{
if ((*it)->getDamage() == bulletDame&& (*it)->getSpeed() == bulletSpeed)
			{
				b = *it;
				break;
			}
		};
		if (b == nullptr)
		{
			b = new Bullet(bulletSpeed, bulletDame);
			v.push_back(b);
		}
		switch (type)
		{
		case Ak47:
			g = new Ak47Gun(b);
			break;
		case M4a1:
			g = new M4a1Gun(b);
			break;
		default:
			return nullptr;
			break;
		}
		g->setNumberOfBullets(NumberOfBullet);
		v.push_back(b);
		return g;
	}
};
GunFactory* GunFactory::g = nullptr;
int main()
{
	
	GunFactory * g = GunFactory::getInstance();
	
	Gun  *gun = nullptr;
	for (int i = 0; i< 1000; ++i)
	{
		
		gun=g->createGun(rand() %2, rand() % 3, rand() % 3, rand() % 3);
		gun->fire();
	}
	cout<<"Number of count:"<<Bullet::count;

	system("PAUSE");
	return 0;
}
