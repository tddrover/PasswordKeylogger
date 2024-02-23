# Kernel Module Keylogger

The Kernel Module Keylogger is a Linux kernel module designed to log keystrokes made on the system's keyboard. It operates by intercepting keyboard events and recording the pressed keys, providing insights into user activity on the system. It will log the keystrokes if it is a possible password, 15 characters, at least one upper and lower case letter, and a number or special character.  

Features
- Logs keystrokes made on the system's keyboard.
- Operates as a kernel module, integrating directly with the Linux kernel.
- Records up to 100 possible passwords


Screenshots: 

<div display="flex">
<img src="/pictures/Screenshot_1.png" alt="Image 1" width="50%" />
</div>


How to Run the App:
- Navigate to the directory with the files and compile the module with "make"
- Load the module into the kernel with "sudo insmod PasswordKeylogger.ko"
- Once the module is loaded, it will begin logging keystrokes made on the system's keyboard. You can check possible passwords by running "sudo dmesg"

Unload the Kernel Module
- Use "sudo rmmod PasswordKeylogger" to remove the NetworkMonitor module from the kernel

Important Notes
- Use caution when deploying kernel modules, as they operate at a low level and can impact system stability.
- Ensure that you have the necessary permissions to load kernel modules (insmod requires root privileges).
- Respect user privacy and legal considerations when deploying keylogging functionality.
