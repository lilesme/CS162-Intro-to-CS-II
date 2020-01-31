#include <stdlib.h>
#include <exception>
#include <iostream>
//#include <exception>

template <class T>
class vector {
   private:
      T *v;
      int s;

   public:
      vector(){
	 s=0;
	 v=NULL;
      }

      ~vector(){
	 delete [] v;
      }

      int size() {
	 return s;
      }

      void push_back(T ele) {
	 T *temp;
	 temp = new T[++s];
	 for(int i=0; i<s-1; i++)
	    temp[i]=v[i];

	 delete [] v;
	 v=temp;
	 v[s-1]=ele;
      }

      //copy constructor
      vector (vector<T> &other){
	 if(s == 0){
	    delete [] v;
	    v = NULL;
	 }
	 else {
	    s = other.s;
	    for(int i = 0; i < s; i++){
	       v[i] = other.v[i];
	    }
	 }
      }

      //assignment operator 
      void operator = (vector<T> &other){
	 if(s == 0){
	    delete [] v;
	    v = NULL;
	 }
	 else{
	    delete [] v;
	    s = other.s;
	    for(int i = 0; i < s; i++){
	       v[i] = other.v[i];
	    }
	 }
      }

      T operator [] (int a){
         int size = 0;
	 size = v + (a * sizeof(vector<T>));
	 return size;
      }

      T at(int a){
	 try{
	    if(a > (s-1) || s<0){
	       throw std::exception();
	    }
	    else{
	       return v[a];
            }
	 }
	 catch(std::exception &e){
	    std::cout<<"out of bounds"<<std::endl;
	 }
      }
};
