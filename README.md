# Cellular Automaton Simulator

This project is a simple cellular automaton simulator written in C++. It initializes a 2D grid with random values (0 and 1) based on a given probability. The program iteratively modifies the grid using Moore neighborhood rules until a stable configuration is reached.

## Features
- Random grid initialization with probability-based cell assignment.
- Iterative updates following Moore neighborhood rules.
- Stabilization detection to stop iterations.
- Console visualization of the grid using ASCII characters.

## How It Works
1. The grid is initialized with random 0s and 1s based on the probability `p`.
2. At each iteration:
   - Each cell's state is updated based on the sum of its neighboring cells.
   - Cells with a sum above or equal to a threshold are set to `1`, others to `0`.
3. The process repeats until the grid reaches a stable state where no further changes occur.

## Example Output:
Initial grid (randomly generated):

*   * *    
  * *   *  
* *     *  

Stable grid after iterations:

  * * *    
  * * *    
* * * * *  

## This simulation is inspired by Conway's Game of Life and models dynamic systems, such as:
- Forest fire spread.
- Epidemic dynamics.
- Population growth simulations.

## Future Enhancements:
- Add customizable grid size and probability input.
- Implement different cellular automaton rules.
- Create a graphical visualization of the simulation.
