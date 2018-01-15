#define IN1 10
#define IN2 9     //定义IN1接10引脚，控制左轮前进；IN2接9引脚，控制左轮后退
#define IN3 12 
#define IN4 13     //定义IN3接12引脚，控制右轮前进；IN4接13引脚，控制右轮后退
#define STEER 14

#include <Servo.h>
Servo servo_pin_14;

void forward( );
void back( );
void turnLeft( );
void turnRight( );
void turnbackLeft( );
void turnbackRight( );
void turnLeftOrigin( );
void turnRightOrigin( );
void _stop();          //声明要用到的函数

int TURN = 120;
int TURNZUO = 100;
int RUN1 = 100;//左轮前进
int RUN2 = 80;//右轮前进

void setup()
{
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  Serial.begin(9600);// 打开串口，并将数据传输速率设置为9600bps
}
//循环接受蓝牙信号，根据信号
int i;
void loop()
{
    if(Serial.available())// 判断是否收到消息，有则返回值为1，否则为0
    {
      i=Serial.read(); //从串口中读取信息，并作为返回值返回。
      
      switch(i) //根据接收到的信息运行不同函数
      {
        case'1':
          {turnLeft( );  break; }
        case'2':
          {forward( );   break;}
        case'3':
          {turnRight( );   break;}
        case'4':
          {turnLeftOrigin( );   break;}
        case'5':
          {_stop();   break;}
        case'6':
          {turnRightOrigin( );   break;}
        case'7':
          {turnbackLeft( );   break;}
        case'8':
          {back( );   break;}
        case'9':
          {turnbackRight( );   break;}
      }
    }    
}



//forward函数功能：控制车前进

void forward( )
{
  analogWrite(IN1,RUN2);      
  digitalWrite(IN2,LOW);         //左轮前进
  analogWrite(IN3,RUN1);      
  digitalWrite(IN4,LOW);         //右轮前进
}

//back函数功能：控制车后退

void back( )
{
  digitalWrite(IN1,LOW);      
  analogWrite(IN2,RUN1);        //左轮后退
  digitalWrite(IN3,LOW);      
  analogWrite(IN4,RUN1);        //右轮后退
}

// turnLeft函数功能：控制车左转

void turnLeft( )
{
  digitalWrite(IN1,LOW);      
  digitalWrite(IN2,LOW);         //左轮静止不动
  analogWrite(IN3,TURNZUO);      
  digitalWrite(IN4,LOW);         //右轮前进
}

// turnbackLeft函数功能：控制车左后转弯

void turnbackLeft( )
{
  digitalWrite(IN1,LOW);      
  digitalWrite(IN2,LOW);         //左轮静止不动
  digitalWrite(IN3,LOW);      
  analogWrite(IN4,TURN);         //右轮后退
}

//turnRight函数功能：控制车右后转弯

void turnRight( )
{
  analogWrite(IN1,TURNZUO);      
  digitalWrite(IN2,LOW);         //左轮前进
  digitalWrite(IN3,LOW);      
  digitalWrite(IN4,LOW);         //右轮静止不动
}

// turnbackRight：函数功能：控制车右转

void turnbackRight( )
{
  digitalWrite(IN1,LOW);      
  analogWrite(IN2,TURNZUO);         //左轮后退
  digitalWrite(IN3,LOW);      
  digitalWrite(IN4,LOW);         //右轮静止不动
}

// turnLeftOrigin函数功能：控制车原地左转

void turnLeftOrigin( )
{
  digitalWrite(IN1,LOW);      
  analogWrite(IN2,TURN);        //左轮后退
  analogWrite(IN3,TURN);      
  digitalWrite(IN4,LOW);         //右轮前进
}

// turnRightOrigin函数功能：控制车原地右转

void turnRightOrigin( )
{
  analogWrite(IN1,TURN);      
  digitalWrite(IN2,LOW);        //左轮前进
  digitalWrite(IN3,LOW);      
  analogWrite(IN4,TURN);       //右轮后退
}

// stop函数功能：控制车停止

void _stop()
{
  digitalWrite(IN1,LOW);      
  digitalWrite(IN2,LOW);         //左轮静止不动
  digitalWrite(IN3,LOW);      
  digitalWrite(IN4,LOW);         //右轮静止不动
}

