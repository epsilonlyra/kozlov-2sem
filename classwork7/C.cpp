#include<iostream>
using namespace std;
struct Time{
    int seconds = 0;
    int minutes = 0;
    int hours = 0;

    Time operator+(Time right){
        Time sum;

        sum.seconds = seconds + right.seconds;
        if (sum.seconds >= 60){
            sum.seconds -= 60;
            sum.minutes += 1;
        }

        sum.minutes += minutes + right.minutes;
        if (sum.minutes >= 60){
            sum.minutes -= 60;
            sum.hours += 1;
        }

        sum.hours += hours + right.hours;
        if (sum.hours >= 24){
            sum.hours -= 24;
        }
        return sum ;
    }

    friend ostream& operator<<(ostream &output, const Time &other) {
        output << other.hours << ":" << other.minutes << ":" << other.seconds;
        return output;
    }

    friend istream& operator>>(istream &input, Time &other) {
        input >> other.hours >> other.minutes >> other.seconds;
        return input;
    }
};

int main(){
Time present, delta;

cin >> present >> delta;
cout << (present + delta);
return 0;
}
