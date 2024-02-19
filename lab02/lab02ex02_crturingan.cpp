#include <iostream>
#include <cmath>
#include <string>

using namespace std;


template<typename T>
class Pair {
    private:
        T first, second;
    public:
        Pair(T first, T second);
        //Accessor
        T get_first();
        T get_second();

        //mutator
        void set_first(T val);
        void set_second(T val);
        Pair<T> operator+(Pair b);
        Pair<string> operator/(Pair<string> b);
        double operator/(Pair<double> b);
        void show_pair();
};



template<typename T>
Pair<T>::Pair(T first, T second) {
    this -> first = first;
    this -> second = second;
}

template<typename T>
T Pair<T>::get_first() {
    return this -> first;
}

template<typename T>
T Pair<T>::get_second() {
    return this -> second;
}

template<typename T>
void Pair<T>::set_first(T val) {
    this -> first = val;
}

template<typename T>
void Pair<T>::set_second(T val) {
    this -> second = val;
}

template<typename T>
void Pair<T>::show_pair() {
    cout << this -> first << " and " << this -> second << endl;
}

template<typename T>
Pair<T> Pair<T>::operator+(Pair b) {
    return Pair(this -> first + b.first,
                this -> second + b.second);
}

template<>
Pair<string> Pair<string>::operator/(Pair<string> b) {
    int c = 0; // c - count of letters
    int o = 0; // o - number of occurence
    char l; // l - letter with highest occurence in the string
    string str_combined = this->first + this->second + b.first + b.second; // concatenate all paired strings
    int s = size(str_combined); // size of the concatenated string
    
    for (int i = 0; i < s; i++){ // loop the string to get the letter to compare from
        char *ptr1 = &str_combined[i]; // ptr1 hold the letter to compare from
        for (int j = 0; j < s; j++){ // loop again to the string to compare the *ptr1 value to the letter in the string
            char *ptr2 = &str_combined[j]; // hold the letter to compare to
            if (*ptr1 == *ptr2){ // compare if the value of *ptr1 adn *ptr2 is the same 
                c++; // if true, add 1 to the counter
            }
        if(c > o){ // after the inner loop, check if the counter is more than the current highest occurence
            o = c; // if True, set the occurence equal to the counter
            l = *ptr1; // set the letter to the value of *ptr1
        }    
        }
        c = 0; // reset the counter
    } 

    return Pair<string>(string(1,l) , to_string(o));
}

template<>
double Pair<int>::operator/(Pair<double> b) {
    // Calculate the average of the integers in the pair
    double avg = (this->first + this->second + b.first + b.second) / 4.0; // add all the values and divide by 4
    return avg; // return average
}

int main() {

    string str1, str2, str3, str4;
    int num1, num2, num3, num4;
    // Pair<string> p_str = Pair<string>("Banana B1", "Banana B2");
    // Pair<int> p_int = Pair<int>(3,5);

    // p_str.show_pair();
    // p_int.show_pair();

    // Pair<string> p1 = Pair<string>("1","2");
    // Pair<string> p2 = Pair<string>("3","4");
    // (p1+p2).show_pair();

    cin >> str1 >> str2;
    cin >> str3 >> str4;
    
    cin >> num1 >> num2;
    cin >> num3 >> num4;

    Pair<string> s1 = Pair<string>(str1,str2);
    Pair<string> s2 = Pair<string>(str3, str4);
    (s1/s2).show_pair();

    //comment if average dont work
    Pair<int> n1 = Pair<int>(num1,num2);
    Pair<int> n2 = Pair<int>(num3, num4);
    cout << n1/n2 << endl;

    return 0;
}
