1) Design Abstraction
2) Design Automation(EDA)
3) Design Re-use IP(intellectual property)

--------------------- Basic design abstraction ---------------------------------------
1) system level (c-programming language)
2) register transfer level (rtl) - cycle accurate model close to hardware implementation
3) gate level - model on finite-state machine level
4) transistor level
5) layout level
6) mask level 

design -------> 
verification  <-------

Another view
1) Application
2) algorithm
3) programming language
4) os/virtual machine
5) instruction set architecture
6) micro architecture
7) rtl
8) circuit (gate level)
9) device
10) physics (ohm's law, maxwell's law)

------------------------------ Design Automation ----------------------------------------

Design - 
1) high level synthesis
2) logic synthesis
3) schematic capture
4) layout
5) pcb design

Simulation - 
1) transistor Simulation
2) logic Simulation
3) hardware Emulation
4) technology CAD
5) field solvers

Analysis and verification
1) functional verification
2) clock domain crossing
3) formal verification
4) equivalence checking
5) static timing Analysis
6) physical verification


---------------------------------------------------------------------------------------

1) RTL - verilog
2) synthesis - cadence genus
3) place and route
cadence innovus
static timing analysis - tempus
power estimation - voltus
parasitic extraction - qrc
clock tree synthesis - CCOpt

---------------------------------------------------------------------------------------
Chip design flow - 
1) defination and planning
2) design and verification
3) logic synthesis
4) physical design
5) signoff and tapeout
6) silicon validation

----------------------------------------------------------------------------------------
Design and verification
RTL design
Integration/development of IPs
RTL Lint/ synthesability checks
Formal verification

Hard Ip - timing models, layout abstract, behavioural models(verilog/VHDL)
Soft Ip - RTL code

FPGA Prototyping -
synthesis to FPGA
speed up testing where possible

Different level of verification -
specification driven testing
bug driven testing
coverage driven testing
regression

---------------------------------------------------------------------------------------
Logic synthesis
1) Input - technology library file, RTL file, Constraint files(SDC), DFT defination(design for test)
2) output - gate level netlist
3) synthesis - converting RTL code into a generic logic netlist
4) mapping - mapping generic netlist into standard cells from the core library
5) optimization - to meet timing/area/power contraints
6) post synthesis checks - gate level simulation, formal verification(logic equivalence),
                           static timing analysis(STA), power/area estimation

-------------------------------------------- end ---------------------------------------



