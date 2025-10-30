# 🚗 Bluetooth Controlled RC Car (ESP32 + BTS7960)

This project is a **Bluetooth-controlled RC car** built using an **ESP32 microcontroller** and **BTS7960 motor drivers**.  
The car is designed for smooth remote operation via a smartphone app and uses high-torque **500 RPM geared DC motors** mounted on a **metal chassis**.

---
## Photos 
![WhatsApp Image 2025-10-30 at 19 48 27_f43ebac4](https://github.com/user-attachments/assets/977d4e9b-2626-4008-b156-e8ff0af17f5d)
---


## 🧩 Components Used

| Component | Quantity | Description |
|------------|-----------|-------------|
| **ESP32** | 1 | Main microcontroller used for Bluetooth communication and motor control |
| **ESP32 Expansion Board** | 1 | Simplifies wiring and power connection |
| **BTS7960 Motor Driver** | 2 | Dual-channel high-current motor drivers used to control 4 DC motors (2 per driver) |
| **500 RPM Geared DC Motor** | 4 | Provides sufficient torque and speed for the car’s movement |
| **Metal Chassis** | 1 | Sturdy base for mounting motors, drivers, and controller |
| **Wheels** | 4 | Attached to DC motors for locomotion |
| **Connecting Wires** | — | For all electrical connections |
| **9V Battery** | 1 | Powers the ESP32 and drivers  |
| **2200 mAH LiPo battery** | 1 | Powers the motors  |


---

## ⚙️ Working Principle

1. **Bluetooth Control:**  
   The ESP32 connects to a smartphone via Bluetooth. A mobile app (such as *Arduino Bluetooth controller* from the Play Store) sends commands like **Forward**, **Backward**, **Left**, **Right**, and **Stop**.

2. **Signal Processing:**  
   The ESP32 receives these commands through its Bluetooth serial interface and decodes them in real-time.

3. **Motor Driving:**  
   - Two **BTS7960 drivers** handle the 4 motors (2 per driver).  
   - Each driver receives PWM signals from the ESP32 to control the direction and speed of the motors.

4. **Movement:**  
   - **Forward:** All motors rotate forward.  
   - **Backward:** All motors rotate backward.  
   - **Left / Right:** One side slows down or reverses to turn.  
   - **Stop:** PWM signals are set to 0.

---

## 🔌 Circuit Overview

**ESP32 Connections:**
- Each BTS7960 is connected to separate PWM and enable pins from the ESP32.
- logic power (5V) are derived from the expansion board.
- The 9V battery powers both motor drivers and ESP32 via the barrel jack of the expansion board.

**Basic Wiring Flow:**
- ESP32 → BTS7960 #1 → [Front Left + Front Right Motors]
- ESP32 → BTS7960 #2 → [Rear Left + Rear Right Motors]
- Battery → ESP32 Expansion Board (barrel jack)
- LiPo → BTS7960 #1and BTS7960 #2 (To power the motors)
  
  ---
  
---

## 📱 Mobile App Control

You can use any **Bluetooth Controller App**

**Typical Control Buttons:**
- 🔼 Forward  
- 🔽 Backward  
- ◀️ Left  
- ▶️ Right  
    

Pair the ESP32 via Bluetooth (device name will appear as *ESP32_BT* or similar) and start controlling your car.

---

## ⚡ Power Supply Notes

- The **9V battery**  powers the ESP32.
- The **2200 mAH LiPo** powers the motors



---

## 📸 Assembly Overview

1. Mount 4 geared DC motors onto the **metal chassis**.  
2. Attach **wheels** to the motor shafts.  
3. Secure **ESP32** (with expansion board) and both **BTS7960 drivers** on top of the chassis.  
4. Connect wires according to the wiring diagram.  
5. Power the system via the battery and connect through Bluetooth.

---

## 🧰 Tools Used

- Soldering iron and wires  
- Screwdriver and nuts/bolts  
- Multimeter (for connection checks)  

---

## 👨‍💻 Author

**Debanshu Sarkar**, **Sriparno Roy**, **Kaushani Das**, **Somoshree Halder**

B.Tech Student, Techno Main Saltlake  
*Project: Bluetooth Controlled RC Car using ESP32 and BTS7960 Motor Drivers*

---

## 📄 License

This project is open-source and free to modify or distribute for educational purposes.
