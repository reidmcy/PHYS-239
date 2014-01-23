%Question 2
%Reid McIlroy-Young
%20416412
%January 21 2014

function returnR = rotationZ(theta, vectorC)
    %Takes in an angle theta and a column vector vectorC
    %Returns the rotaion of vectorC around the z axis by theta
    %Uses the matrix exponetial of the generator and theta to create the rotation matrix 
    generatorRC = -1 * i * [0 1 0; -1 0 0; 0 0 0];
    returnR= (expm(-1 * i * theta * generatorRC) * vectorC)';
endfunction

rotationZ(pi, [1 0 0]')     %Produces [-1 0 0]
rotationZ(pi / 2, [0 1 0]') %Produces [-1 0 0]
