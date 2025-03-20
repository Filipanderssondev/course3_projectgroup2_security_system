# 🚨 SAFE Security System - User Manual for Dummies

## 📌 What is the SAFE Security System?
The SAFE Security System is a **simple home security system** that detects movement and alerts you with a **buzzer (alarm)** and a **blinking red light**.

This system is controlled by an **Arduino board** and includes:
- A **motion sensor** that detects movement.
- A **buzzer** that makes noise when movement is detected.
- An **LCD screen** that shows system messages.
- A **button** to turn the system ON/OFF and stop the alarm.
- Two **LED lights**:
  - **Green LED** = System is ON and ready. 
  - **Red LED** = System detected movement (alarm triggered).

---

## 🛠 What’s Included in the System?
| **Component**          | **What It Does** |
|------------------------|----------------|
| **Arduino Uno**        | The "brain" of the system that controls everything. |
| **PIR Motion Sensor**  | Detects movement. |
| **LCD Display**        | Shows messages about the system status. |
| **Buzzer**            | Makes a loud noise when movement is detected. |
| **LED Lights**        | Green = System ON, Red = Alarm triggered. |
| **Button**            | Used to turn system ON/OFF and stop the alarm. |

---

## 🔌 How to Set Up the System

### **1️⃣ Step 1: Power On the System**
1. **Connect** the Arduino board to a **USB power source** or a power adapter.
2. The **LCD screen** will display:  
3. The **Green LED** will turn ON, meaning the system is **ready to use**.

---

### **2️⃣ Step 2: Turning ON the Alarm Mode**
1. **Press the button once** to activate the alarm mode.
2. The **LCD will display:**
3. The **Red LED** will turn ON, meaning the system is **armed**.
4. If the **motion sensor** detects movement, the alarm will be triggered.

---

### **3️⃣ Step 3: When Motion is Detected**
- If someone **moves** in front of the motion sensor:
1. The **buzzer will start ringing** loudly.
2. The **Red LED** will start **blinking**.
3. The LCD will display:  
  ```
  Alarm: Intruder!
  ```
4. The system will keep ringing **until you press the button**.

---

### **4️⃣ Step 4: Stopping the Alarm**
1. **Press the button** to stop the alarm.
2. The buzzer will stop, and the LCD will show:  
3. The **Green LED** will turn ON, and the **Red LED** will turn OFF.
4. The system is now **ready to detect movement again**.

---

### **5️⃣ Step 5: Turning OFF the Alarm Mode**
1. **Press the button again** to turn OFF the alarm mode completely.
2. The LCD will display:  
3. The **Green LED** will stay ON, but the system will **not detect movement anymore**.
4. The system is now **inactive**.

---

## 🔍 Troubleshooting (If Something Goes Wrong)
| **Issue**              | **Possible Cause**                | **Solution** |
|------------------------|--------------------------------|-------------|
| **No power**          | Arduino not connected properly | Check the USB/power adapter. |
| **Alarm doesn’t trigger** | Motion sensor isn’t detecting movement | Make sure nothing is blocking the sensor. |
| **Alarm doesn’t stop** | Button is not working | Check that the button is properly connected. |

---

## 📌 Important Notes
- **The motion sensor may take a few seconds to reset** after detecting movement.
- **Press the button firmly** to make sure it registers.
- **Place the motion sensor** in an open area so it can detect movement properly.
- If the system stops working, **restart the Arduino** by unplugging and plugging it back in.

---

## 📊 Quick Summary of How to Use It
| **Action**            | **Result**                               |
|----------------------|----------------------------------------|
| **Press button once** | Alarm mode ON |
| **Move in front of sensor** | Alarm sounds, red LED blinks |
| **Press button again** | Alarm stops                          |
| **Press button once more** | Alarm mode OFF (System is inactive) |

---

🎉 **Now you're ready to use your SAFE Security System!** 🚀  
