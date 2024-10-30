#pragma once
#include <GL/GLEW.h>
#include <vector>

#include "Default.h"
#include "Node.h"

class Quadtree
{
public: 
	Quadtree(vec2 pos, int size);
	void putBody(Particle* body);
	void reinsert();

protected:
	Node* root;
	std::vector<Particle*> particles;
};

