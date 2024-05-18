# Gravitational-N-body-simulator

This repository shows a C++ script of a N-body simulator with gravitational interactions, with the use of template and overlaoding.
The script show the use of overlaoding to redefine sum and subtractions suitable for the type of physical quantities involved in the simulation.
Variable assignments are done within instances of templated classes or functions.


The N particles are considered in a periodic finite box and they all interact with each others. 
The force on each particle is computed with Newton's second law:

![Newton II](https://latex.codecogs.com/png.latex?m_i%20\vec{a}_i%20(t)%20=%20m_i%20\frac{d^2%20\vec{x}_i}{dt^2}%20=%20\sum_{j%20\neq%20i}^{N}%20\vec{F}_{ij}%20\\),

such formula is computed exploting back reacton of Newton's thir law, making the code more efficient,
and the motion integrated with the simple first order Euler's method (the goal is not a precise simulation but how to use template and overlaodin in this type of code):

![Numerical Integration](https://latex.codecogs.com/png.latex?\vec{v}_i%20(t%20+%20dt)%20=%20\vec{v}_i%20(t)%20+%20\vec{a}_i%20(t)%20dt,%20\\%20\vec{x}_i%20(t%20+%20dt)%20=%20\vec{x}_i%20(t)%20+%20\vec{v}_i%20(t)%20dt.)


# Avoiding instabilities

The gravitational force ![Gravitational Force](https://latex.codecogs.com/png.latex?F_{ij}%20=%20\frac{G%20m_i%20m_j}{r^2}) might create instabilities when \( r \) is approximately zero.
So we considered the softened form 

![Softened Gravitational Force](https://latex.codecogs.com/png.latex?F_{ij}%20=%20\frac{G%20m_i%20m_j}{(r%20+%20\epsilon)^2})

where &epsilon; is a small (compared to the box-size) constant.

In the script particles might have different properties (here two different masses), precision can be chosen.
User input: dimension, box-size, number of particles, final simulation time and time step.
Initial position is chosen randomly with a uniform distribution. 
Along the box size and time of the simulation one should set the gravity constant.
