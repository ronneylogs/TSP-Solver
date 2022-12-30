#include "point.hpp"

float Point::getDistance(const Point &other) const { 
  float tempx = other.getX(); //gets the x value
  float tempy = other.getY(); //gets the y value
  float sum = sqrt((tempx-m_x)*(tempx-m_x) + (tempy-m_y)*(tempy-m_y)); //gets the pythagoras path



  return sum;
}
//structuring the print point
string Point::toString() const {
  // examples how to create string from small parts
  string str(m_name);
  str += " = (";
  str += std::to_string(m_x);
  str.append(",").append(std::to_string(m_y)).append(")");
  return str;
}


void Point::printPoint() const {
  cout << toString() << endl;
}

// used for printing Point using << operator.
// For example, the following code will work
// Point origin(0,0,'O');
// cout << origin;

//operator overloading for printing the point
ostream& operator<<(ostream &os, const Point &p) {
  return os << p.toString();
}
