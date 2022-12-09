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
#### Motor Driver
![image (4)](https://user-images.githubusercontent.com/57039762/206571892-28a6c287-2fe1-4890-81dc-837b262cc285.png)

#### Mbed
![image (5)](https://user-images.githubusercontent.com/57039762/206571933-dc31d99f-980a-413e-8704-4251c6981424.png)

#### Power Railings
![image (3)](https://user-images.githubusercontent.com/57039762/206571819-1b1d2bf7-4224-4daa-bf74-560b9a5bc337.png)


## MECHANICAL SUBSYSTEM
### THE BOX
The box is the base of the rotating turn table. All files that need to be cut can be found in the [Laser-Cutting-Files](https://github.com/katelynprovost/4180-Final-Project-Gifting-Table/tree/main/Laser-Cutting-Files) folder. 

#### Required Parts
- (x6) 1/8" - 12x12" Plywood Sheets
- (x1) 1/8" - 12x12" Acrylic Sheet
- (x4) M3 Screws
- (x4) M3 Nuts
- Wood glue

#### Illustrator Files
Here are a description of the holes in each Illustrator file:

**Box_Three_Sides.ai**
1. Top: (rectangle) Mbed USB cable, (circle #1) barrel jack connector #1, (circle #2) barrel jack connector #2
2. Middle: (x2 circles) Through holes to feed IR sensor & uLCD wires
3. Bottom: no holes, side piece

**Box_Last_Side.ai**
1. (rectangle) Opening to access breadboards
2. (x4 circles) Through holes to screw acrylic cover on (optional)

**Box_Bottom.ai**
1. No holes, bottom of box

**Box_Top.ai**
1. (x1 circle) Large hole to next DC motor
2. (x4 circles) Through holes to secure DC motor to top of box

### THE TURN TABLE
The turn table is the part of this device that holds the gift and rotates. All files that need to be cut can be found in the [Laser-Cutting-Files](https://github.com/katelynprovost/4180-Final-Project-Gifting-Table/tree/main/Laser-Cutting-Files) folder. 

#### Required Parts
- (x1) 3/16" - 24x24" Plywood Sheet
- (x3) 1/8" - 12x12" Plywood Sheets
- (x4) 1/2" - 1.5x1.5" Wood blocks 
- (x4) 3/4" Wooden balls (or any material)
- (x1) 3/4" - 1x1.75" Aluminum Block
- (x1) M4 - 20mm Screw (Set screw for motor)
- (x4) M5 - 25mm Screws (Secure aluminum block to table top)
- Wood Glue

#### Illustrator Files
**Table_Bottom.ai**
1. (rectangles) Slots for securing dividers
2. (x4 circles) Through holes to secure aluminum block

**Table_Dividers.ai**
1. No holes

#### Aluminum Block
The aluminum block was created with a drill press by creating 5 holes on the front side using a 1/4" drill bit.
![aluminum block Front View](https://user-images.githubusercontent.com/35545192/206573625-7c2fbf88-4982-4bb1-8167-58b02b9c62cf.png)

From there, from the top side, I then created a hole going to the center hold where the motor shaft would go to using a 5/32" drill bit, and then used a tap and die set to tap on a M4 threading into the hole.

![aluminum block Top View](https://user-images.githubusercontent.com/35545192/206574170-4f44651b-ce1f-4f27-8601-a1758cc76914.png)

## DEMO VIDEOS
### 1 MINUTE EXPLANATION

https://user-images.githubusercontent.com/57039762/206563006-d1e433b8-86a9-482a-a3b2-f2434675120a.mp4

### SHORT DEMO 
To use, first place your gift you're giving away in an empty slot. Then wave your hand in between the IR Sensors to spin the table.

https://user-images.githubusercontent.com/57039762/206561998-83649456-30dc-48b3-a93e-b3a1992a9514.mp4

## FINAL PRODUCT PHOTOS
![IMG_9409](https://user-images.githubusercontent.com/35545192/206773687-f66dca78-9bc5-435e-96e6-23d3ab1ac4d0.jpg)
![IMG_0175](https://user-images.githubusercontent.com/35545192/206774405-af2a7573-d269-4eb2-b5ad-6ab92b2a64b0.jpg)
![IMG_0176](https://user-images.githubusercontent.com/35545192/206774409-d718ab4e-088d-4948-b5d4-6f5dc1caca9d.jpg)
![IMG_9410](https://user-images.githubusercontent.com/35545192/206773662-3492726c-1aa5-45b0-866d-c131ed86582e.jpg)
![IMG_0168](https://user-images.githubusercontent.com/35545192/206773665-591f966b-3090-4b2f-b0a5-847c2a55f912.jpg)
![IMG_0169](https://user-images.githubusercontent.com/35545192/206773670-a0dd5b34-d5c0-4131-8a65-ef131d33cbaf.jpg)
![IMG_0171](https://user-images.githubusercontent.com/35545192/206773673-cce49dfc-7d72-4130-92ad-58f4f4343744.jpg)
![IMG_0172](https://user-images.githubusercontent.com/35545192/206773675-ddabf124-06d6-4550-9314-315c81745174.jpg)
![IMG_0173](https://user-images.githubusercontent.com/35545192/206773678-18bc955e-1a52-439b-b968-821745b0cd3c.jpg)
![IMG_0174](https://user-images.githubusercontent.com/35545192/206773682-03cebf8e-d1f1-421e-9156-fb2b8997e73f.jpg)



