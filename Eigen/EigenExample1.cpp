//
//  EigenExample1.cpp
//  
//
//  Created by Zac Schulwolf on 12/26/16.
//
// Compile by g++ -I "$(brew --prefix eigen)/include/eigen3" EigenExample1.cpp  -o EigenExample1
// http://stackoverflow.com/questions/34340578/installing-c-libraries-on-os-x

#include <iostream>
#include <Eigen/Dense>
//using Eigen::MatrixXd; used for 1
using namespace Eigen;
using namespace std;

int main()
{
    //1
    MatrixXd m1(2,2);
    m1(0,0) = 3;
    m1(1,0) = 2.5;
    m1(0,1) = -1;
    m1(1,1) = m1(1,0) + m1(0,1);
    cout << m1 << endl;
    cout << endl << endl;
    
    //2A
    Matrix3d m2a= Matrix3d::Random();
    m2a= (m2a+ Matrix3d::Constant(1.2)) * 50;
    cout << "m2a=" << endl << m2a<< endl;
    Vector3d v2a(1,2,3);
    cout << "m2a* v2a =" << endl << m2a* v2a << endl;
    cout << endl << endl;
    
    //2B
    MatrixXd m2b= MatrixXd::Random(3,3);
    m2b= (m2b+ MatrixXd::Constant(3,3,1.2)) * 50;
    cout << "m2b=" << endl << m2b<< endl;
    VectorXd v2b(3);
    v2b << 1, 2, 3;
    cout << "m2b* v2b =" << endl << m2b* v2b << endl;
    cout << endl << endl;
    
}
