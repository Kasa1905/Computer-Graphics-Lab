# Computer-Graphics-Lab

This repository contains a collection of computer graphics assignments implemented in C++ using various graphics libraries such as `graphics.h`, `SFML`, and `OpenGL`. Each assignment demonstrates a specific concept or algorithm in computer graphics.

## Table of Contents

1. [Assignment 1: Basic Graphics](#assignment-1-basic-graphics)
2. [Assignment 2: Line Clipping](#assignment-2-line-clipping)
3. [Assignment 3: Scan Line Polygon Fill](#assignment-3-scan-line-polygon-fill)
4. [Assignment 4: 2D Transformations](#assignment-4-2d-transformations)
5. [Assignment 5: Koch Snowflake](#assignment-5-koch-snowflake)
6. [Assignment 6: Sun Rise and Sunset Animation](#assignment-6-sun-rise-and-sunset-animation)

---

## Assignment 1: Basic Graphics

**File:** [Assingment1.cpp](Assingment1.cpp)

This program demonstrates basic graphics operations such as drawing lines and circles using the `graphics.h` library. It implements a pattern consisting of a triangle, an outer circle, and an inner circle.

### Features:
- Draws a triangle using the DDA algorithm.
- Draws concentric circles using the Bresenham circle algorithm.

---

## Assignment 2: Line Clipping

**File:** [Assingment2.cpp](Assingment2.cpp)

This program implements the Cohen-Sutherland line clipping algorithm to clip a line segment against a rectangular clipping window.

### Features:
- Accepts user input for the line segment's endpoints.
- Clips the line segment based on its visibility relative to the clipping window.
- Displays the original and clipped line segments.

---

## Assignment 3: Scan Line Polygon Fill

**File:** [Assingment3.cpp](Assingment3.cpp)

This program demonstrates the scan line polygon fill algorithm to fill a polygon with a specified color.

### Features:
- Accepts user input for the vertices of a polygon.
- Calculates intersections of scan lines with polygon edges.
- Fills the polygon using horizontal lines.

---

## Assignment 4: 2D Transformations

**File:** [Assingment4.cpp](Assingment4.cpp)

This program implements various 2D transformations on a polygon, including translation, scaling, rotation, reflection, and shearing.

### Features:
- Accepts user input for the vertices of a polygon.
- Performs transformations based on user choice.
- Displays the original and transformed polygons.

---

## Assignment 5: Koch Snowflake

**File:** [Assingment5.cpp](Assingment5.cpp)

This program generates a Koch snowflake fractal using the `SFML` library.

### Features:
- Recursively divides a line segment into smaller segments to create the Koch curve.
- Combines three Koch curves to form a snowflake.
- Allows visualization of the fractal at different levels of recursion.

---

## Assignment 6: Sun Rise and Sunset Animation

**File:** [Assingment6.cpp](Assingment6.cpp)

This program creates an animation of the sun rising and setting using the `OpenGL` library.

### Features:
- Animates the sun's vertical movement.
- Changes the background color to simulate day and night transitions.
- Uses double buffering for smooth rendering.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.