#include "plan.h"

using std::cout;
using std::endl;

Plan::Plan(){
    callCount = 0;
    daytimeMinutes = 0;
    listCapacity = 20;
    calls = new Call * [listCapacity];
}

Plan::~Plan() {
    for (int i = 0; i < callCount; i++) {
        delete calls[i];
    }
    delete [] calls;
    callCount = 0;
    daytimeMinutes = 0;
    listCapacity = 20;
}

void swap(Call *xp, Call *yp) {
    Call temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void Plan::sortCalls(){
    int pos = 0;
    for (int i = 0; i < callCount - 1; ++i) {
      pos = i;
      for (int j = i + 1; j < callCount; ++j) {
        if (*calls[j] < *calls[pos]) {
          pos = j;
        }
      }
      swap(calls[i], calls[pos]);
    }
}

int detTime(int start, int dur){
    int smin = 60 * (start / 100) + start % 100;
    int emin = smin + dur; 
    const int dayStart = 420; // 7:00
    const int dayEnd = 1080; // 18:00
    if (emin < dayStart || smin > dayEnd) {
        return 0;
    } else if (smin < dayStart && emin > dayEnd) {
        return dayEnd - dayStart;
    } else if (smin > dayStart && emin < dayEnd) {
        return emin - smin;
    } else if (smin < dayStart && emin < dayEnd) {
        return emin - dayStart;
    } else {
        return dayEnd - smin;
    }
}

void Plan::add(Call call){
    if (callCount >= listCapacity) {
        listCapacity *= 2;
        Call ** newcalls = new Call * [listCapacity];
        for(int i = 0; i < listCapacity / 2; i++) {
            newcalls[i] = calls[i];
        }
        delete[] calls;
        calls = newcalls;
    }
    Call * newcall = new Call{call.date, call.startTime, call.duration}; 
    DayOfWeek weekday = call.date.getDay();
    if (weekday == DayOfWeek::Saturday || weekday == DayOfWeek::Sunday) {
        // do nothing
    } else {
        this->daytimeMinutes += detTime(call.startTime, call.duration);
    }
    calls[callCount++] = newcall;
    this->sortCalls();
}

void Plan::calculateBill(){
    const int freeMinutes = 150;
    const int monthlyFee = 2500; //in cents
    int exceededTime = daytimeMinutes - freeMinutes;
    exceededTime = exceededTime < 0 ? 0 : exceededTime;
    double fee = monthlyFee + exceededTime * 50;
    cout << *this << endl;
    const std::ostringstream default_format; 
    cout << "Day time minutes: " << this->daytimeMinutes << endl;
    cout << "Total cost ";
    cout.imbue(std::locale("en_US.utf8")); 
    cout << std::showbase << std::put_money(fee) << endl;
    cout.copyfmt(default_format);
    for (int i = 0; i < callCount; i++) {
        delete calls[i];
    }
    delete [] calls;
    callCount = 0;
    daytimeMinutes = 0;
    listCapacity = 20;
    calls = new Call * [listCapacity];
}

std::ostream & operator<<(std::ostream & out, const Plan & plan){
    if (plan.callCount){
        for (int i = 0; i < plan.callCount; i++) {
            Call call = *(plan.calls[i]);
            out << call << endl;
        }
    }
    return out;
}

