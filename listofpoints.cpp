#include "listofpoints.hpp"
#include <cmath>


ListOfPoints::ListOfPoints() {
  // implement me
}

void ListOfPoints::addAfter(Point& newPt, string name) {
  int counter = 1; 
  for (auto i:m_points){ //loops through the list of points
  if (i.getName()==name){ //if the name in the iterator is equal to the name given
    m_points.insert(m_points.begin()+counter,newPt); //insert the new point using insert
  }
  counter++;
  }
  }

void ListOfPoints::addPoint(Point& newPt)  {
  m_points.push_back(newPt); //adds the points to the end
}

Point& ListOfPoints::getPointAt(unsigned int i) {
  return m_points[i]; // returns that point
}

int ListOfPoints::getSize() const {
  return m_points.size(); //returns the size using get size
}

void ListOfPoints::printList() const {
  
  for (auto x: m_points) { //using for loop to print all the points
    cout << ' ' << x;
  }
  cout << '\n';

}

void ListOfPoints::draw() const {
  
  for(int i=20;i>=0;i--){ //setting the boundaries as 20
    for(int z=0;z<=20;z++){
      int flicker = 0;
      for(auto x: m_points){
        if(z==x.getX() && i==x.getY()){ //if the point is found then the name will be printed
          cout<<x.getName();
          flicker = 1;
        }

      }
      if(flicker == 0){ //if the point is not found then print a '-'
        cout<<"-";
      } 

    }
    cout<<"\n";
  }
}

void ListOfPoints::clr() {
  return m_points.clear(); //used to clear all the points in the list
}

 
