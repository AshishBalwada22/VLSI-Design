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

-------------------------------------------------------------------------------------

values and signal strength
- verilog supports 4 value levels to model the functionality of real hardware
value level - 0,1,x(unknown),z(high impedance) 

--------------------------------------------------------------------------------------
port assignment
input - externally reg or net, internally net
output - internally reg or net, externally net

-----------------------------------------------------------------------------------------
net data type
always use net data type as continous driven

module half_adder(a,b,sum,carry);
input a,b;
output sum,carry;
wire sum,carry;

assign sum=a^b;
assign carry=a&b;
endmodule

- assign keyword, always use net data type or wire

module use_of_wire(y,a,b,c,d);
input a,b,c,d;
output y;
wand y; // this should be wand, not wire
assign y=a&b;
assign y=c|d;
endmodule

------------------------------------------------------------------------
number
<size> '<base><number>
1'b1 -> 1
8'h21 -> 0010 0001
0, x, z extension
4'bx0 -> xxx0
5'd1 -> 0001

------------------------------------------------------------------------------------
register data type
1) reg(most widely used)
2) integer(used for loop counting)
3) real(floating point number)
4) time(keep track of simulation time)

reg count; // single bit register variable
reg[7:0] bus; // 8-bit bus

reg reset;
initial
begin
reset=1'b0;
#10 reset =1'b1;
#10 reset =1'b0;
end

integer data type
-keyword - integer, counting purpose
- synthesizable in nature, default value is x
- default width is 32 bits
i.e 
integer count, new_num;
intital begin
count=1;
new_num=-2;
end

real data type
-stores floating point numbers
- keyword - real, not synthesizable, default value is 0.0
- rounded off to the nearest integer when it is assigned to an integer
i.e 
integer a;
real b;
initial begin
b=-6.5
a=b;
end
// a will be assigned value -7

time data type
- used to store the simulation time
- keyword - time
- time variable are unassigned in nature
- width is implementation specific but is atleast 64 bits
- not synthesizable(useful for testbench)
- default value is x

i.e 
time new_sim_time;
initial begin
new_sim_time = $time; // save the current simulation time
end

---------------------------------------------------------------------------------
vectors, arrays, memories, parameter, strings

vector
- nets or reg data type can be declared as vectors(multiple bit widths)
- vector represent buses
i.e 
wire x,y,z; // single bit variable
wire[15:0] data; // 16-bit data , [msb:lsb]
wire [0:31] sum; // 32 bit data

arrays
- reg, integer, time, real, vector register data type
i.e
reg [7:0] register_bank[15:0]; // 16 8-bit register
reg num [31:0]; // array of size 32 one bit numbers

memories
- memories are modeled as a one-dimensional array of registers
i.e reg mem_1bit [0:1023];

parameter
- parameter cannot be used as varibles, it is a constant value
- parameter value for each module instance can be overriden individually at compile time
- this allows the module instance to be customized

strings
- string can be stored in reg
i.e reg[8*10:1] string_value; // declaration
string_value = "VLSI";
// each string character takes up 8 bits(1 byte)

---------------------------------------------------------------------------------------
operator in verilog

1) arithmetic operator
- unary(one operand) -> +,-
- binary (two operand)

a=4'b001x, b=4'b1011;
output = a+b = 4'bx
// below depends upon first bit
-7%2 => -1;
7%-2 => 1;

2) logical operator (!,&&,||)
3) bitwise operator (&,|,~,^,~^ or ^~)
4) equality operator
- logical -> doesn't include x & z, result -> 0,1,x
-- logical equality(==) and logical inequality(!=)
- case -> include x & z, all bit including x and z should be match then result -> 0,1 
5) relation operator (>,<,>=,<=)
6) reduction operator (&,|,~&(nand),~|(nor),^(xor),~^ or ^~(xnor))
- takes 1 operand only
- output -> single bit

i.e x=4'b1010
&x -> 1&0&1&0 => 1'b0

7) shift operator
- right shift(>>), left shift(<<)
when the bits are shifted then vacant bit positions are filled with zeros
- arithmetic left shift(<<<), arithmetic right shift(>>>)
the context of the expression to determine the value with which to fill the vacanted bits, depends upon first bit(msb)

8) concatenation({})
- provides a mechanism to append multiple operands
- operands must be sized
i.e 
x=2'b00, y=2'b10
z={x,y} // 4'b0010
z = {x,2{y}} // replication operator, 2{y} = yy , replicate y 2 times

9) conditional operator
condition_expr ? true_expr : false_expr;

-----------------------------------------------------------------------------------------
practice question
1) y=1101
a = y>>1'b1;
b = y>>>1'b1;
find a&b?
a = 1101 -> 0110
b = 1101 -> 1110
a&b = 0110

2) m = 2'b10 , n = 2'b1x;
assign q=(m<n)? 2'b10 : 2'b11;
ans = 2'bxx
3) a = 4'b0011
   b = 4'b0001
   c = 4'b0100 (a+b)
   
------------------------------------------------------------------------------------------
gate level modeling
gate primitives
- verilog has predefined inbuilt gate primitives
- all logic gate can be implemented using these gates

