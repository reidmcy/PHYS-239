%Question 3
%Reid McIlroy-Young
%20416412
%January 21 2014

randCollector = []; %Collects rand eigenvalues

for loop = 0:99
    %loops 100 times and produces 100 eigenvlaues a loop
    randCollector = [abs(eig(round(rand(100,100)))), randCollector];
endfor
%randCollector ends with 10000 values

randnCollector = []; %Collects randn eigenvalues

for loop = 0:99
    %loops 100 times and produces 100 eigenvlaues a loop
    randnCollector = [abs(eig((randn(100,100)))), randnCollector];
endfor
%randCollector ends with 10000 values

setenv GNUTERM dumb %necessary for portability 


%plotting
subplot(1,2,1)
hist(randCollector,200)
subplot(1,2,2)
hist(randnCollector,200)

pause() %pauses


%{
Produces
+------------------------------------------------------------------------------+
|                                                                              |
|       8 ++--+--+---+---+---+--+--++     20 ++--+----+---+---+----+--++       |
|         +------------------------++        +------------------------++       |
|       7 |+         +|+|+||       |+        | |                      ||       |
|         |          |||||||       ||        | +                      ||       |
|       6 |+   +  +++|+|+++++      |+     15 |+|                      |+       |
|         |    |  |||||||||||      ||        |+|                      ||       |
|       5 |+   |  |||+|++|+||      |+        ||+                      ||       |
|         |    |  |||||||||||      ||        |+|                      ||       |
|       4 |+  ++++++|++++++++++    |+     10 |++                      |+       |
|         |   |||||||||||||||||    ||        |+|                      ||       |
|         |   |||||||||||||||||    ||        |+|                      ||       |
|       3 |++++|+||+|||||||||++    |+        |+|                      ||       |
|         | |||||||||||||||||||    ||        |||                      ||       |
|       2 |++|+++++||+|++|+|++|++  |+      5 |+|                      |+       |
|         |||||||||||||||||||||||  ||        |+|                      ||       |
|       1 |+++||||+||||+||||||++|  |+        |+|                      ||       |
|         ||||+||+|||+|||+|||+||+  |+        |||++    +   +   +   ++  |+       |
|       0 +------------------------++      0 +------------------------++       |
|         0   2  4   6   8  10 12  14        0  10   20  30  40   50  60       |
+------------------------------------------------------------------------------+
%}
