//
//  EigenEx1DenseMatVec.cpp
//  
//
//  Created by Zac Schulwolf on 12/26/16.
//
// Compile by g++ -I "$(brew --prefix eigen)/include/eigen3" EigenEx1DenseMatVec.cpp -o EigenEx1DenseMatVec
//
// From https://eigen.tuxfamily.org/dox/GettingStarted.html
// From https://eigen.tuxfamily.org/dox/group__TutorialMatrixClass.html
// Installing Libraries http://stackoverflow.com/questions/34340578/installing-c-libraries-on-os-x

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
    cout << "Here is the matrix m1:\n" << m1 << endl;
    
    VectorXd v1(2);
    v1(0) = 4;
    v1(1) = v1(0) - 1;
    cout << "Here is the vector v1:\n" << v1 << endl;
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
    
    
    //3
    //initialization
    Matrix3d m3a; //3 by 3 matrix of uninitialized coefficients
    MatrixXd m3b; //dynamic size matrix, size currently 0 by 0, coefficients not allocated
    MatrixXf m3c(10,15); //10 by 15 dynamic sized matrix, allocated and uninitialized coeffients
    VectorXf v3a(30); //size 30 dynamic sized vector, allocated and uninitialized coeffients
    Vector2d v3b(5.0, 6.0);
    Vector3d v3c(5.0, 6.0, 7.0);
    Vector4d v3d(5.0, 6.0, 7.0, 8.0); //can initialize up to 4 coeffients with this method
    Matrix3f m3d;
    m3d << 1, 2, 3, 4, 5, 6, 7, 8, 9; //Comma-initialization for matrix
    cout << m3d << endl;
    
    Vector3f v3e; //column vector <float,3,1> Vector
    RowVector3f v3f; //row vector <float,3,2> RowVector
    cout << endl << endl;
    
    
    //4
    //rows(), cols(), size(), resize()
    //resize() changes coeffients, use conservativeResize() to keep coeffients
    MatrixXd m4(2,5); //Note that this is Xd so its dynamic sized
    m4.resize(4,3); //Needs to be dynamic, now 4 by 3
    cout << "The matrix m4 is of size " << m4.rows() << "x" << m4.cols() << endl;
    cout << "It has " << m4.size() << " coefficients" << endl;
    
    VectorXd v4(2);
    v4.resize(5);
    cout << "The vector v4 is of size " << v4.size() << endl;
    cout << "As a matrix, v4 is of size " << v4.rows() << "x" << v4.cols() << endl;
    cout << endl << endl;
    
    
    //5
    //Assignment and resizing
    MatrixXf m5a(2,2);
    cout << "m5a is of size " << m5a.rows() << "x" << m5a.cols() << endl;
    MatrixXf m5b(3,3);
    m5a = m5b;
    cout << "m5a is now of size " << m5a.rows() << "x" << m5a.cols() << endl;
    cout << "m5a is now of size " << m5a.rows() << "x" << m5a.cols() << endl;
    
    
    //6
    //Formula
    /*
     cout << "MatrixNt; ex: MatrixXi (Matrix<int, Dynamic, Dynamic>)
     VectorNt; ex: Vector2f (Matrix<float, 2, 1>)
     RowVectonNt; ex: Vector3d (Matrix<double, 1, 3>)
     
     N can be 2,3,4, or x (dynamic)
     t can be i (int), f (float), d (double), cf (complex<float>), or cd(complex<double>)" << endl;
    */
    
}
