## Table of Content
### Overview
### About MiniLibx
### Project Requirement
### Pseudo Code
### Reflection

## Overview
```so_long``` is a project where we are tasked to program a 2D game in C Language with the application of MiniLibx, a graphical library spun off from the X-Window Library. The project requires us to code a programme which takes in 2 arguments which are the executable and a ```.ber``` file which is the map for the game. To simplify things, the concept is like PACMAN where the first part of the project requires the player to collect coins and fin the exit to win the game. The bonus part of the project requires the player to collect coins similar to part 1 while evading enemies that are lurking around the map.
## About MiniLibX
MiniLibX is a library abstracted from the original X Window System for students of 42 as an introduction to graphics programming. This library allows student to easily create a graphical software without any prior X Window programming knowledge. As such, students only need to use the function that is provided within the library to initialize the X Terminal, Window and create a loop for displaying graphics. In the context of ```so_long```, below are the set of functions I have used to compile ```so_long```.

**Mandatory**
- mlx_init()
- mlx_new_window()
- mlx_key_hook()
- mlx_xpm_file_to_image()
- mlx_put_img_to_window()
- mlx_loop()

**Bonus**
- mlx_loop_hook()
- mlx_string_put()
## Project Requirement
The project requires us to code in 2 parts namely: Mandatory & Bonus. In the mandatory portion, it should perform the following:

**Mandatory**

```Event handling```
- Handle events when ```directional keys(W,S,A,D)``` are pressed.
- Exit game when escape key is pressed.
- Exit game in victory when all coins have been collected.
- Terminal must display move counter. Display invalid move when wrong key is pressed.

```Map checks```
- Map MUST be valid. Have the correct elements.
- Map MUST not be empty.

```Game conditions```
- Map MUST have correct number of tokens.

      1 player, 1 exit, at least 1 coins
- Map MUST be surrounded by walls.
- Map MUST be rectangular.
- Map must contain a unique path to exit.
- Symbols for each element are as follow:

      'P' = Player
      'C' = COins
      'E' = Exit
      '1' = Walls
      '0' = Floor

## Bonus
Adding on to what has been coded, this portion of the project should consists of 3 additional items and not restricted to more:
- Roaming enemy.
- Move counter displayed on X Window.
- Animation of element (coins, player, enemies).

## Pseudo Code
I have split the code into 5 main parts:

**Main Function**
This is where the ```int main(int argc, char ** argv)``` is located. It checks for the correct number of inputs. Followed by whether the map file being opened is of the correct format ```.ber```. Once these conditions are met, it proceeds to initialize the game. That will be where the bulk of the code resides where functions from MiniLibx is used.

**Initialize Game**
This part of the code consist of functions from MiniLibx used to create a loop to initialize, display and continuously run the game window. I have further broken down this function into 3 sub functions:
- Map Check

This function checks the validity of the map: ```Is is a valid map? & Is it empty?```. Once these conditions are fulfilled, it then proceed to check all the game condition stated in the project requirement under ```Game Conditions```.
- Game Conditions

This function aims to check the project requirement stated below:

      Is it surrounded by walls?
      is it rectangular?
      Does it have the correct number of tokens?
      Does it have a path to exit with all the coins collected?

If any of the conditions are not met, the game will not initilaize and exit with error(mentioned in ```Handle Errors``` below). Once all the conditions are met, the code proceedsd to initialize all the structures that have been declared.

- Initialize Structure

In this part of the code, a main structure named ```window``` is declared to house the rest of the structure (nested structure): Player & Image. It is also where the ```mlx_ptr``` and ```win_ptr``` is located. This portion of the code also consists of a function to start filling the map onto the screen by iterating through the map array to place all the respective token within the map.

- Render Map

After the images have been loaded, the map is iterated where a function is used to put the specific image of each element onto the window.

**Handle Events**
In the previous initializaiton and rendering, all items displayed on the window are static. This portion of the code aims to update each event ranging from movement to exiting with an evenhandler made possible by ```mlx_key_hook()```. This updates the position of each element and images real time.

**Handle Errors**
In the event that any error is encountered within map check and game conditions, this function will be called to handle it accordingly. As stipulated, each error will result in a certain action ranging from exiting to freeing all relevant dynamically allocated memory to prevent memory leaks.

## Reflection
This was a long and arduous journey. It was indeed so long! Work has not been kind as stuff has been piling up. This reduced the amount fo free time I have to properly code/study. Coupled with family matters to tend to, it made heading to school even harder. Fortunately, when I do go to school, I bumped into friends who were willing to teach and share their learnings and some challenges they faced while doing this project. At the same time, they served as a wall to bounce ideas off which assisted me greatly in debugging the entire code. Through this entire project, I've learnt that I can actually code, as long as I take a towel and perservere. Most of my friends questioned why I took this up because there was an obivious lack of resources to refer and learn. My answer have not changed since the day I clicked enrol, 'I want to code something that my loved ones can try and enjoy'. Not forgetting the MVP throughout this whole ordeal, my lovely partner. Giving me a good neck massage and constantly encouraging me and believing in me as well as cooking me dinner on days where I came home late with blurred vision and whined. To have seen this through and witness the character moving and collecting coins was indeed a sweet victory albeit all the hardship. So there you all go, my own version of a mario-pacman like game! Time to have a 3 days rest before tackling the next project and resume my constant complaints, 42 Oui!
