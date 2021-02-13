#include <iostream> 
#include <list> 
#include <vector>
#include <iterator> 
// #include "Gaussian.h"
// #include "Multinomial.h"
#include "Flip.h"
#include "uncertain.h"
#include "Sampler.h"
#include "RandomPrimitive.h"
#include "extensions.h"
#include "MarkovChainMonteCarloSampler.h"


using namespace std; 
  
//function for printing the elements in a list 
void showlist(list <int> g) 
{ 
    list <int> :: iterator it; 
    for(it = g.begin(); it != g.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 

// int main() 
// { 
  
//     list <int> gqlist1, gqlist2; 
  
  
//     for (int i = 0; i < 10; ++i) 
//     { 
//         gqlist1.push_back(i * 2); 
//         gqlist2.push_front(i * 3); 
//     } 
//     cout << "\nList 1 (gqlist1) is : "; 
//     showlist(gqlist1); 
//     return 0;
// }


bool Gaussian_sample(){
    Uncertain<double>* X = new Gaussian(5.0,2.0);
    Sampler<double> s;
    s.Create(X);
    auto li = s.Take(100);
    // vector<double>::iterator ptr = li.begin();
    bool test = true;
    for(int i=0; i<100; i++){
        // auto check = *(next(ptr,i));
        double check = li.at(i);
        test = test && (check >= -3 && check <= 13);}

    return test;}

bool Gaussian_Mean(){

    double Sum = 0.0;

    Uncertain<double>* X = new Gaussian(5.0,0.10);
    Sampler<double> s;
    s.Create(X);
    auto li = s.Take(100);
    vector<double>::iterator ptr = li.begin();
    bool test = true;
    for(int i=0; i<100; i++){
        Sum += *(next(ptr,i));
        // cout << *(next(ptr,i)) << endl;
    }
    Sum /=100;

    return (Sum >= 4.6 && Sum <= 5.4);
    }

bool Gaussian_BNN_Sample(){

    Uncertain<double>* X = new Gaussian(5.0,0.1);
    Uncertain<double>* Y = new Gaussian(4.0,0.1);
    Uncertain<double>* Z = *X + *Y;
    // cout << Z->GetSupport()<< endl;
    Sampler<double> s;
    s.Create(Z);
    vector<double> li = s.Take(100);
    vector<double>::iterator ptr = li.begin();
    bool test = true;
    for(int i=0; i<100; i++){
        // cout << "new sample: " << (*(next(ptr,i))) << "| ";
        // cout << "new sample " << li.at(i) << "|";
        test = test && (*(next(ptr,i)) >= -3.0 && *(next(ptr,i)) < 13.0);
    }
    // cout << endl;
    return test;
}


bool Gaussian_BNN_Mean(){

    Uncertain<double>* X = new Gaussian(1.0,0.1);
    Uncertain<double>* Y = new Gaussian(4.0,0.1);
    Uncertain<double>* Z = *X + *Y;
    double sum =0;
    Sampler<double> s;
    s.Create(Z);
    auto li = s.Take(100);
    vector<double>::iterator ptr = li.begin();
    bool test = true;
    for(int i=0; i<100; i++){
        sum += (*(next(ptr,i)));
        // cout << "new sample: " << (*(next(ptr,i))) << "| ";
    }
    // cout << endl;
    sum /= 100;
    test = (sum >= 4.11 && sum < 5.89);
    return test;
}

bool Gaussian_Bernoulli_Mean(){

    Uncertain<double>* X = new Gaussian(1.0,1.0);
    Uncertain<double>* Y = new Gaussian(3.0,2.0);
    Uncertain<double>* Z = *X > *Y;
    Sampler<double> s; 
    s.Create(Z); 
    auto li = s.Take(100);
    vector<double>::iterator ptr = li.begin();
    bool test = true;
    double sum = 0.0;
    for(int i=0; i<100; i++){
        // cout << (*(next(ptr,i))) << " | ";
        if((*(next(ptr,i))) >= 0.5){
            sum += 1;
        }
        // cout << "new sample: " << (*(next(ptr,i))) << "| ";
    }
    test = (sum >=13 && sum < 52);
    return test;
}


bool Gaussian_Bernoulli_Conditional(){
    //to ensure correct evaluation for each run, increase sample size in Pr(), however this may cause the code to take time while running ;)
    Uncertain<double>* X = new Gaussian(1.0,1.0);
    Uncertain<double>* Y = new Gaussian(4.0,2.0);

    Uncertain<double>* Z1 = *X > *Y;
    if(!Pr(*Z1)){cout << "X > Y evaluates true, incorrectly" << endl;}
    Uncertain<double>* Z2 = *Y < *X;
    if(!Pr(*Z2)){cout << "Y > X evaluates true, incorrectly" << endl;}
    Uncertain<double>* Z3 = *Y > *X;
    if(!Pr(*Z3)){cout << "Y > X evaluates false, incorrectly" << endl;}
    Uncertain<double>* Z4 = *X > *Y;
    if(!Pr(*Z4)){cout << "X > Y evaluates false, incorrectly" << endl;}

    return 1;

}



int main(){
    // Uncertain<double> *bp =  new Gaussian(10,1);
    // Uncertain<double> *bm = new Gaussian(2,0.4);
    // bp->Support();
    // cout <<  bp->GetSupport() << endl;
    // Gaussian x(10,2);
    // cout << (bp > bm)<< endl;
    // cout << (bp == bm)<< endl;
    // cout << (bp < bm)<< endl;
    // Sampler<double> s;
    // list<double> d = s.Create(*bp);
    // list<double> li = s.Take(100);
    // list<double>::iterator ptr2 = std::next(d.begin());
    // cout << *(li.begin())+1 << endl;
    // Sampler<double> s;
    // s.Create(*bp);
    // Uncertain<double> *X = new Gaussian(5.0,1);
    // auto sampler = s.Create(*X);
    // auto li = s.Take(100);
    // list<double>::iterator ptr = li.begin();
    // for(int i=0; i<10; i++){
    //     cout << *(next(ptr,i)) << endl;
    // }
    cout << Gaussian_sample() << endl;
    cout << Gaussian_Mean() << endl;
    cout << Gaussian_BNN_Sample() << endl;
    cout << Gaussian_BNN_Mean() << endl;
    cout << Gaussian_Bernoulli_Mean()<<endl;
    cout << Gaussian_Bernoulli_Conditional() << endl; 
    // Uncertain<double>* X =  new Gaussian(5.0,1.0);
    // Uncertain<double>* Y = new Gaussian(4.0,1.0);
    // cout << X->GetSupport() << endl;
    // Uncertain<double> Q = *X - *Y;
    // Uncertain<double> Q = *(&Q);
    // cout << Q.GetSupport() << endl;
    // Q = X+Y;
    // list<double> l;
    // l.push_back(0.9);
    // Uncertain<double> *Z = new Multinomial(l);
    // // cout << "HI Multinomial " << Z->GetSupport() << endl;
    // delete Z;
    // delete X;
//    for(int i=0; i<1; i++){
//        cout << X << endl;
//    }
    // Uncertain<double> Z = *X + *Y;
    Uncertain<double>* X = new Gaussian(10.0,0.1);
    Uncertain<double>* Y = new Gaussian(5.0,0.1);
    // Uncertain<double>* Z = *X + *Y;
    // cout << Z->GetSupport()<< endl;
    // Sampler<double> s;
    // s.Create(Z);
    // vector<double> li = s.Take(100);
    // vector<double>::iterator ptr = li.begin();
    // bool test = true;
    // for(int i=0; i<100; i++){
    //     cout << "new sample: " << (*(next(ptr,i))) << "| ";
    //     cout << "new sample " << li.at(i) << "|";
    //     test = test && (*(next(ptr,i)) >= -3.0 && *(next(ptr,i)) < 13.0);
    // }
    // cout << endl;
    // Uncertain<double>* X = new Flip(0.1);
    // cout << X->GetSupport() << endl; 
    Uncertain<double>* Z = *X > *Y;
    // cout << Flip(0.4).Score(1) << endl; 
    cout << Pr(*Z) << endl; 

    return 0;
}

// list<int> myfunc(){
//     list<int> some_list; 
//     some_list.push_back(1); 
//     some_list.push_back(1); 
//     return some_list; 
// }
// int main(){

//     list<int> x = myfunc(); 
//     list<int> y = x; 
//     cout << (x==y)<<endl; 
//     return 0;
// }