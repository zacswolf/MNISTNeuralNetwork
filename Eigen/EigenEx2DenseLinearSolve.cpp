//
//  EigenEx2DenseLinearSolve.cpp
//  
//
//  Created by Zac Schulwolf on 12/26/16.
//
// Compile by g++ -I "$(brew --prefix eigen)/include/eigen3" EigenEx2DenseLinearSolve.cpp -o EigenEx2LinearSolve
//
// From https://eigen.tuxfamily.org/dox/group__TutorialLinearAlgebra.html
//

#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
    //1
    //General Decomposition using ColPivHouseholderQR
    Matrix3f m1; //m1 is 3 by 3 of floats
    Vector3f v1a; //B is 1 by 3 of floats
    m1 << 1,2,3,  4,5,6,  7,8,10;
    v1a << 3, 3, 4;
    cout << "Here is the matrix m1:\n" << m1 << endl;
    cout << "Here is the vector v1a:\n" << v1a << endl;
    Vector3f v1b = m1.colPivHouseholderQr().solve(v1a); //A QR decomposition with column pivoting and solve
    cout << "The solution is:\n" << v1b << endl;
    cout << endl << endl;
    
    
    //2
    //Decomposition if matix is positive definite use LLT or LDLT
    Matrix2f m2a, m2b; //using 2 matrices, m2a could also be a vector
    m2a << 2, -1, -1, 3;
    m2b << 1, 2, 3, 1;
    cout << "Here is the matrix m2a:\n" << m2a << endl;
    cout << "Here is the right hand side m2b:\n" << m2b << endl;
    Matrix2f x = m2a.ldlt().solve(m2b);
    cout << "The solution is:\n" << x << endl;
    cout << endl << endl;
    
    
    //3
    //Error margin
    MatrixXd m3a = MatrixXd::Random(100,100);
    MatrixXd m3b = MatrixXd::Random(100,50);
    MatrixXd m3c = m3a.fullPivLu().solve(m3b);
    double relative_error = (m3a*m3c - m3b).norm() / m2b.norm(); //norm() is L2 norm
    cout << "The relative error is:\n" << relative_error << endl;
    cout << endl << endl;
    
    
    //4
    //eigenvalues() and eginvectors() by SelfAdjointEigenSolver and EigenSolver
    Matrix2f m4a;
    m4a << 1, 2, 2, 3;
    cout << "Here is the matrix m4a:\n" << m4a << endl;
    SelfAdjointEigenSolver<Matrix2f> eigensolver(m4a); //SelfAdjointEigenSolver
    if (eigensolver.info() != Success) abort(); //eigensolver
    cout << "The eigenvalues of m4a are:\n" << eigensolver.eigenvalues() << endl; //eigenvalues()
    cout << "Here's a matrix whose columns are eigenvectors of m4a \n";
    cout << "corresponding to these eigenvalues:\n";
    cout << eigensolver.eigenvectors() << endl; //eigenvecotors()
    cout << endl << endl;
    
    //5
    //Inverse and Determinant
    Matrix3f m5;
    m5 << 1, 2, 1, 2, 1, 0, -1, 1, 2;
    cout << "Here is the matrix m5:\n" << m5 << endl;
    cout << "The determinant of m5 is " << m5.determinant() << endl;
    cout << "The inverse of m5 is:\n" << m5.inverse() << endl;
    cout << endl << endl;
    
    
    //6
    //Least squares solving using JocobiSVD
    MatrixXf m6 = MatrixXf::Random(3, 2);
    cout << "Here is the matrix m6:\n" << m6 << endl;
    VectorXf v6 = VectorXf::Random(3);
    cout << "Here is the right hand side b:\n" << v6 << endl;
    cout << "The least-squares solution is:\n";
    cout << m6.jacobiSvd(ComputeThinU | ComputeThinV).solve(v6) << endl;
    cout << endl << endl;
    
    //7
    //Separating the computation from the construction
    Matrix2f m7a, m7b;
    LLT<Matrix2f> llt;
    m7a << 2, -1, -1, 3;
    m7b << 1, 2, 3, 1;
    cout << "Here is the matrix m7a:\n" << m7a << endl;
    cout << "Here is the right hand side m7b:\n" << m7b << endl;
    cout << "Computing LLT decomposition..." << endl;
    llt.compute(m7a);
    cout << "The solution is:\n" << llt.solve(m7b) << endl;
    m7a(1,1)++;
    cout << "The matrix m7a is now:\n" << m7a << endl;
    cout << "Computing LLT decomposition..." << endl;
    llt.compute(m7a);
    cout << "The solution is now:\n" << llt.solve(m7b) << endl;
    cout << endl << endl;
    
    
    //8
    //Rank-revealing decompositions
    Matrix3f m8a;
    m8a << 1, 2, 5, 2, 1, 4, 3, 0, 3;
    cout << "Here is the matrix m8a:\n" << m8a << endl;
    FullPivLU<Matrix3f> lu_decomp(m8a);
    cout << "The rank of m8a is " << lu_decomp.rank() << endl;
    cout << "Here is a matrix whose columns form a basis of the null-space of m8a:\n"
    << lu_decomp.kernel() << endl;
    cout << "Here is a matrix whose columns form a basis of the column-space of m8a:\n"
    << lu_decomp.image(m8a) << endl; // yes, have to pass the original m8a
    
    Matrix2d m8b;
    m8b << 2, 1,
    2, 0.9999999999;
    FullPivLU<Matrix2d> lu(m8b);
    cout << "By default, the rank of m8b is found to be " << lu.rank() << endl;
    lu.setThreshold(1e-5);
    cout << "With threshold 1e-5, the rank of m8b is found to be " << lu.rank() << endl;
    cout << endl << endl;
    
    
    
}
