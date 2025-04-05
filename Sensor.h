#ifndef SENSOR_H
#define SENSOR_H

#include <NewPing.h> // Библиотека для работы с ультразвуковыми датчиками

class Sensor {
public:
  Sensor(int pin_echo, int pin_trig); // Конструктор
  int get_value(); // Метод для получения значения с датчика

private:
  NewPing sonar; // Объект NewPing
  int MAX_DISTANCE = 30; // Максимальное расстояние для измерений
  int PIN_ECHO;
  int PIN_TRIG;
};

#endif
