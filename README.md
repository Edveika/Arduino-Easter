<p align="center">
 <img src="https://github.com/Edveika/Arduino-Easter/assets/113787144/2d3fb8a2-249f-4e07-bc39-61ed8e855dde" height="400px">
</p>

# 🐣 Arduino-Easter

This is a physics lesson project that was assigned to me by my school. It's an egg roll ramp that has Arduino UNO mounted on it with sensors that measure how long the egg has rolled from top to bottom and a screen that shows the results. The goal of this project is not only to practice the skills gained from the physics class but to also entertain the students of my school.

**You can find a demonstration of this project on [YouTube](https://www.youtube.com/watch?v=FbbyMqFqj5Q)**

# 📚 Content table

* [🛠️ How it works](#how-does-it-work)
* [⚙️ Hardware & Components](#hardware-components)
* [📐 Schematics](#schematics)
* [🚀 Features](#features)
* [💿 Installing & Running](#installing-the-firmware-running)
* [🏗️ Engineering shenanagins](#engineering-shenanagins)
* [🤝 Credits](#credits)
* [📜 License](#license)

# 🛠️ How does it work? <a name="how-does-it-work"></a>

* There are two sensors. One at the top of the ramp and the other at the bottom. 

<p align="center">
 <img src="https://github.com/Edveika/Arduino-Easter/assets/113787144/a94b1819-14a8-4b65-8f12-8679e16b59bd" height="400px">
</p>

* The top sensor is the start sensor that is waiting for an egg to move past it and once it does, the timer starts. Before activated, green LED is lit to indicate that the user can roll the egg.

<p align="center">
 <img src="https://github.com/Edveika/Arduino-Easter/assets/113787144/bcb3535e-4478-44e6-bca3-79a83cd0b206" height="400px">
</p>

* The bottom sensor can only be activated if the top sensor was activated first and the timer is started.

<p align="center">
 <img src="https://github.com/Edveika/Arduino-Easter/assets/113787144/ac15de4e-5f5e-4f17-ba34-9f3d47669516" height="400px">
</p>

* Once the bottom sensor is activated, the timer is stopped and the rolling time is shown on the 4 digit screen.

<p align="center">
 <img src="https://github.com/Edveika/Arduino-Easter/assets/113787144/0223c412-6b18-42b2-9838-5e149e6ff62a" height="400px">
</p>

# ⚙️ Hardware & Components <a name="hardware-components"></a>

* Arduino UNO
* 2x UltraSound sensors
* 2x LEDs
  * Red LED
  * Green LED
* 4 digits screen
* 2x 220ohm resistor
* 2x BreadBoard
* Wires
* Sponge
* Egg roller ramp

# 📐 Schematics <a name="schematics"></a>

<p align="center">
 <img src="https://github.com/Edveika/Arduino-Easter/assets/113787144/2efe9380-9f6d-499a-9813-339b2d135963">
</p>

# 🚀 Features <a name="features"></a>

* Measure time it takes the egg to roll from one sensor to the other
* Measure the speed of the egg(cm/s)
* LEDs to indicare the state of the egg roller ramp
  * Green - you can roll the egg
  * Red - you cant roll the egg, wait for the green light
* 4 digits screen that will show how much time it took the egg to roll to the bottom
* The sponge guarantees a smooth landing without breaking the egg

# 💿 Installing & Running <a name="installing-the-firmware-running"></a>

1. Git clone this repo

```
git clone https://github.com/Edveika/Arduino-Easter.git
```

2. Open main.ino in your Arduino IDE

3. Make sure you have Arduino UNO libraries installed

4. Click verify and upload

**OPTIONAL:** download the [serial reader](https://github.com/SteponasK/Arduino-To-Excel) made by [SteponasK](https://github.com/steponask) to save egg roll data on your machine

# 🏗️ Engineering shenanagins <a name="engineering-shenanagins"></a>

* The sponge - imagine you've dyed a beautiful Easter egg, investing a lot effort to achieve just the right look. You probably don't want it to break. The sponge offers a perfect solution by effectively preventing the eggs from cracking upon impact with the ramp's bottom.

<p align="center">
 <img src="https://github.com/Edveika/Arduino-Easter/assets/113787144/54b15669-5048-4f19-9358-03fd9f2d7c74" height="400px">
</p>

* Long cables - the wires that come with the Arduino UNO are simply too short for a project like this. To solve this problem I decided to take a random wire, cut off the ends, expose the copper and connect the components with it. 

<p align="center">
 <img src="https://github.com/Edveika/Arduino-Easter/assets/113787144/3034aa3d-8291-4d30-aed2-92a5a19c298a" height="400px">
</p>

* Loose wires - connecting components with loose wires can cause short circuit. To solve this problem I took the original wires that came with Arduino UNO, cut them in half and connected them with the wires that are inside the cable mentioned above using duct tape. This solved two problems: too short wires, short circuit.

<p align="center">
 <img src="https://github.com/Edveika/Arduino-Easter/assets/113787144/08038046-4847-41a3-bdd3-c01e96184246" height="400px">
</p>

* Single 5V pin - since there is only one 5V pin I had to connect the long cable's wire to it to get 5V to the 2nd BreadBoard.

<p align="center">
 <img src="https://github.com/Edveika/Arduino-Easter/assets/113787144/cc403e8b-1ff5-4122-bfe7-7fae8c8567c6" height="400px">
</p>

# 🤝 Credits <a name="credits"></a>

🏫 School for the hardware and the project idea

👨‍💻 [SteponasK](https://github.com/steponask) for [Serial reader](https://github.com/SteponasK/Arduino-To-Excel)

👷🏻‍♂️ [ThePcCreator](https://github.com/ThePcCreator) for 4 digit display [library and schematics](https://github.com/ThePcCreator/Arduino-4-Digit-7-Segment-Display-Library)

# 📜 License <a name="license"></a>

This project is licensed under the GPL v2 [LICENSE](LICENSE).
