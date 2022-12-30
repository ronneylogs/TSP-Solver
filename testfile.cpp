#include <iostream>
#include <cstdlib>

#include "point.hpp"
#include "listofpoints.hpp"
#include "tspsolver.hpp"
#include "tspcycle.hpp"

using namespace std;

//testing point
void testPoint() {
  Point origin(0,0,"ORIGIN");
  cout << "--print using printPoint():" << endl;
  origin.printPoint();
  cout << "--print using toString():" << endl;
  cout << origin.toString() << endl;
  cout << "--print using << operator:" << endl;
  cout << origin << endl;
  
  

  Point q(3,4,"Q");
  //distance should be 5
  cout << "distance between ORIGIN and Q is " << q.getDistance(origin) << endl;

}

//testing listofpoints
void testListOfPoints(){
  ListOfPoints inputTSP;
  Point p[4] = {Point(2,2,"A"),
                Point(2,6,"B"),
                Point(5,6,"C"),
                Point(5,9,"D")};
  for (int i=0;i<4;i++){
    inputTSP.addPoint(p[i]); //testing addPoint function
    }
  Point e(3,3,"E"); 
  inputTSP.addAfter(e,"D"); //testing addAfter function. Function should now have an extra point named "E" after "D"
  inputTSP.printList(); //testing printList function
  inputTSP.draw(); //testing draw funciton. Should look like "A = (2,2) B = (2,6) C = (5,6) D = (5,9) E = (3,3)"
  cout<<"Size is "<<inputTSP.getSize()<<endl; //testing getSize function. Should be 5.
  cout<<inputTSP.getPointAt(0)<<endl; //testing getPointAt function. Should look like "A = (2,2)"



}


// gets a list of points and runs the solver on this list
// used in test1 and test2 below
void testSolver(ListOfPoints &input) {
  cout << "---run the solver---" << endl;
  TSPSolver solver(input);
  solver.solve();
  TSPCycle solution = solver.getSolution();


  cout << "Solution found is: " << endl;
  solution.printList();
  cout << "the length of the solution is: " << solution.getLength() << endl;
}

void test1() {
  Point p[4] = {Point(2,2,"A"),
                Point(2,6,"B"),
                Point(5,6,"C"),
                Point(5,9,"D")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<4;i++){
    inputTSP.addPoint(p[i]);
    }

  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();

  //should give 52.3818
  //sequence should be A = (2,2) E = (3,3) C = (5,6) F = (20,20) D = (5,9) B = (2,6)
  testSolver(inputTSP);
}


void test2() {
  ListOfPoints inputTSP;
  Point p(0,0,"A");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<10;i++) {
    string s;
    s = 'A'+i;
    p = Point(i,0,s);
    inputTSP.addPoint(p);
  }
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw(); 

  //should be 18
  //sequence should be A = (0,0) B = (1,0) C = (2,0) D = (3,0) E = (4,0) F = (5,0) G = (6,0) H = (7,0) I = (8,0) J = (9,0)
  testSolver(inputTSP);
}


void test3() {
  ListOfPoints inputTSP;
  Point p(0,0,"O");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<50;i++) {
    p = Point(rand() % 1000, rand() % 1000,"P"+to_string(i));
    inputTSP.addPoint(p);
  }
  // some coordinates values more than 20, so we do not use draw here

  testSolver(inputTSP);
}


void test4() {
  ListOfPoints inputTSP;
  Point p[11] = {
    Point(1, 2, "A"),
    Point(3, 9, "B"),
    Point(6, 1, "C"),
    Point(3, 1, "D"),
    Point(3, 3, "E"),
    Point(2, 3, "F"),
    Point(1, 4, "G"),
    Point(2, 4, "H"),
    Point(8, 7, "I"),
    Point(2, 7, "J"),
    Point(4, 7, "K")
  };
  for (int i = 0; i < 11; i++) inputTSP.addPoint(p[i]);
  cout << "Printing the list:" << endl;
  inputTSP.printList();
  cout << "\n";
  inputTSP.draw();

  //should give 28.0235
  //sequence should be A = (1,2) F = (2,3) E = (3,3) H = (2,4) G = (1,4) J = (2,7) B = (3,9) K = (4,7) I = (8,7) C = (6,1) D = (3,1)
  testSolver(inputTSP);
}

void test5() {
  ListOfPoints inputTSP;
  Point p[10] = {
    Point(1, 1, "A"),
    Point(9, 9, "B"),
    Point(9, 0, "C"),
    Point(0, 2, "D"),
    Point(2, 0, "E"),
    Point(1, 3, "F"),
    Point(6, 9, "G"),
    Point(3, 3, "H"),
    Point(2, 2, "I"),
    Point(3, 2, "J") };
  
  for (int i = 0; i < 10; i++) {
    inputTSP.addPoint(p[i]);
  }
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();
  inputTSP.draw();
  
  //should give 33.3651
  //sequence should be A = (1,1) D = (0,2) F = (1,3) I = (2,2) J = (3,2) H = (3,3) G = (6,9) B = (9,9) C = (9,0) E = (2,0)
  testSolver(inputTSP); 

}


int main() {
  cout << "****Test point**" << endl;
  testPoint();
  cout << "****End of test point**" << endl << endl;

  cout << "****Test ListOfPoints**" << endl;
  testListOfPoints();
  cout << "****End of ListOfPoints**" << endl << endl;

  cout << "****test1**:" << endl;
  test1();
  cout << "****end of test1**:" << endl << endl;
 
  cout << "****test2**:" << endl;
  test2();
  cout << "****end of test2**:" << endl << endl;

  cout << "****test3**:" << endl;
  test3();
  cout << "****end of test3**:" << endl << endl;

  cout << "****test4**:" << endl;
  test4();
  cout << "****end of test4**:" << endl << endl;

   cout << "****test5**:" << endl;
  test5();
  cout << "****end of test5**:" << endl << endl;



  return 0;
}
