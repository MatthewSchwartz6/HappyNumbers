#include <iostream>
#include <vector>

using namespace std;

void createArray(vector<int> *v, int n);
bool is_happy( int n);

int main (){
  int n = 0;

  cout <<"Number to check: ";
  cin>>n;
  cout<<endl;


  if (is_happy(n))
    cout<<"Yep its happy :)"<<endl;
  else
    cout<<"Nope its sad :("<<endl;

    return 0;
}

void createArray(vector<int>* v, int n){
  int number = n;
  int a = 0; int b = 0;
  a = number % 10;
  b = (number - a)/10;
  v->insert(v->begin(),a);
  while(b>10){
    number = b;
    a = number % 10;
    b = (number - a)/ 10;
    v->insert(v->begin(),a);
  }
  v->insert(v->begin(),b);
}

bool is_happy(int n){
  int j = 0;
  const int c = n;
  int num = n;
  
  while (j < 1000){
    int sum = 0;
    vector<int> *v = new vector<int>();
    createArray(v,num);

    for (int i = 0; i < v->size();i++){
      sum += (v->at(i) * v->at(i));
    }

    cout<< "The "<< j <<" number is: "<<sum<<endl;

    if (sum == 1){
      return true;
    }
    else if (sum == c){

      return false;
    }
    else {
      j++;
      num = sum;
    }
  }
  return false;
}
