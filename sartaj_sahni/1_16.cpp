#include<iostream>
#include"currency.h"




currency::currency( signType sign_, unsigned long dollars_, unsigned int cents_){
    sign =sign_;
    dollars = dollars_;
    cents = cents_;
    output();
}

currency::~currency(){
    std::cout<<"Destructor"<<std::endl;
}

currency currency::add(const currency& curr){
    // add *this and curr
    long a1, a2, a3;
    currency result;

    a1 = dollars * 100 + cents;
    if (sign == minus)
        a1 = -a1;
    a2 = curr.dollars * 100 + curr.cents;
    if (curr.sign == minus)
        a2 = -a2;

    a3 = a1 + a2;

    if (a3 < 0){
        result.sign = minus;
        a3 = -a3;
    }
    result.dollars = a3/100;
    result.cents = a3  - result.dollars * 100 ;
    
    return result;

}

currency & currency::increment(const currency & curr){
    *this = add(curr);
    return *this;
}


void currency::output() const {
    if (sign == minus)
        std::cout<<"-";
    std::cout<<"$"<<dollars<<".";
    if ( cents < 0)
        std::cout<<"0";
    std::cout<<cents<<std::endl;
    
}


currency currency::operator+( const currency curr) const{
    long a, b, c;
    currency result;

    a = this->dollars* 100 + this->cents;
    if (this->sign == minus)
        a = -a;
    b = curr.dollars * 100 + curr.cents;
    if (curr.sign == minus)
        b = -b;
    c = a + b;
    if ( c < 0){
        result.sign = minus;
        c = -c;
    }
    result.dollars = c/100;
    result.cents = c - result.dollars * 100;

    return result;
}


void currency::input(double curr){
    if(curr < 0){
        this->sign = minus;
        curr = -curr;
    }
    else{
        this->sign = plus;
    }

    double temp = curr * 100;
    this->dollars = temp/100;
    this->cents = temp - this->dollars * 100;
}


std::istream& operator>>(std::istream& in, currency curr){
    double input;
    in>>input;
    curr.input(input);
}

std::ostream& operator<<(std::ostream& out, const currency curr){
    curr.output();        
    return out;    
}



int main(){


    currency  * curr = new currency(plus, 10);
    currency curr2(plus, 20, 34);
    currency curr3;

    curr3 = curr2 + * curr;
    std::cout<<"sum is "<<curr3<<std::endl;
}