//
// Created by Kina on 2020/11/14.
//
#include <iostream>

using namespace std;

/* Global variable */
int T, test_case, N, L;
int costs[1024];
double min_cost;

/* Constraint */
// C <= 100
// 1 <= N && N <= 1000
// 1 <= L && L <= 1000
// L <= N
// costs[i] <= 100(integer)

int main(void){
    cin>>T;
    for(test_case = 1; test_case<=T; ++test_case){
        min_cost = 100.0;
        cin >> N >> L;
        for(int i=0; i<N; i++){
            cin>>costs[i];
        }
        // 0<= idx < N
        for(int start=0; start<=N-L; start++){
            int sum = 0;
            int len = 0;
            for(int i=start; i<start+L; i++){
                sum += costs[i];
                len++;
            }
            double cost = (double)sum/(double)(len);
            if(cost<min_cost){
                min_cost = cost;
            }
            for(int i=start+L; i<N; i++){
                sum += costs[i];
                len++;
                cost = (double)sum/(double)(len);
                if(cost<min_cost){
                    min_cost = cost;
                }
            }
        }
        printf("%.11f\n", min_cost);
    }
    return 0;
}