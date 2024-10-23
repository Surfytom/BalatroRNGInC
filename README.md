# Balatro RNG System from scratch in C

This repository tries to recreate the Balatro RNG system written in (LUAJIT). It takes influence from the games source code, the LUAJIT source code as well as [immolate](https://github.com/MathIsFun0/Immolate) (written in OpenCL).

This project no longer supports the latest version of Balatro so predictions will likely be wrong for the latest versions. The project works on version 1.0.1g-FULL if you still have that version to play around with.

## Using The Project

The project is a hobby project to try and learn/get better at the C language. Please bare in mind this project uses the gcc compiler and utilises windows specific functions meaning the project will not function on platforms with no access to <windows.h>. If you want a too see a demo of the project follow the steps below:

### Step 1 | Clone The Repository

```
git clone 
```

### Step 2 | Build .exe With Make

In the root directory of the repository:

```
make
```

### Step 3 | Run .exe

In the root directory of the repository:

```
./main
```

This will run the ```main()``` function in ```main.c``` which contains this snippet of code:

```c
Instance* ip = InstanceCreate("A", HASHMAPSIZE);

FuncWrapper func = CallFunction("filter");

(*func)(ip, true, true, true, true);

InstanceDelete(ip);
```

This code creates an Instance of the game which sets up all context needed to run a simulation of the Balatro's RNG system. Then a filter function is called that is defined in ```src/filters.c```. This defines what to search in the seed. In this case a general search is conducted looping for 1 ANTE (a normal game is 8 ANTES in length) and showing the cards that appear in the shop given no rerolls as well as the pack types that appear and the cards that appear in those packs.

A video of the first two shops of ANTE 1 for seed A can be seen by clicking on the image below to allow you to see how this project predicts the items in the game correctly.

[![Balatro Test Case Video](https://img.youtube.com/vi/a1y7xRfzVcA/0.jpg)](https://youtu.be/a1y7xRfzVcA "Balatro Test Case Video")

All the integers that are printed can be referenced to the large enum in ```src/packs.h``` to reference the general name of the item in question. For example the integer ```63``` appears as the first card in the first shop. When referencing the enum ```63``` is labelled as ```j_shoot_the_moon```. Incase you don't want to download the project and run the code to see the output it is below along with the packs.h enum references in speech marks:

```
ANTE 1
    BOSS: 369 "The_Head"
    TAGS: 355 "Economy Tag" | 355 "Economy Tag"
    SHOP 1
            REROLL 1
                    Card 1:  63 "j_shoot_the_moon"
                    Card 2:  56 "j_golden" Eternal Rental

            PACKS
                    Pack 1 type 10 "Buffoon_Pack"
                            Card 1:   9 "j_zany" Perishable Rental
                            Card 2: 110 "j_troubadour" Perishable Rental
                    Pack 2 type 1 "Arcana_Pack"
                            Card 1: 172 "c_hermit"
                            Card 2: 180 "c_star"
                            Card 3: 163 "c_fool"
    SHOP 2
            REROLL 1
                    Card 1:  90 "j_rocket" Perishable Rental
                    Card 2: 115 "j_bloodstone" Eternal

            PACKS
                    Pack 1 type 8 "Jumbo_Standard_Pack"
                            Card 1: 302 "S_9"
                            Card 2: 292 "H_K" Is Stone in Pack
                            Card 3: 299 "S_6"
                            Card 4: 293 "H_Q"
                            Card 5: 276 "D_9"
                    Pack 2 type 5 "Jumbo_Celestial_Pack"
                        As Celestial Pack RNG depends on the types of
                        hands played and the project does not allow cards
                        to be played this packs draws will be inaccurate.
                            Card 1: 191
                            Card 2: 198
                            Card 3: 193
                            Card 4: 192
                            Card 5: 189
```