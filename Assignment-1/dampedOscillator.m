%Question 1
%Reid McIlroy-Young
%20416412
%January 21 2014

function finalConditions = dampedOscillator(intialConditions, gamma, time)
    %Takes the intialConditions as an array containing position and velocity
    %The spring constant gamma and time
    %Returns the updated velocity and postion as an array
    %Uses the formula from assignment 1 
    k = 1;
    m = 1;
    y = gamma;

    finalConditions(1) = intialConditions(2);
    finalConditions(2) = -y * intialConditions(2) - k / m * intialConditions(1);
endfunction

function final = oscillator0 (intialConditions, time)
    %dampedOscillator with spring constant 0
    final = dampedOscillator(intialConditions, 0, time);
endfunction

function final = oscillator1 (intialConditions, time)
    %dampedOscillator with spring constant 1
    final = dampedOscillator(intialConditions, 1, time);
endfunction

function final = oscillator2 (intialConditions, time)
    %dampedOscillator with spring constant 2
    final = dampedOscillator(intialConditions, 2, time);
endfunction

function final = oscillator4 (intialConditions, time)
    %dampedOscillator with spring constant 4
    final = dampedOscillator(intialConditions, 4, time);
endfunction

timeC = linspace(0, 10, 1000)'; %Time array to iterate over
intialValues = [1,0]; %Intial value for ODE
position0C = lsode("oscillator0", intialValues, timeC)(:,1); %Solution to ODE at each time for spring constant 0
position1C = lsode("oscillator1", intialValues, timeC)(:,1); %Solution to ODE at each time for spring constant 1
position2C = lsode("oscillator2", intialValues, timeC)(:,1); %Solution to ODE at each time for spring constant 2
position4C = lsode("oscillator4", intialValues, timeC)(:,1); %Solution to ODE at each time for spring constant 4

setenv GNUTERM dumb %necessary for portability 

hold on
plot(timeC, position0C, '+')
plot(timeC, position1C, 'p')
plot(timeC, position2C, 'd')
plot(timeC, position4C, 'h')

pause() %pauses

%{
Produces:
+------------------------------------------------------------------------------+
|                                                                              |
|   1 AAAN----------+-------------+-------------AAAAA---------+------------++  |
|     +-AAANCC--------------------------------AAA---AAA--------------------++  |
|     |   AANLLCCC                           AA       AA                   ||  |
|     |     AANLLCCCCCC                    AA           AA                 ||  |
| 0.5 |+     ANNLLL   CCCCCCC             AA             AA                |+  |
|     |       ANNNLLLL      CCCCCCCC      A               A                ||  |
|     |       AA NNN LLLLL         CCCCCCACCCCC           AA               ||  |
|     |        AA  NNN   LLLLLLLL       AA    CCCCCCCCCCCCCAACCCC          ||  |
|   0 |+        AA   NNN        LLLLLLLAALLLLLLLNNNNNNNNNNNNAANNNNNNNNNNNNNLL  |
|     |          AA    NNNNN          AANNNNNNNNN            AA           NNN  |
|     |           AA       NNNNNNNNNNAA                       AA           ||  |
|     |            A                AA                         A           ||  |
|     |             A               A                           A          ||  |
|-0.5 |+            AA             A                            AA         |+  |
|     |              AA           AA                             AA        ||  |
|     |                AA       AA                                AAA      ||  |
|     |             +   AAA   AAA +             +             +     AAA   AAA  |
|  -1 +-------------------AAAAA---------------------------------------AAAAA++  |
|     0             2             4             6             8            10  |
+------------------------------------------------------------------------------+
%}
