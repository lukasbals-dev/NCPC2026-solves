# Problem C: Captain's Compass

## Key idea:
Actual distances do not matter, you only need to compare differences.

## Solution:
Taking input is asumed to be trivial. `relx` and `rely` are defined as the difference between the $x_t - x_s$ and $y_t - y_s$, respectively. There are 3 cases from here, 2 of which are trivial.

### Case 1:
This case is when the points share the same $x$-coordinate or $y$-coordinate. Note, the case where they share both coordinates is guaranteed to not happen as explicitly stated by the question prompt in the `Input` section: "We have $(x_s, y_s) \neq (x_t, y_t)$". In either such case you move in the appropriate cardinal direction, which is shortest path: a straight line. This is the taken care of by: 
```c++
if (relx == 0 ) { std::cout << (rely>0 ? "N\n" : "S\n");}
else if (rely == 0) { std::cout << (relx>0 ? "E\n" : "W\n");}
```

### Case 2: 
In this case, `abs(relx) == abs(rely)`; it is the simplest. The ship and treasure make a square, with relative anlges to each other in the form $90^\circ n +45^\circ, n\in \mathbb{Z}$, which correspond to the intercardinal directions (i.e. NE, SW, etc.). In this case, a single movement along an intercardinal direction is the shortest path as guaranteed by the Pythagorean theorem. This is addressed in the section:
```c++
(rely > 0) ? path += "N" : path += "S";
(relx > 0) ? path += "E" : path += "W";
```

### Case 3:
Arguably the least trivial case, here movements along both a cardinal and an intercardinal direction are required. It is enough to find the longest of either `abs(relx)` or `abs(rely)`, and then move along the appropriate cardinal direction. This is because movements in intercardinal directions decrease `abs(relx)` and `abs(rely)` equally, and will first drop the smaller of the two to $0$ requiring the remaining distance to be covered by this cardinal movement. 

The full movement sequence is then that extra movement in a cardinal direction, followed by a movement in an intercardinal direction. This is seen in the following part appended to the code of the previous case, as this uses the same logic for intercardinal movement with additional logic for cardinal movement:
```c++
if ( abs(relx) > abs(rely) ) {
    (relx > 0) ? path += "E\n" : path += "W\n";
} else if ( abs(rely) > abs(relx) ) {
    (rely > 0) ? path += "N\n" : path += "S\n";
}
```