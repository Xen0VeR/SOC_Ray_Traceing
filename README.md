### Raytracer Project
# Overview
This project is a Raytracer developed during the Summer of Code. The goal was to create a minimal yet functional raytracing engine that simulates realistic lighting, shadows, reflections, and refractions to render high-quality 3D images. The project demonstrates the fundamental principles of raytracing, including light interaction with surfaces and objects.

# Features
Ray-Object Intersection: Implements ray intersection algorithms for spheres, planes, and triangles.
Phong Lighting Model: Simulates ambient, diffuse, and specular reflections.
Shadows: Supports hard shadows using ray-object intersection.
Reflections: Adds realism by supporting reflective surfaces.
Refractions: Simulates materials like glass or water using Snell's law.
Anti-aliasing: Reduces jagged edges for smoother image output.
# How It Works
The raytracing algorithm works by casting rays from the camera into the scene, calculating the color for each pixel based on the object the ray intersects, and determining how light interacts with that object. The ray's path is recursively traced to handle reflections and refractions, producing photorealistic effects.

# Steps Involved:
1. Scene Setup: Define objects, lights, and camera position.
2. Ray Casting: Shoot rays from the camera through the pixels of the image plane.
3. Intersection Calculation: For each ray, determine if it intersects any objects.
4. Shading: Calculate the color at the intersection point using lighting and material properties.
5. Reflections & Refractions: If the material is reflective or transparent, cast additional rays to simulate those effects.
6. Image Output: Write the final color of each pixel to an image file.
