# 06: metrology

> metrology: the science of  measurement, embracing both experimental and theoretical determinations  at any level of uncertainty in any field of science and technology
> -International Bureau of Weights and Measures (BIPM) 



## admin

### assignments

- what did you do wrong last time?
  - hint: multimeter

- homework due Wed
- prelab report (individual) due Fri
  - (students—read lab instructions)
  - go over prelab report
  - https://www.overleaf.com/read/mkfdycznthxz




## metrology

What do we measure from space?

How/what kind of measurements?



Analog/digital



other terms for each?



Chain of info:

| step       | conversion | A/D  |
| ---------- | ---------- | ---- |
| real world |            | A    |
| ADC        | A/D        |      |
| computer   |            | D    |
| radio      | D/A        |      |
| photons    |            | A    |
| radio      | A/D        |      |
| computer   |            | D    |
| DAC        | D/A        |      |
| analysis   |            | A    |



Discuss these photographs

Bad photograph:

![https://belindashi.com/photography-tips/5-common-mistakes-using-a-circular-polarizer](sources/CPL-bad-examples-004.jpg)



Worse photograph:

![image-20230827213014258](sources/image-20230827213014258.png)



Problem with 1st photo:

- differential polarization of sunny sky
  - circ polarizing filter on wide angle lens
- uninspiring subject
- fix: photoshop



Problem with 2nd photo:

- banding
- often see on big screen TVs with DVDs/streaming content
- insufficient color depth (this photo has 4-bit color—how many colors is that?)
- fix: Dolby color/HDR/10-bit color



We can measure any quantity with as many bits as we want/decide to. 



### quantization/discretization



#### Example

spacecraft fuel level

What will we actually measure?

- pressure?
- temperature?
- contact sensor?

![image-20230827223412422](sources/image-20230827223412422.png)



How many bits is this example?

2 bits/4 levels


| **Analog Range** | Discrete  Value | Maximum  Error |
| ---------------- | --------------- | -------------- |
| **0-4 V**        | 2  V            | 2  V           |
| **4-8** **V**    | 6  V            | 2  V           |
| **8-12 V**       | 10  V           | 2  V           |
| **12-16 V**      | 14  V           | 2  V           |


#### equations

$$
Discrete \# = A_{min} + (A_{max}-A_{min}) \left( \frac{Digital\#}{2^n} + \frac{1}{2^{n+1}}  \right)
$$

$$
Quantization\ Step = \frac{(A_{max}-A_{min})}{2^n}
$$

$$
Error_{max}=\frac{(A_{max}-A_{min})}{2^{n+1}}
$$



What can we quantize?

- brightness
- voltage (you will do this today)
- current?
- acceleration
- force
- loudness/sound pressure



Representation of a PCM signal

![https://commons.wikimedia.org/wiki/File:Pcm.svg](sources/pcm_quantization.svg)



How many levels? How many bits?

This represents a sound waveform.



There’s another dimension here—what is it?



### sampling frequency

How often must you sample a wave to recreate it? 
$$
f_s \geq 2.2 f_m
$$
Nyquist sampling criterion



human audio sensitivity: 20 Hz–20 kHz

CD audio: 16 bit/44.1 kHz

Tidal: 24 bit/192 kHz


![sampling_frequency](sources/sampling_frequency.svg)

![Davidjessop, CC BY-SA 4.0 <https://creativecommons.org/licenses/by-sa/4.0>, via Wikimedia Commons](sources/FFT_aliasing.gif)



(you won’t do this today)



### calibration

- ends of scale aren’t necessarily 0/15

- curve isn’t necessarily linear

- you have to build calibration curve

  - can be preflight design/engineering
  - can be in flight
  - both?

  ![image-20230827223412422](sources/image-20230827223412422.png)

(you will do this today)



Watch this video.

https://youtu.be/_k9egfWvb7Y?si=0gWMrULNJZKLkbh3



Traceable/certified calibration

(you won’t do this today)



## homework

- by Wednesday
  - HW
- by Friday
  - electrical prelab report