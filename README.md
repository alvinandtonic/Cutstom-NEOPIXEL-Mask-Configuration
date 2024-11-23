
# **Interactive LED Face Animation**

This project is an interactive LED-based face animation system built using NeoPixel LED strips, a Bluefruit microcontroller, and customizable button inputs. The system displays different facial expressions based on button combinations, making it perfect for creative installations or robotics projects.

---

## **Features**
- **Interactive Control**: Three buttons control various facial expressions.
- **Custom Animations**: Includes pre-defined expressions like happy, mad, smirk, and more.
- **Dynamic Effects**: Animations like "crazy" cycle through multiple expressions rapidly.
- **User-Friendly Design**: Compact setup using a repurposed Dell CRT monitor chassis.

---

## **Hardware Components**
- **Chassis**: Repurposed **Dell CRT Monitor**.
- **Microcontroller**: **Adafruit Bluefruit** for easy programming and Bluetooth connectivity.
- **LED Strips**: **NeoPixel LED Strips** (90 LEDs per strip) for vibrant and customizable lighting.
- **Buttons**: **TS-D001** tactile switches for user input.
- **Power Supply**: Powered by **AA Batteries** for portability.

---

## **Setup Instructions**
1. **Connect the Hardware**:
   - Attach NeoPixel LED strips to the Bluefruit microcontroller.
   - Connect buttons to the designated pins (`A3`, `A4`, `A5`) on the Bluefruit.
   - Mount all components within the Dell CRT monitor chassis.

2. **Upload the Code**:
   - Install the **Adafruit NeoPixel library** in the Arduino IDE.
   - Configure the microcontroller in the IDE for the **Bluefruit board**.
   - Upload the provided code to the microcontroller.

3. **Power On**:
   - Insert AA batteries into the power supply.
   - Turn on the system and interact using the buttons.

---

## **How It Works**
- Each button or combination of buttons triggers a specific animation:
  - **Button 1 (A3)**: Displays "talking" animation.
  - **Button 2 (A4)**: Displays "mad" animation.
  - **Button 3 (A5)**: Displays "dead" animation.
  - **Multiple Buttons**: Combines animations, like "crazy" mode when all buttons are pressed.
- The LED strips light up in pre-defined patterns, creating expressive faces.

---

## **Software Details**
- **Programming Language**: Arduino C++.
- **Libraries Used**:
  - [Adafruit NeoPixel Library](https://github.com/adafruit/Adafruit_NeoPixel).
- **Main Features**:
  - Customizable facial expressions controlled via buttons.
  - Simple modular code structure for adding new expressions.

---

## **Hardware Diagram**
Below is the mapping of hardware connections:
- **LED Strip 1 (Eyes)**: Connected to `A1`.
- **LED Strip 2 (Mouth)**: Connected to `A2`.
- **Button 1**: Connected to `A3`.
- **Button 2**: Connected to `A4`.
- **Button 3**: Connected to `A5`.

---

## **Acknowledgments**
This project was inspired by the LED mask design used by DJ **Chayboss**. Special thanks to him for allowing me to create a similar project for personal, non-commercial purposes.

---

## **License**
This project is for **personal use only** and is not licensed for commercial purposes. The design is inspired by DJ Chayboss's LED mask, and any commercial use of this project or its derivative works is prohibited.

---

## **Future Enhancements**
- **Bluetooth Integration**: Control animations remotely via a smartphone app.
- **Battery Optimization**: Replace AA batteries with a rechargeable Li-ion battery.
- **Additional Animations**: Add more facial expressions and animations.
- **Sound Effects**: Sync animations with sound for a richer experience.

---

## **Gallery**
Uploaded soon


