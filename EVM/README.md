# Arduino Based Project

🗳️ Arduino Electronic Voting Machine

A simple Electronic Voting Machine (EVM) prototype built with Arduino, LCD (I2C), and push buttons.
Each button represents a candidate, and an additional button is used to end the voting process.
The LCD displays live votes and announces the winner.

⚡ Features

  Four candidates (A, B, C, D) with dedicated vote buttons.
 
  One "End Vote" button to stop voting and show results.
  
  LCD displays votes in real time and announces the winner.

  Handles tie situations by showing NO RESULT.

🔌 Hardware

  Arduino Uno

  16x2 I2C LCD

  5 Push buttons

  Breadboard + jumper wires

📷 Demo

  Press candidate buttons → votes are counted.

  Press "End Vote" button → voting stops, results are displayed.

  LCD shows total votes and the winner.

📜 Code

  The full Arduino sketch is included in this repository.


🛠️ Future Improvements

  Add EEPROM support to save votes even after reset.

  Secure voting logic with password-protected admin mode.


Secure voting logic with password-protected admin mode.
