#include <iostream>
#include "PID.h"


using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double kkp, double kki, double kkd) {
  Kp = kkp;
  Ki = kki;
  Kd = kkd;

}

void PID::UpdateError(double cte) {
  old_cte = cte;
  cte_total+=cte;  
}

double PID::TotalError() {
  return cte_total;
}
