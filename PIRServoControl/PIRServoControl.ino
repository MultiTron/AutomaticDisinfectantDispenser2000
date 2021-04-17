#include <Servo.h>

#define servoPin 13
#define sensorPin 12 //дефинираме пин за ПИР сезор
Servo servo;         //променлива серво

void setup()
{
  pinMode(sensorPin, INPUT); //задаваме работен режим на пин 12 отговарящ за ПИР сензора
  servo.attach(servoPin);    //Свързваме серво мотора с дигитален пин 12 на ардуиното
}

void loop()
{
  PIRSensor(); // извикваме метода
}

//метод
void PIRSensor()
{
  //проверка дали в обсега на сензора е засечено движение
  if (digitalRead(sensorPin) == HIGH)
  {
    servo.write(90); //задаваме градусна стойност за движение на серво мотора
  }
  else
  {
    servo.write(0);
  }
}
