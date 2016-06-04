#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//std::vector<Entity> stuff;

unsigned int a;
struct Vector2
{
	float xPos;
	float yPos;

	Vector2() {
		xPos = 0;
		yPos = 0;
	}

	Vector2(float x, float y) {
		xPos = x;
		yPos = y;
	}

	Vector2 operator -(const Vector2& myVec2B)
	{
		return Vector2(this->xPos - myVec2B.xPos, this->yPos - myVec2B.yPos);
	}

	Vector2 operator +(const Vector2& myVec2B)
	{

		
		return Vector2(this->xPos + myVec2B.xPos, this->yPos + myVec2B.yPos);
	}
	Vector2 operator *(const Vector2& myVec2B)
	{
		return Vector2(this->xPos * myVec2B.xPos, this->yPos * myVec2B.yPos);
	}
	Vector2 operator /(const Vector2& myVec2B)
	{
		return Vector2(this->xPos / myVec2B.xPos, this->yPos / myVec2B.yPos);
	}
	bool operator ==(const Vector2& myVec2B)
	{
		return this->xPos == myVec2B.xPos && this->yPos == myVec2B.yPos;
	}

};

class Entity
{
public:
	unsigned short uniqueID;

	unsigned short entityID;

	float xPos;
	float yPos;

	float forwardNormalXComponent;
	float forwardNormalYComponent;

	float collisionRadius;
	float fOV;

	Entity() {
		uniqueID = 0;

		entityID = 0;

		xPos = 0;
		yPos = 0;

		forwardNormalXComponent = 0.f;
		forwardNormalYComponent = 0.f;

		collisionRadius = 0.f;
		fOV = 0.f;
	}


	Entity( int eid ) : Entity() {
		entityID = eid;
		switch (entityID)
		{
		case 0:
			collisionRadius = 10;
			break;
		case 1:
			collisionRadius = 20;
			break;
		case 2:
			collisionRadius = 64;
			break;
		case 3:
			collisionRadius = 12;
			fOV = 45;
			break;
		case 4:
			collisionRadius = 10;
			fOV = 65;
			break;
		case 5:
			collisionRadius = 25;
			fOV = 90;
			break;
		default:
			break;
		}
	}
	
};

string GetEntityData(Entity myEntity)
{
	std::string myString = std::to_string(myEntity.uniqueID)
		+ " " + std::to_string(myEntity.entityID)
		+ " " + std::to_string(myEntity.xPos)
		+ " " + std::to_string(myEntity.yPos)
		+ " " + std::to_string(myEntity.forwardNormalXComponent)
		+ " " + std::to_string(myEntity.forwardNormalYComponent);
	return myString;
}

bool IsColliding(Entity entity0, Entity entity1)
{
	float colRadius = entity0.collisionRadius + entity1.collisionRadius;

	if ((entity1.xPos-entity0.xPos)+(entity1.yPos-entity0.yPos)<(colRadius*colRadius))
	{
		return true;
	}
	return false;
}

int main()
{
	std::vector<Entity> thing;
	int length;
	int amount;
	string line;
	fstream myfile;
	myfile.open("C:\\Users\\bryson.au\\Desktop\\EscalationTest\\EscalationProgrammerTest.bin");
	if (myfile.is_open())
	{

		for (int i = 0; i < amount; i++)
		{
			thing[i] = Entity( 5 );
		}

		//cout << GetEntityData(thing);
	}

	//
	//if (myfile.is_open())
	//{
	//	while (getline(myfile, line))
	//	{
	//		cout << line.size() << '\n';
	//	}
	//}

	myfile.close();

	system("pause");
}