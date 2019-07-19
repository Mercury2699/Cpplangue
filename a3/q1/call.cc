#include "call.h"

using std::cout;
using std::endl;

Call::Call(Date date = Date(0,0,0), int startTime = 0, int duration = 0)
    : date{date}, startTime{startTime} , duration{duration} {}

bool Call::operator<(Call other) const{
    if (this->date == other.date) {
        int hr1, hr2, min1, min2; 
        hr1 = this->startTime / 100;
        hr2 = other.startTime / 100;
        min1 = this->startTime % 100;
        min2 = other.startTime % 100;
        if (hr1 > hr2) {
            return false;
        } else if (hr1 == hr2){
            if (min1 >= min2){
                return false;
            } else {
                return true;
            }
        } else {
            return true;
        }
    } else if (!(this->date < other.date)){
        return false;
    } else {
        return true;
    }
}

std::istream & operator>>(std::istream & in, Call & call){
    Date date{0,0,0};
    int start, dur;
    in >> date;
    in >> start;
    in >> dur;
    call = Call{date,start,dur};
    return in;
}

std::ostream & operator<<(std::ostream & out, Call call){
    out << std::setfill('0') << std::setw(4);
    out << call.date << " " ;
    out << std::setfill('0') << std::setw(4) << call.startTime << " ";
    out << std::setw(1) << call.duration;
    return out;
}
