
#ifndef CONSTANTS_H_
#define CONSTANTS_H_

/*
 * Demographics Northern Territory:
 * Land Area: 1,420,970Km2
 * Population: 211,945 (2011 Census)
 * % Women: 51.7%
 * % Men: 48.3%
 * Population Density: Population/Km2-> 0.17
 * % of People in Capital (Darwin): 54%
 * % of People between 0-14 years: 23.2%
 * % of People between 15-39 years: 40.5%
 * % of People between 40-59 years: 26.7%
 * % of People between 60 and over: 9.6%
 * Birth rate: 0.025 / 365
 * Death rate: 0.015 / 365
 * Probability weapon: 0.3
 */

static const long NUMTICKS = 3000; //Number of ticks
static const long YEARTICKS = 3; //Ticks in 1 year

static const int HUMANSPEED = 2; //Human speed
static const int INCUBATIONTIME = 5;//Ticks that take the zombie disease to incubate in an infected human

static int const GRIDROWS = 40; //Number of row grids
static int const GRIDCOLUMNS = 40;//Number of column grids

static const int ZOMBIESPEED = 1; //Zombie speed
static const int MINDECOMPOSITIONTIME = 10;//Ticks that take the zombie to decompose
static const int MAXDECOMPOSITIONTIME = 15;//Ticks that take the zombie to decompose

static const int MINLIFEEXPECTANCY = 25;//minimum human life expectancy
//static const int MINLIFEEXPECTANCY = 65*365;//minimum human life expectancy
static const int MAXLIFEEXPECTANCY= 35;//maximum human life expectancy
//static const int MAXLIFEEXPECTANCY= 90*365;//maximum human life expectancy

static const float DARWINPOPDENSITY = 100;
static const float NUMBEROFZOMBIES = 10;
//static const float DARWINPOPDENSITY = 926/2;
static const float NTPOPDENSITY = 0.17;
static const float GENDERRATIO = 0.483; //Women vs Men

static const float GUNDENSITY = 0.3; //19.13
static const float BIRTHPERCENTAGE = 0.5;
//static const float BIRTHPERCENTAGE = 864.0/23000000.0; //

//static const float BIRTHPERCENTAGE = 864.0/23000000.0; //


static const float HEADSHOTPERCENTAGE = 10; //40%
static const float SUCESSFULBITEPERCENTAGE = 30; //40%

#define MOVE    0.1 //Probability of a move in each direction

#define DEBUG = true;
#define DEBUGGRID = false;

#endif
