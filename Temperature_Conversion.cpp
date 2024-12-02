#include <iostream>
using namespace std;


void fah(){
    float temp;
    float product;
    cout << "Enter temperature: "<< endl;
    cin >> temp;
    product = temp * 9/5 + 32;
    cout << product << endl;
}
void Cel(){
    float temp;
    float pro;
    cout << "Enter temperature: "<< endl;
    cin >> temp;
    pro = (temp-32)*5/9;
    cout << pro << endl;
    
}

void pick(){
    int choice = 0;
    cout <<"\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius"<< endl;
    cout << "Enter your conversion of choice: ";
    cin >> choice;
    switch (choice){
        case 1:
        fah();
        break;
        case 2:
        Cel();
        break;
    }
}
int main(){
    while (true){
        pick();
    break;
    }
	return 0;
    
}