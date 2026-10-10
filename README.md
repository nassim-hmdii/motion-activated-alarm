Motion activated Alarm 
Recently I decided to start learning electronics as I was fascinated by this topic since I was a kid. I decided to learn by building projects rather than following tutorials. 
Motion Alarm Detector will be my first project after performing the conventional first step of blinking a LED, this project is built as part of a project-by-project approach to learning electronics: pick a build, get stuck, learn exactly what's needed to get unstuck, move to the next one.

WHAT is DOES ?
A PIR sensor detects motion and triggers an alert using an LED + Buzzer 

WHAT a PIR Stand For ?
Before explaining the code I want to introduce and explain what is a PIR sensor. Passive Infra Red (IR) sensor is an electronic device that detects changes in heat or IR emitted by a source like us humans or animals. It uses two sensor slots to detect the potential change caused by an IR source entering or leaving its area of detection. 
To elaborate more under normal circumstances both sensors pick up roughly the same IR signal. When something warm moves in front of the sensor's field of view, it changes the signal hitting one slot before the other this differential change triggers an output signal which the microcontroller can use to perform certain actions (turn on an LED, trigger an alarm, start recording a video or a combination of all actions).

How Does a Micro Controller Read a PIR ?
I'm using an ESP32 for this project but the logic stays roughly the same for an Arduino or another micro controllers. The PIR should be connected to a 5V power source, a GND, and a digital pin that can read the output signal. The output signal acts both as HIGH voltage when it detects movements and LOW voltage when it is idle.
PS: be sure to check your PIR wiring before applying a voltage source. 

WHAT is my Project Process ?
For my project I decided to use a PIR sensor, an LED, and a Low trigger buzzer module. The operation will go as follows, the PIR will detect motion from a human, it'll send a HIGH 3.3V signal to the ESP32 23rd GPIO pin, the ESP32 will interpret that HIGH signal as activating a blinking led through pin 19 and activating the buzzer through pin 26. 

How Buzzers Works ?
The buzzer I am using has 3 ports, VCC, I/O, and GND. The VCC is connected to a 5V power source, GND to the ground, and I/O to a digital pin that can act as an output.

How Does the Code Works:

  pinMode(inputPin, INPUT_PULLDOWN);

I used INPUT_PULLDOWN on the PIR’s signal pin to avoid a floating input. Without it, an unconnected digital pin can pick up random electrical noise and read as HIGH even when nothing’s happening, which would trigger false alarms. Pulling the pin down means it reliably reads LOW by default, and only goes HIGH when the PIR actually signals motion.


    digitalWrite(buzzerPin, LOW);  // ON
    digitalWrite(buzzerPin, HIGH); // OFF

This buzzer module is active-low, meaning it turns ON when its signal pin reads LOW, and OFF when it reads HIGH, it is counter conventional. I start it HIGH (off) in setup(), then during an alert the code briefly pulls it LOW (on) to sound it, before setting it back HIGH (off) again.

    delay(wait);
    
delay() blocks the entire program while it runs, meaning the PIR isn’t being read again during that 200ms window. For this project, that’s an acceptable tradeoff: the goal is detecting that motion happened at all, not catching every single motion event back-to-back, one trigger is enough to sound the alarm.