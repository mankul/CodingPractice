#include<iostream>

using namespace std;


int movX[] = {1,-1, 0 , 0, 1, -1, 1, -1};
int movY[] = {0, 0, 1, -1, 1, 1, -1, -1};


int findPatternCount(char * arr, int r, int c, std::string pattern){
    int patternLength = pattern.length();
    int count = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            for(int direction = 0 ; direction < 8 ; direction++){
                bool stringMatch = true;
                for(int k = 0; k < patternLength; k++){
                    if(movX[direction] * k >= c || movX[direction] * k<0){
                        stringMatch =  false;
                        break;
                    }
                    if(movY[direction] * k >= r || movY[direction] * k < 0 ){
                        stringMatch = false;
                        break;
                    }
                    if(pattern[k] != *(arr + i*movY[direction]*k + j + movX[direction]) ){
                        stringMatch = false;
                        break;
                    }
                }
                if(stringMatch)
                    count+=1;
            }
        }
    }
    return count;
}



int main(){



    int r,c;// rows and columns
    cin>>r>>c;
    char WordMatrix[r][c];
    std::string matchingWord;
    cin>>matchingWord;
    for(int i = 0; i < r; i++){
        for(int j = 0 ; j < c; j++){
            cin>>WordMatrix[i][j];
        }
    }

    for(int i = 0 ; i < r; i++){
        for(int j = 0; j < c; j++)
            cout<<WordMatrix[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}