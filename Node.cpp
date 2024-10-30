#include "Node.h"

Node::Node(vec2 pos, glm::uint64 size) : min { pos }, max { pos.x + size, pos.y + size }, size(size)
{
	
}

void Node::subdivide()
{
	vec2 new_pos = {};
	glm::uint64 new_size = this->size / 2;

	childreen[NW] = new Node(min, new_size);

	childreen[NE] = new Node(min + vec2{ new_size, 0 }, new_size);

	childreen[SW] = new Node(min + vec2{ new_size, 0 }, new_size);

	childreen[SE] = new Node(min + vec2{ new_size }, new_size);
}

void Node::insert(Particle* body)
{
	if (this->body == body)
		return;


	if (this->isLeaf() && this->body == nullptr)
	{
		this->body = body;
	}
	else
	{
		if(this->isLeaf())
		{
			this->subdivide();
			if (this->body)
			{
				Particle* old = this->body;
				this->body = nullptr;
				this->insert(old);
			}

			for (int i = 0; i < 4; i++)
			{
				if (childreen[i]->intersect(body->position))
					childreen[i]->insert(body);
			}
		}
	}
}

void Node::display()
{

}

bool Node::intersect(vec2 point)
{
	if (!(this->min.x < point.x < this->max.x))
		return false;

	if (!(this->min.y < point.y < this->max.y))
		return false;

	return true;
}

bool Node::isLeaf()
{
	if (childreen[NW] == NULL)
		return true;
	
	return false;
}