#ifndef WHEEL_CONTROLLER_H
#define WHEEL_CONTROLLER_H

class WheelController {
public:
  WheelController(int encoder_r_a, int encoder_r_b, int encoder_l_a, int encoder_l_b, 
                  int d_w_r, int d_w_l, int a_w_r, int a_w_l);

  void pid();
  void encoder_r_ISR();
  void encoder_l_ISR();
  int getRightEncoderCount();
  int getLeftEncoderCount();

private:
  volatile int encoder_r_count;
  volatile int encoder_l_count;
  int encoder_r_a;
  int encoder_r_b;
  int encoder_l_a;
  int encoder_l_b;
  int d_w_r;
  int d_w_l;
  int a_w_r;
  int a_w_l;
  float kp;
  float ki;
  float kd;
  int target_r_speed;
  int target_l_speed;
  int error;
  int old_error;
  float error_summ;
  float u;
  float time;
  float old_time;
  float dt;
};
extern WheelController* wheelController;  // Только объявление
// Прототипы ISR-обработчиков
void encoder_r_ISR_wrapper();
void encoder_l_ISR_wrapper();

#endif
