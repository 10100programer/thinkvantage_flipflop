# ThinkVantage Button Flip-Flop

This small utility allows you to map a button, such as the ThinkVantage button, to toggle between two commands in a flip-flop manner.

## Features

- Toggles between two commands with a single button press.
- Lightweight and easy to configure.
- Designed to work seamlessly with window managers like **i3-gaps**.

## Installation

1. Compile the program using your preferred C/C++ compiler (e.g., `gcc`):
   ```bash
   gcc -o thinkflip thinkflip.c
   ```
2. Rename the compiled binary if desired and move it to your `/bin` directory:
   ```bash
   mv thinkflip /bin/thinkflip
   ```

## Configuration

1. Map the button you want to use as the toggle. For example:
   - If you use **i3-gaps** as your window manager, add the following line to your i3 config file (typically `~/.config/i3/config`):
     ```bash
     bindsym XF86Launch1 exec thinkflip
     ```
   - Replace `XF86Launch1` with the keycode or button name you want to use.

2. Save the configuration and reload your window manager. In i3, this can be done with:
   ```bash
   i3-msg reload
   ```

## Notes

- The program is intentionally minimal; name it whatever suits your setup.
- Default behavior is to toggle between two pre-defined commands. Update the source code to customize further if needed.
