# 4180 FINAL PROJECT: THE GIFTING TABLE
The following repository contains the parts list, code, and set up instructions for creating your very own Gifting Table!

**Contributors:** Yu Chang (@yuchang2) & Katelyn Provost (@katelynprovost)

## PROJECT IDEA
This project is a small gift exchange table made to be used at festivals and small events where gifting is a core value. The goal of this is to allow people to exchange small items (such as trinkets, mugs, jewelry, etc.) similar to a [Little Free Library](https://littlefreelibrary.org/). 

> Take a gift. Leave a gift. 

Our exchange table has interactive LEDs, sensors, and turntable to provide an engaging experience for the user. The table spins for a randomized amount of time so you never know which gift you will get--will it be a happy surprise? ,':) 

The table can hold up to 8 gifts at a time, and it can be powered with a generator for use at events where electricity may not be available. 

## ELECTRONICS SUBSYSTEM
### HARDWARE REQUIRED
- (x1) [Mbed 1768](https://os.mbed.com/platforms/mbed-LPC1768/)
- (x1) [uLCD-144](https://os.mbed.com/users/4180_1/notebook/ulcd-144-g2-128-by-128-color-lcd/)
- (x1) [DC Gear Motor](https://www.phidgets.com/?tier=3&catid=19&pcid=16&prodid=279)
- (x1) [Motor Driver](https://www.sparkfun.com/products/14451)
- (x1) [IR Beam Break Sensors](https://www.adafruit.com/product/2167)
- (x1) [NeoPixel Digital RGB LED Strip](https://www.adafruit.com/product/1376?length=1)
- (x1) [Terminal Block](https://www.pololu.com/product/2440)
- (x2) [Barrel Jack Connectors](https://www.mouser.com/ProductDetail/OSEPP-Electronics/LS-00015?qs=wNBL%252BABd93NMhbCmcntoKg%3D%3D&mgh=1)
- (x5) Capacitors - (x4) 220uF & (x1) 1000uF
- (x3) Push Buttons
- (x2) Breadboards 

### WIRING DIAGRAM


## MECHANICAL COMPONENTS
### THE BOX
The box is the base of the rotating turn table. All files that need to be cut can be found in the [Laser-Cutting-Files](https://github.com/katelynprovost/4180-Final-Project-Gifting-Table/tree/main/Laser-Cutting-Files) folder. 

Here are a description of the holes in each Illustrator file:

**Box_Three_Sides.ai**
1. Top: (rectangle) Mbed USB cable, (circle #1) barrel jack connector #1, (circle #2) barrel jack connector #2
2. Middle: no holes, side piece
3. Bottom: no holes, side piece

**Box_Last_Side.ai**
1. (rectangle) Opening to access breadboards
2. (x4 circles) Through holes to screw acrylic cover on (optional)

**Box_Bottom.ai**
1. No holes, bottom of box

**Box_Top.ai**
1. (x1 circle) Large hole to next DC motor
2. (x4 circles) Through holes to secure DC motor to top of box

## DEMO VIDEOS
### 1 MINUTE EXPLANATION

https://user-images.githubusercontent.com/57039762/206563006-d1e433b8-86a9-482a-a3b2-f2434675120a.mp4

### SHORT DEMO 
To use, first place your gift you're giving away in an empty slot. Then wave your hand in between the IR Sensors to spin the table.

https://user-images.githubusercontent.com/57039762/206561998-83649456-30dc-48b3-a93e-b3a1992a9514.mp4

