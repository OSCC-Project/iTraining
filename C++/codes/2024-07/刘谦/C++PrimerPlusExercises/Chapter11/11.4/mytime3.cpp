#include "mytime3.h"

 
Time::Time() : hours(0), minutes(0) {}

 
Time::Time(int h, int m) : hours(h), minutes(m) {
    while (minutes >= 60) {
        hours++;
        minutes -= 60;
    }
    while (minutes < 0) {
        hours--;
        minutes += 60;
    }
    if (hours < 0) hours = 0;  
}

 
void Time::AddMin(int m) {
    minutes += m;
    while (minutes >= 60) {
        hours++;
        minutes -= 60;
    }
}

 
void Time::AddHr(int h) {
    hours += h;
}

 
void Time::Reset(int h, int m) {
    hours = h;
    minutes = m;
    while (minutes >= 60) {
        hours++;
        minutes -= 60;
    }
    while (minutes < 0) {
        hours--;
        minutes += 60;
    }
    if (hours < 0) hours = 0;  
}

 
Time operator+(const Time& t1, const Time& t2) {
    Time sum;
    sum.minutes = t1.minutes + t2.minutes;
    sum.hours = t1.hours + t2.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

 
Time operator-(const Time& t1, const Time& t2) {
    Time diff;
    int total1 = t1.minutes + 60 * t1.hours;
    int total2 = t2.minutes + 60 * t2.hours;
    diff.minutes = (total1 - total2) % 60;
    diff.hours = (total1 - total2) / 60;
    return diff;
}

 
Time operator*(double n, const Time& t) {
    Time result;
    long totalMinutes = t.hours * n * 60 + t.minutes * n;
    result.hours = totalMinutes / 60;
    result.minutes = totalMinutes % 60;
    return result;
}

 
Time operator*(const Time& t, double n) {
    return n * t;  
}

 
std::ostream& operator<<(std::ostream& os, const Time& t) {
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}
