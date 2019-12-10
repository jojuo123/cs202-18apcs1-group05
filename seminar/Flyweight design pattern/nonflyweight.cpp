#include<iostream>
	#include<vector>
	#include<string>
	using namespace std;
	#define small 0
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
	class Ak47Gun :public Gun
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
			cout << "Gun type:" << type << " fire with " << numOfBullet <<
			"speed,dame:" << bullet->getSpeed() << "," 
<< bullet->getDamage()<< endl;
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
			cout << "Gun type:" << type << " fire with " << numOfBullet <<
			"speed,dame:" << bullet->getSpeed() << "," 
<< bullet->getDamage()<< endl;
		};

	
	};
	
	int main()
	{
		Ak47Gun *g = new Ak47Gun(new Bullet(small, large));
M4a1Gun *g2 = new M4a1Gun(new Bullet(large, large));
		system("PAUSE");
		return 0;
	}
