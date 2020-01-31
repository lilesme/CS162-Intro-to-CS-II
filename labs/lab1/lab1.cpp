#include <iostream>
#include <cstdlib>


using namespace std;

struct mult_div_values{
   int mult;
   float div;
};

void set_mult_values(mult_div_values **table, int m, int n){

   cout<<"Multiplication Table"<<endl;
   for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
	 table[i][j].mult=(i+1)*(j+1);
      cout<<table[i][j].mult<<" ";
      }
      cout<<endl;
   }

}
void set_div_values(mult_div_values **table, int m, int n){
   
   cout<<"Division Table"<<endl;
   for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
	 table[i][j].div=(float(i+1)/(j+1));
      cout<<table[i][j].div<<" ";
      }
      cout<<endl;
   }
}
void delete_table(mult_div_values **table, int m){
   for(int i=0; i<m; i++){
      delete table[i];
   }
   delete [] table;
}


bool is_valid_dimensions(char *m, char *n){
 if((*m<49) || (*m>57)){
    cout<<"You did not enter a valid row"<<endl;
    return false;
 }
 else{
    return true;
 }
 if((*n<49) || (*n>57)){
    cout<<"You did not enter a valid"<<endl;
    return false;
 }
 else{
    return true;
 }

}

mult_div_values** create_table(int m, int n){
 mult_div_values **table;
 table = new mult_div_values *[m];
 for(int i=0; i<m; i++){
    table[i]= new mult_div_values[n];
 }
return table;
}

int main(int argc, char* argv[]){


   bool is_valid;
   do{
   is_valid= is_valid_dimensions(argv[1], argv[2]);
   }while(is_valid==false);
   int x; 
   int rows=atoi(argv[1]);
   int cols=atoi(argv[2]);
   
   mult_div_values **table = create_table(rows, cols);
   set_mult_values(table, rows, cols);
   set_div_values(table, rows, cols);
   delete_table(table, rows);
   
   return 0;


}
