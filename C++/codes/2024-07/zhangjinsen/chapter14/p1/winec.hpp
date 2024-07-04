#ifndef WINEC_H_
#define WINEC_H_

#include <iostream>
#include <valarray>
#include <string>

template <class T1, class T2>
class Pair{
private:
	T1 a;
	T2 b;
public:
	void set(const T1 &yr, const T2 &bot){
        a=yr;
	    b=bot;
    }
	Pair(const T1 & aa, const T2 & bb):a(aa),b(bb) {}
	Pair(){}
	int Sum(){
        return b.sum();
    }
	void Show(){
    for (int i=0;i<a.size();i++){
		    std::cout <<"  "<<a[i]<<"  "<< b[i] << std::endl;
	    }   
    }
};
typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine{
private:
    std::string name;
	int yrs;
	Pair<ArrayInt,ArrayInt> dat;
public:
	Wine(const char *str,int y,int yr[],int bot[]);
	Wine(const char *str,int y);
	void GetBottles();
	std::string & Label();
	int sum();
	void Show();
};

Wine::Wine(const char *str,int y,int yr[],int bot[]):name(str),yrs(y),dat(ArrayInt(yr, y),ArrayInt(bot, y)){}

Wine::Wine(const char *str,int y):name(str),yrs(y){}

void Wine::GetBottles(){
	ArrayInt yr(yrs),bot(yrs);
	std::cout<<"Enter "<<this->name<<" data for "<<yrs<<" year(s):\n";
	for (int i=0;i<yrs;i++){
		std::cout<<"Enter year: ";
		std::cin>>yr[i];
		std::cout<<"Enter bottles for that year: ";
		std::cin>>bot[i];
	}
	this->dat.set(yr, bot);
}

std::string &Wine::Label(){
	return this->name;
}

int Wine::sum(){
	return this->dat.Sum();
}

void Wine::Show(){
	std::cout<<"Wine: "<<this->name<<std::endl;
	std::cout<<"Year Bottles\n";
	return this->dat.Show();
}

#endif
