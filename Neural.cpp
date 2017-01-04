//
//  Neural.cpp
//  
//
//  Created by Zac Schulwolf on 12/27/16.
//
// Based on http://neuralnetworksanddeeplearning.com/chap1.html
// Compile by g++ -I "$(brew --prefix eigen)/include/eigen3" Neural.cpp -o Neural


#include <iostream>
#include <Eigen/Dense>
#include <ctime> //for random stuff
#include <list> //for list of Matrices for biases and weights
using namespace Eigen;
using namespace std;





void Biases(list<MatrixXd> &biases, VectorXi sizes){ //NEEDS TO BE OPTIMIZED inline?
    int r;
    for(int i=0; i <sizes.rows()-1;i++){
        r=sizes[i+1];
        biases.push_back(MatrixXd::Random(r,1));
    }
    
    cout << endl << "Biases:" << endl; //print biases
    for (list<MatrixXd>::iterator itb = biases.begin(); itb != biases.end(); itb++) //print biases
        cout << *itb << endl <<endl; //print biases
}


void Weights(list<MatrixXd> &weights, VectorXi sizes){ //NEEDS TO BE OPTIMIZED inline?
    int x,y;
    for(int i=0; i <sizes.rows()-1;i++){

        y=sizes[i+1];
        x=sizes[i];
        weights.push_back(MatrixXd::Random(y,x));
    }
    
    cout << endl << "Weights:" << endl; //print weights
    for (list<MatrixXd>::iterator itw = weights.begin(); itw != weights.end(); itw++) //print weights
        cout << *itw << endl <<endl; //print weights
}



class Network{
    int num_layers;
    VectorXi sizes;
    list<MatrixXd> biases;
    list<MatrixXd> weights;
    
    VectorXd sigmoid(ArrayXd z){
        return (1/(1+exp(-z))).vector();
    }
    
    
public:
    Network(VectorXi Sizes){ //constructor
        struct timespec tm; //time for random seed
        clock_gettime(CLOCK_REALTIME,&tm); //time for random seed
        srand(tm.tv_nsec); //This makes the Eigen random different each time        NEEDS TO BE OPTIMIZED
        
        num_layers = Sizes.rows();
        sizes = Sizes;
        Biases(biases,sizes);
        Weights(weights,sizes);
        
        
    }
    
    VectorXd feedforward(VectorXd a){ //probably needs to be private
		MatrixXd b;
        MatrixXd w;
        list<MatrixXd>::iterator itb = biases.begin();
        list<MatrixXd>::iterator itw = weights.begin();
        cout << "sizes.rows() = " << sizes.rows()<<endl;
        
        
        /*for (list<MatrixXd>::iterator itb = biases.begin(); itb != biases.end(); itb++){ //print biases
            b = *itb;
        }*/
        
        
        for (int i=0; i<sizes.rows()-1;i++,itb++,itw++){
            ///cout << "asdjkasldjsakldjaklsdjlkas\n";
            //b.resize((*itb).rows(),(*itb).cols());
            //w.resize((*itw).rows(),(*itw).cols());
            
            cout << (*itb).rows() << endl << (*itb).cols() << endl << endl;
            cout << (*itw).rows() << endl << (*itw).cols() << endl << endl;
            b= *itb;
            w= *itw;
            cout << "*itb:\n"<< *itb << endl <<endl; //print biases
            cout << "*itw:\n"<< *itw << endl <<endl; //print weights

            //cout << "itb at " << i << " is:\n" << *itb << endl;
            //cout << "itw at " << i << " is:\n" << *itw << endl;
            cout << "a:\n" << a << endl << "w:\n" << w << endl <<"a.matrix()\n" << a.matrix() << endl << "b.array():\n" << b.array() << endl;
            
            
            a = sigmoid((a * w).array() + b.array()); //w.row(0) is there because weights is always a vector but its easier to store it as a matrix
            cout << endl << endl << a << endl << endl;
            
        }
        return a;
    }

};

int main(){
    VectorXi s(3);
    s << 1,2,3;
    Network a(s);
    ArrayXd arr(2);
    arr << 1,2;
    a.feedforward(arr);
    
    return 0;
}











