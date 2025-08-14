# po10diy
A tiny video synthesizer in the pocket operator format

## Background


## Making your own
I'm not selling these, but this repository includes everything you'd need to make your own! And I encourage that! Please send me pics :)


# Hardware
## Supplies
I estimate that these cost around $100 to build. The most expensive parts of this are:
- The display ($45)
- The microcontroller ($15)
- The PCB (maybe $10-20 depending on where you get it from, how many you order, the tariffs du jour, etc).

### Parts
- 1 x [Adafruit Feather RP2040 with DVI](https://www.adafruit.com/product/5710)
- 1 x [Adafruit 2.7” 400x240 Sharp Memory Display](https://www.adafruit.com/product/4694)
- 2 x [10k potentiometer with built-in knob](https://www.adafruit.com/product/4133)
- 2 x [Breadboard-friendly 3.5mm stereo headphone jack](https://www.adafruit.com/product/1699)
- 1 x [Adafruit 400 mAh LiPo battery](https://www.adafruit.com/product/3898)
- 18 x [Surface-mount tactile switches](https://www.jameco.com/z/TL3301NF160QG-TR-JVP-Jameco-ValuePro-Surface-Mount-Tactile-Pushbutton-Switch-SPST-NO-OFF-MOM-50mA-12VDC-Tape-Reel_2334399.html)
- 18 x [Surface-mount 1N4148 diode](https://www.mouser.com/ProductDetail/Vishay/1N4148W-HG3_A-08?qs=Imq1NPwxi77PuyLGBhrVtQ%3D%3D)
- 2 x [Surface-mount 1.1k resistor](https://www.mouser.com/ProductDetail/Vishay-Beyschlag/MCS04020D1101BE000?qs=bTzheeSci6TjHr/d2PD0oQ%3D%3D)
  - R3 and R4 on the PCB
- 1 x [10.2k Surface-mount resistor](https://www.mouser.com/ProductDetail/Vishay/MCS04020D1022BE000?qs=pUKx8fyJudATYWOpd0Fc/A%3D%3D)
  - R1 on the PCB
- 1 x [15k Surface-mount resistor](https://www.mouser.com/ProductDetail/Vishay-Beyschlag/MCS04020C1502FE500?qs=81r%252BiQLm7BRdp6vG%252BWjYSQ%3D%3D)
  - R2 on the PCB
- 2 x [15 uF Surface-mount capacitor](https://www.mouser.com/ProductDetail/Murata-Electronics/GRM155R60G156ME01D?qs=doiCPypUmgFLObzcgpnt9Q%3D%3D)
  - C1 and C2 on the PCB
- 1 x [Slide switch](https://www.mouser.com/ProductDetail/E-Switch/EGJ1210AAT2?qs=%252BXxaIXUDbq28DPumZsnIIA%3D%3D)
- Standard 0.1” header pins and sockets, specifically:
  - One 12-pin female header
  - One 12-pin male header
  - One 16-pin female header
  - One 16-pin male header
  - One 9-pin male header (for the display)
  - You can buy these in bulk (I just had a bunch lying around), or you can get some from Adafruit, like [this](https://www.adafruit.com/product/2886) and [this](https://www.adafruit.com/product/3002)
- Custom PCB
  - I've uploaded the files for these too, so you can just order them directly
  - More details below
- 4 x M2 or M2.5 10mm machine screw
- 12 x M2 or M2.5 nut

### Tools
- Soldering iron
- Lead-free solder
- Low-temp solder paste
  - I used [Maker Paste](https://www.adafruit.com/product/3217)
- Hot plate
  - I used a TLBZK 100mm x 100mm 350W hot plate from Amazon
- Ventilation fan
- Snips
- Tweezers for positioning small components
- Hobby knife or file for cleaning up rough PCB edges


## PCB
Notes about the PCB

## Assembly steps

### 1. Cut or file down any rough edges on the PCB
- Mine came with little spiky protrusions from the manufacturing process, and I just snipped and filed them down

### 2. Unpackage and organize your parts
- The resistors especially are hard to tell apart, so keep everything nice and tidy and don't forget what's what!

### 3. Place the surface-mount diodes, resistors, and capcitors
- Pre-heat the hotplate according to your solder paste (I used Maker Paste and set my hotplate to 145 C)
- Squeeze out little dabs of maker paste on each of the pads for the diodes, resistors, and capacitors (we'll do the tactile switches in a separate step)
  - Some of these pads are quite small, so it can help to use a toothpick to scrape out little blobs of paste and wipe them where you want them, rather than squeezing from the tube directly onto the PCB
- Use small amounts of paste, and be especially cautious with the pads for the tiny resistors and capacitors, as they can easily form bridges when too much solder paste is used
- Use tweezers to position the diodes, resistors, and capacitors into their respective places one by one, and gently press them into the paste
  - R1 is the 10.2k resistor
  - R2 is the 15k resistor
  - R3 and R4 are the 1.1k resistors
  - The capacitors are identical but go in the spots marked C1 and C2
  - The diodes are also interchangeable but make sure the stripe on the diode is facing INTO the "C" shaped silkscreen marking, not away from it

### 4. Solder the diodes, resistors, and capacitors
- With the components all placed, put the PCB on the hotplate and let it melt the solder
- First you'll see the paste blobs spread out as the paste warms
- Then the liquid-y flux will boil off
- Then the solder balls in the paste will melt and reflow onto the pads, hopefully avoiding the solder mask
- This process takes a minute or two depending on the temperature
- Ideally you should see your components slide and adjust into place from the surface tension of the solder
- Watch carefully to make sure the solder paste is all melting at roughly the same time
  - If the board isn't sitting totally flat, press it down with a scredriver or tweezers to make sure it's heating evenly
- Look for any solder bridges that might have formed around the smallest components, and use tweezers or a craft knife to very gently remove some of the solder or smush it around until it separates again from the solder mask

### 5. Let the PCB cool
- It will be quite hot, so remove the PCB with tweezers or something similar and let it cool down and rest on a heat-safe surface
- Let it cool completely, to make the next step easier

### 6. Place the tactile switches
- Make sure the hot plate is preheating again if you shut it off earlier
- Like before, squeeze out solder blobs onto all the pads of the 18 tactile switches (though this time it will be a little easier to not make a mess since the pads are larger and further apart)
- Use tweezers to position the tactile switches on the blobs of solder paste

### 7. Solder the tactile switches
- Like before, put the PCB on the hotplate
  - I tried to have the top third of the PCB hanging off the plate so that the smaller components didn't heat up again, just in case their positioning got messed up, but I don't know how much of a difference this makes
- Wait a minute or two for the paste to melt and attach the switches

### 8. Let the PCB cool
- It's hot! Be careful!

### 9. Flip the board over and solder the 12 and 16 pin female header strips to the underside of the board
- The microcontroller will go on the back
- Strictly speaking you don't need the female header here, you could solder the feather to the circuit board directly with male header, but the female header makes it removable in case you want to use it for something else later, and it makes room for the battery to go underneath
- Trim the leads if they're long on the front side, the display will go above them and there's only so much room

### 10. Solder the 12 and 16 pin male header strips to the Feather
- The header should point "down" (i.e. the longer part should protrude from the flat bottom of the Feather), and you should be soldering it from the top of the Feather
- I like to just plug the male header into the female header we just soldered, then drop the Feather on top of that and solder — it holds everything in place!

### 11. Solder the audio jacks to the back of the board
- You may have to press quite firmly to get all five pins to slide into the holes at once, or even bend them a bit to align better

### 12. Solder the slide switch to the front of the board
- It's slim enough to fit under the display, so you can mount it on the front
- Note that when I designed the PCB I hooked up this switch backwards, so you slide it "down" / towards you to turn it on

### 13. Solder the potentiometers
- You may have to bend the side tabs in slightly to get them to align with the holes
- Double check the tilt of the potentiometers by looking at them from the side. It's easy for them to slightly lean one direction or the other.

### 14. At this point, you can test!
- Upload the code to the Feather using the procedure below to test the device with an external projector / monitor / TV and verify that the buttons and pots all work as expected
- This step is optional, but it's much easier to fix any issues with the diodes / resisotrs / capacitors now, before you solder the display on
- At a minimum, check the connections with a thorough visual inspection and maybe even with a multimeter
- Make sure there are no shorts from excess solder, and that all the components are fully and securely attached

### 15. Solder the male header to the display
- But do NOT solder it to rest of the PCB yet! That will be our final step because it depends on a few things being aligned first.

### 16. File down the right inner corner of the display to fit around Pot B
- Note that the lower mounting points of the display have a slight inner radius where they meet the main body of the display PCB
- This will bump into the hard corner of Pot B and make it hard to align the display properly
- With a craft knife or a file, you can shave down that inner corner radius to a right angle
- You may also need to file down the part of plastic casing of the potentiometers that faces the display a bit to get it to slide smoothly past them

### 17. Mount the display
- Thread bolts through the four mounting holes of the display
- If using M2 bolts, thread two nuts on each of the bolts to provide even spacing between the display and the main PCB
- If using M2.5 bolts, thread nuts only on the upper left, upper right, and lower left bolts (the nuts are too big to sit next to the pots)
- Mount the display to the main PCB using four more nuts
  - The already-soldered male header should be poking through the holes on the main PCB now

### 18. Solder the display



# Software

# Using it
