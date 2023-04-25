# FPS-Simulator
ENGG1340 Group project made by group 102
Contributors:

  Liu Sizhe (University no.: 3036098041)

  Chan Aaron

  Zhuang Keju

  Xiao Yuxuan

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

