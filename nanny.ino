#include "FaceRobot.h" // импорт класса матрицы робота
#include "Speaker.h" // импорт класса динамика робота
#include "Sensor.h" // импорт класса датчика робота
#include "WheelController.h"


WheelController wheelsController(2, 3, 4, 5, 12, 13, 10, 11);  // Создаем объект WheelController

FaceRobot faceRobot; // Создание обьекта лица робота

Speaker speaker(10, 11); // rxPin, txPin. Создание обьекта динамика робота

Sensor sensor_right(33, 32); // echo, trig. Создание правого датчика
Sensor sensor_left(37, 36); // Создание левого датчика
Sensor sensor_forward(31, 30); // Создание переднего датчика
Sensor sensor_back(35, 34); // Создание заднего датчика

void setup() {
  Serial.begin(9600); 
  faceRobot.start(); // инициализация лица
}
void yield() {
  faceRobot.start_smile(); // улыбка
}
void loop() {
}
