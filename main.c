#include <stdio.h>
#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/distance_sensor.h>

#define TIME_STEP 32
#define NUM_SENSORS 16

int main() {
  char sensor_name[20];
  double distance[20];

  wb_robot_init();

  WbDeviceTag sensors[NUM_SENSORS];

  WbDeviceTag front_left_wheel  = wb_robot_get_device("front left wheel");
  WbDeviceTag front_right_wheel = wb_robot_get_device("front right wheel");
  WbDeviceTag back_left_wheel   = wb_robot_get_device("back left wheel");
  WbDeviceTag back_right_wheel  = wb_robot_get_device("back right wheel");

  wb_motor_set_position(front_left_wheel,  INFINITY);
  wb_motor_set_position(front_right_wheel, INFINITY);
  wb_motor_set_position(back_left_wheel,   INFINITY);
  wb_motor_set_position(back_right_wheel,  INFINITY);

  for (int i = 0; i < NUM_SENSORS; i++) {
    sprintf(sensor_name, "so%d", i);
    sensors[i] = wb_robot_get_device(sensor_name);
    wb_distance_sensor_enable(sensors[i], TIME_STEP);
  }

  wb_motor_set_velocity(front_left_wheel,  1);
  wb_motor_set_velocity(front_right_wheel, 1);
  wb_motor_set_velocity(back_left_wheel,   1);
  wb_motor_set_velocity(back_right_wheel,  1);

  while (wb_robot_step(TIME_STEP) != -1) {
    for (int i = 0; i < NUM_SENSORS; i++) {
      double value = wb_distance_sensor_get_value(sensors[i]);
      distance[i] = value;
      printf("Sensor %d: %f\n", i, value);
    }

    if (distance[11] < 150) {
      wb_motor_set_velocity(front_left_wheel,  -1);
      wb_motor_set_velocity(front_right_wheel, -1);
      wb_motor_set_velocity(back_left_wheel,   -1);
      wb_motor_set_velocity(back_right_wheel,  -1);

      wb_robot_step(10);

      wb_motor_set_velocity(front_left_wheel,  1);
      wb_motor_set_velocity(front_right_wheel, 0);
      wb_motor_set_velocity(back_left_wheel,   1);
      wb_motor_set_velocity(back_right_wheel,  0);
    }
    else if (distance[3] < 150) {
      wb_motor_set_velocity(front_left_wheel,  1);
      wb_motor_set_velocity(front_right_wheel, 1);
      wb_motor_set_velocity(back_left_wheel,   1);
      wb_motor_set_velocity(back_right_wheel,  1);

      wb_robot_step(10);

      wb_motor_set_velocity(front_left_wheel,  0);
      wb_motor_set_velocity(front_right_wheel, 1);
      wb_motor_set_velocity(back_left_wheel,   0);
      wb_motor_set_velocity(back_right_wheel,  1);
    }
    else {
      wb_motor_set_velocity(front_left_wheel,  1);
      wb_motor_set_velocity(front_right_wheel, 1);
      wb_motor_set_velocity(back_left_wheel,   1);
      wb_motor_set_velocity(back_right_wheel,  1);
    }

    printf("\r\n");
    wb_robot_step(500);
  }
}
