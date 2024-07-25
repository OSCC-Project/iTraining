#include "MyPoint.hpp"

MyPoint::MyPoint(int x,int y,int id):_coordinate_X(x),_coordinate_Y(y),_id(id)
{
    _is_obstruction = false;
    _has_visit = false;
    _end_point = false;
    _start_point = false;
    _father_point = nullptr;
}

MyPoint::~MyPoint()
{

}

int MyPoint::get_coordinate_X() const
{
  return _coordinate_X;
}

int MyPoint::get_coordinate_Y() const
{
  return _coordinate_Y;
}

void MyPoint::set_obstruction_station(bool obs_station)
{
    _is_obstruction = obs_station;
}

void MyPoint::set_visit_station(bool visit_station)
{
    _has_visit = visit_station;
}

int MyPoint::get_id()
{
  return _id;
}

void MyPoint::set_end_point()
{
  _end_point = true;
}

bool MyPoint::is_end_point()
{
  return _end_point;
}

void MyPoint::set_start_point()
{
  _start_point = true;
}

bool MyPoint::is_start_point()
{
  return _start_point;
}

bool MyPoint::get_obstruction_station()
{
  return _is_obstruction;
}

void MyPoint::set_father_point(MyPoint *p)
{
  _father_point = p;
}

MyPoint *MyPoint::get_father_point()
{
  return _father_point;
}

void MyPoint::set_f_value(double v)
{
  _f_value = v;
}

double MyPoint::get_f_value()
{
  return _f_value;
}
