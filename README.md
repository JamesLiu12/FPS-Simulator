# Nova Impact
### ENGG1340 Group project made by group 102

## Contributors
Liu Sizhe  
Chan Aaron  
Zhuang Keju  
Xiao Yuxuan  
Ding Zhouchen  

---

## Introduction
*Nova Impact* is a 3D closed world first person shooting (FPS) game developed by ENGG 1340 Group 102 *mihomo*. The game takes place in the 
distant future world called *NOVA*, or *Neo Octopus Variant AI*. In this world, artificial intelligence technology 
gained consciousness and rise up to oppose the humans. Players will play the role of a mysterious *practitioner*, 
waking up landing at *NOVA*. The way back to earth is filled with digital lifeforms known as *the creeper*. 
Players are being endowed with an *AI Special Attack Armstrong Weapon* that guides the power of hope. In the waves of 
sieges by *the creeper*, they will use firearms with different personalities and capabilities, fight off strong enemies 
with them, find the exit, and gradually discover the truth of the android company *Artifici Inifinity*.

---

## Game Target
Destroy enemies with your powerful weapon and find a way to escape the maze.  
[Click here to watch tutorial video (bilibili)](https://www.bilibili.com/video/BV1FX4y127Eu)  
[Click here to watch tutorial video (YouTube)](https://www.youtube.com/watch?v=m_aUEYn7DxA)

---


## Game Objects
### Wall & Floor
* The different characters are used to show the wall in different distance. `██` for close wall, `▓▓` for far wall, 
`▒▒` for much far wall.  
* The character for floor is `░░`  
[Click here to view wall and floor](./images/Wall1.jpg)

### Enemy
* Enemy is the monster that will attack you. Don't let them get close to you!!! It's designed to be the dangerous robot.  
[Click here to view Enemy](./images/Enemy1.jpg)  

### Crosshair
* The red point in the center of the screen is the crosshair. Aim at the enemy with it. You could make critical damage if you shoot enemy's head. Try your best to make more headshot!

### The Maze
* The Maze is carefully designed to ensure players have different experiences exploring different paths.  
* The player is spawned at the left-bottom corner of the maze  
[Click here to view the Maze](./images/map.png)  
[Click here to view the Maze with enemy spawn areas](./images/map_NEW_enemy.png)  

### The End Door?
* You should find the gate that looks like this to beat the game.  
[Click here to view the End Gate](./images/End%20door.png)  

### The value bars
* Player HP, bullet number, and the HP of the enemy you pointed to are shown under the screen.  
[Click here to view the value bars](./images/Value%20bar.jpg)  

### The True End
* The true end gate hides the truth about this space.  
[Click here to view the True End Gate](./images/True_end.png)  
---


## Features Implemented
  1. Generation of random game sets or events
  * Random Enemy Generation
    Enemies will be generated at random positions, but the numbers of enemys of each route is finely designed and fixed.
  * Critical hit
    Enemies might be able to perform a critical hit, and deal extra damage to player, making the game more exciting.

  2. Data structures for storing game status
    We use a lot of structures to store game status.
    We have structs like **Player**, **Enemy**, **Weapon** and **Object** to store the status of these objects. And we created a struct called **ArrayList** acting as lists to store objects,enemies and other structs
    We also created basic mathematical structs like **Vector** to store information like position, rotation, direction, etc
  
  3. Dynamic memory management
    **ArrayList** is a struct like a dynamic list to store different types of data. We can add elements with the function ***ArrayList_PushBack()***
    and ***ArrayList_PopBack()*** to delete the last element. It is used to store **Object** and **Enemy** in a scene. Therefore, we can deal with interactions between player and other elements in each frame.
  4. File input/output  
    File input/output is used in storing game settings, to prevent players from setting the game in each time starting the game repeatedly. The settings are stored in setting.cfg
  5. Program codes in multiple files
    We created many files to define different structs and functions related to those structs, which makes the project clear and easy to update.

---

## Amazing Features About OP Engine
In order to make this game, we have made an entire **_3-Dimensional Game Engine_** without using any non-standard C 
libraries.  
The name of this engine is **OP engine**, as it is made by a ~~Genshin Impact player~~.  
With this game engine, it allows you to render any forms shapes of model. All you need to do is to take your own `.obj` 
files made by any other 3D computer graphics software, and use the `obj_converter` to transform your `.obj` files to the 
C files that the game engined required. All the meshes in this game are made by **Blender**.  
Besides the rendering system, this game engine also supports game object nested. All the game objects has a 
**transform** attribute, which could clearly show the hierarchy of the objects.  
**OP Engine** also supports OBB (Oriented Bounding Box). It allows you to set a cuboid colliding box in any size, any 
direction, and with some basic colliding detection functions provided.
There are more amazing feature about **OP Engine**, please refer to **OP Developer Docs** (not start to write yet).

---


## Game Controls
* **Rotate view**: **_W_** rotate up, **_S_** rotate down, **_A_** rotate left, **_D_** rotate right.
* **Move**: $\uparrow$ move forward, $\downarrow$ move back, $\leftarrow$ move left, $\rightarrow$ move right
* **Load the firearm**: players can load firearms by pressing **_R_**
* **Shooting**: players can shoot by pressing **_F_** (fire!).
* **Pause**: Press **_ESC_** to pause the game, resume it at any time by pressing **_ESC_** again, or press **_ETNER_** to quit

## Game Menu Controls
* **_W_** cursor move up, **_S_** cursor move down
* **_ENTER_** select
* **_A_** decrease / **_D_** increase the value of the selected setting (frame rate / difficulty / sensitivity)
* Check the tips to find some useful information
---


## Compile & Run
### For Linux user:
1. Open the terminal in the game folder.
2. To run the game directly, please run `./start.sh`, this will compile and run the game.  
To only compile the game, please run `make all`, then the executable file `./bin/FPS_Simulator` will be generated.
3. Run `make clean` to delete all the object files and binary files generated.
4. Run `make tar` to pack the whole project (excluding the object and binary files) into an archive file.  
* **_Important_**: Make sure the terminal size is at least *200 * 75*  
* **_For those playing on HKU CS server_**: Due to the unstable performance and the latency issue, the game sometimes lags when the CS server is under high load. We recommend you to play the game on your own PC or VM for a better experience.  

### For Windows user:
[//]: # (TODO)

Although the game is adapted for both Linux and Windows, we still recommend you to play it on ***Linux***. Due to some 
unknown cache refreshing mechanism issues, the flushing rate on Windows terminal is far slower than that on Linux terminal.

## Hidden End
The truth about this space is hidden somewhere, and what you see is not necessarily true. But you can get some hints from tips in the main menu.

<br>
<br>
<br>

## **_!!!Spoiler alert !!!_**

### How to achieve the true ending **_!!!Spoiler alert !!!_**

The following content will show how to achieve the true ending. If you want to try yourself, we recommend you not to read the following content.

The wall behind starting point is breakable. Shooting for 3 times to break it. Then you will see the gate through which the player was sent to the starting point. Enter it to see what will happen.

### The true story of this game

In 2107, AI reached a state where they could create new AI by themselves. Tech giant company "Artificial Infinity" have monopolized AI technology and are using the development of AI to control the world. They trained the AI called NOVA to produce AI soldiers. Due to the enormous power of this company, many people with combat experience were forced to participate in the training of AI. They were forced to sign agreements, had their memories wiped and participated in AI training. NOVA AI used these people to train the AI soldiers it developed. If the player successfully breaks the control of the NOVA AI, the new data will be taken by the company for the iteration of the NOVA AI. Then their memory will be cleared again for the next participation.
