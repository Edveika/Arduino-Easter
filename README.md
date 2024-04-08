<p align="center">
 <img src="https://github.com/Edveika/Arduino-Easter/assets/113787144/2d3fb8a2-249f-4e07-bc39-61ed8e855dde" height="400px">
</p>

# 🐣 Arduino-Easter

This is a physics lesson project that was assigned to me by my school. Its a egg roll ramp that has Arduino UNO mounted on it with sensors and a screen that shows how long it took for the egg to roll to the bottom of the ramp. The goal of this project is not only to practice the skills gained from the physics class but to also entertain the students of my school.

**You can find a demonstration of this project on [YouTube](#)**

# 🛠️ How does it work?

* There are two sensors. One at the top of the ramp and the other at the bottom. 

<p align="center">
 <img src="https://github.com/Edveika/Arduino-Easter/assets/113787144/06ea5abd-4462-4c3e-846a-ee27d5075d44" height="400px">
</p>

* The top sensor is the start sensor that is waiting for an egg to move past it and once it does, the timer starts. Before activated, green LED is lit to indicate that the user can roll the egg.

![1712524988200](https://github.com/Edveika/Arduino-Easter/assets/113787144/ff2b2d0c-404d-497f-970a-ea33cff59979)

* The bottom sensor can only be activated if the top sensor was activated first and the timer is started.

![1712524988207](https://github.com/Edveika/Arduino-Easter/assets/113787144/33df1098-82e9-4d4f-bf3a-c384c45560fe)

* Once the bottom sensor is activated, the timer is stopped and the rolling time is shown on the 4 digit screen.

![1712524988220](https://github.com/Edveika/Arduino-Easter/assets/113787144/0e6825fe-e076-4f08-ae6f-87de31b0bab2)

# ⚙️ Hardware & Components

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

# 📐 Schematics

# 🏗️ Engineering shenanagins

# 🚀 Features

* Measure time it takes the egg to roll from one sensor to the other
* Measure the speed of the egg(cm/s)
* LEDs to indicare the state of the egg roller ramp
  * Green - you can roll the egg
  * Red - you cant roll the egg, wait for the green light
* 4 digits screen that will show how much time it took the egg to roll to the bottom
* The sponge guarantees a smooth landing without breaking the egg

# 💿 Installing the firmware

1. Git clone this repo

```
git clone git@github.com:Edveika/Arduino-Easter.git
```

2. Open main.ino in your Arduino IDE

3. Make sure you have Arduino UNO libraries installed

4. Click verify and upload

# 🤝 Credits

🏫 School for the hardware and the project idea

👨‍💻 [SteponasK](https://github.com/steponask) for [Serial reader](https://github.com/SteponasK/Arduino-To-Excel)

👷🏻‍♂️ [ThePcCreator](https://github.com/ThePcCreator) for 4 digit display [library and schematics](https://github.com/ThePcCreator/Arduino-4-Digit-7-Segment-Display-Library)

# 📜 License

This project is licensed under the GPL v2 [LICENSE](LICENSE).
