#include "temperature.h"

// CLASS FUNCTION DEFINITIONS GO HERE

Temperature::Temperature() {
    kelvin_ = 0;
  }

Temperature::Temperature(double kelvin) {
    kelvin_ = kelvin;
  }

Temperature::Temperature(double temp, char unit) {
    if (toupper(unit) == 'C') {
      SetTempFromCelsius(temp);
    } else if (toupper(unit) == 'F') {
      SetTempFromFahrenheit(temp);
    } else {
      SetTempFromKelvin(temp);
    }
  }

void Temperature::SetTempFromKelvin(double kelvin) {
    kelvin_ = kelvin;
  }

void Temperature::SetTempFromCelsius(double celsius) {
    kelvin_ = celsius + 273.15;
  }

void Temperature::SetTempFromFahrenheit(double fahrenheit) {
  kelvin_ = (5.0 * (fahrenheit - 32) / 9) + 273.15;
  }

double Temperature::GetTempAsKelvin() const {
    return kelvin_;
  }

double Temperature::GetTempAsCelsius() const {
    return kelvin_ - 273.15;
  }

double Temperature::GetTempAsFahrenheit() const {
    double f;
    f = ((GetTempAsCelsius() * 9.0) / 5) + 32;
    return f;
  }

string Temperature::ToString(char unit) const {
    stringstream ss;
    string s;
    ss << std::fixed << std::setprecision(2);
    if (toupper(unit) == 'K') {
      ss << GetTempAsKelvin() << " Kelvin";
    } else if (toupper(unit) == 'C') {
      ss << GetTempAsCelsius() << " Celsius";
    } else if (toupper(unit) == 'F') {
      ss << GetTempAsFahrenheit() << " Fahrenheit";
    } else {
      ss << "Invalid Unit";
    }
    s = ss.str();
    return s;
  }
