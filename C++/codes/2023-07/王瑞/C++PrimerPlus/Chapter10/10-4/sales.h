#ifndef SALES_H_
#define SALES_H_
class Sales {
public:
  Sales();
  ~Sales();
  Sales(const double S[], int len);
  void setAverage();
  void setMin();
  void setMax();
  void showSales() const;
  void showAverage() const;
  void showMin() const;
  void showMax() const;

private:
  static const int QUARTERS = 4;
  double _sales[QUARTERS];
  double _average;
  double _min;
  double _max;
};
#endif