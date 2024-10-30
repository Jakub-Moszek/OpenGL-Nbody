#include "Quadtree.h"

Quadtree::Quadtree(vec2 pos, int size)
{
	this->root = new Node(pos, size);
}

void Quadtree::putBody(Particle* body)
{
	root->insert(body);
}