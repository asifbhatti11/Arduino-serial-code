#include <Servo.h>
#include <ros.h>
#include <std_msgs/Int32.h>

Servo myservo0, myservo1, ESC;  
float servo0, servo1, esc;

ros::NodeHandle nh;

void servo0Cb(const std_msgs::Int32 &msg0)
{
  servo0=msg0.data;
  myservo0.write(servo0);
  Serial.println("servo0 angle:");
  Serial.println(servo0);
  

}
void servo1Cb(const std_msgs::Int32 &msg1)
{
  servo1=msg1.data;
  myservo1.write(servo1);
  Serial.println("servo1 angle:");
  Serial.println(servo1);

}

void escCb(const std_msgs::Int32 &msg2)
{
  esc=msg2.data;
  ESC.write(esc);
  Serial.println("ESC speed:");
  Serial.println(esc);

}
ros::Subscriber<std_msgs::Int32> sub0("servo0", &servo0Cb);
ros::Subscriber<std_msgs::Int32> sub1("servo1", &servo1Cb);
ros::Subscriber<std_msgs::Int32> sub2("esc", &escCb);
void setup() {
  Serial.begin(57600);
  
  myservo0.attach(2);
  myservo1.attach(3);
  ESC.attach(4);
  
  nh.initNode();
  nh.subscribe(sub0);  
  nh.subscribe(sub1);
  nh.subscribe(sub2);
}

void loop() {

  nh.spinOnce();
  delay(10);                           
}
