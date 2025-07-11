#pragma once
class Singleton
{
	static Singleton* Instance;

private:
	Singleton();

public:
	
	static Singleton* getInstance();
	static void ReleaseInst();
};

