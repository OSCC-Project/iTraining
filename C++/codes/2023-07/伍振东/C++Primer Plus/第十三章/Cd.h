#ifndef CD_H_
#define CD_H_

class Cd {
private:
	char* _performers;
	char* _label;
	int _selections;
	double _playtime;
public:
	Cd(const char* s1, const char* s2, int n, double x);
	Cd(const Cd& d);
	Cd();
	virtual ~Cd();
	virtual void Report()const;
	virtual Cd& operator=(const Cd& d);
};

class Classic :public Cd {
private:
	char* _main_work;
public:
	Classic(const char* s1, const char* s2, int n, double x, const char* mk);
	Classic(const Cd& d, const char* mk);
	Classic();
	virtual ~Classic();
	virtual void Report()const;
	virtual Classic& operator=(const Classic& cl);

};

#endif // !CD_H_
