
#include <IRremote.h>

int PIN_IR = 2;
IRrecv irrecv(PIN_IR);
decode_results ir_code;

void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling IR in");
  irrecv.enableIRIn();
  Serial.println("Enabled IR in");
}

void loop() 
{
  if (irrecv.decode(&ir_code)) 
  {
    Serial.println(ir_code.value, HEX);
    irrecv.resume(); 
  }
  delay(500);
}
