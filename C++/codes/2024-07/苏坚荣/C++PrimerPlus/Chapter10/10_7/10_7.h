#pragma once

class Plorg
{
private:
	char m_name[20];
	int m_CI;

public:
	Plorg();
	Plorg(const char name[]);
	~Plorg();
	void resetCI(int CI);
	void showPlorg() const;

};