#include <iostream>
using namespace std;
double sum, s;
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    for(int l = 0; l < 20; ++l){
        string subject, grade;
        double num;
        cin >> subject >> num >> grade;
        if(grade != "P") s += num;
        if(grade == "A+"){
            sum += num * 4.5;
        }
        else if(grade == "A0"){
            sum += num * 4.0;
        }
        else if(grade == "B+"){
            sum += num * 3.5;
        }
        else if(grade == "B0"){
            sum += num * 3.0;
        }
        else if(grade == "C+"){
            sum += num * 2.5;
        }
        else if(grade == "C0"){
            sum += num * 2.0;
        }
        else if(grade == "D+"){
            sum += num * 1.5;
        }
        else if(grade == "D0"){
            sum += num * 1.0;
        }
        else {
            continue;
        }
    }
    printf("%lf", sum / s);
}