


std::unique_ptr<className> ptr= make_ptr<className>();

int * a ;




int c;


void f(int  b){

};


class A{
    int a;
    void f();
    void g();
};

class B:A{

}

void df(A & t){

}

B b;
df(b);


// list of ints. a number sum . find two numbers sum equal to the given number;
// sort it. iteration and binary search. nlogn + nlogn.
// iterate and use a dictionary to store the diff of number and sum and find it if it is there.
// n space n time complexity.



void swap(int & a, int & b){
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(vector<int> & list, int left, int right){
    if(left == right)
        return;
    int pivot = (left + right)/2;
    swap(list[pivot], list[right]);
    int i = left;
    int j= left;
    while(i < right){
        if(list[i] < list[right]){
            swap(list[i], list[j]);
            j+=1;
        }
        i+=1;
    }
    swap(list[j], list[right]);
    quicksort(list, left, j-1);
    quickSort(list, j+1, right);
}

void search(vector<int> list, int fi, int & si, int sum){
    int left = fi;
    int right = list.length() - 1;
    while(left <= right){
        int mid = (left + right)/2;
       
        if(list[mid] + list[fi] == sum ){
            si = mid;
            return;
        }
        if(list[mid] + list[fi] > sum){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
            
    }
}
// 1,2,3,4,5
int main(){
    vector<int> list;
    int sum = 9;
    
    for(int i = 0 ; i <  10; i++){
        list.push_back(i);
    }
    quickSort(list,0, 9);
    int num = -1;
    for(int i = 0; i <  10; i++){
        search(list, i + 1, num, sum);
        if(num != -1)
        {
            cout<<list[i]<<" "<<list[num]<<endl;
            break;
        }
    }

}




f(5);
