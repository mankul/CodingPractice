#include<iostream>

class IllegalParameterValue{
    private:
        char * message;
    public:
        IllegalParameterValue(): message("Illegel Parameter value"){};
        IllegalParameterValue(char * message_){
            message = message_;
        }
        void output_message(){
            std::cout<<message<<std::endl;
        }
};
int abc(int a, int b, int c){
    if ( a == 0 || b == 0 || c == 0){
        throw IllegalParameterValue("Either value equals to 0");
    }
    return a + b * c;
}

int main(){

    try{
        std::cout<<abc(0,1,2)<<std::endl;
    }
    catch(IllegalParameterValue e){
        e.output_message();
    }
    try{
        std::cout<<abc(1,2,3)<<std::endl;
    }
    catch( IllegalParameterValue e){
        e.output_message();
    }

}



