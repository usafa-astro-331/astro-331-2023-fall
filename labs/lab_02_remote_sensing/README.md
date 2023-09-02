# Lab 2: remote sensing

In this lab you will test FlatSAT's Arducam payload to determine if FlatSAT's imaging system will meet its resolution requirement from a 500 km orbit. You will record images of a resolution chart to determine the best resolution FlatSAT can achieve at distances ranging from 0.5 m to 5 m. You will extrapolate this to a 500 km distance and compare performance to your prelab predictions.



## equipment

- laptop
- micro USB cable
- resolution charts (big and normal)
- ruler and measuring tape

## hardware

* FlatSAT

  * components from lab 1
  * ArduCAM-M-2MP

## software

- Arduino IDE
- Arduino SAMD drivers (already installed)
- Arduino libraries (install by running `install_libraries.bat`)
  - ArduCAM
- `lab_02_remote_sensing.ino`

* Arducam Host V2



## setup

Connect components

- 2MP ArduCAM
  - as listed in `arducam_pins.h`
    - 2x I2C lines
    - power, ground
    - 4x SPI lines



ArduCAM-M-2MP communicates with Arduino using both I2C and SPI. The Arduino sketch handles these protocols with the `Wire` and `SPI` libraries. I2C: sensor configuration. SPI: camera commands and data stream (images). 

Note the orientation of the connections in the diagram: the camera board should be vertical with the sensor looking over the LCD. 

Connect power

- VCC (5 V)
- ground (any ground is fine)

Connect I2C comm lines--these are already in place from lab 1

- SDA
- SCL

Connect SPI comm lines

- SCK (clock)
- CIPO (controller in/peripheral out)*
- COPI (controller out/peripheral in)*
- CS (chip select)

**\*Note**: some components and documentation use master/slave terminology (MISO/MOSI), and some use controller/peripheral (CIPO/COPI). MISO = CIPO, MOSI = COPI. 

## Capture images

You will capture images of a resolution chart at multiple distances to determine the resolution of FlatSAT's camera payload. 

### upload FlatSAT code

Open `lab 02 camera payload.ino` in the Arduino IDE. 

Connect Arduino to computer via USB. 

Select the correct board (Arduino MKRZERO) and port. 

Upload your code. 

Open the serial monitor. 

### Configure ArduCAM Host GUI

Create a folder on the desktop with your group name. 

Open `ArduCAM_Host_V2.exe` from the `ArduCAM_Host_V2.0_Windows` folder. 

<img src="sources\ArduCAM_Host screenshot.png" alt="ArduCAM_Host screenshot" style="zoom:100%;" />

Set the following options:

- Port -> COMX (same port your Arduino is connected to)
  - click "Open" (purple button)
  - This opens serial communication between Arduino and ArduCAM Host. You should get a message that confirms COM is open.
- Pix -> 1200 x 1600 (the sensor's max/native resolution)
- SaveImage -> select (check)
- File -> (select your group's folder)

Hit the red "Capture" button to take an image. 

Review the image. If it is out of focus (completely blurry), turn the lens until the image is in focus. 

Take and save a photo of your team using ArduCAM. 

### Measure and prepare resolution chart

<img src="sources\ISO_12233-reschart letter.svg" alt="ISO_12233-reschart" style="zoom: 33%;" />

- There are two resolution charts printed at your lab station. They are also available electronically with these lab instructions. 
  
  - ISO_12233-reschart letter
  - ISO_12233-reschart big

- Using the metric ruler at your lab station, measure the height of the resolution chart (triangle-to-triangle). Note the remark at the top: "VALUES IN 100X LINES PER PICTURE HEIGHT."

- Verify the scale of the resolution markings. If the image height is 200 mm, at the 1 mark there should be 100 lines/200 mm, making each line 2 mm wide. 

- Note this scale for later use after the lab. 

- Repeat these steps for the large resolution chart. 

<img src="sources\ISO_12233-reschart big.svg" alt="ISO_12233-reschart" style="zoom: 33%;" />

### Position the camera and resolution chart

You will use your camera to record images at the same distances you predicted in the prelab (except 500 km). 

- Position the camera and resolution chart so that they are perpendicular at the same height and 0.5 m apart. Ensure the chart is illuminated evenly and both objects are sufficiently supported to remain still during image capture. 
- Click “Capture” to take the image. You may have to wait a few seconds for the data to transfer back to the computer. Once it has completed, you should get a message in the GUI and should be able to see a jpeg file in the location you specified. Double-click on the image, to ensure a satisfactory image. Re-take if necessary. 
- Once you are satisfied, rename the image with the distance in the filename. 
- Repeat this process for the distances calculated in your prelab (1, 2, and 5 m).

## Lab station cleanup

- Transfer all captured images to your group's storage location (your computer or share drive)
- Disconnect the micro-USB to USB cable from your laptop and the Arduino microcontroller
- Remove the ESD wrist straps and replace them in the bag at your lab station.
- Replace all items at your lab station the way you found them. 
- Close the GUI, close the Arduino IDE, and log out of the laptop.
- Have your instructor check off your lab station before you depart.

## Data Reduction (after the lab)

To determine the camera's resolution for each distance, find the point where you can distinguish each individual line. Refer to the scale you recorded during your lab. If the smallest lines you can resolve are 2/3 mm wide, your camera's resolution is 0.667 mm. 

Include the measured resolution for each distance (0.5 m, 1 m, 2 m, and 5 m) in the results section of your team’s final lab report. Is your resolution different in the corners vs the center of the image? If so, discuss possible causes. 
