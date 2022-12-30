#include "tspsolver.hpp"

TSPSolver::TSPSolver(ListOfPoints &list) {
  m_list = list;
  
}

void TSPSolver::solve() {
  TSPCycle temp;
  
  //adding the first three points into the vector
  temp.addPoint(m_list.getPointAt(0));
  temp.addPoint(m_list.getPointAt(1));
  temp.addPoint(m_list.getPointAt(2));
  
 // outer loop for values >=3
  for(int z = 3; z<m_list.getSize();z++){
    int p = temp.getSize();
    float min = temp.getPointAt(0).getDistance(m_list.getPointAt(z))+(m_list.getPointAt(z).getDistance(temp.getPointAt(1)))-(temp.getPointAt(1).getDistance(temp.getPointAt(0)));
    string name;
    //inner loop for testing values one at a time
    for(int i = 0;i<p-1;i++){
      if(min>=(temp.getPointAt(i).getDistance(m_list.getPointAt(z)))+(m_list.getPointAt(z).getDistance(temp.getPointAt(i+1)))-(temp.getPointAt(i+1).getDistance(temp.getPointAt(i)))){
        min = (temp.getPointAt(i).getDistance(m_list.getPointAt(z)))+(m_list.getPointAt(z).getDistance(temp.getPointAt(i+1)))-(temp.getPointAt(i+1).getDistance(temp.getPointAt(i)));
        name = temp.getPointAt(i).getName(); //gets name of the index to add after
      }
      }
      //this is the case to connect the last element to the first element
      if(min>=(temp.getPointAt(p-1).getDistance(m_list.getPointAt(z)))+(m_list.getPointAt(z).getDistance(temp.getPointAt(0)))-(temp.getPointAt(0).getDistance(temp.getPointAt(p-1)))){
      
        min = temp.getPointAt(p-1).getDistance(m_list.getPointAt(z))+(m_list.getPointAt(z).getDistance(temp.getPointAt(0)))-(temp.getPointAt(0).getDistance(temp.getPointAt(p-1)));
        name = temp.getPointAt(p-1).getName(); //gets name of the index to add after

      }

      temp.addAfter(m_list.getPointAt(z),name); //uses add after to put point into temp vector
      
  }
      m_list.clr();//clears m_list
      for (int x = 0; x<temp.getSize();x++){//for putting items in temp into m_list
       m_list.addPoint(temp.getPointAt(x));
       
      }
      }

TSPCycle& TSPSolver::getSolution() {
  //adding everything from m_list to m_solution
  for (int x = 0; x<m_list.getSize();x++){
    m_solution.addPoint(m_list.getPointAt(x));

  }
  return m_solution;
}

