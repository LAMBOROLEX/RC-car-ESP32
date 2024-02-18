 #include <Arudiono.h>

 void customFunction() {
  Serial.print("callded customFunction");
 }

 int retunrNumber(int a, intb) {
  return a + b;
 }

 void setup() {
  customFunction();
 }

 void loop() {
  int result = returnNumber (a, a++);

  Serial.print(result);

  wait(1000);
 }