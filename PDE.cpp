#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
const float L = 1;
const float v_borde = 0;
const float v_placas = 100;
const float delta = 1/100;
const int N = 101;

void PDE();
int main(){
    PDE();
    return 0;
}

void PDE(){
    const float error = 0.01;
    float v_old[N][N] = {0};
    float v_new[N][N] = {0};
    for(int i = 20; i <= 80; i ++){
        v_old[40][i] = v_placas;
        v_old[60][i] = -1*v_placas;
    }
    float error_actual = 10.0;
    while(error_actual > error){
        for(int i = 1;i < N-1; i ++ ){
            for(int j = 1;j < N-1; j ++ ){
                if(i!=40 && i != 60 && j > 80 && j < 20){
                    v_new[i][j] = 0.25*(v_old[i+1][j]+v_old[i-1][j]+v_old[i][j+1]+v_old[i][j-1]);
                    if(i == 1 && j == 1){
                        error_actual = abs(v_new[i][j] - v_old[i][j]);
                    }
                    else{
                        if(abs(v_new[i][j] - v_old[i][j]) > error_actual){
                            error_actual = abs(v_new[i][j] - v_old[i][j]);
                        }
                    }  
                }
            }
        }
        for(int i = 1;i < N-1; i ++){
            for(int j = 1;j < N-1; j ++){
                v_old[i][j] = v_new[i][j];
            }
        }
    }
    
    ofstream outline;
    outline.open("datos.txt");
    for(int i = 0;i < N; i ++){
            for(int j = 0;j < N; j ++){
                outline << v_old[i][j] << " ";
            }
            outline << endl;
        }
}

