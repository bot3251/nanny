#include "WheelController.h"
#include <Arduino.h>

WheelController* wheelController = nullptr;  // Указатель на объект WheelController

WheelController::WheelController(int encoder_r_a, int encoder_r_b, int encoder_l_a, int encoder_l_b, 
                                 int d_w_r, int d_w_l, int a_w_r, int a_w_l) {
  this->encoder_r_a = encoder_r_a;
  this->encoder_r_b = encoder_r_b;
  this->encoder_l_a = encoder_l_a;
  this->encoder_l_b = encoder_l_b;
  this->d_w_r = d_w_r;
  this->d_w_l = d_w_l;
  this->a_w_r = a_w_r;
  this->a_w_l = a_w_l;

  // Инициализация пинов
  pinMode(encoder_r_a, INPUT);
  pinMode(encoder_r_b, INPUT);
  pinMode(encoder_l_a, INPUT);
  pinMode(encoder_l_b, INPUT);
  pinMode(d_w_r, OUTPUT);
  pinMode(d_w_l, OUTPUT);
  pinMode(a_w_r, OUTPUT);
  pinMode(a_w_l, OUTPUT);
  
  // Инициализация переменных PID
  kp = 0.7;
  ki = kp / 10;
  kd = kp / 2;
  target_r_speed = 70;
  target_l_speed = 70;
  error = 0;
  old_error = 0;
  error_summ = 0;
  old_time = millis();
  
  // Привязываем обработчики прерываний
  wheelController = this;  // Присваиваем указатель на текущий объект
  attachInterrupt(digitalPinToInterrupt(encoder_r_a), encoder_r_ISR_wrapper, RISING);
  attachInterrupt(digitalPinToInterrupt(encoder_l_a), encoder_l_ISR_wrapper, RISING);
}

void WheelController::pid() {
  int l_r = encoder_r_count;
  int l_l = encoder_l_count;
  
  time = millis();
  dt = (time - old_time) / 1000.0;

  error = l_r - l_l;
  error_summ += error * dt;
  
  u = error * kp + (error - old_error) / dt * kd + error_summ * ki;

  int w_r = target_r_speed + u;
  int w_l = target_l_speed - u;

  analogWrite(a_w_r, constrain(w_r, 0, 255));
  analogWrite(a_w_l, constrain(w_l, 0, 255));

  old_error = error;
  old_time = time;
}

void WheelController::encoder_r_ISR() {
  if (digitalRead(encoder_r_b) == HIGH) {
    encoder_r_count++;
  } else {
    encoder_r_count--;
  }
}

void WheelController::encoder_l_ISR() {
  if (digitalRead(encoder_l_b) == HIGH) {
    encoder_l_count++;
  } else {
    encoder_l_count--;
  }
}

int WheelController::getRightEncoderCount() {
  return encoder_r_count;
}

int WheelController::getLeftEncoderCount() {
  return encoder_l_count;
}

void encoder_r_ISR_wrapper() {
  if (wheelController != nullptr) {
    wheelController->encoder_r_ISR();
  }
}

void encoder_l_ISR_wrapper() {
  if (wheelController != nullptr) {
    wheelController->encoder_l_ISR();
  }
}
