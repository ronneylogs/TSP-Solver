#include <iostream>

#include "tspcycle.hpp"

TSPCycle::TSPCycle() {
  
 
}

// returns the length of the cycle
float TSPCycle::getLength() const {
  float distance =0; 
  int size = getSize();//gets the size of object
  for(int z = 0; z<size;z++){//loops through obejct to get the 
    if(z==size-1){
      //the case to add distance of last point with first point
      distance = distance + m_points[0].getDistance(m_points[z]);
   }
   else
   //the normal case for adding distance between points
    distance = distance + m_points[z].getDistance(m_points[z+1]);
  }
 
   
  return distance;
}