1) basic gate(and/or, buf/not)
i.e 
primitive_name instance_name(o,in1,in2);
or(o,in1,in2);

Buf/Not gates - > same ouput as input

2) Bufif/ Notif gates
- these gates have a additional control signal
- they propogate if the control signal is given otherwise the output will be in high impedence state
i.e bufif1, bufif0, notif1, notif0

----------------------------------------------------------------------------
gate delays
- in verilog, we can introduce gate delay in the logic circuits
- three types of delay from input to output of gates
1) rise delay
- these delays come into picture when the output of the gate transist from another value to logic 1
2) fall delay
- when gate output transist from another value to logic 0
3) turn off delay
- when gate output transist from any other logic value to high impedance(z)

note - if the gate output transist to don't care(x) then minimum of three delays is considered

syntax
1) for all transition
gate_name #(delay_time) a1(output,inputs)

2) for rise and fall delay specification
gate_name #(rise_val,fall_val) a1(output,inputs)

3) for rise fall and turnoff delay specification
gate_name #(rise_val,fall_val,turnoff_value) a1(output,inputs)

-------------------------------------------------------------------------------------------
dataflow modeling
continous assignment
- continous assignment is used to drive a value onto a net.
- a continous assignment replaces gates in the description of the circuit and describes the circuit at a higher level of abstraction
- continous assignment statements starts with the keyword assign
characterstics
- the left hand side of an assignment must always be a net type. right hand side can be reg or net type
- continous assignment are always active
- delay value can be specified for assignments in terms of time units

Implicit continous assignment
- continous assignment can be placed on a net when it is declared
- there can be only one implicit declaration assignment per net because a net is declared only once

regular continous assignment
wire out;
assign out = in1&in2;
implicit continous assignment
wire out = in1&in2;

-----------------------------------------------------------------------------------------
Delays
- delays value control the time between the change in rhs operand and when the new value is assigned to the lhs
1) regular assignment delay
2) implicit continous assignment delay
3) net declaration delay

1) regular assignment delay
- delay value is specified after the keyword assign
- any change in value of in1 and in2 will result in a delay of 10 time unit before recomputation of the expression in1 and in2 and the result will be assigned to out
i.e assign #10 out = in1&in2;

2) implicit continous assignment delay
- specify both a delay and an assignment on the net
wire #10 o =in1&in2;

3) net declaration delay
- delay can be specified on a net when it is declared without putting continous assignment on the net
wire #10 out;
assign out=in1&in2;

------------------------------------------------------------------------------------------
behavioral modeling
1) structured procedures(initial and always block)
2) procedural assignment (blocking and non-blocking)
3) delay in procedural assignment
4) block statement(begin-end / fork-join)
5) conditional and multiway branching statements
6) looping constructs(while,for,repeat,forever)
7) some examples

1) structured procedure
- all behavioral statement are written inside initial and always block
- these blocks run in parallel i.e concurrent in nature
- their activity starts at 0 simulation time
- block cannot be nested

initial statement
- once executable only
- execution starts at 0 simulation time
- parallel execution in case of multiple initial blocks
- needs begin and end if we have multiple statement in initial block

always statement
- repeat continously throughout the duration of simulation time
- concurrent in nature and starts at 0 simulation time
- parallel execution in case of multiple always blocks
- a deadlock execution condition will be created if an always construct has no control for simulation time

2) procedural assignment

blocking assignments
- represent with "="
- statements are executed sequentially
- statements are executed in the order they are specified in a sequential block
- delay values will be added
- blocking assignment can be used in both procedural and continous assignments

non-blocking assignment
- represented with sign "<="
- statements are executed concurrently
- rhs are evaluated first, subsequently the specified assignment are scheduled
- non-blocking assignment can't be used in a continous assignment statement or in a net declaration

3) delay in procedural assignment
- delay-based timing control in an expression specifies the time duration when the statement is encountered and when it is executed

regular delay
- if delay is specified then at that time the entire statement is executed and assigned to the lhs
- this is the delay before the rhs is evaluated and assigned to the lhs
i.e #10 x=5; // value 5 is assigned to x by 10 unit delay

intra-assignment delay
- the rhs of the equation at current time but the value is assigned to lhs after the delay time
- it can be applied to both blocking and non-blocking assignment
i.e x=0,z=0;
y = #5 x*z;

4) block statement

sequence block
- begin-end is used to group multiple statements
- statements are executed in the order they are mentioned
- delay is treated relative to the simulation time and previous statement

parallel block
- fork-join is used to group multiple statements
- statement are executed concurrently
- delay is treated relative to the simulation time of entering the block
i.e 
intital fork
statements
join


5) conditional and multiway branching statements
multiway branching statements - case statements
i.e
case(expression)
endcase


6) looping constructs

for loop
i.e for(; expression ; )
begin
end

while loop
- non-synthesizable in nature
i.e 
while(expression)
begin
$display("count");
end

repeat loop
- iterate fixed number of times
i.e 
repeat(number)
begin
end

forever loop
- it execute forever until $finish or disable statement is encountered

i.e 
initial
begin
clock = 1'b0;
forever #10 clock=~clock;
end
