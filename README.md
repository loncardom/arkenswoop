# Arkenswoop

A WIP fork of [jimmerricks's Swoop](https://github.com/jimmerricks/swoop), which is a fork of [David Barr's Sweep](https://github.com/davidphilipbarr/Sweep), which is itself based on the fabulous [Ferris by Pierre Chevalier](https://github.com/pierrechevalier83/ferris).

| Front | Back |
| :---: | :---: |
| ![front](/images/exports/arkenswoop/front.png) | ![back](/images/exports/arkenswoop/back.png) |

### Features

⭕ Low profile Kailh Choc switches  
⭕ Per-key RGB LEDs (mini-e)  
⭕ Dual side-scrolling encoder  
⭕ Oled screens  
⭕ Power switch for battery management  
⭕ Bluetooth support w/ nice!nano  
⭕ Plate style case with mcu cover

### Components list

To build and use an Arkenswoop you will need:

* 1× PCB Kit (1.6mm thickness is good)
* 1× back plate kit (optional, you can go for 1.2mm thickness)
* 2× promicro compatible boards or 2 nice!nanos.
* 34× Kailh Choc v1 switches
* 34× SK6812 Mini-E RGB SMD Leds (optional; not recommended for wireless)
* 34× keycaps
* 2× side-scrolling encoders EVQWGD001
* 2× OLED LCD Display 128x32 SSD1306 (optional)
* 2× reset switches (optional; B3U-1000P(M))
* Some little rubber feet/bumpers (a minimum of 4 on each side)
* 2× power switches (wireless only; MSK 12C02)
* 2× lipo batteries (wireless only; 301230 or 301228)
* 1× TRRS (not TRS!) cable (wired only)
* 2× TRRS Jack [PJ-320A] (wired only)
* 1× USB Cable (depends on your micro-controller choice)

### Todo

- [ ] add hotswap socket support
- [ ] convert the SMD diodes to through hole diodes to ease soldering?
- [ ] change the holes for mounts: they are too big (for a soldered build)
- [ ] add mcu/oled cover
- [ ] move the encoder down about 1mm because it interfers with a keycap
- [ ] redo the vial KLE to align the keys
