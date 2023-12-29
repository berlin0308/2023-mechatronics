
<img width="698" alt="image" src="https://github.com/berlin0308/2023-mechatronics/assets/90204339/a6274634-1316-4b4e-9891-f1a7e449b465">


# I. Introduction

Our robot is designed to be controlled remotely through video streaming. Its primary functions include navigating around and performing vacuuming tasks. Our core philosophy is to minimize space to enhance the robot's agility. In addition, careful study and design of the vacuum is essential to ensure sufficient cleaning efficiency. 
However, fulfilling both requirements simultaneously is not an easy task. In the next chapter, we divided our system design into three main parts: Mechanical Design, Hardware & Electrical Design, and Software & User Interface. 

# II. System Design

## 1.	Mechanical Design

### 1.1 Overview

Our robot is comprised of three layers in a circular design, allowing it to rotate in place. Its diameter is restricted to just 18 centimeters for enhanced agility. The main structural components are in the middle (in x, y axis) and underneath (in z axis) to ensure balance. 

The top layer mainly consists of an Arduino and RPi, forming the core for computation and control. The middle layer houses the vacuum and motor structures, along with the power control circuit. The lowest layer aligns the omnidirectional wheels, drive wheels, and vacuum nozzle at the same height to ensure the vacuum remains close to the ground, maximizing suction efficiency.

<img width="1046" alt="image" src="https://github.com/berlin0308/2023-mechatronics/assets/90204339/61ac3a0a-a510-4023-9ea4-3125729166d9">


For securing each mechanical component, we strictly use keyholes and screws instead of direct adhesion. Additionally, with an emphasis on superior industrial design, the body of the robot features a combination of wood tones and white. This choice underlines a lightweight, minimalist, and homely style. 

### 1.2 Vacuum Design

Unlike other groups using fan-induced duct flow to direct dust into a collection box, we utilized a fan close to the ground to create a pressure difference, sucking in dust. Then, using centrifugal force, it disperses the dust to settle onto the dustbin. 

We adopted this method for two reasons: First, integrating the nozzle and dustbin into a single mechanism reduces space occupation, aligning with our core philosophy. Second, a fan positioned close to the ground minimizes pressure loss.

During the midterm test, we adopted a circular design as shown in Figure (a). However, due to the nozzle being too close to the ground and the opening too narrow, precise alignment was necessary to vacuum up scraps of paper. In the final test version, shown in Figure (b), we precisely adjusted the mechanism's height and enlarged the opening. Additionally, we conceived and validated a fact: a rectangular opening effectively creates turbulence in corners, enhancing the vacuum's cleaning performance.

Figure (c) provides a closer look. The blue region indicates the spatial occupation of the fan. Acting like a pump, the fan generates an airflow (red arrows) that dives into the interior with turbulence induced (orange arrows). The fan then disperses the dust (blue arrows), letting it to settle into the dustbin (grey arrows).

<img width="1050" alt="image" src="https://github.com/berlin0308/2023-mechatronics/assets/90204339/ae119d54-7a7c-4de3-9b15-abe8ddb4b89b">



### 1.3 Front Sensor and Robotic Eyes 

During the mid-term test, we employed a video-streaming strategy but encountered visibility issues when the robot was too close to walls. To address this, we installed an ultrasonic sensor at the front for corner detection. Upon detecting a corner, the device activates 'storm' mode, which involves spinning in place with the vacuum on.

In addition, to enhance its appearance and for fun aspects, we equipped the front side with an LCD display that shows different expressions during various states, as illustrated in Figures (a), (b), and (c).

<img width="1028" alt="image" src="https://github.com/berlin0308/2023-mechatronics/assets/90204339/4e61c76d-aeae-4a3e-96d9-9d25733b0be9">


## 2. Hardware & Electrical Design

Figure (a) illustrates our focus on achieving seamless integration of diverse components within a comprehensive circuit to augment both the functionality and power efficiency of the robot. The integrated components encompass a battery box, switch, vacuum motor, wheel motor, motor driver, RGB LED, ultrasonic sensor, camera, LCD, relay, power converter, Raspberry Pi, and Arduino Uno. 

A notable feature of our approach is the incorporation of a power converter in tandem with a relay, facilitating the robot to operate all devices using only a single battery box. This innovation eliminates the necessity for external power sources, setting our design apart from other teams' configurations that commonly rely on supplementary mobile power supplies.

<img width="870" alt="image" src="https://github.com/berlin0308/2023-mechatronics/assets/90204339/9b6c6fc2-b766-4da7-a3ff-fdcf0e46b92c">



## 3. Software & User Interface

Figure (b) represents the user interface developed by our team for this project. Unlike other groups utilizing App Inventor or other pre-existing toolkits, our team constructed the operational interface using HTML. Beyond the fundamental functionalities of basic directional controls for upward, downward, leftward, and rightward movement, our interface incorporates an additional feature known as the 'storm' function, depicted by the lightning cloud icon in Figure (b). This function enables powerful vacuuming upon reaching areas with accumulated dust.

Furthermore, the background design adopts a cyberpunk style to align with the visually striking appearance of our robotic vacuum cleaner. This cohesive design approach aims to ensure consistency between the device's aesthetics and its user interface.

The innovative use of HTML in crafting the interface sets our project apart, offering a tailored and visually engaging control system for the user. This deliberate design choice not only enhances usability but also complements the futuristic and captivating appeal of our robotic cleaner.



Figure (c) illustrates the conceptual diagram depicting the intercommunication and interaction between backend programs. Through interface buttons, messages are transmitted to 'main.py,' residing within our Raspberry Pi (RPI), which further relays these instructions via serial transmission to the Arduino for execution. This successful process fulfills the objectives of the class, specifically achieving communication and mechanical integration between the RPI and Arduino.
 
All these programs are hosted within our RPI, allowing us to utilize SSH from a computer within the same network domain for remote control. Employing these methods and technologies reflects our aim to simulate real-world operational environments for robotic vacuum cleaners. Typically, these operations involve remote communication via the internet from home environments. Therefore, this concept aligns with the core principle driving the initial design of our software.

# III. Discussion

## 1.	 Challenges

### 1.1	Mechanical Design

<img width="1079" alt="image" src="https://github.com/berlin0308/2023-mechatronics/assets/90204339/502f347e-f31d-4cb7-82f1-12779060e21a">


### 1.2	Software System Control

<img width="1075" alt="image" src="https://github.com/berlin0308/2023-mechatronics/assets/90204339/8f8ba3ba-9cdf-47bd-b3d0-31e83b8d95fd">


## 2.	Test Reviews

<img width="856" alt="image" src="https://github.com/berlin0308/2023-mechatronics/assets/90204339/1a8be6c2-a493-4b32-b8ce-4c3f60e50c2d">


# IV.	Appendix

## Members and Teamwork

<img width="906" alt="image" src="https://github.com/berlin0308/2023-mechatronics/assets/90204339/6efd05fd-2e04-42b4-b219-9740886c5871">






