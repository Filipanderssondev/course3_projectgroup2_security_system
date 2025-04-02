# Step-by-Step Guide to Setting Up the Arduino IDE

## Step 1: Download the Arduino IDE

1. Go to the official [Arduino website](https://www.arduino.cc/en/software).
2. Choose the appropriate version for your operating system (Windows, macOS, or Linux).
3. **Download** the installer file for your operating system.

---

## Step 2: Install the Arduino IDE

### For Windows:
1. Run the installer you downloaded (`Arduino-x.y.z-windows.exe`).
2. Follow the installation prompts:
   * Select the installation folder (default is fine).
   * **Install drivers** if prompted.
   * Click **Install** to start the installation.
3. Once the installation is complete, click **Close**.

### For macOS:
1. Open the `.dmg` file you downloaded.
2. Drag the Arduino application to your **Applications** folder.
3. Open Arduino from the **Applications** folder.

### For Linux:
1. Extract the downloaded `.tar.xz` file.
2. Open a terminal, navigate to the extracted folder, and run the following commands:
   ```bash
   sudo ./install.sh


## Step 3: Open/launch the IDE.

## Step 4: Install the board drivers.
* It's both common and possible that your OS will automatically find and download the correct drivers when you first connect your board.
* If the OS hasn't downloaded the drivers automatically, we recommend that you search up the method to manually install said drivers for your system.

## Step 5: Selecting your board.
1. In the Arduino IDE, click the **Tools** option, followed by **Board**.
2. Find/Select your board.

## Step 6: Selecting the right Port.
1. In the Arduino IDE, click the **Tools** option, followed by **Port**.
2. Find and select the port your Arduino is connected to on your system.

## Step 7: Verify the Installation with a Test Sketch
* Open the Blink example sketch:
* Go to File > Examples > 01.Basics > Blink.
* Click the Upload button (right arrow) in the Arduino IDE toolbar.
* The IDE will compile and upload the sketch to your Arduino board. Once done, the built-in LED on the Arduino should start blinking.

## Step 8: Troubleshoot (if needed)
* If the upload fails, here are some things to check:

* Ensure the correct board and port are selected.
* Make sure the Arduino drivers are installed correctly.
* Try using a different USB cable or USB port on your computer.

## The IDE should now be ready for the project.
* You will find the .ino file used for the project in the **src** section of the repo.
* [Direkt link to the code](https://github.com/Filipanderssondev/course3_projectgroup2_security_system/blob/main/src/SAFE_AlarmSystem/SAFE_Alarm_System_v.1.0.ino)
