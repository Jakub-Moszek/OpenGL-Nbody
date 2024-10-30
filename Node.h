#pragma once
#include <GL/GLEW.h>
#include <glm/glm.hpp>

#include "Particle.h"

#define NW 0
#define NE 1
#define SW 2
#define SE 3

#define vec glm::dvec2

class Node
{
public:
	Node(vec2 pos, glm::uint64 size);

	Particle* body;
	Node* childreen[4];

	glm::uint size;
	vec2 min;
	vec2 max;

	void subdivide();
	void insert(Particle* body);
	void display();
	bool intersect(vec2 point);
	bool isLeaf();

private:
};

