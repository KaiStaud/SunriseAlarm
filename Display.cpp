#include "Display.hpp"

/* Number One */
const byte vdash[8] = {
  B00001,
  B00011,
  B00110,
  B01100,
  B11000,
  B10000,
  B00000,
};

const byte dash[8] = {
  B11111,
  B11111,
  B00111,
  B00111,
  B00111,
  B00111,
  B00111,
};

 const byte hstrich[8] = {
  B00111,
  B00111,
  B00111,
  B00111,
  B00111,
  B00111,
  B00111,
};

/* Number 'Two' */
/* consists of vdash*/
const byte underline[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
};

const byte urcorner[8] = {
  B11111,
  B11111,
  B00001,
  B00011,
  B00110,
  B01100,
  B11000,
};

const byte llcorner[8] = {
  B00001,
  B00011,
  B00110,
  B01100,
  B11000,
  B11111,
  B11111,
};

/* Number '4' */
const byte ulcornerIV[8] = 
{
  B00000, 
  B00000, 
  B00001, 
  B00011, 
  B00110, 
  B01100, 
  B11000, 
  B10000, 
};

const byte urcornerIV[8] = 
{
  B01100,
  B11100,
  B11100,
  B01100,
  B01100,
  B01100,
  B01100,
  B01100,
};


const byte lcornerIV[8] = 
{
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};
const byte rcornerIV[8] = 
{
  B11111,
  B11111,
  B01100,
  B01100,
  B01100,
  B01100,
  B01100,
  B01100,
};

/* Number '5' */
const byte ulcornerV[8] = 
{
  B01111,
  B11111,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
};

const byte urcornerV[8] = 
{
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};


const byte lcornerV[8] = 
{
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
};
const byte rcornerV[8] = 
{
  B11111,
  B11111,
  B00011,
  B00011,
  B00011,
  B00011,
  B11111,
  B11111,
};


/* Number '6' */
const byte ulcornerVI[8] = 
{
  B11111,
  B11111,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
};

const byte urcornerVI[8] = 
{
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};


const byte lcornerVI[8] = 
{
  B11111,
  B11111,
  B11000,
  B11000,
  B11000,
  B11000,
  B11111,
  B11111,
};
const byte rcornerVI[8] = 
{
  B11111,
  B11111,
  B00011,
  B00011,
  B00011,
  B00011,
  B11111,
  B11111,
};


/* Number '8' */
const byte ulcornerVII[8] = 
{
  B01111,
  B11111,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B01111,
};

const byte urcornerVII[8] = 
{
  B11110,
  B11111,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B11110,
};


const byte lcornerVII[8] = 
{
  B01111,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11111,
  B01111,
};
const byte rcornerVII[8] = 
{
  B01110,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B11111,
  B11110,
};
