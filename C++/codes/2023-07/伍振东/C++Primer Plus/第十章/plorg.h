#pragma once
class Plorg {
private:
	char name[20];
	int CI;
public:
	Plorg();
	Plorg(int m_CI = 50);
	void change_CI(int ci);
	void show()const;
};