

#ifndef currency_
#define currency_


enum signType{
    plus,
    minus
};


class currency{


    private:
        signType sign;
        unsigned long dollars;
        unsigned int cents;

    public:
        //constucter
        currency(signType sign = plus, unsigned long dollars = 0, unsigned int cents = 0);
        
        //destructer
        ~currency();

        void setValue(signType, unsigned long dollars, unsigned int cents);
        void setValue(double);
        signType getSign() const{ return sign;};
        unsigned long getDollars() const { return dollars;};
        unsigned int getCents() const {return cents;};

        currency add(const currency& );
        currency& increment(const currency&);

        void output() const;

        currency operator+ (const currency ) const;

        void input(double);

};

#endif