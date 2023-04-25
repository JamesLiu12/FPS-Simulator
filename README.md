# FPS-Simulator
### ENGG1340 Group project made by group 102

Contributors
&emsp; Liu Sizhe (University no.: 3036098041)
&emsp; Chan Aaron (University no.: 3036057217)
&emsp; Zhuang Keju (University no.: 3035988201)
&emsp; Xiao Yuxuan (University no.: 3035974389)
&emsp; Ding Zhouchen (University no.: 3036094526)

Setting
*Nova Impact* is a 3D closed world first person shooting (FPS) game developed by *mihomo*. The game takes place in the distant future world called *NOVA*, or *Neo Octopus Variant AI*. In this world, artificial intelligence technology gained consciousness and rise up to oppose the humans. Players will play the role of a mysterious *practitioner*, waking up landing at *NOVA*. The way back to earth is filled with digital lifeforms known as *the creeper*. Players are being endowed with an *AI Special Attack Armstrong Weapon* that guides the power of hope. In the waves of sieges by *the creeper*, they will use firearms with different personalities and capabilities, fight off strong enemies with them, find the exit back to earch, and gradually discover the truth of the android company *Artifici Inifinity*.


Operations
1. rotate: players can rotate their view using w, s, a and d, where w is rotate up, s is rotate down, a is rotate left and d is rotate right.
2. movement: players can move forward, back, left and right by pressing the respective arrow keys.
3. load the firearm: players can load firearms by pressing r
4. shooting: players can shoot by pressing f (fire!).


Features Implemented
1. engine
* collision
  Collide box
* ray detection
  using the distance between a ray and a collide box
* visual distance

* enemy path seeking


2. object：
  model
  位置

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