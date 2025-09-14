Arduino Based Project

🔐 Arduino Password Based Lock
📌 Project Overview:

A password-protected lock system built with Arduino, a 4×4 keypad, an I2C 16×2 LCD and a servo motor.
User can set a custom password length at startup, enter a password with masked input, and the servo unlocks on correct entry. The system enforces progressive lockout delays and a physical reset after repeated failures.

⚙️ Key Controls (exact behavior):

Enter password length: type digits, then press A to save the length.

If you entered the length incorrectly, press B, C, or D to restart length setup.

Set password: after saving length, type the password digits. The password is stored for the session.

During password entry:

B → Clear all digits (restart the current password entry).

C → Confirm / submit the entered password.

After 4 wrong attempts → system shows SYSTEM LOCKED and requires the external reset button to reboot and restart setup.

⚙️ Features:

Custom password length (user defined at startup)

Masked password input on LCD (*)

Clear-all key (B) during entry

Confirm key (C) to submit password

Save-length key (A) during startup length input

Servo unlocks to 90° on successful authentication and returns to 0° afterward

Progressive lockout delays after failed attempts: 5s → 15s → 30s

After 4 failures → SYSTEM LOCKED until physical reset button pressed

🖥️ How It Works (flow):

Boot → Enter Length

Enter digits for desired password length, press A to save. If mistaken, press B/C/D to re-enter length.

Set Password

Type password digits (length = saved length). The sketch stores the password.

Enter Password

LCD shows ENTER PASSWORD. Type digits (they appear as *).

Press B to clear whole entry and restart typing.

Press C to submit the password.

Result

If correct → ACCESS GRANTED, servo rotates to 90° for a short time, then returns to 0°.

If incorrect → ACCESS DENIED and lockout delay applies (first wrong = 5s, second = 15s, third = 30s).

After 4 wrong attempts → SYSTEM LOCKED until reset button is pressed (reboots the system and returns to length setup).


🚀 Future Improvements:

Add RFID / fingerprint for multi-factor auth

Add a small web or Bluetooth interface for admin actions
