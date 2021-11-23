#include<iostream>

int abc_modify(int a, int b, int c){
    if (a < 0 && b < 0 && c < 0)
        throw 1;
    
    if ( a == 0 && b == 0 && c == 0)
        throw 2;

    return a*b*c;
}
void abc(int a, int b, int c){
    if (a <= 0 || b <= 0 || c<=0){
        // throwing an exception of const char *
        throw " All numbers are not less than zero"; 
    }
    std::cout<<"Memebers functions are greater than zero"<<std::endl;
}


int main(){
    try{
        abc(1,2,3);
    }
    catch(char * exception){
        std::cout<<exception<<std::endl;
    }
    try{
        abc(0,1,2);
    }
    catch(const char * exception){
        std::cout<<exception<<std::endl;
    }

    try{
        std::cout<<abc_modify(-1,-2,-3)<<std::endl;
    }
    catch(int e){
        std::cout<<"exception is "<<e<<std::endl;
    }
try{
        std::cout<<abc_modify(0,0,0)<<std::endl;
    }
    catch(int e){
        std::cout<<"exception is "<<e<<std::endl;
    }

}