Overview
========

I purchased a couple of 32X16 RG Bicolor LED Dot Matrix boards and thought I'd write a game for one of these displays. 
I settled on a relatively straight forward game called Snake and decided to write using object oriented principles.  I had seen a number of versions of the game and each one consisted of a single file with all the code shoved in it.  I decided to write a structured code that would logically represent the game and demonstrate some of the object oriented techniques with Arduino.  

The solution I present relies on encapsulation and contains interfaces which allow you to easily add new input and display hardware whilst keeping the code maintainable.

There is a Vine video on my profile here:

https://vine.co/v/MjUJMa9thQD

Display
========

The screen I used came from here:

http://www.sureelectronics.net/goods.php?id=1095

You could use any other display you like.  Have a look at sure32x16.cpp to see how that implements the interface in display.h.  Your new class will have to implement the same methods to work.

Input
=====

Serial input is enabled by default but you can also use hardwired buttons if you comment out 

#define SERIAL_INPUT 1

and uncomment

//#define BUTTON_INPUT 1

in the types.h file.

The methods of input can be easily extended.  Just like the display you can add new classes to handle whatever input method you like.

Credit
=======

This proejct also contains code written by other people: 

Button 
------

JChristensen's Arduino library to debounce button switches, detect presses, releases, and long presses
https://github.com/JChristensen/Button/

ht1632c
------

Arduino library for HT1632C based led dot matrix displays (eg. Sure Electronics).

Https://code.google.com/p/ht1632c/