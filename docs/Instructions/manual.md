# SAFE Security System - User Manual

## Introduction
The SAFE Security System is a **motion-detecting alarm system** that helps **detect intruders** and alerts you with a buzzer and an LED indicator. It includes a **PIR motion sensor**, a **buzzer**, an **LCD display**, and an **activation button** to turn the system ON and OFF.

This guide will help you understand **how to use the system step by step**.

---

## System Components
1. **Arduino Uno** – The brain of the system.
2. **PIR Motion Sensor** – Detects movement in the area.
3. **LCD Display** – Shows system messages and alarm status.
4. **Buzzer** – Sounds an alarm when motion is detected.
5. **LEDs** –  
   - **Green LED**: Indicates that the system is active and in standby mode.  
   - **Red LED**: Blinks when an intruder is detected.  
6. **Button** – Used to **activate/deactivate** the system and stop the alarm.

---

## How to Use the System

### Step 1: Powering On
1. **Connect** the Arduino to a **USB power source** or a power adapter.
2. The LCD will display:  
3. The **Green LED** will turn ON, indicating the system is ready.

---

### Step 2: Activating the Alarm Mode
1. **Press the button once** to activate the alarm mode.
2. The **LCD will display:**
3. The **Red LED** turns ON, showing that the system is now **armed**.
4. If the PIR motion sensor **detects movement**, the alarm will activate.

---

### Step 3: Alarm Triggered
- If motion is detected:  
1. The **buzzer will start ringing** loudly.  
2. The **Red LED** will start **blinking**.  
3. The LCD will display:  
  ```
  Alarm: Intruder!
  ```
4. The system will remain in this state until the alarm is manually turned off.

---

### Step 4: Deactivating the Alarm
1. **Press the button** to turn OFF the alarm.
2. The buzzer will stop, and the LCD will show:  
3. The **Green LED** will remain ON.
4. The system is now **inactive** and will **not detect motion** until reactivated.

---

## Troubleshooting

| **Issue**               | **Possible Cause**               | **Solution**                                  |
|-------------------------|---------------------------------|----------------------------------------------|
| No power               | Arduino not connected           | Check the USB/power adapter.                 |
| Alarm does not trigger | PIR sensor not detecting movement | Ensure the sensor is positioned correctly.  |
| Alarm does not stop    | Button not working              | Ensure the button is correctly connected.   |

---

## Additional Notes
- **PIR Sensor Delay**: If the PIR sensor is active when turning ON the alarm mode, it may take a few seconds before it is ready.
- **Press the button firmly** to ensure it registers the input.
- **Place the PIR sensor** in an area where it has a clear view of the space to detect motion effectively.
- If the alarm gets stuck, **restart the Arduino** by unplugging and plugging it back in.

---

## Summary

| **Action**            | **Result**                               |
|----------------------|----------------------------------------|
| **Press button once** | Alarm mode ON (System is armed)       |
| **Motion detected**  | Alarm sounds, red LED blinks          |
| **Press button again** | Alarm stops                          |
| **Press button once more** | Alarm mode OFF (System is inactive) |

---

**Now you're ready to use your SAFE Security System! 🚀**
