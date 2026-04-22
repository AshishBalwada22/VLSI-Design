// HDL
- Hardware description language
- used to describe the structure and behaviour of electronic circuits
- HDL include the notion of time
- HDLs support concurrency

-------------------------------------------------------------------------------------------------------------------------
// Level of abstraction
1) switch level
2) gate level
3) data flow level
4) behavioural level

1) switch level
- module can be implemented in terms of switches
- here nmos and pmos are used as switches for the design

syntax -  mos_name instance_name();

2) gate level
- lowest level of abstraction
syntax - primitive_name instance_name(output,inputs)
         and inst(out,A,B);

3) data flow level
- register transfer level
- at the level, module is designed by specifying the data flow
- design is implemented using continous assignments
- all such assignments are concurrent in nature
- assign keyword is used
syntax - assign z = x&y

4) Behavioral level
- highest level of abstraction provided by HDL
- different element like function, task and block can be used
- two important constructs - intial and always

2*1 mux
always @(i0,i1,sel)
begin
   if(sel) out = i1;
   else  out = i0;
end


-------------------------------------------------------------------------------------------------------------------------------------
module
- basic building block in verilog
- module can be an element or collection of lower level design blocks
- it provides the required functionality to the higher level block through its port interface but hides the internal implementation
- it provides the flexibility to the designer to modify the module internal without affection the rest of the design

module module_name(x,y,z); // port declaration
input x,y; // defined direction of port
output z;
statments ---
endmodule

module instantiation
- instantiation allows the creation of hierarchy in verilog
- it is a process of creating object from a module template and the objects are called instances
- in verilog, nesting of module is illegal
- one module defination cannot contain another module defination

// implement 4*1 mux using 2*1 mux
module mux_2_to_1(i0,i1,sel,out);
input i0,i1,sel;
output out;
always @(i0,i1,sel)
begin
  if(sel) out=i1;
  else out=i0;
end
endmodule

module mux_4_to_1(i0,i1,i2,i3,s1,s0,out);
input i0,i1,i2,i3,s1,s2;
output out;
wire x1,x2;

mux_2_to_1 m1(i0,i1,s1,x1);
mux_2_to_1 m2(i2,i3,s1,x2);
mux_2_to_1 m3(x1,x2,s0,out);

endmodule

// verilog keyword
- case sensitive
- $, _ , alphanumeric character are allowed

------------------------------------------------------------------------------------------------------------------------------------
Simulation, synthesis and design methodology
- simulation is used to verify the functionality of the digital design that is modeled using hdl like verilog

input - verilog module and testbench 
to Simulation
output - evaluate result

- for simulation purpost, we apply different input stimulus to the design at different time, to check whether the rtl code behaves in intended way or not

synthesis - to generate netlist
- synthesis is a process in which the digital design that is modeled using hdl is translated into an implementation consisting logic gates

inout - verilog 
to synthesis
output - ASIC, FPGA

- no testbench , not consider time delay

--------------------------------------------------------------------------------------------------------------------------------------
Design methodology
1) top-down methodology
- we first define the top level block and identify the sub blocks necessary to build the top level blocks
- these sub-blocks are further subdivided until we come to leaf-cells, which cannot be further divided

2) bottom-up design methodology
- we first identify the building blocks that are available to us
- by using these building blocks, we build the higher level blocks

---------------------------------------------------------------------------------------------------------------------------------------
verilog data types introduction
1) register data type
- represent data storage elements
- it is a variable that can hold a value
keyword - reg , default value - x
- register represent a class of data type such as reg, integer, real, time electronic

2) net data type
- represent connection between hardware elements
- continously driven i.e cannot be used to store the value
keyword - wire, default value - z
- net represent a class of data type such as wire, wand etc
