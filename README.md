<span align="center">
	<h1>42 - Cub3D
	<br>
	<img alt="mac" src="https://svgshare.com/i/tV2.svg" width="100px" height="20px"/></h1>
</span>
<div align="center">
	<img alt="mac" src="https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=apple&logoColor=white"/>
	<img alt="Linux" src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black"/>
	<img alt="Ubuntu" src="https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white"/>
	<br>
	<img alt="c" src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white"/>
</div>

---

## **_Description_**
This project is inspired by the world-famous Wolfenstein 3D game, which
was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to
make a dynamic view inside a maze, in which you’ll have to find your way.
<br><br>
## **_Goals_**
This project’s objectives are: Rigor, use of C, use of basic algorithms, information research etc.<br>
As a graphic design project, cub3D will enable you to improve your skills in these
areas: windows, colors, events, fill shapes, etc.<br>
To conclude cub3D is a remarkable playground to explore the playful practical applications of mathematics without having to understand the specifics.<br>
With the help of the numerous documents available on the internet, you will use
mathematics as a tool to create elegant and efficient algorithms

## **_Preview_**

![cubgif2.gif](./screenshoots/cubgif2.gif)

## **_Requirements_**
As this program is coded in C, you will need a compiler as gcc. Also you will need minilibX graphic library. You can get it [here](https://github.com/42Paris/minilibx-linux).

## **_How to run it_**
To run the mandatory part just

```
make && ./cub3D ./maps/[chooseMap]

```

replace chooseMap with one of the maps available in the maps folder.<br>
Although, the most fun part of this project is the bonus, so I strongly recommend you to use

```
make bonus && ./cub3D_bonus ./maps/[chooseMap]
```

to take advantage of all the functionalities of the program.

_ps: if you are using Mac, make sure that your Makefile is compiling with the flag MOSFLAGS. If you use linux the flags should be LINFLAGS._

## **_Commands_**

| __Key__        | __Action__   |
| -------------  |:-------------:|
| W              | Move forward |
| A       | Move left      |
| D  | Move right      |
| S  | Move backwards      |
| Left Arrow  | Turn Left      |
| Right Arrow  | Turn Right      |
| Space  | Shoot      |
| F  | Open doors      |
| Mouse  | Turn      |
| ESC  | Close window      |

## **_Collaborators_**

[@Rubidium7](https://github.com/Rubidium7)
