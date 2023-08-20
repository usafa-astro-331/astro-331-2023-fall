# 04: digital logic + breadboarding lab



## admin

### quiz

write the answers on your homework

[1]: # (The two possible values in Boolean logic can be described in multiple ways. List two ways.)

[2]: # (What are the three primary operators used in Boolean logic?)


### assignments

collect HW and skills review



The three primary logic operators used with Boolean logic are AND, OR, and NOT. 

| Type                                                         | Distinctive shape <br />(IEEE Std 91/91a-1991)               | [Boolean algebra](https://en.wikipedia.org/wiki/Boolean_algebra) | [Truth table](https://en.wikipedia.org/wiki/Truth_table)    |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ----------------------------------------------------------- |
| **[AND](https://en.wikipedia.org/wiki/AND_gate)**            | ![AND](sources/AND.svg)                                      | $A \cdot B$                                                  | `A B Q`<br />`0 0 0`<br />`0 1 0`<br />`1 0 0`<br />`1 1 1` |
| **[OR](https://en.wikipedia.org/wiki/OR_gate)**              | ![OR](sources/OR.svg) | $A+B$                                                        | `A B Q`<br />`0 0 0`<br />`0 1 1`<br />`1 0 1`<br />`1 1 1` |
| **[NOT](https://en.wikipedia.org/wiki/NOT_gate)** (inverter) | ![NOT](sources/NOT.svg)| $\bar{A}$                                                    | `A Q`<br />`0 1`<br />`1 0`                                 |



(describe them)





Many additional gates are possible. Here are some basic ones: 

| Type                                                    | Distinctive shape <br />(IEEE Std 91/91a-1991)               | [Boolean algebra](https://en.wikipedia.org/wiki/Boolean_algebra) | [Truth table](https://en.wikipedia.org/wiki/Truth_table)    |
| ------------------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ----------------------------------------------------------- |
| **[Buffer](https://en.wikipedia.org/wiki/Buffer_gate)** | ![Buffer](sources/Buffer.svg)| A                                                            | `A Q`<br />`0 0`<br />`1 1`                                 |
| **[NAND](https://en.wikipedia.org/wiki/NAND_gate)**     | ![NAND](sources/NAND.svg) | $\overline{A \cdot B}$                                       | `A B Q`<br />`0 0 1`<br />`0 1 1`<br />`1 0 1`<br />`1 1 0` |
| **[NOR](https://en.wikipedia.org/wiki/NOR_gate)**       | ![NOR](sources/NOR.svg) | $\overline{A + B}$                                           | `A B Q`<br />`0 0 1`<br />`0 1 0`<br />`1 0 0`<br />`1 1 0` |
| **[XOR](https://en.wikipedia.org/wiki/XOR_gate)**       | ![XOR](sources/XOR.svg)| $A \oplus B$                                                 | `A B Q`<br />`0 0 0`<br />`0 1 1`<br />`1 0 1`<br />`1 1 0` |
| **[XNOR](https://en.wikipedia.org/wiki/XNOR_gate)**     | ![XNOR](sources/XNOR.svg) | $\overline{A \oplus B}$                                      | `A B Q`<br />`0 0 1`<br />`0 1 0`<br />`1 0 0`<br />`1 1 1` |

NAND and NOR are *universal gates*: any other gate can be be constructed solely from NAND gates, or solely from NOR gates. 

- NAND is the most common gate in integrated circuits
- The Apollo Guidance Computer was made exclusively with 3-input NOR gates. https://www.ibiblio.org/apollo/hrst/archive/1716.pdf



|AND                        |OR                            | law |
| ------------------------------- | ------------------------------------ | -------------------- |
| X•0  = 0                        | X+1  = 1                             | Annulment       |
| X•1  = X                        | X+0  = X                             | Identity        |
| X•X  = X                        | X+X  = X                             | Idempotent      |
| X•X’ =  0                     | X+ X’ =  1                         | Complement      |
| (X’)’=  X                  |                  | Double  Negation |
| X•Y  = Y•X                      | X+Y  = Y+X                           | Commutative     |
| X(YZ)  = (XY)Z =   (XZ)Y  = XYZ | X+(Y+Z)  = (X+Y)+Z = (X+Z)+Y = X+Y+Z | Associative     |
| X•(Y+Z)  = XY+XZ                | X+YZ  = (X+Y)•(X+Z)                  | Distributive    |
| (X•Y)’ =X’ +Y’              | (X+Y)’ =X’ •Y’                   | de  Morgan’s Theorem |



## homework

- by Thursday: watch these soldering tutorials
  - https://youtu.be/-qk-ulz05J8
  - https://youtu.be/eHu_fGAyNY4





