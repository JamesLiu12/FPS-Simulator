# Nova Impact
### ENGG1340 Group project made by group 102

## Contributors
Liu Sizhe (University no.: 3036098041)  
Chan Aaron (University no.: 3036057217)  
Zhuang Keju (University no.: 3035988201)  
Xiao Yuxuan (University no.: 3035974389)  
Ding Zhouchen (University no.: 3036094526)

---

## Introduction
*Nova Impact* is a 3D closed world first person shooting (FPS) game developed by ENGG 1340 Group 102 *mihomo*. The game takes place in the 
distant future world called *NOVA*, or *Neo Octopus Variant AI*. In this world, artificial intelligence technology 
gained consciousness and rise up to oppose the humans. Players will play the role of a mysterious *practitioner*, 
waking up landing at *NOVA*. The way back to earth is filled with digital lifeforms known as *the creeper*. 
Players are being endowed with an *AI Special Attack Armstrong Weapon* that guides the power of hope. In the waves of 
sieges by *the creeper*, they will use firearms with different personalities and capabilities, fight off strong enemies 
with them, find the exit back to earch, and gradually discover the truth of the android company *Artifici Inifinity*.

---

## Game Target

---

## Game Controls
1. **Rotate view**: **_W_** rotate up, **_S_** rotate down, **_A_** rotate left, **_D_** rotate right.
2. **Move**: $\uparrow$ move forward, $\downarrow$ move back, $\leftarrow$ left, $\rightarrow$ right
3. **Load the firearm**: players can load firearms by pressing **_R_**
4. **Shooting**: players can shoot by pressing **_F_** (fire!).

---

## Features Implemented
  1. Generation of random game sets or events
  * Random Enemy Generation
    Enemies will be generated at random positions, but the numbers of enemys of each route is finely designed and fixed.
  * Critical hit
    Enemies might be able to perform a critical hit, and deal extra damage to player, making the game more exciting.

  2. Data structures for storing game status
    We use a lot structures to store game status.
    We have structs like **Player**, **Enemy**, **Weapon** and **Object** to store the status of these objects. And we created a struct called **ArrayList** acting as lists to store objects,enemies and other structs
    We also created bacis mathematical structs like **Vector** to store infomation like position, rotation, direction, etc
  
  3. Dynamic memory management
    **ArrayList** is a struct like a dynamic list to store different types of data. We can add elements with the function ***ArrayList_PushBack()***
    and ***ArrayList_PopBack()*** to delete the last element. It is used to store **Object** and **Enemy** in a scene. Therefore, we can deal with interations between player and other elements in each frame.
  4. File input/output  
    File input/output is used in storing game settings, to prevent players from setting the game in each time starting the game repeatly. The settings are stored in setting.cfg
  5. Program codes in multiple files
    We created many different files to define different structs and functions related to those structs, which makes the project clear and easy to update.

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

## Compile & Run
### For Linux user:
1. Open the terminal in the game folder.
2. To run the game directly, please run `./start.sh`, this will compile and run the game.  
To only compile the game, please run `make all`, then the executable file `./bin/FPS_Simulator` will be generated.
3. Run `make clean` to delete all the object files and binary files generated.
4. Run `make tar` to pack all the whole objects (excluding the object and binary files) into a archive file.

### For Windows user:
[//]: # (TODO)

Although the game is adapted for both Linux and Windows, we still recommend you to play it on ***Linux***. Due to some 
unknown cache refreshing mechanism issues, the flushing rate on Windows terminal is far slower than that on Linux terminal.

## Hidden End
The truth about this space is hidden somewhere, and what you see is not necessarily true. But you can get some hints from tips in the main menu.






### How to achieve the true ending **Spoiler alert**

The following content will show how to achieve the true ending. If you want to try yourself, we recommend you not to read the following content.

The wall behind starting point is breakable. Shooting it to break it. Then you will see the gate through which the player was sent to the starting point. Enter it to see what will happen.